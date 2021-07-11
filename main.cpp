// Created by Jiaheng on 2021/7/10.
// Copyright (c) 2021 Jiaheng Wang All rights reserved.
//

#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  QPushButton  button("Hello world!", nullptr);
  button.resize(200, 100);
  button.show();
  return QApplication::exec();
}
