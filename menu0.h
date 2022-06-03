#ifndef _MENU0_H_
#define _MENU0_H_

#include <QtWidgets>

typedef QMainWindow IMenu0_GUI;

typedef std::function<IMenu0_GUI*()> fu_create_Menu0_GUI;


class Menu0  
{
private:
    inline static fu_create_Menu0_GUI create_Menu0_GUI{0};
    inline static IMenu0_GUI * instance_menu_gui{nullptr}; 
    Menu0(){};
public:
    ~Menu0()
    {
        qDebug()<<" ********************* DESTRUKTOR *******************" << this;
    }
    ////////////////////////////////////////////// 
    static bool Visible(void)
    {
        if(instance_menu_gui)
        {
            return instance_menu_gui->isVisible(); 
        }
        else
        return false;
    }

    ////////////////////////////////////////////// 
    static void Close(void)
    {
        printf("Menu0::Close\n");
        if(instance_menu_gui)
        {
            instance_menu_gui->close();
        }
    }

    ////////////////////////////////////////////// 
    static void RegisterMenu(fu_create_Menu0_GUI fu){
        create_Menu0_GUI = fu;
    }

    ////////////////////////////////////////////// 
    static bool Execute(QWidget *parent)
    {
        //(void)parent;
        // Menu0_gui *WindowMenu=nullptr; // stara wersja !!!
        // printf("Menu::Execute\n");
        // inicjalizacja 
        
        // uruchamiam okno 

        //if(WindowMenu) { WindowMenu->close();  delete WindowMenu ;  };

        //Menu0_gui * menu_gui = Menu0_gui::instance(parent);

        //IMenu0_GUI * menu_gui{nullptr};

        if(create_Menu0_GUI) 
        {
            instance_menu_gui = create_Menu0_GUI();
        }   

        if(!instance_menu_gui) return false;

        instance_menu_gui->setParent(parent);

        //W->show();
        // Qt::WindowFlags flags = 0;
        // flags =  Qt::Window;
        // flags |= Qt::FramelessWindowHint;
        // W->setWindowFlags(flags );
        //W->showFullScreen();
        instance_menu_gui->setWindowFlags(Qt::CustomizeWindowHint);

        // ustawiam rozmiar 
        QRect drect = QGuiApplication::primaryScreen()->availableGeometry();
        //qApp->primaryScreen()->availableGeometry();
        instance_menu_gui->resize(drect.width(),140);

        instance_menu_gui->move(0,0);


        //  ?? QMenuBar { background-color: #880000; font-size: 26px; font: bold 20px;  } dziala font-size i font:
    
        //QString style = "QMenuBar { background-color: #880000; font-size: 26px; font: bold 20px;  }   QMenuBar::item:selected { background: white; } QMenuBar::item:pressed {  background: white; }";
        //QString style = "QMenuBar { background-color: #00FF00; font-size: 26px; font: bold 20px;  }   QMenuBar::item {font-size: 26px; font: bold 20px; }";
        //style += "QMenuBar::item { font-size: 26px; spacing: 0px; padding: 3px 6px 3px 8px; }";
        //W->menuBar()->setStyleSheet(style);


        instance_menu_gui->show();

        // [1] aby rozwinać MENU klikam 
        QMouseEvent *clickEvent=new QMouseEvent(QEvent::MouseButtonPress,QPoint(24,12),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier); // Qt::NoModifier == 0 , ale jak uzyjemy "0" to jest warning 
        QApplication::sendEvent(instance_menu_gui->menuBar(),clickEvent);
        delete clickEvent;

        // [2] naciskam strzałke do dołu 
        QKeyEvent *keyEvent=new QKeyEvent(QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier );  // Qt::NoModifier == 0 , ale jak uzyjemy "0" to jest warning 
        QApplication::sendEvent(instance_menu_gui->menuBar() ,keyEvent);
        delete keyEvent;

        return true; 
    }
};


#endif
