#include "gtest.h"
#include "Header.h"



TEST(test_fillvector, check_size) {
	// Arrange
	std::vector<int> vec;
	// Act
	fillvectortwentyzero(vec);
	int res = vec.size();
	// Assert
	EXPECT_EQ(res, 20);
}

TEST(test_fillvector, check_fill) {
	std::vector<int> vec;

	fillvectortwentyzero(vec);
	int res = 0;
	for (int i = 0; i < 20; i++) {
		res += vec[i];
	}
	EXPECT_EQ(res, 0);
}

///

TEST(test_setrandvec, check_rand) {
	std::vector<int> vec;
	bool test_complete = 1;
	for (int test_deep = 1000; test_deep != 0; test_deep--) {
		if (abs(randvecset(vec)) > 100) {
			bool test_complete = 0;
			break;
		}
	}
	EXPECT_EQ(test_complete, 1);
}
