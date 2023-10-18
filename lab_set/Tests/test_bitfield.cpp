#include "..\qtest\gtest.h"
#include <climits>
#include "..\BitField\bitfield.h"

TEST(TBitField, can_get_length) {
  // Arrange & Act
  TBitField bf(5);

  // Assert
  EXPECT_EQ(5, bf.size());
}

TEST(TBitField, can_create_bitfield_with_positive_length) {
  // Arrange & Act & Assert
  ASSERT_NO_THROW(TBitField bf(5));
}

TEST(TBitField, can_create_too_large_bitfield) {
  // Arrange & Act
  TBitField bf(INT_MAX);
  // Assert
  EXPECT_EQ(INT_MAX, bf.size());

}

TEST(TBitField, new_bitfield_is_set_to_zero) {
  // Arrange & Act
  TBitField bf(150);

  // Assert
  int sum = 0;
  for (int i = 0; i < bf.size(); i++) sum += bf.test(i);
  EXPECT_EQ(0, sum);
}

TEST(TBitField, set_some_bits) {
	// Arrange & Act
	TBitField bf(150);
	std::string res1;
	std::string res2(150, '0');
	res2[4] = '1';
	res2[5] = '1';
	res2[35] = '1';
	res2[149] = '1';
	bf.set(4);
	bf.set(5);
	bf.set(35);
	bf.set(149);
	res1 = bf.to_string();
	// Assert
	EXPECT_EQ(res1, res2); //show to accept result
}

TEST(TBitField, or_for_bf) {
	// Arrange & Act
	TBitField bf1(36);
	TBitField bf2(10);
	std::string res1;
	std::string res2 = "011110100000000000000010000000000001";
	// Assert
	bf1.set(1);
	bf1.set(3);
	bf1.set(35);
	bf1.set(22);
	bf2.set(2);
	bf2.set(4);
	bf2.set(6);
	res1 = (bf1 | bf2).to_string();
	EXPECT_EQ(res1, res2);
}
TEST(TBitField, and_for_bf_no_throw) {
	// Arrange & Act
	TBitField bf1(28);
	TBitField bf2(67);
	std::string res1;
	std::string res2(28, '0');
	res2[1] = '1';
	res2[27] = '1';
	// Assert
	bf1.set(1);
	bf1.set(3);
	bf1.set(5);
	bf1.set(25);
	bf1.set(27);
	bf1.set(12);
	bf2.set(2);
	bf2.set(4);
	bf2.set(6);
	bf2.set(1);
	bf2.set(27);
	bf2.set(64);
	res1 = (bf1 & bf2).to_string();
	EXPECT_EQ(res1, res2);
}
TEST(TBitField, no_for_bf_no_throw) {
	// Arrange & Act
	TBitField bf1(10);
	std::string res1 = "1010101111";
	std::string res2;
	// Assert
	bf1.set(1);
	bf1.set(3);
	bf1.set(5);
	res2 = (~bf1).to_string();
	EXPECT_EQ(res1, res2);
}
TEST(TBitField, assig_for_bf_no_throw) {
	// Arrange & Act
	TBitField bf1(10);
	TBitField bf2(10);
	TBitField bf3(10);
	// Assert
	bf1.set(1);
	bf1.set(3);
	bf1.set(5);
	bf2.set(2);
	bf2.set(4);
	bf2.set(6);
	EXPECT_NO_THROW(bf1 = bf2);
	EXPECT_EQ(bf1, bf2);
}
TEST(TBitField, equal) {
	// Arrange & Act
	TBitField bf1(10);
	TBitField bf2(10);
	// Assert
	bf1.set(1);
	bf1.set(3);
	bf1.set(5);
	bf2.set(1);
	bf2.set(3);
	bf2.set(5);
	EXPECT_EQ(bf1, bf2);
}
TEST(TBitField, double_set) {
	// Arrange & Act
	TBitField bf1(10);
	TBitField bf2(10);
	// Assert
	bf1.set(1);
	bf1.set(1);
	bf1.set(1);
	bf2.set(1);
	EXPECT_EQ(bf1, bf2);
}
TEST(TBitField, reset_0) {
	// Arrange & Act
	TBitField bf1(10);
	TBitField bf2(10);
	// Assert
	bf1.reset(1);
	bf1.reset(1);
	bf1.reset(1);
	EXPECT_EQ(bf1, bf2);
}