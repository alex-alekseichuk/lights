#ifndef __FRAME_WIDGET_H__
#define __FRAME_WIDGET_H__

#include <QtGlobal>

#if QT_VERSION >= 0x050000
#include <QtWidgets>
#else
#include <QtGui>
#endif

#include <QPoint>
#include "frame.h"
#include "model.h"

class FrameWidget : public QWidget
{
    Q_OBJECT
public:
    FrameWidget(Model& model, QWidget *parent = 0);
    static const int SIDE_SIZE = 4;
    static const int N_PARTS = 4;
public slots:
    void updateCurrentFrame();
protected:
    void paintEvent(QPaintEvent *event);
    void getCellsByIndex(const int index, QPoint cells[N_PARTS]);
private:
    Model& model;
};

#endif
