#ifndef FRAME_H
#define FRAME_H

class Frame {
public:
    Frame(unsigned short _pins, unsigned int _time);
private:
    unsigned short pins;
    unsigned int time; // ms
};

#endif // FRAME_H
