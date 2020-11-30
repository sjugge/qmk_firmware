/* Declaration of custom effects using the RGB_MATRIX_EFFECT macro
⚠ (note the lack of semicolon after the macro!) */
RGB_MATRIX_EFFECT(sjugge_tne_orange)
RGB_MATRIX_EFFECT(sjugge_tne_blue)
RGB_MATRIX_EFFECT(sjugge_tne_aqua)
RGB_MATRIX_EFFECT(sjugge_tne_green)

RGB_MATRIX_EFFECT(sjugge_carbon_beige)
RGB_MATRIX_EFFECT(sjugge_carbon_escape)
RGB_MATRIX_EFFECT(sjugge_alt_brownish)

RGB_MATRIX_EFFECT(HUE_BREATHING_0)
RGB_MATRIX_EFFECT(HUE_BREATHING_1)
RGB_MATRIX_EFFECT(HUE_BREATHING_2)
RGB_MATRIX_EFFECT(HUE_BREATHING_3)

RGB_MATRIX_EFFECT(HUE_PENDULUM_0)
RGB_MATRIX_EFFECT(HUE_PENDULUM_1)
RGB_MATRIX_EFFECT(HUE_PENDULUM_2)
RGB_MATRIX_EFFECT(HUE_PENDULUM_3)
RGB_MATRIX_EFFECT(HUE_PENDULUM_4)
RGB_MATRIX_EFFECT(HUE_PENDULUM_5)

RGB_MATRIX_EFFECT(HUE_WAVE_0)
RGB_MATRIX_EFFECT(HUE_WAVE_1)
RGB_MATRIX_EFFECT(HUE_WAVE_2)
RGB_MATRIX_EFFECT(HUE_WAVE_3)
RGB_MATRIX_EFFECT(HUE_WAVE_4)
RGB_MATRIX_EFFECT(HUE_WAVE_5)

