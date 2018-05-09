/***********************************************************************************************************************************
* <clss ScoreBoard >                                                                                                               *
*  �������� ���                                                                                                                   *
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
		scoreBoard = newwin(4, 10, 12, 40); //�� ��ũ��, ��ġ
	}
	void print(); //������ ���
	void end(); //scoreBoard �޸� ����
	void upScore(int s)
	{
		score+=s;
	}
};
#endif