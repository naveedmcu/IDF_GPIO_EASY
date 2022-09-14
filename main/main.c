#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define LED GPIO_NUM_5

void app_main() {
    gpio_pad_select_gpio(LED);//选择一个GPIO
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);//把这个GPIO作为输出

    while (1)
    {
        gpio_set_level(LED, 0);//把这个GPIO输出低电平
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(LED, 1);//把这个GPIO输出高电平
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}