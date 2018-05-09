/*holdBlockBoard Function*/
#include "HoldBlock.h"


void HoldBlock::initBoard()
{
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<10; j++)
		{
			board[i][j]=0;
		}
	}

}


void HoldBlock::end()
{
	delwin(holdBlockBoard); 
}

void HoldBlock::print()
{
	wattron(holdBlockBoard, COLOR_PAIR(1));  
	for(int i=1; i<=4; i++)
	{
		for(int j=1; j<=7; j+=2)
		{
			if(board[i][j] == 0)
			{ 
				mvwprintw(holdBlockBoard, i, j, "□"); 
				wrefresh(holdBlockBoard); 
			}
			else
			{
				wattron(holdBlockBoard, COLOR_PAIR(board[i][j]+2)); 
				mvwprintw(holdBlockBoard, i, j, "■");
				wattroff(holdBlockBoard, COLOR_PAIR(board[i][j]+2)); 
				wattron(holdBlockBoard, COLOR_PAIR(1)); 
				wrefresh(holdBlockBoard); 
			}
		}

	}//지정위치 문자열 출력
	wattroff(holdBlockBoard, COLOR_PAIR(1));
	wborder(holdBlockBoard, '|','|','-','-','+','+','+','+');
	wrefresh(holdBlockBoard);  
}

void HoldBlock::setBoard(int &tet) //보드판 바꾸기
{
	initBoard(); //판초기화

	if(tet==0)
	{
		board[1][1] =1;
		board[1][3] =1;
		board[2][1] =1;
		board[2][3] =1;
	}

	else if(tet==1 || tet==11 || tet==12 || tet==13)
	{
		board[1][3] =2;
		board[2][3] =2;
		board[3][3] =2;
		board[3][5] =2;
	}

	else if(tet==2 || tet==21 || tet==22 || tet==23)
	{
		board[1][3] =3;
		board[2][3] =3;
		board[3][3] =3;
		board[3][1] =3;
	}

	else if(tet==3 || tet==31)
	{
		board[1][3] =4;
		board[2][3] =4;
		board[2][5] =4;
		board[3][5] =4;
	}

	else if(tet==4 || tet==41)
	{
		board[1][3] =5;
		board[2][3] =5;
		board[2][1] =5;
		board[3][1] =5;
	}

	else if(tet==5 || tet==51 || tet==52 || tet==53)
	{
		board[1][3] =6;
		board[2][3] =6;
		board[2][1] =6;
		board[2][5] =6;
	}

	else if(tet==6 || tet==61)
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
