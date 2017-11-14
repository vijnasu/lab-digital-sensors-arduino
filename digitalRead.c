#include "stdio.h"
#include "unistd.h"
#include <signal.h>

#include "mraa.h"

#define PLATFORM_OFFSET 512
#define PIN 3 + PLATFORM_OFFSET

int running = 0;

void
sig_handler(int signo)
{
    if (signo == SIGINT) {
        printf("closing down nicely\n");
        running = -1;
    }
}

int
main(void)
{
    mraa_add_subplatform(MRAA_GROVEPI, "0");
    mraa_result_t r = MRAA_SUCCESS;

    mraa_init();
    fprintf(stdout, "MRAA Version: %s\nStarting Read on D3 (Ctrl+C to exit)\n", mraa_get_version());

    //! [Interesting]
    mraa_gpio_context gpio;

    gpio = mraa_gpio_init(PIN);

    mraa_gpio_dir(gpio, MRAA_GPIO_IN);

    signal(SIGINT, sig_handler);

    while (running == 0) {
        fprintf(stdout, "Gpio is %d\n", mraa_gpio_read(gpio));
        sleep(1);
    }

    r = mraa_gpio_close(gpio);
    //! [Interesting]
    if (r != MRAA_SUCCESS) {
        mraa_result_print(r);
    }

    return r;
}
