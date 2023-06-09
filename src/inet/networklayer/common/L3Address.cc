//
// Copyright (C) 2005 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#include "inet/networklayer/common/L3Address.h"

#include "inet/linklayer/common/MacAddressType.h"
#include "inet/networklayer/common/ModuleIdAddressType.h"
#include "inet/networklayer/common/ModulePathAddressType.h"
#include "inet/networklayer/contract/clns/ClnsAddressType.h"
#include "inet/networklayer/contract/ipv4/Ipv4AddressType.h"
#include "inet/networklayer/contract/ipv6/Ipv6AddressType.h"

namespace inet {

#define RESERVED_IPV6_ADDRESS_RANGE    0x8000 // IETF reserved address range 8000::/16 (extended)

uint64_t L3Address::get(AddressType type) const
{
    if (getType() != type)
        throw cRuntimeError("Address %s is of type %s where type %s was expected", str().c_str(), getTypeName(getType()), getTypeName(type));
    return lo;
}

void L3Address::set(AddressType type, uint64_t lo)
{
    this->hi = ((uint64_t)RESERVED_IPV6_ADDRESS_RANGE << 48) + (uint64_t)type;
    this->lo = lo;
}

void L3Address::set(const Ipv6Address& addr)
{
    const uint32_t *words = addr.words();
    hi = ((uint64_t)*(words + 0) << 32) + *(words + 1);
    lo = ((uint64_t)*(words + 2) << 32) + *(words + 3);
    if (getType() != IPv6)
        throw cRuntimeError("Cannot set Ipv6 address");
}

void L3Address::set(const ClnsAddress& addr)
{

    hi = ((uint64_t)RESERVED_IPV6_ADDRESS_RANGE << 48) | ((addr.getAreaId() & 0xFFFFFFFFL) << 16) | (uint64_t)addr.getNsel() << 8 | (uint64_t)L3Address::CLNS;
    lo = addr.getSystemId();
}

L3Address::AddressType L3Address::getType() const
{
    if (hi >> 48 == RESERVED_IPV6_ADDRESS_RANGE)
        return (AddressType)(hi & 0xFF);
    else
        return L3Address::IPv6;
}

const IL3AddressType *L3Address::getAddressType() const
{
    switch (getType()) {
        case L3Address::NONE:
            throw cRuntimeError("Address contains no value");

        case L3Address::IPv4:
            return &Ipv4AddressType::INSTANCE;

        case L3Address::IPv6:
            return &Ipv6AddressType::INSTANCE;

        case L3Address::MAC:
            return &MacAddressType::INSTANCE;

        case L3Address::MODULEID:
            return &ModuleIdAddressType::INSTANCE;

        case L3Address::MODULEPATH:
            return &ModulePathAddressType::INSTANCE;

        case L3Address::CLNS:
            return &CLNSAddressType::INSTANCE;

        default:
            throw cRuntimeError("Unknown type");
    }
}

std::string L3Address::str() const
{
    switch (getType()) {
        case L3Address::NONE:
            return "<none>";

        case L3Address::IPv4:
            return toIpv4().str();

        case L3Address::IPv6:
            return toIpv6().str();

        case L3Address::MAC:
            return toMac().str();

        case L3Address::MODULEID:
            return toModuleId().str();

        case L3Address::MODULEPATH:
            return toModulePath().str();

        case L3Address::CLNS:
            return toClns().str();

        default:
            throw cRuntimeError("Unknown type");
    }
}

bool L3Address::tryParse(const char *addr)
{
    Ipv6Address ipv6;
    MacAddress mac;
    ModuleIdAddress moduleId;
    ModulePathAddress modulePath;
    if (Ipv4Address::isWellFormed(addr))
        set(Ipv4Address(addr));
    else if (ipv6.tryParse(addr))
        set(ipv6);
    else if (mac.tryParse(addr))
        set(mac);
    else if (moduleId.tryParse(addr))
        set(moduleId);
    else if (modulePath.tryParse(addr))
        set(modulePath);
    else
        return false;
    return true;
}

bool L3Address::isUnspecified() const
{
    switch (getType()) {
        case L3Address::NONE:
            return true;

        case L3Address::IPv4:
            return toIpv4().isUnspecified();

        case L3Address::IPv6:
            return toIpv6().isUnspecified();

        case L3Address::MAC:
            return toMac().isUnspecified();

        case L3Address::MODULEID:
            return toModuleId().isUnspecified();

        case L3Address::MODULEPATH:
            return toModulePath().isUnspecified();

        default:
            throw cRuntimeError("Unknown type");
    }
}

bool L3Address::isUnicast() const
{
    switch (getType()) {
        case L3Address::NONE:
            throw cRuntimeError("Address contains no value");

        case L3Address::IPv4:
            return !toIpv4().isMulticast() && !toIpv4().isLimitedBroadcastAddress(); // TODO move to Ipv4Address

        case L3Address::IPv6:
            return toIpv6().isUnicast();

        case L3Address::MAC:
            return !toMac().isBroadcast() && !toMac().isMulticast(); // TODO move to MacAddress

        case L3Address::MODULEID:
            return toModuleId().isUnicast();

        case L3Address::MODULEPATH:
            return toModulePath().isUnicast();

        default:
            throw cRuntimeError("Unknown type");
    }
}

bool L3Address::isMulticast() const
{
    switch (getType()) {
        case L3Address::NONE:
            throw cRuntimeError("Address contains no value");

        case L3Address::IPv4:
            return toIpv4().isMulticast();

        case L3Address::IPv6:
            return toIpv6().isMulticast();

        case L3Address::MAC:
            return toMac().isMulticast();

        case L3Address::MODULEID:
            return toModuleId().isMulticast();

        case L3Address::MODULEPATH:
            return toModulePath().isMulticast();

        default:
            throw cRuntimeError("Unknown type");
    }
}

bool L3Address::isBroadcast() const
{
    switch (getType()) {
        case L3Address::NONE:
            throw cRuntimeError("Address contains no value");

        case L3Address::IPv4:
            return toIpv4().isLimitedBroadcastAddress();

        case L3Address::IPv6:
            return false;

//        throw cRuntimeError("Ipv6 isBroadcast() unimplemented");
        case L3Address::MAC:
            return toMac().isBroadcast();

        case L3Address::MODULEID:
            return toModuleId().isBroadcast();

        case L3Address::MODULEPATH:
            return toModulePath().isBroadcast();

        default:
            throw cRuntimeError("Unknown type");
    }
}

bool L3Address::isLinkLocal() const
{
    switch (getType()) {
        case L3Address::NONE:
            throw cRuntimeError("Address contains no value");

        case L3Address::IPv4:
            return false;

        case L3Address::IPv6:
            return toIpv6().isLinkLocal();

        case L3Address::MAC:
            return true;

        case L3Address::MODULEID:
            return false;

        case L3Address::MODULEPATH:
            return false;

        default:
            throw cRuntimeError("Unknown type");
    }
}

bool L3Address::operator<(const L3Address& other) const
{
    AddressType type = getType();
    AddressType otherType = other.getType();
    if (type != otherType)
        return type < otherType;
    else {
        switch (type) {
            case L3Address::NONE:
                throw cRuntimeError("Address contains no value");

            case L3Address::IPv4:
                return toIpv4() < other.toIpv4();

            case L3Address::IPv6:
                return toIpv6() < other.toIpv6();

            case L3Address::MAC:
                return toMac() < other.toMac();

            case L3Address::MODULEID:
                return toModuleId() < other.toModuleId();

            case L3Address::MODULEPATH:
                return toModulePath() < other.toModulePath();

            default:
                throw cRuntimeError("Unknown type");
        }
    }
}

bool L3Address::operator==(const L3Address& other) const
{
    AddressType type = getType();
    if (type != other.getType())
        return false;
    else {
        switch (type) {
            case L3Address::NONE:
                return true;

            case L3Address::IPv4:
                return toIpv4() == other.toIpv4();

            case L3Address::IPv6:
                return toIpv6() == other.toIpv6();

            case L3Address::MAC:
                return toMac() == other.toMac();

            case L3Address::MODULEID:
                return toModuleId() == other.toModuleId();

            case L3Address::MODULEPATH:
                return toModulePath() == other.toModulePath();

            default:
                throw cRuntimeError("Unknown type");
        }
    }
}

bool L3Address::operator!=(const L3Address& other) const
{
    return !operator==(other);
}

bool L3Address::matches(const L3Address& other, int prefixLength) const
{
    switch (getType()) {
        case L3Address::NONE:
            throw cRuntimeError("Address contains no value");

        case L3Address::IPv4:
            return Ipv4Address::maskedAddrAreEqual(toIpv4(), other.toIpv4(), Ipv4Address::makeNetmask(prefixLength)); // FIXME !!!!!

        case L3Address::IPv6:
            return toIpv6().matches(other.toIpv6(), prefixLength);

        case L3Address::MAC:
            return toMac() == other.toMac();

        case L3Address::MODULEID:
            return toModuleId() == other.toModuleId();

        case L3Address::MODULEPATH:
            return ModulePathAddress::maskedAddrAreEqual(toModulePath(), other.toModulePath(), prefixLength);

        default:
            throw cRuntimeError("Unknown type");
    }
}

L3Address L3Address::getPrefix(int prefixLength) const
{
    switch (getType()) {
        case L3Address::NONE:
            return *this;

        case L3Address::IPv4:
            return L3Address(toIpv4().getPrefix(prefixLength));

        case L3Address::IPv6:
            return L3Address(toIpv6().getPrefix(prefixLength));

        case L3Address::MAC:
            if (prefixLength != 48)
                throw cRuntimeError("mask not supported for MacAddress");
            return *this;

        case L3Address::MODULEID:
        case L3Address::MODULEPATH:
            return *this;

        default:
            throw cRuntimeError("getPrefix(): Unknown type");
    }
}

const char *L3Address::getTypeName(AddressType t)
{
#define CASE(x)    case x: \
        return #x
    switch (t) {
        CASE(NONE);
        CASE(IPv4);
        CASE(IPv6);
        CASE(MAC);
        CASE(MODULEID);
        CASE(MODULEPATH);

        default:
            return "Unknown type";
    }
#undef CASE
}

ClnsAddress L3Address::toClns() const
{
    switch (getType()) {
        case L3Address::NONE:
            return ClnsAddress();

        case L3Address::CLNS:
            return ClnsAddress((hi & 0x0000FFFFFFFF0000L) >> 16, lo, (hi & 0xFF00L) >> 8);

        default:
            throw cRuntimeError("Address is not of the given type");
    }
}

MacAddress L3Address::mapToMulticastMacAddress() const
{
    ASSERT(isMulticast());

    int id = 0;
    switch (getType()) {
        case L3Address::IPv4:
            return toIpv4().mapToMulticastMacAddress();
        case L3Address::IPv6:
            return toIpv6().mapToMulticastMacAddress();
        case L3Address::MAC:
            return toMac();
        case L3Address::MODULEID: {
            ModuleIdAddress moduleIdAddress = toModuleId();
            id = moduleIdAddress.getId();
            MacAddress macAddress;
            macAddress.setAddressByte(0, 0x01);
            macAddress.setAddressByte(1, 0x00);
            macAddress.setAddressByte(2, (id >> 24) & 0xFF);
            macAddress.setAddressByte(3, (id >> 16) & 0xFF);
            macAddress.setAddressByte(4, (id >> 8)  & 0xFF);
            macAddress.setAddressByte(5, (id >> 0)  & 0xFF);
            return macAddress;
        }
        case L3Address::MODULEPATH: {
            ModulePathAddress modulePathAddress = toModulePath();
            id = modulePathAddress.getId();
            MacAddress macAddress;
            macAddress.setAddressByte(0, 0x01);
            macAddress.setAddressByte(1, 0x00);
            macAddress.setAddressByte(2, (id >> 24) & 0xFF);
            macAddress.setAddressByte(3, (id >> 16) & 0xFF);
            macAddress.setAddressByte(4, (id >> 8)  & 0xFF);
            macAddress.setAddressByte(5, (id >> 0)  & 0xFF);
            return macAddress;
        }
        default:
            throw cRuntimeError("Unknown address type");
    }
}

} // namespace inet

