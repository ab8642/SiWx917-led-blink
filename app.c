#include "sl_si91x_driver_gpio.h"
#include "sl_sleeptimer.h"
#include "sl_gpio_board.h"

// Configure GPIO_10 (Port B, Pin 10) as output for external LED
static sl_si91x_gpio_pin_config_t gpio_config = {
  { SL_SI91X_GPIO_10_PORT, GPIO_PIN_NUMBER10 },
  GPIO_OUTPUT
};

#define TOGGLE_DELAY_MS 500

static sl_sleeptimer_timer_handle_t timer;
static volatile bool toggle_timeout = false;

static void on_timeout(sl_sleeptimer_timer_handle_t *handle, void *data)
{
  (void)handle;
  (void)data;
  toggle_timeout = true;
}

void app_init(void)
{
  sl_status_t status;

  // Initialize GPIO driver
  status = sl_gpio_driver_init();
  if (status != SL_STATUS_OK) {
    return;
  }

  // Configure pin as output
  status = sl_gpio_set_configuration(gpio_config);
  if (status != SL_STATUS_OK) {
    return;
  }

  // Start periodic sleep timer for blinking
  sl_sleeptimer_start_periodic_timer_ms(&timer,
                                        TOGGLE_DELAY_MS,
                                        on_timeout,
                                        NULL,
                                        0,
                                        SL_SLEEPTIMER_NO_HIGH_PRECISION_HF_CLOCKS_REQUIRED_FLAG);
}

void app_process_action(void)
{
  if (toggle_timeout == true) {
    sl_gpio_driver_toggle_pin(&gpio_config.port_pin);
    toggle_timeout = false;
  }
}
