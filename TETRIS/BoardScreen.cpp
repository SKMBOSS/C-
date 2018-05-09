#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "BoardScreen.h"
#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;

BLOCK& randomBlcok(const int& tetromino) //테트로미노를 무작위로 만들게하는 함수
{
	BLOCK* cur_block=NULL;

	switch(tetromino)
	{
	case 0 :
		cur_block= new OBLOCK();
		break;
	case 1:
		cur_block= new LBLOCK();
		break;
	case 2:
		cur_block= new JBLOCK();
		break;
	case 3:
		cur_block= new SBLOCK();
		break;
	case 4:
		cur_block= new ZBLOCK();
		break;
	case 5:
		cur_block= new TBLOCK();
		break;
	case 6:
		cur_block= new IBLOCK();
		break;
	case 7:
		cur_block= new EX_1BLOCK();
		break;
	case 8:
		cur_block= new EX_2BLOCK();
		break;
	}
	return *cur_block;
}

void BoardScreen::startgame() //게임시작 함수
{
	srand(seed); //시드값은 input.txt가 있으면 txt에 있는 값이고, 없다면 랜덤이다.
	int tetromino=rand()%7;; //떨어지는 테트로미노가 7개이므로 0~6까지 각각 다른 테트로미노를 의미한다.
	char key; //사용자릐 키를 입력받는 변수
	BLOCK *cur_block=NULL; //현재블럭

	/*프로젝트 외 기능을 담당하는 변수들입니다....*/
	int next_tetromino; // *다음 떨어질 테트로미노를* 
	int hold_tetromino=-1; //*홀드 테트로미노 *
	bool ishold= false; //홀드가 된상태인지 확인하는 변수
	int holdcount=0; //홀드 진행이 몇번 되었는지 확인하는 변수
	/********************************************************/

	ifstream inStream; 
	inStream.open("input.txt"); //파일을 불러옵니다.

	while(true)
	{
		cur_block=&randomBlcok(tetromino);//현재 블록을 랜덤으로 설정

		//프로젝트 외 기능인 다음블록을 설정해주는 기능입니다./
		next_tetromino=rand()%7;
		nextblockboard.setBoard(next_tetromino); //다음블록 설정
		///////////////////////////////////////////////////////

		while(true)
		{
			cur_block->clearBoard(gameboard);

			if(kbhit() == 0 && argc==false) //자동으로 떨어지기(프로젝트 외 기능입니다.)
			{

				if(!cur_block->isEdge(gameboard)) 
				{
					cur_block->down();
					cur_block->setBoard(gameboard);
					cur_block->setEdgeCountZero();
				}

				else //끝부분일때 상태
					cur_block->setBoard(gameboard);
				printBoards();


				if(cur_block->isEdge(gameboard))
				{
					cur_block->plusEdgeCount();

					if(cur_block->getEdgeCount()==2) //블록고정시키기
					{
						scoreboard.upScore(gameboard.crashBlock());
						break;
					}
				}
				cur_block->clearBoard(gameboard);

			}

			for(int i=0; i<100; i++) //자동으로 떨어질 시 속도를 담당하는 반복문입니다. 
			{
				Sleep(5);//자동으로 떨어질 시 속도를 담당하는 Sleep함수입니다.

				if(kbhit() != 0) //키입력이있을때
				{
					if(argc==true) inStream >> key; //파일이 존재하면 key를 파일에서 받고

					else key=getch(); // 아니면 사용자에의해 받게합니다.

					if(key=='\x2'|| key=='g')//아래
					{
						if(!cur_block->isEdge(gameboard)) //현재 블록의 밑이 진행할 수 있는 상태면
						{
							cur_block->down(); //아래로 한칸내리고
							cur_block->setBoard(gameboard); //화면에 표시합니다.
							cur_block->setEdgeCountZero(); //밑 충돌 확인 수를 0으로 초기화합니다.
						}

						else //끝부분일때 상태
							cur_block->setBoard(gameboard); //현재블록의 밑이 진행 할수 없다면 화면에 고정시킵니다.


						printBoards(); //전체화면 출력


						if(cur_block->isEdge(gameboard)) //현재블록의 밑을 진행 시킬 수 없는 상태이면
						{
							cur_block->plusEdgeCount(); // 밑 충돌 확인수를 1증가 시킵니다.

							if(cur_block->getEdgeCount()==2) //밑 충돌 확인수가 2라면 바로 고정 시킵니다.
							{
								scoreboard.upScore(gameboard.crashBlock()); //모든라인을 검사한뒤 블록이 없어지면 점수를 올립니다.
								goto skip00; //반복문 빠져나오기
							}
						}
						cur_block->clearBoard(gameboard);
					}


					else if(key=='\x5' || key=='r') //오른쪽
					{
						cur_block->right(); //오른쪽으로 블록을 이동시킨뒤

						if(cur_block->isEdgeCrash(gameboard)) //벽이나 다른 블록에 부딪힌다면
							cur_block->left(); //다시 원상태로 돌아가게하여 접근을 막습니다.

						cur_block->setBoard(gameboard); //현재 블록위치를 저장
						printBoards(); //화면출력

						cur_block->clearBoard(gameboard); //현재 블록위치를 클리어해줍니다.

					}
					else if(key=='\x4'||key=='l') //왼쪽 (오른쪽과 같습니다)
					{
						cur_block->left();

						if(cur_block->isEdgeCrash(gameboard))
							cur_block->right();

						cur_block->setBoard(gameboard);
						printBoards();

						cur_block->clearBoard(gameboard);
					}

					else if(key==' '||key=='d') //스페이스바 == 드랍시키기
					{

						cur_block->dropBlock(gameboard); //드랍시키기
						printBoards(); //화면출력

						if(cur_block->isEdge(gameboard))
						{
							scoreboard.upScore(gameboard.crashBlock()); //점수및 블록 없애기
							/*break;*/
							goto skip00; //반복문 종료
						}

					}

					else if(key=='\x3' || key=='t') //위쪽 == 회전
					{
						cur_block->rotate(gameboard); // rotateForm을 1증가시킵니다.
						cur_block->setBoard(gameboard); //현재 상태를 저장
						printBoards(); //출력
						cur_block->clearBoard(gameboard); //클리어
					}

					//////프로젝트외 기능입니다 /////////////
					else if(key=='\t') //tap 홀드
					{
						if(ishold==false) // 아무것도없었을때
						{
							ishold=true;
							hold_tetromino=tetromino;
							holdblockboard.setBoard(tetromino); //저장

							goto skip00;
						}
						else if (ishold==true)
						{
							if(holdcount==0)
							{
								int temp;
								temp=tetromino;
								tetromino=hold_tetromino;
								hold_tetromino=temp;

								int tempC=cur_block->getCol();
								int tempR=cur_block->getRow();

								BLOCK*tempBlock=cur_block;
								tempBlock=&randomBlcok(tetromino);
								tempBlock->setCol(tempC);
								tempBlock->setRow(tempR);

								if(!tempBlock->isEdgeCrash(gameboard))
								{
									holdblockboard.setBoard(hold_tetromino); //저장

									delete cur_block;
									cur_block=tempBlock;

									cur_block->setBoard(gameboard);
									printBoards();
									cur_block->clearBoard(gameboard);

									holdcount++;
								}
								else
								{
									temp=tetromino;
									tetromino=hold_tetromino;
									hold_tetromino=temp;
								}
							}
						}
					}

					else if(key=='q') 
					{
						mvprintw(15,20,"게임을 끝냅니다......");
						getch();
						delete cur_block;
						endgame();
						exit(1);
					}
					else if(key=='p')
					{
						getch();
					}
				}
			}


		}
skip00:
		delete cur_block; //현재 블록의 메모리 할당을 해제

		tetromino=next_tetromino; // 다음테트로미노를 현재테트로미노로 바꿈

		if(gameboard.isGameOver())
		{
			endgame();
			exit(1);
		}

		holdcount=0;
	}
}


