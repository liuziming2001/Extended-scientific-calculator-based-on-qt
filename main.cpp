#include "extendedcalculator.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExtendedCalculator w;
    w.setWindowTitle("拓展型科学计算器");
    w.setFixedHeight(550);  //固定高度
    w.setFixedWidth(500);   //固定宽度
    w.move(QApplication::desktop()->rect().center()-QPoint(250,275));   //窗口弹出位置
    w.show();

    return a.exec();
}
