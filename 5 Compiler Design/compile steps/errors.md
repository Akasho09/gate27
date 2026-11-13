#

## Error Detection and Recovery | Lexical Phase Errors
1. What is a Lexical Error?
A Lexical Error occurs during the lexical analysis phase when the Lexical Analyzer (Scanner) encounters an invalid sequence of characters that cannot form a valid token.

2. Common Types of Lexical Errors
    1. Illegal character	int @a;	Invalid character
    2. Invalid identifier	int 2abc;	Identifier cannot start with a digit
    3. Unterminated string	"Hello	Missing closing quotation mark
    4. Unterminated comment	/* Hello	Missing closing */
    5. Invalid numeric constant	12.3.4	Malformed number
    6. Invalid escape sequence	"\q"	Invalid escape sequence

3. Error Recovery Techniques in Lexical Analysis
When a lexical analyzer encounters an error, it can use the following techniques to recover.

1. Panic Mode Recovery
    - Skip characters until a valid token boundary is found.
    - Resume lexical analysis.
```c
int a = 10 @#$; 
int b = 20;
```
- The scanner may skip invalid characters @#$ and continue scanning.

2. Delete an Extra Character
Remove an unnecessary character.
- Example:
int a = 10;;
Delete the extra semicolon if it is identified as an invalid character in the current context.

3. Insert a Missing Character
- Insert a missing character to form a valid token.
Example:
"Hello
The scanner may insert a closing quotation mark.

4. Replace an Incorrect Character
Replace an invalid character with a valid one.
- Example:
int a = 10#;
- Replace # with an appropriate valid character.

5. Transpose Adjacent Characters
Swap two adjacent characters.
- Example:
fi (a > b)
- Swap f and i to obtain if.

## Transcription Error 
A Transcription Error occurs when a programmer accidentally writes a character or sequence of characters incorrectly while entering source code.
- It is a type of lexical error.
Correct code	        Incorrect code	Error
while	                whille	        Extra character
int	                    innt	        Extra character
if		                fi	           	Transposition of characters
count		            coun#t	        Illegal character


