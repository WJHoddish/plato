// Created by Jiaheng on 2021/7/13.
// Copyright (c) 2021 Jiaheng Wang <wjhgeneral@outlook.com> All rights reserved.
//
// Common entrance for all unit tests.

#include <gtest/gtest.h>

namespace plt {

//

int    argc;
char** argv;

}  // namespace plt

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);

  // init global vars
  plt::argc = argc;
  plt::argv = argv;

  return RUN_ALL_TESTS();
}
