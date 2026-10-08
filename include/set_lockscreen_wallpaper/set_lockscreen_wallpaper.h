#ifndef SET_LOCKSCREEN_WALLPAPER_H
#define SET_LOCKSCREEN_WALLPAPER_H


/* C23 标准已将 bool/true/false 收为内置关键字，因此按标准仅需在 C23 之前包含 stdbool.h。 */
#if !defined(__STDC_VERSION__) || (defined(__STDC_VERSION__) && __STDC_VERSION__ < 202311L)
#include <stdbool.h>
#endif


/**
 * @brief 设置锁屏壁纸（单张图片）。
 *
 * @param image_file_path[in] 目标图片路径（不支持相对路径）。
 *                            应使用系统代码页编码。
 *
 * @return 是否设置成功，设置成功返回 true，否则返回 false。
 */
bool set_lockscreen_wallpaper(const char *image_file_path);


#endif
