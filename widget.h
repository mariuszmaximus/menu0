#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

protected:
    // onShow
    // void showEvent(QShowEvent *event) override;
    // onKeyPress
    void keyPressEvent(QKeyEvent *event) override;
};
#endif // WIDGET_H
