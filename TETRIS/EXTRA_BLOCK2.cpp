///EX_2BLOCK

#include "EXTRA_BLOCK2.h"

void EX_2BLOCK::setBoard(GameBoard& gameboard)
{
	gameboard.board[r][c]=7;
	gameboard.board[r+2][c]=7;
	gameboard.board[r+4][c]=7;
	gameboard.board[r+6][c]=7;
}

void EX_2BLOCK::clearBoard(GameBoard& gameboard)
{
	gameboard.board[r][c]=0;
	gameboard.board[r+2][c]=0;
	gameboard.board[r+4][c]=0;
	gameboard.board[r+6][c]=0;
}

bool EX_2BLOCK::isEdge(GameBoard& gameboard)
{
	if(gameboard.board[r+7][c]!=0)
		return true;

	else
		return false;
}

bool EX_2BLOCK::isEdgeCrash(GameBoard& gameboard)
{
	if(gameboard.board[r][c]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+4][c]!=0 || gameboard.board[r+6][c]!=0)
		return true;

	else
		return false;

}

void EX_2BLOCK::dropBlock( GameBoard& gameboard)
{
	while(true)
	{
		if(gameboard.board[r+7][c]!=0)
		{
			gameboard.board[r][c]=7;
			gameboard.board[r+2][c]=7;
			gameboard.board[r+4][c]=7;
			gameboard.board[r+6][c]=7;

			break;
		}

		r++;
	}
}