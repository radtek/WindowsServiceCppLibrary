#ifndef __WINSVCINSTALLER_HPP__
#define __WINSVCINSTALLER_HPP__
#include "BuildCoreMacro.hpp"
#include "Common.hpp"
#include <Windows.h>
#include <string>
#ifdef WINSVCLIB_SHARED_BUILD
#include <memory>
typedef std::shared_ptr<std::basic_string<TCHAR>> String;
#else
typedef std::basic_string<TCHAR> String;
#endif

namespace WinSvcLib {
	namespace Installer {
		enum class ExecuteUser : short {
			System = 0,
			LocalService = 1,
			NetworkService = 2
		};
		enum class ServiceStartType : DWORD {
			BootStart = 0x00000000, // システムローダーが開始するデバイスドライバの指定
			SystemStart = 0x00000001, // IoInitSystem関数が開始するデバイスドライバを指定
			AutoStart = 0x00000002, // 自動開始
			ManualStart = 0x00000003, // 手動開始
			Disabled = 0x00000004, // 無効
			DelayStart = 0x00000005  // 遅延開始
		};
		enum class ServiceErrorControlType : DWORD {
			Ignore = 0x00000000, // SERVICE_ERROR_IGNORE
			Normal = 0x00000001, // SERVICE_ERROR_NORMAL
			Severe = 0x00000002, // SERVICE_ERROR_SEVERE
			Critical = 0x00000003  // SERVICE_ERROR_CRITICAL
		};
		struct ServiceInstallInformation {
			WINSVCBUILD ServiceInstallInformation();
			String ServiceName;
			String DisplayName;
			LPTSTR Description;
			String ExecuteFilePath;
			ServiceType Type;
			ServiceStartType StartType;
			ServiceErrorControlType ErrorControl;
			String LoadOrderGroup;
			LPCTSTR Dependencies;
			String ExecuteUser;
			String ExecuteUserPassword;
			bool DeviceDriver;
		};
		WINSVCBUILD void RunasAdministratorsAuthority();
		WINSVCBUILD ServiceInstallInformation InstallerLibInit(const std::basic_string<TCHAR> ServiceName, const std::basic_string<TCHAR> ExecuteFilePath, const bool IsDeviceDriver = false);
		WINSVCBUILD void ChangeServiceType(const ServiceType NewType, ServiceInstallInformation &Inf);
		WINSVCBUILD void ChangeStartType(const ServiceStartType NewType, ServiceInstallInformation &Inf);
		WINSVCBUILD void ChangeDisplayName(const std::basic_string<TCHAR> DisplayName, ServiceInstallInformation &Inf);
		WINSVCBUILD void SetLoadOrderGroup(const std::basic_string<TCHAR> LoadOrderGroup, ServiceInstallInformation &Inf);
		WINSVCBUILD void SetDependencies(LPCTSTR Dependencies, ServiceInstallInformation &Inf);
		WINSVCBUILD void ChangeExecuteUser(const std::basic_string<TCHAR> UserName, ServiceInstallInformation &Inf);
		WINSVCBUILD void ChangeExecuteUser(const ExecuteUser User, ServiceInstallInformation &Inf);
		WINSVCBUILD void SetUserPassword(const std::basic_string<TCHAR> Password, ServiceInstallInformation &Inf);
		WINSVCBUILD void InstallService(const ServiceInstallInformation Inf, LPDWORD lpdwTagId);
	}
}
#endif
