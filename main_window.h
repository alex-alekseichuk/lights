#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__ 1

#include <QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets>
#else
#include <QtGui>
#endif

#include <QMainWindow>

#include "model.h"

class QAction;
class QMenu;

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow();

private slots:
	void newFile();
	void openFile();
	void saveFile();
	void saveAsFile();

    void addFrame();
    void deleteFrame();

    void goFirst();
    void goPrev();
    void goNext();
    void goLast();

    void start();
    void stop();

    void updateUI();

private:
	Model model;
	
	void createActions();
	void createMenu();
	void createToolBars();
	void createStatusBar();

	QAction *exitAct;
	QAction *newAct;
	QAction *openAct;
	QAction *saveAct;
	QAction *saveAsAct;

    QAction *insertAct;
    QAction *deleteAct;

    QAction *goFirstAct;
    QAction *goPrevAct;
    QAction *goNextAct;
    QAction *goLastAct;

    QAction *startAct;
    QAction *stopAct;

	QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *runMenu;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QToolBar *runToolBar;

    QLabel *lblCurrent;
};

#endif
