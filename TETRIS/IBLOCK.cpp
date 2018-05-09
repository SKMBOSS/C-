//IBLOCK
#include "IBLOCK.h"

void IBLOCK::setBoard(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		gameboard.board[r][c]=7;
		gameboard.board[r+1][c]=7;
		gameboard.board[r+2][c]=7;
		gameboard.board[r+3][c]=7;
	}

	else
	{
		gameboard.board[r+1][c-2]=7;
		gameboard.board[r+1][c]=7;
		gameboard.board[r+1][c+2]=7;
		gameboard.board[r+1][c+4]=7;
	}
}

void IBLOCK::clearBoard(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		gameboard.board[r][c]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r+2][c]=0;
		gameboard.board[r+3][c]=0;
	}

	else
	{
		gameboard.board[r+1][c-2]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r+1][c+2]=0;
		gameboard.board[r+1][c+4]=0;
	}
}

bool IBLOCK::isEdge(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		if(gameboard.board[r+4][c]!=0 )
			return true;

		else
			return false;
	}

	else
	{
		if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c+2]!=0 || gameboard.board[r+2][c+4]!=0)
			return true;

		else
			return false;
	}
}

bool IBLOCK::isEdgeCrash(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		if(gameboard.board[r][c]!=0 ||  gameboard.board[r+1][c]!=0 || gameboard.board[r+2][c]!=0 ||  gameboard.board[r+3][c]!=0 )
			return true;

		else
			return false;
	}
	else
	{
		if(gameboard.board[r+1][c]!=0 ||  gameboard.board[r+1][c-2]!=0 || gameboard.board[r+1][c+2]!=0 ||  gameboard.board[r+1][c+4]!=0 )
			return true;

		else
			return false;
	}
}

void IBLOCK::dropBlock(GameBoard& gameboard)
{
	if(rotateForm%2==0)
	{
		while(true)
		{
			if(gameboard.board[r+4][c]!=0)
			{
				gameboard.board[r][c]=7;
				gameboard.board[r+1][c]=7;
				gameboard.board[r+2][c]=7;
				gameboard.board[r+3][c]=7;

				break;
			}

			r++;
		}
	}

	else
	{
		while(true)
		{
			if(gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c+2]!=0 || gameboard.board[r+2][c+4]!=0)
			{
				gameboard.board[r+1][c-2]=7;
				gameboard.board[r+1][c]=7;
				gameboard.board[r+1][c+2]=7;
				gameboard.board[r+1][c+4]=7;

				break;
			}

			r++;
		}
	}
}

