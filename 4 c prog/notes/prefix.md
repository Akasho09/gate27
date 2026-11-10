# 
1. Infix	Between operands	A + B
2. Prefix	Before operands	+ A B
3. Postfix	After operands	A B +

##  Prefix to Postfix
- Important: Scan the prefix expression from RIGHT to LEFT.
Steps:
1. Start scanning from the rightmost character.
2. If the character is an operand, push it onto the stack.
3. If the character is an operator:
   - Pop two operands from the stack.
   - First popped element = operand 1.
   - Second popped element = operand 2.
   - Combine them as operand1 + operand2 + operator.
   - Push the resulting expression back onto the stack.
4. At the end, the stack contains the postfix expression.

