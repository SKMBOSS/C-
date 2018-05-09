/***********************************************************************************************************************************
* <clss HoldBlock >                                                                                                               *
*  홀드 블럭판 담당                                                                                                               *
************************************************************************************************************************************/
#ifndef __HOLDBLOCK_H__
#define __HOLDBLOCK_H__

#include <curses.h>
#include <iostream>

class HoldBlock
{
private:
	WINDOW *holdBlockBoard;
	int board[6][10];
public : 
	
	void initBoard();
	void setBoard(int &tet); //보드판 바꾸기


	void setwindow()
	{
		holdBlockBoard = newwin(6, 10, 5, 2); //행 열크기, 위치
	}
	void print(); 
	void end(); 

};
#endif