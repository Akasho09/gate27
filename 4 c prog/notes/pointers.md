#


## Near, Far and Huge Pointers in C 
- Near, Far and Huge pointers are memory-model concepts associated with `16-bit Intel 8086 architecture and Turbo C.`
- They were used to access memory in systems where the address space was larger than the directly accessible segment.
- These are `not standard C pointer` types. They are compiler/platform-specific extensions.

1. Near pointer = 2 bytes
Near → Offset only (16 bits).

2. Far pointer  = 4 bytes
Far → Segment + Offset (32 bits).

3. Huge pointer = 4 bytes
Huge → Segment + Offset (32 bits).

