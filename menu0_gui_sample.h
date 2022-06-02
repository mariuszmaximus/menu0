#ifndef MENU0_GUI_SAMPLE_H
#define MENU0_GUI_SAMPLE_H

#include <QMainWindow>

namespace Ui {
class menu0_gui_sample;
}

class menu0_gui_sample : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu0_gui_sample(QWidget *parent = nullptr);
    ~menu0_gui_sample();

private slots:
    void on_actionclose_menu_triggered();

private:
    Ui::menu0_gui_sample *ui;

protected:
    bool eventFilter(QObject* obj, QEvent* event)override;
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MENU0_GUI_SAMPLE_H
