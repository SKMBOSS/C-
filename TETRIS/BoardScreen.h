/***********************************************************************************************************************************
* <clss BoardScreen >                                                                                                              *
*  전체 출력화면을 담당                                                                                                            *
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
	//생성자
	BoardScreen();

	//소멸자
	~BoardScreen()
	{
		void endgame(); // 게임종료시 윈도우 메모리 삭제기능 함수
		endwin();  //PDCurses TUI 모드 사용 종료 
		system("cls");
	}

	//function
	void printfirst(); //게임시작 이전 화면 출력
	void printBoards(); //게임화면 출력
	void endgame(); // 게임종료
	void startgame();

};


#endif