//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/transportlayer/rtp/Reports.msg.
//

#ifndef __INET__RTP_REPORTS_M_H
#define __INET__RTP_REPORTS_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif


namespace inet {
namespace rtp {

class SenderReport;
class ReceptionReport;

}  // namespace rtp
}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs


namespace inet {
namespace rtp {

/**
 * Class generated from <tt>inet/transportlayer/rtp/Reports.msg:16</tt> by opp_msgtool.
 * <pre>
 * //
 * // Represents an RTP sender report as contained
 * // in an ~RtcpSenderReportPacket.
 * //
 * class SenderReport extends cObject
 * {
 *     // The ntp time stamp.
 *     uint64_t NTPTimeStamp;
 * 
 *     // The rtp time stamp.
 *     uint32_t RTPTimeStamp;
 * 
 *     // The number of packets sent.
 *     uint32_t packetCount;
 * 
 *     // The number of (payload) bytes sent.
 *     uint32_t byteCount;
 * }
 * </pre>
 */
class INET_API SenderReport : public ::omnetpp::cObject
{
  protected:
    uint64_t NTPTimeStamp = 0;
    uint32_t RTPTimeStamp = 0;
    uint32_t packetCount = 0;
    uint32_t byteCount = 0;

  private:
    void copy(const SenderReport& other);

  protected:
    bool operator==(const SenderReport&) = delete;

  public:
    SenderReport();
    SenderReport(const SenderReport& other);
    virtual ~SenderReport();
    SenderReport& operator=(const SenderReport& other);
    virtual SenderReport *dup() const override {return new SenderReport(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual uint64_t getNTPTimeStamp() const;
    virtual void setNTPTimeStamp(uint64_t NTPTimeStamp);

    virtual uint32_t getRTPTimeStamp() const;
    virtual void setRTPTimeStamp(uint32_t RTPTimeStamp);

    virtual uint32_t getPacketCount() const;
    virtual void setPacketCount(uint32_t packetCount);

    virtual uint32_t getByteCount() const;
    virtual void setByteCount(uint32_t byteCount);


  public:
    /**
     * Writes a short info about this SenderReport into the given string.
     */
    virtual std::string str() const override;

    /**
     * Writes a longer info about this SenderReport into the given stream.
     */
    virtual void dump(std::ostream& os) const;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SenderReport& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SenderReport& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/transportlayer/rtp/Reports.msg:48</tt> by opp_msgtool.
 * <pre>
 * //
 * // Rrepresents an RTP receiver report stored
 * // in an RTPSenderReportPacket or RTPReceiverReport.
 * //
 * class ReceptionReport extends cObject
 * {
 *     // The ssrc identifier of the sender this ~ReceptionReport is for.
 *     uint32_t ssrc;
 * 
 *     // The fraction lost.
 *     uint8_t fractionLost;
 * 
 *     // The number of packets expected minus the number of packets received.
 *     int packetsLostCumulative;
 * 
 *     // The extended highest sequence number received.
 *     uint32_t sequenceNumber;
 * 
 *     // The interarrival jitter.
 *     int jitter;
 * 
 *     // The rtp time stamp of the last ~SenderReport received from this source.
 *     int lastSR;
 * 
 *     // The delay since the last ~SenderReport from this sender has been
 *     // received in units of 1/65536 seconds.
 *     int delaySinceLastSR;
 * }
 * </pre>
 */
class INET_API ReceptionReport : public ::omnetpp::cObject
{
  protected:
    uint32_t ssrc = 0;
    uint8_t fractionLost = 0;
    int packetsLostCumulative = 0;
    uint32_t sequenceNumber = 0;
    int jitter = 0;
    int lastSR = 0;
    int delaySinceLastSR = 0;

  private:
    void copy(const ReceptionReport& other);

  protected:
    bool operator==(const ReceptionReport&) = delete;

  public:
    ReceptionReport();
    ReceptionReport(const ReceptionReport& other);
    virtual ~ReceptionReport();
    ReceptionReport& operator=(const ReceptionReport& other);
    virtual ReceptionReport *dup() const override {return new ReceptionReport(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual uint32_t getSsrc() const;
    virtual void setSsrc(uint32_t ssrc);

    virtual uint8_t getFractionLost() const;
    virtual void setFractionLost(uint8_t fractionLost);

    virtual int getPacketsLostCumulative() const;
    virtual void setPacketsLostCumulative(int packetsLostCumulative);

    virtual uint32_t getSequenceNumber() const;
    virtual void setSequenceNumber(uint32_t sequenceNumber);

    virtual int getJitter() const;
    virtual void setJitter(int jitter);

    virtual int getLastSR() const;
    virtual void setLastSR(int lastSR);

    virtual int getDelaySinceLastSR() const;
    virtual void setDelaySinceLastSR(int delaySinceLastSR);


  public:
    /**
     * Writes a short info about this ReceptionReport into the given string.
     */
    virtual std::string str() const override;

    /**
     * Writes a longer info about this ReceptionReport into the given stream.
     */
    virtual void dump(std::ostream& os) const;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ReceptionReport& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ReceptionReport& obj) {obj.parsimUnpack(b);}


}  // namespace rtp
}  // namespace inet


namespace omnetpp {

template<> inline inet::rtp::SenderReport *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::rtp::SenderReport*>(ptr.get<cObject>()); }
template<> inline inet::rtp::ReceptionReport *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::rtp::ReceptionReport*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET__RTP_REPORTS_M_H

