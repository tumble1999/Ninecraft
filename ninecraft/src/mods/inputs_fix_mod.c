#include <ninecraft/mods/inputs_fix_mod.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ninecraft/input/minecraft_keys.h>
#include <ninecraft/version_ids.h>
#include <ancmp/android_dlfcn.h>

/*
    This mod fixes input related issues
    for mcpe 0.5.0-0.10.5
*/

static void *_handle = NULL;
static int _version_id = version_id_unknown;

typedef struct {
    void **vtable;
    float h_pos;
    float v_pos;
    bool unknown0;
    bool is_jumping;
    bool is_sneaking;
    bool is_flying_up;
    bool is_flying_down;
    bool unknown5;
    bool forward_pressed;
    bool back_pressed;
    bool left_pressed;
    bool right_pressed;
    bool jump_pressed;
    bool sneak_pressed;
    bool crafting_pressed;
    bool unknown13;
    bool unknown14;
    bool unknown15;
    void *options;
} keyboard_input_0_6_0_t;

typedef struct {
    void **vtable;
    float h_pos;
    float v_pos;
    bool unknown0;
    bool is_jumping;
    bool is_sneaking;
    bool is_flying_up;
    bool is_flying_down;
    bool forward_pressed;
    bool back_pressed;
    bool left_pressed;
    bool right_pressed;
    bool jump_pressed;
    bool sneak_pressed;
    bool crafting_pressed;
    bool unknown13;
    bool unknown14;
    bool unknown15;
    void *options;
} keyboard_input_0_5_0_t;

typedef struct {
    void **vtable;
    float h_pos;
    float v_pos;
    bool unknown0;
    bool is_flying_up;
    bool is_flying_down;
    bool unknown5;
    bool is_jumping;
    bool unknown6;
    bool forward_pressed;
    bool back_pressed;
    bool left_pressed;
    bool right_pressed;
    bool jump_pressed;
    bool sneak_pressed;
    bool crafting_pressed;
    bool unknown13;
    bool unknown14;
    bool unknown15;
    void *options;
} keyboard_input_0_11_0_t;

typedef struct {
    void **vtable;
    float h_pos;
    float v_pos;
    bool unknown0;
    bool is_flying_up;
    bool is_flying_down;
    bool unknown5;
    bool is_jumping;
    bool unknown6;
    bool forward_pressed;
    bool back_pressed;
    bool left_pressed;
    bool right_pressed;
    bool jump_pressed;
    bool sneak_pressed;
    bool crafting_pressed;
    bool unknown13;
    bool unknown14;
    bool unknown15;
    void *options;
    void *unknown16;
    void *boat;
    bool unknown40;
    bool paddle_right;
    bool paddle_left;
    bool side_right;
    bool old_paddle_right;
    bool old_paddle_left;
    bool side_left;
} boat_input_0_11_0_t;

typedef union {
    keyboard_input_0_11_0_t v_0_11_0;
    keyboard_input_0_6_0_t v_0_6_0;
    keyboard_input_0_5_0_t v_0_5_0;
} keyboard_input_t;

