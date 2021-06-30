#						THE 2048 GAME VARIANT
---------------------------------------------------------------------------

This is the famous 2048 game written in C with some variations.
The variations include subtraction,multiplication and division operations in addition to the plain doubling operations at tile mergers.

----------------------------------------------------------------------------

SAMPLE RUN (post compilation: gcc game.c)

Command:  ./a.out

Output:   

Welcome to the 2048 family game!!!
The Initial State of the board is: 
_ _ _ 2 
_ _ _ 2 
_ _ _ _ 
_ _ _ _ 

Command: ADD LEFT

Output:
2 _ _ _ 
2 _ _ _ 
_ 2 _ _ 
_ _ _ _ 

Command: ADD RIGHT

Output:
_ _ 4 2 
_ _ _ 2 
_ _ _ 2 
_ _ _ _ 

Command:  ADD UP

Output:
_ _ 4 4 
_ _ 2 2 
_ _ _ _ 
_ _ _ _ 

Command: ADD DOWN

Output:
_ _ _ _ 
_ _ _ _ 
2 _ 4 4 
_ _ 2 2

Command: SUBTRACT LEFT

Output:
_ _ _ _ 
_ _ _ _ 
2 _ _ _ 
_ 2 _ _ 

Command: SUBTRACT RIGHT

Output:
_ _ _ _ 
_ _ _ _ 
_ _ 2 2 
_ _ _ 2 

Command: SUBTRACT UP

Output:
_ _ 2 2 
_ _ _ _ 
_ _ _ _ 
_ _ _ _ 

Command: SUBTRACT DOWN

Output:
_ _ _ _ 
_ _ _ _ 
_ 2 _ _ 
_ _ 2 2 

Command: MULTIPLY LEFT

Output:
_ _ _ _ 
_ _ 4 _ 
2 _ _ _ 
4 _ _ _ 

Command: MULTIPLY RIGHT

Output:
_ 2 _ _ 
_ _ _ 4 
_ _ _ 2 
_ _ _ 4 

Command: MULTIPLY UP

Output:
_ 2 _ 4 
_ 4 _ 2 
_ _ _ 4 
_ _ _ _ 

Command: MULTIPLY DOWN

Output:
_ _ _ _ 
_ _ _ 4 
2 2 _ 2 
_ 4 _ 4 

Command: DIVIDE LEFT

Output:
_ _ _ _ 
4 _ _ _ 
1 2 _ _ 
1 _ 4 _ 

Command: DIVIDE RIGHT

Output:
_ _ 2 _ 
_ _ _ 4 
_ _ 1 2 
_ _ 1 4 

Command: DIVIDE UP

Output:
_ _ 2 4 
4 _ 1 2 
_ _ _ 4 
_ _ _ _ 

Command: DIVIDE DOWN

Output:
4 _ _ _ 
_ _ _ 4 
_ _ 2 2 
4 _ 1 4 
-------------------------------------------------------------------------------

NOTE:

1) If user types "exit", the game will end.
2) If 2048 is achieved, the user will win and game ends
3) If command is invalid, there will be a prompt to enter a valid command.

-------------------------------------------------------------------------------
