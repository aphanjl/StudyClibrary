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
	void test_for_each();
	void test_find();
	void test_find_if();
	void test_find_if_not();
	void test_find_end();
	void test_first_of();
	void test_adjacent_find();
	void test_count();
	void test_count_if();
	void test_mismatch();
	void test_equal();
	void test_is_permutation();
	void test_search();
	void test_search_n();


	void test_copy();
	void test_copy_n();
	void test_copy_if();
	void test_copy_backward();
	void test_move();
	void test_move_backward();
	void test_swap();
	void test_swap_ranges();
	void test_iter_swap();
	void test_transform();
	void test_replace();
	void test_replace_if();
	void test_replace_copy();
	void test_replace_copy_if();
	void test_fill();
	void test_fill_n();
	void test_generate();
	void test_generate_n();
	void test_remove();
	void test_remove_if();
	void test_remove_copy();
	void test_remove_copy_if();

};

#endif