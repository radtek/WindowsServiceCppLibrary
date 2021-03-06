#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <stdexcept>

#ifndef NO_USE_EXCEPTIONMANAGER
static std::string LastError;

void SetLastException(const char* ExceptionMessage) {
	LastError.resize(std::strlen(ExceptionMessage));
	LastError = ExceptionMessage;
}

namespace WinSvcLib {
	std::string GetLastException() {
		return LastError;
	}
}
#endif

#include "KgWinException.hpp"

std::string KgWinException::GetErrorMessage(const unsigned long ErrorCode) {
	char* lpMessageBuffer = nullptr;
	const DWORD length = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, ErrorCode, LANG_USER_DEFAULT, (LPSTR)&lpMessageBuffer, 0, NULL);
	if (length == 0) throw std::runtime_error("エラーメッセージ取得時にエラーが発生しました。\nエラーコード : " + std::to_string(GetLastError()));
	DWORD i = length - 3;
	for (; '\r' != lpMessageBuffer[i] && '\n' != lpMessageBuffer[i] && '\0' != lpMessageBuffer[i]; i++);//改行文字削除
	lpMessageBuffer[i] = '\0';
	std::string s = "エラーコード : " + std::to_string(ErrorCode) + "　" + lpMessageBuffer;
	LocalFree(lpMessageBuffer);
	return s;
}

std::string KgWinException::GetErrorMessage() {
	const DWORD Code = GetLastError();
	return this->GetErrorMessage(Code);
}

int KgWinException::GraphErrorMessageOnMessageBox(const char* Caption, const int Button) const {
	return MessageBoxA(NULL, this->what(), Caption, MB_ICONERROR | Button);
}

void KgWinException::GraphErrorMessageOnConsole() const {
	std::cout << this->what() << std::endl;
}

