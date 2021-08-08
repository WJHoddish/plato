// Created by Jiaheng on 2021/8/8.
// Copyright (c) 2021 Jiaheng Wang All rights reserved.
//

// You may need to build the project (run Qt uic code generator) to get
// "ui_image_processing.h" resolved

#include "image_processing.h"

#include <QMessageBox>
#include <QPushButton>

#include "ui_image_processing.h"

/**
 * UI setup, resize window, declare signal/slot relationship & list all
 * components...
 * @param parent
 */
ImageProcessing::ImageProcessing(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageProcessing) {
  setFixedSize(800, 450);

  ui->setupUi(this);

  connect(this, SIGNAL(iSignal(int)), this, SLOT(iSlot(int)));

  helloWorld();
}

ImageProcessing::~ImageProcessing() { delete ui; }

void ImageProcessing::helloWorld() {
  auto* button = new QPushButton(this);
  button->setText(tr("hello, Qt"));

  button->move(geometry().width() / 2 - button->width() / 2,
               geometry().height() / 2 - button->height() / 2);

  // connect to slot
  connect(button, SIGNAL(clicked()), this, SLOT(slotButton()));
}

/**
 * when touch the button...
 */
void ImageProcessing::slotButton() {
  QMessageBox::information(this, tr("Hello World!"), tr("Hello World!"));

  // interrupt here

  emit iSignal(5);

  disconnect(this, 0, 0, 0);
}

/**
 *
 * @param x
 */
void ImageProcessing::iSlot(int x) { qDebug() << QString::number(x); }
