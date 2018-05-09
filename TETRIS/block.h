#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "GameBoard.h"

class BLOCK
{
private:
	int edgecount; //��Ϲؿ� ����ε����� ī��Ʈ(�浹 Ȯ�� ��)

protected :
	int r;//��
	int c;//��
	int rotateForm; //���� ����� ����(�󸶳� ȸ���ߴ°�)
public:

	//construct 
	BLOCK():edgecount(0), r(0),c(9),rotateForm(0) //�ʱ� ����� ��ġ�� ����
	{
	}

	//class func
	void setEdgeCountZero(); //�浹 Ȯ�� ���� 0���� �ʱ�ȭ
	void plusEdgeCount();//�浹 Ȯ�� �� ����
	int  getEdgeCount();//�浹 Ȯ�� ���� �޾ƿ�

	void down(); //�Ʒ��� �̵�
	void left(); //�������� �̵�
	void right(); //���������� �̵�
	void rotate(GameBoard& gameboard); //ȸ�����// rotareFormChange

	/*������Ʈ�� ����� Ȧ������ ����Ҷ� ���̴� �Լ����Դϴ�.*/
	int getRow(); //���� �޾ƿ�
	int getCol(); //���� �޾ƿ�
	void setRow(const int& r); //���� ����
	void setCol(const int& c); //���� ����

	//virtual func
	virtual void setBoard(GameBoard&)=0;       //���Ӻ����ǿ� ������¸� ����
	virtual void clearBoard(GameBoard& )=0;    //���Ӻ����ǿ� ������¸� ����
	virtual bool isEdge(GameBoard& )=0;        //����� �� �̻� ������ �����ִ��� ������ �˻�
	virtual bool isEdgeCrash( GameBoard& )=0;  //��ϰ� Ȥ�� ��迡 �ε������� �˻�
	virtual void dropBlock(GameBoard& )=0;  //����� �����Ŵ
};

#endif
