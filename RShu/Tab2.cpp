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
	DDX_Control(pDX, IDC_TITLE1, m_title);
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

long CTab2::Test(int max, long n)
{
	int maxNode = max;
	RTree rtree(maxNode);
	long t1 = GetTickCount();//
	long t2 = 0;
	Rect r;
	/*CString str;
	str.Format(_T("内部节点最大条目数:%d,\r\n矩形数:%d："), max, n);
	ShowText(str);*/
	for (long i = 0; i < n; i++)
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
	font.CreatePointFont(150, _T("微软雅黑"));
	m_title.SetFont(&font);

	pPic = (CStatic*)GetDlgItem(IDC_STATIC);//获取控件
	pDC = pPic->GetWindowDC();//获取设备环境
	
	if(firstrun)
	{
		pPic->GetClientRect(r);
		x_m = r.Width();
		y_m = r.Height();
		MemDC.CreateCompatibleDC(pDC);
		bm.CreateCompatibleBitmap(pDC, x_m, y_m);
		MemDC.SelectObject(&bm);
		InitTable();
		firstrun = false;
	}
	pDC->BitBlt(0, 0, x_m, y_m, &MemDC, 0, 0, SRCAND);
					   // 不为绘图消息调用 CDialogEx::OnPaint()
}

int CTab2::GetRand(int MIN, int MAX)
{
	int max;

	max = RAND_MAX;//rand()函数随机数的最大值

	return (int)(rand()*(MAX - MIN) / max + MIN);
}

void CTab2::InitTable()
{
	pPic->GetClientRect(r);
	MemDC.Rectangle(r);
	r.top += 130;
	r.bottom -= 40;
	r.left += 100;
	r.right -= 60;
	MemDC.Rectangle(r);

	dif_x = (r.right - r.left) / 9;
	dif_y = (r.bottom - r.top) / 5;

	//int color[5][3] = { { 255,0,0 },{ 150,150,255 },{ 100,255,100 },{ 255,0,255 },{ 0,0,0 } };
	//long num[] = { 50000, 100000, 200000, 300000, 500000 };
	long x = -80;
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *pOldPen = MemDC.SelectObject(&pen);
	MemDC.MoveTo(r.left + x, r.top - 90);
	MemDC.LineTo(r.left + x + 35, r.top - 90);
	MemDC.TextOutW(r.left + x + 41, r.top - 97, _T("50000"));
	x += 100;

	pen.CreatePen(PS_SOLID, 1, RGB(100, 200, 100));
	MemDC.SelectObject(&pen);
	MemDC.MoveTo(r.left + x, r.top - 90);
	MemDC.LineTo(r.left + x + 35, r.top - 90);
	MemDC.TextOutW(r.left + x + 41, r.top - 97, _T("100000"));
	x += 110;

	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	MemDC.SelectObject(&pen);
	MemDC.MoveTo(r.left + x, r.top - 90);
	MemDC.LineTo(r.left + x + 35, r.top - 90);
	MemDC.TextOutW(r.left + x + 41, r.top - 97, _T("200000"));
	x += 110;

	pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 255));
	MemDC.SelectObject(&pen);
	MemDC.MoveTo(r.left + x, r.top - 90);
	MemDC.LineTo(r.left + x + 35, r.top - 90);
	MemDC.TextOutW(r.left + x + 41, r.top - 97, _T("300000"));
	x += 110;

	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	MemDC.SelectObject(&pen);
	MemDC.MoveTo(r.left + x, r.top - 90);
	MemDC.LineTo(r.left + x + 35, r.top - 90);
	MemDC.TextOutW(r.left + x + 41, r.top - 97, _T("500000"));
	


	MemDC.SelectObject(pOldPen);

	MemDC.TextOutW(r.left - 55, r.top - 50, _T("耗时/ms"));

	MemDC.TextOutW(r.left - 45, r.top - 10, _T("5000"));

	MemDC.MoveTo(r.left, r.top + dif_y);
	MemDC.LineTo(r.right, r.top + dif_y);
	MemDC.TextOutW(r.left - 45, r.top + dif_y * 1 - 10, _T("4000"));

	MemDC.MoveTo(r.left, r.top + dif_y * 2);
	MemDC.LineTo(r.right, r.top + dif_y * 2);
	MemDC.TextOutW(r.left - 45, r.top + dif_y * 2 - 10, _T("3000"));

	MemDC.MoveTo(r.left, r.top + dif_y * 3);
	MemDC.LineTo(r.right, r.top + dif_y * 3);
	MemDC.TextOutW(r.left - 45, r.top + dif_y * 3 - 10, _T("2000"));

	MemDC.MoveTo(r.left, r.top + dif_y * 4);
	MemDC.LineTo(r.right, r.top + dif_y * 4);
	MemDC.TextOutW(r.left - 45, r.top + dif_y * 4 - 10, _T("1000"));

	MemDC.TextOutW(r.left - 32, r.bottom - 10, _T("0"));

	MemDC.MoveTo(r.left + dif_x, r.bottom);
	MemDC.LineTo(r.left + dif_x, r.bottom - 10);
	MemDC.TextOutW(r.left + dif_x - 3, r.bottom, _T("5"));

	MemDC.MoveTo(r.left + dif_x * 2, r.bottom);
	MemDC.LineTo(r.left + dif_x * 2, r.bottom - 10);
	MemDC.TextOutW(r.left + dif_x * 2 - 7, r.bottom, _T("10"));

	MemDC.MoveTo(r.left + dif_x * 3, r.bottom);
	MemDC.LineTo(r.left + dif_x * 3, r.bottom - 10);
	MemDC.TextOutW(r.left + dif_x * 3 - 7, r.bottom, _T("20"));

	MemDC.MoveTo(r.left + dif_x * 4, r.bottom);
	MemDC.LineTo(r.left + dif_x * 4, r.bottom - 10);
	MemDC.TextOutW(r.left + dif_x * 4 - 7, r.bottom, _T("50"));

	MemDC.MoveTo(r.left + dif_x * 5, r.bottom);
	MemDC.LineTo(r.left + dif_x * 5, r.bottom - 10);
	MemDC.TextOutW(r.left + dif_x * 5 - 11, r.bottom, _T("100"));

	MemDC.MoveTo(r.left + dif_x * 6, r.bottom);
	MemDC.LineTo(r.left + dif_x * 6, r.bottom - 10);
	MemDC.TextOutW(r.left + dif_x * 6 - 11, r.bottom, _T("120"));

	MemDC.MoveTo(r.left + dif_x * 7, r.bottom);
	MemDC.LineTo(r.left + dif_x * 7, r.bottom - 10);
	MemDC.TextOutW(r.left + dif_x * 7 - 11, r.bottom, _T("150"));

	MemDC.MoveTo(r.left + dif_x * 8, r.bottom);
	MemDC.LineTo(r.left + dif_x * 8, r.bottom - 10);
	MemDC.TextOutW(r.left + dif_x * 8 - 11, r.bottom, _T("200"));

	MemDC.TextOutW(r.left + dif_x * 9 , r.bottom, _T("M值"));
}


