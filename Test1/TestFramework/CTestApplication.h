#ifndef CXX_CTESTAPPLICATION_H
#define CXX_CTESTAPPLICATION_H

#include <vector>
#include "CTestIF.h"

class CTestApplication
{
public:
	CTestApplication();
	~CTestApplication();
	void Run();
private:

	std::vector<spCTestIF > mvTestArray;
};

#endif