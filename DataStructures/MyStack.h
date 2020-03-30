#pragma once

//使用数组实现一个栈
template<typename T>
class MyStack {
public:
	MyStack(size_t initSize) {
		content = new T[initSize];
		arraySize = initSize;
	}
	~MyStack() {
		delete[] content;
	}
	void Push(T node) {
		if (size == arraySize)
			Resize();
		size++;
		content[size - 1] = node;
	}
	T* Pop() {
		if (size == 0)
			return nullptr;
		else {
			return &content[size-- - 1];
		}
	}
	T* Peek() {
		if (size == 0)
			return nullptr;
		else {
			return &content[size - 1];
		}
	}
	void Clear() {}

	void Resize() {
		T* temp = new T[2 * size];
		for (size_t i = 0; i < size; i++) {
			temp[i] = content[i];
		}
		delete[] content;
		content = temp;
		arraySize = 2 * size;
	}

private:
	T* content;
	size_t arraySize;
	size_t size;
};