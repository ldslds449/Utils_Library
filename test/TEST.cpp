#include "KMP.h"
#include "KMP.cpp"

#include <cstring>
#include <iostream>

#include "gtest/gtest.h"

namespace{

TEST(KMP_TEST, EXIST){
  std::string data_1 = "fghxsg54j6xs4g6z4h6g4j6zx4g5n43hg4km3j4c86j4zgd654j4zgd653j5sy4hm63541x35m";
  lds::KMP<char> kmp_1(data_1.c_str(), data_1.size());
  
  std::string target_1_1 = "h6g4j6zx4g";
  EXPECT_EQ(17, kmp_1.find(target_1_1.c_str(), target_1_1.size()));

  std::string target_1_2 = "j4zgd653";
  EXPECT_EQ(50, kmp_1.find(target_1_2.c_str(), target_1_2.size()));

  std::string data_2 = "abababaab";
  lds::KMP<char> kmp_2(data_2.c_str(), data_2.size());

  std::string target_2_1 = "ababaa";
  EXPECT_EQ(2, kmp_2.find(target_2_1.c_str(), target_2_1.size()));
}

TEST(KMP_TEST, NON_EXIST){
  std::string data_1 = "j6xs4g6z4h6g4j6zx4g5n43hg4kmx4g5n433j4c86j4zgdx4g5n43654j5sy4hm6x4g5n433541x35m";
  lds::KMP<char> kmp_1(data_1.c_str(), data_1.size());
  
  std::string target_1_1 = "135792468101113151719";
  EXPECT_EQ(-1, kmp_1.find(target_1_1.c_str(), target_1_1.size()));

  std::string target_1_2 = "x4g5n41";
  EXPECT_EQ(-1, kmp_1.find(target_1_2.c_str(), target_1_2.size()));

  std::string data_2 = "abababbaa";
  lds::KMP<char> kmp_2(data_2.c_str(), data_2.size());

  std::string target_2_1 = "ababaa";
  EXPECT_EQ(-1, kmp_2.find(target_2_1.c_str(), target_2_1.size()));
}

} // end namespace

int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}