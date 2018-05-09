#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "BoardScreen.h"
#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;

BLOCK& randomBlcok(const int& tetromino) //��Ʈ�ι̳븦 �������� ������ϴ� �Լ�
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

void BoardScreen::startgame() //���ӽ��� �Լ�
{
	srand(seed); //�õ尪�� input.txt�� ������ txt�� �ִ� ���̰�, ���ٸ� �����̴�.
	int tetromino=rand()%7;; //�������� ��Ʈ�ι̳밡 7���̹Ƿ� 0~6���� ���� �ٸ� ��Ʈ�ι̳븦 �ǹ��Ѵ�.
	char key; //����ڐl Ű�� �Է¹޴� ����
	BLOCK *cur_block=NULL; //�����

	/*������Ʈ �� ����� ����ϴ� �������Դϴ�....*/
	int next_tetromino; // *���� ������ ��Ʈ�ι̳븦* 
	int hold_tetromino=-1; //*Ȧ�� ��Ʈ�ι̳� *
	bool ishold= false; //Ȧ�尡 �Ȼ������� Ȯ���ϴ� ����
	int holdcount=0; //Ȧ�� ������ ��� �Ǿ����� Ȯ���ϴ� ����
	/********************************************************/

	ifstream inStream; 
	inStream.open("input.txt"); //������ �ҷ��ɴϴ�.

	while(true)
	{
		cur_block=&randomBlcok(tetromino);//���� ����� �������� ����

		//������Ʈ �� ����� ��������� �������ִ� ����Դϴ�./
		next_tetromino=rand()%7;
		nextblockboard.setBoard(next_tetromino); //������� ����
		///////////////////////////////////////////////////////

		while(true)
		{
			cur_block->clearBoard(gameboard);

			if(kbhit() == 0 && argc==false) //�ڵ����� ��������(������Ʈ �� ����Դϴ�.)
			{

				if(!cur_block->isEdge(gameboard)) 
				{
					cur_block->down();
					cur_block->setBoard(gameboard);
					cur_block->setEdgeCountZero();
				}

				else //���κ��϶� ����
					cur_block->setBoard(gameboard);
				printBoards();


				if(cur_block->isEdge(gameboard))
				{
					cur_block->plusEdgeCount();

					if(cur_block->getEdgeCount()==2) //��ϰ�����Ű��
					{
						scoreboard.upScore(gameboard.crashBlock());
						break;
					}
				}
				cur_block->clearBoard(gameboard);

			}

			for(int i=0; i<100; i++) //�ڵ����� ������ �� �ӵ��� ����ϴ� �ݺ����Դϴ�. 
			{
				Sleep(5);//�ڵ����� ������ �� �ӵ��� ����ϴ� Sleep�Լ��Դϴ�.

				if(kbhit() != 0) //Ű�Է���������
				{
					if(argc==true) inStream >> key; //������ �����ϸ� key�� ���Ͽ��� �ް�

					else key=getch(); // �ƴϸ� ����ڿ����� �ް��մϴ�.

					if(key=='\x2'|| key=='g')//�Ʒ�
					{
						if(!cur_block->isEdge(gameboard)) //���� ����� ���� ������ �� �ִ� ���¸�
						{
							cur_block->down(); //�Ʒ��� ��ĭ������
							cur_block->setBoard(gameboard); //ȭ�鿡 ǥ���մϴ�.
							cur_block->setEdgeCountZero(); //�� �浹 Ȯ�� ���� 0���� �ʱ�ȭ�մϴ�.
						}

						else //���κ��϶� ����
							cur_block->setBoard(gameboard); //�������� ���� ���� �Ҽ� ���ٸ� ȭ�鿡 ������ŵ�ϴ�.


						printBoards(); //��üȭ�� ���


						if(cur_block->isEdge(gameboard)) //�������� ���� ���� ��ų �� ���� �����̸�
						{
							cur_block->plusEdgeCount(); // �� �浹 Ȯ�μ��� 1���� ��ŵ�ϴ�.

							if(cur_block->getEdgeCount()==2) //�� �浹 Ȯ�μ��� 2��� �ٷ� ���� ��ŵ�ϴ�.
							{
								scoreboard.upScore(gameboard.crashBlock()); //�������� �˻��ѵ� ����� �������� ������ �ø��ϴ�.
								goto skip00; //�ݺ��� ����������
							}
						}
						cur_block->clearBoard(gameboard);
					}


					else if(key=='\x5' || key=='r') //������
					{
						cur_block->right(); //���������� ����� �̵���Ų��

						if(cur_block->isEdgeCrash(gameboard)) //���̳� �ٸ� ��Ͽ� �ε����ٸ�
							cur_block->left(); //�ٽ� �����·� ���ư����Ͽ� ������ �����ϴ�.

						cur_block->setBoard(gameboard); //���� �����ġ�� ����
						printBoards(); //ȭ�����

						cur_block->clearBoard(gameboard); //���� �����ġ�� Ŭ�������ݴϴ�.

					}
					else if(key=='\x4'||key=='l') //���� (�����ʰ� �����ϴ�)
					{
						cur_block->left();

						if(cur_block->isEdgeCrash(gameboard))
							cur_block->right();

						cur_block->setBoard(gameboard);
						printBoards();

						cur_block->clearBoard(gameboard);
					}

					else if(key==' '||key=='d') //�����̽��� == �����Ű��
					{

						cur_block->dropBlock(gameboard); //�����Ű��
						printBoards(); //ȭ�����

						if(cur_block->isEdge(gameboard))
						{
							scoreboard.upScore(gameboard.crashBlock()); //������ ��� ���ֱ�
							/*break;*/
							goto skip00; //�ݺ��� ����
						}

					}

					else if(key=='\x3' || key=='t') //���� == ȸ��
					{
						cur_block->rotate(gameboard); // rotateForm�� 1������ŵ�ϴ�.
						cur_block->setBoard(gameboard); //���� ���¸� ����
						printBoards(); //���
						cur_block->clearBoard(gameboard); //Ŭ����
					}

					//////������Ʈ�� ����Դϴ� /////////////
					else if(key=='\t') //tap Ȧ��
					{
						if(ishold==false) // �ƹ��͵���������
						{
							ishold=true;
							hold_tetromino=tetromino;
							holdblockboard.setBoard(tetromino); //����

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
									holdblockboard.setBoard(hold_tetromino); //����

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
						mvprintw(15,20,"������ �����ϴ�......");
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
		delete cur_block; //���� ����� �޸� �Ҵ��� ����

		tetromino=next_tetromino; // ������Ʈ�ι̳븦 ������Ʈ�ι̳�� �ٲ�

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
	initscr();  //PDCurses TUI ��� ��� ���� 
	start_color();  //��������
	init_pair(1, COLOR_GREEN, COLOR_BLACK); 
	init_pair(2, COLOR_RED, COLOR_YELLOW);

	init_pair(3, COLOR_YELLOW, COLOR_BLACK);//��
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
	resize_term(25, 50); //�͹̳�, ������ũ�� ��������
	char name[9]="user";
	printw(" 20123404 ������ ��Ʈ���� �⸻������Ʈ \n\n\n");


	ifstream inStream; 
	char check;

	inStream.open("input.txt"); //������ �ҷ��ɴϴ�.
	if(inStream.fail())
	{
		argc=false;
	}
	else
	{
		int back=0;
		noecho(); //���� �Է� �� �Է��� ���� ȭ�鿡 ������ �ʰ� �� 
		printw("���̺������� �����մϴ� �ҷ��ɴϱ�? Y/N   :");

		while(back==0)
		{
			check=getch();
			if(check=='N' || check=='n')
			{

				printw("\n\nInput your name : ");
				echo(); //���� �Է� �� �Է��� ���� ȭ�鿡 ���̰� �� 
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
	keypad(stdscr, TRUE); //�Է� �� Ű���� Ư�� Ű �Է��� �� ���ϰ� �����ϴ� �Լ� 
	curs_set(0);   //ȭ�鿡 ���̴� Ŀ�� ���� 
	noecho(); //���� �Է� �� �Է��� ���� ȭ�鿡 ������ �ʰ� �� 

	clear(); //ȭ�� �ʱ�ȭ

	resize_term(25, 53); //�͹̳�, ������ũ�� ��������
	border('|','|','-','-','+','+','+','+'); 
	attron( COLOR_PAIR(2));
	mvprintw(1,17,"LEE's TETRIS GAME!!");
	attroff( COLOR_PAIR(2));
	mvprintw(4,39,"<NEXT BLOCK>");
	mvprintw(4,4,"<HOLD>");

	mvprintw(14,1," ��  rotate");
	mvprintw(15,1,"����left/right");
	mvprintw(16,1," ��   down");
	mvprintw(17,1," TAB   hold");
	mvprintw(18,1," p/P   pause");
	mvprintw(19,1," q/Q   quit");

	if(argc==true)
		mvprintw(2,5,"���̺������� �����մϴ� �ƹ�Ű�� �����ּ���");



	attroff( COLOR_PAIR(3));
	refresh(); //������Ʈ(���� ���)

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



