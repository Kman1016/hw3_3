#include "mbed.h"
#include "accelerometer.h"
#include "gyro.h"
#include <cstdio>

static BufferedSerial pc(USBTX, USBRX);
Accelerometer acc;
Thread thread1, thread2;
// main() runs in its own thread in the OS
double Accel[3]={0};
bool start;
void record(void) {
    if (pc.readable()) {
        char buf;
        pc.read(&buf, sizeof(buf));
        if (buf == '1')
            start = 1;
        else
            start = 0;
    }
    if (start) {
        for (int i = 0; i < 128; i++) {
            acc.GetAcceleromterSensor(Accel);
            acc.GetAcceleromterCalibratedData(Accel);
            ThisThread::sleep_for(5ms);
            printf("%g\n", Accel[0]);
            printf("%g\n", Accel[1]);
            printf("%g\n", Accel[2]);
            //printf("----------");
        }
        start = 0;
    }
}

int main()
{
    while (true) {
        record();
    }
}

