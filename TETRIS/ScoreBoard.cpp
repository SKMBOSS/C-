/*ScoreBoard Function*/

#include "ScoreBoard.h"
void ScoreBoard::print()
{
	//scoreBoard = newwin(4, 10, 4, 30); //행 열크기, 위치
	wattron(scoreBoard, COLOR_PAIR(3)); 
	mvwprintw(scoreBoard, 1, 1, "Score: \n %d",score);  //지정위치 문자열 출력
	wattroff(scoreBoard, COLOR_PAIR(3));
	wborder(scoreBoard, '|','|','-','-','+','+','+','+'); 
	wrefresh(scoreBoard);  
}
void ScoreBoard::end()
{
	delwin(scoreBoard);
}