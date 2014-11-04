// KeyborDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Keybor.h"
#include "KeyborDlg.h"
#include "Afx.h"
#include "BCMenu.h"
#include "XMessageBox.h"

#define WM_NOTIFYICON 111

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKeyborDlg �Ի���


CDlg1 dlg1;
CDlg2 dlg2;
CDlg3 dlg3;
CDlg4 dlg4;
CDlg5 dlg5;

CKeyborDlg::CKeyborDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKeyborDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CKeyborDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tab);
}

BEGIN_MESSAGE_MAP(CKeyborDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_NCPAINT()
//	ON_WM_LBUTTONDOWN()
	ON_MESSAGE(WM_NOTIFYICON,OnNotifyIcon)
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771,OnSet)
	ON_COMMAND(ID_32772,OnExit)
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CKeyborDlg::OnTcnSelchangeTab1)
	ON_WM_CLOSE()
	ON_COMMAND(ID_32773, &CKeyborDlg::OnQuitTime)
	ON_MESSAGE(WM_HOTKEY,OnHotKey)
	ON_COMMAND(ID_32779, &CKeyborDlg::On32779)
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// CKeyborDlg ��Ϣ�������

BOOL CKeyborDlg::OnInitDialog()
{
	
	CDialog::OnInitDialog();
 
	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_tab.InsertItem(0," �������� "); //��Ӳ���һѡ� 
    m_tab.InsertItem(1," ���ӳ�� "); //��Ӳ�����ѡ� 
	m_tab.InsertItem(2," �ƻ����� "); 
	m_tab.InsertItem(3," ��չӦ�� ");
    m_tab.InsertItem(4," ���� "); //��ӽ��ѡ� 

	//�����Ի���,���ҽ�IDC_TAB�ؼ���Ϊ������ 
	dlg1.Create(IDD_DIALOG1,GetDlgItem(IDC_TAB)); 
	dlg2.Create(IDD_DIALOG2,GetDlgItem(IDC_TAB)); 
	dlg4.Create(IDD_DIALOG4,GetDlgItem(IDC_TAB)); 
	dlg5.Create(IDD_DIALOG5,GetDlgItem(IDC_TAB));
	dlg3.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB)); 

	//���IDC_TABTEST�ͻ�����С 
	CRect rs; 
	m_tab.GetClientRect(&rs ); 
	//�����ӶԻ����ڸ������е�λ�� 
	rs.top+=22; 
	rs.bottom+=30; 
	//rs.left+=1; 
	//rs.right-=2; 

	//�����ӶԻ���ߴ粢�ƶ���ָ��λ�� 
	dlg1.MoveWindow(&rs); 
	dlg2.MoveWindow(&rs); 
	dlg3.MoveWindow(&rs); 
	dlg4.MoveWindow(&rs);
	dlg5.MoveWindow(&rs);

	//�ֱ��������غ���ʾ  
	dlg1.ShowWindow(true);
	dlg2.ShowWindow(false); 
	dlg3.ShowWindow(false); 
	dlg4.ShowWindow(false); 
	dlg5.ShowWindow(false);

	//����Ĭ�ϵ�ѡ� 
	m_tab.SetCurSel(0);

    CString m_good;
	CTime ct = CTime::GetCurrentTime();
	int hour = ct.GetHour();
	if(hour>=0 && hour<6)
		m_good="�賿�ã���ҹ��ǿ����ע����Ϣ��";
	else if(hour>=6 && hour<8)
		m_good="���Ϻã����ʱ��ÿ��鰡��";
	else if(hour>=8 && hour<11)
		m_good="����ã������徻�����Ǻǣ�";
	else if(hour>=11 && hour<13)
		m_good="����ã���������Ϣʱ�俩��";
	else if(hour>=13 && hour<19)
		m_good="����ã��ٺ�";
	else if(hour>=19)
		m_good="���Ϻã�����̫���ˣ����˯��lo��";

	notifydata.cbSize=sizeof(NOTIFYICONDATA);
	notifydata.hWnd=this->m_hWnd;
	notifydata.uCallbackMessage=WM_NOTIFYICON;
	notifydata.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP;
	notifydata.uID=IDI_ICON1;
	notifydata.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON1));
	strcpy_s(notifydata.szTip," Keybor for you");
	Shell_NotifyIconA(NIM_ADD,&notifydata);

	if(GetPrivateProfileIntA("System","Balloon",1,CAfx::filepath))
	{
		ShowBalloonTip("�𾴵Ŀͻ�"+m_good,"Keybor", 3000, 1);//����������ʾ
	}

