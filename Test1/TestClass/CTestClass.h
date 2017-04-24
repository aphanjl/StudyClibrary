#ifndef CXX_CTESTCLASS_H
#define CXX_CTESTCLASS_H

#ifndef __cplusplus
#    error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif

namespace TESTC {

	enum class Options
	{
		None, 
		One,
		All
	};

	class B
	{
	public:
		B();
		~B();
		virtual void f(int);
	};

	class D : public B
	{
	public:
		D();
		virtual ~D();
		virtual void f(int) override;
	};

	class F : public D
	{
	public:
		F();
		~F();
		virtual void f(int) override;
	};

	class CTestClass
	{
	public:
		CTestClass();
		~CTestClass();
		void doAction();
	};
}

#endif // CXX_CTESTCLASS_H