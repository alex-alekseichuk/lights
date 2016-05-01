#include <cstring>
#include <cstdio>
#include "model.h"

Frame::Frame() {

}

Frame::Frame(const Frame& rhs)
{
	memcpy(points, rhs.points, Frame::N_POINTS);
}

Frame& Frame::operator=(const Frame& rhs)
{
  if (this == &rhs)
    return *this;

  memcpy(points, rhs.points, Frame::N_POINTS);

  return *this;
}


Model::Model() {
	current = frames.begin();
}

void Model::blank() {
	frames.clear();
	current = frames.begin();
}

void Model::insertFrame() {
	Frame frame;
	current = frames.insert(current, frame);
}

