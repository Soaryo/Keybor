// Dlg5.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Keybor.h"
#include "Dlg5.h"
#include "Afx.h"
#include "LoadDlg.h"
// CDlg5 �Ի���

IMPLEMENT_DYNAMIC(CDlg5, CDialog)

CDlg5::CDlg5(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg5::IDD, pParent)
{

}

CDlg5::~CDlg5()
{
}

void CDlg5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SET, m_set);
	DDX_Control(pDX, IDC_SET2, m_set2);
}


BEGIN_MESSAGE_MAP(CDlg5, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg5::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON14, &CDlg5::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON11, &CDlg5::OnBnClickedButton11)
	ON_STN_CLICKED(IDC_SET, &CDlg5::OnStnClickedSet)
	ON_BN_CLICKED(IDC_BUTTON13, &CDlg5::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlg5::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON12, &CDlg5::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON15, &CDlg5::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON17, &CDlg5::OnBnClickedButton17)
	ON_STN_CLICKED(IDC_SET2, &CDlg5::OnStnClickedSet2)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlg5 ��Ϣ�������


BOOL CDlg5::OnInitDialog()
{
	    CDialog::OnInitDialog();
		 //PcStart();      ////��ʼ���з��Ϳ�����ʾ�ʼ�

		m_bt1.SubclassDlgItem(IDC_BUTTON1, this);
		m_bt1.SetIcon(IDI_XKJS);
		m_bt1.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt1.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt1.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt1.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt1.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt1.EnableBalloonTooltip();
		m_bt1.SetTooltipText(_T("�ǿռ��������ƽ�\r\n�ں�MD5ת��"));
		m_bt1.SetRounded(TRUE,FALSE);		

		m_bt2.SubclassDlgItem(IDC_BUTTON11, this);
		m_bt2.SetIcon(IDI_JSBH);
		m_bt2.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt2.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt2.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt2.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt2.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt2.EnableBalloonTooltip();
		m_bt2.SetTooltipText(_T("���ٲ���\r\n���ųɹ�����ռ��ϵͳ��Դ��"));
		m_bt2.SetRounded(TRUE,FALSE);

		m_bt3.SubclassDlgItem(IDC_BUTTON13, this);
		m_bt3.SetIcon(IDI_JHGJ);
		m_bt3.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt3.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt3.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt3.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt3.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt3.EnableBalloonTooltip();
		m_bt3.SetTooltipText(_T("���ö�ʱ�رռ����"));
		m_bt3.SetRounded(TRUE,FALSE);

		m_bt4.SubclassDlgItem(IDC_BUTTON2, this);
		m_bt4.SetIcon(IDI_Web);
		m_bt4.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt4.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt4.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt4.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt4.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt4.EnableBalloonTooltip();
		m_bt4.SetTooltipText(_T("����,��ʱ�������"));
		m_bt4.SetRounded(TRUE,FALSE);

		m_bt5.SubclassDlgItem(IDC_BUTTON12, this);
		m_bt5.SetIcon(IDI_JP);
		m_bt5.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt5.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt5.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt5.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt5.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt5.EnableBalloonTooltip();
		m_bt5.SetTooltipText(_T("Keybor����\r\n����Ľ������ߣ���һ�������飡"));
		m_bt5.SetRounded(TRUE,FALSE);

		m_bt6.SubclassDlgItem(IDC_BUTTON14, this);
		m_bt6.SetIcon(IDI_PIN);
		m_bt6.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt6.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt6.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt6.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt6.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt6.EnableBalloonTooltip();
		m_bt6.SetTooltipText(_T("����"));
		m_bt6.SetRounded(TRUE,FALSE);

		m_bt7.SubclassDlgItem(IDC_BUTTON15, this);
		m_bt7.SetIcon(IDI_SET);
		m_bt7.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt7.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt7.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt7.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt7.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt7.EnableBalloonTooltip();
		m_bt7.SetTooltipText(_T("�������"));
		m_bt7.SetRounded(TRUE,FALSE);

		m_bt8.SubclassDlgItem(IDC_BUTTON17, this);
		m_bt8.SetIcon(IDI_MESSAGE);
		m_bt8.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt8.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt8.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt8.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt8.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt8.EnableBalloonTooltip();
		m_bt8.SetTooltipText(_T("��������"));
		m_bt8.SetRounded(TRUE,FALSE);

		if(GetPrivateProfileIntA(_T("System"),_T("BeginHide"),0,CAfx::filepath))
		{
			m_set.SetWindowText(_T("��������"));
			m_set.SetToolTipText(_T("������չӦ�ý�����������"));
		}
		else
		{
			m_set.SetWindowText(_T("����������"));
			m_set.SetToolTipText(_T("������չӦ�ý���������������"));
		}
		m_set2.SetToolTipText(_T("Keybor����ʱ����Ӧ��������"));

		//Keybor����������Ŀ
		if(GetPrivateProfileIntA(_T("Load"), _T("�ǿ��ƽ�"),0,CAfx::filepath))
			OnBnClickedButton1();
		if(GetPrivateProfileIntA(_T("Load"), _T("���ٲ���"),0,CAfx::filepath))
			OnBnClickedButton11();
		if(GetPrivateProfileIntA(_T("Load"),_T("�ƻ��ػ�"),0,CAfx::filepath))
			OnBnClickedButton13();
		if(GetPrivateProfileIntA(_T("Load"),_T("Web����"),0,CAfx::filepath))
			OnBnClickedButton2();
		if(GetPrivateProfileIntA(_T("Load"), _T("Keybor����"),0,CAfx::filepath))
			OnBnClickedButton12();
		if(GetPrivateProfileIntA(_T("Load"),_T("Keybor����"),0,CAfx::filepath))
			OnBnClickedButton14();
		if(GetPrivateProfileIntA(_T("Load"),_T("�������"),0,CAfx::filepath))
			OnBnClickedButton15();
		if(GetPrivateProfileIntA(_T("Load"),_T("��������"),0,CAfx::filepath))
			OnBnClickedButton17();


		return TRUE;
}

