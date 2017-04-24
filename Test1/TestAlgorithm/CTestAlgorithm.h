#ifndef CXX_CTESTALGORITHM_H
#define CXX_CTESTALGORITHM_H

#include "CTestIF.h"

class CTestAlgorithm: public CTestIF
{
public:
	CTestAlgorithm();
	virtual ~CTestAlgorithm();
	virtual void Run();
private:
	void test_all_of();
	void test_any_of();
	void test_none_of();
};

#endif