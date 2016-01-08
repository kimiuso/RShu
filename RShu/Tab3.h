#pragma once
#include "afxwin.h"
#include "RTree.h"


// CTab3 对话框

class CTab3 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab3)

public:
	CTab3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTab3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
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
	afx_msg void OnPaint();
	void ShowText(CString);
	afx_msg void OnBnClickedButton1();
	int GetRand(int, int);
	long Test(int, int, long);
};
