#include <iostream>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


using namespace std;

#define DATA 16

void rising_edge(uint gpio, uint32_t events) {
    cout << "Rising Edge: " << to_ms_since_boot(get_absolute_time()) << endl;
}

void falling_edge(uint gpio, uint32_t events) {
    cout << "Falling Edge: " << to_ms_since_boot(get_absolute_time()) << endl;
}

int main() {
    stdio_init_all();
    gpio_init(DATA);
    gpio_set_dir(DATA, GPIO_IN);
    gpio_pull_up(DATA);

    while (!stdio_usb_connected()) {
    }
    cout << "--- Ready ---" << endl;

    gpio_set_irq_enabled_with_callback(DATA, GPIO_IRQ_EDGE_RISE, true, &rising_edge);
    gpio_set_irq_enabled_with_callback(DATA, GPIO_IRQ_EDGE_FALL, true, &falling_edge);

    for (;;) {
        sleep_ms(10000);
    }
}
