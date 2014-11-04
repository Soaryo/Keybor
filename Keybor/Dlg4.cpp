// Dlg4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Keybor.h"
#include "KeyborDlg.h"
#include "Dlg4.h"
#include "Afx.h"
#include "XMessageBox.h"

// CDlg4 �Ի���

IMPLEMENT_DYNAMIC(CDlg4, CDialog)

CDlg4::CDlg4(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg4::IDD, pParent)
	, m_cTime(_T(""))
	, m_hHour(_T(""))
	, m_hMinute(_T(""))
	, m_combo(_T("�ػ�"))
{
	timem = 0;
}

CDlg4::~CDlg4()
{
}

void CDlg4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CTIME, m_cTime);
	DDX_Text(pDX, IDC_HOUR, m_hHour);
	DDX_Text(pDX, IDC_MINUTE, m_hMinute);
	DDX_Control(pDX, IDC_HOURSP, m_spinh);
	DDX_Control(pDX, IDC_MINUTESP, m_spinm);
	DDX_CBString(pDX, IDC_COMBO_KIND, m_combo);
}


BEGIN_MESSAGE_MAP(CDlg4, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlg4::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON12, &CDlg4::OnBnClickedButton12)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_COMBO_KIND, &CDlg4::OnCbnSelchangeComboKind)
END_MESSAGE_MAP()


// CDlg4 ��Ϣ�������

void CDlg4::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_HOUR,m_hHour);
	GetDlgItemText(IDC_MINUTE,m_hMinute);
	timeh = atoi(m_hHour);
	timem = atoi(m_hMinute);

	CTime ct = CTime::GetCurrentTime();
	int hour = ct.GetHour();
	int minute = ct.GetMinute();

	//XMessageBox
	XMSGBOXPARAMS xmb;
	xmb.nTimeoutSeconds = 2;
	xmb.crText = RGB(255,0,0);
	xmb.dwOptions |= XMSGBOXPARAMS::VistaStyle;

	if (m_hHour == _T("") /*|| m_hMinute == _T("")*/)
	{
		    //MessageBox(_T("���벻��Ϊ��"), _T("Keybor"), MB_ICONINFORMATION | MB_OK);
			XMessageBox(m_hWnd,  _T("���벻��Ϊ��!"), _T("Keybor"), MB_OK | MB_ICONINFORMATION, &xmb);
	}
	else if(timeh > 23 || timem >59)
	{
	        //MessageBox(_T("���볬����Χ"), _T("Keybor"), MB_ICONINFORMATION | MB_OK);
			XMessageBox(m_hWnd,  _T("���볬����Χ!"), _T("Keybor"), MB_OK | MB_ICONINFORMATION, &xmb);
	}
	else if(timeh == hour && timem == minute)
	{
			  //MessageBox(_T("���볬���߼���Χ"), _T("Keybor"), MB_ICONINFORMATION | MB_OK);
			  XMessageBox(m_hWnd,  _T("���볬���߼���Χ!"), _T("Keybor"), MB_OK | MB_ICONINFORMATION, &xmb);
	}
	else
	{
		if(timeh < hour || timeh == hour && timem < minute)
		{
		      timeh += 24;
		}
		isStar = TRUE;

		//ʹ�ؼ���Ч
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON1)->EnableWindow();
		GetDlgItem(IDC_HOUR)->EnableWindow(FALSE);
        GetDlgItem(IDC_MINUTE)->EnableWindow(FALSE);
		m_spinh.EnableWindow(FALSE);
		m_spinm.EnableWindow(FALSE);
	}

}

void CDlg4::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_BUTTON2)->EnableWindow();
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
    GetDlgItem(IDC_HOUR)->EnableWindow();
	GetDlgItem(IDC_MINUTE)->EnableWindow();
	m_spinh.EnableWindow();
	m_spinm.EnableWindow();
	SetDlgItemText(IDC_STIME, _T(""));
// 	if (isStar)   //������ùػ�ʱ��
// 	{
// 		SetDlgItemText(IDC_HOUR, _T(""));
// 		SetDlgItemText(IDC_MINUTE, _T(""));
// 	}
	isStar = FALSE;
}

