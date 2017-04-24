
#include <iostream>
#include "CTestApplication.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "main start ------" << endl;
	CTestApplication cCTestApplication;
	cCTestApplication.Run();
	cout << "main end ------" << endl;
	return 0;
}