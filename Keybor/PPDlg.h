#pragma once



// CPPDlg �Ի���

class CPPDlg : public CDialog
{
	DECLARE_DYNAMIC(CPPDlg)

public:
	CPPDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPPDlg();
	virtual BOOL OnInitDialog();
// �Ի�������
	enum { IDD = IDD_VOL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_p;
	afx_msg void OnPaint();
};
