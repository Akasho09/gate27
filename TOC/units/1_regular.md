# Regular Expressions and Finite Automata
- A regular expression describes a set of strings, called a regular language, over an alphabet `Sigma`.
- A regular language is a formal language that can be recognized by a finite-state machine (such as a Deterministic Finite Automaton or Non-Deterministic Finite Automaton) or described by a regular expression.

- Operators 
1. + : ie Union 	0+1 => either 0 or 1
2. Concatenation : 	Followed by  => 01: string 01
3. Zero or more repetitions	: 0^* = { epsilon,0,00, ... }
4. + as postfix	 : One or more repetitions	0^+ = {0,00,000,..}
5. epsilon : 	Empty string, length 0
6. emptyset : 	Empty language	ie Accepts no strings

- Properties :
| Operation | Regular languages closed? |
|---|---|
| Union | YES |
| Intersection | YES |
| Complement | YES |
| Difference | YES |
| Symmetric difference | YES |
| Concatenation | YES |
| Kleene Star | YES |
| Kleene Plus | YES |
| Reversal | YES |
| Homomorphism | YES |
| Inverse homomorphism | YES |
| Quotient | YES |
> Regular languages are closed under finite union. They are not closed under infinite union of regular languages.
> Subset of regular language may not be regular.
- Consider 
L = 0^*.1^* and
L1 = {0^n.1^n|n>0}. 
L1 is a subset of L but not regular.

### 5. Important GATE facts and tricks
1. Every regular language is context-free.
2. Every finite language is regular.
3. Every infinite regular language has at least one string that can be pumped.
4. A regular language can be recognized by a finite automaton.
5. Regular languages are closed under complement.
6. The complement of a regular language is obtained by swapping final and non-final states in a complete DFA.
7. If L_1,L_2 are regular, then L_1 intersection L_2 is regular.
8. If a language is not regular, no DFA, NFA or regular expression can represent it.

## The Pumping Lemma 
- for Regular Languages is used mainly to prove that a language is `NOT regular`.
- The core idea: a finite automaton has a limited number of states, so sufficiently long strings must revisit a state. This creates a loop that can be repeated or removed.

If a language \(L\) is regular, there exists a pumping length \(p\geq1\) such that every string \(w\in L\) with \(|w|\geq p\) can be divided into three parts:
- w=xyz
satisfying all three conditions:
1. |xy| <= p
2. |y|>0
3. x.y^i.z ě L , forall i >= 0

## Context free grammar
- A Context-Free Grammar (CFG) is a formal grammar used to generate context-free languages. 

1. Formal definition of CFG
A CFG is represented by a four-tuple:
> G=(V,T,P,S)
- V : Set of variables / non-terminals
- T :	Set of terminals
- P :	Set of production rules
- S :	Start symbol

2. Important terminology
- Terminal: Actual symbols appearing in the final string, e.g. a, b.
- Non-terminal: Variables used to generate strings, e.g. S, A, B.
- Production: A replacement rule, e.g. S -> aSb.
- Derivation: Applying production rules to generate a string.
- Sentential form: Any intermediate string during derivation.
- Sentence: A string containing only terminals.

3. CFG's
    1. all strings with equal numbers of a and b
    > S --> aSbS\bSaS\epsilon
    OR
    > S --> aSb / bSa / SS / epsilon

### CFL closure properties 
| Operation | CFL closed? |
|---|---|
| Union | YES |
| Concatenation | YES |
| Kleene Star | YES |
| Reversal | YES |
| Homomorphism | YES |
| Inverse homomorphism | YES |
| Intersection | NO |
| Complement | NO |
| Difference | NO |

### Remove Unit Production from CFG(Context Free Grammar)
1. Make graph of Unit prductions 
2. Replace variables by terminals 
3. Remove terminals whcuh are non reachable


### Remove Null Production from CFG (Context Free Grammar)
1. Find Nullable terminals
2. Replace the production rules with epsilon and add that rule also plus remove the epsilon.

### Important GATE facts
1. Every regular language is CFL.
2. Every CFL is not regular.
3. Every CFL has an equivalent NPDA.
4. CFLs are closed under union but not intersection.
5. CFLs are closed under intersection with regular languages.
6. CFLs are not closed under complement.
> 7. Deterministic CFLs (DCFLs) are closed under complement.
7. DCFLs are closed under intersection with regular languages.
8. DCFLs are not closed under union or general intersection.
> 9. NFA can have less or greater or equal number of states with its corresponding min DFA.

