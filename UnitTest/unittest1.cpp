#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Programming project/Point2f.h"
#include "../Programming project/String.h"
#include "../Programming project/String.cpp"
#include "../Programming project/SList.h"
#include "../Programming project/DList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace Point2fTests
{


	TEST_CLASS(PointTests)
	{
	public:

		TEST_METHOD(opeRest)
		{

			Point2f <int> a;
			Point2f <int> b;
			Point2f <int> c;

			a.x = 10;
			a.y = -10;
			b.x = 7;
			b.y = 7;

			c = a - b;

			Assert::IsTrue(c.x == 3 && c.y == -17);
			Assert::IsTrue(a.x == 10 && a.y == -10);
			Assert::IsTrue(b.x == 7 && b.y == 7);
		}

		TEST_METHOD(opeSum)
		{
			Point2f <int> a;
			Point2f <int> b;
			Point2f <int> c;

			a.x = 10;
			a.y = -10;
			b.x = 7;
			b.y = 7;

			c = a + b;

			Assert::IsTrue(c.x == 17 && c.y == -3);
			Assert::IsTrue(a.x == 10 && a.y == -10);
			Assert::IsTrue(b.x == 7 && b.y == 7);
		}

		TEST_METHOD(opeAdd)
		{
			Point2f <int> a;
			Point2f <int> b;

			a.x = 10;
			a.y = -10;
			b.x = 7;
			b.y = 7;

			a += b;

			Assert::IsTrue(a.x == 17 && a.y == -3);
			Assert::IsTrue(b.x == 7 && b.y == 7);
		}

		TEST_METHOD(opeSubs)
		{
			Point2f <int> a;
			Point2f <int> b;

			a.x = 10;
			a.y = -10;
			b.x = 7;
			b.y = 7;

			a -= b;

			Assert::IsTrue(a.x == 3 && a.y == -17);
			Assert::IsTrue(b.x == 7 && b.y == 7);
		}

		TEST_METHOD(opeEqualTo)
		{
			Point2f <int> a;
			Point2f <int> b;

			a.x = 10;
			a.y = 10;
			b.x = 10;
			b.y = 10;

			Assert::IsTrue(a == b);

			b.x = 0;

			Assert::IsFalse(a == b);
		}

		TEST_METHOD(opeDifferentTo)
		{
			Point2f <int> a;
			Point2f <int> b;

			a.x = 10;
			a.y = 10;
			b.x = 9;
			b.y = 10;

			Assert::IsTrue(a != b);

			b.x = 10;

			Assert::IsFalse(a != b);
		}
		TEST_METHOD(DistanceTo)
		{
			Point2f <float> a;
			Point2f <float> b;

			a.x = 3;
			a.y = 3;
			b.x = 6;
			b.y = 7;

			Assert::IsTrue(a.DistanceTo(b) == 5);
		}

		TEST_METHOD(SetZero)
		{
			Point2f <int> a;
			a.SetZero();
			Assert::IsTrue(a.x == 0 && a.y == 0);
		}

		TEST_METHOD(IsZero)
		{
			Point2f <int> a;
			a.x = 0;
			a.y = 0;
			Assert::IsTrue(a.IsZero());
		}
	};
}
namespace StringTests
{

	TEST_CLASS(StringTests)
	{
	public:
		TEST_METHOD(opeEqualTo_char)
		{
			String a("hello");

			Assert::IsTrue(a == ("hello"));
			Assert::IsFalse(a == ("hi"));
		}

		TEST_METHOD(opeEqualTo_string)
		{
			String a("hello");
			String b("hello");
			String c("hi");

			Assert::IsTrue(a == b);
			Assert::IsFalse(a == c);
		}

		TEST_METHOD(opeDifferentTo_char)
		{
			String a("hello");

			Assert::IsTrue(a != "hi");
			Assert::IsFalse(a != "hello");
		}

		TEST_METHOD(opeDifferentTo_string)
		{
			String a("hello");
			String b("hello");
			String c("hi");

			Assert::IsTrue(a != c);
			Assert::IsFalse(a != b);
		}

		TEST_METHOD(opeAssignment_char)
		{
			String a("hello");

			Assert::IsTrue(a == "hello");
		}

		TEST_METHOD(opeAssignment_string)
		{
			String a("hello");
			String b("hello");

			Assert::IsTrue(b == a);
		}

		TEST_METHOD(opeCat_char)
		{
			String a("hello");

			a += "hi";

			Assert::IsTrue(a == "hellohi");
		}

		TEST_METHOD(opeCat_string)
		{
			String a("hello");
			String b("hi");

			a += b;

			Assert::IsTrue(a == "hellohi");
		}

		TEST_METHOD(GetLenght)
		{
			String a("hello");

			Assert::IsTrue(a.GetLenght() == 5);
		}

		TEST_METHOD(GetCapacity)
		{
			String a("hello");

			Assert::IsTrue(a.GetCapacity() == 6);
		}

		TEST_METHOD(GetString)
		{
			String a("hello");

			Assert::IsTrue(strcmp(a.GetString(), "hello") == 0);
		}

		TEST_METHOD(Clear)
		{
			String a("hello");

			a.Clear();

			Assert::IsTrue(strcmp(a.str, "") == 0);
		}
	};
}
namespace SListTests
{
	TEST_CLASS(SListMethods)
	{
		TEST_METHOD(NodeCounter)
		{
			SList <int> list;
			Assert::IsTrue(list.NodeCounter() == 0);
			list.Add(5);
			list.Add(2);
			Assert::IsTrue(list.NodeCounter() == 2);
		}

		TEST_METHOD(Add)
		{
			SList <int> list;
			list.Add(3);
			Assert::IsTrue(list.NodeCounter() == 1);
		}

		TEST_METHOD(DelNode)
		{
			SList <int> list;
			list.Add(5);
			list.Add(3);
			list.Add(4);
			list.DelNode(list.GetPointer(2));
			Assert::IsTrue(list.NodeCounter() == 2);
		}

		TEST_METHOD(DelList)
		{
			DList <int> list;
			list.Add(5);
			list.Add(5);
			list.Add(5);
			list.DelList();
			Assert::IsTrue(list.NodeCounter() == 0);
		}
	};
}

namespace DListTests
{
	TEST_CLASS(DListMethods)
	{
		TEST_METHOD(NodeCounter)
		{
			DList <int> list;
			Assert::IsTrue(list.NodeCounter() == 0);
			list.Add(5);
			list.Add(2);
			Assert::IsTrue(list.NodeCounter() == 2);
		}

		TEST_METHOD(Add)
		{
			DList <int> list;
			list.Add(3);
			Assert::IsTrue(list.NodeCounter() == 1);
		}

		TEST_METHOD(DelNode)
		{
			DList <int> list;
			list.Add(5);
			list.Add(3);
			list.Add(4);
			list.DelNode(list.GetPointer(2));
			Assert::IsTrue(list.NodeCounter() == 2);
		}

		TEST_METHOD(DelList)
		{
			DList <int> list;
			list.Add(5);
			list.Add(5);
			list.Add(5);
			list.DelList();
			Assert::IsTrue(list.NodeCounter() == 0);
		}
	};
}

namespace DynArrayTests
{
	TEST_CLASS(DynArrayMethods)
	{
		
	}
}