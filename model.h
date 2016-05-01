#ifndef __MODEL_H__
#define __MODEL_H__ 1

#include <list>

class Frame {
public:
	const static int N_POINTS = 16;
	Frame();
	Frame(const Frame& rhs);
	Frame& operator=(const Frame& rhs);
private:
	unsigned char points[N_POINTS];
};


class Model {
private:
	std::list<Frame> frames;
	std::list<Frame>::iterator current;
public:
	Model();
	void blank();
	void insertFrame();
};

#endif