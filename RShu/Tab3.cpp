// Tab3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RShu.h"
#include "Tab3.h"
#include "afxdialogex.h"


// CTab3 �Ի���

IMPLEMENT_DYNAMIC(CTab3, CDialogEx)

CTab3::CTab3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CTab3::~CTab3()
{
}

void CTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_TITLE1, m_title);
}

void CTab3::InitTable()
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


BEGIN_MESSAGE_MAP(CTab3, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CTab3::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTab3 ��Ϣ�������


void CTab3::OnPaint()
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
	pDC->BitBlt(0, 0, 200, 150, &MemDC, 0, 0, SRCAND);
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}

void CTab3::ShowText(CString str)
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


void CTab3::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// , *oldBmp;

	MemDC.CreateCompatibleDC(pDC); //����һ�����ݵ��ڴ��豸������

	bm.CreateCompatibleBitmap(pDC, 100, 100); //����һ�����ݵ�DDB

	//oldBmp = 
	MemDC.SelectObject(&bm);

	MemDC.SelectStockObject(BLACK_PEN);

	MemDC.SelectStockObject(GRAY_BRUSH);

	MemDC.Rectangle(0, 0, 50, 50); //��DDB�л�һ������

	pDC->BitBlt(0, 0, 200, 150, &MemDC, 0, 0, SRCAND);

	//MemDC.SelectObject(oldBmp); //ʹλͼbm���������豸������

}
