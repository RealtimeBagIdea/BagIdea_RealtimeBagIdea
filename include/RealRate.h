#ifndef REALRATE_H
#define REALRATE_H


class RealRate
{
    private:
    int startTicks;

    public:
    RealRate();
    void frameRate(int rate);
    void start();
    int get_ticks();
};

#endif // REALRATE_H
