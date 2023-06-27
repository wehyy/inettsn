//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/networklayer/ipv4/IcmpHeader.msg.
//

#ifndef __INET_ICMPHEADER_M_H
#define __INET_ICMPHEADER_M_H

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

class IcmpHeader;
class IcmpEchoRequest;
class IcmpEchoReply;
class IcmpPtb;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/transportlayer/common/CrcMode_m.h" // import inet.transportlayer.common.CrcMode


namespace inet {

/**
 * Enum generated from <tt>inet/networklayer/ipv4/IcmpHeader.msg:18</tt> by opp_msgtool.
 * <pre>
 * //
 * // The real ICMP codes
 * //
 * enum IcmpType
 * {
 *     ICMP_DESTINATION_UNREACHABLE = 3;
 *     ICMP_SOURCEQUENCH = 4;               // packet lost, slow down
 *     ICMP_REDIRECT = 5;
 *     ICMP_ECHO_REQUEST = 8;
 *     ICMP_ROUTER_ADVERTISEMENT = 9;    // router advertisement
 *     ICMP_ROUTER_SOLICITATION = 10;    // router solicitation
 *     ICMP_TIME_EXCEEDED = 11;
 *     ICMP_PARAMETER_PROBLEM = 12;
 * 
 *     ICMP_ECHO_REPLY = 0;
 *     ICMP_TIMESTAMP_REQUEST = 13;
 *     ICMP_TIMESTAMP_REPLY = 14;
 *     ICMP_INFORMATION_REQUEST = 15;    // information request
 *     ICMP_INFORMATION_REPLY = 16;    // information reply
 *     ICMP_MASK_REQUEST = 17;    // address mask request
 *     ICMP_MASK_REPLY = 18;    // address mask reply
 * }
 * </pre>
 */
enum IcmpType {
    ICMP_DESTINATION_UNREACHABLE = 3,
    ICMP_SOURCEQUENCH = 4,
    ICMP_REDIRECT = 5,
    ICMP_ECHO_REQUEST = 8,
    ICMP_ROUTER_ADVERTISEMENT = 9,
    ICMP_ROUTER_SOLICITATION = 10,
    ICMP_TIME_EXCEEDED = 11,
    ICMP_PARAMETER_PROBLEM = 12,
    ICMP_ECHO_REPLY = 0,
    ICMP_TIMESTAMP_REQUEST = 13,
    ICMP_TIMESTAMP_REPLY = 14,
    ICMP_INFORMATION_REQUEST = 15,
    ICMP_INFORMATION_REPLY = 16,
    ICMP_MASK_REQUEST = 17,
    ICMP_MASK_REPLY = 18
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IcmpType& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IcmpType& e) { int n; b->unpack(n); e = static_cast<IcmpType>(n); }

/**
 * Enum generated from <tt>inet/networklayer/ipv4/IcmpHeader.msg:39</tt> by opp_msgtool.
 * <pre>
 * enum IcmpRedirectSubcodes
 * {
 *     ICMP_REDIRECT_NET = 0;    // for network
 *     ICMP_REDIRECT_HOST = 1;    // for host
 *     ICMP_REDIRECT_TOSNET = 2;    // for tos and net
 *     ICMP_REDIRECT_TOSHOST = 3;    // for tos and host
 * }
 * </pre>
 */
enum IcmpRedirectSubcodes {
    ICMP_REDIRECT_NET = 0,
    ICMP_REDIRECT_HOST = 1,
    ICMP_REDIRECT_TOSNET = 2,
    ICMP_REDIRECT_TOSHOST = 3
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IcmpRedirectSubcodes& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IcmpRedirectSubcodes& e) { int n; b->unpack(n); e = static_cast<IcmpRedirectSubcodes>(n); }

/**
 * Enum generated from <tt>inet/networklayer/ipv4/IcmpHeader.msg:47</tt> by opp_msgtool.
 * <pre>
 * enum IcmpTimeExceededSubcodes
 * {
 *     ICMP_TIMXCEED_INTRANS = 0;               // ttl==0 in transit
 *     ICMP_TIMXCEED_REASS = 1;               // ttl==0 in reass
 * }
 * </pre>
 */
enum IcmpTimeExceededSubcodes {
    ICMP_TIMXCEED_INTRANS = 0,
    ICMP_TIMXCEED_REASS = 1
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IcmpTimeExceededSubcodes& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IcmpTimeExceededSubcodes& e) { int n; b->unpack(n); e = static_cast<IcmpTimeExceededSubcodes>(n); }

/**
 * Enum generated from <tt>inet/networklayer/ipv4/IcmpHeader.msg:53</tt> by opp_msgtool.
 * <pre>
 * enum IcmpParameterProblemSubcodes
 * {
 *     ICMP_PARAMPROB_ERRATPTR = 0;    // error at param ptr
 *     ICMP_PARAMPROB_OPTABSENT = 1;    // req. opt. absent
 *     ICMP_PARAMPROB_LENGTH = 2;    // bad length
 * }
 * </pre>
 */
enum IcmpParameterProblemSubcodes {
    ICMP_PARAMPROB_ERRATPTR = 0,
    ICMP_PARAMPROB_OPTABSENT = 1,
    ICMP_PARAMPROB_LENGTH = 2
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IcmpParameterProblemSubcodes& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IcmpParameterProblemSubcodes& e) { int n; b->unpack(n); e = static_cast<IcmpParameterProblemSubcodes>(n); }

/**
 * Enum generated from <tt>inet/networklayer/ipv4/IcmpHeader.msg:63</tt> by opp_msgtool.
 * <pre>
 * //
 * // Codes for type ICMP_DESTINATION_UNREACHABLE
 * //
 * enum IcmpDestinationUnreachableCodes
 * {
 *     ICMP_DU_NETWORK_UNREACHABLE = 0;
 *     ICMP_DU_HOST_UNREACHABLE = 1;
 *     ICMP_DU_PROTOCOL_UNREACHABLE = 2;
 *     ICMP_DU_PORT_UNREACHABLE = 3;
 *     ICMP_DU_FRAGMENTATION_NEEDED = 4;
 *     ICMP_DU_SOURCE_ROUTE_FAILED = 5;
 *     ICMP_DU_DESTINATION_NETWORK_UNKNOWN = 6;
 *     ICMP_DU_DESTINATION_HOST_UNKNOWN = 7;
 *     ICMP_DU_SOURCE_HOST_ISOLATED = 8;
 *     ICMP_DU_NETWORK_PROHIBITED = 9;
 *     ICMP_DU_HOST_PROHIBITED = 10;
 *     ICMP_DU_NETWORK_UNREACHABLE_FOR_TYPE_OF_SERVICE = 11;
 *     ICMP_DU_HOST_UNREACHABLE_FOR_TYPE_OF_SERVICE = 12;
 *     ICMP_DU_COMMUNICATION_PROHIBITED = 13;
 *     ICMP_DU_HOST_PRECEDENCE_VIOLATION = 14;
 *     ICMP_DU_PRECEDENCE_CUTOFF_IN_EFFECT = 15;
 *     ICMP_AODV_QUEUE_FULL = 16;
 * }
 * </pre>
 */
enum IcmpDestinationUnreachableCodes {
    ICMP_DU_NETWORK_UNREACHABLE = 0,
    ICMP_DU_HOST_UNREACHABLE = 1,
    ICMP_DU_PROTOCOL_UNREACHABLE = 2,
    ICMP_DU_PORT_UNREACHABLE = 3,
    ICMP_DU_FRAGMENTATION_NEEDED = 4,
    ICMP_DU_SOURCE_ROUTE_FAILED = 5,
    ICMP_DU_DESTINATION_NETWORK_UNKNOWN = 6,
    ICMP_DU_DESTINATION_HOST_UNKNOWN = 7,
    ICMP_DU_SOURCE_HOST_ISOLATED = 8,
    ICMP_DU_NETWORK_PROHIBITED = 9,
    ICMP_DU_HOST_PROHIBITED = 10,
    ICMP_DU_NETWORK_UNREACHABLE_FOR_TYPE_OF_SERVICE = 11,
    ICMP_DU_HOST_UNREACHABLE_FOR_TYPE_OF_SERVICE = 12,
    ICMP_DU_COMMUNICATION_PROHIBITED = 13,
    ICMP_DU_HOST_PRECEDENCE_VIOLATION = 14,
    ICMP_DU_PRECEDENCE_CUTOFF_IN_EFFECT = 15,
    ICMP_AODV_QUEUE_FULL = 16
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IcmpDestinationUnreachableCodes& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IcmpDestinationUnreachableCodes& e) { int n; b->unpack(n); e = static_cast<IcmpDestinationUnreachableCodes>(n); }

// cplusplus {{
typedef int IcmpCode;

inline bool isIcmpInfoType(int type)
{
    return (type == ICMP_ECHO_REPLY
            || type == ICMP_ECHO_REQUEST
            || type == ICMP_ROUTER_ADVERTISEMENT
            || type == ICMP_ROUTER_SOLICITATION
            || type == ICMP_TIMESTAMP_REQUEST
            || type == ICMP_TIMESTAMP_REPLY
            || type == ICMP_INFORMATION_REQUEST
            || type == ICMP_INFORMATION_REPLY
            || type == ICMP_MASK_REQUEST
            || type == ICMP_MASK_REPLY);
}
// }}

/**
 * Class generated from <tt>inet/networklayer/ipv4/IcmpHeader.msg:111</tt> by opp_msgtool.
 * <pre>
 * //
 * // ICMP message class
 * //
 * // Note: receiver MUST NOT decapsulate the datagram from ICMP error messages,
 * // because their contents is conceptually truncated. decapsulate() would result
 * // in a "length became negative" error; use getEncapsulatedMsg() instead.
 * //
 * // TODO add originator id and sequence number and create an ICMPControlInfo
 * class IcmpHeader extends FieldsChunk
 * {
 *     chunkLength = B(8);
 *     IcmpType type;   // 1 byte
 *     int code = -1;                   // 1 byte
 *     int chksum = 0;                 // 2 bytes, RFC 1071
 *     CrcMode crcMode = CRC_MODE_UNDEFINED;
 * }
 * </pre>
 */
class INET_API IcmpHeader : public ::inet::FieldsChunk
{
  protected:
    IcmpType type = static_cast<inet::IcmpType>(-1);
    int code = -1;
    int chksum = 0;
    CrcMode crcMode = CRC_MODE_UNDEFINED;

