## 1. IPv4 addressing, subnetting and CIDR

### IPv4 basics
- IPv4 address length: **32 bits**.
- A prefix `/n` means **n network bits** and `32 − n` host bits.
- Addresses per subnet: \(2^{32-n}\).
- For a conventional subnet, usable host addresses are \(2^{32-n}-2\), excluding the network and broadcast addresses. Special cases such as `/31` point-to-point links and `/32` host routes need separate treatment.
- To support at least \(H\) usable hosts, choose host bits \(h\) such that \(2^h-2 \ge H\); prefix length is \(32-h\).

### Subnet masks
- Mask bits: network bits are 1; host bits are 0.
- Block size in the interesting octet: \(256-\text{mask octet}\).
- Subnet/network address = IP address AND subnet mask.
- Broadcast address = network address OR inverse subnet mask.
- Subnet ranges advance by the block size in the octet where the mask is not 255 or 0.

### Classful IPv4 ranges (historical)
| Class | First octet | Default prefix | Typical use |
|---|---:|---:|---|
| A | 1–126 | /8 | Large networks 2^31 |
| B | 128–191 | /16 | Medium networks 2^30|
| C | 192–223 | /24 | Small networks 2^29 |
| D | 224–239 | — | Multicast 2^28|
| E | 240–255 | — | Experimental/reserved 2^27|

> 127.0.0.0/8 is loopback. Modern routing uses CIDR rather than classful allocation.

### Speacial cases : 
1. If Host id bits are all 0's => Network Id.

2. If Host id bits are all 1's => Direct Broadcast Address(Always Destination IP).

3. If Netwrok id bits are all 1's and Host id bits are all 0's => Network Subnet mask.

4. If Netwrok id bits are all 1's and Host id bits are all 1's => Limited Broadcast Address (Always Destination IP).
- 255.255.255.255

### Private IPv4 blocks
- `10.0.0.0/8`
- `172.16.0.0/12` (172.16–172.31 in the second octet)
- `192.168.0.0/16`

###  1.5 Subnetting and supernetting
1. Subnetting: divides one network into smaller networks. The prefix becomes longer.

2. Supernetting (route aggregation): combines contiguous networks into a larger address block. The prefix becomes shorter.

![alt text](image-1.png)

### ERROR CONTROL:
1. Error detection and correction
- If the data rate is R bits/s and noise corrupts a signal for duration t seconds
> Potentially affected bits=R*t

### 2.2 Hamming distance
- Hamming distance is the number of bit positions in which two codewords differ.
> To detect s errors, minimum distance must be at least s+1.
> To correct t errors, minimum distance must be at least 2t+1.

### CIDR aggregation
- A group of equal-sized, aligned networks can be summarized by a shorter prefix.
- The addresses must be contiguous and the block size must be a power of 2.
- The first network address must be aligned to the aggregate block size.
- Common trick: convert addresses to binary and count the common leading bits; that count is the aggregate prefix.

## 2. Delay, throughput and switching

### Delay components
- Transmission delay: \(d_{trans}=L/R\), where packet length \(L\) is in bits and link rate \(R\) is in bits/s.
- Propagation delay: \(d_{prop}=D/v\), where distance \(D\) is in metres and propagation speed \(v\) is in m/s.
- Total one-link delay (without queueing/processing): \(L/R+D/v\).
- Bandwidth-delay product: \(BDP=R\times d_{prop}\) bits.
- Throughput cannot exceed the bottleneck link rate; actual throughput may be lower because of protocol overhead, loss, and congestion.

### Circuit vs packet switching
- Circuit switching reserves a path/resources before data transfer.
- Datagram packet switching routes each packet independently; packets may follow different paths and arrive out of order.
- Virtual-circuit packet switching establishes a logical path; packets generally follow that logical route.
- Store-and-forward switching generally requires a router to receive a complete packet before forwarding it.

### Pipelining
For \(N\) packets, \(P\) links, packet transmission time \(t=L/R\), and equal link rates, ignoring propagation and processing:
- Store-and-forward, no pipelining: approximately \(NPt\).
- With pipelining: approximately \((P+N-1)t\).
- Add propagation, processing, setup, or ACK time only when the question asks for them.

## 3. Error detection and correction

