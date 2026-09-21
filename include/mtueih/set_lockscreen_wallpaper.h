#ifndef SET_LOCKSCREEN_WALLPAPER_H
#define SET_LOCKSCREEN_WALLPAPER_H

#include <stdbool.h>

#ifdef __cplusplus
namespace mtueih
{
	extern "C"
	{
#endif

		/**
		 * @brief 设置锁屏壁纸（单张图片）。
		 *
		 * @param[in] image_file_path
		 * 目标图片文件路径（const char * 类型字符串，应使用系统代码页编码）。
		 *
		 * @return
		 * 是否设置成功，设置成功返回 true，否则返回 false。
		 */
		bool set_lockscreen_wallpaper(const char *image_file_path);

#ifdef __cplusplus
	}
}
#endif

#endif