void xperia_play_input_tick(keyboard_input_t *__this, void *player) {
    if (_version_id >= version_id_0_11_0 && _version_id <= version_id_0_11_1) {
        ((void (*)(keyboard_input_t *, void *))android_dlsym(_handle, "_ZN13KeyboardInput4tickER6Player"))(__this, player);
    } else {
        ((void (*)(keyboard_input_t *, void *))android_dlsym(_handle, "_ZN13KeyboardInput4tickEP6Player"))(__this, player);
    }
    bool *jump_pressed = NULL;
    bool *sneak_pressed = NULL;
    bool *is_flying_down = NULL;
    bool *is_flying_up = NULL;
    if (_version_id >= version_id_0_5_0 && _version_id <= version_id_0_5_0_j) {
        jump_pressed = &__this->v_0_5_0.jump_pressed;
        sneak_pressed = &__this->v_0_5_0.sneak_pressed;
        is_flying_down = &__this->v_0_5_0.is_flying_down;
        is_flying_up = &__this->v_0_5_0.is_flying_up;
    } else if (_version_id >= version_id_0_6_0 && _version_id <= version_id_0_10_5) {
        jump_pressed = &__this->v_0_6_0.jump_pressed;
        sneak_pressed = &__this->v_0_6_0.sneak_pressed;
        is_flying_down = &__this->v_0_6_0.is_flying_down;
        is_flying_up = &__this->v_0_6_0.is_flying_up;
    } else if (_version_id >= version_id_0_11_0 && _version_id <= version_id_0_11_1) {
        jump_pressed = &__this->v_0_11_0.jump_pressed;
        sneak_pressed = &__this->v_0_11_0.sneak_pressed;
        is_flying_down = &__this->v_0_11_0.is_flying_down;
        is_flying_up = &__this->v_0_11_0.is_flying_up;
    } else {
        return;
    }
    if (jump_pressed && sneak_pressed && is_flying_down && is_flying_up) {
        if (*jump_pressed) {
            *is_flying_up = true;
        } else {
            *is_flying_up = false;
        }
        if (*sneak_pressed) {
            if (_version_id >= version_id_0_11_0 && _version_id <= version_id_0_11_1) {
                ((void (*)(void *, bool))android_dlsym(_handle, "_ZN3Mob11setSneakingEb"))(player, true);
            }
            *is_flying_down = true;
        } else {
            if (_version_id >= version_id_0_11_0 && _version_id <= version_id_0_11_1) {
                ((void (*)(void *, bool))android_dlsym(_handle, "_ZN3Mob11setSneakingEb"))(player, false);
            }
            *is_flying_down = false;
        }
    }
}

void xperia_play_input_set_key(keyboard_input_t *__this, int id, bool state) {
    ((void (*)(keyboard_input_t *, int, bool))android_dlsym(_handle, "_ZN13KeyboardInput6setKeyEib"))(__this, id, state);
}

void boat_input_tick(boat_input_0_11_0_t *__this, void *player) {
    ((void (*)(boat_input_0_11_0_t *, void *))android_dlsym(_handle, "_ZN13KeyboardInput4tickER6Player"))(__this, player);
    __this->paddle_right = __this->right_pressed || __this->forward_pressed;
    __this->paddle_left = __this->left_pressed || __this->forward_pressed;
    __this->side_right = ((bool (*)(void *, int, bool, bool))android_dlsym(_handle, "_ZN4Boat14setPaddleStateE4Sidebb"))(__this->boat, 0, __this->paddle_right, __this->old_paddle_right);
    __this->side_left = ((bool (*)(void *, int, bool, bool))android_dlsym(_handle, "_ZN4Boat14setPaddleStateE4Sidebb"))(__this->boat, 1, __this->paddle_left, __this->old_paddle_left);
    __this->old_paddle_right = __this->paddle_right;
    __this->old_paddle_left = __this->paddle_left;
    __this->paddle_right = 0;
    __this->paddle_left = 0;
    __this->unknown5 = 0;
}

void inputs_fix_mod_inject(void *handle, int version_id) {
    _handle = handle;
    _version_id = version_id;
    if (version_id >= version_id_0_5_0 && version_id <= version_id_0_8_1) {
        ((void **)android_dlsym(handle, "_ZTV15XperiaPlayInput"))[4] = xperia_play_input_tick;
    } else if (version_id >= version_id_0_9_0 && version_id <= version_id_0_11_1) {
        ((void **)android_dlsym(handle, "_ZTV19ControllerMoveInput"))[4] = xperia_play_input_tick;
        ((void **)android_dlsym(handle, "_ZTV19ControllerMoveInput"))[6] = xperia_play_input_set_key;
    }
    if (_version_id >= version_id_0_11_0 && _version_id <= version_id_0_11_1) {
        ((void **)android_dlsym(handle, "_ZTV23BoatControllerMoveInput"))[4] = boat_input_tick;
        ((void **)android_dlsym(handle, "_ZTV23BoatControllerMoveInput"))[6] = xperia_play_input_set_key;
    }
}