#ifndef PiezoCadence_h
#define PiezoCadence_h

class PiezoCadence {
  public:
    PiezoCadence(int pin, int threshold = 400, int maSize = 5);
    void begin();
    int getCadence();
  private:
    void stepDetection();
    int _pin;
    int _threshold;
    int _maSize;
    volatile int _count;
    unsigned long _lastTime;
    unsigned long _thisTime;
    int _inter;
    int _maValues[MA_SIZE];
    int _maIndex;
};

#endif
