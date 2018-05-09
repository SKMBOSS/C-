/***********************************************************************************************************************************
* <clss NameBoard >                                                                                                                *
*  이름판을 담당                                                                                                                   *
************************************************************************************************************************************/
#ifndef __NAMEBOARD_H__
#define __NAMEBOARD_H__

#include <curses.h>
#include <iostream>
#include <cstring>

class NameBoard 
{
private:
	WINDOW *nameBoard;
	char username[9];
public :


	void setName(char name[]=0)//Set username
	{
		if(name !=0)
		strcpy(username,name);
	}

	void setwindow()
	{
		nameBoard = newwin(4, 10, 18, 40); //행 열크기, 위치
	}
	void print(); //이름판출력
	void end(); //NameBoard 메모리해제

};
#endif