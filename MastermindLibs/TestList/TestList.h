#pragma once
#include "List.h"

class TestList
{
public:
    TestList(void);
    ~TestList(void);

    void RunAllTests();
	void testPushBack();
	void testInsert();
	void testErase();
	void testGetElement();
	void testGetNbElement();
	void testIsEmpty();
	void testClear();
	void testNext();
	void testPrevious();
	void testGetCurrent();
	void testSetCurrent();
};

