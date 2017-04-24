#ifndef CXX_CTESTAPPLICATION_H
#include "CTestApplication.h"
#endif

#include <iostream>
#include "CTestLibrary.h"
#include "CTestAlgorithm.h"

CTestApplication::CTestApplication()
{
	mvTestArray.push_back(spCTestIF(new CTestLibrary()));
	mvTestArray.push_back(spCTestIF(new CTestAlgorithm()));
}

CTestApplication::~CTestApplication()
{
	mvTestArray.clear();
}

void 
CTestApplication::Run()
{
	for (const auto& it: mvTestArray) {
		it->Run();
	}
	std::cout << "CTestApplication::Run()" << std::endl;
}