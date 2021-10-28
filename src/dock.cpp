// Created by Jiaheng on 2021/8/9.
// Copyright (c) 2021 Jiaheng Wang All rights reserved.
//

// You may need to build the project (run Qt uic code generator) to get
// "ui_Dock.h" resolved

#include "dock.h"

#include <QMainWindow>
#include <QPushButton>
#include <QtGui>
#include <QtWidgets>
#include <iostream>

#include "ui_Dock.h"

Dock::Dock(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Dock) {
  ui->setupUi(this);

  this->statusBar()->showMessage("default message");

  Menu_File();  // 文件菜单
  InitImage();  // 初始化图像QLabel
}

Dock::~Dock() { delete ui; }

void Dock::Menu_File() {
  QMenu* file = menuBar()->addMenu(tr("文件"));

  // 菜单动作
  QAction* Act_file_new =
      new QAction(QIcon("../Image/file/New.png"), tr("新建"), this);
  Act_file_new->setShortcuts(QKeySequence::New);  // 快捷键 Ctrl+N
  connect(Act_file_new, SIGNAL(triggered()), this, SLOT(File_new()));

  QAction* Act_file_open =
      new QAction(QIcon("../Image/file/Open.png"), tr("打开"), this);
  Act_file_open->setShortcuts(QKeySequence::Open);  // 快捷键 Ctrl+O
  connect(Act_file_open, SIGNAL(triggered()), this, SLOT(File_open()));

  QAction* Act_file_save =
      new QAction(QIcon("../Image/file/Save.png"), tr("保存"), this);
  Act_file_save->setShortcuts(QKeySequence::Save);  // 快捷键 Ctrl+S
  connect(Act_file_save, SIGNAL(triggered()), this, SLOT(File_save()));

  QAction* Act_file_close =
      new QAction(QIcon("../Image/file/Close.png"), tr("关闭"), this);
  Act_file_close->setShortcuts(QKeySequence::Close);  // 快捷键 Ctrl+F4
  connect(Act_file_close, SIGNAL(triggered()), this, SLOT(close()));

  // 将动作添加到菜单上
  file->addAction(Act_file_new);
  file->addSeparator();  //添加分割线
  file->addAction(Act_file_open);
  file->addAction(Act_file_save);
  file->addAction(Act_file_close);

  // tips
  Act_file_new->setStatusTip(tr("new"));
  Act_file_close->setStatusTip(tr("close"));
}

void Dock::InitImage() {
  //
}

void Dock::File_new() {}

void Dock::File_open() {}

void Dock::File_save() {}
