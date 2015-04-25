#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\Programming project\Point2f.h"
#include "..\Programming project\String.cpp"
#include "..\Programming project\SList.h"
#include "..\Programming project\DynArray.h"

#include "..\Programming project\Projectile.h"
#include "..\Programming project\String.h"
#include "..\Programming project\globals.h"
#include "..\Programming project\DList.h"

#include "..\Programming project\Tree.h"

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
			Assert::AreEqual((int)array.GetCapacity(), 33);
		}

		TEST_METHOD(DynArray_push_back)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			Assert::AreEqual((int)array.GetCapacity(), 3);
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

			Assert::AreEqual((int)array.GetCapacity(), 3);
			Assert::AreEqual((int)array.GetSize(), 1);

		}

		TEST_METHOD(DynArray_clear)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			array.Clear();

			Assert::AreEqual((int)array.GetCapacity(), 3);
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

			Assert::AreEqual((int)array.GetCapacity(), 999);
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

			//Assert::IsFalse(array.Insert(777, 50));
			//Assert::AreEqual((int)array.GetCapacity(), 20);
			//Assert::AreEqual((int)array.GetSize(), 20);
			Assert::AreEqual((int)array[3], 999);
			Assert::AreEqual((int)array[5], 888);
			Assert::AreEqual((int)array[8], 777);
		}

	};
}

