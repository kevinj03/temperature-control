// commDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//#include "serial.h"
//}}AFX_INCLUDES

#if !defined(AFX_COMMDLG_H__845EE026_FBE1_11D3_B3A6_00C00CB075D5__INCLUDED_)
#define AFX_COMMDLG_H__845EE026_FBE1_11D3_B3A6_00C00CB075D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "meter1.h"

/////////////////////////////////////////////////////////////////////////////
// CCommDlg dialog

class CCommDlg : public CDialog
{
// Construction
public:
	int i;
	void Display();
	void Display_meter();
	//CSerial comm2;
	CCommDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCommDlg)
	enum { IDD = IDD_COMM_DIALOG };
	CMeter	m_mymeter;
	CButton	m_stop;
	CButton	m_hexsend;
	CComboBox	m_speed;
	CButton	m_hex;
	CComboBox	m_com;
	CMSComm	m_Comm;
	CString	m_SendData;
	CString	m_ReceiveData;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCommDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnComm();
	afx_msg void OnButton1();
	afx_msg void OnComselect();
	afx_msg void OnComspeed();
	afx_msg void OnStoprecv();
	afx_msg void OnButton8();

	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL stop;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMDLG_H__845EE026_FBE1_11D3_B3A6_00C00CB075D5__INCLUDED_)
