#include "CTestAlgorithm.h"
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <utility> 
#include <strings.h>
#include <string>

#define TEST_OUT_START \
std::cout << __FUNCTION__ << " start------\n";

#define TEST_OUT_END \
std::cout << __FUNCTION__ << " end------\n";



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

	test_copy();
	test_copy_n();
	test_copy_if();
	test_copy_backward();
	test_move();
	test_move_backward();
	test_swap();
	test_swap_ranges();
	test_iter_swap();
	test_transform();
	test_replace();
	test_replace_if();
	test_replace_copy();
	test_replace_copy_if();
	test_fill();
	test_fill_n();
	test_generate();
	test_generate_n();
	test_remove();
	test_remove_if();
	test_remove_copy();
	test_remove_copy_if();

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
	int aTest[] = { 1,2,3,4,5,1,2,3,4,5 };
	std::vector<int> vTest(aTest, aTest+10);
	int aFind1[] = {1, 2, 3};
	std::vector<int>::iterator it;
	it = std::find_end(vTest.begin(), vTest.end(), aFind1, aFind1 + 3, [](int i, int j) {return i == j;});
	if (it != vTest.end()) {
		std::cout<< "CTestAlgorithm::test_find_end aFind1 last found at position " << it - vTest.begin() << std::endl;
	}

	int aFind2[] = {4,5,1};
	it = std::find_end(vTest.begin(), vTest.end(), aFind2, aFind2 + 3, [](int i, int j) {return i == j;});
	if (it != vTest.end()) {
		std::cout<< "CTestAlgorithm::test_find_end aFind2 last found at position " << it - vTest.begin() << std::endl;
	}
}

void 
CTestAlgorithm::test_first_of()
{
	char acTest[] = {'a', 'b', 'c', 'A', 'B', 'C'};
	std::vector<char> vcTest(acTest, acTest + 6);

	char acfTest[] = {'A', 'B', 'C'};

	std::vector<char>::iterator it;
	it = find_first_of(vcTest.begin(), vcTest.end(), acfTest, acTest + 3);
	if (it != vcTest.end()) {
		std::cout<< "CTestAlgorithm::test_first_of the first match element is: " << *it << std::endl;
	}

	it == find_first_of(vcTest.begin(), vcTest.end(), acfTest, acTest + 3, [](char c1, char c2){return std::tolower(c1) == std::tolower(c2);});
	if (it != vcTest.end()) {
		std::cout<< "CTestAlgorithm::test_first_of the first match element is: " << *it << std::endl;
	}
}

void 
CTestAlgorithm::test_adjacent_find()
{
	int aiTest[] = {10, 20, 30, 30, 10, 10, 40, 20};
	std::vector<int> viTest(aiTest, aiTest + 8);
	std::vector<int>::iterator it;
	it = adjacent_find(viTest.begin(), viTest.end());
	if (it != viTest.end()) {
		std::cout<< "CTestAlgorithm::test_adjacent_find the first match element is: " << *it << std::endl;
	}

	it = adjacent_find(viTest.begin(), viTest.end(), [](int i1, int i2){return i1/i2 == 2;});
	if (it != viTest.end()) {
		std::cout<< "CTestAlgorithm::test_adjacent_find the first match element is: " << *it << std::endl;
	}
}	

void 
CTestAlgorithm::test_count()
{
	int aiTest[] = {10, 20, 30, 30, 10, 10, 40, 20};
	std::vector<int> viTest(aiTest, aiTest + 8);
	int iCount = std::count(aiTest, aiTest+8, 10);
	std::cout<< "CTestAlgorithm::test_count the 10 element count is: " << iCount << std::endl;
	iCount = std::count(viTest.begin(), viTest.end(), 30);
	std::cout<< "CTestAlgorithm::test_count the 30 element count is: " << iCount << std::endl;
}

void 
CTestAlgorithm::test_count_if()
{
	std::vector<int> vTest;
	for (int i = 0; i < 10; ++i) {
		vTest.push_back(i);
	}	
	int iCount = std::count_if(vTest.begin(), vTest.end(), [](int i){return i%2 == 1;});
	std::cout<< "CTestAlgorithm::test_count_if odd numbers count is: " << iCount << std::endl;
}

