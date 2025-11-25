#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

using namespace std;

class container {
private:
	int* elementi;
	std::size_t logicalSize;
	std::size_t physicalSize;
public:
	container(std::size_t init = 10);
	container(const container& other);
	container(container&& other);
	~container();

	void push_back(int value);
	std::size_t size() const;
	std::size_t capacity() const;
	int at(int i) const;
	void clear();
};

#endif