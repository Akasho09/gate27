# Counters
- A Counter is a sequential logic circuit used to count the number of clock pulses applied to it.
- It consists of a group of flip-flops connected together to represent binary numbers.

1. Basic Concepts of Counters
- A counter is made using:
    - Flip-flops (usually JK, T or D).
    - Clock signal.
    - Logic gates (depending on counter design).

- How many states can a counter represent?
For n flip-flops:
> Maximum states = 2^n.

2. Types of Counters
- 
    1. Asynchronous
    - Ripple Counter
    An Asynchronous Counter is a counter in which all flip-flops do not receive the clock signal simultaneously.
    - The first flip-flop receives the external clock.
    - The second flip-flop receives the output of the first.
    - The third flip-flop receives the output of the second.
    Thus, the clock signal ripples from one flip-flop to another.

    2. Synchronous
    - Common Clock
    A Synchronous Counter is a counter in which all flip-flops receive the same clock signal simultaneously.
    - Unlike an asynchronous counter, the clock is directly connected to every flip-flop.
        - Relatively fast
        - Compelxity Higher

- Other classifications:
    - Up Counter
    - Down Counter
    - Up-Down Counter
    - Mod-N Counter
    - Ring Counter
    - Johnson Counter

