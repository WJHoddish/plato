// Created by Jiaheng on 2021/8/8.
// Copyright (c) 2021 Jiaheng Wang All rights reserved.
//

#ifndef PLATO_IMAGE_PROCESSING_H
#define PLATO_IMAGE_PROCESSING_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class ImageProcessing;
}
QT_END_NAMESPACE

class ImageProcessing : public QMainWindow {
  Q_OBJECT

 public:
  explicit ImageProcessing(QWidget* parent = nullptr);
  ~ImageProcessing() override;

  /**
   * TODO: Add member functions.
   */

  void helloWorld();

 private:
  Ui::ImageProcessing* ui;

 signals:

  /**
   * TODO: Add signal functions.
   */

  void iSignal(int x);

 private slots:

  /**
   * TODO: Add slot functions.
   */

  void slotButton();

  void iSlot(int x);
};

#endif  // PLATO_IMAGE_PROCESSING_H
