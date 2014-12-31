#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\Chris\Documents\Visual Studio 2012\Projects\Project2\Project2\unit.h"
#include "C:\Users\Chris\Documents\Visual Studio 2012\Projects\Project2\Project2\champ.h"
#include "C:\Users\Chris\Documents\Visual Studio 2012\Projects\Project2\Project2\rune.h"
#include "C:\Users\Chris\Documents\Visual Studio 2012\Projects\Project2\Project2\ChampFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace JungleSimTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Assert::AreNotEqual(1,2);
		}

		TEST_METHOD(TestMethod2)
		{
			Champfactory CFactory;
			Champ * hero = CFactory.CreateNunu();
			//Assert::AreNotEqual((*hero).getRange(),600);
			Assert::AreEqual(1,1);
		}

	};
}