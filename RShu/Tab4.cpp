// Tab4.cpp : 实现文件
//

#include "stdafx.h"
#include "RShu.h"
#include "Tab4.h"
#include "afxdialogex.h"


// CTab4 对话框

IMPLEMENT_DYNAMIC(CTab4, CDialogEx)

CTab4::CTab4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

CTab4::~CTab4()
{
}

void CTab4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_TITLE1, m_title);
}

void CTab4::InitTable()
{
	pPic->GetClientRect(r);
	pDC->Rectangle(r);
	r.top += 100;
	r.bottom -= 90;
	r.left += 100;
	r.right -= 60;
	pDC->Rectangle(r);

	dif_x = (r.right - r.left) / 9;
	dif_y = (r.bottom - r.top) / 5;
}

BEGIN_MESSAGE_MAP(CTab4, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CTab4::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTab4 消息处理程序

void CTab4::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
	CFont  font;
	font.CreatePointFont(100, _T("微软雅黑"));     //选择字体
	m_edit.SetFont(&font);
	font.CreatePointFont(150, _T("微软雅黑"));
	m_title.SetFont(&font);

	pPic = (CStatic*)GetDlgItem(IDC_STATIC);//获取控件
	pDC = pPic->GetWindowDC();//获取设备环境
							  //pPic->GetClientRect(r);
	if (firstrun)
	{
		InitTable();
		firstrun = false;
	}
	// 不为绘图消息调用 CDialogEx::OnPaint()
}

void CTab4::ShowText(CString str)
{
	m_text += str;
	m_text += "\r\n";
	m_edit.SetWindowTextW(m_text);
	m_edit.SetSel(-1);
	MSG   msg;
	while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}


void CTab4::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}
