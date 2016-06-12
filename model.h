#ifndef __MODEL_H__
#define __MODEL_H__ 1

#include <vector>

class Frame {
public:
	Frame(unsigned short _pins, unsigned int _time);
    
private:
	unsigned short pins;
    unsigned int time; // ms
};

typedef std::vector<Frame> Frames;

class Model {
public:
	Model();
	void blank();
	void insertFrame();
private:
    Frames frames;
	Frames::iterator current;
};

#endif
