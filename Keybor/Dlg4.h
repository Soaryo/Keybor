#pragma once


// CDlg4 �Ի���

class CDlg4 : public CDialog
{
	DECLARE_DYNAMIC(CDlg4)

public:
	CDlg4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlg4();
	virtual BOOL OnInitDialog();
	BOOL isStar;
	int timeh;
	int timem;
	int times;
	CString	m_ltime;
// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnOK();
	afx_msg void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	CString m_cTime;
	CString m_hHour;
	CString m_hMinute;
	afx_msg void OnBnClickedButton12();
	CSpinButtonCtrl m_spinh;
	CSpinButtonCtrl m_spinm;
	void SetEditTime(void);
	CString m_combo;
	afx_msg void OnCbnSelchangeComboKind();
};
