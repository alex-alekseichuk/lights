#include <cstring>
#include <cstdio>
#include "model.h"


Model::Model()
{
    _current = _frames.end();
    emit currentFrameChanged();
}

void Model::blank()
{
    _frames.clear();
    _current = _frames.begin();
    insertBlankFrame();
}

static int counter = 0;
void Model::insertBlankFrame()
{
//    Frame frame(0x00, 100);
    Frame frame((++counter)%(1<<16), 100);
    _current = _frames.insert(_current, frame);
    emit currentFrameChanged();
}

void Model::togglePin(int index) {
    if (!hasFrames())
        return;
    _current->togglePin(index);
    emit currentFrameChanged();
}
