///TBLOCK
#include "TBLOCK.h"

void TBLOCK::setBoard(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		gameboard.board[r][c]=6;
		gameboard.board[r+1][c]=6;
		gameboard.board[r+1][c+2]=6;
		gameboard.board[r+1][c-2]=6;
	}

	else if(rotateForm%4==1)
	{
		gameboard.board[r+1][c-2]=6;
		gameboard.board[r+1][c]=6;
		gameboard.board[r][c]=6;
		gameboard.board[r+2][c]=6;
	}

	else if(rotateForm%4==2)
	{
		gameboard.board[r+2][c]=6;
		gameboard.board[r+1][c]=6;
		gameboard.board[r+1][c+2]=6;
		gameboard.board[r+1][c-2]=6;
	}

	else
	{
		gameboard.board[r+1][c+2]=6;
		gameboard.board[r+1][c]=6;
		gameboard.board[r][c]=6;
		gameboard.board[r+2][c]=6;
	}

}

void TBLOCK::clearBoard(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		gameboard.board[r][c]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r+1][c+2]=0;
		gameboard.board[r+1][c-2]=0;
	}

	else if(rotateForm%4==1)
	{
		gameboard.board[r+1][c-2]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r][c]=0;
		gameboard.board[r+2][c]=0;
	}

	else if(rotateForm%4==2)
	{
		gameboard.board[r+2][c]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r+1][c+2]=0;
		gameboard.board[r+1][c-2]=0;
	}

	else
	{
		gameboard.board[r+1][c+2]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r][c]=0;
		gameboard.board[r+2][c]=0;
	}
}

bool TBLOCK::isEdge(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c+2]!=0 || gameboard.board[r+2][c]!=0)
			return true;

		else
			return false;
	}


	else if(rotateForm%4==1)
	{
		if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+3][c]!=0)
			return true;

		else
			return false;
	}
	else if(rotateForm%4==2)
	{
		if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c+2]!=0 || gameboard.board[r+3][c]!=0)
			return true;

		else
			return false;
	}

	else
	{
		if(gameboard.board[r+2][c+2]!=0 || gameboard.board[r+3][c]!=0)
			return true;

		else
			return false;
	}
}

bool TBLOCK::isEdgeCrash(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		if(gameboard.board[r][c]!=0 ||  gameboard.board[r+1][c]!=0 || gameboard.board[r+1][c-2]!=0 ||  gameboard.board[r+1][c+2]!=0 )
			return true;

		else
			return false;
	}

	else if(rotateForm%4==1)
	{
		if(gameboard.board[r+1][c-2]!=0 || gameboard.board[r+1][c]!=0 || gameboard.board[r][c]!=0 || gameboard.board[r+2][c]!=0)
			return true;

		else
			return false;
	}

	else if(rotateForm%4==2)
	{
		if(gameboard.board[r+2][c]!=0 || gameboard.board[r+1][c]!=0 || gameboard.board[r+1][c+2]!=0 || gameboard.board[r+1][c-2]!=0)
			return true;

		else
			return false;
	}

	else
	{
		if(gameboard.board[r+1][c+2]!=0 || gameboard.board[r+1][c]!=0 || gameboard.board[r][c]!=0 || gameboard.board[r+2][c]!=0)
			return true;

		else
			return false;
	}
}

void TBLOCK::dropBlock(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		while(true)
		{
			if(gameboard.board[r+2][c+2]!=0 || gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c]!=0)
			{
				gameboard.board[r][c]=6;
				gameboard.board[r+1][c]=6;
				gameboard.board[r+1][c+2]=6;
				gameboard.board[r+1][c-2]=6;

				break;
			}

			r++;
		}
	}

	else if(rotateForm%4==1)
	{
		while(true)
		{
			if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+3][c]!=0)
			{
				gameboard.board[r+1][c-2]=6;
				gameboard.board[r+1][c]=6;
				gameboard.board[r][c]=6;
				gameboard.board[r+2][c]=6;

				break;
			}

			r++;
		}
	}

	else if(rotateForm%4==2)
	{
		while(true)
		{
			if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c+2]!=0 || gameboard.board[r+3][c]!=0)
			{
				gameboard.board[r+2][c]=6;
				gameboard.board[r+1][c]=6;
				gameboard.board[r+1][c+2]=6;
				gameboard.board[r+1][c-2]=6;

				break;
			}

			r++;
		}
	}

	else
	{
		while(true)
		{
			if(gameboard.board[r+2][c+2]!=0 || gameboard.board[r+3][c]!=0)
			{
				gameboard.board[r+1][c+2]=6;
				gameboard.board[r+1][c]=6;
				gameboard.board[r][c]=6;
				gameboard.board[r+2][c]=6;

				break;
			}

			r++;
		}
	}

}