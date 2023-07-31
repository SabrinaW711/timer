#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startButton_clicked();
    void timeoutSlot();
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTimer *timer;
    int picId;                  //图片编号
};
#endif // WIDGET_H
