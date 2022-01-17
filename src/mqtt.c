#include "esp_log.h"

#include "mqtt.h"

static const char* TAG = "mqtt";

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);

void mqtt_init(mqtt_ctx_t * ctx) {
    ESP_LOGI(TAG, "using username %s", CONFIG_MQTT_USER);

    const esp_mqtt_client_config_t mqtt_cfg = {
        .uri = CONFIG_MQTT_URL,
        #ifdef CONFIG_MQTT_USER
        .username = CONFIG_MQTT_USER,
        #endif
        #ifdef CONFIG_MQTT_PASS
        .password = CONFIG_MQTT_PASS
        #endif
    };

    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, client);
    esp_mqtt_client_start(client);

    ctx->handle = client;
}

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data) {
    ESP_LOGI(TAG, "Event dispatched from event loop base=%s, event_id=%d", base, event_id);
}