void 
CTestAlgorithm::test_mismatch()
{
	std::vector<int> vTest;
	for (int i = 1; i < 6; ++i) {
		vTest.push_back(i*10);
	}
	int aTest[] = { 10, 20, 80, 320, 400 };
	std::pair<std::vector<int>::iterator, int*> retPair;
	retPair = std::mismatch(vTest.begin(), vTest.end(), aTest);
	std::cout<< "CTestAlgorithm::test_mismatch the first mismatch elements: " << *retPair.first;
	std::cout<< "add " << *retPair.second << std::endl;
	++retPair.first;
	++retPair.second;
	retPair = std::mismatch(vTest.begin(), vTest.end(), aTest, [](int i1, int i2){return i1  == i2;});
	std::cout<< "CTestAlgorithm::test_mismatch the second mismatch elements: " << *retPair.first;
	std::cout<< "add " << *retPair.second << std::endl;
}

void 
CTestAlgorithm::test_equal()
{
	int aTest[] = {1, 2, 3, 4, 5, 6};
	std::vector<int> vTest(aTest, aTest + 6);
	if (std::equal(vTest.begin(), vTest.end(), aTest)) {
		std::cout<< "CTestAlgorithm::test_equal The contents of both requences ard equal!" << std::endl;
	}
	else {
		std::cout<< "CTestAlgorithm::test_equal The contents of both requences differ!" << std::endl;
	}

	aTest[3] = 10;
	if (std::equal(vTest.begin(), vTest.end(), aTest, [](int i1, int i2){return i1 == i2;})) {
		std::cout<< "CTestAlgorithm::test_equal The contents of both requences ard equal!" << std::endl;
	}
	else {
		std::cout<< "CTestAlgorithm::test_equal The contents of both requences differ!" << std::endl;
	}
 }

void 
CTestAlgorithm::test_is_permutation()
{
	std::array<int, 5> foo = {1, 2, 3, 4, 5};
	std::array<int, 5> bar = {2, 4, 5, 1, 3};
	if (std::is_permutation(foo.begin(), foo.end(), bar.begin())) {
		std::cout<< "CTestAlgorithm::test_is_permutation The contents of both requences is same!" << std::endl;
	}
	else {
		std::cout<< "CTestAlgorithm::test_is_permutation The contents of both requences is not same!" << std::endl;
	}

	std::array<int, 5> bar1 = {2, 4, 3, 1, 3};
	if (std::is_permutation(foo.begin(), foo.end(), bar1.begin())) {
		std::cout<< "CTestAlgorithm::test_is_permutation The contents of both requences is same!" << std::endl;
	}
	else {
		std::cout<< "CTestAlgorithm::test_is_permutation The contents of both requences is not same!" << std::endl;
	}

	std::array<int, 5> bar2 = {2, 4, 6, 1, 3};
	if (std::is_permutation(foo.begin(), foo.end(), bar2.begin())) {
		std::cout<< "CTestAlgorithm::test_is_permutation The contents of both requences is same!" << std::endl;
	}
	else {
		std::cout<< "CTestAlgorithm::test_is_permutation The contents of both requences is not same!" << std::endl;
	}
}

void 
CTestAlgorithm::test_search()
{
	std::vector<int> vTest;
	for (int i = 1; i < 10; ++i)
	{
		vTest.push_back(i*10);
	}

	int aFind[] = {30, 40, 50};

	std::vector<int>::iterator it;
	it = std::search(vTest.begin(), vTest.end(), aFind, aFind + 3);
	if (it != vTest.end()) {
		std::cout<< "CTestAlgorithm::test_search aFind found at postion:" << it - vTest.begin() << std::endl;
	}
	else {
		std::cout<< "CTestAlgorithm::test_search aFind not found!" << std::endl;
	}

	int aFind1[] = {30, 40, 70};
	it = std::search(vTest.begin(), vTest.end(), aFind1, aFind1 + 3, [](int i1, int i2){return i1 == i2;});
	if (it != vTest.end()) {
		std::cout<< "CTestAlgorithm::test_search aFind found at postion:" << it - vTest.begin() << std::endl;
	}
	else {
		std::cout<< "CTestAlgorithm::test_search aFind not found!" << std::endl;
	}
}

