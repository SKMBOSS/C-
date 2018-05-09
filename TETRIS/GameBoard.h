/***********************************************************************************************************************************
* <clss GameBoard>                                                                                                                 *
*  테트리스 게임판을 담당                                                                                                          *
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
		gameBoard = newwin(20, 22, 3, 15); //행 열크기, 위치
	}

	void print(); //게임보드판출력
	void end(); //gameBoard메모리 해제
	void initBoard(); //보드판초기화

	bool isGameOver(); //게임오버확인
	int crashBlock(); //블록 지우기

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