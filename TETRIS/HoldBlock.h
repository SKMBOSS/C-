/***********************************************************************************************************************************
* <clss HoldBlock >                                                                                                               *
*  Ȧ�� ���� ���                                                                                                               *
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
	void setBoard(int &tet); //������ �ٲٱ�


	void setwindow()
	{
		holdBlockBoard = newwin(6, 10, 5, 2); //�� ��ũ��, ��ġ
	}
	void print(); 
	void end(); 

};
#endif