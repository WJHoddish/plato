// Created by Jiaheng on 2021/7/25.
// Copyright (c) 2021 Jiaheng Wang All rights reserved.
//

#ifndef PLATO_TEST_H
#define PLATO_TEST_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Test;
}
QT_END_NAMESPACE

class Test : public QWidget {
  /**
   * Claim signal slot?
   */
  Q_OBJECT

 public:
  explicit Test(QWidget* parent = nullptr);
  ~Test() override;

  /**
   * Simple member function.
   */
  void greet();

 private:
  Ui::Test* ui;

  /**
   * Slot function.
   */
  void slot();
};

#endif  // PLATO_TEST_H
