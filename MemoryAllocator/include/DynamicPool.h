#pragma once 

#include <iostream>

class DynamicPool {
private:
	struct MemoryBlock {
		void* memory;
		size_t blockSize;
		MemoryBlock* next;
		MemoryBlock* prev;
	};
	MemoryBlock* blockList;
	int blocksAllocated;
	int currentBlocks;

public:
	std::string infoType(void* data);
	void* allocBlock(size_t bytsNeeded);

};