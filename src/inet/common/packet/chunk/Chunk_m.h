//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/common/packet/chunk/Chunk.msg.
//

#ifndef __INET_CHUNK_M_H
#define __INET_CHUNK_M_H

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


}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/Units_m.h" // import inet.common.Units

// cplusplus {{
#include "inet/common/packet/chunk/BitCountChunk.h"
#include "inet/common/packet/chunk/BitsChunk.h"
#include "inet/common/packet/chunk/ByteCountChunk.h"
#include "inet/common/packet/chunk/BytesChunk.h"
#include "inet/common/packet/chunk/Chunk.h"
#include "inet/common/packet/chunk/cPacketChunk.h"
#include "inet/common/packet/chunk/EmptyChunk.h"
#include "inet/common/packet/chunk/StreamBufferChunk.h"
#include "inet/common/packet/chunk/EncryptedChunk.h"
#include "inet/common/packet/chunk/FieldsChunk.h"
#include "inet/common/packet/chunk/SequenceChunk.h"
#include "inet/common/packet/chunk/SliceChunk.h"
// }}


namespace inet {


}  // namespace inet


namespace omnetpp {

template<> inline inet::SharingRegionTagSet::TagBaseRegionTag *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::SharingRegionTagSet::TagBaseRegionTag*>(ptr.get<cObject>()); }
template<> inline inet::Chunk *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Chunk*>(ptr.get<cObject>()); }
template<> inline inet::BitCountChunk *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::BitCountChunk*>(ptr.get<cObject>()); }
template<> inline inet::BitsChunk *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::BitsChunk*>(ptr.get<cObject>()); }
template<> inline inet::ByteCountChunk *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::ByteCountChunk*>(ptr.get<cObject>()); }
template<> inline inet::BytesChunk *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::BytesChunk*>(ptr.get<cObject>()); }
template<> inline inet::SequenceChunk *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::SequenceChunk*>(ptr.get<cObject>()); }
template<> inline inet::SliceChunk *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::SliceChunk*>(ptr.get<cObject>()); }
template<> inline inet::EmptyChunk *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::EmptyChunk*>(ptr.get<cObject>()); }
template<> inline inet::StreamBufferChunk *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::StreamBufferChunk*>(ptr.get<cObject>()); }
template<> inline inet::EncryptedChunk *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::EncryptedChunk*>(ptr.get<cObject>()); }
template<> inline inet::cPacketChunk *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::cPacketChunk*>(ptr.get<cObject>()); }
template<> inline inet::FieldsChunk *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::FieldsChunk*>(ptr.get<cObject>()); }
template<> inline inet::ChunkTemporarySharedPtr *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::ChunkTemporarySharedPtr*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_CHUNK_M_H

