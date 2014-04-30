#include "TestList.h"
#include "List.h"
#include "Cell.h"
#include <assert.h>

TestList::TestList(void)
{
}


TestList::~TestList(void)
{
}

void TestList::RunAllTests()
{
	testPushBack();
	testIsEmpty();
	testInsert();
	testErase();
	testGetElement();
	testGetNbElement();
	testClear();
	testNext();
	testPrevious();
	testGetCurrent();
	testSetCurrent();
}
void TestList::testPushBack()
{
	cout << "test PushBack" << endl;
	List<int> liste;
	int* element;

	liste.PushBack(element);
	assert(liste.End()->Element == element);
}
void TestList::testInsert()
{
	cout << "test Insert" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int* element;

	if (liste.IsEmpty())
	{
		liste.PushBack(element);
		assert(liste.End()->Element == element);
	}
	iterateur.SetCurrent(liste.End());
	if (iterateur.GetCurrent() == liste.End())
	{
		liste.PushBack(element);
		assert(liste.End()->Element == element);
	}
	iterateur.SetCurrent(liste.Begin());
	if (iterateur.GetCurrent() == liste.Begin())
	{
		liste.Insert(element, iterateur);
		assert(liste.Begin()->Element == element);
	}
	iterateur.Next();
	liste.Insert(element, iterateur);
	assert(iterateur.GetCurrentElement == element);
}
void TestList::testIsEmpty()
{
	cout << "test IsEmpty" << endl;
	List<int> liste;

	assert(liste.Begin()->Element == NULL);
}
void TestList::testErase()
{
	cout << "test Erase" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int* element;

	iterateur.SetCurrent(liste.Begin());
	iterateur.GetCurrent()->Element = element;

	if (liste.IsEmpty() == false)
	{
		liste.Erase(iterateur);
		assert(iterateur.GetCurrentElement() == NULL);
	}
}
void TestList::testGetElement()
{
	cout << "test GetElement" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int* element;

	liste.PushBack(element);
	iterateur.SetCurrent(liste.End());
	assert(element == liste.GetElement(iterateur));
}
void TestList::testGetNbElement()
{
	cout << "test GetNbElement" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int nbElement = 0;

	iterateur.SetCurrent(liste.Begin());
	while (liste.GetElement(iterateur) != NULL)
	{
		nbElement++;
		iterateur.Next();
	}
	assert(nbElement == liste.GetNbElements());
}
void TestList::testClear()
{
	cout << "test Clear" << endl;
	List<int> liste;
	liste.Clear();
	assert(liste.Begin()->Element == NULL && liste.End()->Element == NULL);
}
void TestList::testGetCurrent()
{
	cout << "test GetCurrent" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int* element;

	liste.PushBack(element);
	assert(liste.Begin() == iterateur.GetCurrent());
}
void TestList::testSetCurrent()
{
	cout << "test SetCurrent" << endl;
	List<int> liste;
	Iterator<int> iterateur;

	iterateur.SetCurrent(liste.Begin());
	assert(iterateur.GetCurrent() == liste.Begin());
}
void TestList::testNext()
{
	cout << "test Next" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int* element;

	iterateur.SetCurrent(liste.Begin());
	liste.PushBack(element);
	iterateur.Next();
	assert(iterateur.GetCurrent() == liste.End());
}
void TestList::testPrevious()
{
	cout << "test Previous" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int* element1;
	int* element2;

	liste.PushBack(element1);
	liste.PushBack(element2);
	iterateur.SetCurrent(liste.End());
	iterateur.Previous();
	assert(iterateur.GetCurrentElement() == liste.Begin()->Element);
}