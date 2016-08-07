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
	void blank();
	void insertBlankFrame();
    inline Frames::iterator current() {
        return _current;
    }
    inline bool hasFrames() {
        return _current != _frames.end();
    }
signals:
   void currenFrameChanged();
private:
    Frames _frames;
    Frames::iterator _current;
};

#endif

