//SBOLCK
#include "SBLOCK.h"

void SBLOCK::setBoard(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		gameboard.board[r][c]=4;
		gameboard.board[r+1][c]=4;
		gameboard.board[r+1][c+2]=4;
		gameboard.board[r+2][c+2]=4;
	}
	else
	{
		gameboard.board[r][c]=4;
		gameboard.board[r+1][c]=4;
		gameboard.board[r][c+2]=4;
		gameboard.board[r+1][c-2]=4;

	}
}

void SBLOCK::clearBoard(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		gameboard.board[r][c]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r+1][c+2]=0;
		gameboard.board[r+2][c+2]=0;
	}

	else
	{
		gameboard.board[r][c]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r][c+2]=0;
		gameboard.board[r+1][c-2]=0;
	}
}

bool SBLOCK::isEdge(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		if(gameboard.board[r+3][c+2]!=0 || gameboard.board[r+2][c]!=0)
			return true;

		else
			return false;
	}

	else
	{
		if(gameboard.board[r+1][c+2]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c-2])
			return true;

		else
			return false;
	}
}

bool SBLOCK::isEdgeCrash(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		if(gameboard.board[r][c]!=0 ||  gameboard.board[r+1][c]!=0 || gameboard.board[r+1][c+2]!=0 ||  gameboard.board[r+2][c+2]!=0 )
			return true;

		else
			return false;
	}
	else
	{
		if(gameboard.board[r][c]!=0 ||  gameboard.board[r+1][c]!=0 || gameboard.board[r][c+2]!=0 ||  gameboard.board[r+1][c-2]!=0 )
			return true;

		else
			return false;
	}
}

void SBLOCK::dropBlock(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		while(true)
		{
			if(gameboard.board[r+3][c+2]!=0 || gameboard.board[r+2][c]!=0)
			{
				gameboard.board[r][c]=4;
				gameboard.board[r+1][c]=4;
				gameboard.board[r+1][c+2]=4;
				gameboard.board[r+2][c+2]=4;

				break;
			}

			r++;
		}
	}

	else
	{
		while(true)
		{
			if(gameboard.board[r+1][c+2]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c-2])
			{
				gameboard.board[r][c]=4;
				gameboard.board[r+1][c]=4;
				gameboard.board[r][c+2]=4;
				gameboard.board[r+1][c-2]=4;

				break;
			}

			r++;
		}
	}
}
