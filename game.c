#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 4     // it is a 4 * 4 matrix
int board[SIZE][SIZE];   //Game Board
int generateRandom(int low,int high)    // generate a random number in the range [low,high]
{
	int num=(rand()%(high-low+1))+low;
	return num;
}
void introMessage()
{
	printf("Welcome to the 2048 family game!!!\n");
}
void randomFill()      //insert a random num(2/4) at an empty cell in the board
{
	int occupied=1;     // if the randomly chosen cell is occupied or not
	while(occupied)
	{
		int cell=generateRandom(0,15);  //since its a 4*4 board, we have 16 cells. so we choose randomly from 0 to 15.
		if(board[cell/SIZE][cell%SIZE]==0)  // cell/SIZE gives the row index and cell%SIZE gives me the column index
		{
			while(1)
			{
				int num=generateRandom(0,4); //since we need either 2 or 4, we take the range 0 to 4
				if(num==2||num==4)     // we fill the empty cell
				{
					board[cell/SIZE][cell%SIZE]=num;
					break;
				}
			}
			occupied=0;    //Since the cell was initially empty, we set occupied as false
		}
	}
}
int compare(int a[SIZE][SIZE],int b[SIZE][SIZE])   //comparison between two states
{
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			if(a[i][j]!=b[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}
void startGame()
{
	//empty the board
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			board[i][j]=0;    //0 indicates an empty cell
		}
	}
	//since initially, we have two random filled cells, we do two random fillings.
	randomFill();      
	randomFill();

}
void leftMove(char op)  //covering every possible left move variants
{
	int old[SIZE][SIZE];  //state of the matrix before the operation
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			old[i][j]=board[i][j];   
		}
	}
	for(int i=0; i<SIZE; i++)   // we are going row by row
	{
		int a[SIZE];   // this will be the update row after the operation
		for(int j=0; j<SIZE; j++)
		{
			a[j]=0;
		}
		int k=0;   //pointer to element that has to be filled in updated row
		int isOp=0;     //whether a add/sub/mul/div operation has been performed or not
		for(int j=0; j<SIZE; j++)
		{
			if(board[i][j]!=0)  // non empty
			{
				if(k>0 && board[i][j]==a[k-1] && isOp==0)  //operation is performed here
				{

					if(op=='+')
						a[k-1]*=2;
					else if(op=='-')
						a[k-1]=0;
					else if(op=='*')
						a[k-1]*=a[k-1];
					else                         //division
						a[k-1]=1;
					isOp=1;   //the operation has been performed, so no further operations allowed.
				}
				else    //normal fillup
				{
					a[k]=board[i][j];
					k++;
					isOp=0;
				}
			}
		}
		for(int j=0; j<SIZE; j++)   //updating the board row after the operation
		{
			board[i][j]=a[j];
		}
	}
	if(!compare(old,board))   //if board state as changed, we insert a random tile
		randomFill();

}
void rightMove(char op)
{
	int old[SIZE][SIZE];
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			old[i][j]=board[i][j];
		}
	}
	for(int i=0; i<SIZE; i++)
	{
		int a[SIZE];
		for(int j=0; j<SIZE; j++)
		{
			a[j]=0;
		}
		int k=SIZE-1;
		int isOp=0;

		for(int j=SIZE-1; j>=0; j--)
		{
			if(board[i][j]!=0)
			{
				if(k<SIZE-1 && board[i][j]==a[k+1] && isOp==0)
				{
					if(op=='+')
						a[k+1]*=2;
					else if(op=='-')
						a[k+1]=0;
					else if(op=='*')
						a[k+1]*=a[k+1];
					else
						a[k+1]=1;
					isOp++;
				}
				else
				{
					a[k]=board[i][j];
					k--;
					isOp=0;
				}
			}
		}
		for(int j=SIZE-1; j>=0; j--)
		{
			board[i][j]=a[j];
		}
	}
	if(!compare(old,board))
		randomFill();
}
void upMove(char op)
{
	int old[SIZE][SIZE];
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			old[i][j]=board[i][j];
		}
	}
	for(int i=0; i<SIZE; i++)
	{
		int a[SIZE];
		for(int j=0; j<SIZE; j++)
		{
			a[j]=0;
		}
		int k=0;
		int isOp=0;
		for(int j=0; j<SIZE; j++)
		{
			if(board[j][i]!=0)
			{
				if(k>0 && board[j][i]==a[k-1] && isOp==0)
				{
					if(op=='+')
						a[k-1]*=2;
					else if(op=='-')
					{
						a[k-1]=0;
					}
					else if(op=='*')
						a[k-1]*=a[k-1];
					else
						a[k-1]=1;
					isOp++;
				}
				else
				{
					a[k]=board[j][i];
					k++;
					isOp=0;
				}
			}
		}
		for(int j=0; j<SIZE; j++)
		{
			board[j][i]=a[j];
		}
	}
	if(!compare(old,board))
		randomFill();
}
void downMove(char op)
{
	int old[SIZE][SIZE];
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			old[i][j]=board[i][j];
		}
	}
	for(int i=0; i<SIZE; i++)
	{
		int a[SIZE];
		for(int j=0; j<SIZE; j++)
		{
			a[j]=0;
		}
		int k=SIZE-1;
		int isOp=0;
		for(int j=SIZE-1; j>=0; j--)
		{
			if(board[j][i]!=0)
			{
				if(k<SIZE-1 && board[j][i]==a[k+1] && isOp==0)
				{
					if(op=='+')
						a[k+1]*=2;
					else if(op=='-')
					{
						a[k+1]=0;
					}
					else if(op=='*')
						a[k+1]*=a[k+1];
					else
						a[k+1]=1;
					isOp++;
				}
				else
				{
					a[k]=board[j][i];
					k--;
					isOp=0;
				}
			}
		}
		for(int j=SIZE-1; j>=0; j--)
		{
			board[j][i]=a[j];
		}
	}
	if(!compare(old,board))
		randomFill();
}
void printBoard()   //printing the state of the board
{
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			if(board[i][j]==0)
				printf("_ ");
			else
				printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}
