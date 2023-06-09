//
// Copyright (C) 2014 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#ifndef __INET_IIEEE80211MODE_H
#define __INET_IIEEE80211MODE_H

#include "inet/physicallayer/wireless/common/contract/packetlevel/IModulation.h"
#include "inet/physicallayer/wireless/ieee80211/packetlevel/Ieee80211PhyHeader_m.h"

namespace inet {

namespace physicallayer {

class INET_API IIeee80211PreambleMode : public cObject, public IPrintableObject
{
  public:
    virtual const simtime_t getDuration() const = 0;
    virtual Ptr<Ieee80211PhyPreamble> createPreamble() const = 0;
};

class INET_API IIeee80211HeaderMode : public cObject, public IPrintableObject
{
  public:
    virtual bps getNetBitrate() const = 0;
    virtual bps getGrossBitrate() const = 0;
    virtual b getLength() const = 0;
    virtual const simtime_t getDuration() const = 0;
    virtual const simtime_t getSymbolInterval() const = 0;
    virtual const IModulation *getModulation() const = 0;
    virtual Ptr<Ieee80211PhyHeader> createHeader() const = 0;
};

class INET_API IIeee80211DataMode : public cObject, public IPrintableObject
{
  public:
    virtual Hz getBandwidth() const = 0;
    virtual bps getNetBitrate() const = 0;
    virtual bps getGrossBitrate() const = 0;
    virtual b getPaddingLength(b dataLength) const = 0;
    virtual b getCompleteLength(b dataLength) const = 0;
    virtual const simtime_t getDuration(b dataLength) const = 0;
    virtual const simtime_t getSymbolInterval() const = 0;
    virtual const IModulation *getModulation() const = 0;
    virtual int getNumberOfSpatialStreams() const = 0;
};

class INET_API IIeee80211Mode : public cObject, public IPrintableObject
{
  public:
    virtual int getLegacyCwMin() const = 0;
    virtual int getLegacyCwMax() const = 0;
    virtual const char *getName() const = 0;
    virtual const IIeee80211PreambleMode *getPreambleMode() const = 0;
    virtual const IIeee80211HeaderMode *getHeaderMode() const = 0;
    virtual const IIeee80211DataMode *getDataMode() const = 0;
    IIeee80211PreambleMode *_getPreambleMode() const { return const_cast<IIeee80211PreambleMode *>(getPreambleMode()); }
    IIeee80211HeaderMode *_getHeaderMode() const { return const_cast<IIeee80211HeaderMode *>(getHeaderMode()); }
    IIeee80211DataMode *_getDataMode() const { return const_cast<IIeee80211DataMode *>(getDataMode()); }
    virtual const simtime_t getDuration(b dataLength) const = 0;
    virtual const simtime_t getSlotTime() const = 0;
    virtual const simtime_t getSifsTime() const = 0;
    virtual const simtime_t getRifsTime() const = 0;
    virtual const simtime_t getCcaTime() const = 0;
    virtual const simtime_t getPhyRxStartDelay() const = 0;
    virtual const simtime_t getRxTxTurnaroundTime() const = 0;
    virtual const simtime_t getPreambleLength() const = 0;
    virtual const simtime_t getPlcpHeaderLength() const = 0;
    virtual int getMpduMaxLength() const = 0;
};

} // namespace physicallayer

} // namespace inet

#endif

