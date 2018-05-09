/***********************************************************************************************************************************
* <clss ScoreBoard >                                                                                                               *
*  점수판을 담당                                                                                                                   *
************************************************************************************************************************************/
#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

#include <curses.h>
#include <iostream>

class ScoreBoard 
{
private:
	WINDOW *scoreBoard;
	int score;
public : 
	ScoreBoard():score(0){}
	void setwindow()
	{
		scoreBoard = newwin(4, 10, 12, 40); //행 열크기, 위치
	}
	void print(); //점수판 출력
	void end(); //scoreBoard 메모리 해제
	void upScore(int s)
	{
		score+=s;
	}
};
#endif