int winState()    //checking if we have got a 2048 tile(the winning mark)
{
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			if(board[i][j]==2048)
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	introMessage();
	startGame();
	printf("The Initial State of the board is: \n");
	printBoard();
	printf("\n");
	while(1)
	{
		char command[100];    
		fgets(command,100,stdin);   //user input  
		if(strncmp(command,"exit",strlen("exit"))==0)
		{
			printf("Game ended by User!!!");
			break;
		}
		else if(strncmp(command,"ADD LEFT",strlen("ADD LEFT"))==0)
		{
			leftMove('+');
		}
		else if(strncmp(command,"MULTIPLY LEFT",strlen("MULTIPLY LEFT"))==0)
		{
			leftMove('*');
		}
		else if(strncmp(command,"SUBTRACT LEFT",strlen("SUBTRACT LEFT"))==0)
		{
			leftMove('-');
		}
		else if(strncmp(command,"DIVIDE LEFT",strlen("DIVIDE LEFT"))==0)
		{
			leftMove('/');
		}
		else if(strncmp(command,"ADD RIGHT",strlen("ADD RIGHT"))==0)
		{
			rightMove('+');
		}
		else if(strncmp(command,"MULTIPLY RIGHT",strlen("MULTIPLY RIGHT"))==0)
		{
			rightMove('*');
		}
		else if(strncmp(command,"SUBTRACT RIGHT",strlen("SUBTRACT RIGHT"))==0)
		{
			rightMove('-');
		}
		else if(strncmp(command,"DIVIDE RIGHT",strlen("DIVIDE RIGHT"))==0)
		{
			rightMove('/');
		}
		else if(strncmp(command,"ADD UP",strlen("ADD UP"))==0)
		{
			upMove('+');
		}
		else if(strncmp(command,"MULTIPLY UP",strlen("MULTIPLY UP"))==0)
		{
			upMove('*');
		}
		else if(strncmp(command,"SUBTRACT UP",strlen("SUBTRACT UP"))==0)
		{
			upMove('-');
		}
		else if(strncmp(command,"DIVIDE UP",strlen("DIVIDE UP"))==0)
		{
			upMove('/');
		}
		else if(strncmp(command,"ADD DOWN",strlen("ADD DOWN"))==0)
		{
			downMove('+');
		}
		else if(strncmp(command,"MULTIPLY DOWN",strlen("MULTIPLY DOWN"))==0)
		{
			downMove('*');
		}
		else if(strncmp(command,"SUBTRACT DOWN",strlen("SUBTRACT DOWN"))==0)
		{
			downMove('-');
		}
		else if(strncmp(command,"DIVIDE DOWN",strlen("DIVIDE DOWN"))==0)
		{
			downMove('/');
		}
		else
		{
			printf("Plz enter a valid command!!!\n");
		}

		printBoard();
		printf("\n");
		if(winState())   //game won!!
		{
			printf("You have won the game!!!\n");
			break;
		}



	}
	return 0;
}