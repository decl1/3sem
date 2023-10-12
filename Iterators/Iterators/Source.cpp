#include "Header.h"

void main() {
	TVector<int> v1(5);
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it;
	}
}