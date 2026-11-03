# 

## LAN, MAN, WAN, PAN , CAN
> P L C M W
| Network | Full Form | Coverage | Example |
|---|---|---|---|
| PAN | Personal Area Network | A few metres | Bluetooth between phone and smartwatch |
| LAN | Local Area Network | Room, building, office | Home Wi-Fi, computer lab |
| CAN | Campus Area Network | Campus or nearby buildings | University network |
| MAN | Metropolitan Area Network | City | City-wide network |
| WAN | Wide Area Network | Country to worldwide | Internet |

## TCP/IP Protocol Suite

1. 5 Layer TCP/IP ==> Application , Presetation and session layer become Application Layer.

2. 4 Layer ===> 5 Layer + (Data Link and Physical Layer become Network Acesses Layer)

## Data → Segment → Packet → Frame → Bits
| OSI Layer | Layer Name | Data Unit (PDU) |
|---:|---|---|
| 7 | Application | Data |
| 6 | Presentation | Data |
| 5 | Session | Data |
| 4 | Transport | Segment (TCP) / Datagram (UDP) |
| 3 | Network | Packet |
| 2 | Data Link | Frame |
| 1 | Physical | Bits |

- PDU (Protocol Data Unit): Data unit handled by a specific layer, including that layer's protocol control information (usually its header, and sometimes a trailer) plus the data.
- SDU (Service Data Unit): Data passed from the layer above to a layer to be processed by that layer. 
       - ISKI ServicING HOTI HAI

> PDU = PCI + SDU
- Here, PCI (Protocol Control Information) is typically the header added by the current layer. A trailer may also be included.


## Physical layer
- Last layer of sender and first of Reciever.

- Includes Cables and connectors.
- Phyical Topology.
- Uses Repeaters and Hubs.

## Topology :

1. Mesh Topo : All with all
- No of cables : n(n-1)/2;
- No of ports : (n-1)*(n)
- Reliable , No single point Failure.
- Cost  : High.
- Security : Yes.
- Dedicated or Point to Point Communication.

2. Star or Hub : 
Central Hub
- No of Cables : n
- Ports : 1*n
- No Reliablity n single point Failure.
- Cost  : Normal.
- Security : Yes.
- Dedicated or Point to Point Communication.

3. Bus Topo : Central or Backbone cable
- No of Cables : n + 1
- Ports : 1*n
- No Reliablity n single point Failure.
- Cost  : Cheap.
- Security : Less.
- Multi Point Communication

4. Ring :
connect bus topology ends
- No of Cables : n + 1
- Ports : 1*n
- No Reliablity n single point Failure.
- Cost  : Cheap.
- Security : Less.
- Multi Point Communication

## Manchester encoding and differential Manchester encoding

1. Manchester encoding
```yml
1 ===> __
         |__

0 ===>    __
       __|
```
- Revese wrt IEEE.

2.  Differential Manchester encoding
```yml
1 ===> __            __     
         |__   or  __|

0 ===> |  ___  or  |--|__
       |__|        |
```
- 1 is same bu for zero extra line or edge

## Circuit Switching :
- EXAMPLE : Telephone call
1. On Physical Layer
2. Dedicated Path
3. Continous Flow
4. No Readers or Headers
5. Less Efficent
6. Less Delays cz Dedicated Path

> Total Time = SetUp Time + Transmission Time + Propgation Delay + Tear Down Time.

- Transmission Time = Size / Bnadwidth
- Propgation Delay = Distance / Speed

## Packet Switching :
1. Data Link and Network Layer.
2. Store and Forward.
3. Pipeline Used (Parellel sending)
4. Readers and Headers
5. More Efficent
6. More Delays

> Total Time = n*(Transmission Time) + Propgation Delay.
- but Transmission Time is high wrt Circuit Switching
 
- 2 Types :

1. Datagram Switching:
- Connectionless
- Out of Order
- High Overhead
- Packet Loss is high
- Used in Internet.

2. Virtual Switching :
- Connection Oriented
- Reservations (one global packet finds path and reserves that path for all other packets).
- Same order
- Less overhead
- Packet Loss is less
- Example : ATM , X.25