void CDlg5::PcStart()         /////////////////////���Կ����ʼ���ʾ
{
       
// TODO: Add your control notification handler code here
char buff[100];
CString curuser=_T("administrator");
CString curmailfrom;
CString currcptto=_T("15886495012");
CString curdomain=_T("domain.com");
CString strsubject=_T("�����ѿ���");
CString strmessagebody=_T("�������ѿ�������������Keybor");
CString strtemp;
CString	strmail;

//curuser="abc";


currcptto+=_T("@qq.com");
curmailfrom.Format(_T("%s@%s"), curuser,curdomain);
memset(buff,0,100);

if(!m_socket.Create())
{
	//MessageBox("����socketʧ��.");
	return;
}
if(!m_socket.Connect(_T("mx0.qq.com"),25))
{
	//MessageBox("���ӷ�����ʧ��");
	return;
}
//���ӳɹ���ȡ�û�ӭ��Ϣ
m_socket.Receive(buff,100);
if (!IsSameString(buff,3,_T("220")))
{
	m_socket.Close();
	//MessageBox(buff,"220����");
	return;
}
//����HELO����
sprintf_s(buff,_T("HELO %s\r\n"),curdomain);
m_socket.Send(buff,strlen(buff));
m_socket.Receive(buff,100);
if (!IsSameString(buff,3,_T("250")))
{
	m_socket.Send(_T("QUIT\r\n"),strlen(_T("QUIT\r\n")));
	//m_socket.Receive(buff,100);
	m_socket.Close();
	//MessageBox(buff,"HELO����ش���");
	return ;
}
//����MAIL FROM����
sprintf_s(buff,_T("MAIL FROM:<%s>\r\n"),curmailfrom);
m_socket.Send(buff,strlen(buff));
m_socket.Receive(buff,100);
if (!IsSameString(buff,3,_T("250")))
{
	m_socket.Send(_T("QUIT\r\n"),strlen(_T("QUIT\r\n")));
	//m_socket.Receive(buff,100);
	m_socket.Close();
	//MessageBox(buff,"MAIL FROM����ش���");
	return;
}
//����RCPT TO����
sprintf_s(buff,_T("RCPT TO:<%s>\r\n"),currcptto);
m_socket.Send(buff,strlen(buff));
m_socket.Receive(buff,100);
if (IsSameString(buff,3,_T("550")))
{
	m_socket.Send(_T("QUIT\r\n"),strlen(_T("QUIT\r\n")));
	m_socket.Receive(buff,100);
	//m_socket.Close();
	strtemp.Format(_T("����ʼ��ռ��˵�ַ������\r\n��������Ϣ:%s"),buff);
	//MessageBox(strtemp);
	return;
}
if (!IsSameString(buff,3,_T("250")))
{
	m_socket.Send(_T("QUIT\r\n"),strlen(_T("QUIT\r\n")));
	//m_socket.Receive(buff,100);
	m_socket.Close();
	//MessageBox(buff,"RCPT TO����ش���");
	return;
}
sprintf_s(buff,_T("DATA\r\n"));
m_socket.Send(buff,strlen(buff));
m_socket.Receive(buff,100);
if (!IsSameString(buff,3,_T("354")))
{
	m_socket.Send(_T("QUIT\r\n"),strlen(_T("QUIT\r\n")));
	//m_socket.Receive(buff,100);
	m_socket.Close();
	//MessageBox(buff,"DATA����ش���");
	return;
}

//���ո�ʽ�������ʼ�
strmail=_T("");
strtemp.Format(_T("From: \"%s\" <%s>\r\n"),curuser,curmailfrom);
strmail+=strtemp;
strtemp.Format(_T("To: <%s>\r\n"),currcptto);
strmail+=strtemp;
strtemp.Format(_T("Subject: %s\r\n"),strsubject);
strmail+=strtemp;
CTime time=CTime::GetCurrentTime();
strtemp=time.Format(_T("Date: %a,%d %b %Y %X +0800\r\n")); //"Date: Thu, 30 Aug 2007 15:23:32 +0800\r\n";  //Ԥ������
strmail+=strtemp;
strtemp=_T("Content-Type: multipart/mixed; boundary=\"#BOUNDARY.CMAILSERVER#\"\r\n\r\n\r\n");
strmail+=strtemp;
strtemp=_T("--#BOUNDARY.CMAILSERVER#\r\n");
strmail+=strtemp;
strtemp=_T("Content-Type: text/html; charset=\"gb2312\"\r\nContent-Transfer-Encoding: 7bit\r\n\r\n");
strmail+=strtemp;
strmail+=strmessagebody;
strtemp=_T("\r\n\r\n--#BOUNDARY.CMAILSERVER#--\r\n\r\n.\r\n");
strmail+=strtemp;

//�����ʼ�����

m_socket.Send(strmail,strmail.GetLength());
m_socket.Receive(buff,100);
if (!IsSameString(buff,3,_T("250")))
{
	m_socket.Send(_T("QUIT\r\n"),strlen(_T("QUIT\r\n")));
	//m_socket.Receive(buff,100);
	m_socket.Close();
	//MessageBox(buff,"DATA����ش���");
	return;
}
//����QUIT����
sprintf_s(buff,_T("QUIT\r\n"));
m_socket.Send(buff,strlen(buff));
m_socket.Receive(buff,100);
if (!IsSameString(buff,3,_T("221")))
{
	//MessageBox(buff,"QUIT����ش���");
	return;
}
m_socket.Close();
//MessageBox("���ͳɹ�");

}


