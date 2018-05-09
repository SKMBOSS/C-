#ifndef __SBLOCK_H__
#define __SBLOCK_H__

#include "block.h"

class SBLOCK:public BLOCK
{
public:
	virtual void setBoard(GameBoard&);
	virtual void clearBoard(GameBoard& );
	virtual bool isEdge(GameBoard& );
	virtual bool isEdgeCrash(GameBoard& );
	virtual void dropBlock(GameBoard& );
};

#endif