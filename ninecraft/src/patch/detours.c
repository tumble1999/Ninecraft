#include <ninecraft/patch/detours.h>
#include <stdint.h>
#include <string.h>

void detour_disarm(detour_backup_t backup) {
    memcpy(backup.addr, backup.original, backup.len);
#if !defined(_MSC_VER) && (defined(__arm__) || defined(_M_ARM))
    __builtin___clear_cache((char *)backup.addr, (char *)backup.addr + backup.len);
#endif
}

void detour_rearm(detour_backup_t backup) {
    memcpy(backup.addr, backup.detour, backup.len);
#if !defined(_MSC_VER) && (defined(__arm__) || defined(_M_ARM))
    __builtin___clear_cache((char *)backup.addr, (char *)backup.addr + backup.len);
#endif
}

detour_backup_t arm_detour(void *target_addr, void *replacement_addr) {
    detour_backup_t backup;
    backup.len = 8;
    if ((uintptr_t)target_addr & 1) {
        uintptr_t addr = (uintptr_t)target_addr & ~1;
        backup.addr = (void *)addr;
        memcpy(backup.original, (void *)addr, 8);
        *(uint16_t *)addr = 0xF8DF;
        if (addr % 4 != 0) {
            *(uint16_t *)(addr + 2) = 0xF002;
        } else {
            *(uint16_t *)(addr + 2) = 0xF000;
        }
        *(uint32_t *)(addr + 4) = (uintptr_t)replacement_addr;
        memcpy(backup.detour, (void *)addr, 8);
    } else {
        backup.addr = target_addr;
        memcpy(backup.original, target_addr, 8);
        *(uint32_t *)target_addr = 0xe51ff004;
        *(uint32_t *)((char *)target_addr + 4) = (uint32_t)replacement_addr;
        memcpy(backup.detour, target_addr, 8);
    }
#if !defined(_MSC_VER) && (defined(__arm__) || defined(_M_ARM))
    __builtin___clear_cache((char *)backup.addr, (char *)backup.addr + backup.len);
#endif
    return backup;
}

detour_backup_t x86_detour(void *target_addr, void *replacement_addr, bool jump) {
    detour_backup_t backup;
    backup.len = 5;
    backup.addr = target_addr;
    memcpy(backup.original, target_addr, 5);
    *(uint8_t *)target_addr = jump ? 0xe9 : 0xe8;
    *(uint32_t *)((uintptr_t)target_addr + 1) = (uintptr_t)replacement_addr - (uintptr_t)target_addr - 5;
    memcpy(backup.detour, target_addr, 5);
    return backup;
}