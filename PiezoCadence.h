#ifndef PiezoCadence_h
#define PiezoCadence_h

class PiezoCadence {
  public:
    PiezoCadence(int pin, int threshold = 400, int maSize = 5);
    void begin();
    int getCadence();
  private:
    int _pin;
    int _threshold;
    int _maSize;
};

#endif
