///OBLOCK

#include "OBLOCK.h"

void OBLOCK::setBoard(GameBoard& gameboard)
{
	gameboard.board[r][c]=1;
	gameboard.board[r][c+2]=1;
	gameboard.board[r+1][c]=1;
	gameboard.board[r+1][c+2]=1;
}

void OBLOCK::clearBoard(GameBoard& gameboard)
{
	gameboard.board[r][c]=0;
	gameboard.board[r][c+2]=0;
	gameboard.board[r+1][c]=0;
	gameboard.board[r+1][c+2]=0;
}

bool OBLOCK::isEdge(GameBoard& gameboard)
{
	if(gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c+2]!=0)
		return true;

	else
		return false;
}

bool OBLOCK::isEdgeCrash(GameBoard& gameboard)
{
	if(gameboard.board[r][c]!=0 ||  gameboard.board[r+1][c]!=0 || gameboard.board[r][c+2]!=0 ||  gameboard.board[r+1][c+2]!=0 )
		return true;

	else
		return false;

}

void OBLOCK::dropBlock( GameBoard& gameboard)
{
	while(true)
	{
		if(gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c+2]!=0)
		{
			gameboard.board[r][c]=1;
			gameboard.board[r][c+2]=1;
			gameboard.board[r+1][c]=1;
			gameboard.board[r+1][c+2]=1;

			break;
		}

		r++;
	}
}