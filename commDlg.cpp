// commDlg.cpp : implementation file
// Download by http://www.codefans.net

#include "stdafx.h"
#include "comm.h"
#include "commDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int LineHight[602];
int LHTemp[120];
CString DTemp;
int LineNum=0;
int NextTime;
int RightLeftNum=0;
int check='n';
int gogo=0;
int speed=9600;
int tab=0;
CString FilePath="c:\\data.txt";

//仪表功能变量
char *p;
char *pBuf;
double r;
float q[100];	

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommDlg dialog

CCommDlg::CCommDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCommDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCommDlg)
	m_SendData = _T("");
	m_ReceiveData = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	stop=FALSE;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCommDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommDlg)
	DDX_Control(pDX, IDC_Meter, m_mymeter);
	DDX_Control(pDX, IDC_STOPRECV, m_stop);
	DDX_Control(pDX, IDC_COMSEEPED, m_speed);
	DDX_Control(pDX, IDC_COMSELECT, m_com);
	DDX_Control(pDX, IDC_MSCOMM1, m_Comm);
	DDX_Text(pDX, IDC_EDIT2, m_ReceiveData);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCommDlg, CDialog)
	//{{AFX_MSG_MAP(CCommDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_CBN_SELENDOK(IDC_COMSELECT, OnComselect)
	ON_CBN_SELENDOK(IDC_COMSEEPED, OnComspeed)
	ON_BN_CLICKED(IDC_STOPRECV, OnStoprecv)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
//	ON_BN_CLICKED(IDC_BUTTON4, OnWrite)
//	ON_BN_CLICKED(IDC_BUTTON5, OnRead)
	ON_WM_TIMER()
