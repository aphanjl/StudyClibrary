#include "CTestAlgorithm.h"
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

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

	// test non-modifying sequence operations
	test_all_of();
	test_any_of();
	test_none_of();
	test_for_each();
	test_find();
	test_find_if();
	test_find_if_not();
	test_find_end();
	test_first_of();
	test_adjacent_find();
	test_count();
	test_count_if();
	test_mismatch();
	test_equal();
	test_is_permutation();
	test_search();
	test_search_n();


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

void opFunc(int i)
{
	std::cout<<' '<<i;
}

struct myClass
{
	void operator() (int i) {std::cout<<' '<<i;}
} opojbect;

void 
CTestAlgorithm::test_for_each()
{
	std::vector<int> vTest;
	vTest.push_back(10);
	vTest.push_back(20);
	vTest.push_back(30);

	std::cout<< "CTestAlgorithm::test_for_each use function vTest containts: ";
	for_each(vTest.begin(), vTest.end(), opFunc);
	std::cout<< "\n";

	std::cout<< "CTestAlgorithm::test_for_each use function object vTest containts: ";
	for_each(vTest.begin(), vTest.end(), opojbect);
	std::cout<< "\n";
}

void 
CTestAlgorithm::test_find()
{
	int aTest[] = { 10, 20, 30, 40 };
	int *p;
	p = std::find(aTest, aTest+4, 30);
	if (p != aTest+4) {
		std::cout<< "CTestAlgorithm::test_find element fond in aTest:" << *p << '\n';
	}
	else {
		std::cout<< "CTestAlgorithm::test_find element not fond in aTest\n";
	}

	std::vector<int> vTest(aTest, aTest+4);
	std::vector<int>::iterator it;
	it = std::find(vTest.begin(), vTest.end(), 30);
	if (it != vTest.end()) {
		std::cout<< "CTestAlgorithm::test_find element fond in vTest:" << *it << '\n';
	}
	else {
		std::cout<< "CTestAlgorithm::test_find element not fond in vTest\n";
	}
}

bool isOdd(int i)
{
	return ((i%2) == 1);
}

void 
CTestAlgorithm::test_find_if()
{
	std::vector<int> vTest;
	vTest.push_back(10);
	vTest.push_back(20);
	vTest.push_back(21);
	vTest.push_back(30);
	vTest.push_back(35);

	std::vector<int>::iterator it;
	it = std::find_if(vTest.begin(), vTest.end(), isOdd);
	if (it != vTest.end()) {
		std::cout<< "CTestAlgorithm::test_find_if element fond in vTest:" << *it << '\n';
	}
	else {
		std::cout<< "CTestAlgorithm::test_find_if element not fond in vTest\n";
	}
}

void 
CTestAlgorithm::test_find_if_not()
{
	std::vector<int> vTest;
	vTest.push_back(10);
	vTest.push_back(20);
	vTest.push_back(21);
	vTest.push_back(30);
	vTest.push_back(35);

	std::vector<int>::iterator it;
	it = std::find_if_not(vTest.begin(), vTest.end(), [](int i){return i%2;});
	if (it != vTest.end()) {
		std::cout<< "CTestAlgorithm::find_if_not element fond in vTest:" << *it << '\n';
	}
	else {
		std::cout<< "CTestAlgorithm::find_if_not element not fond in vTest\n";
	}
}

void 
CTestAlgorithm::test_find_end()
{

}

void 
CTestAlgorithm::test_first_of()
{

}

void 
CTestAlgorithm::test_adjacent_find()
{

}

void 
CTestAlgorithm::test_count()
{

}

void 
CTestAlgorithm::test_count_if()
{

}

void 
CTestAlgorithm::test_mismatch()
{

}

void 
CTestAlgorithm::test_equal()
{

}

void 
CTestAlgorithm::test_is_permutation()
{

}

void 
CTestAlgorithm::test_search()
{

}

void 
CTestAlgorithm::test_search_n()
{

}