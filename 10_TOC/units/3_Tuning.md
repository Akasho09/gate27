# Turing Machine (TM)

## Turing Machine (TM) modifications
- A Turing Machine (TM) can be modified in several ways to make its design easier. These modifications do not increase its computational power.
1. More tapes ≠ More computational power.
2. More heads ≠ More computational power.
3. NTM = DTM in computational power.
4. These modifications may change time complexity.
5. No standard modification listed above can solve an undecidable problem that a basic TM cannot solve.

- Power comparision :
> FA < DPDA < NPDA < LBA < TM

## Recursive vs Recursive Enumerable Languages
1. Recursive Language (Decidable Language)
A language \(L\) is called Recursive if there exists a Turing Machine that:
- Accepts every string belonging to \(L\).
- Rejects every string not belonging to \(L\).
- Always halts (accepts or rejects)
> In other words, a TM must give a definite YES or NO answer for every input.


2. Recursively Enumerable Language (RE)
A language \(L\) is called Recursively Enumerable (RE) if there exists a Turing Machine that:
- Accepts every string belonging to \(L\).
- For strings not belonging to \(L\), it may reject OR loop forever.
- It is `not necessary to halt` for every input.

6. Important Closure Properties
Operation	    Recursive	    RE
Complement	    Closed	        Not closed
Difference	    Closed	        Not closed
Homomorpshism   Not Closed	    Closed
Substitution    Not Closed      Closed



