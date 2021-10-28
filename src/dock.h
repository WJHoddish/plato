// Created by Jiaheng on 2021/8/9.
// Copyright (c) 2021 Jiaheng Wang All rights reserved.
//

#ifndef PLATO_DOCK_H
#define PLATO_DOCK_H

#include <QLabel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dock;
}
QT_END_NAMESPACE

class Dock : public QMainWindow {
  Q_OBJECT

 public:
  explicit Dock(QWidget* parent = nullptr);
  ~Dock() override;

 private:
  Ui::Dock* ui;

 private:
  void Menu_File();  // 文件菜单
  void InitImage();  // 初始化图像

  QDockWidget* dock_Image;   // 图像窗口
  QString      currentPath;  // 当前图像的路径
  QLabel*      imgLabel;     // 图像显示框

 private slots:
  void File_new();   // 新建
  void File_open();  // 打开
  void File_save();  // 保存
};

#endif  // PLATO_DOCK_H
