// Created by Jiaheng on 2021/7/25.
// Copyright (c) 2021 Jiaheng Wang All rights reserved.
//

// You may need to build the project (run Qt uic code generator) to get
// "ui_Test.h" resolved

#include "test.h"

#include "ui_Test.h"

/**
 * The constructor.
 *
 * @param parent
 */
Test::Test(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Test) {
  ui->setupUi(this);

  // TODO: Resize window.
}

/**
 * The destructor.
 */
Test::~Test() { delete ui; }

// TODO: Member functions.
