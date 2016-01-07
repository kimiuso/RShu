// Tab2.cpp : 实现文件
//

#include "stdafx.h"
#include "RShu.h"
#include "Tab2.h"
#include "afxdialogex.h"


// CTab2 对话框

IMPLEMENT_DYNAMIC(CTab2, CDialogEx)

CTab2::CTab2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	
}

CTab2::~CTab2()
{
}

void CTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(CTab2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTab2::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CTab2 消息处理程序


void CTab2::ShowText(CString str)
{
	m_text += str;
	m_text += "\r\n";
	m_edit.SetWindowTextW(m_text);
	m_edit.SetSel(-1);
	///////////////////////////
	MSG   msg;
	while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	///////////////////////////////
}

long CTab2::Test(int max, int n)
{
	int maxNode = max;
	RTree rtree(maxNode);
	long t1 = GetTickCount();//
	long t2 = 0;
	Rect r;
	/*CString str;
	str.Format(_T("内部节点最大条目数:%d,\r\n矩形数:%d："), max, n);
	ShowText(str);*/
	for (int i = 0; i < n; i++)
	{
		int x0 = GetRand(0, 10000);
		int y0 = GetRand(0, 10000);
		int x1 = x0 + GetRand(0, 10);
		int y1 = y0 + GetRand(0, 10);
		r = { x0,y0,x1,y1 };
		t1 = GetTickCount();
		rtree.Insert(r);
		t2 += GetTickCount() - t1;
	}
	
	//str.Format(_T("耗时:%dms"), t2);//
	//ShowText(str);
	
	return t2;
}


void CTab2::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
	CFont  font;
	font.CreatePointFont(100,_T( "微软雅黑"));     //选择字体
	m_edit.SetFont(&font);


	pPic = (CStatic*)GetDlgItem(IDC_STATIC);//获取控件
	pDC = pPic->GetWindowDC();//获取设备环境
	//CRect r;
	pPic->GetClientRect(r);
	x_m = r.right - r.left;
	y_m = r.bottom - r.top;
	//pDC->MoveTo(30, y_m - 30);
	//pDC->LineTo(x_m - 30, y_m - 30);
	
	pDC->Rectangle(r);
	r.top += 130;
	r.bottom -= 60;
	r.left += 100;
	r.right -= 60;
	pDC->Rectangle(r);

	dif_x = (r.right - r.left) / 9;
	dif_y = (r.bottom - r.top) / 5;


	pDC->TextOutW(r.left - 55, r.top - 10, _T("5000"));

	pDC->MoveTo(r.left, r.top + dif_y);
	pDC->LineTo(r.right, r.top + dif_y);
	pDC->TextOutW(r.left - 55, r.top + dif_y * 1 - 10, _T("4000"));

	pDC->MoveTo(r.left, r.top + dif_y*2);
	pDC->LineTo(r.right, r.top + dif_y*2);
	pDC->TextOutW(r.left - 55, r.top + dif_y * 2 - 10, _T("3000"));

	pDC->MoveTo(r.left, r.top + dif_y * 3);
	pDC->LineTo(r.right, r.top + dif_y * 3);
	pDC->TextOutW(r.left - 55, r.top + dif_y * 3 - 10, _T("2000"));

	pDC->MoveTo(r.left, r.top + dif_y * 4);
	pDC->LineTo(r.right, r.top + dif_y * 4);
	pDC->TextOutW(r.left - 55, r.top + dif_y * 4 - 10, _T("1000"));

	pDC->TextOutW(r.left - 42, r.bottom - 10, _T("0"));

	pDC->MoveTo(r.left + dif_x, r.bottom);
	pDC->LineTo(r.left + dif_x, r.bottom - 10);
	pDC->TextOutW(r.left + dif_x - 3, r.bottom, _T("5"));

	pDC->MoveTo(r.left + dif_x * 2, r.bottom);
	pDC->LineTo(r.left + dif_x * 2, r.bottom - 10);
	pDC->TextOutW(r.left + dif_x * 2 - 7, r.bottom, _T("10"));

	pDC->MoveTo(r.left + dif_x * 3, r.bottom);
	pDC->LineTo(r.left + dif_x * 3, r.bottom - 10);
	pDC->TextOutW(r.left + dif_x * 3 - 7, r.bottom, _T("20"));

	pDC->MoveTo(r.left + dif_x * 4, r.bottom);
	pDC->LineTo(r.left + dif_x * 4, r.bottom - 10);
	pDC->TextOutW(r.left + dif_x * 4 - 7, r.bottom, _T("50"));

	pDC->MoveTo(r.left + dif_x * 5, r.bottom);
	pDC->LineTo(r.left + dif_x * 5, r.bottom - 10);
	pDC->TextOutW(r.left + dif_x * 5 - 11, r.bottom, _T("100"));

	pDC->MoveTo(r.left + dif_x * 6, r.bottom);
	pDC->LineTo(r.left + dif_x * 6, r.bottom - 10);
	pDC->TextOutW(r.left + dif_x * 6 - 11, r.bottom, _T("120"));

	pDC->MoveTo(r.left + dif_x * 7, r.bottom);
	pDC->LineTo(r.left + dif_x * 7, r.bottom - 10);
	pDC->TextOutW(r.left + dif_x * 7 - 11, r.bottom, _T("150"));

	pDC->MoveTo(r.left + dif_x * 8, r.bottom);
	pDC->LineTo(r.left + dif_x * 8, r.bottom - 10);
	pDC->TextOutW(r.left + dif_x * 8 - 11, r.bottom, _T("200"));
					   // 不为绘图消息调用 CDialogEx::OnPaint()
}

int CTab2::GetRand(int MIN, int MAX)
{
	int max;

	max = RAND_MAX;//rand()函数随机数的最大值

	return (int)(rand()*(MAX - MIN) / max + MIN);
}


void CTab2::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//int maxNode = 200;
	//RTree rtree(maxNode);
	//long t1 = GetTickCount();//
	//long t2=0;
	//Rect r;
	//for (int i = 0; i < 50000; i++)
	//{
	//	r = { i,i,i+1,i+1 };
	//	t1 = GetTickCount();
	//	rtree.Insert(r);
	//	t2 += GetTickCount() - t1;
	//}
	//CString str;
	//str.Format(_T("time:%dms"), t2);//
	//ShowText(str);

	//1000000, 500000, 300000, 200000, 100000
	m_text = "";
	CString str;
	long num[] = { 100000, 200000, 300000, 500000, 1000000 };
	long maxnode[] = { 5,10,20,50,100,120,150,200 };
	for (int i = 0; i < 5; i++)
	{
		
		str.Format(_T("矩形数:%d："), num[i]);
		ShowText(str);
		//pDC->MoveTo(r.left + dif_x * i, i);
		for (int j = 0; j < 8; j++)
		{
			long t=Test(maxnode[j], num[i]);
			str.Format(_T("内部节点最大条目数:%d：\r\n耗时:%d\r\n"), maxnode[j],t);
			ShowText(str);	
			if (j == 0)
			{
				pDC->MoveTo(r.left + dif_x * (j + 1), (5000 - t) * dif_y / 1000 + r.top);
			}
			pDC->LineTo(r.left + dif_x * (j + 1), (5000 - t) * dif_y / 1000  + r.top);
			
		}
	}
	
	/*Test(5, 500000);
	Test(10, 500000);
	Test(20, 500000);
	Test(50, 500000);
	Test(100, 500000);
	Test(120, 500000);
	Test(150, 500000);
	Test(200, 1000000);*/
	
	
	

	



}