  private:
    void copy(const IcmpHeader& other);

  protected:
    bool operator==(const IcmpHeader&) = delete;

  public:
    IcmpHeader();
    IcmpHeader(const IcmpHeader& other);
    virtual ~IcmpHeader();
    IcmpHeader& operator=(const IcmpHeader& other);
    virtual IcmpHeader *dup() const override {return new IcmpHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual IcmpType getType() const;
    virtual void setType(IcmpType type);

    virtual int getCode() const;
    virtual void setCode(int code);

    virtual int getChksum() const;
    virtual void setChksum(int chksum);

    virtual CrcMode getCrcMode() const;
    virtual void setCrcMode(CrcMode crcMode);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IcmpHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IcmpHeader& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv4/IcmpHeader.msg:120</tt> by opp_msgtool.
 * <pre>
 * class IcmpEchoRequest extends IcmpHeader
 * {
 *     type = ICMP_ECHO_REQUEST;
 *     code = 0;
 *     int identifier; // sender module id   // 2 bytes
 *     int seqNumber; // sequence number           // 2 bytes
 * }
 * </pre>
 */
class INET_API IcmpEchoRequest : public ::inet::IcmpHeader
{
  protected:
    int identifier = 0;
    int seqNumber = 0;

  private:
    void copy(const IcmpEchoRequest& other);

  protected:
    bool operator==(const IcmpEchoRequest&) = delete;

  public:
    IcmpEchoRequest();
    IcmpEchoRequest(const IcmpEchoRequest& other);
    virtual ~IcmpEchoRequest();
    IcmpEchoRequest& operator=(const IcmpEchoRequest& other);
    virtual IcmpEchoRequest *dup() const override {return new IcmpEchoRequest(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getIdentifier() const;
    virtual void setIdentifier(int identifier);

    virtual int getSeqNumber() const;
    virtual void setSeqNumber(int seqNumber);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IcmpEchoRequest& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IcmpEchoRequest& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv4/IcmpHeader.msg:128</tt> by opp_msgtool.
 * <pre>
 * class IcmpEchoReply extends IcmpHeader
 * {
 *     type = ICMP_ECHO_REPLY;
 *     code = 0;
 *     int identifier; // sender module id   // 2 bytes
 *     int seqNumber; // sequence number           // 2 bytes
 * }
 * </pre>
 */
class INET_API IcmpEchoReply : public ::inet::IcmpHeader
{
  protected:
    int identifier = 0;
    int seqNumber = 0;

  private:
    void copy(const IcmpEchoReply& other);

  protected:
    bool operator==(const IcmpEchoReply&) = delete;

  public:
    IcmpEchoReply();
    IcmpEchoReply(const IcmpEchoReply& other);
    virtual ~IcmpEchoReply();
    IcmpEchoReply& operator=(const IcmpEchoReply& other);
    virtual IcmpEchoReply *dup() const override {return new IcmpEchoReply(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getIdentifier() const;
    virtual void setIdentifier(int identifier);

    virtual int getSeqNumber() const;
    virtual void setSeqNumber(int seqNumber);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IcmpEchoReply& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IcmpEchoReply& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv4/IcmpHeader.msg:136</tt> by opp_msgtool.
 * <pre>
 * class IcmpPtb extends IcmpHeader
 * {
 *     type = ICMP_DESTINATION_UNREACHABLE;
 *     code = ICMP_DU_FRAGMENTATION_NEEDED;
 *     uint16_t unused = 0;
 *     uint16_t mtu = 0;
 * }
 * </pre>
 */
class INET_API IcmpPtb : public ::inet::IcmpHeader
{
  protected:
    uint16_t unused = 0;
    uint16_t mtu = 0;

  private:
    void copy(const IcmpPtb& other);

  protected:
    bool operator==(const IcmpPtb&) = delete;

  public:
    IcmpPtb();
    IcmpPtb(const IcmpPtb& other);
    virtual ~IcmpPtb();
    IcmpPtb& operator=(const IcmpPtb& other);
    virtual IcmpPtb *dup() const override {return new IcmpPtb(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual uint16_t getUnused() const;
    virtual void setUnused(uint16_t unused);

    virtual uint16_t getMtu() const;
    virtual void setMtu(uint16_t mtu);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IcmpPtb& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IcmpPtb& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::IcmpHeader *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::IcmpHeader*>(ptr.get<cObject>()); }
template<> inline inet::IcmpEchoRequest *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::IcmpEchoRequest*>(ptr.get<cObject>()); }
template<> inline inet::IcmpEchoReply *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::IcmpEchoReply*>(ptr.get<cObject>()); }
template<> inline inet::IcmpPtb *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::IcmpPtb*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_ICMPHEADER_M_H

