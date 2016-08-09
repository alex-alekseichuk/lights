#include <cstring>
#include <cstdio>
#include <QTimer>
#include "model.h"

void Model::_init()
{
    _running = false;
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
    if (_running)
        return;
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
    if (_running)
        return;
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
    if (_running)
        return;
    if (!hasFrames())
        return;
    _current->togglePin(index);
    emit currentFrameChanged();
}

void Model::deleteCurrentFrame()
{
    if (_running)
        return;
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
    if (_running)
        return;
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
    if (_running)
        return;
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
    if (_running)
        return;
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
    if (_running)
        return;
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

void Model::frameTimeout() {
    if (!_running)
        return;

    if (++_current == _frames.end()) {
        _current = _frames.begin();
        _index = 0;
    } else {
        _index++;
    }
    emit currentFrameChanged();
    QTimer::singleShot(100, this, SLOT(frameTimeout()));
}

void Model::start() {
    if (_running)
        return;
    if (!hasFrames())
        return;

    _running = true;
    QTimer::singleShot(100, this, SLOT(frameTimeout()));
}
void Model::stop() {
    if (_running)
        _running = false;
}
