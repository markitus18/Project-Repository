#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\Programming project\Point2f.h"
#include "..\Programming project\String.h"
#include "..\Programming project\String.cpp"
#include "..\Programming project\SList.h"
#include "..\Programming project\DList.h"
#include "..\Programming project\DynArray.h"

#include "..\Programming project\Projectile.h"
#include "..\Programming project\Point2f.h"
#include "..\Programming project\DynArray.h"
#include "..\Programming project\String.h"
#include "..\Programming project\globals.h"
#include "..\Programming project\DList.h"

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
TEST_METHOD(DynArray_constructor1)
{
DynArray<int> array;
Assert::AreEqual((int)array.GetCapacity(), 0);
}

TEST_METHOD(DynArray_constructor)
{
DynArray<int> array(33);
Assert::AreEqual((int)array.GetCapacity(), 34);
}

TEST_METHOD(DynArray_push_back)
{
DynArray<int> array;

array.PushBack(1);
array.PushBack(2);
array.PushBack(3);
Assert::AreEqual((int)array.GetCapacity(), 4);
Assert::AreEqual((int)array.GetSize(), 3);
}

TEST_METHOD(DynArray_pop)
{
DynArray<int> array;

array.PushBack(1);
array.PushBack(2);
array.PushBack(3);

Assert::IsTrue(array.Pop());
Assert::IsTrue(array.Pop());

Assert::AreEqual((int)array.GetCapacity(), 4);
Assert::AreEqual((int)array.GetSize(), 1);

}

TEST_METHOD(DynArray_clear)
{
DynArray<int> array;

array.PushBack(1);
array.PushBack(2);
array.PushBack(3);
array.Clear();

Assert::AreEqual((int)array.GetCapacity(), 4);
Assert::AreEqual((int)array.GetSize(), 0);
}


TEST_METHOD(DynArray_op)
{
DynArray<int> array;

array.PushBack(1);
array.PushBack(2);
array.PushBack(3);

Assert::AreEqual(array[0], 1);
Assert::AreEqual(array[1], 2);
Assert::AreEqual(array[2], 3);
}

TEST_METHOD(DynArray_at)
{
DynArray<int> array;

array.PushBack(1);
array.PushBack(2);
array.PushBack(3);

Assert::AreEqual(*(array.At(0)), 1);
Assert::AreEqual(*(array.At(1)), 2);
Assert::AreEqual(*(array.At(2)), 3);
Assert::IsNull(array.At(3));
}

TEST_METHOD(DynArray_resize)
{
DynArray<int> array;

for (int i = 0; i < 999; ++i)
{
array.PushBack(i);
}

Assert::AreEqual(*(array.At(900)), 900);
Assert::IsNull(array.At(1000));

Assert::AreEqual((int)array.GetCapacity(), 1000);
Assert::AreEqual((int)array.GetSize(), 999);
}

TEST_METHOD(DynArray_insert)
{
DynArray<int> array;

for (int i = 0; i < 16; ++i)
{
array.PushBack(i);
}

array.Insert(999, 3);
array.Insert(888, 5);
array.Insert(777, 8);

Assert::IsFalse(array.Insert(777, 50));
Assert::AreEqual((int)array.GetCapacity(), 20);
Assert::AreEqual((int)array.GetSize(), 19);
Assert::AreEqual((int)array[3], 999);
Assert::AreEqual((int)array[5], 888);
Assert::AreEqual((int)array[8], 777);
}

};
}


namespace ExamTests
{
	TEST_CLASS(ExamTests)
	{
	public:
		// Projectile ----------------------------------------
		TEST_METHOD(Projectile_test)
		{
			Projectile p;
			p.x = 10.0f;
			p.y = 10.0f;
			p.speedx = 2.0f;
			p.speedy = 0.0f;
			Point2f<float> current = p.GetCurrentPosition(3.0f);
			Assert::AreEqual((float)16.0f, current.x, 0.00001f);
			Assert::AreEqual((float)10.0f, current.y, 0.00001f);
		}

		TEST_METHOD(ArrDyn_optimizeMem)
		{
			DynArray<int> array(10);
			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			Assert::AreEqual((unsigned int)10, array.GetCapacity());
			unsigned int wasted = array.removeWastedMemory();
			Assert::AreEqual((unsigned int)3, array.GetCapacity());
			Assert::AreEqual((unsigned int)7, wasted);
			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
		}

		/*		TEST_METHOD(String_prefix)
				{
				String a("1234567890");
				String b("asdfasdfasdfasdfasdfasdfsdaf");
				b = "hola";
				a.prefix(b);
				b.prefix("1234567890");
				Assert::AreEqual(strcmp(a.GetString(), "hola1234567890"), 0);
				Assert::AreEqual(strcmp(b.GetString(), "1234567890hola"), 0);
				Assert::IsTrue(1 == 1);
				}*/

		TEST_METHOD(p2List_delNodes_mid)
		{
			DList<int> l;
			l.Add(1);
			l.Add(2);
			l.Add(3);
			l.Add(4);
			l.DelNodes(1, 2);
			Assert::AreEqual((int)1, l.start->atr);
			Assert::AreEqual((int)4, l.end->atr);
			Assert::AreEqual((unsigned int)2, l.NodeCounter());
		}
	};
}

namespace TreeTests
{
	TEST_CLASS(OrderTests)
	{

	};

}