namespace TreeTests
{
	TEST_CLASS(VisitNodes)
	{
		TEST_METHOD(Preorder_Recursive)
		{
			Tree<char> myTree('1');

			treeNode <char>* two = myTree.Add('2');
			treeNode <char>* three = myTree.Add('3');
			treeNode <char>* four = myTree.Add('4');

			myTree.Add('5', two);
			myTree.Add('6', two);

			myTree.Add('7', three);

			myTree.Add('8', four);
			myTree.Add('9', four);
			myTree.Add('a', four);

			DList<char>* myList = new DList<char>;
			myTree.PreorderRecursive(myList);

			
			Assert::AreEqual(myList->GetPointer(0)->atr, '1');
			Assert::AreEqual(myList->GetPointer(1)->atr, '2');
			Assert::AreEqual(myList->GetPointer(2)->atr, '5');
			Assert::AreEqual(myList->GetPointer(3)->atr, '6');
			Assert::AreEqual(myList->GetPointer(4)->atr, '3');
			Assert::AreEqual(myList->GetPointer(5)->atr, '7');
			Assert::AreEqual(myList->GetPointer(6)->atr, '4');
			Assert::AreEqual(myList->GetPointer(7)->atr, '8');
			Assert::AreEqual(myList->GetPointer(8)->atr, '9');
			Assert::AreEqual(myList->GetPointer(9)->atr, 'a');
		}

		TEST_METHOD(Preorder_Iterative)
		{
			Tree<char> myTree('1');

			treeNode <char>* two = myTree.Add('2');
			treeNode <char>* three = myTree.Add('3');
			treeNode <char>* four = myTree.Add('4');

			myTree.Add('5', two);
			myTree.Add('6', two);

			myTree.Add('7', three);

			myTree.Add('8', four);
			myTree.Add('9', four);
			myTree.Add('a', four);

			DList<char>* myList = new DList<char>;
			myTree.PreorderIterative(myList);


			Assert::AreEqual(myList->GetPointer(0)->atr, '1');
			Assert::AreEqual(myList->GetPointer(1)->atr, '2');
			Assert::AreEqual(myList->GetPointer(2)->atr, '5');
			Assert::AreEqual(myList->GetPointer(3)->atr, '6');
			Assert::AreEqual(myList->GetPointer(4)->atr, '3');
			Assert::AreEqual(myList->GetPointer(5)->atr, '7');
			Assert::AreEqual(myList->GetPointer(6)->atr, '4');
			Assert::AreEqual(myList->GetPointer(7)->atr, '8');
			Assert::AreEqual(myList->GetPointer(8)->atr, '9');
			Assert::AreEqual(myList->GetPointer(9)->atr, 'a');
		}

		TEST_METHOD(Inorder_Recursive)
		{
			Tree<char> myTree('1');

			treeNode <char>* two = myTree.Add('2');
			treeNode <char>* three = myTree.Add('3');
			treeNode <char>* four = myTree.Add('4');

			myTree.Add('5', two);
			myTree.Add('6', two);

			myTree.Add('7', three);

			myTree.Add('8', four);
			myTree.Add('9', four);
			myTree.Add('a', four);

			DList<char>* myList = new DList<char>;
			myTree.InorderRecursive(myList);

			Assert::AreEqual(myList->GetPointer(0)->atr, '5');
			Assert::AreEqual(myList->GetPointer(1)->atr, '2');
			Assert::AreEqual(myList->GetPointer(2)->atr, '6');
			Assert::AreEqual(myList->GetPointer(3)->atr, '1');
			Assert::AreEqual(myList->GetPointer(4)->atr, '3');
			Assert::AreEqual(myList->GetPointer(5)->atr, '7');
			Assert::AreEqual(myList->GetPointer(6)->atr, '8');
			Assert::AreEqual(myList->GetPointer(7)->atr, '4');
			Assert::AreEqual(myList->GetPointer(8)->atr, '9');
			Assert::AreEqual(myList->GetPointer(9)->atr, 'a');
		}

		TEST_METHOD(Inorder_Iterative)
		{
			Tree<char> myTree('1');

			treeNode <char>* two = myTree.Add('2');
			treeNode <char>* three = myTree.Add('3');
			treeNode <char>* four = myTree.Add('4');

			myTree.Add('5', two);
			myTree.Add('6', two);

			myTree.Add('7', three);

			myTree.Add('8', four);
			myTree.Add('9', four);
			myTree.Add('a', four);

			DList<char>* myList = new DList<char>;
			myTree.InorderIterative(myList);

			Assert::AreEqual(myList->GetPointer(0)->atr, '5');
			Assert::AreEqual(myList->GetPointer(1)->atr, '2');
			Assert::AreEqual(myList->GetPointer(2)->atr, '6');
			Assert::AreEqual(myList->GetPointer(3)->atr, '1');
			Assert::AreEqual(myList->GetPointer(4)->atr, '3');
			Assert::AreEqual(myList->GetPointer(5)->atr, '7');
			Assert::AreEqual(myList->GetPointer(6)->atr, '8');
			Assert::AreEqual(myList->GetPointer(7)->atr, '4');
			Assert::AreEqual(myList->GetPointer(8)->atr, '9');
			Assert::AreEqual(myList->GetPointer(9)->atr, 'a');
		}

		TEST_METHOD(Postorder_Recursive)
		{
			Tree<char> myTree('1');

			treeNode <char>* two = myTree.Add('2');
			treeNode <char>* three = myTree.Add('3');
			treeNode <char>* four = myTree.Add('4');

			myTree.Add('5', two);
			myTree.Add('6', two);

			myTree.Add('7', three);

			myTree.Add('8', four);
			myTree.Add('9', four);
			myTree.Add('a', four);

			DList<char>* myList = new DList<char>;
			myTree.PostorderRecursive(myList);

			Assert::AreEqual(myList->GetPointer(0)->atr, '5');
			Assert::AreEqual(myList->GetPointer(1)->atr, '6');
			Assert::AreEqual(myList->GetPointer(2)->atr, '2');
			Assert::AreEqual(myList->GetPointer(3)->atr, '7');
			Assert::AreEqual(myList->GetPointer(4)->atr, '3');
			Assert::AreEqual(myList->GetPointer(5)->atr, '8');
			Assert::AreEqual(myList->GetPointer(6)->atr, '9');
			Assert::AreEqual(myList->GetPointer(7)->atr, 'a');
			Assert::AreEqual(myList->GetPointer(8)->atr, '4');
			Assert::AreEqual(myList->GetPointer(9)->atr, '1');
		}

		TEST_METHOD(Postorder_Iterative)
		{
			Tree<char> myTree('1');

			treeNode <char>* two = myTree.Add('2');
			treeNode <char>* three = myTree.Add('3');
			treeNode <char>* four = myTree.Add('4');

			myTree.Add('5', two);
			myTree.Add('6', two);

			myTree.Add('7', three);

			myTree.Add('8', four);
			myTree.Add('9', four);
			myTree.Add('a', four);

			DList<char>* myList = new DList<char>;
			myTree.PostorderIterative(myList);

			Assert::AreEqual(myList->GetPointer(0)->atr, '5');
			Assert::AreEqual(myList->GetPointer(1)->atr, '6');
			Assert::AreEqual(myList->GetPointer(2)->atr, '2');
			Assert::AreEqual(myList->GetPointer(3)->atr, '7');
			Assert::AreEqual(myList->GetPointer(4)->atr, '3');
			Assert::AreEqual(myList->GetPointer(5)->atr, '8');
			Assert::AreEqual(myList->GetPointer(6)->atr, '9');
			Assert::AreEqual(myList->GetPointer(7)->atr, 'a');
			Assert::AreEqual(myList->GetPointer(8)->atr, '4');
			Assert::AreEqual(myList->GetPointer(9)->atr, '1');
		}

	};

}