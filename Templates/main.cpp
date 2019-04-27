#include <iostream>
#include "Stack.h"

void test()
{
	Stack<int> st(5);
	
	st.add(45);
	st.add(1);
	st.add(6);
	st.add(3);
	st.add(37); 	
	st.add(4);	   //check resize function

	std::cout << "Print elements: " << std::endl;
	st.print();

	std::cout << "Empty: ";
	std::cout << (st.isEmpty() ? "yes" : "no") << std::endl;

	std::cout << "Top element is: " << st.peek() << std::endl;

	st.pop();
	std::cout << "After popping element, stack is: " << std::endl;
	st.print();
	std::cout << "After popping element, top element is: " << st.peek() << std::endl;

	st.sorting();
	std::cout << "After sorting elements in stack: " << std::endl;
	st.print();

	st.writeInFile("stack.txt");
}

int main()
{
	test();
	return 0;
}