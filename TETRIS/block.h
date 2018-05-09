#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "GameBoard.h"

class BLOCK
{
private:
	int edgecount; //블록밑에 몇번부딪힌지 카운트(충돌 확인 수)

protected :
	int r;//행
	int c;//렬
	int rotateForm; //현재 블록의 상태(얼마나 회전했는가)
public:

	//construct 
	BLOCK():edgecount(0), r(0),c(9),rotateForm(0) //초기 블록의 위치를 설정
	{
	}

	//class func
	void setEdgeCountZero(); //충돌 확인 수를 0으로 초기화
	void plusEdgeCount();//충돌 확인 수 증가
	int  getEdgeCount();//충돌 확인 수를 받아옴

	void down(); //아래로 이동
	void left(); //왼쪽으로 이동
	void right(); //오른쪽으로 이동
	void rotate(GameBoard& gameboard); //회전담당// rotareFormChange

	/*프로젝트외 기능인 홀드기능을 사용할때 쓰이는 함수들입니다.*/
	int getRow(); //행을 받아옴
	int getCol(); //열을 받아옴
	void setRow(const int& r); //행을 설정
	void setCol(const int& c); //열을 설정

	//virtual func
	virtual void setBoard(GameBoard&)=0;       //게임보드판에 블록형태를 전달
	virtual void clearBoard(GameBoard& )=0;    //게임보드판에 블록형태를 해제
	virtual bool isEdge(GameBoard& )=0;        //블록이 더 이상 밑으로 갈수있는지 없는지 검사
	virtual bool isEdgeCrash( GameBoard& )=0;  //블록간 혹은 경계에 부딪히는지 검사
	virtual void dropBlock(GameBoard& )=0;  //블록을 드랍시킴
};

#endif
