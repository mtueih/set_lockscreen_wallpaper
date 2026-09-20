#include "set_lockscreen_wallpaper.h"
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
#  include <stdio.h>
#endif

bool set_lockscreen_wallpaper(const char *const image_file_path) {
	static const char cmd_prefix[] = "reg add "
		"\"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Personalization\" "
		"/v LockScreenImage /t REG_SZ /d \"";
	static const char cmd_suffix[] = "\" /f";
	const size_t image_file_path_len = strlen(image_file_path);

	char *cmd = malloc(sizeof(cmd_prefix) + sizeof(cmd_suffix) + image_file_path_len + 1);
	if (!cmd) {
#ifdef DEBUG
		fprintf(
			stderr, "[%s | %s]: [Error]: malloc failed.\n",
			__FILE__, __func__
		);
#endif
		return false;
	}

	strcpy(cmd, cmd_prefix);
	strcat(cmd, image_file_path);
	strcat(cmd, cmd_suffix);

	const int cmd_exit_code = system(cmd);
	if (cmd_exit_code != 0) {
#ifdef DEBUG
		fprintf(
			stderr, "[%s | %s]: [Error]: system failed with exit code %d.\n",
			__FILE__, __func__, cmd_exit_code
		);
#endif

		return false;
	}

	return true;
}
