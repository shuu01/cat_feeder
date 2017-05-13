#include <Stepper.h>
#include <TimeAlarms.h> // https://github.com/PaulStoffregen/TimeAlarms & https://github.com/PaulStoffregen/Time
#include <RTClib.h> // https://github.com/adafruit/RTClib

#define STEPS 64

Stepper stepper(STEPS, 9, 8, 7, 6);
RTC_DS1307 rtc;

uint32_t sync_provider()
{
    /// sync provider for timelib sychronization
    return rtc.now().unixtime();
}

void feed()
{
    stepper.step(1024);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
}

void setup() 
{
    /// rtc setup
    rtc.begin();
    // uncomment this line at first upload to set current ds1307 date & time
    // then comment it, build and upload sketch again
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    /// timelib setup
    setSyncProvider(sync_provider);
    setSyncInterval(86400); 
    /// stepper setup
    stepper.setSpeed(15);
    /// timealarms
    Alarm.alarmRepeat(6, 30, 0, feed);
    Alarm.alarmRepeat(10, 30, 0, feed);
    Alarm.alarmRepeat(14, 30, 0, feed);
    Alarm.alarmRepeat(18, 30, 0, feed);
    Alarm.alarmRepeat(23, 00, 0, feed);

}

void loop()
{
    Alarm.delay(0);
}
