#pragma once
#include"item.h"


class CFile : public CItem
{
public:
	CFile(const string &name, int size);
	void addSize(CItem *) {};
	void removeSize(CItem *) {};
};

