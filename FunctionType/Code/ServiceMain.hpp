#ifndef __SERVICEMAIN_HPP__
#define __SERVICEMAIN_HPP__
#include "Common.hpp"
#include <Windows.h>

typedef UINT(WINAPI* SERVICETHREAD)(PVOID);
typedef DWORD(WINAPI* HANDLERFUNCTION)(DWORD, DWORD, PVOID, PVOID);


namespace WinSvcLib {
	struct WinSvcInfo;
	// あらゆるWindowsサービスの種類を作ることができます。
	// 自身でHandlerEx関数を指定する必要があります。
	WinSvcInfo WinSvcLibInit(SERVICETHREAD ServiceThread, HANDLERFUNCTION HandlerEx, const ServiceType WindowsServiceType);
	// Win32OwnProcessサービスを作ることができます。
	// 自身でHandlerEx関数を指定するタイプです。
	WinSvcInfo WinSvcLibInit(SERVICETHREAD ServiceThread, HANDLERFUNCTION HandlerEx);
	// Win32OwnProcessサービスを作ることができます。
	// ライブラリで用意されたHandlerEx関数を使います。
	WinSvcInfo WinSvcLibInit(SERVICETHREAD ServiceThread);
}
#endif
