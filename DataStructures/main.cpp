#include "MyStack.h"
#include<iostream>
#include <string>

int main() {
	MyStack<int> stack(4);

	for (size_t i = 0; i < 1000; i++) {
		std::cout << i << std::endl;
		stack.Push(i);
	}
	//LOG("aaa");
	std::cout << std::to_string(*stack.Pop()) << std::endl;
	std::cout << std::to_string(*stack.Peek()) << std::endl;
	char exit;
	std::cin>>exit;
}