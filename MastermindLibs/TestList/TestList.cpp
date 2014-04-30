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
	int entier = 37;
	int* element = &entier;

	liste.PushBack(element);
	assert(liste.End()->Element == element);
	cout << "Ok !" << endl;
}
void TestList::testInsert()
{
	cout << "test Insert" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int entier = 37;
	int* element = &entier;

	liste.PushBack(element);
	assert(liste.End()->Element == element);

	iterateur.SetCurrent(liste.End());
	liste.PushBack(element);
	assert(liste.End()->Element == element);

	iterateur.SetCurrent(liste.Begin());
	liste.Insert(element, iterateur);
	assert(liste.Begin()->Element == element);

	iterateur.Next();
	liste.Insert(element, iterateur);
	assert(iterateur.GetCurrentElement() == element);

	cout << "Ok !" << endl;
}
void TestList::testIsEmpty()
{
	cout << "test IsEmpty" << endl;
	List<int> liste;

	assert(liste.Begin() == NULL);
	assert(liste.End() == NULL);
	cout << "Ok !" << endl;
}
void TestList::testErase()
{
	cout << "test Erase" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int entier = 37;
	int* element = &entier;

	liste.PushBack(element);

	iterateur.SetCurrent(liste.Begin());
	iterateur.GetCurrent()->Element = element;

	if (liste.IsEmpty() == false)
	{
		liste.Erase(iterateur);
		assert(liste.IsEmpty());
	}
	cout << "Ok !" << endl;
}
void TestList::testGetElement()
{
	cout << "test GetElement" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int entier = 37;
	int* element = &entier;

	liste.PushBack(element);
	iterateur.SetCurrent(liste.End());
	assert(element == liste.GetElement(iterateur));
	cout << "Ok !" << endl;
}
void TestList::testGetNbElement()
{
	cout << "test GetNbElement" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int nbElement = 0;

	iterateur.SetCurrent(liste.Begin());
	while (iterateur.GetCurrent() != NULL)
	{
		nbElement++;
		iterateur.Next();
	}
	assert(nbElement == liste.GetNbElements());
	cout << "Ok !" << endl;
}
void TestList::testClear()
{
	cout << "test Clear" << endl;
	List<int> liste;
	liste.Clear();
	assert(liste.Begin() == NULL && liste.End() == NULL);
	cout << "Ok !" << endl;
}
void TestList::testGetCurrent()
{
	cout << "test GetCurrent" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int entier = 37;
	int* element = &entier;

	liste.PushBack(element);
	iterateur.SetCurrent(liste.End());
	assert(liste.Begin() == iterateur.GetCurrent());
	cout << "Ok !" << endl;
}
void TestList::testSetCurrent()
{
	cout << "test SetCurrent" << endl;
	List<int> liste;
	Iterator<int> iterateur;

	iterateur.SetCurrent(liste.Begin());
	assert(iterateur.GetCurrent() == liste.Begin());
	cout << "Ok !" << endl;
}
void TestList::testNext()
{
	cout << "test Next" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int entier = 37;
	int* element1 = &entier;
	int entier2 = 42;
	int* element2 = &entier2;

	liste.PushBack(element1);
	liste.PushBack(element2);
	iterateur.SetCurrent(liste.Begin());
	iterateur.Next();
	assert(iterateur.GetCurrent() == liste.End());
	cout << "Ok !" << endl;
}
void TestList::testPrevious()
{
	cout << "test Previous" << endl;
	List<int> liste;
	Iterator<int> iterateur;
	int entier = 37;
	int* element1 = &entier;
	int entier2 = 42;
	int* element2 = &entier2;

	liste.PushBack(element1);
	liste.PushBack(element2);
	iterateur.SetCurrent(liste.End());
	iterateur.Previous();
	assert(iterateur.GetCurrent() == liste.Begin());
	cout << "Ok !" << endl;
}