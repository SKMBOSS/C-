/*ScoreBoard Function*/

#include "ScoreBoard.h"
void ScoreBoard::print()
{
	//scoreBoard = newwin(4, 10, 4, 30); //�� ��ũ��, ��ġ
	wattron(scoreBoard, COLOR_PAIR(3)); 
	mvwprintw(scoreBoard, 1, 1, "Score: \n %d",score);  //������ġ ���ڿ� ���
	wattroff(scoreBoard, COLOR_PAIR(3));
	wborder(scoreBoard, '|','|','-','-','+','+','+','+'); 
	wrefresh(scoreBoard);  
}
void ScoreBoard::end()
{
	delwin(scoreBoard);
}