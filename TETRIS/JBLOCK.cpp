///JBLOCK
#include "JBLOCK.h"

void JBLOCK::setBoard(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		gameboard.board[r][c]=3;
		gameboard.board[r+1][c]=3;
		gameboard.board[r+2][c]=3;
		gameboard.board[r+2][c-2]=3;
	}

	else if(rotateForm%4==1)
	{
		gameboard.board[r+1][c-2]=3;
		gameboard.board[r+1][c]=3; //기준
		gameboard.board[r+1][c+2]=3;
		gameboard.board[r+2][c+2]=3;
	}

	else if(rotateForm%4==2)
	{
		gameboard.board[r][c]=3;
		gameboard.board[r+1][c]=3;
		gameboard.board[r+2][c]=3;
		gameboard.board[r][c+2]=3;
	}

	else
	{
		gameboard.board[r][c-2]=3; //기준
		gameboard.board[r+1][c-2]=3;
		gameboard.board[r+1][c]=3;
		gameboard.board[r+1][c+2]=3;
	}

}

void JBLOCK::clearBoard(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		gameboard.board[r][c]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r+2][c]=0;
		gameboard.board[r+2][c-2]=0;
	}

	else if(rotateForm%4==1)
	{
		gameboard.board[r+1][c-2]=0;
		gameboard.board[r+1][c]=0; //기준
		gameboard.board[r+1][c+2]=0;
		gameboard.board[r+2][c+2]=0;
	}

	else if(rotateForm%4==2)
	{
		gameboard.board[r][c]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r+2][c]=0;
		gameboard.board[r][c+2]=0;
	}

	else
	{
		gameboard.board[r][c-2]=0; //기준
		gameboard.board[r+1][c-2]=0;
		gameboard.board[r+1][c]=0;
		gameboard.board[r+1][c+2]=0;
	}
}

bool JBLOCK::isEdge(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		if(gameboard.board[r+3][c]!=0 || gameboard.board[r+3][c-2]!=0)
			return true;

		else
			return false;
	}

	else if(rotateForm%4==1)
	{
		if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+3][c+2])
			return true;

		else
			return false;
	}

	else if(rotateForm%4==2)
	{
		if(gameboard.board[r+3][c]!=0 || gameboard.board[r+1][c+2]!=0)
			return true;

		else
			return false;
	}

	else
	{
		if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c+2]!=0)
			return true;

		else
			return false;
	}
}

bool JBLOCK::isEdgeCrash(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		if(gameboard.board[r][c]!=0 ||  gameboard.board[r+1][c]!=0 || gameboard.board[r+2][c]!=0 ||  gameboard.board[r+2][c-2]!=0 )
			return true;

		else
			return false;
	}

	else if(rotateForm%4==1)
	{
		if(gameboard.board[r+1][c-2]!=0 || gameboard.board[r+1][c]!=0 || gameboard.board[r+1][c+2]!=0 || gameboard.board[r+2][c+2]!=0)
			return true;

		else
			return false;
	}

	else if(rotateForm%4==2)
	{
		if(gameboard.board[r][c]!=0 || gameboard.board[r+1][c]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r][c+2]!=0)
			return true;

		else
			return false;
	}

	else
	{
		if(gameboard.board[r][c-2]!=0 || gameboard.board[r+1][c-2]!=0 || gameboard.board[r+1][c]!=0 || gameboard.board[r+1][c+2]!=0)
			return true;

		else
			return false;
	}


}

void JBLOCK::dropBlock(GameBoard& gameboard)
{
	if(rotateForm%4==0)
	{
		while(true)
		{
			if(gameboard.board[r+3][c]!=0 || gameboard.board[r+3][c-2]!=0)
			{
				gameboard.board[r][c]=3;
				gameboard.board[r+1][c]=3;
				gameboard.board[r+2][c]=3;
				gameboard.board[r+2][c-2]=3;

				break;
			}

			r++;
		}
	}

	else if(rotateForm%4==1)
	{
		while(true)
		{
			if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+3][c+2])
			{
				gameboard.board[r+1][c-2]=3;
				gameboard.board[r+1][c]=3; //기준
				gameboard.board[r+1][c+2]=3;
				gameboard.board[r+2][c+2]=3;

				break;
			}

			r++;
		}
	}

	else if(rotateForm%4==2)
	{
		while(true)
		{
			if(gameboard.board[r+3][c]!=0 || gameboard.board[r+1][c+2]!=0)
			{
				gameboard.board[r][c]=3;
				gameboard.board[r+1][c]=3;
				gameboard.board[r+2][c]=3;
				gameboard.board[r][c+2]=3;
				break;
			}

			r++;
		}
	}

	else
	{
		while(true)
		{
			if(gameboard.board[r+2][c-2]!=0 || gameboard.board[r+2][c]!=0 || gameboard.board[r+2][c+2]!=0)
			{
				gameboard.board[r][c-2]=3; //기준
				gameboard.board[r+1][c-2]=3;
				gameboard.board[r+1][c]=3;
				gameboard.board[r+1][c+2]=3;

				break;
			}

			r++;
		}
	}

}