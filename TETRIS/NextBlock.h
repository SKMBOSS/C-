/***********************************************************************************************************************************
* <clss NextBlock >                                                                                                               *
*  다음블록 판 담당                                                                                                               *
************************************************************************************************************************************/
#ifndef __NEXTBLOCK_H__
#define __NEXTBLOCK_H__

#include <curses.h>
#include <iostream>

class NextBlock
{
private:
	WINDOW *nextBlockBoard;
	int board[6][10];
public : 
	
	void initBoard();
	void setBoard(int &tet); //보드판 바꾸기


	void setwindow()
	{
		nextBlockBoard = newwin(6, 10, 5, 40); //행 열크기, 위치
	}
	void print(); 
	void end(); 

};
#endif