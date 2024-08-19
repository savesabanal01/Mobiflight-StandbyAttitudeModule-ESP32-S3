#pragma once

#include "Arduino.h"

class StandbyAttitudeModule
{
public:
    StandbyAttitudeModule(uint8_t Pin1, uint8_t Pin2);
    void begin();
    void attach(uint16_t Pin3, char *init);
    void detach();
    void set(int16_t messageID, char *setPoint);
    void update();

private:
    bool    _initialised;
    uint8_t _pin1, _pin2, _pin3;
    float pitch = 0;
    float roll = 0;
    float newRoll = 0;
    float pitchPosition = 0;
    float newPitch = 0;
    float slipAngle = 0; // slip angle value from sim
    float airSpeed = 0;  // Air speed value from the sim
    double altitude = 0;  // Altitude Value from the simulator
    float heading = 0;    // heading value from sim
    float baro = 0;       // baro value from sim
    float instrumentBrightnessRatio = 0.75;       // baro value from sim
    float instrumentBrightness = 192;
    int screenRotation = 3;
    int prevScreenRotation = 3;


    // Function declarations
    float scaleValue(float x, float in_min, float in_max, float out_min, float out_max);
    void drawAll();
    void drawPitchScale(float pitch);
    void drawBall();
    void drawAttitudeIndicator();
    void drawSpeedIndicator();
    void drawAltitudeIndicator();
    void drawSpeedIndicatorLines();
    void drawSpeedIndicatorValues();
    void drawAltitudeIndicatorLines();
    void drawAltitudeIndicatorValues();
    void setAirSpeed(float value);
    void setPitch(float value);
    void setRoll(float value);
    void setSlipAngle(float value);
    void setAltitude(float value);
    void setHeading(float value);
    void setBaro(float value);
    void setInstrumentBrightness(float value);
    void setScreenRotation(int rotation);
};