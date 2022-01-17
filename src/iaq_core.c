#include "iaq_core.h"

static const char* TAG = "iaq-core";

esp_err_t iaq_core_read(i2c_port_t i2c_port, sensor_reading_t* reading) {

    // Send the address byte
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, IAQ_CORE_SENSOR_ADDR << 1 | I2C_MASTER_READ, true);

    uint8_t buffer[8] = { 0 };
    i2c_master_read(cmd, (uint8_t*)&buffer, sizeof(buffer), I2C_MASTER_LAST_NACK);

    esp_err_t ret = i2c_master_cmd_begin(i2c_port, cmd, 1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);

    if (ret != ESP_OK) {
        return ret;
    }

    return ESP_OK;
}
