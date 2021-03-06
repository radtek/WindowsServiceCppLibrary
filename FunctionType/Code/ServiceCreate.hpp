#ifndef __SERVICECREATE_HPP__
#define __SERVICECREATE_HPP__
#include "Common.hpp"
#include "ServiceCreateEnum.hpp"
#include <string>

typedef UINT(WINAPI* SERVICETHREAD)(PVOID);
typedef DWORD(WINAPI* HANDLERFUNCTION)(DWORD, DWORD, PVOID, PVOID);


namespace WinSvcLib {
	struct WinSvcInfo {
		SERVICE_STATUS SvcStatus;
		SERVICE_STATUS_HANDLE SvcStatusHandle;
		ServiceState CurrentServiceState;
		ServiceControl CurrentServiceControl;
	};
	namespace Original {
		WINSVCBUILD WinSvcInfo WinSvcLibInit(LPCTSTR ServiceName, HANDLERFUNCTION HandlerEx, const ServiceType WindowsServiceType = ServiceType::Win32OwnProcess);
		WINSVCBUILD WinSvcInfo WinSvcLibInit(const std::basic_string<TCHAR> ServiceName, HANDLERFUNCTION HandlerEx, const ServiceType WindowsServiceType = ServiceType::Win32OwnProcess);
		WINSVCBUILD void SetCurrentState(WinSvcInfo& Info, const ServiceState SvcState);
		WINSVCBUILD void SetControlsAccepted(WinSvcInfo& Info, const ServiceControlsAccepted SvcControlAccepted);
		WINSVCBUILD void SetWin32ExitCode(WinSvcInfo& Info, const DWORD Win32ExitCode);
		WINSVCBUILD void SetServiceSpecificExitCode(WinSvcInfo& Info, const DWORD ServiceSCallpecificExitCode);
		WINSVCBUILD void SetCheckPoint(WinSvcInfo& Info, const DWORD CheckPoint);
		WINSVCBUILD void SetWaitHint(WinSvcInfo& Info, const DWORD WaitHint);
		WINSVCBUILD int  Run(WinSvcInfo &Inf, SERVICETHREAD ServiceThread, LPVOID ArgList = NULL);
		WINSVCBUILD void UpdateNewState(WinSvcInfo &Info, const ServiceState NewState);
		WINSVCBUILD void SetServiceStatus(WinSvcInfo& Info);
	}
	namespace StandardWin32OwnProcess {
		WINSVCBUILD void WinSvcLibInit(LPCTSTR ServiceName);
		WINSVCBUILD void WinSvcLibInit(const std::basic_string<TCHAR> ServiceName);
		WINSVCBUILD void SetCurrentState(const ServiceState SvcState);
		WINSVCBUILD void SetControlsAccepted(const ServiceControlsAccepted SvcControlAccepted);
		WINSVCBUILD void SetWin32ExitCode(const DWORD Win32ExitCode);
		WINSVCBUILD void SetServiceSpecificExitCode(const DWORD ServiceSCallpecificExitCode);
		WINSVCBUILD void SetCheckPoint(const DWORD CheckPoint);
		WINSVCBUILD void SetWaitHint(const DWORD WaitHint);
		WINSVCBUILD int Run(SERVICETHREAD ServiceThread, LPVOID ArgList = NULL);
		WINSVCBUILD void UpdateNewState(const ServiceState NewState);
	}
}
#endif