### Hamming distance
- Hamming distance is the number of bit positions in which two codewords differ.
- Minimum distance \(d_{min}\) detects up to \(d_{min}-1\) bit errors.
- Minimum distance \(d_{min}\) corrects up to \(\lfloor(d_{min}-1)/2\rfloor\) bit errors.
- To correct \(t\) errors, require \(d_{min}\ge 2t+1\).
- To detect \(s\) errors, require \(d_{min}\ge s+1\).

### CRC
1. Append r zeros to the data, where r is the generator polynomial degree.
2. Divide modulo-2 (XOR, no carries/borrows) by the generator.
3. The \(r\)-bit remainder is the CRC; append it to the original data.
4. The receiver divides the received codeword by the same generator. A zero remainder indicates no detected error, not a guarantee that no error occurred.
- Generator degree \(r\) produces an \(r\)-bit CRC.
- CRC detects all burst errors of length <= r , provided the generator has the standard nonzero constant term.

### Hamming code
- Let \(m\) be data bits and \(r\) parity bits. Choose the smallest \(r\) satisfying \(2^r >= m+r+1\).
- Parity bits occupy positions \(1,2,4,8,\ldots\) (powers of 2); data bits fill the other positions.
- Parity bit at position \(2^k\) checks positions whose binary index has bit \(k\) set.
- Syndrome 0 indicates no detected single-bit error; a nonzero syndrome gives the erroneous bit position under the single-error-correction assumption.
- A standard Hamming code has \(d_{min}=3\), correcting one error. Adding an overall parity bit gives SECDED (single-error correction, double-error detection).

## 4. Data-link protocols and sliding windows

Let \(T_t=L/R\) be frame transmission time and \(T_p\) be one-way propagation delay. Define \(a=T_p/T_t\).

Let:
- \(L\) = frame length in bits.
- \(R\) = link bandwidth in bits/s.
- \(d\) = distance between sender and receiver.
- \(v\) = propagation speed.
- \(T_t\) = transmission delay.
- \(T_p\) = one-way propagation delay.

> T_t= L / R
> T_p= d / v

Link bandwidth-delay product:
> BDP=R * T_p

### Stop-and-Wait ARQ
For an error-free link, negligible ACK transmission time, and no processing delay:
\[
U=\frac{T_t}{T_t+2T_p}=\frac{1}{1+2a}
\]
- With an ACK transmission time \(T_{ack}\), include it in the cycle time as specified by the question.
- If the frame carries \(L_d\) useful data bits and total cycle time is \(T_{cycle}\), useful throughput is \(L_d/T_{cycle}\).

### Go-Back-N (GBN)
- With an \(m\)-bit sequence number, sequence space is \(2^m\).
- Maximum sender window: \(W_s\le 2^m-1\).
- Receiver window is normally 1.
- On loss/error, retransmit the missing frame and subsequent outstanding frames as required by GBN.

### Selective Repeat (SR)
- Sender and receiver windows are both bounded by half the sequence space to avoid ambiguity:
\[
W_s,W_r\le 2^{m-1}
\]
- Retransmits only lost/damaged frames (and frames not acknowledged before timeout).
- For a full-rate sliding-window link under common idealized assumptions:
\[
U=\min\left(1,\frac{W}{1+2a}\right)
\]
Use the exact assumptions stated in the problem; ACK time, piggybacking, and timeout behavior can change the result.

## 5. Random access and Ethernet

### ALOHA
- Pure ALOHA: \(S=Ge^{-2G}\), maximum throughput \(S_{max}=1/(2e)\approx 0.184\) (18.4%).
- Slotted ALOHA: \(S=Ge^{-G}\), maximum throughput \(S_{max}=1/e\approx 0.368\) (36.8%).
- \(G\) is the average number of transmission attempts per packet time, including retransmissions.

### CSMA/CD and Ethernet
- CSMA/CD: sense carrier, transmit if idle, detect collision, send jam signal, back off, retry.
- Binary exponential backoff: after collision number \(i\), choose a random integer from a range that grows exponentially (Ethernet commonly uses \(0\) through \(2^k-1\), with \(k=\min(i,10)\)); wait that many slot times.
- Slot time must be long enough for a collision to propagate back to the transmitting station.
- For classic shared Ethernet, the minimum frame size is tied to the round-trip propagation delay and collision detection requirement.
- CSMA/CD is for shared, half-duplex Ethernet; switched full-duplex Ethernet does not use collision detection.

