#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__ 1

#include <QMainWindow>
//#include "model.h"

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

	void insertFrame();

private:
	//Model model;
	
	void createActions();
	void createMenu();
	void createToolBars();
	void createStatusBar();

	QAction *exitAct;
	QAction *insertAct;
	QAction *newAct;
	QAction *openAct;
	QAction *saveAct;
	QAction *saveAsAct;

	QMenu *fileMenu;
	QMenu *editMenu;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;
};

#endif