void CDlg5::OnBnClickedButton1()       // �ǿ��ƽ�dll
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HideMainWnd();
	HINSTANCE hInst;
	hInst=LoadLibrary(_T("XingBreak.dll"));
	typedef int (*ADDPROC)();
	ADDPROC XingBreak=(ADDPROC)GetProcAddress(hInst,_T("XingBreak"));
// 	if(!XingBreak)
// 	{
// 		//MessageBox("��ȡ������ַʧ��!");
// 		return;
// 	}
	//XingBreak();

	FreeLibrary(hInst);
}

void CDlg5::OnBnClickedButton14()      //����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������


}

void CDlg5::OnBnClickedButton11()      //���ٲ��ţ���չ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HideMainWnd();
	CString str=CAfx::Directorypath+_T("Dial\\���ٲ���.exe");
	char dial[100];
	strcpy_s(dial,str);
	ShellExecuteA(NULL,NULL,dial,NULL,NULL,SW_SHOWNORMAL);
}

void CDlg5::OnBnClickedButton13()           //�ƻ��ػ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDlg5::OnBnClickedButton2()            //����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HideMainWnd();
	CString str=CAfx::Directorypath+_T("feiq\\����FeiQ.exe");
	char dial[100];
	strcpy_s(dial,str);
	ShellExecuteA(NULL,NULL,dial,NULL,NULL,SW_SHOWNORMAL);
}


void CDlg5::OnBnClickedButton12()         //��������չ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HideMainWnd();
	CString str=CAfx::Directorypath+_T("Cut Screen\\����.exe");
	char jp[100];
	strcpy_s(jp,str);
	ShellExecuteA(NULL,NULL,jp,NULL,NULL,SW_SHOWNORMAL);
}


void CDlg5::OnBnClickedButton15()        //�������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HideMainWnd();
	CString str=CAfx::Directorypath+_T("DeskBox\\DeskBox.exe");
	char jp[100];
	strcpy_s(jp,str);
	ShellExecuteA(NULL,NULL,jp,NULL,NULL,SW_SHOWNORMAL);
}


void CDlg5::OnBnClickedButton17()        //������ʾ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDlg5::HideMainWnd()
{
	if (GetPrivateProfileIntA(_T("System"),_T("BeginHide"),0,CAfx::filepath))
	{
		AfxGetMainWnd()->ShowWindow(SW_HIDE);
	}
}

void CDlg5::OnStnClickedSet()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	m_set.GetWindowText(str);
	if(str==_T("��������"))
	{
				GetDlgItem(IDC_SET)->SetWindowText(_T("����������"));
				m_set.SetToolTipText(_T("������չӦ�ý���������������"));
				WritePrivateProfileString(_T("System"),_T("BeginHide"),_T("0"),CAfx::filepath);
	}
	else
	{
				GetDlgItem(IDC_SET)->SetWindowText(_T("��������"));
				m_set.SetToolTipText(_T("������չӦ�ý�����������"));
				WritePrivateProfileString(_T("System"),_T("BeginHide"),_T("1"),CAfx::filepath);
	}
	Invalidate();  //���´���
}

void CDlg5::OnStnClickedSet2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CLoadDlg dlg;
	dlg.DoModal();
}

void CDlg5::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rect; 
	GetClientRect(&rect); //����Ի���ĳߴ� 
	dc.FillSolidRect(&rect,RGB(255,255,255)); //���ƶԻ��򱳾�ɫ
	// TODO: �ڴ˴������Ϣ����������
	 CDialog::OnPaint();
}
