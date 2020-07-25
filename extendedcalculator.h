#ifndef EXTENDEDCALCULATOR_H
#define EXTENDEDCALCULATOR_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QPalette>
#include <QDebug>
#include <QMessageBox>
#include <QStack>
#include <QVector>

namespace Ui {
class ExtendedCalculator;
}

class ExtendedCalculator : public QWidget
{
    Q_OBJECT

private:
    //标准页面
    QLineEdit *lineInput;    //标准页面的输入框
    QLineEdit *lineResult;    //标准页面的显示框
    QString input;  //标准页面的输入框的内容
    QString input_com; //设置input用于运算的版本

    //科学页面
    QLineEdit *linesInput;    //科学页面的输入框
    QLineEdit *linesResult;    //科学页面的显示框
    QString inputs;  //科学页面的输入框的内容
    QString inputs_com; //设置inputs用于运算的版本

    //排列组合页面
    QLineEdit* lineEdit;//显示框
    QString inputp; //输入框

    //复数页面
    QLineEdit *lineReal1,*lineReal2,*lineImag1,*lineImag2,*lineComplexResult;
    QString inputc1,inputc2,inputc3,inputc4,complexResult;
    float real1,real2,imag1,imag2,realres,imagres;
    char complexOper;

private slots:  //定义槽函数
    //标准页面
    void buttonClicked();   //标准页面的槽函数

    //科学页面
    void buttonsClicked();   //科学页面的槽函数

    //排列组合页面
    void Mydisplay_C();
    void Mydisplay_A();
    void OnButtonClicked();
    void button_0Clicked();
    void button_1Clicked();
    void button_2Clicked();
    void button_3Clicked();
    void button_4Clicked();
    void button_5Clicked();
    void button_6Clicked();
    void button_7Clicked();
    void button_8Clicked();
    void button_9Clicked();
    void button_deletClicked();

    //复数页面
    void on_btnc0_clicked();
    void on_btnc1_clicked();
    void on_btnc2_clicked();
    void on_btnc3_clicked();
    void on_btnc4_clicked();
    void on_btnc5_clicked();
    void on_btnc6_clicked();
    void on_btnc7_clicked();
    void on_btnc8_clicked();
    void on_btnc9_clicked();
    void on_btncClear_clicked();
    void on_btncPoint_clicked();
    void on_btncNeg_clicked();
    void on_btncEqual_clicked();
    void on_btncBack_clicked();



public:
    explicit ExtendedCalculator(QWidget *parent = 0);
    //标准页面，科学页面
    void InfixToSuffix(const char *S,char OPS[],int &len);
    void CalculateSuffix(char SUF[], int len, double &result,bool &flag);
    bool RefuseCompositeFunction(QString);
    //排列组合页面
    long long Combinat(int m, int n);
    long long Arrange(int m, int n);
    QVector<int> prim_produce();
    int cal(int x,int p);
    int Pow(long long n,int k);
    void setpText(QString str);
    //复数页面
    void setcText(QString); //显示输入数字
    bool checkInput(float,float,float,float,QString,QString,QString,QString);   //检查输入框内是否是正负浮点数
    ~ExtendedCalculator();

private:
    Ui::ExtendedCalculator *ui;
};

#endif // EXTENDEDCALCULATOR_H