void CTab2::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//1000000, 500000, 300000, 200000, 100000
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	m_text = "";
	CString str;
	long num[] = { 50000, 100000, 200000, 300000, 500000};
	long maxnode[] = { 5,10,20,50,100,120,150,200 };
	int color[5][3] = { {255,0,0},{ 100,200,100 },{ 0,0,255 },{ 255,0,255 },{ 0,0,0 } };

	//MemDC.CreateCompatibleDC(pDC);
	for (int i = 0; i < 5; i++)
	{
		
		str.Format(_T("矩形数:%d："), num[i]);
		ShowText(str);
		CPen pen(PS_SOLID, 1, RGB(color[i][0], color[i][1], color[i][2]));
		CPen *pOldPen = MemDC.SelectObject(&pen);
		//pDC->MoveTo(r.left + dif_x * i, i);

		for (int j = 0; j < 8; j++)
		{
			long t=Test(maxnode[j], num[i]);
			str.Format(_T("  内部节点最大条目数:%d：\r\n  耗时:%dms\r\n"), maxnode[j],t);
			ShowText(str);	
			long y = (long)((5000.0 - t) * dif_y / 1000+ r.top);
			if (j == 0)
			{
				MemDC.MoveTo(r.left + dif_x * (j + 1), y);
			}
			MemDC.LineTo(r.left + dif_x * (j + 1), y );
			pDC->BitBlt(0, 0, x_m, y_m, &MemDC, 0, 0, SRCAND);
			
		}
		MemDC.SelectObject(pOldPen);
	}
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);


}