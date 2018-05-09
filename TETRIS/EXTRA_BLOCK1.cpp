///EX_1BLOCK

#include "EXTRA_BLOCK1.h"

void EX_1BLOCK::setBoard(GameBoard& gameboard)
{
	gameboard.board[r][c]=1;
	gameboard.board[r+1][c-2]=1;
	gameboard.board[r+1][c+2]=1;
	gameboard.board[r+2][c]=1;
}

void EX_1BLOCK::clearBoard(GameBoard& gameboard)
{
	gameboard.board[r][c]=0;
	gameboard.board[r+1][c-2]=0;
	gameboard.board[r+1][c+2]=0;
	gameboard.board[r+2][c]=0;
}

bool EX_1BLOCK::isEdge(GameBoard& gameboard)
{
	if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c+2]!=0 || gameboard.board[r+3][c]!=0)
		return true;

	else
		return false;
}

bool EX_1BLOCK::isEdgeCrash(GameBoard& gameboard)
{
	if(gameboard.board[r][c]!=0 || gameboard.board[r+1][c-2]!=0 || gameboard.board[r+1][c+2]!=0 || gameboard.board[r+2][c]!=0)
		return true;

	else
		return false;

}

void EX_1BLOCK::dropBlock( GameBoard& gameboard)
{
	while(true)
	{
		if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c+2]!=0 || gameboard.board[r+3][c]!=0)
		{
			gameboard.board[r][c]=1;
			gameboard.board[r+1][c-2]=1;
			gameboard.board[r+1][c+2]=1;
			gameboard.board[r+2][c]=1;

			break;
		}

		r++;
	}
}