void 
CTestAlgorithm::test_search_n()
{
	int aFind[] = {10, 20, 30, 30, 10 ,10, 50};
	std::vector<int> vTest(aFind, aFind + 7);

	std::vector<int>::iterator it;
	it = std::search_n(vTest.begin(), vTest.end(), 2, 30);
	if (it != vTest.end()) {
		std::cout<< "CTestAlgorithm::test_search_n two 30 found at postion: " << it - vTest.begin() << std::endl;
	}
	else {
		std::cout<< "CTestAlgorithm::test_search_n two 30 not found!" << std::endl;
	}

	int aFind1[] = {30, 40, 70};
	it = std::search_n(vTest.begin(), vTest.end(), 2, 10, [](int i1, int i2){return i1 == i2;});
	if (it != vTest.end()) {
		std::cout<< "CTestAlgorithm::test_search_n two 10 found at postion: " << it - vTest.begin() << std::endl;
	}
	else {
		std::cout<< "CTestAlgorithm::test_search_n two 10 not found!" << std::endl;
	}
}

void 
CTestAlgorithm::test_copy()
{
	int aOrignal[] = { 10, 20, 30, 40, 50, 60, 70};
	std::vector<int> vDes(7);
	std::copy(aOrignal, aOrignal + 7, vDes.begin());
	std::vector<int>::iterator it = vDes.begin();
	std::cout << "CTestAlgorithm::test_copy(): ";
	for (; it != vDes.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;
}

void 
CTestAlgorithm::test_copy_n()
{
	int aOrignal[] = { 10, 20, 30, 40, 50, 60, 70};
	std::vector<int> vDes(7);
	auto it = std::copy_n(aOrignal, 3, vDes.begin());
	vDes.resize(std::distance(vDes.begin(), it));
	std::cout << "CTestAlgorithm::test_copy_n(): ";
	for (int &i: vDes) {
		std::cout << ' ' << i;
	}
	std::cout << std::endl;
}

void 
CTestAlgorithm::test_copy_if()
{
	int aOrignal[] = { 10, 20, -30, 40, -50, 60, -70};
	std::vector<int> vDes(7);
	auto it = std::copy_if(aOrignal, aOrignal + 7, vDes.begin(), [](int i){return i < 0;});
	vDes.resize(std::distance(vDes.begin(), it));
	std::cout << "CTestAlgorithm::test_copy_if(): ";
	for (int &i: vDes) {
		std::cout << ' ' << i;
	}
	std::cout << std::endl;
}

void 
CTestAlgorithm::test_copy_backward()
{
	std::vector<int> vTest;
	for (int i = 1; i <= 5; ++i)
	{
		vTest.push_back(i*10);
	}
	vTest.resize(vTest.size() + 3);
	std::copy_backward(vTest.begin(), vTest.begin() + 5, vTest.end());
	std::vector<int>::iterator it = vTest.begin();
	std::cout << "CTestAlgorithm::test_copy(): ";
	for (; it != vTest.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

}

void 
CTestAlgorithm::test_move()
{
	std::vector<std::string> foo = {"new", "old", "start", "end"};
	std::vector<std::string> bar(4);
	std::cout<< "CTestAlgorithm::test_move move ranges......\n";

	std::move(foo.begin(), foo.end(), bar.begin());
	std::cout << "CTestAlgorithm::test_move bar contains " << bar.size() << " elements:";
	for (std::string &x: bar)
	{
		std::cout << " [ " << x << " ] ";
	}
	std::cout << '\n';

	foo = std::move(bar);
	std::cout << "CTestAlgorithm::test_move foo contains " << foo.size() << " elements:";
	for (std::string &x: foo)
	{
		std::cout << " [ " << x << " ] ";
	}
	std::cout << '\n';
}

void 
CTestAlgorithm::test_move_backward()
{
	std::string aTest[10] = {"new", "old", "start", "end"};
	std::move_backward(aTest, aTest + 4, aTest + 5);
	aTest[0] = "enter";

	std::cout << "CTestAlgorithm::test_move_backward aTest contains: ";
	for (std::string &x: aTest)
	{
		std::cout << " [ " << x << " ] ";
	}
	std::cout << '\n';
}

void 
CTestAlgorithm::test_swap()
{
	int x = 10;
	int y = 20;
	std::swap(x, y);
	std::vector<int> foo(4, x);
	std::vector<int> bar(6, y);
	std::swap(foo, bar);

	std::cout << "CTestAlgorithm::test_swap foo contains:  ";
	for(int &i: foo) 
	{
		std::cout << ' ' << i;
	} 
	std::cout << '\n';
}

void 
CTestAlgorithm::test_swap_ranges()
{
	std::vector<int> foo(5, 10);
	std::vector<int> bar(5, 33);
	std::swap_ranges(foo.begin() + 1, foo.end() -1, bar.begin());
	std::cout << "CTestAlgorithm::test_swap_ranges foo contains: ";
	for (int& i: foo) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';

	std::cout << "CTestAlgorithm::test_swap_ranges bar contains: ";
	for (int& i: bar) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';
}

void 
CTestAlgorithm::test_iter_swap()
{
	std::array<int, 5> foo = {10 ,20, 30, 40, 50};
	std::vector<int> bar(5, 33);
	std::iter_swap(foo.begin(), bar.begin());
	std::iter_swap(foo.begin() + 3, bar.begin() + 2);
	std::cout << "CTestAlgorithm::test_iter_swap foo contains: ";
	for (int& i: foo) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';

	std::cout << "CTestAlgorithm::test_iter_swap bar contains: ";
	for (int& i: bar) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';
}

void 
CTestAlgorithm::test_transform()
{
	TEST_OUT_START

	std::vector<int> foo;
	std::vector<int> bar;
	for (int i = 1; i < 6; ++i)
	{
		foo.push_back(i * 10);
	}
	bar.resize(foo.size()); 
	std::transform(foo.begin(), foo.end(), bar.begin(), [](int i){return ++i;});
	std::cout << " bar contains: ";
	for (int& i: bar) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';

	std::transform(foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());
	std::cout << " foo contains: ";
	for (int& i: foo) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';

	TEST_OUT_END
}

void 
CTestAlgorithm::test_replace()
{
	TEST_OUT_START

	std::array<int, 8> foo = { 10, 20, 30, 40, 10, 20, 30, 40 };
	std::replace(foo.begin(), foo.end(), 20, 90);
	std::cout << " foo contains: ";
	for (int& i: foo) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';

	TEST_OUT_END
}

void 
CTestAlgorithm::test_replace_if()
{
	TEST_OUT_START
	std::array<int, 8> foo = { 1, 2, 3, 4, 5, 6, 7, 8 };
	std::replace_if(foo.begin(), foo.end(), [](int i){return i%2;}, 0);
	std::cout << " foo contains: ";
	for (int& i: foo) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';
	TEST_OUT_END
}

void 
CTestAlgorithm::test_replace_copy()
{
	TEST_OUT_START

	std::array<int, 8> foo = { 10, 20, 30, 40, 10, 20, 30, 40 };
	std::vector<int> bar(8);
	std::replace_copy(foo.begin(), foo.end(), bar.begin(), 20, 90);
	std::cout << " foo contains: ";
	for (int& i: foo) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';

	std::cout << " bar contains: ";
	for (int& i: bar) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';

	TEST_OUT_END
}

void 
CTestAlgorithm::test_replace_copy_if()
{
	TEST_OUT_START

	std::array<int, 8> foo = { 1, 2, 3, 4, 5, 6, 7, 8 };
	std::vector<int> bar(foo.size());
	std::replace_copy_if(foo.begin(), foo.end(), bar.begin(), [](int i){return i%2;}, 0);
	std::cout << " foo contains: ";
	for (int& i: foo) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';

	std::cout << " bar contains: ";
	for (int& i: bar) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';

	TEST_OUT_END
}

void 
CTestAlgorithm::test_fill()
{
	TEST_OUT_START

	std::array<int, 8> foo = {0};
	std::fill(foo.begin(), foo.begin() + 3, 5);
	std::fill(foo.begin() + 4, foo.end() - 2, 8);
	std::cout << " foo contains: ";
	for (int& i: foo) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';

	TEST_OUT_END
}

void 
CTestAlgorithm::test_fill_n()
{
	TEST_OUT_START

	std::array<int, 8> foo = {0};
	std::fill_n(foo.begin(), 4, 5);
	std::fill_n(foo.begin() + 4, 3, 8);
	std::cout << " foo contains: ";
	for (int& i: foo) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';

	TEST_OUT_END
}

struct c_unique
{
	int current;
	c_unique() {current = 0;}
	int operator()() {return ++current;}
};

void 
CTestAlgorithm::test_generate()
{
	TEST_OUT_START
	c_unique iIncrease;
	std::vector<int> foo(6);
	std::generate(foo.begin(), foo.end(), iIncrease);
	std::cout << " foo contains: ";
	for (int& i: foo) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';

	TEST_OUT_END
}

void 
CTestAlgorithm::test_generate_n()
{
	TEST_OUT_START
	c_unique iIncrease;
	std::vector<int> foo(10, 10);
	std::generate_n(foo.begin(), 6, iIncrease);

	std::cout << " foo contains: ";
	for (int& i: foo) {
		std::cout << ' ' << i;
	}
	std::cout << '\n';
	
	TEST_OUT_END
}

void 
CTestAlgorithm::test_remove()
{
	TEST_OUT_START
	c_unique iIncrease;
	std::vector<int> foo(10, 10);
	std::generate_n(foo.begin(), 6, iIncrease);
  	std::vector<int>::iterator itEnd = std::remove(foo.begin(), foo.end(), 10);
	std::cout << " foo contains size: " << foo.size() << '\n';
	std::vector<int>::iterator it = foo.begin();
	for (; it != itEnd; ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << '\n';

	TEST_OUT_END
}

void 
CTestAlgorithm::test_remove_if()
{
	TEST_OUT_START
	c_unique iIncrease;
	std::vector<int> foo(10, 10);
	std::generate_n(foo.begin(), 6, iIncrease);
  	std::vector<int>::iterator itEnd = std::remove_if(foo.begin(), foo.end(), [](int i) {return i%2 == 1;});
	std::cout << " foo contains size: " << foo.size() << '\n';
	std::vector<int>::iterator it = foo.begin();
	for (; it != itEnd; ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << '\n';

	TEST_OUT_END
}

void 
CTestAlgorithm::test_remove_copy()
{
	TEST_OUT_START

	c_unique iIncrease;
	std::vector<int> foo(10, 10);
	std::vector<int> myvector (10);
	std::generate_n(foo.begin(), 6, iIncrease);
  	std::vector<int>::iterator itEnd = std::remove_copy(foo.begin(), foo.end(), myvector.begin(), 10);
	std::cout << " myvector contains size: " << foo.size() << '\n';
	std::vector<int>::iterator it = myvector.begin();
	for (; it != itEnd; ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << '\n';

	TEST_OUT_END
}

void 
CTestAlgorithm::test_remove_copy_if()
{
	TEST_OUT_START

	c_unique iIncrease;
	std::vector<int> foo(10, 10);
	std::vector<int> myvector (10);
	std::generate_n(foo.begin(), 6, iIncrease);
  	std::vector<int>::iterator itEnd = std::remove_copy_if(foo.begin(), foo.end(), myvector.begin(), [](int i) {return i%2 == 1;});
	std::cout << " myvector contains size: " << foo.size() << '\n';
	std::vector<int>::iterator it = myvector.begin();
	for (; it != itEnd; ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << '\n';

	TEST_OUT_END
}