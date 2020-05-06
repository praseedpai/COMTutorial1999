// dllserver.h : main header file for the DLLSERVER DLL
//

#if !defined(AFX_DLLSERVER_H__DFD31296_F3F4_11D2_A4E4_0040056DF87F__INCLUDED_)
#define AFX_DLLSERVER_H__DFD31296_F3F4_11D2_A4E4_0040056DF87F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDllserverApp
// See dllserver.cpp for the implementation of this class
//

class CDllserverApp : public CWinApp
{
public:
	CDllserverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDllserverApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CDllserverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLLSERVER_H__DFD31296_F3F4_11D2_A4E4_0040056DF87F__INCLUDED_)
