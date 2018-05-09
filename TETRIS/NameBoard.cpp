/*NameBoard Function*/
#include "NameBoard.h"

void NameBoard::print()
{
	wattron(nameBoard, COLOR_PAIR(3)); 
	mvwprintw(nameBoard, 1, 1, "name: \n %s",username);  //지정위치 문자열 출력
	wattroff(nameBoard, COLOR_PAIR(3));
	wborder(nameBoard, '|','|','-','-','+','+','+','+'); 
	wrefresh(nameBoard);  
}
void NameBoard::end()
{
	delwin(nameBoard); 
}
