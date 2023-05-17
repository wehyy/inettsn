//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/linklayer/ieee8022/Ieee8022LlcSocketCommand.msg.
//

#ifndef __INET_IEEE8022LLCSOCKETCOMMAND_M_H
#define __INET_IEEE8022LLCSOCKETCOMMAND_M_H

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

class Ieee8022LlcSocketOpenCommand;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/socket/SocketCommand_m.h" // import inet.common.socket.SocketCommand


namespace inet {

/**
 * Class generated from <tt>inet/linklayer/ieee8022/Ieee8022LlcSocketCommand.msg:13</tt> by opp_msgtool.
 * <pre>
 * class Ieee8022LlcSocketOpenCommand extends SocketCommandBase
 * {
 *     int localSap;
 * }
 * </pre>
 */
class INET_API Ieee8022LlcSocketOpenCommand : public ::inet::SocketCommandBase
{
  protected:
    int localSap = 0;

  private:
    void copy(const Ieee8022LlcSocketOpenCommand& other);

  protected:
    bool operator==(const Ieee8022LlcSocketOpenCommand&) = delete;

  public:
    Ieee8022LlcSocketOpenCommand();
    Ieee8022LlcSocketOpenCommand(const Ieee8022LlcSocketOpenCommand& other);
    virtual ~Ieee8022LlcSocketOpenCommand();
    Ieee8022LlcSocketOpenCommand& operator=(const Ieee8022LlcSocketOpenCommand& other);
    virtual Ieee8022LlcSocketOpenCommand *dup() const override {return new Ieee8022LlcSocketOpenCommand(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getLocalSap() const;
    virtual void setLocalSap(int localSap);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ieee8022LlcSocketOpenCommand& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ieee8022LlcSocketOpenCommand& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::Ieee8022LlcSocketOpenCommand *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ieee8022LlcSocketOpenCommand*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_IEEE8022LLCSOCKETCOMMAND_M_H

