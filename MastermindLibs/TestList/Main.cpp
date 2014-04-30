#include "TestList.h"
#include "List.h"

void main()
{
    TestList testlist;
	List<int> liste;
	int* element;
	for (int i = 0; i < 10; i++)
	{
		element = &i;
		liste.PushBack(element);
	}
	cout << liste;

	system("pause");
}