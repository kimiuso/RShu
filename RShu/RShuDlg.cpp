
// RShuDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RShu.h"
#include "RShuDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRShuDlg 对话框



CRShuDlg::CRShuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RSHU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRShuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tab);
}

BEGIN_MESSAGE_MAP(CRShuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CRShuDlg::OnTcnSelchangeTab)
END_MESSAGE_MAP()


// CRShuDlg 消息处理程序

BOOL CRShuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	srand((unsigned)time(NULL));

	m_tab.InsertItem(0, _T("实验1"));
	m_tab.InsertItem(1, _T("实验2"));
	m_tab.InsertItem(2, _T("实验3"));
	m_tab.InsertItem(3, _T("实验4"));
	//m_tab.InsertItem(4, _T("小例子"));

	CRect rs;
	m_tab.GetClientRect(&rs);
	rs.top += 31;
	rs.bottom -= 11;
	rs.left += 10;
	rs.right -= 12;

	//////////////////////     tab1 小例子    //////////////////////
	m_tab1.Create(IDD_DIALOG1, GetDlgItem(IDC_TAB));
	m_tab1.MoveWindow(&rs);
	m_tab1.ShowWindow(0);

	//////////////////////     tab2  实验1   //////////////////////
	m_tab2.Create(IDD_DIALOG2, GetDlgItem(IDC_TAB));
	m_tab2.MoveWindow(&rs);
	m_tab2.ShowWindow(1);
	//////////////////////     tab3  实验2   //////////////////////
	m_tab3.Create(IDD_DIALOG3, GetDlgItem(IDC_TAB));
	m_tab3.MoveWindow(&rs);
	m_tab3.ShowWindow(0);
	//////////////////////     tab4  实验3     //////////////////////
	m_tab4.Create(IDD_DIALOG4, GetDlgItem(IDC_TAB));
	m_tab4.MoveWindow(&rs);
	m_tab4.ShowWindow(0);

	//////////////////////     tab5  实验4     //////////////////////
	m_tab5.Create(IDD_DIALOG5, GetDlgItem(IDC_TAB));
	m_tab5.MoveWindow(&rs);
	m_tab5.ShowWindow(0);

	//////////////////////          //////////////////////
	//////////////////////          //////////////////////
	//////////////////////          //////////////////////



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRShuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRShuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRShuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CRShuDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码

	int CurSel = m_tab.GetCurSel();
	switch (CurSel)
	{
	case 0:
		m_tab2.ShowWindow(true);
		m_tab3.ShowWindow(false);
		m_tab4.ShowWindow(false);
		m_tab5.ShowWindow(false);
		break;
	case 1:
		m_tab2.ShowWindow(false);
		m_tab3.ShowWindow(true);
		m_tab4.ShowWindow(false);
		m_tab5.ShowWindow(false);
		break;
	case 2:
		m_tab2.ShowWindow(false);
		m_tab3.ShowWindow(false);
		m_tab4.ShowWindow(true);
		m_tab5.ShowWindow(false);
		break;
	case 3:
		m_tab2.ShowWindow(false);
		m_tab3.ShowWindow(false);
		m_tab4.ShowWindow(false);
		m_tab5.ShowWindow(true);
		break;

	default:
		;
		//*pResult = 0;
	}

	*pResult = 0;
}
