// Created by Jiaheng on 2021/7/10.
// Copyright (c) 2021 Jiaheng Wang All rights reserved.
//

#include <QApplication>
#include <QPushButton>

#include "src/dock.h"
#include "src/image_processing.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  //  ImageProcessing w;
  Dock w;

  w.show();

  return QApplication::exec();
}
