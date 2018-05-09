/*GameBoard Function*/

#include "GameBoard.h"



void GameBoard::initBoard()
{
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<22; j++)
		{
			if(i==19 || j==0 || j==21)
				board[i][j]=1;
			else
				board[i][j]=0;
		}
	}

}

void GameBoard::print()
{
	wattron(gameBoard, COLOR_PAIR(1));  
	for(int i=1; i<=18; i++)
	{
		for(int j=1; j<=19; j+=2)
		{
			if(board[i][j] == 0)
			{ 
				mvwprintw(gameBoard, i, j, "□"); 
				wrefresh(gameBoard); 
			}
			else
			{
				wattron(gameBoard, COLOR_PAIR(board[i][j]+2)); 
				mvwprintw(gameBoard, i, j, "■");
				wattroff(gameBoard, COLOR_PAIR(board[i][j]+2)); 
				wattron(gameBoard, COLOR_PAIR(1)); 
				wrefresh(gameBoard); 
			}
		}

	}//지정위치 문자열 출력
	wattroff(gameBoard, COLOR_PAIR(1));
	wborder(gameBoard, '|','|','-','-','+','+','+','+');
	mvwprintw(gameBoard,0,8,"Tetris");
	wrefresh(gameBoard);  
}

void GameBoard::end()
{
	delwin(gameBoard); 
}

bool GameBoard::isGameOver()
{
	for(int j=1; j<=19; j+=2)
	{
		if(board[0][j] != 0)
			return true;
	}
	return false;
}

int GameBoard::crashBlock()
{
	int crashBlockNum=0;
	int count =0;


	for(int i=1; i<=18; i++)
	{
		for(int j=1; j<=19; j+=2)
		{
			if(board[i][j] !=0) count++;
		}

		if(count == 10)
		{

			for(int j=1; j<=19; j+=2)
				board[i][j] =0;
			crashBlockNum++;

		}
		count=0;
	}

	for(int k=0; k<crashBlockNum; k++)
	{
		for(int i=18; i>=2; i--)
		{
			for(int j=1; j<=19; j+=2)
			{
				if(board[i][j] ==0) count++;
			}

			if(count == 10)
			{

				for(int j=1; j<=19; j+=2)
				{
					board[i][j] =board[i-1][j];
					board[i-1][j]=0;

				}

			}
			count=0;
		}
	}

	return crashBlockNum;
}

