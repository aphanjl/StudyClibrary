#ifndef CXX_CTESTLIBRARY_H
#define CXX_CTESTLIBRARY_H

#include "CTestIF.h"

class CTestLibrary: public CTestIF
{
public:
	CTestLibrary();
	virtual ~CTestLibrary();
	virtual void Run();
};

#endif