#include "CLoop.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "CMakeLoop.h"

using namespace std;

void TestLoop() 
{
	cout << "TestLoop start" << endl;

	map<string, vector<int>> mmap;
	vector<int> vv;
	vv.push_back(1);
	vv.push_back(2);
	vv.push_back(3);

	mmap["one"] = vv;

	for(const auto& rvp : mmap) {
		cout << rvp.first << endl;
		for (auto v: rvp.second) {
			cout << v << endl;
		}
	}

	int arr[] = {1, 2, 3, 4, 5};
	for (int & e: arr) {
		e = e*e;
		cout << e << endl;
	}

	CMakeLoop cCMakeLoop;

	cout << "TestLoop end" << endl;
}