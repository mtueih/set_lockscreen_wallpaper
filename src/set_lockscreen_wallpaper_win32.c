#include "set_lockscreen_wallpaper/set_lockscreen_wallpaper.h"

#include <stdlib.h>
#include <string.h>


#ifndef NDEBUG

#include <stdio.h>

#define PUT_ERR(err_msg) fprintf(stderr, "[%s:%d] %s: %s\n", __FILE__, __LINE__, __func__, err_msg)
#define PUT_ERR_FMT(fmt, ...)                                                                      \
	fprintf(stderr, "[%s:%d] %s: " fmt "\n", __FILE__, __LINE__, __func__, __VA_ARGS__)

#endif


/* 设置锁屏壁纸（单张图片）。 */
bool set_lockscreen_wallpaper(const char *const image_file_path) {
	static const char cmd_prefix[] =
		"reg add "
		"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Personalization "
		"/v LockScreenImage /d \"";
	static const char cmd_suffix[] = "\" /f";
	const size_t image_file_path_len = strlen(image_file_path);

	char *const cmd = malloc(
		image_file_path_len + sizeof(cmd_prefix) + sizeof(cmd_suffix) - 1
	);
	if (cmd == NULL) {
#ifndef NDEBUG
		PUT_ERR("malloc() for command string failed.");
#endif
		return false;
	}

	strcpy(cmd, cmd_prefix);
	strcat(cmd, image_file_path);
	strcat(cmd, cmd_suffix);

	const int cmd_exit_code = system(cmd);
	if (cmd_exit_code != 0) {
#ifndef NDEBUG
		PUT_ERR_FMT("system() failed with error %d.", cmd_exit_code);
#endif
		return false;
	}

	return true;
}
