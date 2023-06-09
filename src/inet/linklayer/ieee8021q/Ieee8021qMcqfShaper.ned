//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package inet.linklayer.ieee8021q;

import inet.queueing.contract.IPacketBuffer;
import inet.queueing.contract.IPacketClassifier;
import inet.queueing.contract.IPacketGate;
import inet.queueing.contract.IPacketQueue;
import inet.queueing.contract.IPacketScheduler;
import inet.queueing.queue.CompoundPacketQueueBase;

//
// This module implements the IEEE 802.1Q time aware shaper.
//
module Ieee8021qMcqfShaper extends CompoundPacketQueueBase
{
    parameters:
        int numTrafficClasses = default(8); // number of traffic categories
        double bitrate @unit(bps);
        *.bitrate = default(this.bitrate);
        *.extraLength = default(64b); // overhead for Ethernet PHY header
    submodules:
        buffer: <default("")> like IPacketBuffer if typename != "" {
            parameters:
                @display("p=100,225");
        }
        classifier: <default("PcpMcqfClassifier")> like IPacketClassifier {
            parameters:
                @display("p=100,100");
        }
        queue[numTrafficClasses]: <default("PacketQueue")> like IPacketQueue {
            parameters:
                bufferModule = default(exists(parent.buffer) ? "^.buffer" : "");
                @display("p=300,100,column,125");
        }
        transmissionSelectionAlgorithm[numTrafficClasses]: <default("")> like IPacketGate {
            parameters:
                @display("p=500,100,column,125");
        }
        transmissionGate[numTrafficClasses]: <default("PeriodicGate")> like IPacketGate {
            parameters:
                @display("p=700,100,column,125");
        }
        transmissionSelection: <default("PriorityScheduler")> like IPacketScheduler {
            parameters:
                reverseOrder = default(true);
                @display("p=900,100");
        }
    connections:
        in --> { @display("m=w"); } --> classifier.in;
        for i = 0 .. numTrafficClasses - 1 {
            classifier.out++ --> queue[i].in;
            queue[i].out --> transmissionSelectionAlgorithm[i].in;
            transmissionSelectionAlgorithm[i].out --> transmissionGate[i].in;
            transmissionGate[i].out --> transmissionSelection.in++;
        }
        transmissionSelection.out --> { @display("m=e"); } --> out;
}