
// RShuDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RShu.h"
#include "RShuDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CRShuDlg �Ի���



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


// CRShuDlg ��Ϣ�������

BOOL CRShuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	srand((unsigned)time(NULL));

	m_tab.InsertItem(0, _T("ʵ��1"));
	m_tab.InsertItem(1, _T("ʵ��2"));
	m_tab.InsertItem(2, _T("ʵ��3"));
	m_tab.InsertItem(3, _T("ʵ��4"));
	//m_tab.InsertItem(4, _T("С����"));

	CRect rs;
	m_tab.GetClientRect(&rs);
	rs.top += 31;
	rs.bottom -= 11;
	rs.left += 10;
	rs.right -= 12;

	//////////////////////     tab1 С����    //////////////////////
	m_tab1.Create(IDD_DIALOG1, GetDlgItem(IDC_TAB));
	m_tab1.MoveWindow(&rs);
	m_tab1.ShowWindow(0);

	//////////////////////     tab2  ʵ��1   //////////////////////
	m_tab2.Create(IDD_DIALOG2, GetDlgItem(IDC_TAB));
	m_tab2.MoveWindow(&rs);
	m_tab2.ShowWindow(1);
	//////////////////////     tab3  ʵ��2   //////////////////////
	m_tab3.Create(IDD_DIALOG3, GetDlgItem(IDC_TAB));
	m_tab3.MoveWindow(&rs);
	m_tab3.ShowWindow(0);
	//////////////////////     tab4  ʵ��3     //////////////////////
	m_tab4.Create(IDD_DIALOG4, GetDlgItem(IDC_TAB));
	m_tab4.MoveWindow(&rs);
	m_tab4.ShowWindow(0);

	//////////////////////     tab5  ʵ��4     //////////////////////
	m_tab5.Create(IDD_DIALOG5, GetDlgItem(IDC_TAB));
	m_tab5.MoveWindow(&rs);
	m_tab5.ShowWindow(0);

	//////////////////////          //////////////////////
	//////////////////////          //////////////////////
	//////////////////////          //////////////////////



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRShuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRShuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CRShuDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

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