//	ON_BN_CLICKED(IDC_BUTTON9, OnOK)
	ON_BN_CLICKED(ID_CLOSE, OnClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommDlg message handlers

BOOL CCommDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_com.SetCurSel(0);
	m_speed.SetCurSel(2);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCommDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
// 画图函数
// 算法:运用LineTo函数把120个点连成折线
void CCommDlg::OnPaint() 
{
	//仪表
	// This code, normally emitted by the AppWizard for a dialog-based
	// project for the dialog's WM_PAINT handler, runs only if the	
	// window is iconic. The window erase the icon's area, then
	// paints the icon referenced by m_hIcon.
	/*if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
  
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}*/
	

	int hoc;
	if (NextTime<600 && stop==FALSE) hoc = 600;
	else hoc = NextTime;
	CString TabStr="";
	CPaintDC dc(this);
	dc.GetNearestColor(RGB(255,0,0));
	dc.MoveTo(108,600);
	if (NextTime<=600 && stop==FALSE)
	for (int i=0;i<NextTime;i++)
	{
		dc.LineTo(108+i,600-2*LineHight[i]);
	}
	else
	for (int i=0;i<601;i++)
	{
		dc.LineTo(108+i,600-2*LineHight[i]);
	}
	TabStr.Format("%d",hoc-600);
	SetDlgItemText(IDC_TAB1,TabStr);
	TabStr.Format("%d",hoc-500);
	SetDlgItemText(IDC_TAB2,TabStr);
	TabStr.Format("%d",hoc-400);
	SetDlgItemText(IDC_TAB3,TabStr);
	TabStr.Format("%d",hoc-300);
	SetDlgItemText(IDC_TAB4,TabStr);
	TabStr.Format("%d",hoc-200);
	SetDlgItemText(IDC_TAB5,TabStr);
	TabStr.Format("%d",hoc-100);
	SetDlgItemText(IDC_TAB6,TabStr);
	TabStr.Format("%d",hoc/5);
	SetDlgItemText(IDC_TAB7,TabStr);

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCommDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CCommDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CCommDlg)
	ON_EVENT(CCommDlg, IDC_MSCOMM1, 1 /* OnComm */, OnComm, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CCommDlg::OnComm() 
{
	if(stop)return;
	SYSTEMTIME systm;     
	GetLocalTime(&systm);  
	VARIANT m_input1;
	COleSafeArray m_input2;
	long length,i;
	BYTE data[3000];
	CString str;
	if(m_Comm.GetCommEvent()==2)//接收缓冲区内有字符
	{
		m_input1=m_Comm.GetInput();//读取缓冲区内的数据
		m_input2=m_input1;//将VARIANT型变量转换为ColeSafeArray型变量
		length=m_input2.GetOneDimSize();//确定数据长度
		for(i=0;i<length;i++)
		m_input2.GetElement(&i,data+i);//将数据转换为BYTE型数组

		for(i=0;i<length;i++)//将数组转换为Cstring型变量
		{
			CFile file;
			CString tempstr;
			CString qwe;
			BYTE a=* (char *)(data+i);
			BYTE b=* (char *)(data+(++i));
		    float c=(float)a+(float)(b%12)/10;
			 m_mymeter.UpdateNeedle(c);
			//str.Format("%2.1f ",c);//将a格式化
			 str.Format( "%4d-%.2d-%.2d %.2d:%.2d:%.2d, %2.1f\n",systm.wYear, systm.wMonth, systm.wDay,systm.wHour, systm.wMinute, systm.wSecond,c);
			 m_ReceiveData+=str;
			if (str.GetLength()<5) str="0"+str;
			str = str.Right(5);
			 //m_ReceiveData+=str;
		//	m_ReceiveData2+=str;//将刚采集的数加到编辑框中
			LineHight[601]=a;
			Display();//对数据显示前的处理
			//将数据保存到文件中
			if (qwe.GetLength()>=600)//600个字符刚好对应120个数据
			{
				CStdioFile readfile; 
				CString readstr,readstr2;
				if(readfile.Open(FilePath,CFile::modeRead))
				{
					while(readfile.ReadString(readstr))//逐行查询，至到文件尾
					{
						readstr2+=readstr;
					}
					readfile.Close();
				}

				if (file.Open(FilePath,CFile::modeCreate|CFile::modeReadWrite))
				{
					file.Write(readstr2,readstr2.GetLength());//原来的数据
 					file.Write(m_ReceiveData,600);//写入新的120个数据
					file.Close();
					m_ReceiveData="";//清除编辑框内容
					break;
				}
			}
		}
	}
	UpdateData(FALSE);//更新编辑框内容
}

//开串口程序
void CCommDlg::OnButton1() 
{
	if( !m_Comm.GetPortOpen())
	{
		m_Comm.SetPortOpen(TRUE);//打开串口
		SetDlgItemText(IDC_BUTTON1,"关闭串口");
	}
	else
	{
		m_Comm.SetPortOpen(FALSE);
		SetDlgItemText(IDC_BUTTON1,"打开串口");
	}
}


//选择那一个串口程序
void CCommDlg::OnComselect() 
{
	if(m_Comm.GetPortOpen())
	m_Comm.SetPortOpen(FALSE);
	m_Comm.SetCommPort(m_com.GetCurSel()+1);
}

//选择波特率
void CCommDlg::OnComspeed() 
{
	CString temp;
	int i=m_speed.GetCurSel();
	switch(i)
	{
	case 0:
		speed=2400;
		break;
	case 1:
		speed=4800;
		break;
	case 2:
		speed=9600;
		break;
	case 3:
		speed=19200;
		break;
	case 4:
		speed=38400;
		break;
	}
	temp.Format("%d,n,8,1",speed);
	m_Comm.SetSettings(temp);
}

//停止/继续程序
void CCommDlg::OnStoprecv()
{
	if (stop==TRUE)
	{
		NextTime=gogo;
		m_ReceiveData=DTemp;
		for (int i=0;i<120;i++) LineHight[i]=LHTemp[i];
	}
	stop=!stop;
	if (stop==TRUE) SetDlgItemText(IDC_STOPRECV,"继续显示");
	else  SetDlgItemText(IDC_STOPRECV,"停止显示");
}

//对数据显示前的处理:将新数年据加到左边,原来的右移一位
void CCommDlg::Display()
{
	if (NextTime <= 600 && stop==FALSE)
	{
		LineHight[NextTime] = LineHight[601];
	}
	else
	{
		for (int i=0;i<600;i++)
		{
			LineHight[i] = LineHight[i+1];
		}
		LineHight[600]=LineHight[601];
	}
	NextTime = NextTime+1;
	this->Invalidate();
	return;
}


void CCommDlg::OnButton8() 
{
	if (stop==TRUE)
	{
		m_ReceiveData=DTemp;
		NextTime=gogo;
		if (NextTime<600) NextTime=600;
		for (int i=0;i<120;i++) LineHight[i]=LHTemp[i];
		UpdateData(FALSE);//更新编辑框内容
		this->Invalidate();//更新图相
	}
}

void CCommDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//MessageBox("adsfadf");	
	m_mymeter.UpdateNeedle(q[i++]) ;	
	//CDialog::OnTimer(nIDEvent);
}

void CCommDlg::Display_meter()
{
	UpdateData(true);
//	m_mymeter.UpdateNeedle(m_input) ;
	OnPaint();
}


void CCommDlg::OnClose() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();	
}