## 6. IPv4 header and fragmentation

### Header length
- IPv4 minimum header: 20 bytes (IHL = 5).
- IPv4 maximum header: 60 bytes (IHL = 15).
- IHL is measured in 32-bit words, so header bytes = \(4\times IHL\).
- Total Length is measured in bytes and includes the IPv4 header plus payload.

### Fragmentation
Let original payload be \(P\) bytes and outgoing MTU be \(M\) bytes. With a 20-byte IPv4 header and no options:
- Maximum payload per fragment is \(8\lfloor(M-20)/8\rfloor\) bytes for fragments that need an 8-byte-aligned payload.
- Fragment offset is measured in **8-byte units**, not bytes.
- Offset of a fragment = number of original payload bytes before that fragment divided by 8.
- All fragments except the final fragment normally carry payload lengths divisible by 8.
- Total length of each fragment = its own header length + its payload length.
- MF (More Fragments) = 1 for all fragments except the final fragment; final fragment has MF = 0.
- Fragments from one original datagram share the Identification value.
- Reassembly occurs at the destination host.

## 7. TCP and UDP

### TCP vs UDP
| Feature | TCP | UDP |
|---|---|---|
| Connection | Connection-oriented | Connectionless |
| Reliability | Reliable byte stream | No built-in delivery guarantee |
| Ordering | In-order byte stream | No built-in ordering |
| Flow control | Yes | No built-in flow control |
| Congestion control | Yes | No built-in congestion control |
| Header size | Minimum 20 bytes | 8 bytes |
| Common uses | Web, file transfer, email transport | DNS, voice/video, lightweight request/response |

### TCP sequence and acknowledgement numbers
- TCP sequence numbers count **bytes**, not segments.
- ACK number is the next byte expected.
- SYN consumes one sequence number; FIN also consumes one.
- For a segment starting at sequence number \(x\) carrying \(n\) data bytes, the next sequence number is \(x+n\), plus 1 if a SYN or FIN flag consumes sequence space.
- Sequence number field is 32 bits; sequence numbers wrap modulo \(2^{32}\).

### TCP three-way handshake
1. Client → server: SYN, sequence number \(x\).
2. Server → client: SYN+ACK, sequence number \(y\), acknowledgement \(x+1\).
3. Client → server: ACK, acknowledgement \(y+1\).

### TCP header
- Minimum TCP header: 20 bytes; maximum: 60 bytes.
- Data Offset is measured in 32-bit words.
- Window field advertises the receiver's available buffer space (with window scaling negotiated where applicable).
- Checksum covers the TCP header and data plus the IP pseudo-header.
- Common flags: SYN, ACK, FIN, RST, PSH, URG; ECN-related flags may also appear.

### Retransmission timeout (RTO)
- TCP estimates RTT using measured round-trip samples and smooths the estimate; the RTO includes a variation margin.
- A common textbook form is \(RTO=SRTT+4\times RTTVAR\); exact update equations depend on the TCP specification/version used.
- Retransmission timeout is not simply the raw RTT; timer backoff can increase RTO after repeated timeouts.

### TCP congestion control (high-level)
- Slow start grows congestion window rapidly (approximately doubling each RTT in idealized conditions).
- Congestion avoidance grows congestion window approximately linearly.
- On congestion signals/loss, TCP reduces its sending rate/window according to the congestion-control algorithm.
- Distinguish receiver advertised window (flow control) from congestion window (network congestion control). Effective sending window is bounded by both.

### TCP connection termination
- A typical orderly close uses FIN/ACK exchanges in both directions; it commonly involves four segments, although ACK and FIN may be combined.
- TIME_WAIT helps ensure delayed duplicate segments expire and allows retransmission of the final ACK if needed.

### UDP header
- Fixed header size: 8 bytes.
- Four 16-bit fields: Source `Port`, Destination Port, Length, Checksum.
- UDP Length includes header and data; minimum legal length is 8 bytes.
> If port value is >1023 then it's a client 
- and if <1023 then it's server.

## 8. Token bucket

- Token bucket permits bursts while controlling the long-term average rate.
- Tokens arrive at rate \(r\), up to bucket capacity \(B\).
- A packet of size \(L\) bytes (or bits, consistently with units) can be sent when enough tokens are available.
- Over an interval of length \(t\), a common upper bound on traffic is:
\[
\text{traffic}\le B+rt
\]
provided units are consistent. The bucket capacity limits the burst; token rate controls the long-term average.

