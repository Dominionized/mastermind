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

	if (liste.IsEmpty() == false)
	{
		if (iterateur.GetCurrent() == liste.Begin())
		{
			Cell<int>* testCell = new Cell<int>(element);
			testCell = liste.Insert(*element, iterateur.GetCurrent());
			assert(testCell->Element == liste.Begin()->Element);
		}
		else
		{

		}
	}
}
void TestList::testIsEmpty()
{
	List<int> liste;

	assert(liste.Begin()->Element == NULL);
}