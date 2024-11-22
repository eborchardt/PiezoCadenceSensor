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
    int maSize;
    volatile int count;
    unsigned long lastTime;
    unsigned long thisTime;
    int inter;
    int maValues[MA_SIZE];
    int maIndex;
};

#endif
