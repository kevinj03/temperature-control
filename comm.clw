; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCommDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "comm.h"

ClassCount=4
Class1=CCommApp
Class2=CCommDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMeter
Resource3=IDD_COMM_DIALOG

[CLS:CCommApp]
Type=0
HeaderFile=comm.h
ImplementationFile=comm.cpp
Filter=N

[CLS:CCommDlg]
Type=0
HeaderFile=commDlg.h
ImplementationFile=commDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CCommDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=commDlg.h
ImplementationFile=commDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_COMM_DIALOG]
Type=1
Class=CCommDlg
ControlCount=33
Control1=IDC_EDIT2,edit,1352730692
Control2=ID_CLOSE,button,1342242817
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_MSCOMM1,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control5=IDC_BUTTON2,button,1342242816
Control6=IDC_COMSELECT,combobox,1344339971
Control7=IDC_STATIC,static,1342308352
Control8=IDC_COMSEEPED,combobox,1344339971
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STOPRECV,button,1342242816
Control11=IDC_STATIC,static,1342177287
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_TAB1,static,1342308352
Control16=IDC_TAB5,static,1342308352
Control17=IDC_TAB2,static,1342308352
Control18=IDC_TAB6,static,1342308352
Control19=IDC_TAB3,static,1342308352
Control20=IDC_TAB4,static,1342308352
Control21=IDC_TAB7,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC0,static,1342308352
Control27=IDC_BUTTON8,button,1342242816
Control28=IDC_Meter,static,1342177289
Control29=IDC_STATIC1,static,1342308352
Control30=IDC_STATIC2,static,1342308352
Control31=IDC_STATIC3,static,1342308352
Control32=IDC_STATIC,static,1342308865
Control33=IDC_STATIC,static,1342308865

[CLS:CMeter]
Type=0
HeaderFile=Meter1.h
ImplementationFile=Meter1.cpp
BaseClass=CStatic
Filter=W
LastObject=CMeter

