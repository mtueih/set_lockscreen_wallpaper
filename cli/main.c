#include <stdio.h>
#include "set_lockscreen_wallpaper.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s [image_file_path].\n", argv[0]);
		return 1;
	}

	if (!set_lockscreen_wallpaper(argv[1])) {
		fprintf(stderr, "Failed to set lockscreen wallpaper!\n");
		return 1;
	}

	printf("Lockscreen Wallpaper Successfully Set.\n");
	return 0;
}
