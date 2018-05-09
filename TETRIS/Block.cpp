#include "Block.h"

//BLOCK

int BLOCK::getRow()
{
	return r;
}
int BLOCK::getCol()
{
	return c;
}

void BLOCK::setRow(const int& r)
{
	this->r=r;
}
void BLOCK::setCol(const int& c)
{
	this->c=c;
}

void BLOCK::setEdgeCountZero()
{
	edgecount=0;
}

void BLOCK::plusEdgeCount()
{
	edgecount++;
}

int  BLOCK::getEdgeCount()
{
	return edgecount;
}

void BLOCK::rotate(GameBoard& gameboard)
{
	rotateForm++;

	if(isEdgeCrash(gameboard))
		rotateForm--;
}

void BLOCK::down()
{
	r++;
}

void BLOCK::left()
{
	c-=2;
}

void BLOCK::right()
{
	c+=2;
}
