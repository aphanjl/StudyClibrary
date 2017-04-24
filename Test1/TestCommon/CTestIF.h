#ifndef CXX_CTESTIF_H
#define CXX_CTESTIF_H

#include <memory>

class CTestIF
{
public:
	CTestIF() {}
	virtual ~CTestIF() {}
	virtual void Run() = 0;
};

typedef std::shared_ptr<CTestIF> spCTestIF;

#endif