/*BoardScreen Function*/
BoardScreen::BoardScreen()
{
	initscr();  //PDCurses TUI 모드 사용 시작 
	start_color();  //색사용시작
	init_pair(1, COLOR_GREEN, COLOR_BLACK); 
	init_pair(2, COLOR_RED, COLOR_YELLOW);

	init_pair(3, COLOR_YELLOW, COLOR_BLACK);//ㅁ
	init_pair(4, COLOR_BLUE, COLOR_BLACK); //L
	init_pair(5, COLOR_GREEN, COLOR_BLACK); //J
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK); //S
	init_pair(7, COLOR_RED, COLOR_BLACK);//Z
	init_pair(8, COLOR_CYAN, COLOR_BLACK); //T
	init_pair(9, COLOR_WHITE, COLOR_BLACK);//I

	gameboard.initBoard();
	nextblockboard.initBoard();
	holdblockboard.initBoard();

	gameboard.setwindow();
	scoreboard.setwindow();
	nameboard.setwindow();
	nextblockboard.setwindow();
	holdblockboard.setwindow();

	printfirst();
}

void BoardScreen::printfirst()
{
	resize_term(25, 50); //터미널, 윈도우크기 동시조정
	char name[9]="user";
	printw(" 20123404 이정수 테트리스 기말프로젝트 \n\n\n");


	ifstream inStream; 
	char check;

	inStream.open("input.txt"); //파일을 불러옵니다.
	if(inStream.fail())
	{
		argc=false;
	}
	else
	{
		int back=0;
		noecho(); //문자 입력 시 입력한 값을 화면에 보이지 않게 함 
		printw("세이브파일이 존재합니다 불러옵니까? Y/N   :");

		while(back==0)
		{
			check=getch();
			if(check=='N' || check=='n')
			{

				printw("\n\nInput your name : ");
				echo(); //문자 입력 시 입력한 값을 화면에 보이게 함 
				scanw("%s", name);
				nameboard.setName(name);

				seed=(unsigned)time(NULL);
				argc=false;
				back=1;
			}
			else if(check=='Y' || check=='y')
			{
				inStream >>name;
				nameboard.setName(name);
				inStream >>seed;
				argc=true;
				back=1;

			}

			else
				back=0;
		}
	}
	keypad(stdscr, TRUE); //입력 시 키보드 특수 키 입력을 가 능하게 설정하는 함수 
	curs_set(0);   //화면에 보이는 커서 설정 
	noecho(); //문자 입력 시 입력한 값을 화면에 보이지 않게 함 

	clear(); //화면 초기화

	resize_term(25, 53); //터미널, 윈도우크기 동시조정
	border('|','|','-','-','+','+','+','+'); 
	attron( COLOR_PAIR(2));
	mvprintw(1,17,"LEE's TETRIS GAME!!");
	attroff( COLOR_PAIR(2));
	mvprintw(4,39,"<NEXT BLOCK>");
	mvprintw(4,4,"<HOLD>");

	mvprintw(14,1," ▲  rotate");
	mvprintw(15,1,"◀▶left/right");
	mvprintw(16,1," ▼   down");
	mvprintw(17,1," TAB   hold");
	mvprintw(18,1," p/P   pause");
	mvprintw(19,1," q/Q   quit");

	if(argc==true)
		mvprintw(2,5,"세이브파일을 실행합니다 아무키나 눌러주세요");



	attroff( COLOR_PAIR(3));
	refresh(); //업데이트(실제 출력)

}

void BoardScreen::printBoards()
{
	gameboard.print();
	scoreboard.print();
	nameboard.print();
	nextblockboard.print();
	holdblockboard.print();
}

void BoardScreen::endgame()
{
	gameboard.end();
	scoreboard.end();
	nameboard.end();
	nextblockboard.end();
	holdblockboard.end();
}



