//
// Copyright (C) 2020 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//

#ifndef __INETTSN_PCPCQFCLASSIFIER_H
#define __INETTSN_PCPCQFCLASSIFIER_H

#include "inet/queueing/base/PacketClassifierBase.h"
#include "inet/common/clock/ClockUserModuleMixin.h"
#include "inet/queueing/base/PacketGateBase.h"

namespace inet {

extern template class ClockUserModuleMixin<queueing::PacketClassifierBase>;

class INET_API PcpCqfClassifier : public ClockUserModuleMixin<queueing::PacketClassifierBase>
{
  protected:
    const char *mode = nullptr;
    cValueArray *mapping = nullptr;
    cValueArray *cqfqueues = nullptr;
    int defaultGateIndex = -1;
    int index = 0;
    clocktime_t interval;
    bool scheduleForAbsoluteTime = false;
    bool isOpen_ = false;

    ClockEvent *changeTimer = nullptr;

  protected:
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *message) override;
    virtual void handleParameterChange(const char *name) override;
    virtual int classifyPacket(Packet *packet) override;

    virtual void initializeGating();
    virtual void scheduleChangeTimer();
    virtual void processChangeTimer();

  public:
    virtual ~PcpCqfClassifier() { cancelAndDelete(changeTimer); }

};

} // namespace inet

#endif
