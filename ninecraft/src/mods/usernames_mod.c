#include <ninecraft/version_ids.h>
#include <ninecraft/minecraft.h>
#include <ninecraft/mods/usernames_mod.h>

/*
    This mod enables usernames rendering
    in multiplayer games.
*/

void usernames_mod_inject(int version_id) { 
    if (version_id == version_id_0_6_1 || version_id == version_id_0_6_0) {
#if defined(__i386__) || defined(_M_IX86)
        *(short *)((char *)player_renderer_render_name + 50) = 0x9090;
#endif
#if defined(__arm__) || defined(_M_ARM) 
    *(short *)((char *)player_renderer_render_name + 23) = 0xbf00;
#endif
    } else if (version_id == version_id_0_5_0) {
#if defined(__i386__) || defined(_M_IX86)
        *(short *)((char *)player_renderer_render_name + 50) = 0x9090;
#endif
#if defined(__arm__) || defined(_M_ARM) 
    *(short *)((char *)player_renderer_render_name + 23) = 0xbf00;
#endif
    }
}