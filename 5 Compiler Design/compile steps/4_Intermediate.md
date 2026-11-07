# Intermediate Code Gen :
- Intermediate Code Generation (ICG) is the fourth phase of a compiler. It converts the source program into an intermediate representation (IR) that is independent of the target machine.

## 2. Why Intermediate Code is Required?
1. Machine Independence: IR is independent of a particular target machine.
2. Code Optimization: Makes optimization easier.
3. Portability: Same intermediate code can be translated into different target machines.
4. Compiler Design: Separates the front end from the back end.
5. Efficiency: Helps generate efficient target code.

## 3. Types of Intermediate Representations
Important IR forms for GATE:
1. Syntax Tree / Abstract Syntax Tree (AST)
2. Directed Acyclic Graph (DAG)
3. Three Address Code (TAC)
4. Postfix Notation
5. Bytecode (in certain compiler implementations)

## Three Address Code (TAC) 
is an intermediate representation (IR) used in compilers.
- Each instruction contains at most three addresses:
- Two operands
- One result
It breaks complex expressions into simple instructions using temporary variables.
1. General Form
- x = y op z

## abstract syntax tree
- AST is generated during Syntax Analysis and is also used in Semantic Analysis and subsequent compiler phases.

### 3. Properties of AST
1. It is a tree data structure.
2. Internal nodes generally represent operators or constructs.
3. Leaf nodes generally represent identifiers and constants.
4. It removes unnecessary syntactic details.
5. It represents operator precedence and associativity.
6. It is useful for semantic analysis and code generation.

### 5. Applications of AST
- Semantic Analysis.
- Type Checking.
- Intermediate Code Generation.
- Code Optimization.
- Static Code Analysis.
- Compiler Design and Code Transformation.

### Points :
1. (a) Syntax analysis phase output is an abstract syntax tree.
2. (b) Abstract syntax tree is a condensed form of parse tree.
3. (c) Abstract syntax tree should not have keywords as leaves.

