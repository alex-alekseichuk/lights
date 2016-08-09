#include <cstring>
#include <cstdio>
#include "model.h"

void Model::_init()
{
    _frames.clear();
    _current = _frames.begin();
    _index = 0;
    _total = 0;
}

Model::Model()
{
    _init();
    emit currentFrameChanged();
}

void Model::blank()
{
    _init();
    addBlankFrame();
}

/*
static int counter = 0;
void Model::insertBlankFrame()
{
    Frame frame(0x00, 100);
    //Frame frame((++counter)%(1<<16), 100);
    _current = _frames.insert(_current, frame);
    _total++;
    emit currentFrameChanged();
}
*/

void Model::addBlankFrame()
{
    Frame frame(0x00, 100);
    if (hasFrames()) {
        _current++;
        _index++;
    }
    _current = _frames.insert(_current, frame);
    _total++;
    emit currentFrameChanged();
}

void Model::togglePin(int index) {
    if (!hasFrames())
        return;
    _current->togglePin(index);
    emit currentFrameChanged();
}

void Model::deleteCurrentFrame()
{
    if (!hasFrames())
        return;

    _current = _frames.erase(_current);
    if (_current == _frames.end() && _frames.begin() != _frames.end()) {

        _current--;
        _index--;
    }

    _total--;
    emit currentFrameChanged();
}

void Model::goFirst()
{
    if (!hasFrames())
        return;
    if (_current == _frames.begin())
        return;

    _current = _frames.begin();
    _index = 0;
    emit currentFrameChanged();
}

void Model::goPrev()
{
    if (!hasFrames())
        return;
    if (_current == _frames.begin())
        return;

    _current--;
    _index--;
    emit currentFrameChanged();
}

void Model::goNext()
{
    if (!hasFrames())
        return;
    Frames::iterator next = _current;
    if (++next == _frames.end())
        return;

    _current++;
    _index++;
    emit currentFrameChanged();
}

void Model::goLast()
{
    if (!hasFrames())
        return;
    Frames::iterator next = _current;
    if (++next == _frames.end())
        return;

    _current = _frames.end();
    _current--;
    _index = _total - 1;
    emit currentFrameChanged();
}

