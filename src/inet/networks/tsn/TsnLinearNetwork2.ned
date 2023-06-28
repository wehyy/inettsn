//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


package inet.networks.tsn;

import inet.networks.base.TsnNetworkBase;
import inet.node.contract.IEthernetNetworkNode;
import inet.node.ethernet.EthernetLink;
import inet.node.ethernet.Eth100M;
import inet.node.inet.Router;

network TsnLinearNetwork2 extends TsnNetworkBase
{
    parameters:
        *.eth[*].bitrate = default(100Mbps);
    submodules:
        client: <default("TsnDevice")> like IEthernetNetworkNode {
            @display("p=350,200");
        }
        switch1: <default("TsnSwitch")> like IEthernetNetworkNode {
            @display("p=550,200");
        }
        router1: Router {
            @display("p=750,200;i=device/smallrouter");
        }
        router2: Router {
            @display("p=950,200;i=device/smallrouter");
        }
        switch2: <default("TsnSwitch")> like IEthernetNetworkNode {
            @display("p=1150,200");
        }
        server: <default("TsnDevice")> like IEthernetNetworkNode {
            @display("p=1350,200");
        }
    connections:
        client.ethg++ <--> Eth100M <--> switch1.ethg++;
        switch1.ethg++ <--> Eth100M <--> router1.ethg++;
        router1.pppg++ <--> Eth100M <--> router2.pppg++;
        router2.ethg++ <--> Eth100M <--> switch2.ethg++;
        switch2.ethg++ <--> Eth100M <--> server.ethg++;
}

