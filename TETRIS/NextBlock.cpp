/*NextBlockBoard Function*/
#include "NextBlock.h"


void NextBlock::initBoard()
{
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<10; j++)
		{
			board[i][j]=0;
		}
	}

}


void NextBlock::end()
{
	delwin(nextBlockBoard); 
}

void NextBlock::print()
{
	wattron(nextBlockBoard, COLOR_PAIR(1));  
	for(int i=1; i<=4; i++)
	{
		for(int j=1; j<=7; j+=2)
		{
			if(board[i][j] == 0)
			{ 
				mvwprintw(nextBlockBoard, i, j, "□"); 
				wrefresh(nextBlockBoard); 
			}
			else
			{
				wattron(nextBlockBoard, COLOR_PAIR(board[i][j]+2)); 
				mvwprintw(nextBlockBoard, i, j, "■");
				wattroff(nextBlockBoard, COLOR_PAIR(board[i][j]+2)); 
				wattron(nextBlockBoard, COLOR_PAIR(1)); 
				wrefresh(nextBlockBoard); 
			}
		}

	}//지정위치 문자열 출력
	wattroff(nextBlockBoard, COLOR_PAIR(1));
	wborder(nextBlockBoard, '|','|','-','-','+','+','+','+');
	wrefresh(nextBlockBoard);  
}

void NextBlock::setBoard(int &tet) //보드판 바꾸기
{
	initBoard(); //판초기화

	if(tet==0)
	{
		board[1][1] =1;
		board[1][3] =1;
		board[2][1] =1;
		board[2][3] =1;
	}

	else if(tet==1)
	{
		board[1][3] =2;
		board[2][3] =2;
		board[3][3] =2;
		board[3][5] =2;
	}

	else if(tet==2)
	{
		board[1][3] =3;
		board[2][3] =3;
		board[3][3] =3;
		board[3][1] =3;
	}

	else if(tet==3)
	{
		board[1][3] =4;
		board[2][3] =4;
		board[2][5] =4;
		board[3][5] =4;
	}

	else if(tet==4)
	{
		board[1][3] =5;
		board[2][3] =5;
		board[2][1] =5;
		board[3][1] =5;
	}

	else if(tet==5)
	{
		board[1][3] =6;
		board[2][3] =6;
		board[2][1] =6;
		board[2][5] =6;
	}

	else if(tet==6)
	{
		board[1][3] =7;
		board[2][3] =7;
		board[3][3] =7;
		board[4][3] =7;
	}
	else if(tet==7)
	{
	board[1][3]=1;
	board[2][1]=1;
	board[2][5]=1;
	board[3][3]=1;
	}

	else if(tet==8)
	{
		board[1][3]=7;
		board[3][3]=7;
	}

}
