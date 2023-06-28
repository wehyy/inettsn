//
// Copyright (C) 2020 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#include "inet/linklayer/ieee8021q/PcpMcqfClassifier.h"

#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/common/PcpTag_m.h"

namespace inet {

Define_Module(PcpMcqfClassifier);

void PcpMcqfClassifier::initialize(int stage)
{
    PacketClassifierBase::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        mode = par("mode");
        mapping = check_and_cast<cValueArray *>(par("mapping").objectValue());
        cqfqueues_h = check_and_cast<cValueArray *>(par("cqfqueues_h").objectValue());
        cqfqueues_l = check_and_cast<cValueArray *>(par("cqfqueues_l").objectValue());
        defaultGateIndex = par("defaultGateIndex");
        isOpen_ = par("initiallyOpen");
        interval = par("interval");
        scheduleForAbsoluteTime = par("scheduleForAbsoluteTime");
        changeTimer = new ClockEvent("ChangeTimer");
        temp = 0;
        multiple = 2;
    }
    else if (stage == INITSTAGE_QUEUEING)
        initializeGating();
}

void PcpMcqfClassifier::handleParameterChange(const char *name)
{
    if (name != nullptr) {
        if (!strcmp(name, "initiallyOpen"))
            isOpen_ = par("initiallyOpen");
        else if (!strcmp(name, "cqfqueues_h"))
            cqfqueues_h = check_and_cast<cValueArray *>(par("cqfqueues_h").objectValue());
        else if (!strcmp(name, "cqfqueues_l"))
            cqfqueues_l = check_and_cast<cValueArray *>(par("cqfqueues_l").objectValue());
        else if (!strcmp(name, "multiple"))
            multiple = par("multiple");
        else if (!strcmp(name, "interval")) {
            interval = par("interval");
            initializeGating();
        }
    }
}

void PcpMcqfClassifier::handleMessage(cMessage *message)
{
    if (message == changeTimer) {
        processChangeTimer();
        scheduleChangeTimer();
    }
    else {
        auto packet = check_and_cast<Packet *>(message);
        pushPacket(packet, packet->getArrivalGate());
    }
}

void PcpMcqfClassifier::initializeGating()
{
    index_l = 0;
    index_h = 0;
    if (index_l < (int)cqfqueues_l->size() && index_h < (int)cqfqueues_h->size()) {
        if (changeTimer->isScheduled())
            cancelClockEvent(changeTimer);
        scheduleChangeTimer();
    }
}

void PcpMcqfClassifier::scheduleChangeTimer()
{
    if (scheduleForAbsoluteTime)
        scheduleClockEventAt(getClockTime() + interval, changeTimer);
    else
        scheduleClockEventAfter(interval, changeTimer);
}

void PcpMcqfClassifier::processChangeTimer()
{
    ASSERT(0 <= index_l && index_l < (int)cqfqueues_l->size() && 0 <= index_h && index_h < (int)cqfqueues_h->size());
    index_h = (index_h + 1) % cqfqueues_h->size();
    temp = (temp + 1) % multiple;
    index_l = temp ? index_l : (index_l + 1) % cqfqueues_l->size();
    if (isOpen_)
        isOpen_ = false;
    else
        isOpen_ = true;
}

int PcpMcqfClassifier::classifyPacket(Packet *packet)
{
    int pcp = -1;
    switch (*mode) {
        case 'r': {
            auto pcpReq = packet->findTag<PcpReq>();
            if (pcpReq != nullptr)
                pcp = pcpReq->getPcp();
            break;
        }
        case 'i': {
            auto pcpInd = packet->findTag<PcpInd>();
            if (pcpInd != nullptr)
                pcp = pcpInd->getPcp();
            break;
        }
        case 'b': {
            auto pcpReq = packet->findTag<PcpReq>();
            if (pcpReq != nullptr)
                pcp = pcpReq->getPcp();
            else {
                auto pcpInd = packet->findTag<PcpInd>();
                if (pcpInd != nullptr)
                    pcp = pcpInd->getPcp();
            }
            break;
        }
    }
    if (pcp != -1) {
        int numTrafficClasses = gateSize("out");
        int currentcqfqueue_l = cqfqueues_l->get(index_l);
        int currentcqfqueue_h = cqfqueues_h->get(index_h);
        if (pcp == 3) {
            return currentcqfqueue_h;
        }
        else if (pcp == 2){
            return currentcqfqueue_l;
        }
        else
            return pcp % numTrafficClasses;
    }
    else
        return defaultGateIndex;
}

} //namespace inet
