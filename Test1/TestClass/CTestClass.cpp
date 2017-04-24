#include "CTestClass.h"
#include <iostream>

namespace TESTC {
	B::B()
	{
		std::cout << "B construct ------" << std::endl;
	}

	B::~B()
	{
		std::cout << "B destruct ------" << std::endl;
	}

	void 
	B::f(int)
	{
		std::cout << "B::f ------" << std::endl;
	}


	D::D()
	{
		std::cout << "D construct ++++++" << std::endl;
	}

	D::~D()
	{
		std::cout << "D destruct ++++++" << std::endl;
	}

	void 
	D::f(int)
	{
		std::cout << "D::f ++++++" << std::endl;
	}

	F::F()
	{
		std::cout << "F construct ======" << std::endl;
	}

	F::~F()
	{
		std::cout << "F destruct ======" << std::endl;
	}

	void 
	F::f(int)
	{
		std::cout << "F::f ======" << std::endl;
	}


	CTestClass::CTestClass()
	{

	}

	CTestClass::~CTestClass()
	{

	}

	void CTestClass::doAction()
	{
		// test class
		D* pBase = new F();
		pBase->f(0);
		delete pBase;

		// test enum
		Options op = Options::All;
	}
}
