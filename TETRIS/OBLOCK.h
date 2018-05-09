#ifndef __OBLOCK_H__
#define __OBLOCK_H__

#include "block.h"

class OBLOCK:public BLOCK
{
public:
	virtual void setBoard(GameBoard&);
	virtual void clearBoard(GameBoard& );
	virtual bool isEdge(GameBoard& );
	virtual bool isEdgeCrash(GameBoard& );
	virtual void dropBlock(GameBoard& );
};

#endif