## 9. Common application protocols and ports

| Protocol | Well-known port(s) | Typical purpose |
|---|---|---|
| FTP | TCP 20/21 | File transfer (data/control roles depend on mode) |
| SSH | TCP 22 | Secure remote login |
| SMTP | TCP 25; submission commonly 587 | Sending/relaying email |
| DNS | UDP/TCP 53 | Name resolution; TCP used in cases such as zone transfer or large responses |
| DHCPv4 | UDP 67/68 | Dynamic IPv4 configuration (server/client) |
| HTTP | TCP 80 by default | Web traffic |
| HTTPS | TCP 443 commonly | HTTP over TLS; HTTP/3 uses QUIC over UDP |
| POP3 | TCP 110 | Retrieve email |
| IMAP | TCP 143 | Access/manage email on server |
| TFTP | UDP 69 | Simple file transfer |
| SNMP | UDP 161/162 | Management queries / traps or notifications |

Ports are conventional defaults; deployments may configure alternatives.

## 10. HTTP, FTP and SMTP command reminders

- HTTP methods commonly tested: GET, HEAD, POST, PUT, PATCH, DELETE, OPTIONS.
- GET retrieves a representation; HEAD returns headers without the response body; POST submits data for processing; PUT generally replaces/creates a resource at the target URI; PATCH applies a partial modification; DELETE requests deletion.
- FTP uses a separate control connection and data connection; active/passive mode affects how the data connection is established.
- SMTP is used to submit/relay outgoing mail; POP3 and IMAP are used by clients to retrieve/access mail.

## 11. Fast formula recap

| Topic | Formula / rule |
|---|---|
| IPv4 addresses in /n | \(2^{32-n}\) |
| Conventional usable hosts in /n | \(2^{32-n}-2\) |
| Transmission delay | \(L/R\) |
| Propagation delay | \(D/v\) |
| Bandwidth-delay product | \(R\times d_{prop}\) |
| Stop-and-Wait utilization | \(1/(1+2a)\), under idealized assumptions |
| GBN max sender window | \(2^m-1\) |
| SR max window | \(2^{m-1}\) |
| Pure ALOHA max throughput | \(1/(2e)\approx18.4\%\) |
| Slotted ALOHA max throughput | \(1/e\approx36.8\%\) |
| IPv4 header bytes | \(4\times IHL\) |
| Fragment offset | Payload byte offset / 8 |
| Hamming parity bits | smallest \(r\) with \(2^r\ge m+r+1\) |
| Detection capability | up to \(d_{min}-1\) errors |
| Correction capability | up to \(\lfloor(d_{min}-1)/2\rfloor\) errors |
| Token bucket traffic bound | \(B+rt\) over interval \(t\) |

## 12. Common GATE traps

1. **Bits vs bytes:** transmission delay uses bits when rate is in bits/s; IPv4 Total Length and MTU are in bytes.
2. **Propagation vs transmission:** packet size affects transmission delay, not propagation delay.
3. **One-way vs round-trip:** Stop-and-Wait commonly includes a round trip for data plus ACK, hence \(2T_p\) in the denominator.
4. **Window sizes:** GBN allows \(2^m-1\); SR allows at most \(2^{m-1}\).
5. **Fragment offsets:** measured in 8-byte units, not bytes.
6. **TCP sequence numbers:** count bytes, not segments; SYN and FIN each consume one sequence number.
7. **CRC:** zero remainder means no error was detected, not proof that the packet is error-free.
8. **Hamming distance:** detection and correction formulas are different.
9. **ALOHA:** pure ALOHA peaks at about 18.4%; slotted ALOHA at about 36.8%.
10. **Flow vs congestion control:** receiver window protects the receiver; congestion window protects the network.
11. **CIDR:** usable-host \(-2\) is a conventional subnet rule with special cases; do not blindly apply it to /31 or /32.
12. **Assumptions matter:** use the exact header sizes, ACK delays, propagation assumptions, and retransmission rules stated in the question.

---
*Revision note: This is a formula-focused summary of the Computer Networks topics covered in the conversation. For numerical questions, write down the units and assumptions first, then substitute values.*
