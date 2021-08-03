// Created by Jiaheng on 2021/7/25.
// Copyright (c) 2021 Jiaheng Wang All rights reserved.
//

#include <gtest/gtest.h>

#include <QApplication>

#include "args.h"

TEST(plato, my_first_widget) {
  QApplication app(plt::argc, plt::argv);

  // declare layout

  // application execution
  QApplication::exec();
}