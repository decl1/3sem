#pragma once 
#include <vector>
#include <algorithm>
#include <stdlib.h> 

void fillvectortwentyzero(std::vector<int>& vec) {
	if (vec.size() != 0)
		vec.clear();
	for (int i = 0; i < 20; i++) {
		vec.push_back(0);
	}
};

int randvecset(std::vector<int>& vec) {
	int rand_set = (rand() % 200 + 1 - 100);
	vec.push_back(rand_set);
	auto iter = vec.end() - 1;
	return (*iter);
}

std::pair<int,int> outpair(const std::vector<int>& vec) {
	int locmin = (*vec.begin());
	int locmax = locmin;
	for (auto iter = vec.begin(); iter != vec.end(); iter++) {
		if ((*iter) > locmax)
			locmax = (*iter);
		if ((*iter) < locmin)
			locmin = (*iter);
	}
	std::pair<int, int> result(locmin, locmax);
	return result;
}

void addtoend(std::vector<int>& vec, int array[], int size) {
	for (int i = 0; i < size; i++) {
		vec.push_back(array[i]);
	}
	sort(vec.begin(), vec.end());
}

void cmpvectozero(std::vector<int>& vec, int cmp) {
	std::replace_if(vec.begin(), vec.end(), [cmp](int& i) {
		return i < cmp;
		}, 0);
}

std::vector<int> createvectorbiggerthancmp(std::vector<int> vec, int cmp) {
	std::vector<int> result;
	for (auto i : vec) {
		if (i > cmp)
			result.push_back(i);
	}
	return result;
}

void erasevector(std::vector<int>& vec) {
	vec.clear();
}