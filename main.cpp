#include <QtGlobal>
#if QT_VERSION >= 0x050000
    #include <QApplication>
#else
    #include <QtGui/QApplication>
#endif

#include <QPushButton>

#include "main_window.h"

int main(int argc, char** argv)
{
	Q_INIT_RESOURCE(app);
	QApplication app(argc, argv);

	MainWindow mainWindow;
	mainWindow.resize(500, 400);
	mainWindow.show();

	return app.exec();
}

