#include "widget.h"
#include "ui_widget.h"

#define TIMEOUT 1 * 1000            //1S

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer;

    QImage img;
    img.load("D:\\QtProject\\QtOnline\\1.jpg");
    ui -> label -> setPixmap(QPixmap::fromImage(img));
    //定时器时间到发出TIMEOUT信号(谁发出信号->发出什么信号->谁来处理->怎么处理）
    connect(timer, &QTimer::timeout, this, &Widget::timeoutSlot);

    picId = 2;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    timer -> start(TIMEOUT);
}

void Widget::timeoutSlot() {
    //创建路径
    QString path("D:\\QtProject\\QtOnline\\");
    path += QString::number(picId);
    path += ".jpg";

    QImage img;
    img.load(path);
    ui -> label -> setPixmap(QPixmap::fromImage(img));

    picId++;
    if (picId == 5) {
        picId = 1;
    }
}

void Widget::on_pushButton_2_clicked()
{
    timer -> stop();
}


void Widget::on_pushButton_clicked()
{
    QTimer::singleShot(1000, this, SLOT(timeoutSlot()) );
    //时间 -> 谁来处理来 -> 怎么处理
}

