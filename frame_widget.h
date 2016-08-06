#ifndef __FRAME_WIDGET_H__
#define __FRAME_WIDGET_H__

#include <QtGlobal>

#if QT_VERSION >= 0x050000
#include <QtWidgets>
#else
#include <QtGui>
#endif

#include <QPoint>
#include "model.h"

class FrameWidget : public QWidget
{
public:
    FrameWidget(QWidget *parent = 0);
    static const int SIDE_SIZE = 4;
    static const int N_PARTS = 4;
public slots:
    void updateCurrentFrame(const Frame& frame);
protected:
    void paintEvent(QPaintEvent *event);
    void getCellsByIndex(const int index, QPoint cells[N_PARTS]);
};

#endif
