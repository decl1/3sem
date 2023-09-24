#pragma once 
#include <vector>
#include <stdlib.h> 

void fillvectortwentyzero(std::vector<int>& vec) {
	if (vec.size() != 0)
		vec.clear();
	for (int i = 0; i < 20; i++) {
		vec.push_back(0);
	}
};

int randvecset(std::vector<int>& vec) {
	vec.push_back(rand() % 200 + 1 - 100);
	auto iter = vec.end();
	return (*iter);
}