#ifndef __WINMAINFUNC_HPP__
#define __WINMAINFUNC_HPP__
#include "BuildCoreMacro.hpp"
#include <Windows.h>
#include <string>
#include <stdexcept>

typedef void (WINAPI* SERVICEMAIN)(DWORD, LPTSTR[]);

namespace WinSvcLib {
	WINSVCBUILD int AddServiceInfo(const std::basic_string<TCHAR> ServiceName, SERVICEMAIN ServiceMain);
	WINSVCBUILD int AddServiceInfo(const LPCTSTR ServiceName, SERVICEMAIN ServiceMain);
	WINSVCBUILD int Dispatcher();
}
#endif
