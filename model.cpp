#include <cstring>
#include <cstdio>
#include "model.h"

Frame::Frame(unsigned short _pins, unsigned int _time)
    : pins(_pins), time(_time)
{
}


Model::Model()
{
	current = frames.begin();
}

void Model::blank()
{
	frames.clear();
	current = frames.begin();

    insertBlankFrame();
}

void Model::insertBlankFrame()
{
	Frame frame(0x00, 100);
	current = frames.insert(current, frame);
}

