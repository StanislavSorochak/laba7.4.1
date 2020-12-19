#include "pch.h"
#include "CppUnitTest.h"
#include "../laba7.4.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest741
{
	TEST_CLASS(UnitTest741)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 2, colCount = 2;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			a[0][0] = 3, a[0][1] = -2, a[1][0] = 12, a[1][1] = -5;
			int suma = Sum(a, rowCount, colCount, 0, 0, 0);
			Assert::AreEqual(suma, 8);
			delete[]a;
		}
	};
}
