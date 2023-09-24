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

///

TEST(test_minmax_out, checkmin) {
	bool all_correct = 0;
	std::vector<int> vec = {5 , 2, -3, 10, 2};

	EXPECT_EQ(outpair(vec).first, -3);
}

TEST(test_minmax_out, checkmax) {
	bool all_correct = 0;
	std::vector<int> vec = { 5 , 2, -3, 10, 2 };

	EXPECT_EQ(outpair(vec).second, 10);
}

///

TEST(test_arrayaddtovec, check_size) {
	std::vector<int> vec = { 6, 2 ,1 ,5 };
	int array[4] = { 5,2,6,9 };

	addtoend(vec, array,4);

	EXPECT_EQ(vec.size(), 8);
}

TEST(test_arrayaddtovec, check_min) {
	std::vector<int> vec = { 6, 2 ,1 ,5 };
	int array[4] = { 5,2,6,9 };

	addtoend(vec, array,4);

	EXPECT_EQ(*vec.begin(), 1);
}
TEST(test_arrayaddtovec, check_max) {
	std::vector<int> vec = { 6, 2 ,1 ,5 };
	int array[4] = { 5,2,6,9 };

	addtoend(vec, array, 4);

	EXPECT_EQ(*(vec.end()-1), 9);
}

///

TEST(test_cmptozero, check_vec) {
	std::vector<int> vec = { 6,2,1,5 };

	cmpvectozero(vec, 3);
	EXPECT_EQ(vec[0] + vec[3], 11);

}

///

TEST(createvectorbiggerthancmp__, check_array) {
	std::vector<int> vec = { 6, 2 ,1 ,5 };
	std::vector<int> veccmp = createvectorbiggerthancmp(vec, 3);

	EXPECT_EQ(veccmp[0] == 6 && veccmp[1] == 5, 1);
}

///

TEST(erasevector_, check_erased) {
	std::vector<int> vec = { 1,2,3,4,5,6,7 };
	erasevector(vec);
	EXPECT_EQ(vec.size(), 0);
}