#ifndef FRAME_H
#define FRAME_H

class Frame {
public:
    Frame(unsigned int pins, unsigned int time);
    inline int pins() {return _pins;}
    inline int time() {return _time;}
private:
    unsigned int _pins;
    unsigned int _time; // ms
};

#endif // FRAME_H
