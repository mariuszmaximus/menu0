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
                [=]()-> menu0_gui_sample*
                       {
                           return new menu0_gui_sample(this);
                           //return  Menu0_gui::instance(this);
                       });


}

Widget::~Widget()
{
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

