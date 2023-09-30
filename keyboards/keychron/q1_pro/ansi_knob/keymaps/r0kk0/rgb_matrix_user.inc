#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

RGB_MATRIX_EFFECT(porcodio)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV porcodio_math(HSV hsv, uint16_t offset) {
#            ifdef RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
    hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
#            endif
    hsv.v = scale8(255 - offset, hsv.v);
    return hsv;
}

bool porcodio(effect_params_t* params) {
    return effect_runner_reactive(params, &porcodio_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED