#pragma once
#include "afxwin.h"
#include "RTree.h"
// CTab5 对话框

class CTab5 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab5)

public:
	CTab5(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTab5();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	CEdit m_edit;
	CString m_text;
	CStatic *pPic;
	CDC *pDC;
	CRect r;
	long dif_x;
	long dif_y;
	long x_m;
	long y_m;
	bool firstrun = true;
	CStatic m_title;
	CDC MemDC;
	CBitmap bm;

	void InitTable();
	void ShowText(CString);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
	int GetRand(int, int);
	long Test(int, int, long);
};
