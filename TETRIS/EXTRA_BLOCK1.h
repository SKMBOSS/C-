#ifndef __EX1BLOCK_H__
#define __EX1BLOCK_H__

#include "block.h"

class EX_1BLOCK:public BLOCK
{
public:
	virtual void setBoard(GameBoard&);
	virtual void clearBoard(GameBoard& );
	virtual bool isEdge(GameBoard& );
	virtual bool isEdgeCrash(GameBoard& );
	virtual void dropBlock(GameBoard& );
};

#endif