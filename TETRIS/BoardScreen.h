/***********************************************************************************************************************************
* <clss BoardScreen >                                                                                                              *
*  ��ü ���ȭ���� ���                                                                                                            *
************************************************************************************************************************************/
#ifndef __TETRIS_H__
#define __TETRIS_H__

#include "GameBoard.h"
#include "NameBoard.h"
#include "ScoreBoard.h"
#include "NextBlock.h"
#include "HoldBlock.h"
#include "Block.h"
#include "IBLOCK.h"
#include "JBLOCK.h"
#include "LBLOCK.h"
#include "TBLOCK.h"
#include "ZBLOCK.h"
#include "SBLOCK.h"
#include "OBLOCK.h"
#include "EXTRA_BLOCK1.h"
#include "EXTRA_BLOCK2.h"

class BoardScreen
{
private:
	GameBoard gameboard;
	NameBoard nameboard;
	ScoreBoard scoreboard;
	NextBlock nextblockboard;
	HoldBlock holdblockboard;

	bool argc;
	int seed;

public :
	//������
	BoardScreen();

	//�Ҹ���
	~BoardScreen()
	{
		void endgame(); // ��������� ������ �޸� ������� �Լ�
		endwin();  //PDCurses TUI ��� ��� ���� 
		system("cls");
	}

	//function
	void printfirst(); //���ӽ��� ���� ȭ�� ���
	void printBoards(); //����ȭ�� ���
	void endgame(); // ��������
	void startgame();

};


#endif