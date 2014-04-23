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

template <typename TYPE>
void TestList::RunAllTests()
{
	Cell* testCell = new Cell;
	cout << "Test de isEmpty" << endl;
	Cell<TYPE> *testCell = NULL;
	assert(testCell->isEmpty() == NULL);

	cout << "Test GetNbElement" << endl;

}
