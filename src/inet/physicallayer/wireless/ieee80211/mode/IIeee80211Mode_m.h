//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/physicallayer/wireless/ieee80211/mode/IIeee80211Mode.msg.
//

#ifndef __INET__PHYSICALLAYER_IIEEE80211MODE_M_H
#define __INET__PHYSICALLAYER_IIEEE80211MODE_M_H

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
namespace physicallayer {


}  // namespace physicallayer
}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/Units_m.h" // import inet.common.Units

#include "inet/physicallayer/wireless/common/contract/packetlevel/IModulation_m.h" // import inet.physicallayer.wireless.common.contract.packetlevel.IModulation

// cplusplus {{
#include "inet/physicallayer/wireless/ieee80211/mode/IIeee80211Mode.h"
#include "inet/physicallayer/wireless/ieee80211/mode/Ieee80211ModeSet.h"
#include "inet/physicallayer/wireless/ieee80211/mode/Ieee80211OfdmModulation.h"
// }}


namespace inet {
namespace physicallayer {


}  // namespace physicallayer
}  // namespace inet


namespace omnetpp {

inline any_ptr toAnyPtr(const inet::physicallayer::IIeee80211PreambleMode *p) {if (auto obj = as_cObject(p)) return any_ptr(obj); else return any_ptr(p);}
template<> inline inet::physicallayer::IIeee80211PreambleMode *fromAnyPtr(any_ptr ptr) { return ptr.get<inet::physicallayer::IIeee80211PreambleMode>(); }
inline any_ptr toAnyPtr(const inet::physicallayer::IIeee80211HeaderMode *p) {if (auto obj = as_cObject(p)) return any_ptr(obj); else return any_ptr(p);}
template<> inline inet::physicallayer::IIeee80211HeaderMode *fromAnyPtr(any_ptr ptr) { return ptr.get<inet::physicallayer::IIeee80211HeaderMode>(); }
inline any_ptr toAnyPtr(const inet::physicallayer::IIeee80211DataMode *p) {if (auto obj = as_cObject(p)) return any_ptr(obj); else return any_ptr(p);}
template<> inline inet::physicallayer::IIeee80211DataMode *fromAnyPtr(any_ptr ptr) { return ptr.get<inet::physicallayer::IIeee80211DataMode>(); }
template<> inline inet::physicallayer::IIeee80211Mode *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::physicallayer::IIeee80211Mode*>(ptr.get<cObject>()); }
template<> inline inet::physicallayer::Ieee80211ModeSet *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::physicallayer::Ieee80211ModeSet*>(ptr.get<cObject>()); }
template<> inline inet::physicallayer::Ieee80211OfdmModulation *fromAnyPtr(any_ptr ptr) { return static_cast<inet::physicallayer::Ieee80211OfdmModulation*>(ptr.get<inet::physicallayer::IModulation>()); }

}  // namespace omnetpp

#endif // ifndef __INET__PHYSICALLAYER_IIEEE80211MODE_M_H

