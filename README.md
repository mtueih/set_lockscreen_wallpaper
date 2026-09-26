# set_lockscreen_wallpaper

![Platform](https://img.shields.io/badge/Platform-Windows-blue)
[![C Standard](https://img.shields.io/badge/C-C99+-blue.svg)](https://zh.cppreference.com/c)
[![CMake](https://img.shields.io/badge/CMake-3.24+-green.svg)](https://cmake.org/)
[![GitHub License](https://img.shields.io/github/license/mtueih/set_lockscreen_wallpaper)](LICENSE)
[![CI](https://github.com/mtueih/set_lockscreen_wallpaper/actions/workflows/ci.yml/badge.svg)](https://github.com/mtueih/set_lockscreen_wallpaper/actions/workflows/ci.yml)
[![CD](https://github.com/mtueih/set_lockscreen_wallpaper/actions/workflows/cd.yml/badge.svg)](https://github.com/mtueih/set_lockscreen_wallpaper/actions/workflows/cd.yml)

一个用于设置系统锁屏壁纸的轻量级 C 库。

目前只支持 Windows 平台。

## CLI

此项目包含一个 CLI 工具：`set_lockscreen_wallpaper`。

### 使用方法

- `set_lockscreen_wallpaper <image_file_path>`。

### 参数说明

`image_file_path` 是包含**目标图片路径**的单个字符串。

“**目标图片路径**”不支持**相对路径**。

### 行为说明

多余的参数会被忽略。

## API

### `set_lockscreen_wallpaper()`

设置锁屏壁纸（单张图片）。

```c
bool set_lockscreen_wallpaper(const char *image_file_path);
```

参数：

- `image_file_path`：包含目标图片路径的单个字符串（应使用系统代码页编码）。

返回值：

（`bool`）是否设置成功，设置成功返回 _`true`_，否则返回 _`false`_。

## 在其他项目中使用（仅库）

### 添加依赖

#### CPM.cmake

环境要求：[CPM.cmake](https://github.com/cpm-cmake/CPM.cmake)。

在 `CMakeLists.txt` 中：

```cmake
include(${PROJECT_SOURCE_DIR}/cmake/CPM.cmake)

CPMAddPackage("gh:mtueih/set_lockscreen_wallpaper#v0.2.0")
```

#### CMake find_package（需已安装）

在 `CMakeLists.txt` 中：

```cmake
find_package(set_lockscreen_wallpaper REQUIRED)
```

### 链接库

在 `CMakeLists.txt` 中：

```cmake
target_link_libraries(your_target PRIVATE set_lockscreen_wallpaper::set_lockscreen_wallpaper)
```

### 在代码中使用

#### 引入头文件

```cpp
#include <set_lockscreen_wallpaper/set_lockscreen_wallpaper.h>
```

#### 使用库函数

在 C 代码中：

```c
set_lockscreen_wallpaper("C:\\Users\\mtueih\\Pictures\\wallhaven-e82xxr.jpg");
```

在 C++ 代码中：

```cpp
set_lockscreen_wallpaper::set_lockscreen_wallpaper("C:\\Users\\mtueih\\Pictures\\wallhaven-e82xxr.jpg");
```

## 从源码构建

### 环境要求

- [CMake](https://cmake.org/) 3.24+。
- 支持 [C99](https://zh.cppreference.com/c/99)+ 的 [C 编译器](https://zh.cppreference.com/c/compiler_support)（MSVC / MinGW-w64 / Clang）。

### 构建步骤

#### 克隆仓库

```bash
git clone https://github.com/mtueih/set_lockscreen_wallpaper.git --depth 1 -b v0.2.0
cd set_lockscreen_wallpaper
```

#### 配置、构建与安装

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release -DSET_LOCKSCREEN_WALLPAPER_INSTALL_LIB=ON -DSET_LOCKSCREEN_WALLPAPER_INSTALL_CLI=ON
cmake --build build --config Release --parallel
cmake --install build --config Release --strip --prefix install
```

有关上述命令的说明：

- 配置命令。通过 `-DSET_LOCKSCREEN_WALLPAPER_INSTALL_LIB=ON` 与 `-DSET_LOCKSCREEN_WALLPAPER_INSTALL_CLI=ON` 分别启用了库与 CLI 工具的安装，你可以按需安装，如果不需要安装某一个，将对应选项删除即可。
- 安装命令。通过 `--prefix install` 将产物安装在了 `install` 目录下，而不是全局安装，以便你按自己的方式使用安装产物。如果你希望全局安装，则删除它即可。

## 许可协议

本项目采用 [ISC 许可证](https://www.isc.org/licenses/) 授权——详情请参阅 [LICENSE](LICENSE) 文件。
