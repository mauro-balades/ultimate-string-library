#include "../src/usl.h"
#include "gtest/gtest.h"
#include <stdio.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(create, ok) {
  (void)usl_from("Hello, World!");
}

TEST(length, ok) {
  usl usl = usl_from("Hello, World!");
  ASSERT_EQ(13, usl_len(usl));
  usl_free(usl);
}

TEST(char_at, ok) {
  usl usl = usl_from("Hello, World!");
  ASSERT_EQ('H', usl_char_at(usl, 0));
  ASSERT_EQ('e', usl_char_at(usl, 1));
  ASSERT_EQ('l', usl_char_at(usl, 2));
  ASSERT_EQ('l', usl_char_at(usl, 3));
  ASSERT_EQ('o', usl_char_at(usl, 4));
  ASSERT_EQ(',', usl_char_at(usl, 5));
  ASSERT_EQ(' ', usl_char_at(usl, 6));
  ASSERT_EQ('W', usl_char_at(usl, 7));
  ASSERT_EQ('o', usl_char_at(usl, 8));
  ASSERT_EQ('r', usl_char_at(usl, 9));
  ASSERT_EQ('l', usl_char_at(usl, 10));
  ASSERT_EQ('d', usl_char_at(usl, 11));
  ASSERT_EQ('!', usl_char_at(usl, 12));
  usl_free(usl);
}