//*******************************��ȡ�Ի�������*********************************//
	RECT rect;
	rect.left=GetPrivateProfileIntA("System","PosX",0,CAfx::filepath);
	rect.top=GetPrivateProfileIntA("System","PosY",0,CAfx::filepath);
	rect.right=rect.left+473;
	rect.bottom=rect.top+362;
	MoveWindow(&rect);

    UpdateWindow();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

BOOL CKeyborDlg::ShowBalloonTip(LPCTSTR szMsg, LPCTSTR szTitle, UINT uTimeout, DWORD dwInfoFlags)
{
	//notifydata.cbSize=sizeof(NOTIFYICONDATA);
	notifydata.uFlags = NIF_INFO;
	notifydata.uTimeout = uTimeout;
	notifydata.dwInfoFlags = dwInfoFlags;
	strcpy_s(notifydata.szInfo,szMsg ? szMsg : _T(""));
	strcpy_s(notifydata.szInfoTitle,szTitle ? szTitle : _T(""));
	return Shell_NotifyIcon(NIM_MODIFY, &notifydata);
}

void CKeyborDlg::SetszTip(LPCTSTR str)
{
// 	notifydata.uFlags=NIF_TIP;
// 	strcpy_s(notifydata.szTip,str);
// 	Shell_NotifyIconA(NIM_MODIFY,&notifydata);
}

void CKeyborDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if(nID==SC_CLOSE)
	{
        ShowWindow(SW_HIDE);
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CKeyborDlg::OnPaint()
{		


		if (IsIconic())
		{
			CPaintDC dc(this); // ���ڻ��Ƶ��豸������
			SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

			// ʹͼ���ڹ����������о���
			int cxIcon = GetSystemMetrics(SM_CXICON);
			int cyIcon = GetSystemMetrics(SM_CYICON);
			CRect rect;
			GetClientRect(&rect);
			int x = (rect.Width() - cxIcon + 1) / 2;
			int y = (rect.Height() - cyIcon + 1) / 2;

			// ����ͼ��
			dc.DrawIcon(x, y, m_hIcon);
		}
		else
		{
			CDialog::OnPaint();
		}
}

void CKeyborDlg::OnNcPaint() 
{
      // TODO: Add your message handler code here
	//**********************���ش���************************//
	 if(GetPrivateProfileIntA("System","Hide",1,CAfx::filepath))
	 {
     static int i = 2; 
      if(i>0) 
      { 
           i--;
           ShowWindow(SW_HIDE); 
      } 
	 }
    CDialog::OnNcPaint();
}



//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CKeyborDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CKeyborDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int CurSel = m_tab.GetCurSel(); 
	switch(CurSel) 
	{ 
	case 0: 
	dlg1.ShowWindow(true);
	dlg2.ShowWindow(false); 
	dlg3.ShowWindow(false); 
	dlg4.ShowWindow(false);
	dlg5.ShowWindow(false);
	::SetFocus(NULL);
	break; 
	case 1: 
	dlg1.ShowWindow(false);    
	dlg2.ShowWindow(true); 
	dlg3.ShowWindow(false); 
	dlg4.ShowWindow(false);
	dlg5.ShowWindow(false);
	::SetFocus(NULL);
	break; 
	case 2: 
	dlg1.ShowWindow(false);     
	dlg2.ShowWindow(false);    
	dlg3.ShowWindow(false); 
	dlg4.ShowWindow(true);
	dlg5.ShowWindow(false);
	::SetFocus(NULL);
	break; 
	case 3: 
	dlg1.ShowWindow(false); 
	dlg2.ShowWindow(false);     
	dlg3.ShowWindow(false); 
	dlg4.ShowWindow(false); 
	dlg5.ShowWindow(true);
	::SetFocus(NULL);
	break; 
	case 4: 
		dlg1.ShowWindow(false);     
		dlg2.ShowWindow(false);    
		dlg3.ShowWindow(true); 
		dlg4.ShowWindow(false);
		dlg5.ShowWindow(false);
		::SetFocus(NULL);
		break; 
	default: 
	; 
	} 

	*pResult = 0;
}

