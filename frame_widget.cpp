#include "frame_widget.h"

FrameWidget::FrameWidget(Model& model, QWidget *parent)
    : QWidget(parent), model(model)
{
//    setAttribute(Qt::WA_StaticContents);
//    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    //connect(&model, SIGNAL(currentFrameChanged()), this, SLOT(updateCurrentFrame()));
    connect(&model, SIGNAL(currentFrameChanged()), this, SLOT(repaint()));
}

void FrameWidget::getCellsByIndex(const int index, QPoint cells[N_PARTS]) {
    int ix = 1 + (index % SIDE_SIZE);
    int iy = 1 + (index / SIDE_SIZE);

    cells[0].setX(SIDE_SIZE + ix - 1);
    cells[0].setY(SIDE_SIZE - iy);

    cells[1].setX(SIDE_SIZE - iy);
    cells[1].setY(SIDE_SIZE - ix);

    cells[2].setX(SIDE_SIZE - ix);
    cells[2].setY(SIDE_SIZE + iy - 1);

    cells[3].setX(SIDE_SIZE + iy - 1);
    cells[3].setY(SIDE_SIZE + ix - 1);
}

void FrameWidget::paintEvent(QPaintEvent *event)
{
    if (!model.hasFrames())
        return;

    int pins = model.current()->pins();

    QPainter painter(this);
    painter.setPen(palette().foreground().color());
    
    int width = size().width();
    int height = size().height();

    int len, x0, y0;
    if (width > height) {
        len = height;
        x0 = (width - height) / 2;
        y0 = 0;
    } else {
        len = width;
        x0 = 0;
        y0 = (height - width) / 2;
    }
    const int MARGIN = 3;
    int r = (len - MARGIN * (1 + 2 * SIDE_SIZE)) / (2 * SIDE_SIZE);

    int n = SIDE_SIZE * SIDE_SIZE;
    QPoint cells[N_PARTS];
    for (int i = 0; i < n; ++i) {
        bool on = (0 != (pins & (1 << i)));

        getCellsByIndex(i, cells);
        for (int ic = 0; ic < N_PARTS; ++ic) {

            int x = x0 + MARGIN + (MARGIN + r) * cells[ic].x();
            int y = y0 + MARGIN + (MARGIN + r) * cells[ic].y();

            if (on) {
                painter.setPen(Qt::NoPen);
                painter.setBrush(Qt::red);
            } else {
                painter.setPen(Qt::black);
                painter.setBrush(Qt::NoBrush);
            }


            painter.drawEllipse(x, y, r, r);

        }
    }

}

void FrameWidget::updateCurrentFrame(){
    repaint();
}

void FrameWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {

    }
}

