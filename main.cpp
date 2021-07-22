// Created by Jiaheng on 2021/7/10.
// Copyright (c) 2021 Jiaheng Wang All rights reserved.
//

#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  QPushButton  button(std::to_string(sizeof(void*)).c_str(), nullptr);
  button.resize(900, 600);
  button.show();
  return QApplication::exec();
}
