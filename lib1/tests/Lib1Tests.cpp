#include "lib1/Lib1.h"
#include <gtest/gtest.h>

TEST(Lib1, ctor) {
  ASSERT_NO_THROW(lib1::Lib1 t);
}

TEST(Lib1, dummy) {
  lib1::Lib1 t;
  EXPECT_EQ(t.dummy(), 0);
}

TEST(Lib1, dummy55) {
  lib1::Lib1 t;
  EXPECT_EQ(t.dummy(55), 55);
}
