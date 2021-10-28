// Created by Jiaheng on 2021/8/8.
// Copyright (c) 2021 Jiaheng Wang All rights reserved.
//

// You may need to build the project (run Qt uic code generator) to get
// "ui_image_processing.h" resolved

#include "image_processing.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QtGui>
#include <QtWidgets>

#include "ui_image_processing.h"

/**
 * UI setup, resize window, declare signal/slot relationship & list all
 * components...
 * @param parent
 */
ImageProcessing::ImageProcessing(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageProcessing) {
  setWindowTitle("P2");
  setFixedSize(800, 450);

  ui->setupUi(this);

  connect(this, SIGNAL(iSignal(int)), this, SLOT(iSlot(int)));

  helloWorld();

  //

  QMenu* menu1 = menuBar()->addMenu(tr("菜单栏1"));

  auto* act1 = new QAction(tr("子菜单1"), this);
  auto* act2 = new QAction(tr("子菜单2"), this);

  connect(act2, SIGNAL(triggered()), this, SLOT(slotButton()));

  act1->setMenu(act2);
  menu1->addAction(act1);
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

  disconnect(this, nullptr, nullptr, nullptr);
}

/**
 *
 * @param x
 */
void ImageProcessing::iSlot(int x) { qDebug() << QString::number(x); }
