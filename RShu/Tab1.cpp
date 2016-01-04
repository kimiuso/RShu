// Tab1.cpp : 实现文件
//

#include "stdafx.h"
#include "RShu.h"
#include "Tab1.h"
#include "afxdialogex.h"


// CTab1 对话框

IMPLEMENT_DYNAMIC(CTab1, CDialogEx)

CTab1::CTab1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CTab1::~CTab1()
{
}

void CTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTab1, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CTab1 消息处理程序


void CTab1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
	//
	GetClientRect(&m_paintarea);
	m_paintarea.top += 100;
	m_paintarea.bottom -= 20;
	m_paintarea.left += 80;
	m_paintarea.right = m_paintarea.right / 3 + 150;
	dc.FillSolidRect(m_paintarea, RGB(100, 100, 255));
	
	CRect   rect;
	rect = m_paintarea;
	m_dif = m_paintarea.right - m_paintarea.left + 80;
	rect.left += m_dif;
	rect.right += m_dif;
	dc.FillSolidRect(rect, RGB(100, 200, 100));


					   // 不为绘图消息调用 CDialogEx::OnPaint()
}


void CTab1::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.y <= m_paintarea.bottom &&
		point.y >= m_paintarea.top &&
		point.x <= m_paintarea.right &&
		point.x >= m_paintarea.left)
	{
		m_bFirstDraw = TRUE;
		m_bDraw = TRUE;
		m_ptOrigin = point;
		CRect r = m_paintarea;
		ClientToScreen(&r);
		ClipCursor(&r);
		//CString cstr;
		//cstr.Format(_T("%ld"), point.x);
		//m_xy.SetWindowTextW(cstr);
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CTab1::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.y <= m_paintarea.bottom &&
		point.y >= m_paintarea.top &&
		point.x <= m_paintarea.right &&
		point.x >= m_paintarea.left)
	{
		m_bDraw = FALSE;
		CClientDC dc(this);
		CRect rect(0, 0, 0, 0);
		dc.DrawDragRect(rect, CSize(1, 1), m_rect, CSize(1, 1), NULL, NULL);
		CPen pen(PS_SOLID, 1, RGB(234, 23, 53));
		CPen *pOldPen = dc.SelectObject(&pen);
		CBrush *pBrush = CBrush::FromHandle((HBRUSH)
			GetStockObject(NULL_BRUSH));
		CBrush *pOldBrush = dc.SelectObject(pBrush);//保存原有画刷 
		dc.Rectangle(m_rect);


		m_rect.left += m_dif;
		m_rect.right += m_dif;
		dc.Rectangle(m_rect);

		dc.SelectObject(pOldPen);
		dc.SelectObject(pOldBrush);//恢复原有画刷 
		m_rect = rect;
		ClipCursor(NULL);
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CTab1::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.y <= m_paintarea.bottom &&
		point.y >= m_paintarea.top &&
		point.x <= m_paintarea.right &&
		point.x >= m_paintarea.left)
	{
		if (m_bDraw == TRUE)
		{
			CClientDC dc(this);
			CRect rect(m_ptOrigin, point);
			rect.NormalizeRect();                                  // 使矩形区域正常，如从下往上拖动鼠标 
			CBrush brush;
			//brush.CreateSolidBrush(RGB(255, 0, 0));   //从颜色生成画刷 
			LOGBRUSH logBrush;
			logBrush.lbStyle = BS_HATCHED;
			logBrush.lbColor = RGB(0, 192, 192);
			logBrush.lbHatch = HS_CROSS;
			//brush.CreateBrushIndirect(&logBrush); 
			brush.CreateStockObject(RGB(255, 0, 0));
			if (m_bFirstDraw == TRUE)
			{
				m_bFirstDraw = FALSE;
				dc.DrawDragRect(rect, CSize(1, 1), NULL, CSize(1, 1), NULL, NULL);
			}
			else
			{
				dc.DrawDragRect(rect, CSize(1, 1), m_rect, CSize(1, 1), NULL, NULL);
				//dc.DrawDragRect(CRect(0, 0, 0, 0), CSize(1, 1), m_rect, CSize(1, 1), NULL, NULL); 
				//dc.Rectangle(rect); 
			}
			m_rect.CopyRect(rect);

			//CString cstr;
			//cstr.Format(_T("%d,%d"), point.x, m_paintarea.bottom - point.y);
			//m_xy.SetWindowTextW(cstr);
		}


	}
	CDialogEx::OnMouseMove(nFlags, point);
}
