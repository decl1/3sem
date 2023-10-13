#include "Header.h"

void main() {
	TVector<int> v1(5);
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it;
	}
	v1.TFill(4);
	std::cout << std::endl;
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it;
	}
	v1.TFill_n(2,2);
	std::cout << std::endl;
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it;
	}
	v1.TReplace(2, 3);
	std::cout << std::endl;
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it;
	}
	v1.TReplace_n(4, 5, 4);
	std::cout << std::endl;
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it;
	}

}