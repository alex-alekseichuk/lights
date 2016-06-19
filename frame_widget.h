#ifndef __FRAME_WIDGET_H__
#define __FRAME_WIDGET_H__

#include <QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets>
#else
#include <QtGui>
#endif

class FrameWidget : public QWidget
{
public:
    FrameWidget(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif
