#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "RenderWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mRenderWindow = new PERenderWindow(this);
    setCentralWidget(mRenderWindow);
    setWindowTitle(tr("调试窗口"));
    resize(1000, 600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

