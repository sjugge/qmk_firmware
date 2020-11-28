/* Declaration of custom effects using the RGB_MATRIX_EFFECT macro
⚠ (note the lack of semicolon after the macro!) */
RGB_MATRIX_EFFECT(sjugge_tne_orange)
RGB_MATRIX_EFFECT(sjugge_tne_blue)
RGB_MATRIX_EFFECT(sjugge_tne_aqua)
RGB_MATRIX_EFFECT(sjugge_tne_green)
RGB_MATRIX_EFFECT(sjugge_carbon_beige)

RGB_MATRIX_EFFECT(HUE_BREATHING)
RGB_MATRIX_EFFECT(HUE_PENDULUM)
RGB_MATRIX_EFFECT(HUE_WAVE)

/* Start custom effect definitions */
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// TNE Orange
static bool sjugge_tne_orange(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color_all(135, 45, 0);
  }
  return led_max < DRIVER_LED_TOTAL;
}

// TNE Blue
static bool sjugge_tne_blue(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color_all(0, 100, 150);
  }
  return led_max < DRIVER_LED_TOTAL;
}

// TNE Aqua
static bool sjugge_tne_aqua(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color_all(20, 100, 100);
  }
  return led_max < DRIVER_LED_TOTAL;
}

// TNE Green
static bool sjugge_tne_green(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color_all(20, 75, 20);
  }
  return led_max < DRIVER_LED_TOTAL;
}

// Carbon beige
static bool sjugge_carbon_beige(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color_all(75, 65, 25);
  }
  return led_max < DRIVER_LED_TOTAL;
}

// START HEU_BREATHING (sourced from https://www.reddit.com/r/olkb/comments/hxtuf7 | https://github.com/qmk/qmk_firmware/pull/9827)
//Change huedelta to adjust range of hue change. 0-255 I think.
//Hue Breathing - All LED's light up
bool HUE_BREATHING(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
	uint8_t huedelta = 12;
    HSV      hsv  = rgb_matrix_config.hsv;
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    hsv.h         = hsv.h + scale8(abs8(sin8(time) - 128) * 2, huedelta);
    RGB rgb       = hsv_to_rgb(hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

//Change huedelta to adjust range of hue change. 0-255 I think. Looks better with a low value and slow speed for subtle change.
//Hue Pendulum - color changes in a wave to the right before reversing direction
static HSV HUE_PENDULUM_math(HSV hsv, uint8_t i, uint8_t time) {
	uint8_t huedelta = 12;
    hsv.h = hsv.h + scale8(abs8(sin8(time) + (g_led_config.point[i].x) - 128) * 2, huedelta);
    return hsv;
}

bool HUE_PENDULUM(effect_params_t* params) { return effect_runner_i(params, &HUE_PENDULUM_math); }

//Change huedelta to adjust range of hue change. 0-255 I think. Looks better with a low value and slow speed for subtle change.
//Hue Wave - color changes in a wave to the right
static HSV HUE_WAVE_math(HSV hsv, uint8_t i, uint8_t time) {
	uint8_t huedelta = 24;
	 hsv.h = hsv.h + scale8(abs8(g_led_config.point[i].x - time), huedelta);
    return hsv;
}

bool HUE_WAVE(effect_params_t* params) { return effect_runner_i(params, &HUE_WAVE_math); }
// END HEU_BREATHING


#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
