//
// Copyright (C) 2020 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#include "inet/linklayer/ieee8021q/PcpCqfClassifier.h"

#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/common/PcpTag_m.h"

namespace inet {

Define_Module(PcpCqfClassifier);

void PcpCqfClassifier::initialize(int stage)
{
    PacketClassifierBase::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        mode = par("mode");
        mapping = check_and_cast<cValueArray *>(par("mapping").objectValue());
        cqfqueues = check_and_cast<cValueArray *>(par("cqfqueues").objectValue());
        defaultGateIndex = par("defaultGateIndex");
        isOpen_ = par("initiallyOpen");
        interval = par("interval");
        scheduleForAbsoluteTime = par("scheduleForAbsoluteTime");
        changeTimer = new ClockEvent("ChangeTimer");
    }
    else if (stage == INITSTAGE_QUEUEING)
        initializeGating();
}

void PcpCqfClassifier::handleParameterChange(const char *name)
{
    if (name != nullptr) {
        if (!strcmp(name, "initiallyOpen"))
            isOpen_ = par("initiallyOpen");
        else if (!strcmp(name, "cqfqueues"))
            cqfqueues = check_and_cast<cValueArray *>(par("cqfqueues").objectValue());
        else if (!strcmp(name, "interval")) {
            interval = par("interval");
            initializeGating();
        }
    }
}

void PcpCqfClassifier::handleMessage(cMessage *message)
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

void PcpCqfClassifier::initializeGating()
{
    index = 0;
    if (index < (int)cqfqueues->size()) {
        if (changeTimer->isScheduled())
            cancelClockEvent(changeTimer);
        scheduleChangeTimer();
    }
}

void PcpCqfClassifier::scheduleChangeTimer()
{
    if (scheduleForAbsoluteTime)
        scheduleClockEventAt(getClockTime() + interval, changeTimer);
    else
        scheduleClockEventAfter(interval, changeTimer);
}

void PcpCqfClassifier::processChangeTimer()
{
    ASSERT(0 <= index && index < (int)cqfqueues->size());
    index = (index + 1) % cqfqueues->size();
    if (isOpen_)
        isOpen_ = false;
    else
        isOpen_ = true;
}

int PcpCqfClassifier::classifyPacket(Packet *packet)
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
        int currentcqfqueue = cqfqueues->get(index);
        if (pcp == 3) {
            return currentcqfqueue;
        }
        else
            return pcp % numTrafficClasses;
    }
    else
        return defaultGateIndex;
}

} //namespace inet
