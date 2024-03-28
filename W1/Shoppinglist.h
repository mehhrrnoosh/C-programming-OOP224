#pragma once
#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

// Your header file content goes here
#include "ShoppingRec.h"

namespace sdds {
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}
#endif
