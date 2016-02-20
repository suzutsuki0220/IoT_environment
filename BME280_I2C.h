#ifndef __BME280_I2C_H__
#define __BME280_I2C_H__

#include <stdint.h>
#include "i2c_access.h"

class BME280_I2C {
private:
    i2c_access *i2c;

    /* calibration data */
    uint16_t dig_T1;
    int16_t dig_T2;
    int16_t dig_T3;
    uint16_t dig_P1;
    int16_t dig_P2;
    int16_t dig_P3;
    int16_t dig_P4;
    int16_t dig_P5;
    int16_t dig_P6;
    int16_t dig_P7;
    int16_t dig_P8;
    int16_t dig_P9;
    int8_t  dig_H1;
    int16_t dig_H2;
    int8_t  dig_H3;
    int16_t dig_H4;
    int16_t dig_H5;
    int8_t  dig_H6;
    signed long int t_fine;

    signed   long int calibration_T(signed long int adc_T);
    unsigned long int calibration_P(signed long int adc_P);
    unsigned long int calibration_H(signed long int adc_H);

    void getCalibration(void);
    void setup(void);

public:
    BME280_I2C();
    ~BME280_I2C();

    void init(const unsigned int slot, const unsigned int chipaddr);
    double getTemperature(void);
    double getHumidity(void);
    double getPressure(void);
};

#endif  // __BME280_I2C_H__
