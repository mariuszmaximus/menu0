#include "menu0_gui_sample.h"
#include "ui_menu0_gui_sample.h"

#include "menu0_gui_sample.h"
#include <QKeyEvent>
#include <QMetaObject>
#include <QMetaEnum>
#include <QDebug>


menu0_gui_sample::menu0_gui_sample(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu0_gui_sample)
{
    ui->setupUi(this);
    installEventFilter(this);
    connect(this->ui->actionmenu02, QAction::triggered, this, menu0_gui_sample::on_actionclose_menu_triggered  );
    connect(this->ui->actionmenu03, QAction::triggered, this, menu0_gui_sample::on_actionclose_menu_triggered  );
    connect(this->ui->actionmenu11, QAction::triggered, this, menu0_gui_sample::on_actionclose_menu_triggered  );
    connect(this->ui->actionmenu12, QAction::triggered, this, menu0_gui_sample::on_actionclose_menu_triggered  );
    connect(this->ui->actionmenu13, QAction::triggered, this, menu0_gui_sample::on_actionclose_menu_triggered  );
}

menu0_gui_sample::~menu0_gui_sample()
{
    qDebug()<<" ********************* DESTRUKTOR *******************" << this;
    delete ui;
}

void menu0_gui_sample::on_actionclose_menu_triggered()
{
    close();
    setParent(nullptr);
}

bool menu0_gui_sample::eventFilter(QObject* obj, QEvent* event)
{
    // qDebug()<< obj<<" "<<event;

    if (event->type()==QEvent::KeyPress||event->type()==QEvent::KeyRelease)
    {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if ( (key->key()==Qt::Key_Escape))
        {
            close();
            setParent(nullptr);
        }
        QMetaEnum metaEnumKey = QMetaEnum::fromType<Qt::Key>();
        QString _key = metaEnumKey.valueToKey(key->key());
        //qDebug("key press %s", _key.toStdString().c_str());
        return false;
    }
    else
    if ( event->type() == QEvent::Close )
    {
        //qDebug()<< obj;
        //qDebug("menu0_gui_sample::eventFilter == >QEvent::Close ???? \n");
        close();
        return QObject::eventFilter(obj, event);
    }
    {
        return QObject::eventFilter(obj, event);
    }
}

void menu0_gui_sample::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "menu0_gui_sample::keyPressEvent" << event;

    QWidget::keyPressEvent(event);
}