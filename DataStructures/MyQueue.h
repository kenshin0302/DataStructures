#pragma once
#include <string.h>

//基于数组的队列
template<typename T>
class MyQueue {
public:
	MyQueue(size_t initSize = 4) {
		content = (T*)::operator new[](sizeof(T)* initSize);
		memset(content, 0, sizeof(T) * initSize);
		arraySize = initSize;
		size = 0;
		headIndex = 0;
	}

	~MyQueue() {

	}

	void Enqueue(T node) {
		if (size == arraySize) {
			Resize();
		}
		size_t tailIndex = (headIndex + size) % arraySize;
		content[tailIndex] = node;
		size++;
	}

	T Dequeue() {
		if (size == 0) {
			return NULL;
		}
		size_t index = headIndex;
		headIndex = (headIndex + 1) % arraySize;
		return content[index];
		size--;
	}

private:
	T* content;
	size_t arraySize;
	size_t size;
	size_t headIndex;

	void Resize() {
		T* temp = (T*)::operator new[](sizeof(T)* arraySize * 2);
		memset(temp, 0, sizeof(T) * arraySize * 2);

		for (size_t i = 0; i < size; i++) {
			temp[i] = content[(headIndex + i) % arraySize];
		}

		delete[] content;
		content = temp;
		arraySize = 2 * arraySize;
	}
};