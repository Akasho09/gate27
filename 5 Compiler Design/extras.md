# 

## 
1. Cross-compiler
- A Cross-Compiler is a compiler that runs on one machine (host machine) but generates executable code for another machine (target machine).

2. Native compiler 
is Same Host and Same Target Machine

3. Bootstrap Compiler
- Compiler is developed using the language it compiles

## 
1. Right-Linear Grammar 
- is a type of regular grammar in which the non-terminal (variable) appears only on the right side of the production, at the extreme right position.
- It is also called a Right-Regular Grammar.

2. Left linear grammar
G2: S→Sa | a | ϵ 

3. `Strictly regular grammar` 
has exactly one terminal in RHS and atmost one non terminal in RHS, (ϵ is also allowed).


## Parser and its Derivation
1. Top-Down Parser	-> Left-most derivation
2. Bottom-Up Parser	-> Right-most derivation in reverse

## A Phrase-Structured Grammar (PSG) 
- is the most general type of grammar in the Chomsky hierarchy.
- It is also called an Unrestricted Grammar or Type-0 Grammar.

### Chomsky Hierarchy
- There are four types of grammars:

1. Type 0 — Unrestricted Grammar
Phrase-Structured Grammar

2. Type 1 — Context-Sensitive Grammar

3. Type 2 — Context-Free Grammar

4. Type 3 — Regular Grammar

## 1. Grammar → Language → Automata
Type 0	Unrestricted / Phrase-Structured	Recursively Enumerable (RE)	Turing Machine (TM)
Type 1	Context-Sensitive (CSG)	Context-Sensitive Language (CSL)	Linear Bounded Automaton (LBA)
Type 2	Context-Free (CFG)	Context-Free Language (CFL)	Pushdown Automaton (PDA)
Type 3	Regular Grammar (RG)	Regular Language (RL)	Finite Automaton (FA)

## NOT a Token
1. preprocessors, such as #include<stdio.h>
2. macros, such as #define value 10
3. comments , whitespaces

## The two most important operations of a symbol table are:
1. Insertion: Adding a new identifier (name).
2. Lookup / Inquiry: Searching whether an identifier exists and retrieving its information.
Different symbol table implementations (arrays, linked lists, hash tables, binary search trees, etc.) are compared based on the time required for both operations.

## 14. An ideal compiler should
(c) detect, report and correct errors

## Any bottom up parser scans input from left to right and constructs a right most derivation in reverse.
> LR0 is bottom up ===>> left to right and right most derivation in reverse.

## Remember: Symbol Table is a shared data structure used throughout the compiler.

