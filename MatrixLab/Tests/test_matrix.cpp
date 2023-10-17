#include "matrixvector.h"
#include "gtest.h"

TEST(TMatrix, can_create_matrix_with_positive_length) {
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix) {
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length) {
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix) {
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one) {
	bool equal = 1;
	TMatrix<int> m(5);
	TMatrix<int> mc(m);
	if (m != mc)
		equal = 0;
	EXPECT_EQ(1, equal);
}

TEST(TMatrix, copied_matrix_has_its_own_memory) {
	bool equal = 0;
	TMatrix<int> m(5);
	TMatrix<int> mc(m);
	if (&m == &mc)
		equal = 1;
	EXPECT_EQ(0, equal);
}

TEST(TMatrix, can_get_size) {
	TMatrix<int> m(5);
	EXPECT_EQ(5, m.size());
}

TEST(TMatrix, can_set_and_get_element) {
	TMatrix<int> m(5);
	m[0][0] = 4;
	EXPECT_EQ(4, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index) {
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[0].at(-1));
}
TEST(TMatrix, throws_when_set_element_with_too_large_index) {
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[0].at(7));
}

TEST(TMatrix, can_assign_matrix_to_itself) {
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size) {
	TMatrix<int> m(5);
	TMatrix<int> m1(5);
	ASSERT_NO_THROW(m = m1);
}

TEST(TMatrix, assign_operator_change_matrix_size) {
	TMatrix<int> m(4);
	TMatrix<int> m1(5);
	m = m1;
	EXPECT_EQ(5, m.size());
}

TEST(TMatrix, can_assign_matrix_eqsize) {
	TMatrix<int> m(4);
	TMatrix<int> m1(5);
	ASSERT_NO_THROW(m = m1);
}

TEST(TMatrix, compare_equal_matrices_return_true) {
	int datai[2] = { 1,2 };
	TVector<int> data(datai, 2);
	TMatrix<int> m(2);
	m[0] = data;
	m[1] = data;
	TMatrix<int> m1(m);
	EXPECT_EQ(1, m == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true) {
	TMatrix<int> m(2);
	EXPECT_EQ(1, m == m);
}

TEST(TMatrix, cmp_matrix_with_itself) {
	TMatrix<int> m(2);
	TMatrix<int> m1(3);
	EXPECT_EQ(0, m == m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size) {
	TMatrix<int> m(2);
	TMatrix<int> m1(2);
	ASSERT_NO_THROW(m + m1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size) {
	TMatrix<int> m(2);
	TMatrix<int> m1(4);
	ASSERT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size) {
	TMatrix<int> m(2);
	TMatrix<int> m1(2);
	ASSERT_NO_THROW(m - m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size) {
	TMatrix<int> m(2);
	TMatrix<int> m1(4);
	ASSERT_ANY_THROW(m - m1);
}