/* Start custom effect definitions */
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

    /* TNE static colors */

    // TNE Orange
    static bool sjugge_tne_orange(effect_params_t* params) {
      RGB_MATRIX_USE_LIMITS(led_min, led_max);
      for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, 135, 45, 0);
      }
      return led_max < DRIVER_LED_TOTAL;
    }

    // TNE Blue
    static bool sjugge_tne_blue(effect_params_t* params) {
      RGB_MATRIX_USE_LIMITS(led_min, led_max);
      for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, 0, 100, 150);
      }
      return led_max < DRIVER_LED_TOTAL;
    }

    // TNE Aqua
    static bool sjugge_tne_aqua(effect_params_t* params) {
      RGB_MATRIX_USE_LIMITS(led_min, led_max);
      for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, 20, 100, 100);
      }
      return led_max < DRIVER_LED_TOTAL;
    }

    // TNE Green
    static bool sjugge_tne_green(effect_params_t* params) {
      RGB_MATRIX_USE_LIMITS(led_min, led_max);
      for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, 20, 75, 20);
      }
      return led_max < DRIVER_LED_TOTAL;
    }

    /* Other static colors */

    // Carbon beige
    static bool sjugge_carbon_beige(effect_params_t* params) {
      RGB_MATRIX_USE_LIMITS(led_min, led_max);
      for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, 75, 65, 25);
      }
      return led_max < DRIVER_LED_TOTAL;
    }

    // Carbon escape
    static bool sjugge_carbon_escape(effect_params_t* params) {
      RGB_MATRIX_USE_LIMITS(led_min, led_max);
      for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 20, 0, 0);
      }
      return led_max < DRIVER_LED_TOTAL;
    }

    // Alt brownish
    static bool sjugge_alt_brownish(effect_params_t* params) {
      RGB_MATRIX_USE_LIMITS(led_min, led_max);
      for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 30, 10, 0);
      }
      return led_max < DRIVER_LED_TOTAL;
    }

    /* Hue breathing */

    // Hue Breathing 0
    bool HUE_BREATHING_0(effect_params_t* params) {
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

    // Hue Breathing 1
    bool HUE_BREATHING_1(effect_params_t* params) {
        RGB_MATRIX_USE_LIMITS(led_min, led_max);
        uint8_t huedelta = 96;
        HSV      hsv  = rgb_matrix_config.hsv;
        uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
        hsv.h         = hsv.h + scale8(abs8(sin8(time) - 32) * 2, huedelta);
        RGB rgb       = hsv_to_rgb(hsv);
        for (uint8_t i = led_min; i < led_max; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        return led_max < DRIVER_LED_TOTAL;
    }

    // Hue Breathing 2
    bool HUE_BREATHING_2(effect_params_t* params) {
        RGB_MATRIX_USE_LIMITS(led_min, led_max);
        uint8_t huedelta = 128;
        HSV      hsv  = rgb_matrix_config.hsv;
        uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
        hsv.h         = hsv.h + scale8(abs8(sin8(time) - 16) * 2, huedelta);
        RGB rgb       = hsv_to_rgb(hsv);
        for (uint8_t i = led_min; i < led_max; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        return led_max < DRIVER_LED_TOTAL;
    }

    // Hue Breathing 3
    bool HUE_BREATHING_3(effect_params_t* params) {
        RGB_MATRIX_USE_LIMITS(led_min, led_max);
        uint8_t huedelta = 128;
        HSV      hsv  = rgb_matrix_config.hsv;
        uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
        hsv.h         = hsv.h + scale8(abs8(sin8(time) - 8) * 2, huedelta);
        RGB rgb       = hsv_to_rgb(hsv);
        for (uint8_t i = led_min; i < led_max; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        return led_max < DRIVER_LED_TOTAL;
    }

    /* Hue pendulums */

    // Hue Pendulum 0
    static HSV HUE_PENDULUM_math_0(HSV hsv, uint8_t i, uint8_t time) {
        uint8_t huedelta = 12;
        hsv.h = hsv.h + scale8(abs8(sin8(time) + (g_led_config.point[i].x) - 128) * 2, huedelta);
        return hsv;
    }

    bool HUE_PENDULUM_0(effect_params_t* params) { return effect_runner_i(params, &HUE_PENDULUM_math_0); }

    // Hue Pendulum 1
    static HSV HUE_PENDULUM_math_1(HSV hsv, uint8_t i, uint8_t time) {
        uint8_t huedelta = 18;
        hsv.h = hsv.h + scale8(abs8(sin8(time) + (g_led_config.point[i].x) - 96) * 2, huedelta);
        return hsv;
    }

    bool HUE_PENDULUM_1(effect_params_t* params) { return effect_runner_i(params, &HUE_PENDULUM_math_1); }

    //Hue Pendulum 2
    static HSV HUE_PENDULUM_math_2(HSV hsv, uint8_t i, uint8_t time) {
        uint8_t huedelta = 48;
        hsv.h = hsv.h + scale8(abs8(sin8(time) + (g_led_config.point[i].x) - 64) * 2, huedelta);
        return hsv;
    }

    bool HUE_PENDULUM_2(effect_params_t* params) { return effect_runner_i(params, &HUE_PENDULUM_math_2); }

    //Hue Pendulum 3
    static HSV HUE_PENDULUM_math_3(HSV hsv, uint8_t i, uint8_t time) {
        uint8_t huedelta = 96;
        hsv.h = hsv.h + scale8(abs8(sin8(time) + (g_led_config.point[i].x) - 32) * 2, huedelta);
        return hsv;
    }

    bool HUE_PENDULUM_3(effect_params_t* params) { return effect_runner_i(params, &HUE_PENDULUM_math_3); }

    //Hue Pendulum 4
    static HSV HUE_PENDULUM_math_4(HSV hsv, uint8_t i, uint8_t time) {
        uint8_t huedelta = 128;
        hsv.h = hsv.h + scale8(abs8(sin8(time) + (g_led_config.point[i].x) - 16) * 1, huedelta);
        return hsv;
    }

    bool HUE_PENDULUM_4(effect_params_t* params) { return effect_runner_i(params, &HUE_PENDULUM_math_4); }

    //Hue Pendulum 5
    static HSV HUE_PENDULUM_math_5(HSV hsv, uint8_t i, uint8_t time) {
        uint8_t huedelta = 128;
        hsv.h = hsv.h + scale8(abs8(sin8(time) + (g_led_config.point[i].x) - 8) * 2, huedelta);
        return hsv;
    }

    bool HUE_PENDULUM_5(effect_params_t* params) { return effect_runner_i(params, &HUE_PENDULUM_math_5); }

    /* Hue waves */

    // Hue Wave 0
    static HSV HUE_WAVE_math_0(HSV hsv, uint8_t i, uint8_t time) {
        uint8_t huedelta = 12;
        hsv.h = hsv.h + scale8(abs8(g_led_config.point[i].x - time), huedelta);
        return hsv;
    }

    bool HUE_WAVE_0(effect_params_t* params) { return effect_runner_i(params, &HUE_WAVE_math_0); }

    // Hue Wave 1
    static HSV HUE_WAVE_math_1(HSV hsv, uint8_t i, uint8_t time) {
        uint8_t huedelta = 24;
        hsv.h = hsv.h + scale8(abs8(g_led_config.point[i].x - time), huedelta);
        return hsv;
    }

    bool HUE_WAVE_1(effect_params_t* params) { return effect_runner_i(params, &HUE_WAVE_math_1); }

    // Hue Wave 2
    static HSV HUE_WAVE_math_2(HSV hsv, uint8_t i, uint8_t time) {
        uint8_t huedelta = 48;
        hsv.h = hsv.h + scale8(abs8(g_led_config.point[i].x - time), huedelta);
        return hsv;
    }

    bool HUE_WAVE_2(effect_params_t* params) { return effect_runner_i(params, &HUE_WAVE_math_2); }

    // Hue Wave 3
    static HSV HUE_WAVE_math_3(HSV hsv, uint8_t i, uint8_t time) {
        uint8_t huedelta = 96;
        hsv.h = hsv.h + scale8(abs8(g_led_config.point[i].x - time), huedelta);
        return hsv;
    }

    bool HUE_WAVE_3(effect_params_t* params) { return effect_runner_i(params, &HUE_WAVE_math_3); }

    // Hue Wave 4
    static HSV HUE_WAVE_math_4(HSV hsv, uint8_t i, uint8_t time) {
        uint8_t huedelta = 128;
        hsv.h = hsv.h + scale8(abs8(g_led_config.point[i].x - time), huedelta);
        return hsv;
    }

    bool HUE_WAVE_4(effect_params_t* params) { return effect_runner_i(params, &HUE_WAVE_math_4); }

    // Hue Wave 5
    static HSV HUE_WAVE_math_5(HSV hsv, uint8_t i, uint8_t time) {
        uint8_t huedelta = 128;
        hsv.h = hsv.h + scale8(abs8(g_led_config.point[i].x - time), huedelta);
        return hsv;
    }

    bool HUE_WAVE_5(effect_params_t* params) { return effect_runner_i(params, &HUE_WAVE_math_5); }

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
