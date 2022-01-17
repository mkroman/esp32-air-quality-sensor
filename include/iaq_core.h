#ifndef IAQ_CORE_H
#define IAQ_CORE_H

#include <stdint.h>
#include <esp_log.h>
#include "driver/i2c.h"

#define IAQ_CORE_SENSOR_ADDR 0x5a

typedef struct sensor_reading {
    uint16_t pred;
    uint8_t status;
    int32_t resistance;
    uint16_t tvoc;
} sensor_reading_t;

esp_err_t iaq_core_read(i2c_port_t i2c_port, sensor_reading_t* reading);

#endif