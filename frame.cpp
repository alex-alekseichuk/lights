#include "frame.h"

Frame::Frame(unsigned int pins, unsigned int time)
    : _pins(pins), _time(time)
{
}

void Frame::togglePin(int index) {
    _pins ^= (1 << index);
}


