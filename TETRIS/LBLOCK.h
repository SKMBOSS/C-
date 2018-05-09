#ifndef __LBLOCK_H__
#define __LBLOCK_H__

#include "block.h"

class LBLOCK:public BLOCK
{
public:
	virtual void setBoard(GameBoard&);
	virtual void clearBoard(GameBoard& );
	virtual bool isEdge(GameBoard& );
	virtual bool isEdgeCrash(GameBoard& );
	virtual void dropBlock(GameBoard& );
};

#endif