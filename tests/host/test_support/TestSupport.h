// tests/host/test_support/TestSupport.h v1
#pragma once

#include <cstring>
#include <iostream>

#define EXPECT_TRUE(expr)                                                          \
  do {                                                                             \
    if (!(expr)) {                                                                 \
      std::cerr << __FILE__ << ":" << __LINE__                                     \
                << ": EXPECT_TRUE(" #expr ") failed" << std::endl;                 \
      return 1;                                                                    \
    }                                                                              \
  } while (0)

#define EXPECT_FALSE(expr)                                                         \
  do {                                                                             \
    if ((expr)) {                                                                  \
      std::cerr << __FILE__ << ":" << __LINE__                                     \
                << ": EXPECT_FALSE(" #expr ") failed" << std::endl;                \
      return 1;                                                                    \
    }                                                                              \
  } while (0)

#define EXPECT_EQ(expected, actual)                                                \
  do {                                                                             \
    const auto expected_value = (expected);                                        \
    const auto actual_value = (actual);                                            \
    if (!(expected_value == actual_value)) {                                       \
      std::cerr << __FILE__ << ":" << __LINE__                                     \
                << ": EXPECT_EQ failed: expected=[" << +expected_value             \
                << "] actual=[" << +actual_value << "]" << std::endl;              \
      return 1;                                                                    \
    }                                                                              \
  } while (0)

#define EXPECT_STREQ(expected, actual)                                             \
  do {                                                                             \
    const char* expected_value = (expected);                                       \
    const char* actual_value = (actual);                                           \
    if (std::strcmp(expected_value, actual_value) != 0) {                          \
      std::cerr << __FILE__ << ":" << __LINE__                                     \
                << ": EXPECT_STREQ failed: expected=[" << expected_value           \
                << "] actual=[" << actual_value << "]" << std::endl;               \
      return 1;                                                                    \
    }                                                                              \
  } while (0)
// tests/host/test_support/TestSupport.h v1