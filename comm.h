// comm.h : main header file for the COMM application
//

#if !defined(AFX_COMM_H__845EE024_FBE1_11D3_B3A6_00C00CB075D5__INCLUDED_)
#define AFX_COMM_H__845EE024_FBE1_11D3_B3A6_00C00CB075D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCommApp:
// See comm.cpp for the implementation of this class
//

class CCommApp : public CWinApp
{
public:
	CCommApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCommApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMM_H__845EE024_FBE1_11D3_B3A6_00C00CB075D5__INCLUDED_)
