
// RShuDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "Tab1.h"
#include "Tab2.h"
#include "Tab3.h"
#include "Tab4.h"
#include "Tab5.h"

// CRShuDlg �Ի���
class CRShuDlg : public CDialogEx
{
// ����
public:
	CRShuDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RSHU_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CTab1 m_tab1;
	CTab2 m_tab2;
	CTab3 m_tab3;
	CTab4 m_tab4;
	CTab5 m_tab5;
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
};
