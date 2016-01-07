// Tab5.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RShu.h"
#include "Tab5.h"
#include "afxdialogex.h"


// CTab5 �Ի���

IMPLEMENT_DYNAMIC(CTab5, CDialogEx)

CTab5::CTab5(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

CTab5::~CTab5()
{
}

void CTab5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_TITLE1, m_title);
}

void CTab5::InitTable()
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


BEGIN_MESSAGE_MAP(CTab5, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CTab5::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTab5 ��Ϣ�������

void CTab5::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
	CFont  font;
	font.CreatePointFont(100, _T("΢���ź�"));     //ѡ������
	m_edit.SetFont(&font);
	font.CreatePointFont(150, _T("΢���ź�"));
	m_title.SetFont(&font);

	pPic = (CStatic*)GetDlgItem(IDC_STATIC);//��ȡ�ؼ�
	pDC = pPic->GetWindowDC();//��ȡ�豸����
							  //pPic->GetClientRect(r);
	if (firstrun)
	{
		InitTable();
		firstrun = false;
	}
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}

void CTab5::ShowText(CString str)
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

void CTab5::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}