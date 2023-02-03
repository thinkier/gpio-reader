#include <iostream>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


using namespace std;

#define DATA 16

int main() {
    stdio_init_all();
    gpio_init(DATA);
    gpio_set_dir(DATA, GPIO_IN);
    gpio_pull_up(DATA);

    while (!stdio_usb_connected()) {
    }
    cout << "--- Ready ---" << endl;

    for (;;) {
        // todo read gpio with precise timing
    }
}
