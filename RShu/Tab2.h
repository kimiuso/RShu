#pragma once
#include "afxwin.h"
#include "RTree.h"
//#include "RShuDlg.h"

// CTab2 �Ի���

class CTab2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab2)

public:
	CTab2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTab2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CString m_text;
	CRect r;
	CStatic *pPic;
	CDC *pDC;
	long x_m;
	long y_m;
	long dif_x;
	long dif_y;

	//RTree m_rtree;
	afx_msg void OnBnClickedButton1();
	void ShowText(CString);
	long Test(int, int);
	afx_msg void OnPaint();
	int GetRand(int, int);
};
