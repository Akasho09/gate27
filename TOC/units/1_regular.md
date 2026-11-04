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

## The Pumping Lemma 
- for Regular Languages is used mainly to prove that a language is `NOT regular`.
- The core idea: a finite automaton has a limited number of states, so sufficiently long strings must revisit a state. This creates a loop that can be repeated or removed.

If a language \(L\) is regular, there exists a pumping length \(p\geq1\) such that every string \(w\in L\) with \(|w|\geq p\) can be divided into three parts:
- w=xyz
satisfying all three conditions:
1. |xy| <= p
2. |y|>0
3. x.y^i.z ě L , forall i >= 0
