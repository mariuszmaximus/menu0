#include "widget.h"
#include "./ui_widget.h"
#include "menu0.h"
#include "menu0_gui_sample.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Menu0::RegisterMenu(
                [=]()-> IMenu0_GUI*
                       {
                           return new menu0_gui_sample(this);
                       });
}

Widget::~Widget()
{
    qDebug()<<" ********************* DESTRUKTOR *******************" << this;
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Return:
        Menu0::Execute(this);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

