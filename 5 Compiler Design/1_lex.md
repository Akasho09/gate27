# COMPILER DESIGN

## Six Phases of Compiler
1. Lexical Analysis
- Source code → Tokens

2. Syntax Analysis
- Tokens → Parse Tree / AST

3. Semantic Analysis
- Type checking and semantic validation

4. Intermediate Code Generation
- AST → Intermediate Code

5. Code Optimization
- Optimized Intermediate Code

6. Target Code Generation
- Target Machine Code


## Lexical Analysis
Lexical Analysis is the first phase of a compiler. It reads the source program character by character and converts it into a sequence of tokens.
- Converts source code into tokens.
- Removes whitespace, comments, etc . comments are replaced by whitespace.
- Identifies keywords, identifiers, operators and constants.
- Uses Regular Expressions and Finite Automata (DFA/NFA).

1. Token
A token is a category or class of lexical units.
Examples:
- Identifier
- Keyword
- Operator
- Constant
- Separator

2.  Lexeme
A lexeme is the actual sequence of characters in the source program that matches a token's pattern.

3. Pattern
A pattern is a rule that describes the set of lexemes belonging to a token.

### 3. Functions of Lexical Analyzer
The main responsibilities are:
1. Read source code character by character.
2. Group characters into lexemes.
3. Generate tokens.
4. Remove whitespace, tabs, newlines and comments (except when significant to language syntax).
5. Enter identifiers into the Symbol Table or retrieve their entries.
6. Detect lexical errors.
7. Pass tokens to the Syntax Analyzer.

### 6. Important Rules of Lexical Analysis
1. Longest Match Rule (Maximal Munch)
When multiple lexemes can be recognized, the lexical analyzer chooses the longest possible prefix that matches a token.
- a >= b
The operator >= is recognized as a single token, not as > and = separately.

2. B. Priority Rule
If two token patterns match the same longest lexeme, the lexical analyzer uses priority rules.

3. C. Lookahead
Sometimes the lexical analyzer needs to read an additional character to determine where a token ends.

4. Input Buffering
Reading one character at a time directly from a file is inefficient.

Therefore, lexical analyzers use input buffering to improve performance.

5. Lexical Errors
A lexical error occurs when the scanner encounters an invalid character sequence.

## First and Follow
 
### 1. FIRST Set
FIRST of a grammar symbol or string is the set of terminals that can appear as the first symbol of strings derived from it.

1. If S derives terminal then terminal is first of S/
2. If S derives Variable then First of Variable is First of S.
3. If First of Variable is epsilon then put epsilon in Equation of S.

### 4. FOLLOW Set
- FOLLOW(A) is the set of terminals that can appear immediately to the right of non-terminal A in some sentential form.

1. Rule 1: Start symbol
Always include $ (end marker) in the FOLLOW of the start symbol.

2. Rule 2: Symbol followed by a terminal
terminal is Follow of Symbol

3. Rule 3: Symbol followed by a non-terminal
First of non temrinal is Follow of Symbol

4. Follow of Last is Follow of Start Symbol

