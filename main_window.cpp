//#include <QtWidgets>
#include <QtGui>
#include "main_window.h"

MainWindow::MainWindow() : model() {
	createActions();
	createMenu();
	createToolBars();
	createStatusBar();

	setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindow::createActions() {
    newAct = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create new lights project"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
    
    openAct = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open lights project"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(openFile()));
    
    saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save lights project"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveFile()));
    
    saveAsAct = new QAction(QIcon(":/images/saveAs.png"), tr("Save &As..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Exit the application"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAsFile()));
    
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    
    insertAct = new QAction(QIcon(":/images/plus.png"), tr("&Insert"), this);
    insertAct->setShortcut(Qt::CTRL + Qt::Key_I);
    insertAct->setStatusTip(tr("Insert a frame"));
    connect(insertAct, SIGNAL(triggered()), this, SLOT(insertFrame()));
    

}

void MainWindow::createMenu() {
	fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

	editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(insertAct);


}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(insertAct);
}

void MainWindow::createStatusBar()
{
    //statusBar()->showMessage(tr("Ready"));
}


void MainWindow::newFile() {
	model.blank();
}
void MainWindow::openFile() {
}
void MainWindow::saveFile() {
}
void MainWindow::saveAsFile() {
}


void MainWindow::insertFrame() {
	model.insertFrame();
	// statusBar()->showMessage(tr("Frame inserted"), 2000);
}

