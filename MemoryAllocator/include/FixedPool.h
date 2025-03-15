#pragma once

#include "CommonStructs.h"
#include <iostream>
#include <array>

class Node {
public:
	int insertId;
	Company company;
	Node* next;
	Node* prev;
};

class FixedPool {
private:
	static const size_t FIXED_POOL = 50;
	int stored;
	Node* tail;
	Node* head;
	Node* current;
	Node* poolSize;

public:
	FixedPool();
	~FixedPool();
	Node* addCompany(Company company);
	Node* removeCompany(Company company);

	Node* getCompany(int id, char tckr[TICKER_SIZE]);
	Node* editCompany(int id, char tckr[TICKER_SIZE], Company edits);
};