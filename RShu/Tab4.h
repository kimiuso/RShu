#pragma once
#include "afxwin.h"

// CTab4 �Ի���

class CTab4 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab4)

public:
	CTab4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTab4();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:

	CEdit m_edit;
	CString m_text;
	CStatic *pPic;
	CDC *pDC;
	CRect r;
	long dif_x;
	long dif_y;
	bool firstrun = true;
	CStatic m_title;

	void InitTable();
	void ShowText(CString);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
};
