#include "extendedcalculator.h"
#include "ui_extendedcalculator.h"
#include "QDebug"
#include "QStringList"
#include <QtWidgets>
#include <QString>
#include <QVector>
#include <stdlib.h>
#include <QTextCursor>
#include <QMessageBox>

const int MOD = 100007;
const int maxn = 1000001;
bool a[maxn]={false};

//构造函数
ExtendedCalculator::ExtendedCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExtendedCalculator)
{
    ui->setupUi(this);
    //ui->setFixedSize(this->width(), this->height());   //禁止改变窗口大小
    ui->tabWidget->setTabPosition(QTabWidget::North);   //设置选项卡位于上方（默认）
    ui->tabWidget->setMovable(false);   //禁止选型卡移动
    //setWindowOpacity(0.9);  //设置窗口透明度
    this->setWindowIcon(QIcon(":/img/icon.png"));   //给程序添加图标



    /* 标准选项卡 */
    connect(ui->btn0,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号0与槽函数
    connect(ui->btn1,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号1与槽函数
    connect(ui->btn2,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号2与槽函数
    connect(ui->btn3,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号3与槽函数
    connect(ui->btn4,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号4与槽函数
    connect(ui->btn5,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号5与槽函数
    connect(ui->btn6,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号6与槽函数
    connect(ui->btn7,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号7与槽函数
    connect(ui->btn8,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号8与槽函数
    connect(ui->btn9,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号9与槽函数
    connect(ui->btnPoint,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号.与槽函数
    connect(ui->btnAdd,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号+与槽函数
    connect(ui->btnSub,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号-与槽函数
    connect(ui->btnMulti,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号*与槽函数
    connect(ui->btnDiv,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号/与槽函数
    connect(ui->btnSqrt,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号√与槽函数
    connect(ui->btnPower,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号^与槽函数
    connect(ui->btnLeftBracket,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号(与槽函数
    connect(ui->btnRightBracket,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号)与槽函数
    connect(ui->btnClear,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号C与槽函数
    connect(ui->btnBack,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号<-与槽函数
    connect(ui->btnEqual,SIGNAL(clicked()),this,SLOT(buttonClicked()));//信号=与槽函数

    //QPalette palette;
    //palette.setColor(QPalette::Text,Qt::red);  //设置字体颜色
    ui->lineInput->setFont(QFont("微软雅黑",12,QFont::Normal));//设置字体大小
    //ui->lineInput->setPalette(palette);
    ui->lineResult->setFont(QFont("微软雅黑",12,QFont::Normal));//设置字体大小
    //ui->lineResult->setPalette(palette);
    //ui->lineInput-&gt;
    ui->lineInput->setReadOnly(true);
    ui->lineResult->setReadOnly(true);



    /* 科学选项卡 */
    connect(ui->btns0,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号0与槽函数
    connect(ui->btns1,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号1与槽函数
    connect(ui->btns2,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号2与槽函数
    connect(ui->btns3,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号3与槽函数
    connect(ui->btns4,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号4与槽函数
    connect(ui->btns5,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号5与槽函数
    connect(ui->btns6,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号6与槽函数
    connect(ui->btns7,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号7与槽函数
    connect(ui->btns8,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号8与槽函数
    connect(ui->btns9,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号9与槽函数
    connect(ui->btnsPi,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号π与槽函数
    connect(ui->btnsEuler,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号e与槽函数
    connect(ui->btnsPoint,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号.与槽函数
    connect(ui->btnsAdd,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号+与槽函数
    connect(ui->btnsSub,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号-与槽函数
    connect(ui->btnsMulti,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号*与槽函数
    connect(ui->btnsDiv,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号/与槽函数
    connect(ui->btnsLeftBracket,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号(与槽函数
    connect(ui->btnsRightBracket,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号)与槽函数
    connect(ui->btnsPower,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号^与槽函数
    connect(ui->btnsSqrt,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号√与槽函数
    connect(ui->btnsExp,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号exp与槽函数
    connect(ui->btnsLog,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号log与槽函数
    connect(ui->btnsLn,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号ln与槽函数
    connect(ui->btnsMod,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号mod与槽函数
    connect(ui->btnsReci,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号1/x与槽函数
    connect(ui->btnsAbs,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号|x|与槽函数
    connect(ui->btnsSin,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号sin与槽函数
    connect(ui->btnsCos,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号cos与槽函数
    connect(ui->btnsClear,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号C与槽函数
    connect(ui->btnsBack,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号<-与槽函数
    connect(ui->btnsEqual,SIGNAL(clicked()),this,SLOT(buttonsClicked()));//信号=与槽函数

    //QPalette palette;
    //palette.setColor(QPalette::Text,Qt::red);  //设置字体颜色
    ui->linesInput->setFont(QFont("微软雅黑",12,QFont::Normal));//设置字体大小
    //ui->linesInput->setPalette(palette);
    ui->linesResult->setFont(QFont("微软雅黑",12,QFont::Normal));//设置字体大小
    //ui->linesResult->setPalette(palette);
    //ui->lineInput-&gt;
    ui->linesInput->setReadOnly(true);
    ui->linesResult->setReadOnly(true);



    /*排列组合选项卡*/
    ui->lineEdit_C1->setFocus();
    ui->pushButton_0->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_1->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_3->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_4->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_5->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_6->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_7->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_8->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_9->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_delet->setFocusPolicy(Qt::NoFocus);
    //关于组合数的connect函数
    connect(this->ui->dengyu_C,SIGNAL(clicked()),this,SLOT(Mydisplay_C()));
    connect(this->ui->Cancle_C,SIGNAL(clicked()),this->ui->lineEdit_C1,SLOT(clear()));
    connect(this->ui->Cancle_C,SIGNAL(clicked()),this->ui->lineEdit_C2,SLOT(clear()));
    connect(this->ui->Cancle_C,SIGNAL(clicked()),this->ui->textBrowser_C,SLOT(clear()));//有问题
    //关于排列数的connect函数
    connect(this->ui->dengyu_A,SIGNAL(clicked()),this,SLOT(Mydisplay_A()));
    connect(this->ui->Cancle_A,SIGNAL(clicked()),this->ui->lineEdit_A1,SLOT(clear()));
    connect(this->ui->Cancle_A,SIGNAL(clicked()),this->ui->lineEdit_A2,SLOT(clear()));
    connect(this->ui->Cancle_A,SIGNAL(clicked()),this->ui->textBrowser_A,SLOT(clear()));//有问题
    //关于阶乘的connect函数
    connect(this->ui->dengyu_fact,SIGNAL(clicked()),this,SLOT(OnButtonClicked()));
    connect(this->ui->Cancle_fact,SIGNAL(clicked()),this->ui->lineEdit_fact,SLOT(clear()));
    connect(this->ui->Cancle_fact,SIGNAL(clicked()),this->ui->textBrowser_fact,SLOT(clear()));
    //关于按键的connect函数
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(button_0Clicked()));//信号0与槽函数
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(button_1Clicked()));//信号1与槽函数
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(button_2Clicked()));//信号2与槽函数
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(button_3Clicked()));//信号3与槽函数
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(button_4Clicked()));//信号4与槽函数
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(button_5Clicked()));//信号5与槽函数
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(button_6Clicked()));//信号6与槽函数
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(button_7Clicked()));//信号7与槽函数
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(button_8Clicked()));//信号8与槽函数
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(button_9Clicked()));//信号9与槽函数
    connect(ui->pushButton_delet,SIGNAL(clicked(bool)),this,SLOT(button_deletClicked()));//信号退格键与槽函数

    ui->lineEdit_A1->setFont(QFont("微软雅黑",12,QFont::Normal));//设置字体大小
    ui->lineEdit_A2->setFont(QFont("微软雅黑",12,QFont::Normal));//设置字体大小
    ui->lineEdit_C1->setFont(QFont("微软雅黑",12,QFont::Normal));//设置字体大小
    ui->lineEdit_C2->setFont(QFont("微软雅黑",12,QFont::Normal));//设置字体大小
    ui->lineEdit_fact->setFont(QFont("微软雅黑",12,QFont::Normal));//设置字体大小
    ui->textBrowser_A->setFont(QFont("微软雅黑",12,QFont::Normal));//设置字体大小
    ui->textBrowser_C->setFont(QFont("微软雅黑",12,QFont::Normal));//设置字体大小
    ui->textBrowser_fact->setFont(QFont("微软雅黑",12,QFont::Normal));//设置字体大小



    /* 复数选项卡 */
    ui->lineReal1->setFocus();  //设置默认焦点
    ui->btnc0->setFocusPolicy(Qt::NoFocus); //按钮失焦点，保证光标都在输入框内
    ui->btnc1->setFocusPolicy(Qt::NoFocus);
    ui->btnc2->setFocusPolicy(Qt::NoFocus);
    ui->btnc3->setFocusPolicy(Qt::NoFocus);
    ui->btnc4->setFocusPolicy(Qt::NoFocus);
    ui->btnc5->setFocusPolicy(Qt::NoFocus);
    ui->btnc6->setFocusPolicy(Qt::NoFocus);
    ui->btnc7->setFocusPolicy(Qt::NoFocus);
    ui->btnc8->setFocusPolicy(Qt::NoFocus);
    ui->btnc9->setFocusPolicy(Qt::NoFocus);
    ui->btncClear->setFocusPolicy(Qt::NoFocus);
    ui->btncBack->setFocusPolicy(Qt::NoFocus);
    ui->btncPoint->setFocusPolicy(Qt::NoFocus);
    ui->btncNeg->setFocusPolicy(Qt::NoFocus);

    inputc1="";
    inputc2="";
    inputc3="";
    inputc4="";
    complexResult="";
    ui->lineComplexResult->setReadOnly(true);

    ui->lineReal1->setFont(QFont("微软雅黑",10,QFont::Normal));//设置字体大小
    ui->lineReal2->setFont(QFont("微软雅黑",10,QFont::Normal));//设置字体大小
    ui->lineImag1->setFont(QFont("微软雅黑",10,QFont::Normal));//设置字体大小
    ui->lineImag2->setFont(QFont("微软雅黑",10,QFont::Normal));//设置字体大小
    ui->lineComplexResult->setFont(QFont("微软雅黑",12,QFont::Normal));//设置字体大小
}

ExtendedCalculator::~ExtendedCalculator()
{
    delete ui;
}





/* 标准选项卡的函数 */
bool pointflag = 1; //全局变量，控制每个数字只有一个小数点
void ExtendedCalculator::buttonClicked()    //按钮触动的槽函数
{
    lineInput = ui->lineInput;
    lineResult = ui->lineResult;
    input = lineInput->text();  //获取输入框的内容，input用于修改显示框内容
    QPushButton *pb = qobject_cast<QPushButton *>(sender());    //把信号转化为按键的类型
    QString text = pb->text();  //获取输入框内容，text用于读取一次输入内容

    if(text==QString("C")) //清除（清空输入框所有内容）
    {
        input = "";
        input_com = "";
        lineInput->clear();
        lineResult->clear();
        pointflag = 1;
    }
    else if(text == QString("<-"))  //退格（删除刚刚输入的字符）
    {
        if(RefuseCompositeFunction(input))
        {
            if((input.right(1))[0]==QChar('.'))
            {
                pointflag = 1;
            }
            input.chop(1);
            input_com.chop(1);
            lineInput->setText(input);
        }
    }
    else if(text == QString("+"))
    {
        if(input != ""&&((input.right(1))[0].isDigit()||(input.right(1))[0]==QChar(')')))  //如果输入框不为空并且最后一个字符是数字或者右括号则添加+
        {
            lineInput->setText(input+"+");
            input_com += "+";
            pointflag = 1;
        }
    }
    else if(text == QString("-"))
    {
        if(input != ""&&((input.right(1))[0].isDigit()||(input.right(1))[0]==QChar('(')||(input.right(1))[0]==QChar(')')))  //负号前边可以是数字或者左右括号
        {
            lineInput->setText(input+"-");
            input_com += "-";
            pointflag = 1;
        }
    }
    else if(text == QString("*"))
    {
        if(input != ""&&((input.right(1))[0].isDigit()||(input.right(1))[0]==QChar(')')))
        {
            lineInput->setText(input+"*");
            input_com += "*";
            pointflag = 1;
        }
    }
    else if(text == QString("/"))
    {
        if(input != ""&&((input.right(1))[0].isDigit()||(input.right(1))[0]==QChar(')')))
        {
            lineInput->setText(input+"/");
            input_com += "/";
            pointflag = 1;
        }
    }
    else if(text == QString("^"))
    {
        if(input != ""&&((input.right(1))[0].isDigit()||(input.right(1))[0]==QChar(')')))
        {
            lineInput->setText(input+"^");
            input_com += "^";
            pointflag = 1;
        }
    }
    else if(text == QString("."))
    {
        if(input != ""&&(input.right(1))[0].isDigit()&&pointflag)  //输入框不为空且前一个字符是数字,同时要求这个数只有这一个小数点
        {
            lineInput->setText(input+".");
            input_com += ".";
            pointflag = 0;
        }
    }
    else if(text == QString("("))
    {
        if(input == ""||(!((input.right(1))[0].isDigit())&&(input.right(1))[0]!=QChar('.')&&(input.right(1))[0]!=QChar(')')))  //左括号出现在空输入框或者前边一个字符不为数字或小数点或右括号
        {
            lineInput->setText(input+"(");
            input_com += "(";
            pointflag = 1;
        }
    }
    else if(text == QString(")"))
    {
        if(input != ""&&((input.right(1))[0].isDigit()||(input.right(1))[0]==QChar(')')))  //右括号出现在非空输入框内,前边一个字符为数字或右括号
        {
            lineInput->setText(input+")");
            input_com += ")";
            pointflag = 1;
        }
    }
    else if(text == QString("√"))
    {
         if(RefuseCompositeFunction(input)&&(input.right(1))[0].isDigit())  //前一个字符只能是数字
         {
            QString::reverse_iterator p = input.rbegin();  //设置反向迭代器
            int count = 0;  //记录遍历的数字个数
            double temp = 0.0;    //用于获取所得数
            while((*p!=QChar('+'))&&(*p!=QChar('-'))&&(*p!=QChar('*'))&&(*p!=QChar('/'))&&(*p!=QChar('^'))&&(*p!=QChar('('))&&p!=input.rend())
            {
                p++;
                count++;
            }//向前遍历直至遇到其他符号或者到了最前面
            if(p==input.rend())
            {
                temp = input.toDouble();
                input_com =QString::number(sqrt(temp),10,6);   //对所得的数开平方并且追加到之前表达式中
                lineInput->setText(QString("√%1").arg(temp));  //按照书写方式显示
            }
            else if((*p==QChar('+'))||(*p==QChar('-'))||(*p==QChar('*'))||(*p==QChar('/'))||(*p==QChar('^'))||(*p==QChar('(')))
            {
                temp = input.right(count).toDouble();    //获取所得的数
                input_com = input_com.left(input_com.length()-count).append(QString::number(sqrt(temp),10,6));   //对所得的数开平方并且追加到之前表达式中
                lineInput->setText(QString("%1√%2").arg(input.left(input.length()-count)).arg(temp));  //按照书写方式显示
            }
         }
    }
    else if(text == QString("="))
    {
        if((input.right(1))[0]!=QChar(')')&&(!((input.right(1))[0].isDigit())))  //输入框的表达式应该以数字或者右括号结尾
        {
            QMessageBox::warning(0 , "注意" , "表达式不完整，请重新输入。",
                                 QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
            lineResult->clear();
        }
        else
        {
            int lcount = 0, rcount = 0;
            QString::iterator p = input.begin();
            while (p != input.end())
            {
                if(*p == QChar('('))
                {
                    lcount++;
                }
                else if(*p == QChar(')'))
                {
                    rcount++;
                }
                p++;
            }
            if(lcount != rcount)
            {
                QMessageBox::warning(0 , "注意" , "左右括号不匹配，请重新输入。",
                                     QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
                lineResult->clear();
            }
            else
            {
                if(input!="")
                {
                    std::string str=input_com.toStdString();//QString转化为String，注意将运算版本的input带入
                    const char *S=str.c_str();//整个输入框的字符串
                    char OPS[50];//中缀表达式
                    int len;//去掉括号之后中缀表达式的长度
                    double result;//计算结果
                    QString output;
                    bool zeroflag = true;  //判断除数是否为0的标志
                    InfixToSuffix(S,OPS,len);  //调用中缀转后缀函数
                    CalculateSuffix(OPS,len,result,zeroflag); //调用后缀表达式计算函数
                    if(zeroflag == false)
                    {
                        lineInput->clear();
                        lineResult->clear();
                        QMessageBox::warning(0 , "注意" , "除数不能为0，请重新输入。",
                                             QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
                        lineResult->clear();
                    }
                    else
                    {
                        output = QString::number(result,10,6);//将计算结果转换为字符串，10进制，6位小数
                        lineResult->setText(output);
                    }
                }
            }
        }
    }
    else   //0~9
    {
        if(RefuseCompositeFunction(input)&&(input.right(1))[0]!=QChar(')'))
        {
            input_com += text;
            lineInput->setText(input+=text);
        }
    }
}





/* 科学选项卡的函数 */
bool pointsflag = 1; //全局变量，控制每个数字只有一个小数点
void ExtendedCalculator::buttonsClicked()    //按钮触动的槽函数
{
    linesInput = ui->linesInput;
    linesResult = ui->linesResult;
    inputs = linesInput->text();  //获取输入框的内容，input用于修改显示框内容
    QPushButton *pb = qobject_cast<QPushButton *>(sender());    //把信号转化为按键的类型
    QString text = pb->text();  //获取输入框内容，text用于读取一次输入内容

    if(text==QString("C")) //清除（清空输入框所有内容）
    {
        inputs = "";
        inputs_com = "";
        linesInput->clear();
        linesResult->clear();
        pointsflag = 1;
    }
    else if(text == QString("<-"))  //退格（删除刚刚输入的字符）
    {
       if(RefuseCompositeFunction(inputs))
       {
            if((inputs.right(1))[0]==QChar('d'))  //求余退格
            {
                inputs.chop(3);
                inputs_com.chop(1);
                linesInput->setText(inputs);
            }
            else if((inputs.right(1) == QString("π"))||(inputs.right(1) == QString("e"))) //π,e退格
            {
                inputs.chop(1);
                inputs_com.chop(8);
                linesInput->setText(inputs);
            }
            else    //其他退格
            {
                if((inputs.right(1))[0]==QChar('.'))    //小数点退格
                {
                    pointsflag = 1;
                }
                inputs.chop(1);
                inputs_com.chop(1);
                linesInput->setText(inputs);
            }
        }
    }
    else if(text == QString("π"))
    {
        if(!((inputs.right(1))[0].isDigit())&&((inputs.right(1))[0]!=QChar(')'))
                &&((inputs.right(1))[0]!=QChar('e'))&&((inputs.right(1))[0]!=QString("π"))) //注意，π不是一个字符
        {
            inputs += "π";
            inputs_com += "3.141593";
            linesInput->setText(inputs);
            pointsflag = 0;
        }

    }
    else if(text == QString("e"))
    {
        if(!((inputs.right(1))[0].isDigit())&&((inputs.right(1))[0]!=QChar(')'))
                 &&((inputs.right(1))!=QString("π"))&&((inputs.right(1))[0]!=QChar('e')))
        {
            inputs += "e";
            inputs_com += "2.718282";
            linesInput->setText(inputs);
            pointsflag = 0;
        }
    }
    else if(text == QString("+"))
    {
        if(inputs != ""&&((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar(')')||(inputs.right(1))[0]==QChar('|')
                          ||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))  //如果输入框不为空并且最后一个字符是数字或者右括号则添加+
        {
            linesInput->setText(inputs+"+");
            inputs_com += "+";
            pointsflag = 1;
        }
    }
    else if(text == QString("-"))
    {
        if(inputs != ""&&((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar('(')||(inputs.right(1))[0]==QChar(')')||(inputs.right(1))[0]==QChar('|')
                          ||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))  //负号前边可以是数字或者左右括号
        {
            linesInput->setText(inputs+"-");
            inputs_com += "-";
            pointsflag = 1;
        }
    }
    else if(text == QString("*"))
    {
        if(inputs != ""&&((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar(')')||(inputs.right(1))[0]==QChar('|')
                          ||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))
        {
            linesInput->setText(inputs+"*");
            inputs_com += "*";
            pointsflag = 1;
        }
    }
    else if(text == QString("/"))
    {
        if(inputs != ""&&((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar(')')||(inputs.right(1))[0]==QChar('|')
                          ||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))
        {
            linesInput->setText(inputs+"/");
            inputs_com += "/";
            pointsflag = 1;
        }
    }
    else if(text == QString("^"))
    {
        if(inputs != ""&&((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar(')')||(inputs.right(1))[0]==QChar('|')
                          ||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))
        {
            linesInput->setText(inputs+"^");
            inputs_com += "^";
            pointsflag = 1;
        }
    }
    else if(text == QString("mod"))
    {
        if(inputs != ""&&((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar(')')||(inputs.right(1))[0]==QChar('|')
                          ||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))
        {
            linesInput->setText(inputs+"mod");
            inputs_com += "%";
            pointsflag = 1;
        }
    }
    else if(text == QString("."))
    {
        if(inputs != ""&&(inputs.right(1))[0].isDigit()&&pointsflag)  //输入框不为空且前一个字符是数字,同时要求这个数只有这一个小数点
        {
            linesInput->setText(inputs+".");
            inputs_com += ".";
            pointsflag = 0;
        }
    }
    else if(text == QString("("))
    {
        if(inputs == ""||(!((inputs.right(1))[0].isDigit())&&(inputs.right(1))[0]!=QChar('.')&&(inputs.right(1))[0]!=QChar(')')
                          &&(inputs.right(1))[0]!=QChar('e')&&(inputs.right(1))!=QString("π")))  //左括号出现在空输入框或者前边一个字符不为数字或小数点或右括号
        {
            linesInput->setText(inputs+"(");
            inputs_com += "(";
            pointsflag = 1;
        }
    }
    else if(text == QString(")"))
    {
        if(inputs != ""&&((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar(')')
                          ||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))  //右括号出现在非空输入框内,前边一个字符为数字或右括号
        {
            linesInput->setText(inputs+")");
            inputs_com += ")";
            pointsflag = 1;
        }
    }
    else if(text == QString("√"))
    {
         if(RefuseCompositeFunction(inputs)&&
                 ((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))  //前一个字符只能是数字
         {
            QString::reverse_iterator p = inputs.rbegin();  //设置反向迭代器
            int count = 0;  //记录遍历的数字个数
            double temp = 0.0;    //用于获取所得数
            while((*p!=QChar('+'))&&(*p!=QChar('-'))&&(*p!=QChar('*'))&&(*p!=QChar('/'))
                  &&(*p!=QChar('^'))&&(*p!=QChar('d'))&&(*p!=QChar('('))&&p!=inputs.rend())
            {
                p++;
                count++;
            }//向前遍历直至遇到其他符号或者到了最前面
            if(p==inputs.rend())
            {
                if(inputs == QString("π"))
                {
                    inputs_com = QString::number(sqrt(3.141593),10,6);
                    linesInput->setText(QString("√π"));
                }
                else if(inputs == QString("e"))
                {
                    inputs_com = QString::number(sqrt(2.718282),10,6);
                    linesInput->setText(QString("√e"));
                }
                else
                {
                    temp = inputs.toDouble();
                    inputs_com =QString::number(sqrt(temp),10,6);   //对所得的数开平方并且追加到之前表达式中
                    linesInput->setText(QString("√%1").arg(temp));  //按照书写方式显示
                }
            }
            else if((*p==QChar('+'))||(*p==QChar('-'))||(*p==QChar('*'))||(*p==QChar('/'))
                    ||(*p==QChar('^'))||(*p==QChar('d'))||(*p==QChar('(')))
            {
                if(inputs.right(1) == QString("π"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(sqrt(3.141593),10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("√π"));
                }
                else if(inputs.right(1) == QString("e"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(sqrt(2.718282),10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("√e"));
                }
                else
                {
                    temp = inputs.right(count).toDouble();    //获取所得的数
                    inputs_com = inputs_com.left(inputs_com.length()-count).append(QString::number(sqrt(temp),10,6));   //对所得的数开平方并且追加到之前表达式中
                    linesInput->setText(QString("%1√%2").arg(inputs.left(inputs.length()-count)).arg(temp));  //按照书写方式显示
                }
            }
         }
    }
    else if(text == QString("1/x"))
    {
         if(RefuseCompositeFunction(inputs)&&
                 ((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))  //前一个字符只能是数字
         {
            QString::reverse_iterator p = inputs.rbegin();  //设置反向迭代器
            int count = 0;  //记录遍历的数字个数
            double temp = 0.0;    //用于获取所得数
            while((*p!=QChar('+'))&&(*p!=QChar('-'))&&(*p!=QChar('*'))&&(*p!=QChar('/'))
                  &&(*p!=QChar('^'))&&(*p!=QChar('d'))&&(*p!=QChar('('))&&p!=inputs.rend())
            {
                p++;
                count++;
            }//向前遍历直至遇到其他符号或者到了最前面
            if(p==inputs.rend())
            {
                if(inputs == QString("π"))
                {
                    inputs_com = QString::number(1/3.141593,10,6);
                    linesInput->setText(QString("1/π"));
                }
                else if(inputs == QString("e"))
                {
                    inputs_com = QString::number(1/2.718282,10,6);
                    linesInput->setText(QString("1/e"));
                }
                else
                {
                    temp = inputs.toDouble();
                    if(temp == 0.0)
                    {
                        QMessageBox::warning(0 , "注意" , "除数不能为0，请重新输入。",
                                             QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
                        linesInput->clear();
                        linesResult->clear();
                    }
                    else
                    {
                        inputs_com =QString::number(1/temp,10,6);   //对所得的数取倒数并且追加到之前表达式中
                        linesInput->setText(QString("1/%1").arg(temp));  //按照书写方式显示
                    }

                }
            }
            else if((*p==QChar('+'))||(*p==QChar('-'))||(*p==QChar('*'))||(*p==QChar('/'))
                    ||(*p==QChar('^'))||(*p==QChar('d'))||(*p==QChar('(')))
            {
                if(inputs.right(1) == QString("π"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(1/3.141593,10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("1/π"));
                }
                else if(inputs.right(1) == QString("e"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(1/2.718282,10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("1/e"));
                }
                else
                {
                    temp = inputs.right(count).toDouble();    //获取所得的数
                    if(temp == 0.0)
                    {
                        QMessageBox::warning(0 , "注意" , "除数不能为0，请重新输入。",
                                             QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
                        linesInput->clear();
                        linesResult->clear();
                    }
                    else
                    {
                        inputs_com = inputs_com.left(inputs_com.length()-count).append(QString::number(1/temp,10,6));   //对所得的数取倒数并且追加到之前表达式中
                        inputs = inputs.left(inputs.length()-count)+QString("1/%1").arg(temp);
                        linesInput->setText(inputs);  //按照书写方式显示
                    }
                }
            }
         }
    }
    else if(text == QString("|x|"))
    {
         if(RefuseCompositeFunction(inputs)&&
                 ((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))  //前一个字符只能是数字
         {
            QString::reverse_iterator p = inputs.rbegin();  //设置反向迭代器
            int count = 0;  //记录遍历的数字个数
            double temp = 0.0;    //用于获取所得数
            while((*p!=QChar('+'))&&(*p!=QChar('-'))&&(*p!=QChar('*'))&&(*p!=QChar('/'))
                  &&(*p!=QChar('^'))&&(*p!=QChar('d'))&&(*p!=QChar('('))&&p!=inputs.rend())
            {
                p++;
                count++;
            }//向前遍历直至遇到其他符号或者到了最前面
            if(p==inputs.rend())
            {
                if(inputs == QString("π"))
                {
                    inputs_com = QString::number(fabs(3.141593),10,6);
                    linesInput->setText(QString("|π|"));
                }
                else if(inputs == QString("e"))
                {
                    inputs_com = QString::number(fabs(2.718282),10,6);
                    linesInput->setText(QString("|e|"));
                }
                else
                {
                    temp = inputs.toDouble();
                    inputs_com =QString::number(fabs(temp),10,6);   //对所得的数取绝对值并且追加到之前表达式中
                    linesInput->setText(QString("|%1|").arg(temp));  //按照书写方式显示
                }
            }
            else if((*p==QChar('+'))||(*p==QChar('-'))||(*p==QChar('*'))||(*p==QChar('/'))
                    ||(*p==QChar('^'))||(*p==QChar('d'))||(*p==QChar('(')))
            {
                if(inputs.right(1) == QString("π"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(fabs(3.141593),10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("|π|"));
                }
                else if(inputs.right(1) == QString("e"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(fabs(2.718282),10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("|e|"));
                }
                else
                {
                    temp = inputs.right(count).toDouble();    //获取所得的数
                    inputs_com = inputs_com.left(inputs_com.length()-count).append(QString::number(fabs(temp),10,6));   //对所得的数取绝对值并且追加到之前表达式中
                    linesInput->setText(QString("%1|%2|").arg(inputs.left(inputs.length()-count)).arg(temp));  //按照书写方式显示
                }
            }
         }
    }
    else if(text == QString("exp"))
    {
         if(RefuseCompositeFunction(inputs)&&
                 ((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))  //前一个字符只能是数字
         {
            QString::reverse_iterator p = inputs.rbegin();  //设置反向迭代器
            int count = 0;  //记录遍历的数字个数
            double temp = 0.0;    //用于获取所得数
            while((*p!=QChar('+'))&&(*p!=QChar('-'))&&(*p!=QChar('*'))&&(*p!=QChar('/'))
                  &&(*p!=QChar('^'))&&(*p!=QChar('d'))&&(*p!=QChar('('))&&p!=inputs.rend())
            {
                p++;
                count++;
            }//向前遍历直至遇到其他符号或者到了最前面
            if(p==inputs.rend())
            {
                if(inputs == QString("π"))
                {
                    inputs_com = QString::number(exp(3.141593),10,6);
                    linesInput->setText(QString("e^π"));
                }
                else if(inputs == QString("e"))
                {
                    inputs_com = QString::number(exp(2.718282),10,6);
                    linesInput->setText(QString("e^e"));
                }
                else
                {
                    temp = inputs.toDouble();
                    inputs_com =QString::number(exp(temp),10,6);   //对所得的数求e为底的指数函数并且追加到之前表达式中
                    linesInput->setText(QString("e^%1").arg(temp));  //按照书写方式显示
                }
            }
            else if((*p==QChar('+'))||(*p==QChar('-'))||(*p==QChar('*'))||(*p==QChar('/'))
                    ||(*p==QChar('^'))||(*p==QChar('d'))||(*p==QChar('(')))
            {
                if(inputs.right(1) == QString("π"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(exp(3.141593),10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("e^π"));
                }
                else if(inputs.right(1) == QString("e"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(exp(2.718282),10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("e^e"));
                }
                else
                {
                    temp = inputs.right(count).toDouble();    //获取所得的数
                    inputs_com = inputs_com.left(inputs_com.length()-count).append(QString::number(exp(temp),10,6));   //对所得的数求e为底的指数函数并且追加到之前表达式中
                    linesInput->setText(QString("%1e^%2").arg(inputs.left(inputs.length()-count)).arg(temp));  //按照书写方式显示
                }
            }
         }
    }
    else if(text == QString("log"))
    {
         if(RefuseCompositeFunction(inputs)&&
                 ((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))  //前一个字符只能是数字
         {
            QString::reverse_iterator p = inputs.rbegin();  //设置反向迭代器
            int count = 0;  //记录遍历的数字个数
            double temp = 0.0;    //用于获取所得数
            while((*p!=QChar('+'))&&(*p!=QChar('-'))&&(*p!=QChar('*'))&&(*p!=QChar('/'))
                  &&(*p!=QChar('^'))&&(*p!=QChar('d'))&&(*p!=QChar('('))&&p!=inputs.rend())
            {
                p++;
                count++;
            }//向前遍历直至遇到其他符号或者到了最前面
            if(p==inputs.rend())
            {
                if(inputs == QString("π"))
                {
                    inputs_com = QString::number(log10(3.141593),10,6);
                    linesInput->setText(QString("logπ"));
                }
                else if(inputs == QString("e"))
                {
                    inputs_com = QString::number(log10(2.718282),10,6);
                    linesInput->setText(QString("loge"));
                }
                else
                {
                    temp = inputs.toDouble();
                    if(temp == 0.0)
                    {
                        QMessageBox::warning(0 , "注意" , "除数不能为0，请重新输入。",
                                             QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
                        linesInput->clear();
                        linesResult->clear();
                    }
                    inputs_com =QString::number(log10(temp),10,6);   //对所得的数求10为底的对数函数并且追加到之前表达式中
                    linesInput->setText(QString("log%1").arg(temp));  //按照书写方式显示
                }
            }
            else if((*p==QChar('+'))||(*p==QChar('-'))||(*p==QChar('*'))||(*p==QChar('/'))
                    ||(*p==QChar('^'))||(*p==QChar('d'))||(*p==QChar('(')))
            {
                if(inputs.right(1) == QString("π"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(log10(3.141593),10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("logπ"));
                }
                else if(inputs.right(1) == QString("e"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(log10(2.718282),10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("loge"));
                }
                else
                {
                    temp = inputs.right(count).toDouble();    //获取所得的数
                    if(temp == 0.0)
                    {
                        QMessageBox::warning(0 , "注意" , "除数不能为0，请重新输入。",
                                             QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
                        linesInput->clear();
                        linesResult->clear();
                    }
                    inputs_com = inputs_com.left(inputs_com.length()-count).append(QString::number(log10(temp),10,6));   //对所得的数求10为底的对数函数并且追加到之前表达式中
                    linesInput->setText(QString("%1log%2").arg(inputs.left(inputs.length()-count)).arg(temp));  //按照书写方式显示
                }
            }
         }
    }
    else if(text == QString("ln"))
    {
         if(RefuseCompositeFunction(inputs)&&
                 ((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))  //前一个字符只能是数字
         {
            QString::reverse_iterator p = inputs.rbegin();  //设置反向迭代器
            int count = 0;  //记录遍历的数字个数
            double temp = 0.0;    //用于获取所得数
            while((*p!=QChar('+'))&&(*p!=QChar('-'))&&(*p!=QChar('*'))&&(*p!=QChar('/'))
                  &&(*p!=QChar('^'))&&(*p!=QChar('d'))&&(*p!=QChar('('))&&p!=inputs.rend())
            {
                p++;
                count++;
            }//向前遍历直至遇到其他符号或者到了最前面
            if(p==inputs.rend())
            {
                if(inputs == QString("π"))
                {
                    inputs_com = QString::number(log(3.141593),10,6);
                    linesInput->setText(QString("lnπ"));
                }
                else if(inputs == QString("e"))
                {
                    inputs_com = QString::number(log(2.718282),10,6);
                    linesInput->setText(QString("lne"));
                }
                else
                {
                    temp = inputs.toDouble();
                    if(temp == 0.0)
                    {
                        QMessageBox::warning(0 , "注意" , "除数不能为0，请重新输入。",
                                             QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
                        linesInput->clear();
                        linesResult->clear();
                    }
                    inputs_com =QString::number(log(temp),10,6);   //对所得的数求e为底的对数函数并且追加到之前表达式中
                    linesInput->setText(QString("ln%1").arg(temp));  //按照书写方式显示
                }
            }
            else if((*p==QChar('+'))||(*p==QChar('-'))||(*p==QChar('*'))||(*p==QChar('/'))
                    ||(*p==QChar('^'))||(*p==QChar('d'))||(*p==QChar('(')))
            {
                if(inputs.right(1) == QString("π"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(log(3.141593),10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("lnπ"));
                }
                else if(inputs.right(1) == QString("e"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(log(2.718282),10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("lne"));
                }
                else
                {
                    temp = inputs.right(count).toDouble();    //获取所得的数
                    if(temp == 0.0)
                    {
                        QMessageBox::warning(0 , "注意" , "除数不能为0，请重新输入。",
                                             QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
                        linesInput->clear();
                        linesResult->clear();
                    }
                    inputs_com = inputs_com.left(inputs_com.length()-count).append(QString::number(log(temp),10,6));   //对所得的数求e为底的对数函数并且追加到之前表达式中
                    linesInput->setText(QString("%1ln%2").arg(inputs.left(inputs.length()-count)).arg(temp));  //按照书写方式显示
                }
            }
         }
    }
    else if(text == QString("sin"))
    {
         if(RefuseCompositeFunction(inputs)&&
                 ((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))  //前一个字符只能是数字
         {
            QString::reverse_iterator p = inputs.rbegin();  //设置反向迭代器
            int count = 0;  //记录遍历的数字个数
            double temp = 0.0;    //用于获取所得数
            while((*p!=QChar('+'))&&(*p!=QChar('-'))&&(*p!=QChar('*'))&&(*p!=QChar('/'))
                  &&(*p!=QChar('^'))&&(*p!=QChar('d'))&&(*p!=QChar('('))&&p!=inputs.rend())
            {
                p++;
                count++;
            }//向前遍历直至遇到其他符号或者到了最前面
            if(p==inputs.rend())
            {
                if(inputs == QString("π"))
                {
                    inputs_com = QString::number(sin(3.141593),10,6);
                    linesInput->setText(QString("sinπ"));
                }
                else if(inputs == QString("e"))
                {
                    inputs_com = QString::number(sin(2.718282),10,6);
                    linesInput->setText(QString("sine"));
                }
                else
                {
                    temp = inputs.toDouble();
                    inputs_com =QString::number(sin(temp),10,6);   //对所得的数求sin函数并且追加到之前表达式中
                    linesInput->setText(QString("sin%1").arg(temp));  //按照书写方式显示
                }
            }
            else if((*p==QChar('+'))||(*p==QChar('-'))||(*p==QChar('*'))||(*p==QChar('/'))
                    ||(*p==QChar('^'))||(*p==QChar('d'))||(*p==QChar('(')))
            {
                if(inputs.right(1) == QString("π"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(0.0,10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("sinπ"));
                }
                else if(inputs.right(1) == QString("e"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(sin(2.718282),10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("sine"));
                }
                else
                {
                    temp = inputs.right(count).toDouble();    //获取所得的数
                    inputs_com = inputs_com.left(inputs_com.length()-count).append(QString::number(sin(temp),10,6));   //对所得的数求sin函数并且追加到之前表达式中
                    linesInput->setText(QString("%1sin%2").arg(inputs.left(inputs.length()-count)).arg(temp));  //按照书写方式显示
                }
            }
         }
    }
    else if(text == QString("cos"))
    {
         if(RefuseCompositeFunction(inputs)&&
                 ((inputs.right(1))[0].isDigit()||(inputs.right(1))[0]==QChar('e')||(inputs.right(1))==QString("π")))  //前一个字符只能是数字
         {
            QString::reverse_iterator p = inputs.rbegin();  //设置反向迭代器
            int count = 0;  //记录遍历的数字个数
            double temp = 0.0;    //用于获取所得数
            while((*p!=QChar('+'))&&(*p!=QChar('-'))&&(*p!=QChar('*'))&&(*p!=QChar('/'))
                  &&(*p!=QChar('^'))&&(*p!=QChar('d'))&&(*p!=QChar('('))&&p!=inputs.rend())
            {
                p++;
                count++;
            }//向前遍历直至遇到其他符号或者到了最前面
            if(p==inputs.rend())
            {
                if(inputs == QString("π"))
                {
                    inputs_com = QString::number(cos(3.141593),10,6);
                    linesInput->setText(QString("cosπ"));
                }
                else if(inputs == QString("e"))
                {
                    inputs_com = QString::number(cos(2.718282),10,6);
                    linesInput->setText(QString("cose"));
                }
                else
                {
                    temp = inputs.toDouble();
                    inputs_com =QString::number(cos(temp),10,6);   //对所得的数求cos函数并且追加到之前表达式中
                    linesInput->setText(QString("cos%1").arg(temp));  //按照书写方式显示
                }
            }
            else if((*p==QChar('+'))||(*p==QChar('-'))||(*p==QChar('*'))||(*p==QChar('/'))
                    ||(*p==QChar('^'))||(*p==QChar('d'))||(*p==QChar('(')))
            {
                if(inputs.right(1) == QString("π"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(cos(3.141593),10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("cosπ"));
                }
                else if(inputs.right(1) == QString("e"))
                {
                    inputs_com = inputs_com.left(inputs_com.length()-8).append(QString::number(cos(2.718282),10,6));
                    linesInput->setText(inputs.left(inputs.length()-1)+QString("cose"));
                }
                else
                {
                    temp = inputs.right(count).toDouble();    //获取所得的数
                    inputs_com = inputs_com.left(inputs_com.length()-count).append(QString::number(cos(temp),10,6));   //对所得的数求cos函数并且追加到之前表达式中
                    linesInput->setText(QString("%1cos%2").arg(inputs.left(inputs.length()-count)).arg(temp));  //按照书写方式显示
                }
            }
         }
    }

    else if(text == QString("="))
    {
        if((inputs.right(1))[0]!=QChar(')')&&(inputs.right(1))[0]!=QChar('|')&&(!((inputs.right(1))[0].isDigit()))
                &&(inputs.right(1))!=QString("π")&&(inputs.right(1))[0]!=QChar('e'))  //输入框的表达式应该以数字或者右括号结尾
        {
            QMessageBox::warning(0 , "注意" , "表达式不完整，请重新输入。",
                                 QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
            linesResult->clear();
        }
        else
        {
            int lcount = 0, rcount = 0;
            QString::iterator p = inputs.begin();
            while (p != inputs.end())
            {
                if(*p == QChar('('))
                {
                    lcount++;
                }
                else if(*p == QChar(')'))
                {
                    rcount++;
                }
                p++;
            }
            if(lcount != rcount)
            {
                QMessageBox::warning(0 , "注意" , "左右括号不匹配，请重新输入。",
                                     QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
                linesResult->clear();
            }
            else
            {
                if(inputs!="")
                {
                    std::string str=inputs_com.toStdString();//QString转化为String，注意将运算版本的input带入
                    const char *S=str.c_str();//整个输入框的字符串
                    char OPS[50];//中缀表达式
                    int len;//去掉括号之后中缀表达式的长度
                    double result;//计算结果
                    QString output;
                    bool zeroflag = true;  //判断除数是否为0的标志
                    InfixToSuffix(S,OPS,len);   //调用中缀转后缀函数
                    CalculateSuffix(OPS,len,result,zeroflag); //计算后缀表达式函数
                    if(zeroflag == false)
                    {
                        linesInput->clear();
                        linesResult->clear();
                        QMessageBox::warning(0 , "注意" , "除数不能为0，请重新输入。",
                                             QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
                        linesInput->clear();
                        linesResult->clear();
                    }
                    else
                    {
                        output = QString::number(result,10,6);//将计算结果转换为字符串，10进制，6位小数
                        linesResult->setText(output);
                    }
                }
            }
        }
    }
    else   //0~9
    {
        if(RefuseCompositeFunction(inputs)
                &&((inputs.right(1))[0]!=QChar('e'))&&(inputs.right(1)!=QString("π"))&&((inputs.right(1))[0]!=QChar(')')))
        {
            inputs_com += text;
            inputs+=text;
            linesInput->setText(inputs);
        }
    }
}

//以下为标准和科学计算器共用函数，用于将中缀表达式转成后缀表达式和后缀表达式的计算
bool ExtendedCalculator::RefuseCompositeFunction(QString inp)   //用于限制一元运算函数的输入格式
{
    QString::reverse_iterator p = inp.rbegin();  //设置反向迭代器
    while((p!=inp.rend())
          &&((*p).isDigit()||((*p)==QChar('.'))||((*p)==QChar('e'))||((*p)==QString("π"))||((*p)==QChar(')'))))
    {
        p++;
    }//向前遍历直至遇到其他符号或者到了最前面
    if((*p==QChar('+'))||(*p==QChar('-'))||(*p==QChar('*'))||(*p==QChar('/'))
            ||(*p==QChar('^'))||(*p==QChar('('))||(*p==QChar('d'))||p==inp.rend())   //设置一元运算符不能形成复合函数
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void ExtendedCalculator::InfixToSuffix(const char *S,char OPS[],int &len)  //将中缀表达式转变为后缀表达式
{
    QStack<char> OPE;//符号栈
    unsigned int i,j=0;
    unsigned int tmp = strlen(S);
    for (i = 0; i < tmp; i++)
    {
        switch (S[i])
        {
        case'+':
            if(OPE.isEmpty())//栈为空
             OPE.push(S[i]);
            else if (OPE.top() == '*' || OPE.top() == '/' || OPE.top() == '%' || OPE.top()=='^'
                     ||OPE.top() == '+'||OPE.top() == '-')
            {
                OPS[j++] = OPE.pop();//弹出比'+'运算符优先级高和相等的运算符，依次加入后缀表达式
                i--;
            }
            else
                OPE.push(S[i]);
            break;
        case'-':
            if(i!=0 && '('!=S[i-1])//正数
            {
             if(OPE.isEmpty())//栈为空
                  OPE.push(S[i]);
              else if (OPE.top() == '*' || OPE.top() == '/'|| OPE.top() == '%' || OPE.top()=='^'
                       ||OPE.top() == '+'||OPE.top() == '-')//弹出比'-'运算符优先级高和相等的运算符，依次加入后缀表达式
             {
               OPS[j++] = OPE.pop();
               i--;
             }
              else
                OPE.push(S[i]);
            }
            else//负数
            {
                while ((S[i] >= '0'&&S[i] <= '9' ) || S[i] == '.' || ('-'==S[i]&&(S[i-1]<'0'||S[i-1]>'9')))
                {
                    OPS[j++] = S[i];
                    if('-'==S[i])
                      OPS[j++]='@';
                    i++;
                }
                i--;
                OPS[j++] = '#';  //数字中的间隔符
            }
            break;
        case '^':
                OPE.push(S[i]);
            break;
        case'*':
            if(OPE.isEmpty())//栈为空
               OPE.push(S[i]);
            else if (OPE.top() == '^'|| OPE.top()=='*' || OPE.top()=='/' ||OPE.top() == '%')
            {
                OPS[j++] = OPE.pop();//弹出比'/'运算符优先级高和相等的运算符，依次加入后缀表达式
                i--;
            }
            else
                OPE.push(S[i]);
            break;
        case'/':
            if(OPE.isEmpty())//栈为空
               OPE.push(S[i]);
            else if (OPE.top() == '^' || OPE.top()=='*' || OPE.top()=='/' ||OPE.top() == '%')
            {
                OPS[j++] = OPE.pop();//弹出比'/'运算符优先级高和相等的运算符，依次加入后缀表达式
                i--;
            }
            else
                OPE.push(S[i]);
            break;
        case '%':
            if(OPE.isEmpty())//栈为空
               OPE.push(S[i]);
            else if (OPE.top() == '^'|| OPE.top()=='*' || OPE.top()=='/' ||OPE.top() == '%')
            {
                OPS[j++] = OPE.pop();//弹出比'%'运算符优先级高和相等的运算符，依次加入后缀表达式
                i--;
            }
            else
                OPE.push(S[i]);
            break;
        case'(':
            OPE.push(S[i]);
            break;
        case')':
            while (OPE.top() != '(')//依次把栈中的运算符加入后缀表达式并将其出栈
            {
                OPS[j++] = OPE.pop();
            }
            OPE.pop();//从栈中弹出'('
            break;
        default:
            while ((S[i] >= '0'&&S[i] <= '9') || S[i] == '.' || ('-'==S[i]&&S[i-1]<'0'&&S[i-1]>'9'))
            {

                OPS[j++] = S[i];

                i++;
            }
            i--;
            OPS[j++] = '#';  //数字中的间隔符
            break;
        }
    }
    while (!OPE.isEmpty())
    {
        OPS[j++] = OPE.pop();
    }
    len = j;
}

void ExtendedCalculator::CalculateSuffix(char SUF[], int len, double &result,bool &flag)//用后缀表达式计算结果
{
    int i;
    double a;
    double b;
    double c;
    QStack<double>ST;
    for (i = 0; i < len; i++)
    {
        switch (SUF[i])
        {
           case'^':
          {
            a = ST.pop();
            b = ST.pop();
            c = pow(b,a);
            ST.push(c);
          }
            break;
           case'+':
           {
            a = ST.pop();
            b = ST.pop();
            c = b + a;
            ST.push(c);
            }
               break;
           case'-':
           {
            if('@'!=SUF[i+1])
            {
            a = ST.pop();
            b = ST.pop();
            c = b - a;
            ST.push(c);
            }
            else
            {
                int jx = 0;
                double dx;
                char *stx = new char[10];
                while (SUF[i] != '#')
                {
                   if('@'!=SUF[i])
                    stx[jx++] = SUF[i];
                    i++;

                }
                dx = atof(stx);//把字符串转换成浮点数
                ST.push(dx);
                delete stx;
            }
           }
               break;
           case'*':
           {
            a = ST.pop();
            b = ST.pop();
            c = b*a;
            ST.push(c);
           }
               break;
           case'/':
           {
              a = ST.pop();
              b = ST.pop();
              if (a == 0)
              {
                  flag = false;
                  return;
              }
              c = b / a;
              ST.push(c);
           }
               break;
           case'%':
          {
           a = ST.pop();
           b = ST.pop();
           if (a == 0)
           {
               flag = false;
               return;
           }
           //c = (int)b % (int)a;
           c = fmod(b,a);
           ST.push(c);
          }
            break;
           default:
               int j = 0;
               double d;
               char *st = new char[10];
               while (SUF[i] != '#')
               {
                   st[j++] = SUF[i];
                   i++;
               }
               d = atof(st);//把字符串转换成浮点数
               ST.push(d);
               delete st;
               break;
        }
    }
    result=ST.top();
}





/*排列组合选项卡的函数*/
void ExtendedCalculator::button_0Clicked()
{
    QString str="0";
    setpText(str);
}
void ExtendedCalculator::button_1Clicked()
{
    QString str="1";
    setpText(str);
}
void ExtendedCalculator::button_2Clicked()
{
    QString str="2";
    setpText(str);
}
void ExtendedCalculator::button_3Clicked()
{
    QString str="3";
    setpText(str);
}
void ExtendedCalculator::button_4Clicked()
{
    QString str="4";
    setpText(str);
}
void ExtendedCalculator::button_5Clicked()
{
    QString str="5";
    setpText(str);
}
void ExtendedCalculator::button_6Clicked()
{
    QString str="6";
    setpText(str);
}
void ExtendedCalculator::button_7Clicked()
{
    QString str="7";
    setpText(str);
}
void ExtendedCalculator::button_8Clicked()
{
    QString str="8";
    setpText(str);
}
void ExtendedCalculator::button_9Clicked()
{
    QString str="9";
    setpText(str);
}
void ExtendedCalculator::button_deletClicked()
{
    QString str="<-";
    setpText(str);
}

void ExtendedCalculator::setpText(QString str)
{
    if(ui->lineEdit_C1->hasFocus())
    {
        QString inputC1=ui->lineEdit_C1->text();
        if(str==QString("<-"))
         {
            inputC1=inputC1.left(inputC1.length()-1);
            ui->lineEdit_C1->setText(inputC1);
        }
        else
        {
            inputC1.append(str);
            ui->lineEdit_C1->setText(inputC1);
        }
    }

    else if(ui->lineEdit_C2->hasFocus())
    {
        QString inputC2=ui->lineEdit_C2->text();
        if(str==QString("<-"))
         {
            inputC2=inputC2.left(inputC2.length()-1);
            ui->lineEdit_C2->setText(inputC2);
        }
        else
        {
            inputC2.append(str);
            ui->lineEdit_C2->setText(inputC2);
        }
    }

    else if(ui->lineEdit_A1->hasFocus())
    {
        QString inputA1=ui->lineEdit_A1->text();
        if(str==QString("<-"))
         {
            inputA1=inputA1.left(inputA1.length()-1);
            ui->lineEdit_A1->setText(inputA1);
        }
        else
        {
            inputA1.append(str);
            ui->lineEdit_A1->setText(inputA1);
        }
    }

    else if(ui->lineEdit_A2->hasFocus())
    {
        QString inputA2=ui->lineEdit_A2->text();
        if(str==QString("<-"))
         {
            inputA2=inputA2.left(inputA2.length()-1);
            ui->lineEdit_A2->setText(inputA2);
        }
        else
        {
            inputA2.append(str);
            ui->lineEdit_A2->setText(inputA2);
        }
    }

    else if(ui->lineEdit_fact->hasFocus())
    {
        QString inputF=ui->lineEdit_fact->text();
        if(str==QString("<-"))
         {
            inputF=inputF.left(inputF.length()-1);
            ui->lineEdit_fact->setText(inputF);
        }
        else
        {
            inputF.append(str);
            ui->lineEdit_fact->setText(inputF);
        }
    }
}

//读取单行输入框中的内容，对数据合法性进行判定后，调用组合数计算公式，并显示在框中
void ExtendedCalculator::Mydisplay_C()
{
    QString C_String1=this->ui->lineEdit_C1->text();
    QString C_String2=this->ui->lineEdit_C2->text();
    int C_Num1=C_String1.toInt();
    int C_Num2=C_String2.toInt();
    if(C_Num1>C_Num2||C_Num1<=0||C_Num2<=0)
    {
        QMessageBox::warning(NULL, QStringLiteral("注意"), QStringLiteral("输入数值有误，请重新输入"),
                             QMessageBox::Yes , QMessageBox::Yes);
    }
    else if(C_Num1>3000||C_Num2>3000)
    {
        QMessageBox::warning(NULL, QStringLiteral("注意"), QStringLiteral("组合数最大输入范围为C（3000,3000）"),
                             QMessageBox::Yes , QMessageBox::Yes);
    }
    else
     {
        QString qstr1 = QString::number(Combinat( C_Num2, C_Num1));
        this->ui->textBrowser_C->setText(qstr1);
     }
}
//读取单行输入框中的内容，对数据合法性进行判定后，调用排列数计算公式，并显示在框中
void ExtendedCalculator::Mydisplay_A()
{
    QString A_String1=this->ui->lineEdit_A1->text();
    QString A_String2=this->ui->lineEdit_A2->text();
    int A_Num1=A_String1.toInt();
    int A_Num2=A_String2.toInt();
    if(A_Num1>A_Num2||A_Num1<=0||A_Num2<=0)
    {
        QMessageBox::warning(NULL, QStringLiteral("注意"), QStringLiteral("输入数值有误，请重新输入"),
                             QMessageBox::Yes , QMessageBox::Yes);
    }
    else if(A_Num1>25||A_Num2>25)
    {
        QMessageBox::warning(NULL, QStringLiteral("注意"), QStringLiteral("排列数最大输入范围为A（25,25）"),
                             QMessageBox::Yes , QMessageBox::Yes);
    }
    else
     {
        QString qstr2 = QString::number(Arrange( A_Num1, A_Num2));
        this->ui->textBrowser_A->setText(qstr2);
     }
}

/*下面4个函数均与计算组合数有关*/
//生成素数序列的函数
QVector<int> ExtendedCalculator::prim_produce()
{
    QVector <int> vc;
    vc.push_back(2);
    int i,j;
    for(i=3;i*i<=maxn;i+=2)
    {
        if(!a[i])
        {
            vc.push_back(i);
            for(j=i*i;j<=maxn;j+=i)
            {
                a[j]=true;
            }
        }
    }
    while(i<maxn)
    {
        if(!a[i]) vc.push_back(i);
        i+=2;
    }
    return vc;
}

//计算n!素数p的指数
int ExtendedCalculator::cal(int x,int p)
{
    int ans=0;
    long long re=p;
    while(x>=re)
    {
        ans+=x/re;
        re*=p;
    }
    return ans;
}

//二分求n的k次方
int ExtendedCalculator::Pow(long long n,int k)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*n%MOD;
        n=(n*n)%MOD;
        k>>=1;
    }
    return ans;
}

//组合数计算公式
long long ExtendedCalculator::Combinat(int n,int m)
{
    QVector <int> prim=prim_produce();
    long long ans=1;
    int num;
    for(int i=0;i<prim.size()&&prim[i]<=n;i++)
    {
        num=cal(n,prim[i])-cal(m,prim[i])-cal(n-m,prim[i]);
        ans=(ans*Pow(prim[i],num))%MOD;
    }
    return ans;
}

//排列数计算公式
long long ExtendedCalculator::Arrange(int n,int m){
    int i;
    long long res=m;
    for(i=1;i<n;i++)
    {
        res=res*(--m);
    }
    return res;
}

//计算并显示阶乘结果
void ExtendedCalculator::OnButtonClicked(){
    ui->textBrowser_fact->clear();
    QString F_String=this->ui->lineEdit_fact->text();
    int n=F_String.toInt();
    if((F_String!="0"&&n==0)||(n<0))
    {
        QMessageBox::warning(NULL, QStringLiteral("注意"), QStringLiteral("输入数值有误，请重新输入"),
                             QMessageBox::Yes , QMessageBox::Yes);
    }
    else
    {
        if(n>5000)
        {
            QMessageBox::warning(NULL, QStringLiteral("注意"), QStringLiteral("阶乘功能输入的数字不能超过5000"),
                                 QMessageBox::Yes , QMessageBox::Yes);

        }
        else
        {
            int a[20001]={};//储存每一位所得到的数
            char b[20001]={};
            int temp,digit,i,j=0,k=0;//temp每次的得数   digit每次得数的位数
            a[0]=1;//从1开始乘
            digit=1;//位数从第一位开始
            for(i=2;i<=n;i++)
            {
                int num=0;
                for(j=0;j<digit;j++)
                {
                    temp=a[j]*i+num;//将一个数的每一位数都分别乘以i，
                    a[j]=temp%10;//将一个数的每一位数利用数组进行储存
                    num=temp/10;
                }
                while(num)//判断退出循环后，num的值是否为0
                {
                    a[digit]=num%10;//继续储存
                    num=num/10;
                    digit++;
                }
            }
            for(i=digit-1;i>=0;i--)//倒序输出每一位
            {

                b[k]=a[i]+'0';
                k++;

            }
            ui->textBrowser_fact->setText(b);
        }
    }
}





/* 复数选项卡的函数 */
void ExtendedCalculator::on_btnc0_clicked()
{
    QString str = "0";
    setcText(str);
}
void ExtendedCalculator::on_btnc1_clicked()
{
    QString str = "1";
    setcText(str);
}
void ExtendedCalculator::on_btnc2_clicked()
{
    QString str = "2";
    setcText(str);
}
void ExtendedCalculator::on_btnc3_clicked()
{
    QString str = "3";
    setcText(str);
}
void ExtendedCalculator::on_btnc4_clicked()
{
    QString str = "4";
    setcText(str);
}
void ExtendedCalculator::on_btnc5_clicked()
{
    QString str = "5";
    setcText(str);
}
void ExtendedCalculator::on_btnc6_clicked()
{
    QString str = "6";
    setcText(str);
}
void ExtendedCalculator::on_btnc7_clicked()
{
    QString str = "7";
    setcText(str);
}
void ExtendedCalculator::on_btnc8_clicked()
{
    QString str = "8";
    setcText(str);
}
void ExtendedCalculator::on_btnc9_clicked()
{
    QString str = "9";
    setcText(str);
}
void ExtendedCalculator::on_btncPoint_clicked()
{
    QString str = ".";
    setcText(str);
}
void ExtendedCalculator::on_btncNeg_clicked()
{
    QString str = "-";
    setcText(str);
}
void ExtendedCalculator::on_btncBack_clicked()
{
    if(ui->lineReal1->hasFocus())
    {
        inputc1 = inputc1.left(inputc1.length()-1);
        ui->lineReal1->setText(inputc1);
    }
    else if(ui->lineImag1->hasFocus())
    {
        inputc2 = inputc2.left(inputc2.length()-1);
        ui->lineImag1->setText(inputc2);
    }
    else if(ui->lineReal2->hasFocus())
    {
        inputc3 = inputc3.left(inputc3.length()-1);
        ui->lineReal2->setText(inputc3);
    }
    else if(ui->lineImag2->hasFocus())
    {
        inputc4 = inputc4.left(inputc4.length()-1);
        ui->lineImag2->setText(inputc4);
    }
}
void ExtendedCalculator::on_btncClear_clicked()
{
    inputc1="";
    inputc2="";
    inputc3="";
    inputc4="";
    complexResult="";
    ui->lineReal1->clear();
    ui->lineImag1->clear();
    ui->lineReal2->clear();
    ui->lineImag2->clear();
    ui->lineComplexResult->clear();
}
void ExtendedCalculator::on_btncEqual_clicked()
{
    inputc1=ui->lineReal1->text();
    inputc2=ui->lineImag1->text();
    inputc3=ui->lineReal2->text();
    inputc4=ui->lineImag2->text();
    real1 = inputc1.toFloat();  //如果含有不能转成float的字符，则返回0
    imag1 = inputc2.toFloat();
    real2 = inputc3.toFloat();
    imag2 = inputc4.toFloat();
    complexOper = (ui->comboBox->currentText().toStdString())[0];   //qstring转成标准string类型再获取第一个字符就是所选择的运算符
    bool flag = checkInput(real1,imag1,real2,imag2,inputc1,inputc2,inputc3,inputc4);
    if(!flag)
    {
        on_btncClear_clicked();
    }
    else
    {
        switch(complexOper)
        {
            case '+':
            {
                realres = real1 + real2;
                imagres = imag1 + imag2;
            }
            break;
            case '-':
            {
                realres = real1 - real2;
                imagres = imag1 - imag2;
            }
            break;
            case '*':
            {
                realres = real1*real2 - imag1*imag2;
                imagres = imag1*real2 + real1*imag2;
            }
            break;
            case '/':
            {
                if(real2*real2+imag2*imag2==0.0)
                {
                    QMessageBox::warning(0 , "注意" , "第二个复数不能为0，请重新输入。",
                                          QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
                }
                else
                {
                    realres = (real1*real2 + imag1*imag2)/(real2*real2+imag2*imag2);
                    imagres = (imag1*real2 - real1*imag2)/(real2*real2+imag2*imag2);
                }
            }
            break;
        }
        QPalette palette;
        ui->lineComplexResult->setFont(QFont("微软雅黑",10,QFont::Normal));//设置字体大小
        ui->lineComplexResult->setPalette(palette);
        if((complexOper == '/')&&(real2*real2+imag2*imag2==0.0))
        {
            on_btncClear_clicked();
        }
        else
        {
            if(imagres >= 0.0)
            {
                complexResult = QString("%1%2%3%4").arg(realres).arg("+").arg(imagres).arg("i");
            }
            else
            {
                complexResult = QString("%1%2%3").arg(realres).arg(imagres).arg("i");
            }
            ui->lineComplexResult->setText(complexResult);
        }
    }
}
void ExtendedCalculator::setcText(QString str)
{
    if(ui->lineReal1->hasFocus())
    {
        inputc1=ui->lineReal1->text();  //先获取目前输入框内的数字
        inputc1.append(str);    //再进行按钮输入字符的操作，以免漏掉键盘输入的数字
        ui->lineReal1->setText(inputc1);
    }
    else if(ui->lineImag1->hasFocus())
    {
        inputc2=ui->lineImag1->text();
        inputc2.append(str);
        ui->lineImag1->setText(inputc2);
    }
    else if(ui->lineReal2->hasFocus())
    {
        inputc3=ui->lineReal2->text();
        inputc3.append(str);
        ui->lineReal2->setText(inputc3);
    }
    else if(ui->lineImag2->hasFocus())
    {
        inputc4=ui->lineImag2->text();
        inputc4.append(str);
        ui->lineImag2->setText(inputc4);
    }
}
bool ExtendedCalculator::checkInput(float real1, float imag1, float real2, float imag2,
        QString inputc1,QString inputc2,QString inputc3,QString inputc4)
{
    //检测输入框是否为空
    if(inputc1.isEmpty()||inputc2.isEmpty()||inputc3.isEmpty()||inputc4.isEmpty())
    {
        QMessageBox::warning(0 , "注意" , "复数的实部和虚部不能为空，请重新输入。",
                              QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
        on_btncClear_clicked();
        return 0;
    }
    //检测原字符串是0还是存在非法字符
    if((real1==0&&inputc1!="0")||(imag1==0&&inputc2!="0")||(real2==0&&inputc3!="0")||(imag2==0&&inputc4!="0"))
    {
        QMessageBox::warning(0 , "注意" , "输入内含有非数字字符，请重新输入。",
                              QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0 );
        on_btncClear_clicked();
        return 0;
    }
    return 1;
}
