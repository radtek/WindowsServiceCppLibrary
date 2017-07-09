#ifndef __BUILDCOREMACRO_HPP__
#define __BUILDCOREMACRO_HPP__
#ifdef WINSVCLIB_SHARED_BUILD // ＤＬＬ使用でビルドする場合
#if defined(SERVICECREATE_EXPORTS) || defined(INSTALLER_EXPORTS) || defined(UNINSTALLER_EXPORTS)
#define WINSVCBUILD __declspec(dllexport)
#else
#define WINSVCBUILD __declspec(dllimport)
#endif
#else // スタティックライブラリを使用してビルドする場合
#define WINSVCBUILD
#endif
#endif 
