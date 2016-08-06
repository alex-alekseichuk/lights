#include <cstring>
#include <cstdio>
#include "model.h"


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

