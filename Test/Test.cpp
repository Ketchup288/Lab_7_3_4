#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7_3_4/lab_7_3_4.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int b[4][4] = { {-3, -2, -2, -3},
							{-2, -3, -2, -3},
							{-3, -2, -2, -2},
							{-2, -2, -2, -2} };
			int* pb[4] = { b[0], b[1], b[2], b[3] };
			int sum = 0;
			int max = Sum_Mtrx(pb, 4, 4, sum, 1, 0);

			Assert::AreEqual(max, 13);

		}
	};
}
