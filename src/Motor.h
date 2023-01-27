#ifndef MOTOR_H

#endif

struct MotorData{
    int rpm;

    double appsPos;
    double bspdPos;

};

class Motor {
private:
    void setSpeed(MotorData* mData);

public:
    Motor(/* args */);
    ~Motor();
};

