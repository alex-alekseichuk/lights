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
signals:
   void currenFrameChanged(const Frame& frame);
private:
    Frames frames;
	Frames::iterator current;
};

#endif

