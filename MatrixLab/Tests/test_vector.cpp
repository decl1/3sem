#include "matrixvector.h"
#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length) {
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector) {
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, can_get_size) {
  TVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TVector, can_set_and_get_element) {
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_create_vector_with_negative_length) {
	ASSERT_ANY_THROW(TVector<int> v(-1));
}

TEST(TVector, can_create_copied_vector) {
	TVector<int> vc(2);
	ASSERT_NO_THROW(TVector<int> v(vc));
}

TEST(TVector, copied_vector_is_equal_to_source_one) {
	int data[3] = { 3,1,2 };
	TVector<int> v1(data, 3);
	TVector<int> vcopy(v1);
	bool equal = 1;
	for (int i = 0; i < 3; i++) {
		equal = (v1[i] != vcopy[i]);
	}
	EXPECT_EQ(1, equal);
}

TEST(TVector, copied_vector_has_its_own_memory) {
	int data[3] = { 3,1,2 };
	TVector<int> v1(data, 3);
	TVector<int> vcopy(v1);
	bool equal = (&v1[0] != &vcopy[0]);
	EXPECT_EQ(1, equal);
}

TEST(TVector, throws_when_create_vector_with_negative_length) {
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index) {
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[7]);
}

TEST(TVector, can_assign_vector_to_itself) {
	TVector<int> v1(3);

	ASSERT_NO_THROW(v1 = v1);
}

TEST(TVector, can_assign_vectors_of_equal_size) {
	TVector<int> v1(3);
	TVector<int> v2(3);

	ASSERT_NO_THROW(v1 = v2);
}


TEST(TVector, assign_operator_change_vector_size) {
	TVector<int> v1(3);
	TVector<int> v2(5);
	v1 = v2;

	EXPECT_EQ(5, v1.size());
}

TEST(TVector, can_assign_vectors_of_different_size) {
	TVector<int> v1(3);
	TVector<int> v2(5);

	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, compare_equal_vectors_return_true) {
	int data[3] = { 3,1,2 };
	TVector<int> v1(data, 3);
	TVector<int> vcopy(v1);
	EXPECT_EQ(1, v1 == vcopy);
}

TEST(TVector, compare_vector_with_itself_return_true) {
	int data[3] = { 3,1,2 };
	TVector<int> v1(data, 3);
	EXPECT_EQ(1, v1 == v1);
}

TEST(TVector, cvectors_with_different_size_are_not_equal) {
	TVector<int> v1(3);
	TVector<int> v2(5);
	EXPECT_EQ(0, v1 == v2);
}

TEST(TVector, can_add_scalar_to_vector) {
	int data[3] = { 3,1,2 };
	TVector<int> v1(data, 3);
	v1 = v1 + 2;
	EXPECT_EQ(5, v1[0]);
}

TEST(TVector, can_subtract_scalar_from_vector) {
	int data[3] = { 3,1,2 };
	TVector<int> v1(data, 3);
	v1 = v1 - 2;
	EXPECT_EQ(1, v1[0]);
}

TEST(TVector, can_multiply_scalar_by_vector) {
	int data[3] = { 3,1,2 };
	TVector<int> v1(data, 3);
	v1 = v1 * 2;
	EXPECT_EQ(6, v1[0]);
}

TEST(TVector, can_add_vectors_with_equal_size) {
	int data[3] = { 3,1,2 };
	TVector<int> v1(data, 3);
	TVector<int> v2(v1);
	v1 = v1 + v2;
	EXPECT_EQ(6, v1[0]);
}
TEST(TVector, cant_add_vectors_with_not_equal_size) {
	TVector<int> v1(3);
	TVector<int> v2(5);
	ASSERT_ANY_THROW(v1 + v2;);
}

TEST(TVector, can_subtract_vectors_with_equal_size) {
	int data[3] = { 3,1,2 };
	TVector<int> v1(data, 3);
	TVector<int> v2(v1);
	v1 = v1 - v2;
	EXPECT_EQ(0, v1[0]);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size) {
	TVector<int> v1(3);
	TVector<int> v2(5);
	ASSERT_ANY_THROW(v1 - v2;);
}

TEST(TVector, can_multiply_vectors_with_equal_size) {
	int data[3] = { 3,1,2 };
	TVector<int> v1(data, 3);
	TVector<int> v2(v1);

	EXPECT_EQ(14, v1 * v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size) {
	TVector<int> v1(3);
	TVector<int> v2(5);
	ASSERT_ANY_THROW(v1 * v2;);
}