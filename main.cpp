/******************************************************************************
* 版权所有(c) <武汉创景可视技术有限公司>, 保留所有权利
******************************************************************************/
#include "RenderWindow.h"
#include "MainWindow.h"

#include "AppContext.h"
#include "PeGod.h"
#include "PeScriptManager.h"

#include <QApplication>
#include <QMessageBox>

#include <string>

/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppContext* appContext = new AppContext;
    Pe::God* god = new Pe::God;

    QMainWindow* mw = new QMainWindow;
    PERenderWindow* w = new PERenderWindow(mw);
    mw->setCentralWidget(w);
    w->initialize();

    god->initialize();

    if(argc > 1) {
        std::string projectFile = argv[1];
        god->loadScene(projectFile);

        Pe::ScriptManager::getSingletonPtr()->start();
    }

    mw->showMaximized();
    w->startRender();

    int res = a.exec();

    delete mw;
    delete god;
    delete appContext;

}
*/

/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    for(int i=0; i<argc; i++){
        if( strstr(argv[i], "/debug") ){
            w.ReadPEData();
            break;
        }
    }

    return a.exec();
}
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppContext* appContext = new AppContext;
    Pe::God* god = new Pe::God;

    MainWindow* mw = new MainWindow;
    mw->getRenderWindow()->initialize();

    god->initialize();

    if(argc > 1) {

        // 可能不能用共享内存
        bool isDebug = false;
//        for(int i=0; i<argc; i++){
//            if( strstr(argv[i], "/debug") ){
//                isDebug = true;
//                mw->getRenderWindow()->readPEData();
//                break;
//            }
//        }

        if(!isDebug) {
            std::string projectFile = argv[1];

            god->loadScene(projectFile);
            Pe::ScriptManager::getSingletonPtr()->start();
        }

    }

    mw->showMaximized();
    mw->getRenderWindow()->startRender();

    int res = a.exec();

    delete mw;
    delete god;
    delete appContext;

}
