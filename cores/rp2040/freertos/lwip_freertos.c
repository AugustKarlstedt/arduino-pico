// For FreeRTOS, we'll just use the NOSYS version because we already safely handle it
#ifdef __FREERTOS

#include "lwip/init.h"
#include "pico/async_context.h"

static bool done_lwip_init = false;

bool lwip_freertos_init(async_context_t *context) {
    if (!done_lwip_init) {
        lwip_init();
        done_lwip_init = true;
    }
    return true;
}
void lwip_freertos_deinit(__unused async_context_t *context) {
    if (done_lwip_init) {
        // deinit is called through the cyw43 driver, see cyw43_driver_freertos.cpp
        done_lwip_init = false;
    }
}
#endif
