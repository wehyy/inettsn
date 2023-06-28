//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/linklayer/xmac/XMacHeader.msg.
//

#ifndef __INET_XMACHEADER_M_H
#define __INET_XMACHEADER_M_H

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

class XMacHeaderBase;
class XMacControlFrame;
class XMacDataFrameHeader;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/linklayer/common/MacAddress_m.h" // import inet.linklayer.common.MacAddress


namespace inet {

/**
 * Enum generated from <tt>inet/linklayer/xmac/XMacHeader.msg:14</tt> by opp_msgtool.
 * <pre>
 * // \@brief Types of messages (self messages and packets) the node can process
 * enum XMacTypes
 * {
 *     // packet types
 *     XMAC_PREAMBLE = 191;
 *     XMAC_DATA = 192;
 *     XMAC_ACK = 193;
 *     // self message types
 *     XMAC_RESEND_DATA = 194;
 *     XMAC_ACK_TIMEOUT = 195;
 *     XMAC_START_XMAC = 196;
 *     XMAC_WAKE_UP = 197;
 *     XMAC_SEND_ACK = 198;
 *     XMAC_CCA_TIMEOUT = 199;
 *     XMAC_ACK_TX_OVER = 200;
 *     XMAC_SEND_PREAMBLE = 201;
 *     XMAC_STOP_PREAMBLES = 202;
 *     XMAC_DATA_TX_OVER = 203;
 *     XMAC_DATA_TIMEOUT = 204;
 *     SWITCH_PREAMBLE_PHASE = 205;
 *     DELAY_FOR_ACK_WITHIN_REMOTE_RX = 206;
 *     XMAC_SWITCHING_FINISHED = 207;
 * }
 * </pre>
 */
enum XMacTypes {
    XMAC_PREAMBLE = 191,
    XMAC_DATA = 192,
    XMAC_ACK = 193,
    XMAC_RESEND_DATA = 194,
    XMAC_ACK_TIMEOUT = 195,
    XMAC_START_XMAC = 196,
    XMAC_WAKE_UP = 197,
    XMAC_SEND_ACK = 198,
    XMAC_CCA_TIMEOUT = 199,
    XMAC_ACK_TX_OVER = 200,
    XMAC_SEND_PREAMBLE = 201,
    XMAC_STOP_PREAMBLES = 202,
    XMAC_DATA_TX_OVER = 203,
    XMAC_DATA_TIMEOUT = 204,
    SWITCH_PREAMBLE_PHASE = 205,
    DELAY_FOR_ACK_WITHIN_REMOTE_RX = 206,
    XMAC_SWITCHING_FINISHED = 207
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const XMacTypes& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, XMacTypes& e) { int n; b->unpack(n); e = static_cast<XMacTypes>(n); }

/**
 * Class generated from <tt>inet/linklayer/xmac/XMacHeader.msg:40</tt> by opp_msgtool.
 * <pre>
 * //
 * // Base class for ~XMac headers.
 * //
 * class XMacHeaderBase extends FieldsChunk
 * {
 *     MacAddress srcAddr;
 *     MacAddress destAddr;
 *     XMacTypes type;
 * }
 * </pre>
 */
class INET_API XMacHeaderBase : public ::inet::FieldsChunk
{
  protected:
    MacAddress srcAddr;
    MacAddress destAddr;
    XMacTypes type = static_cast<inet::XMacTypes>(-1);

  private:
    void copy(const XMacHeaderBase& other);

  protected:
    bool operator==(const XMacHeaderBase&) = delete;

  public:
    XMacHeaderBase();
    XMacHeaderBase(const XMacHeaderBase& other);
    virtual ~XMacHeaderBase();
    XMacHeaderBase& operator=(const XMacHeaderBase& other);
    virtual XMacHeaderBase *dup() const override {return new XMacHeaderBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const MacAddress& getSrcAddr() const;
    virtual MacAddress& getSrcAddrForUpdate() { handleChange();return const_cast<MacAddress&>(const_cast<XMacHeaderBase*>(this)->getSrcAddr());}
    virtual void setSrcAddr(const MacAddress& srcAddr);

    virtual const MacAddress& getDestAddr() const;
    virtual MacAddress& getDestAddrForUpdate() { handleChange();return const_cast<MacAddress&>(const_cast<XMacHeaderBase*>(this)->getDestAddr());}
    virtual void setDestAddr(const MacAddress& destAddr);

    virtual XMacTypes getType() const;
    virtual void setType(XMacTypes type);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const XMacHeaderBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, XMacHeaderBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/xmac/XMacHeader.msg:51</tt> by opp_msgtool.
 * <pre>
 * //
 * // Control Frame for ~XMac. Frame size is configurable
 * // in the MAC layer.
 * //
 * class XMacControlFrame extends XMacHeaderBase
 * {
 * }
 * </pre>
 */
class INET_API XMacControlFrame : public ::inet::XMacHeaderBase
{
  protected:

  private:
    void copy(const XMacControlFrame& other);

  protected:
    bool operator==(const XMacControlFrame&) = delete;

  public:
    XMacControlFrame();
    XMacControlFrame(const XMacControlFrame& other);
    virtual ~XMacControlFrame();
    XMacControlFrame& operator=(const XMacControlFrame& other);
    virtual XMacControlFrame *dup() const override {return new XMacControlFrame(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const XMacControlFrame& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, XMacControlFrame& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/xmac/XMacHeader.msg:59</tt> by opp_msgtool.
 * <pre>
 * //
 * // Dataframe header for ~XMac. Frame size is configurable
 * // in the MAC layer.
 * //
 * class XMacDataFrameHeader extends XMacHeaderBase
 * {
 *     long sequenceId; // Sequence Number to detect duplicate messages
 *     int networkProtocol = -1;
 * }
 * </pre>
 */
class INET_API XMacDataFrameHeader : public ::inet::XMacHeaderBase
{
  protected:
    long sequenceId = 0;
    int networkProtocol = -1;

  private:
    void copy(const XMacDataFrameHeader& other);

  protected:
    bool operator==(const XMacDataFrameHeader&) = delete;

  public:
    XMacDataFrameHeader();
    XMacDataFrameHeader(const XMacDataFrameHeader& other);
    virtual ~XMacDataFrameHeader();
    XMacDataFrameHeader& operator=(const XMacDataFrameHeader& other);
    virtual XMacDataFrameHeader *dup() const override {return new XMacDataFrameHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual long getSequenceId() const;
    virtual void setSequenceId(long sequenceId);

    virtual int getNetworkProtocol() const;
    virtual void setNetworkProtocol(int networkProtocol);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const XMacDataFrameHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, XMacDataFrameHeader& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::XMacHeaderBase *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::XMacHeaderBase*>(ptr.get<cObject>()); }
template<> inline inet::XMacControlFrame *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::XMacControlFrame*>(ptr.get<cObject>()); }
template<> inline inet::XMacDataFrameHeader *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::XMacDataFrameHeader*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_XMACHEADER_M_H

