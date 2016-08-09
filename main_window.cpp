#include <QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets>
#else
#include <QtGui>
#endif

//#include <HQBoxLayout>

#include "main_window.h"
#include "frame_widget.h"

MainWindow::MainWindow() : model()
{
	createActions();
	createMenu();
	createToolBars();
	createStatusBar();

	setUnifiedTitleAndToolBarOnMac(true);

    FrameWidget *frameWidget = new FrameWidget(&model, this);
    setCentralWidget(frameWidget);

    connect(&model, SIGNAL(currentFrameChanged()), this, SLOT(updateUI()));

    updateUI();
}

void MainWindow::updateUI() {
    if (model.total() > 0)
        lblCurrent->setText(QString::asprintf("%d / %d", model.index() + 1, model.total()));
    else
        lblCurrent->setText("No frames");
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
    
    insertAct = new QAction(QIcon(":/images/add.png"), tr("&Add"), this);
    insertAct->setShortcut(Qt::CTRL + Qt::Key_A);
    insertAct->setStatusTip(tr("Add a frame"));
    connect(insertAct, SIGNAL(triggered()), this, SLOT(addFrame()));

    deleteAct = new QAction(QIcon(":/images/delete.png"), tr("&Delete"), this);
    deleteAct->setShortcut(Qt::CTRL + Qt::Key_D);
    deleteAct->setStatusTip(tr("Delete current frame"));
    connect(deleteAct, SIGNAL(triggered()), this, SLOT(deleteFrame()));

    goFirstAct = new QAction(QIcon(":/images/first.png"), tr("Go &First"), this);
    goFirstAct->setShortcut(Qt::CTRL + Qt::Key_PageUp);
    goFirstAct->setStatusTip(tr("Go to First frame"));
    connect(goFirstAct, SIGNAL(triggered()), this, SLOT(goFirst()));

    goPrevAct = new QAction(QIcon(":/images/prev.png"), tr("Go &Previous"), this);
    goPrevAct->setShortcut(Qt::Key_PageUp);
    goPrevAct->setStatusTip(tr("Go to Previous frame"));
    connect(goPrevAct, SIGNAL(triggered()), this, SLOT(goPrev()));

    goNextAct = new QAction(QIcon(":/images/next.png"), tr("Go &Next"), this);
    goNextAct->setShortcut(Qt::Key_PageDown);
    goNextAct->setStatusTip(tr("Go to Next frame"));
    connect(goNextAct, SIGNAL(triggered()), this, SLOT(goNext()));

    goLastAct = new QAction(QIcon(":/images/last.png"), tr("Go &Last"), this);
    goLastAct->setShortcut(Qt::CTRL + Qt::Key_PageDown);
    goLastAct->setStatusTip(tr("Go to Last frame"));
    connect(goLastAct, SIGNAL(triggered()), this, SLOT(goLast()));

    startAct = new QAction(QIcon(":/images/start.png"), tr("&Play"), this);
    startAct->setShortcut(Qt::CTRL + Qt::Key_P);
    startAct->setStatusTip(tr("Play"));
    connect(startAct, SIGNAL(triggered()), this, SLOT(start()));

    stopAct = new QAction(QIcon(":/images/stop.png"), tr("&Stop"), this);
    stopAct->setShortcut(Qt::CTRL + Qt::Key_S);
    stopAct->setStatusTip(tr("Stop"));
    connect(stopAct, SIGNAL(triggered()), this, SLOT(stop()));

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
    editMenu->addAction(deleteAct);
    editMenu->addSeparator();
    editMenu->addAction(goFirstAct);
    editMenu->addAction(goPrevAct);
    editMenu->addAction(goNextAct);
    editMenu->addAction(goLastAct);

    runMenu = menuBar()->addMenu(tr("&Run"));
    runMenu->addAction(startAct);
    runMenu->addAction(stopAct);

}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(insertAct);
    editToolBar->addAction(deleteAct);
    editToolBar->addSeparator();
    editToolBar->addAction(goFirstAct);
    editToolBar->addAction(goPrevAct);

    lblCurrent = new QLabel();
    editToolBar->addWidget(lblCurrent);
    lblCurrent->setText("");
    lblCurrent->setMargin(7);
    QFont font;
    font.setPointSize(11);
    lblCurrent->setFont(font);
    lblCurrent->setFixedWidth(100);
    lblCurrent->setAlignment(Qt::AlignCenter);
    lblCurrent->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    editToolBar->addAction(goNextAct);
    editToolBar->addAction(goLastAct);

    runToolBar = addToolBar(tr("Run"));
    runToolBar->addAction(startAct);
    runToolBar->addAction(stopAct);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
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


void MainWindow::addFrame() {
    model.addBlankFrame();
//	statusBar()->showMessage(tr("Frame inserted"), 2000);
}
void MainWindow::deleteFrame() {
    model.deleteCurrentFrame();
}

void MainWindow::goFirst() {
    model.goFirst();
}
void MainWindow::goPrev() {
    model.goPrev();
}
void MainWindow::goNext() {
    model.goNext();
}
void MainWindow::goLast() {
    model.goLast();
}

void MainWindow::start() {
    model.start();
}
void MainWindow::stop() {
    model.stop();
}

