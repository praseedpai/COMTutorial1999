// dllserver01.h : main header file for the DLLSERVER01 DLL
//

#if !defined(AFX_DLLSERVER01_H__F776BC4B_F3EC_11D2_A4E4_0040056DF87F__INCLUDED_)
#define AFX_DLLSERVER01_H__F776BC4B_F3EC_11D2_A4E4_0040056DF87F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDllserver01App
// See dllserver01.cpp for the implementation of this class
//

class CDllserver01App : public CWinApp
{
public:
	CDllserver01App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDllserver01App)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CDllserver01App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLLSERVER01_H__F776BC4B_F3EC_11D2_A4E4_0040056DF87F__INCLUDED_)