//void CKeyborDlg::OnLButtonDown(UINT nFlags, CPoint point) 
//{
//    // ���ø��ദ������ɻ�������
//    CDialog::OnLButtonDown(nFlags, point);
//
//    // ����WM_NCLBUTTONDOWN��Ϣ
//    // ʹWindows��Ϊ����ڱ�������
//    PostMessage(WM_NCLBUTTONDOWN,HTCAPTION, MAKELPARAM(point.x, point.y));
//}

LRESULT CKeyborDlg::OnNotifyIcon(WPARAM wParam,LPARAM lParam)
{
	//����������
	 if((lParam==WM_LBUTTONDOWN)&&(!ShowWindow(SW_HIDE)))
	 { 	
             OnSet();
	 }

	//��굥���Ҽ�
	 if(lParam==WM_RBUTTONDOWN)
	 {
		  //  �����˵�
		  POINT rpoint;
	      GetCursorPos(&rpoint);
	      BCMenu mu;
		  mu.LoadMenu(IDR_MENU1);
          SetForegroundWindow();
		  mu.GetSubMenu(0)->SetDefaultItem(ID_32779);
		  mu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,rpoint.x,rpoint.y,this);
	 }
	 
	 return 0;

}


void CKeyborDlg::OnExit()
{    
		XMSGBOXPARAMS xmb;
		//xmb.nTimeoutSeconds  = 3;
		//xmb.nDisabledSeconds = 0;
		xmb.nIdIcon          = 0;
	
 	    //xmb.x = 50;
 	    //xmb.y = 20;
	
		xmb.dwOptions |= XMSGBOXPARAMS::VistaStyle;
	
		if( IDOK == ::XMessageBox(m_hWnd, _T("ȷ���˳�Keybor��"), _T("��ʾ"), 
						MB_OKCANCEL | MB_ICONQUESTION, &xmb))
		{
//************************************����Ի�������**********************************//
			CString rt1,rt2/*,rt3,rt4*/;
			RECT r;
			GetWindowRect(&r);
			rt1.Format("%d",r.left);
			rt2.Format("%d",r.top);
			///////////////////////////�������Ի����Ⱥ͸߶�
// 			rt3.Format("%d",r.right-r.left);
// 			rt4.Format("%d",r.bottom-r.top);
// 			MessageBox(rt3,rt4,0);
			WritePrivateProfileStringA("System","PosX",rt1,CAfx::filepath);
			WritePrivateProfileStringA("System","PosY",rt2,CAfx::filepath);
//***************************************************************************************//
			SendMessage(WM_CLOSE);
		}
}
void CKeyborDlg::OnSet()
{
	    AfxGetMainWnd()->ShowWindow(SW_MINIMIZE);
	    //AnimateWindow( 500,   AW_BLEND);   //����
		//Invalidate();
	    AfxGetMainWnd()->ShowWindow(SW_RESTORE);		 
		::SetFocus(NULL);			
}

void CKeyborDlg::OnOK()
{

}

void CKeyborDlg::OnCancel()
{
	   AnimateWindow(500,   AW_BLEND   |   AW_HIDE   );   //����
}
	
void CKeyborDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialog::OnOK();
	Shell_NotifyIcon(NIM_DELETE,&notifydata);
}

void CKeyborDlg::OnQuitTime()
{
	// TODO: �ڴ���������������
	dlg4.OnBnClickedButton12();
}

LRESULT CKeyborDlg::OnHotKey(WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//if(wParam==1014)

	if (!ShowWindow(SW_HIDE))
		OnSet();

    return 0;
}
void CKeyborDlg::On32779()
{
	// TODO: �ڴ���������������
	if(CAfx::m_reg)
	{
		  CAfx::UnRegister();
	      CAfx::m_reg=FALSE;
	}
	else
	{
		  CAfx::Register();
          CAfx::m_reg=TRUE;
	}
}

LRESULT CKeyborDlg::OnNcHitTest(CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
       CRect rc;
	   GetClientRect(&rc);
	   ClientToScreen(&rc);
	   return rc.PtInRect(point) ? HTCAPTION : CDialog::OnNcHitTest(point);
}
