//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


package inet.networks.tsn;

import inet.networks.base.TsnNetworkBase;
import inet.node.contract.IEthernetNetworkNode;
import inet.node.ethernet.EthernetLink;
import inet.node.ethernet.Eth100M;
import inet.node.inet.StandardHost;

network TsnLinearNetwork3 extends TsnNetworkBase
{
    parameters:
        *.eth[*].bitrate = default(100Mbps);
    submodules:
        client: <default("StandardHost")> like IEthernetNetworkNode {
            @display("p=350,200");
        }
        router: <default("Router")> like IEthernetNetworkNode {
            @display("p=750,200;i=device/smallrouter");
        }
        server: <default("StandardHost")> like IEthernetNetworkNode {
            @display("p=1150,200");
        }
    connections:
        client.ethg++ <--> Eth100M <--> router.ethg++;
        router.ethg++ <--> Eth100M <--> server.ethg++;
}

