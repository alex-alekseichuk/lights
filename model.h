#ifndef __MODEL_H__
#define __MODEL_H__ 1

#include <list>
#include <QObject>
#include "frame.h"

typedef std::list<Frame> Frames;

class Model: public QObject {
    Q_OBJECT
public:
	Model();
    inline Frames::iterator current() {
        return _current;
    }
    inline bool hasFrames() {
        return _current != _frames.end();
    }
    inline int total() {
        return _total;
    }
    inline int index() {
        return _index;
    }

    void blank();
    void addBlankFrame();
    void deleteCurrentFrame();

    void togglePin(int index);

    void goFirst();
    void goPrev();
    void goNext();
    void goLast();

    void start();
    void stop();
signals:
   void currentFrameChanged();
private slots:
   void frameTimeout();
private:
    void _init();
    Frames _frames;
    Frames::iterator _current;
    int _total;
    int _index;
    bool _running;
};

#endif

