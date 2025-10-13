#include<stdio.h>
#include<stdlib.h>

void initializeBoard();
int DeterminingOutcome();
char Board[10]={'0','1','2','3','4','5','6','7','8','9'};

int main()
{
	int currentPlayer=1;
	int playerIndex=-1;
	int cellNumberToChange;
	
	char playInput;
	
	do
	{
		initializeBoard();
		
		currentPlayer = (currentPlayer%2)? 1:2;
		
		printf("player %d, enter a number:", currentPlayer);
		
		scanf("%d", &cellNumberToChange);
		
		playInput = (currentPlayer == 1 ) ? 'X':'O';
		
		if(cellNumberToChange == 1 && Board[1] == '1')
		{
			Board[1] = playInput;
		}
		
		else if(cellNumberToChange == 2 && Board[2] == '2')
		{
			Board[2] = playInput;
		}
		else if(cellNumberToChange == 3 && Board[3] == '3')
		{
			Board[3] = playInput;
		}
		else if(cellNumberToChange == 4 && Board[4] == '4')
		{
			Board[4] = playInput;
		}
		else if(cellNumberToChange == 5 && Board[5] == '5')
		{
			Board[5] = playInput;
		}
		else if(cellNumberToChange == 6 && Board[6] == '6')
		{
			Board[6] = playInput;
		}
		else if(cellNumberToChange == 7 && Board[7] == '7')
		{
			Board[7] = playInput;
		}
		else if(cellNumberToChange == 8 && Board[8] == '8')
		{
			Board[8] = playInput;
		}
		else if(cellNumberToChange == 9 && Board[9] == '9')
		{
			Board[9] = playInput;
		}
		else
		{
			printf("INVALID MOVE!!!");
			currentPlayer--;
			
			getch();
		}
		
		playerIndex= DeterminingOutcome();
		currentPlayer++;
		
	} while (playerIndex == -1);
	
	InitializeBoard();
	
	if (playerIndex == 1)
	{
		printf("\aPlayer %d won the game!", --currentPlayer);
	}
	else
	{
		printf("game is a draw!");
	}
	getch();
	
}

void initializeBoard()
{
	
	system("cls");
	printf("\n\n\tTic-Tac-Toe 2-Player \n\n");
	
	printf("Player 1 plays as X\n");
	printf("Player 2 plays as O\n\n\n");
	
	printf("	|	|	|\n");
	
	printf(" %c | %c | %c |\n", Board[1], Board[2], Board[3]);
	
	printf("____|____|____|\n");
	printf("	|	 |	  |\n");
	
	printf(" %c | %c | %c |\n", Board[4], Board[5], Board[6]);
	
	printf("____|____|____|\n");
	printf("	|	 |	  |\n");
	
	printf(" %c | %c | %c |\n", Board[7], Board[8], Board[9]);
	
	printf("	|	|	|\n");
	
}

int DeterminingOutcome()
{
	if(Board[1] == Board[2] && Board[2]==Board[3])
	{
		return 1;
	}
	
	else if(Board[4] == Board[5] && Board[5]==Board[6])
	{
		return 1;
	}
	else if(Board[7] == Board[8] && Board[8]==Board[9])
	{
		return 1;
	}
	else if(Board[1] == Board[4] && Board[4]==Board[7])
	{
		return 1;
	}
	else if(Board[2] == Board[5] && Board[5]==Board[8])
	{
		return 1;
	}
	else if(Board[3] == Board[6] && Board[6]==Board[9])
	{
		return 1;
	}
	else if(Board[1] == Board[5] && Board[5]==Board[9])
	{
		return 1;
	}
	else if(Board[3] == Board[5] && Board[5]==Board[7])
	{
		return 1;
	}
	
	else if(Board[1] != '1' && Board[2] != '2' && Board[3] != '3' 
	&& Board[4] != '4' && Board[5] != '5' && Board[6] != '6'
	 && Board[7] != '7' && Board[8] != '8' && Board[9] != '9')
	
	{
		return 0;
	}
	
	else
	{
		return -1;
	}
	
}

