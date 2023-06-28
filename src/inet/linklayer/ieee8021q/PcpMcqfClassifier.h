/*
 * PcpMcqfClassifier.h
 *
 *  Created on: 2023Äê5ÔÂ30ÈÕ
 *      Author: DELL
 */

#ifndef INET_LINKLAYER_IEEE8021Q_PCPMCQFCLASSIFIER_H_
#define INET_LINKLAYER_IEEE8021Q_PCPMCQFCLASSIFIER_H_



#include "inet/queueing/base/PacketClassifierBase.h"
#include "inet/common/clock/ClockUserModuleMixin.h"
#include "inet/queueing/base/PacketGateBase.h"

namespace inet {

extern template class ClockUserModuleMixin<queueing::PacketClassifierBase>;

class INET_API PcpMcqfClassifier : public ClockUserModuleMixin<queueing::PacketClassifierBase>
{
  protected:
    const char *mode = nullptr;
    cValueArray *mapping = nullptr;
    cValueArray *cqfqueues_h = nullptr;
    cValueArray *cqfqueues_l = nullptr;
    int defaultGateIndex = -1;
    int index_h = 0;
    int index_l = 0;
    int temp = 0;
    int multiple = 0;
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
    virtual ~PcpMcqfClassifier() { cancelAndDelete(changeTimer); }

};

}

#endif /* INET_LINKLAYER_IEEE8021Q_PCPMCQFCLASSIFIER_H_ */
