#pragma once
#include "RTree.h"

// CTab1 �Ի���

class CTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab1)

public:
	CTab1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTab1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CRect m_paintarea;
	bool m_bDraw = false;
	bool m_bFirstDraw = false;
	CPoint m_ptOrigin;
	CRect m_rect;
	long m_dif;
	RTree m_rtree;
};
