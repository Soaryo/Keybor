#pragma once
#include "HyperLink.h"

// CDlg3 �Ի���

class CDlg3 : public CDialog
{
	DECLARE_DYNAMIC(CDlg3)

public:
	CDlg3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlg3();
	virtual BOOL OnInitDialog();
// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedButton1();
	DECLARE_MESSAGE_MAP()
public:
    CHyperLink m_here;
	BOOL CreateLink(LPSTR   szPath, LPSTR   szLink);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
