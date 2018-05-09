///ZBLOCK
#include "ZBLOCK.h"

void ZBLOCK::setBoard(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		gameboard.board[r][c]=5;
		gameboard.board[r+1][c]=5;
		gameboard.board[r+1][c-2]=5;
		gameboard.board[r+2][c-2]=5;
	}
	else
	{
		gameboard.board[r][c]=5;
		gameboard.board[r+1][c]=5;
		gameboard.board[r][c-2]=5;
		gameboard.board[r+1][c+2]=5;
	}
}

void ZBLOCK::clearBoard(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		gameboard.board[r][c]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r+1][c-2]=0;
		gameboard.board[r+2][c-2]=0;
	}
	else
	{
		gameboard.board[r][c]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r][c-2]=0;
		gameboard.board[r+1][c+2]=0;
	}
}

bool ZBLOCK::isEdge(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		if(gameboard.board[r+3][c-2]!=0 || gameboard.board[r+2][c]!=0)
			return true;

		else
			return false;
	}

	else 
	{
		if(gameboard.board[r+1][c-2]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c+2])
			return true;

		else
			return false;
	}
}

bool ZBLOCK::isEdgeCrash(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		if(gameboard.board[r][c]!=0 ||  gameboard.board[r+1][c]!=0 || gameboard.board[r+1][c-2]!=0 ||  gameboard.board[r+2][c-2]!=0 )
			return true;

		else
			return false;
	}

	else
	{
		if(gameboard.board[r][c]!=0 ||  gameboard.board[r+1][c]!=0 || gameboard.board[r][c-2]!=0 ||  gameboard.board[r+1][c+2]!=0 )
			return true;

		else
			return false;
	}
}

void ZBLOCK::dropBlock(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		while(true)
		{
			if(gameboard.board[r+3][c-2]!=0 || gameboard.board[r+2][c]!=0)
			{
				gameboard.board[r][c]=5;
				gameboard.board[r+1][c]=5;
				gameboard.board[r+1][c-2]=5;
				gameboard.board[r+2][c-2]=5;

				break;
			}

			r++;
		}
	}

	else 
	{
		while(true)
		{
			if(gameboard.board[r+1][c-2]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c+2])
			{
				gameboard.board[r][c]=5;
				gameboard.board[r+1][c]=5;
				gameboard.board[r][c-2]=5;
				gameboard.board[r+1][c+2]=5;

				break;
			}

			r++;
		}
	}

}