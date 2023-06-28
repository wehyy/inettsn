//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/transportlayer/rtp/RtpParticipantInfo.msg.
//

#ifndef __INET__RTP_RTPPARTICIPANTINFO_M_H
#define __INET__RTP_RTPPARTICIPANTINFO_M_H

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

class RtpParticipantInfo;

}  // namespace rtp
}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/networklayer/contract/ipv4/Ipv4Address_m.h" // import inet.networklayer.contract.ipv4.Ipv4Address


namespace inet {
namespace rtp {

/**
 * Class generated from <tt>inet/transportlayer/rtp/RtpParticipantInfo.msg:24</tt> by opp_msgtool.
 * <pre>
 * //
 * // This class is a super class for classes intended for storing information
 * // about ~RTP end systems.
 * // It has two subclasses: RTPReceiverInformation which is used for storing
 * // information about other system participating in an ~RTP session.
 * // RTPSenderInformation is used by an ~RTP endsystem for storing information
 * // about itself.
 * // sa RTPReceiverInformation
 * // sa RTPSenderInformation
 * //
 * class RtpParticipantInfo extends cNamedObject
 * {
 *     \@customize;  //FIXME need revise, several custommized functions should be moved to a processing module
 * 
 *     abstract uint32_t ssrc;
 * 
 *     // Used for storing the ip address of this endsystem.
 *     Ipv4Address address = Ipv4Address::UNSPECIFIED_ADDRESS;
 * 
 *     // Used for storing the port for ~RTP by this endsystem.
 *     int RTPPort = PORT_UNDEF;
 * 
 *     // Used for storing the port for ~RTCP by this endsystem.
 *     int RTCPPort = PORT_UNDEF;
 * }
 * </pre>
 *
 * RtpParticipantInfo_Base is only useful if it gets subclassed, and RtpParticipantInfo is derived from it.
 * The minimum code to be written for RtpParticipantInfo is the following:
 *
 * <pre>
 * class INET_API RtpParticipantInfo : public RtpParticipantInfo_Base
 * {
 *   private:
 *     void copy(const RtpParticipantInfo& other) { ... }

 *   public:
 *     RtpParticipantInfo(const char *name=nullptr) : RtpParticipantInfo_Base(name) {}
 *     RtpParticipantInfo(const RtpParticipantInfo& other) : RtpParticipantInfo_Base(other) {copy(other);}
 *     RtpParticipantInfo& operator=(const RtpParticipantInfo& other) {if (this==&other) return *this; RtpParticipantInfo_Base::operator=(other); copy(other); return *this;}
 *     virtual RtpParticipantInfo *dup() const override {return new RtpParticipantInfo(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from RtpParticipantInfo_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(RtpParticipantInfo)
 * </pre>
 */
class INET_API RtpParticipantInfo_Base : public ::omnetpp::cNamedObject
{
  protected:
    ::inet::Ipv4Address address = Ipv4Address::UNSPECIFIED_ADDRESS;
    int RTPPort = PORT_UNDEF;
    int RTCPPort = PORT_UNDEF;

  private:
    void copy(const RtpParticipantInfo_Base& other);

  protected:
    bool operator==(const RtpParticipantInfo_Base&) = delete;
    // make constructors protected to avoid instantiation
    RtpParticipantInfo_Base(const char *name=nullptr);
    RtpParticipantInfo_Base(const RtpParticipantInfo_Base& other);
    // make assignment operator protected to force the user override it
    RtpParticipantInfo_Base& operator=(const RtpParticipantInfo_Base& other);

  public:
    virtual ~RtpParticipantInfo_Base();
    virtual RtpParticipantInfo_Base *dup() const override {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class RtpParticipantInfo");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual uint32_t getSsrc() const = 0;
    virtual void setSsrc(uint32_t ssrc) = 0;

    virtual const ::inet::Ipv4Address& getAddress() const;
    virtual ::inet::Ipv4Address& getAddressForUpdate() { return const_cast<::inet::Ipv4Address&>(const_cast<RtpParticipantInfo_Base*>(this)->getAddress());}
    virtual void setAddress(const ::inet::Ipv4Address& address);

    virtual int getRTPPort() const;
    virtual void setRTPPort(int RTPPort);

    virtual int getRTCPPort() const;
    virtual void setRTCPPort(int RTCPPort);
};


}  // namespace rtp
}  // namespace inet


namespace omnetpp {

template<> inline inet::rtp::RtpParticipantInfo_Base *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::rtp::RtpParticipantInfo_Base*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET__RTP_RTPPARTICIPANTINFO_M_H

