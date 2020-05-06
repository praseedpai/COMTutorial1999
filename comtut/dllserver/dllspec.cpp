//
//DLLMain.cpp
//

#define MAX_STRING_LENGTH 255
#define GUID_SIZE 128  
#include "stdafx.h"
#include "objimpl.h"

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
/////////////////////////////////////////////
//
// implementation DllRegisterServer
//
STDAPI DllRegisterServer(void)
{
	BOOL bOK;
	_TCHAR szModulePath[MAX_PATH + 1];
	_TCHAR szCLSID[GUID_SIZE + 1];
	_TCHAR szCLSIDKey[MAX_STRING_LENGTH + 1];
	wchar_t wszGUID[GUID_SIZE + 1];

	// Obtain the path to server's executable file for later use
	GetModuleFileName(AfxGetInstanceHandle(), szModulePath, 
	sizeof(szModulePath) / sizeof(_TCHAR));
	StringFromGUID2(CLSID_Address, wszGUID, 
		sizeof(wszGUID) / sizeof(wchar_t));
	WideCharToMultiByte(CP_ACP, 0, wszGUID, -1, szCLSID, 
		sizeof(szCLSID) / sizeof(_TCHAR), NULL, NULL);
	_tcscpy(szCLSIDKey, _TEXT("CLSID\\"));
	_tcscat(szCLSIDKey, szCLSID);
	bOK = SetRegKeyValue(HKEY_CLASSES_ROOT, szCLSIDKey, NULL, NULL,
		_TEXT("NEST CYBERCAMPUS - Address Object."));
	if (bOK)
		bOK = SetRegKeyValue(HKEY_CLASSES_ROOT, szCLSIDKey, 
		_TEXT("InProcServer32"), NULL, szModulePath);
	if (!bOK) 
		return SELFREG_E_CLASS;


	StringFromGUID2(CLSID_AddressList, wszGUID, 
		sizeof(wszGUID) / sizeof(wchar_t));
#ifdef  _UNICODE
	//UNICODE
	_tcscpy(szCLSID, wszGUID);
#else	
	//SBCS and MBCS
	//Convert from the wide character set to the multibyte character set
	WideCharToMultiByte(CP_ACP, 0, wszGUID, -1, szCLSID, 
		sizeof(szCLSID) / sizeof(_TCHAR), NULL, NULL);
#endif
	//HKEY_CLASSES_ROOT\CLSID\{00000000-0000-0000-0000-000000000000}
	_tcscpy(szCLSIDKey, _TEXT("CLSID\\"));
	_tcscat(szCLSIDKey, szCLSID);
	bOK = SetRegKeyValue(HKEY_CLASSES_ROOT, szCLSIDKey, NULL, NULL,
		_TEXT("NEST CYBER CAMPUS - AddressList object"));
	if (bOK)
		bOK = SetRegKeyValue(HKEY_CLASSES_ROOT, szCLSIDKey, 
		_TEXT("InProcServer32"), NULL, szModulePath);
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

STDAPI DllUnregisterServer(void)
{
	long lErrorCode;
	_TCHAR szCLSID[GUID_SIZE + 1];
	_TCHAR szCLSIDKey[MAX_STRING_LENGTH + 1];
	_TCHAR szInprocServer32Key[MAX_STRING_LENGTH + 1];
	wchar_t wszGUID[GUID_SIZE + 1];

	//Convert the CLSID to the format
	//{00000000-0000-0000-0000-000000000000}
	StringFromGUID2(CLSID_Address, wszGUID, 
		sizeof(wszGUID) / sizeof(wchar_t));
	WideCharToMultiByte(CP_ACP, 0, wszGUID, -1, szCLSID, 
		sizeof(szCLSID) / sizeof(_TCHAR), NULL, NULL);
	_tcscpy(szCLSIDKey, _TEXT("CLSID\\"));
	_tcscat(szCLSIDKey, szCLSID);
	_tcscpy(szInprocServer32Key, szCLSIDKey);
	_tcscat(szInprocServer32Key, _TEXT("\\InProcServer32"));
	//Delete sub-keys first
	lErrorCode = RegDeleteKey(HKEY_CLASSES_ROOT, szInprocServer32Key);
	//Delete the entry under CLSID.
	if (ERROR_SUCCESS == lErrorCode)
		lErrorCode = RegDeleteKey(HKEY_CLASSES_ROOT, szCLSIDKey);
	if (ERROR_SUCCESS != lErrorCode)
		return SELFREG_E_CLASS;


	StringFromGUID2(CLSID_AddressList, wszGUID, 
		sizeof(wszGUID) / sizeof(wchar_t));
	WideCharToMultiByte(CP_ACP, 0, wszGUID, -1, szCLSID, 
		sizeof(szCLSID) / sizeof(_TCHAR), NULL, NULL);
	_tcscpy(szCLSIDKey, _TEXT("CLSID\\"));
	_tcscat(szCLSIDKey, szCLSID);
	_tcscpy(szInprocServer32Key, szCLSIDKey);
	_tcscat(szInprocServer32Key, _TEXT("\\InProcServer32"));
	//Delete sub-keys first
	lErrorCode = RegDeleteKey(HKEY_CLASSES_ROOT, szInprocServer32Key);
	//Delete the entry under CLSID.
	if (ERROR_SUCCESS == lErrorCode)
		lErrorCode = RegDeleteKey(HKEY_CLASSES_ROOT, szCLSIDKey);
	if (ERROR_SUCCESS != lErrorCode)
		return SELFREG_E_CLASS;

	return NOERROR;

}
//////////////////////////////////////////
//
//DllGetClassObject
//
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv)
{
	HRESULT hr = NOERROR;
	CAddressFactory *pAddressFactory = NULL;
    CAddressListFactory *pAddressListFactory = NULL;
	if (CLSID_Address == rclsid)
	{
		//Create the UserInfo class factory
		pAddressFactory = new CAddressFactory();
		//Check for out of memory error
		if (NULL == pAddressFactory)
			return E_OUTOFMEMORY;
		//Get the requested interface
		hr = pAddressFactory->QueryInterface(riid, ppv);
		if (FAILED(hr))
		{
			delete pAddressFactory;
			pAddressFactory = NULL;
			return hr;
		}
	}
	else if ( CLSID_AddressList == rclsid )
	{
		pAddressListFactory = new CAddressListFactory();
		//Check for out of memory error
		if (NULL == pAddressListFactory)
			return E_OUTOFMEMORY;
		//Get the requested interface
		hr = pAddressListFactory->QueryInterface(riid, ppv);
		if (FAILED(hr))
		{
			delete pAddressListFactory;
			pAddressListFactory = NULL;
			return hr;
		}
        


	}
	else
		hr = CLASS_E_CLASSNOTAVAILABLE;

	return hr;
}
////////////////////////////////////////
//
//DllCanUnloadNow
//
STDAPI DllCanUnloadNow(void)
{
	if (ServerCanUnloadNow())
		return S_OK;
	else 
		return S_FALSE;
}

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
	_TCHAR szKey[MAX_STRING_LENGTH + 1];

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
	
	return;
}


