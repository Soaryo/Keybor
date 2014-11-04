// KeyborDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "Dlg1.h"
#include "Dlg2.h"
#include "Dlg3.h"
#include "Dlg4.h"
#include "Dlg5.h"
#include "Afx.h"


// CKeyborDlg �Ի���
class CKeyborDlg : public CDialog
{

// ����
public:
	CKeyborDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_KEYBOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
  
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	void OnSysCommand(UINT nID, LPARAM lParam);

	afx_msg void OnPaint();
	afx_msg void OnNcPaint();
	afx_msg HCURSOR OnQueryDragIcon();
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg LRESULT OnNotifyIcon(WPARAM wParam,LPARAM lParam);
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClose();
	afx_msg void OnQuitTime();
	afx_msg LRESULT OnHotKey(WPARAM wParam, LPARAM lParam);
	afx_msg void OnOK();
	afx_msg void OnCancel();
	afx_msg void On32777();
	afx_msg void On32779();
	DECLARE_MESSAGE_MAP()

public:
	NOTIFYICONDATA notifydata;
	CTabCtrl m_tab;

	void OnExit();
	void OnSet();
	BOOL ShowBalloonTip(LPCTSTR szMsg, LPCTSTR szTitle, UINT uTimeout, DWORD dwInfoFlags);
	static void SetszTip(LPCTSTR str);
	afx_msg LRESULT OnNcHitTest(CPoint point);
};
