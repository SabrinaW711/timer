#include "widget.h"
#include "ui_widget.h"

#define TIMEOUT 1 * 1000                        //以毫秒为单位，1S
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap pix("D:\\QtProject\\QtOnline\\1.jpg");
    ui -> label -> setPixmap(pix);

    picId = 2;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    myTimerId = this -> startTimer(TIMEOUT);
    //开启定时器，返回定时器编号
}

void Widget::timerEvent(QTimerEvent *event) {
    if (event -> timerId() != myTimerId) {
        return;
    } else {
        //构建路径
        QString path("D:\\QtProject\\QtOnline\\");
        path += QString::number(picId);
        path += ".jpg";

        QPixmap pix(path);
        ui -> label -> setPixmap(pix);

        picId++;
        if (picId == 5) {
            picId = 1;
        }
    }
}


void Widget::on_pushButton_2_clicked()
{
    this -> killTimer(myTimerId);
}

