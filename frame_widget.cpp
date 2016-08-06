#include "frame_widget.h"

FrameWidget::FrameWidget(QWidget *parent)
    : QWidget(parent)
{
//    setAttribute(Qt::WA_StaticContents);
//    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
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
        getCellsByIndex(i, cells);
        for (int ic = 0; ic < N_PARTS; ++ic) {

            int x = x0 + (MARGIN + r) * cells[ic].x();
            int y = y0 + (MARGIN + r) * cells[ic].y();

            painter.setPen(Qt::black);
            painter.setBrush(Qt::NoBrush);

        //        painter.setPen(Qt::NoPen);
        //        painter.setBrush(Qt::red);

            painter.drawEllipse(x, y, r, r);

        }
    }

    /*
    if (zoom >= 3) {
        painter.setPen(palette().foreground().color());
        for (int i = 0; i <= image.width(); ++i)
            painter.drawLine(zoom * i, 0,
                    zoom * i, zoom * image.height());
        for (int j = 0; j <= image.height(); ++j)
            painter.drawLine(0, zoom * j,
                    zoom * image.width(), zoom * j);
    }
    for (int i = 0; i < image.width(); ++i) {
        for (int j = 0; j < image.height(); ++j) {
            QRect rect = pixelRect(i, j);
            if (!event->region().intersect(rect).isEmpty()) {
                QColor color = QColor::fromRgba(image.pixel(i, j));
                if (color.alpha() < 255)
                    painter.fillRect(rect, Qt::white);
                painter.fillRect(rect, color);
            }
        }
    }
    */
}

