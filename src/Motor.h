#ifndef MOTOR_H

#endif

struct MotorData{
    int rpm;

    double appsPos;
    double bspdPos;
    double wheelspeedFR;
    double wheelspeedFL;
    double wheelspeedRR;
    double wheelspeedRL;

};

class Motor {
private:
    void setSpeed(MotorData* mData);

public:
    Motor(/* args */);
    ~Motor();
};

