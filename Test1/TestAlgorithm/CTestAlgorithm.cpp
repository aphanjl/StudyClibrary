#include "CTestAlgorithm.h"
#include <iostream>
#include <algorithm>
#include <array>

CTestAlgorithm::CTestAlgorithm()
{

}

CTestAlgorithm::~CTestAlgorithm()
{

}

void 
CTestAlgorithm::Run()
{
	std::cout << "CTestAlgorithm::Run() start!" << std::endl;

	test_all_of();
	test_any_of();
	test_none_of();

	std::cout << "CTestAlgorithm::Run() end!" << std::endl;
}

void 
CTestAlgorithm::test_all_of()
{
	std::array<int, 8> iarray = {3,5,7,9,11,13,15,17};
	if ( std::all_of(iarray.begin(), iarray.end(), [](int i){return i%2;}) ) {
		std::cout<<"CTestAlgorithm::test_all_of: all the elements are odd nubmer"<<std::endl;
	}
	else {

		std::cout<<"CTestAlgorithm::test_all_of: some elements are not odd nubmer in the range"<<std::endl;
	}
}

void 
CTestAlgorithm::test_any_of()
{
	std::array<int, 8> iarray = {2,4,8,10,11,14,15,16};
	if ( std::any_of(iarray.begin(), iarray.end(), [](int i){return i%2;}) ) {
		std::cout<<"CTestAlgorithm::test_any_of: there are odd nubmers in the range"<<std::endl;
	}
	else {
		std::cout<<"CTestAlgorithm::test_any_of: there are not odd nubmers in the range"<<std::endl;
	}
}

void 
CTestAlgorithm::test_none_of()
{
	std::array<int, 8> iarray = {2,4,8,10,11,14,15,16};
	if ( std::none_of(iarray.begin(), iarray.end(), [](int i){return i < 0;}) ) {
		std::cout<<"CTestAlgorithm::test_none_of: there are no negative element in the range"<<std::endl;
	}
	else {
		std::cout<<"CTestAlgorithm::test_none_of: there are negative element in the range"<<std::endl;
	}
}