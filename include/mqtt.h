#pragma once

#include "mqtt_client.h"

typedef struct mqtt_ctx {
    esp_mqtt_client_handle_t handle;
} mqtt_ctx_t;

void mqtt_init(mqtt_ctx_t * ctx);
