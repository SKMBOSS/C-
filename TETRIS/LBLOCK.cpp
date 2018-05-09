///LBLOCK
#include "LBLOCK.h"

void LBLOCK::setBoard(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		gameboard.board[r][c]=2;
		gameboard.board[r+1][c]=2;
		gameboard.board[r+2][c]=2;
		gameboard.board[r+2][c+2]=2;
	}

	else if(rotateForm%4==1)
	{
		gameboard.board[r][c+2]=2; 
		gameboard.board[r+1][c+2]=2;
		gameboard.board[r+1][c]=2;
		gameboard.board[r+1][c-2]=2;
	}

	else if(rotateForm%4==2)
	{
		gameboard.board[r][c]=2;
		gameboard.board[r+1][c]=2;
		gameboard.board[r+2][c]=2;
		gameboard.board[r][c-2]=2;
	}

	else
	{
		gameboard.board[r+1][c]=2; //기준
		gameboard.board[r+1][c-2]=2;
		gameboard.board[r+1][c+2]=2;
		gameboard.board[r+2][c-2]=2;
	}
}

void LBLOCK::clearBoard(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		gameboard.board[r][c]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r+2][c]=0;
		gameboard.board[r+2][c+2]=0;
	}

	else if(rotateForm%4==1)
	{
		gameboard.board[r][c+2]=0; 
		gameboard.board[r+1][c+2]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r+1][c-2]=0;
	}

	else if(rotateForm%4==2)
	{
		gameboard.board[r][c]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r+2][c]=0;
		gameboard.board[r][c-2]=0;
	}

	else
	{
		gameboard.board[r+1][c]=0; //기준
		gameboard.board[r+1][c-2]=0;
		gameboard.board[r+1][c+2]=0;
		gameboard.board[r+2][c-2]=0;
	}
}

bool LBLOCK::isEdge(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		if(gameboard.board[r+3][c]!=0 || gameboard.board[r+3][c+2]!=0)
			return true;

		else
			return false;
	}


	else if(rotateForm%4==1)
	{
		if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c+2])
			return true;

		else
			return false;
	}

	else if(rotateForm%4==2)
	{
		if(gameboard.board[r+3][c]!=0 || gameboard.board[r+1][c-2]!=0)
			return true;

		else
			return false;
	}

	else
	{
		if(gameboard.board[r+3][c-2]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c+2])
			return true;

		else
			return false;
	}
}

bool LBLOCK::isEdgeCrash(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		if(gameboard.board[r][c]!=0 ||  gameboard.board[r+1][c]!=0 || gameboard.board[r+2][c]!=0 ||  gameboard.board[r+2][c+2]!=0 )
			return true;

		else
			return false;
	}

	else if(rotateForm%4==1)
	{
		if(gameboard.board[r][c+2]!=0 ||gameboard.board[r+1][c+2]!=0 || gameboard.board[r+1][c]!=0 || gameboard.board[r+1][c-2]!=0)
			return true;

		else
			return false;
	}

	else if(rotateForm%4==2)
	{
		if(gameboard.board[r][c]!=0 || gameboard.board[r+1][c]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r][c-2]!=0 )
			return true;

		else
			return false;
	}

	else
	{
		if(gameboard.board[r+1][c]!=0 || gameboard.board[r+1][c-2]!=0 || gameboard.board[r+1][c+2]!=0 || gameboard.board[r+2][c-2]!=0)
			return true;

		else
			return false;
	}



}

void LBLOCK::dropBlock(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		while(true)
		{
			if(gameboard.board[r+3][c]!=0 || gameboard.board[r+3][c+2]!=0)
			{
				gameboard.board[r][c]=2;
				gameboard.board[r+1][c]=2;
				gameboard.board[r+2][c]=2;
				gameboard.board[r+2][c+2]=2;

				break;
			}

			r++;
		}
	}

	else if(rotateForm%4==1)
	{
		while(true)
		{
			if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c+2])
			{
				gameboard.board[r][c+2]=2; //기준
				gameboard.board[r+1][c+2]=2;
				gameboard.board[r+1][c]=2;
				gameboard.board[r+1][c-2]=2;

				break;
			}

			r++;
		}
	}

	else if(rotateForm%4==2)
	{
		while(true)
		{
			if(gameboard.board[r+3][c]!=0 || gameboard.board[r+1][c-2]!=0)
			{
				gameboard.board[r][c]=2;
				gameboard.board[r+1][c]=2;
				gameboard.board[r+2][c]=2;
				gameboard.board[r][c-2]=2;

				break;
			}

			r++;
		}
	}

	else 
	{
		while(true)
		{
			if(gameboard.board[r+3][c-2]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c+2])
			{
				gameboard.board[r+1][c]=2; //기준
				gameboard.board[r+1][c-2]=2;
				gameboard.board[r+1][c+2]=2;
				gameboard.board[r+2][c-2]=2;

				break;
			}

			r++;
		}
	}
}
