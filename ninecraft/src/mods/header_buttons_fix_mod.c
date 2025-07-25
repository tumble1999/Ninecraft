#include <ninecraft/mods/header_buttons_fix_mod.h>
#include <ancmp/android_dlfcn.h>
#include <ninecraft/version_ids.h>
#include <ninecraft/patch/patch_address.h>

/*
    This mod fixes the missing menu buttons issue
    for mcpe 0.9.0-0.10.5
*/

#if defined(__i386__) || defined(_M_IX86)

#define INST_PATCH "\x90\x90"
#define OFFSET_FOR_0_9_0 79
#define OFFSET_FOR_0_9_1 79
#define OFFSET_FOR_0_9_2 79
#define OFFSET_FOR_0_9_3 79
#define OFFSET_FOR_0_9_4 79
#define OFFSET_FOR_0_9_5 79
#define OFFSET_FOR_0_10_0 79
#define OFFSET_FOR_0_10_1 79
#define OFFSET_FOR_0_10_2 79
#define OFFSET_FOR_0_10_3 79
#define OFFSET_FOR_0_10_4 79
#define OFFSET_FOR_0_10_5 76
#define OFFSET_FOR_0_11_0 72
#define OFFSET_FOR_0_11_1 72

#else
#if defined(__arm__) || defined(_M_ARM) 

#define INST_PATCH "\x01\x20"
#define OFFSET_FOR_0_9_0 41
#define OFFSET_FOR_0_9_1 41
#define OFFSET_FOR_0_9_2 41
#define OFFSET_FOR_0_9_3 41
#define OFFSET_FOR_0_9_4 41
#define OFFSET_FOR_0_9_5 41
#define OFFSET_FOR_0_10_0 41
#define OFFSET_FOR_0_10_1 41
#define OFFSET_FOR_0_10_2 41
#define OFFSET_FOR_0_10_3 41
#define OFFSET_FOR_0_10_4 41
#define OFFSET_FOR_0_10_5 41
#define OFFSET_FOR_0_11_0 41
#define OFFSET_FOR_0_11_1 41

#endif
#endif

void header_buttons_fix_mod_inject(void *handle, int version_id) {
    if (version_id >= version_id_0_9_0 && version_id <= version_id_0_11_1) {
        char *play_screen_reset_base_buttons = (char *)android_dlsym(handle, "_ZN10PlayScreen16resetBaseButtonsEv");
        if (play_screen_reset_base_buttons) {
            if (version_id == version_id_0_9_0) {
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_9_0, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
            } else if (version_id == version_id_0_9_1) {
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_9_1, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
            } else if (version_id == version_id_0_9_2) {
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_9_2, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
            } else if (version_id == version_id_0_9_3) {
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_9_3, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
            } else if (version_id == version_id_0_9_4) {
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_9_4, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
            } else if (version_id == version_id_0_9_5) {
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_9_5, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
            } else if (version_id == version_id_0_10_0) {
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_10_0, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
            } else if (version_id == version_id_0_10_1) {
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_10_1, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
            } else if (version_id == version_id_0_10_2) {
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_10_2, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
            } else if (version_id == version_id_0_10_3) {
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_10_3, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
            } else if (version_id == version_id_0_10_4) {
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_10_4, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
            } else if (version_id == version_id_0_10_5) {
#if defined(__i386__) || defined(_M_IX86)
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_10_5, "\xeb", 1, PATCH_ADDRESS_PROT_XR);
#else
#if defined(__arm__) || defined(_M_ARM)
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_10_5, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
#endif
#endif
            } else if (version_id == version_id_0_11_0) {
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_11_0, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
            } else if (version_id == version_id_0_11_1) {
#if defined(__i386__) || defined(_M_IX86)
                if (*(int *)play_screen_reset_base_buttons == 0x57E58955) {
                    patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_11_1, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
                } else {
                    patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_11_1, "\xeb", 1, PATCH_ADDRESS_PROT_XR);
                }
#else
#if defined(__arm__) || defined(_M_ARM)
                patch_address(play_screen_reset_base_buttons + OFFSET_FOR_0_11_1, INST_PATCH, 2, PATCH_ADDRESS_PROT_XR);
#endif
#endif
            }
        }
    }
}
