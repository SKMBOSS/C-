/***********************************************************************************************************************************
* <clss GameBoard>                                                                                                                 *
*  ��Ʈ���� �������� ���                                                                                                          *
************************************************************************************************************************************/
#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

#include <curses.h>
#include <iostream>

class GameBoard 
{
private :
	WINDOW *gameBoard;
	int board[20][22];
	
public :
	
	void setwindow()
	{
		gameBoard = newwin(20, 22, 3, 15); //�� ��ũ��, ��ġ
	}

	void print(); //���Ӻ��������
	void end(); //gameBoard�޸� ����
	void initBoard(); //�������ʱ�ȭ

	bool isGameOver(); //���ӿ���Ȯ��
	int crashBlock(); //��� �����

	//friend class;
	friend class BLOCK;
	friend class OBLOCK;
	friend class LBLOCK;
	friend class JBLOCK;
	friend class SBLOCK;
	friend class ZBLOCK;
	friend class TBLOCK;
	friend class IBLOCK;
	friend class EX_1BLOCK;
	friend class EX_2BLOCK;

};
#endif