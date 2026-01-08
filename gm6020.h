#ifndef INCLUDED_rbms_H
#define INCLUDED_rbms_H

#include "mbed.h"


class gm6020{
    public:
        gm6020(CAN &can,bool motor_type,int motor_num);
        int rbms_send(int* moter);
        void rbms_read(CANMessage &msg, short *rotation,short *speed);
        void can_read();

        float pid(float T,short rpm_now, short set_speed,float *delta_rpm_pre,float *ie,float KP,float KI, float KD);

        void spd_control(int* set_speed,int* motor,float KP, float KI, float KD);
        
    private:

        CANMessage _canMessage,_canMessage2,_msg;
        CAN &_can;
        bool _ctrl_type;
        int _motor_num,_motor_max;
        unsigned short _r;
        int _rotation;
        int _speed;
        int _torque;
        int _temperature;
};


#endif