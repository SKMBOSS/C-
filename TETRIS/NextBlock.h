/***********************************************************************************************************************************
* <clss NextBlock >                                                                                                               *
*  ������� �� ���                                                                                                               *
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
	void setBoard(int &tet); //������ �ٲٱ�


	void setwindow()
	{
		nextBlockBoard = newwin(6, 10, 5, 40); //�� ��ũ��, ��ġ
	}
	void print(); 
	void end(); 

};
#endif