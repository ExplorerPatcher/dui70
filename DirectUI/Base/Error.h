#pragma once

#include <Windows.h>

namespace DirectUI
{

inline void TryDbgPrintEx(ULONG ComponentId, ULONG Level, PCSTR pszMessage)
{
	HMODULE hmod = GetModuleHandleW(L"ntdll.dll");
	if (hmod)
	{
		typedef ULONG (WINAPI *DbgPrintEx_t)(ULONG ComponentId, ULONG Level, PCSTR Format, ...);
		DbgPrintEx_t pfnDbgPrintEx = (DbgPrintEx_t)GetProcAddress(hmod, "DbgPrintEx");
		if (pfnDbgPrintEx)
		{
			pfnDbgPrintEx(ComponentId, Level, pszMessage);
		}
	}
}

}

#ifdef _DEBUG
#define DUI_ASSERT(msg) \
	do \
	{ \
		DirectUI::TryDbgPrintEx(101 /*DPFLTR_DEFAULT_ID*/, 0, msg); \
		_ASSERTE(false); \
	} \
	while (0)

#define DUI_ASSERT_EXPR(expr, msg) \
	if (!(expr)) \
	{ \
		DUI_ASSERT("(" #expr ")\r\n" msg "\r\n"); \
	}
#else
#define DUI_ASSERT(msg)
#define DUI_ASSERT_EXPR(expr, msg)
#endif

// DirectUI Error codes
#define FACILITY_DIRECTUI			FACILITY_ITF
#define MAKE_DUIERROR(code)			MAKE_HRESULT(SEVERITY_ERROR, FACILITY_DIRECTUI, code)

#define DUI_E_USERFAILURE			MAKE_DUIERROR(1002)		// 0x800403EA
#define DUI_E_NODEFERTABLE			MAKE_DUIERROR(1003)		// 0x800403EB
#define DUI_E_PARTIAL				MAKE_DUIERROR(1004)		// 0x800403EC

// New in Vista+ DirectUI
#define DUI_E_BADMARKUP				MAKE_DUIERROR(1005)		// 0x800403ED
#define DUI_E_UNREGISTEREDELEMENT	MAKE_DUIERROR(1006)		// 0x800403EE
#define DUI_E_MISSINGPROPERTY		MAKE_DUIERROR(1007)		// 0x800403EF
#define DUI_E_NOTFOUND				MAKE_DUIERROR(1008)		// 0x800403F0
#define DUI_E_INVALIDPROPVALUE		MAKE_DUIERROR(1009)		// 0x800403F1
#define DUI_E_INVALIDPROPERTY		MAKE_DUIERROR(1010)		// 0x800403F2
