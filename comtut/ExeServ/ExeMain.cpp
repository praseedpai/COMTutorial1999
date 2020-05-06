#include <windows.h>
#include "tchar.h"
#include "olectl.h"
#include "objimpl.h"


#define P_MAX_STRING_LENGTH 255


#define GUID_SIZE 128  

///////////////////////////////////
// Function Protototypes
//
BOOL SetRegKeyValue(HKEY hKeyRoot, LPTSTR lpszKey, LPTSTR lpszSubKey, 
					LPTSTR lpszNamedValue, LPTSTR lpszValue);
BOOL ServerCanUnloadNow(void);
void UnloadServer(void);
////////////////////////////////////
//
//Global variables
//
ULONG g_cObjects = 0;
ULONG g_cLocks = 0;
DWORD g_dwExpression;
HANDLE g_hv;
HINSTANCE hinst;

/////////////////////////////////////////////
//
// implementation DllRegisterServer
//
BOOL RegisterServer(void)
{
	BOOL bOK;
	_TCHAR szModulePath[MAX_PATH + 1];
	_TCHAR szCLSID[GUID_SIZE + 1];
	_TCHAR szCLSIDKey[P_MAX_STRING_LENGTH + 1];
	wchar_t wszGUID[GUID_SIZE + 1];

	// Obtain the path to server's executable file for later use
	GetModuleFileName(NULL, szModulePath, 
	sizeof(szModulePath) / sizeof(_TCHAR));
	StringFromGUID2(CLSID_Expression, wszGUID, 
		sizeof(wszGUID) / sizeof(wchar_t));
	WideCharToMultiByte(CP_ACP, 0, wszGUID, -1, szCLSID, 
		sizeof(szCLSID) / sizeof(_TCHAR), NULL, NULL);
	_tcscpy(szCLSIDKey, _TEXT("CLSID\\"));
	_tcscat(szCLSIDKey, szCLSID);
	bOK = SetRegKeyValue(HKEY_CLASSES_ROOT, szCLSIDKey, NULL, NULL,
		_TEXT("Expression Evaluator - From Praseed Pai."));
	if (bOK)
		bOK = SetRegKeyValue(HKEY_CLASSES_ROOT, szCLSIDKey, 
		_TEXT("LocalServer32"), NULL, szModulePath);
	

	if (bOK) 
		return NOERROR;
	else
		return SELFREG_E_CLASS;




}

/////////////////////////////////////////////////
//
//DllUnregisterServer
//
//
//

BOOL  UnregisterServer(void)
{
	long lErrorCode;
	_TCHAR szCLSID[GUID_SIZE + 1];
	_TCHAR szCLSIDKey[P_MAX_STRING_LENGTH + 1];
	_TCHAR szInprocServer32Key[P_MAX_STRING_LENGTH + 1];
	wchar_t wszGUID[GUID_SIZE + 1];

	//Convert the CLSID to the format
	//{00000000-0000-0000-0000-000000000000}
	StringFromGUID2(CLSID_Expression, wszGUID, 
		sizeof(wszGUID) / sizeof(wchar_t));
	WideCharToMultiByte(CP_ACP, 0, wszGUID, -1, szCLSID, 
		sizeof(szCLSID) / sizeof(_TCHAR), NULL, NULL);
	_tcscpy(szCLSIDKey, _TEXT("CLSID\\"));
	_tcscat(szCLSIDKey, szCLSID);
	_tcscpy(szInprocServer32Key, szCLSIDKey);
	_tcscat(szInprocServer32Key, _TEXT("\\LocalServer32"));
	//Delete sub-keys first
	lErrorCode = RegDeleteKey(HKEY_CLASSES_ROOT, szInprocServer32Key);
	//Delete the entry under CLSID.
	if (ERROR_SUCCESS == lErrorCode)
		lErrorCode = RegDeleteKey(HKEY_CLASSES_ROOT, szCLSIDKey);
	if (ERROR_SUCCESS != lErrorCode)
		return SELFREG_E_CLASS;

	return NOERROR;

}

////////////////////////////////////////
//
//DllCanUnloadNow
//


////////////////////////////////////////////////
//
//SetRegKeyValue
//
BOOL SetRegKeyValue(HKEY hKeyRoot, LPTSTR lpszKey, LPTSTR lpszSubKey, 
					LPTSTR lpszNamedValue, LPTSTR lpszValue)
{
	BOOL bOk = FALSE;
	long lErrorCode;
	HKEY hKey;
	_TCHAR szKey[P_MAX_STRING_LENGTH + 1];

	_tcscpy(szKey, lpszKey);
	if (NULL != lpszSubKey)
	{
		_tcscat(szKey, _TEXT("\\"));
		_tcscat(szKey, lpszSubKey);
	}
	lErrorCode = RegCreateKeyEx(hKeyRoot, szKey, 0, 
		 NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 
		 NULL, &hKey, NULL);
	if (ERROR_SUCCESS == lErrorCode)
	{
		lErrorCode = RegSetValueEx(hKey, lpszNamedValue, 0, REG_SZ, 
		   (BYTE *)lpszValue, (_tcslen(lpszValue) + 1) * sizeof(_TCHAR));
		if (ERROR_SUCCESS == lErrorCode)
			bOk = TRUE;
		RegCloseKey(hKey);
	}

	return bOk;
}
//////////////////////////////////////////////////////
//
//ServerCanUnloadNow
//
BOOL ServerCanUnloadNow(void)
{
	//The server can unload if there are no outstanding 
	//objects or class factory locks
	if(0 == g_cObjects && 0 == g_cLocks)
		return TRUE;
	else
		return FALSE;
}
///////////////////////////////////////
//
//UnloadServer
//
void UnloadServer(void)
{
	PostQuitMessage(0);
}
///////////////////////////
//
//
//
//
//




 int __cdecl main(int arc , char **argv)

{
	HRESULT hr;
	MSG msg;
	_TCHAR szTokens[] = _TEXT("-/");
	LPTSTR szNextToken;
	LPTSTR szCmdLine;
	CExpressionFactory *pAddressFactory = NULL;
    

	szCmdLine = GetCommandLine();
    

	//Find the first token
	szNextToken = _tcstok(szCmdLine, szTokens); 
	while (NULL != szNextToken)
	{
		if (0 == _tcsicmp(szNextToken, _TEXT("UnregServer")))
		{
			::UnregisterServer();
			
			return FALSE;
		}
		else if (0 == _tcsicmp(szNextToken, _TEXT("RegServer")))
		{
			::RegisterServer();
			
			return FALSE;
		}
		else if (0 == _tcsicmp(szNextToken, _TEXT("Embedding")))
		{
			break;
		}
		//Find the next token
		szNextToken = _tcstok(NULL, szTokens) ;
	}
	// Initialize the COM Library.
	hr = CoInitialize(NULL);
	if (FAILED(hr))
		return FALSE;
	//Create the UserInfo class factory
	pAddressFactory = new CExpressionFactory();
	//Check for out of memory error
	if (NULL != pAddressFactory)
	{
		//Register the UserInfo class factory
		hr = CoRegisterClassObject(CLSID_Expression, 
			(IUnknown *)pAddressFactory, CLSCTX_LOCAL_SERVER, 
			REGCLS_MULTIPLEUSE, &g_dwExpression);
		if (FAILED(hr))
		{
			delete pAddressFactory;
			pAddressFactory = NULL;
		}

	}

			
	while ( GetMessage(&msg,0,0,0))
		DispatchMessage(&msg);
	
	CoRevokeClassObject(g_dwExpression);
	CoUninitialize();
    return (msg.wParam); 
}


