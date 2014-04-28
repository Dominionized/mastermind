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
}
void TestList::testPushBack()
{
	List<int> liste;
	int* element;

	liste.PushBack(element);
	assert(liste.End()->Element == element);
}
void TestList::testInsert()
{
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
	List<int> liste;

	assert(liste.Begin()->Element == NULL);
}
void TestList::testErase()
{
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
	List<int> liste;
	Iterator<int> iterateur;
	int* element;

	liste.PushBack(element);
	iterateur.SetCurrent(liste.End());
	assert(element == liste.GetElement(iterateur));
}
void TestList::testGetNbElement()
{
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
	List<int> liste;
	liste.Clear();
	assert(liste.Begin()->Element == NULL && liste.End()->Element == NULL);
}