void CDlg4::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CTime ct = CTime::GetCurrentTime();
	int year = ct.GetYear();
	int month = ct.GetMonth();
	int day = ct.GetDay();
	int hour = ct.GetHour();
	int minute = ct.GetMinute();
	int second = ct.GetSecond();
	CString y,m,d,h,mi,s;
	y.Format(_T("%d"),year);
	m.Format(_T("%d"),month);
	d.Format(_T("%d"),day);
	if (hour<10)
		h.Format(_T("0%d"),hour);
	else
		h.Format(_T("%d"),hour);
	if (minute<10)
		mi.Format(_T("0%d"),minute);
	else
		mi.Format(_T("%d"),minute);
	if (second<10)
		s.Format(_T("0%d"),second);
	else
		s.Format(_T("%d"),second);
	m_cTime = y + _T("-") + m + _T("-") + d + _T("    ") + h + _T(":") + mi + _T(":") + s;
	GetDlgItem(IDC_CTIME)->SetWindowText(m_cTime);
	if (isStar)
	{
		times = timeh*60*60+timem*60 - hour*60*60 - minute*60 -second;
		////time
		m_ltime.Format(_T("%d Сʱ %d ���� %d ��"), times/3600, times%3600/60, times%3600%60);
		GetDlgItem(IDC_STIME)->SetWindowText(m_ltime);
		//if (m_hHour.CompareNoCase(h) == 0 && m_hMinute.CompareNoCase(mi) == 0)
		if( times == 0 )
		{
			KillTimer(10);

			XMSGBOXPARAMS xmb;
	        xmb.nTimeoutSeconds = 10;
			xmb.crText = RGB(255,0,0);
			xmb.dwOptions |= XMSGBOXPARAMS::VistaStyle;
	        if(IDCANCEL == XMessageBox(m_hWnd,  _T("����")+m_combo+_T("����ȷ����?"), _T("��ʾ"), MB_OKCANCEL | MB_ICONEXCLAMATION, &xmb))
			{
			      OnBnClickedButton12();
				  SetTimer(10,1000,NULL);
				  return;
			}
			//MessageBox(_T("���Դ���"));  //���Դ���
			/////////��������3��ȫ�ֱ���///////////
			BOOL fResult;
			TOKEN_PRIVILEGES tkp;
			HANDLE hToken;
			if (!OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
			{
				//MessageBox(_T("OpenProcessToken failed!"));
			}

			LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,&tkp.Privileges[0].Luid); //��ñ��ػ�Ψһ�ı�ʶ
			tkp.PrivilegeCount = 1; 
			tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
			AdjustTokenPrivileges(hToken, FALSE, &tkp, 0,(PTOKEN_PRIVILEGES) NULL, 0); //������õ�Ȩ��

// 			if (GetLastError() != ERROR_SUCCESS)
// 			{
// 				MessageBox(_T("AdjustTokenPrivileges enable failed!"));
// 			}

			fResult =InitiateSystemShutdownA(
				NULL,                                  // Ҫ�صļ�����û���
				_T(""/*WINDOWS���������ʱ���ڹػ��������ñ��湤��!*/),  // ��ʾ����Ϣ
				0,                                    // �ػ������ʱ��
				FALSE,                                 // ask user to close apps
				m_combo == _T("�ػ�") ? FALSE : TRUE);                               //��ΪTRUEΪ������ΪFALSEΪ�ػ�
// 			if(!fResult)
// 			{
// 				MessageBox(_T("InitiateSystemShutdown failed."));
// 			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////
			tkp.Privileges[0].Attributes = 0;
			AdjustTokenPrivileges(hToken, FALSE, &tkp, 0,(PTOKEN_PRIVILEGES) NULL, 0);

// 			if (GetLastError() != ERROR_SUCCESS)
// 			{
// 				MessageBox(_T("AdjustTokenPrivileges disable failed."));
// 			}

			ExitWindowsEx(EWX_SHUTDOWN|EWX_POWEROFF,0);
		}
	}

	CDialog::OnTimer(nIDEvent);
}
//Dlg4��ʼ��
BOOL CDlg4::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_cTime = _T("");
	m_hHour = _T("");
	m_hMinute = _T("");
	m_ltime = _T("");
	isStar = FALSE;
	timeh = 0;
	timem = 0;
	times = 0;
	SetTimer(10,1000,NULL);
	//���ñ�ִ�����񼭿��ʼʱ��
	SetEditTime();
	//����Spin������Χ
	m_spinh.SetRange(0, 23);
	m_spinm.SetRange(0, 59);
	return TRUE;
}

void CDlg4::OnOK()
{

}

void CDlg4::OnCancel()
{

}

HBRUSH CDlg4::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd->GetDlgCtrlID() == IDC_STIME) //���þ�̬�ı��ؼ���ʣ��ػ�ʱ�䡱����ɫ
	{
			pDC->SetTextColor(RGB(255,0,0));//����ɫ
	}
	if(nCtlColor == CTLCOLOR_DLG || nCtlColor == CTLCOLOR_STATIC)
	{

		pDC->SetBkColor(RGB(245,245,255));//���屳��ɫ******
		HBRUSH B = CreateSolidBrush(RGB(245,245,255)); //����ɫ
		return B;
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CDlg4::SetEditTime(void)
{
	CTime ct = CTime::GetCurrentTime();
	int hour = ct.GetHour();
	CString str;
	str.Format("%d", hour<23 ? hour+1 : 0);
	SetDlgItemText(IDC_HOUR, str);
	SetDlgItemText(IDC_MINUTE, _T("0"));
}


void CDlg4::OnCbnSelchangeComboKind()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*GetDlgItem(IDC_COMBO_KIND)->*/UpdateData(TRUE);
}
