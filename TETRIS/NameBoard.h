/***********************************************************************************************************************************
* <clss NameBoard >                                                                                                                *
*  �̸����� ���                                                                                                                   *
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
		nameBoard = newwin(4, 10, 18, 40); //�� ��ũ��, ��ġ
	}
	void print(); //�̸������
	void end(); //NameBoard �޸�����

};
#endif