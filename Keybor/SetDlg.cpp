// SetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Keybor.h"
#include "SetDlg.h"
// CSetDlg �Ի���

IMPLEMENT_DYNAMIC(CSetDlg, CDialog)

CSetDlg::CSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDlg::IDD, pParent)
{

}

CSetDlg::~CSetDlg()
{
}

void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HOTKEY1, m_hot1);
	DDX_Control(pDX, IDC_HOTKEY2, m_hot2);
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &CSetDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CSetDlg::OnBnClickedButton1)
	ON_WM_HOTKEY()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSetDlg ��Ϣ�������

BOOL CSetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    ///////////////////////////////////  ������ʾ  /////////////////////////////////////    
	UINT Balloon=GetPrivateProfileIntA("System","Balloon",1,CAfx::filepath);
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(Balloon);

	////////////////////////////////   ����������ʼ��  //////////////////////////////////
	UINT start=GetPrivateProfileIntA("System","m_bstart",1,CAfx::filepath);
	((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(start);

	if(start)
	{
		CString   str;                     
		LPCH     CurrentPath= (LPCH)new WCHAR[sizeof(WCHAR)*100];//����ǰ·��
		HKEY   hRegKey;             //ע��key
		BOOL   bResult;              //��ע�����ֵ
		str=_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run");//ע���   
		GetModuleFileName(NULL,CurrentPath,MAX_PATH); //������ó���·��
		if(bResult=RegOpenKeyA(HKEY_LOCAL_MACHINE,   str,   &hRegKey)   !=   ERROR_SUCCESS)//��ע���     
		{   
			delete[] CurrentPath;
			return TRUE;   
		}
		RegSetValueExA(hRegKey,_T("Keybor"),0,REG_SZ, (const unsigned char *)CurrentPath, MAX_PATH);//�򿪳ɹ�д��Ϣ��ע���
		RegCloseKey(hRegKey);   
		delete[] CurrentPath; 
	}
	 /////////////////////////////////////   �������������ڳ�ʼ�� //////////////////////////////////
	UINT Hide=GetPrivateProfileIntA("System","Hide",1,CAfx::filepath);
	((CButton*)GetDlgItem(IDC_CHECK5))->SetCheck(Hide);
    //////////////////////////////////////////   �ϰ����ʼ��  /////////////////////////////////
	UINT Hot1=GetPrivateProfileIntA("Hot","Key1",1,CAfx::filepath);
	((CButton*)GetDlgItem(IDC_CHECK4))->SetCheck(Hot1);
	
		WORD vk1=GetPrivateProfileIntA("Hot","vk1",0,CAfx::filepath);
		WORD sk1=GetPrivateProfileIntA("Hot","sk1",0,CAfx::filepath);
		m_hot1.SetHotKey(vk1,sk1);

	if(Hot1)
	{
		UINT fs1 = 0;
		if (sk1 & HOTKEYF_ALT)	    fs1|= MOD_ALT;
		if (sk1 & HOTKEYF_CONTROL)   fs1|= MOD_CONTROL;
		if (sk1 & HOTKEYF_SHIFT) 	fs1|= MOD_SHIFT; 	
		RegisterHotKey(m_hWnd, 111, fs1, vk1);	
	}
	//***************************************�˳�����ʼ��*************************************//
	UINT Hot2=GetPrivateProfileIntA("Hot","Key2",1,CAfx::filepath);
	((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(Hot2);

	WORD vk2=GetPrivateProfileIntA("Hot","vk2",0,CAfx::filepath);
	WORD sk2=GetPrivateProfileIntA("Hot","sk2",0,CAfx::filepath);
	m_hot2.SetHotKey(vk2,sk2);
	if(Hot2)
	{
		UINT fs2 = 0;
		if (sk2 & HOTKEYF_ALT)	    fs2|= MOD_ALT;
		if (sk2 & HOTKEYF_CONTROL)   fs2|= MOD_CONTROL;
		if (sk2 & HOTKEYF_SHIFT) 	fs2|= MOD_SHIFT; 	
		RegisterHotKey(m_hWnd, 222, fs2, vk2);		
    }
	//***************************************�����ö�******************************************//
	UINT PosW=GetPrivateProfileIntA("System","PosW",1,CAfx::filepath);
	((CButton*)GetDlgItem(IDC_CHECK6))->SetCheck(PosW);
	if (PosW)
		//�����öԻ�����ʾ����Ļ��ǰ��
		AfxGetMainWnd()->SetWindowPos(&wndTopMost,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);

	::SetFocus(NULL);
	return TRUE;
}
void CSetDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
	CWnd *pWnd=AfxGetMainWnd();
// 	pWnd->AnimateWindow( 200,   AW_BLEND);   //����
//     UpdateData(FALSE);

	pWnd->ShowWindow(SW_SHOWNORMAL);
   
}
void CSetDlg::OnBnClickedButton1()
{
	/////////////////////////////////////    ������ʾ  ////////////////////////////////////
	 if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	 {
		 WritePrivateProfileStringA("System","Balloon","1",CAfx::filepath);
	 }
	 if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	 {
		 WritePrivateProfileStringA("System","Balloon","0",CAfx::filepath);
	 }
	 /////////////////////////////////////   ��������   //////////////////////////////////
	 CString   str;                     
	 LPCH     CurrentPath= (LPCH)new WCHAR[sizeof(WCHAR)*100];//����ǰ·��
	 HKEY   hRegKey;             //ע��key
	 BOOL   bResult;              //��ע�����ֵ
	 str=_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run");//ע���   
	 GetModuleFileName(NULL,CurrentPath,MAX_PATH); //������ó���·��
	 if(bResult=RegOpenKeyA(HKEY_LOCAL_MACHINE,   str,   &hRegKey)   !=   ERROR_SUCCESS)//��ע���     
	 {   
		 delete[] CurrentPath;
		 return;   
	 }

	 if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())
	 {
		 RegSetValueExA(hRegKey,_T("Keybor"),0,REG_SZ, (const unsigned char *)CurrentPath, MAX_PATH);//�򿪳ɹ�д��Ϣ��ע���
		 RegCloseKey(hRegKey);   
		 delete[] CurrentPath; 
		 WritePrivateProfileString("System","m_bstart","1",CAfx::filepath);
	 }

	 if(BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())
	 {
		 RegDeleteValue(hRegKey,"Keybor");
		 RegCloseKey(hRegKey);
		 delete[] CurrentPath;
		 WritePrivateProfileString("System","m_bstart","0",CAfx::filepath);
	 }
	 /////////////////////////////////////   �������������� //////////////////////////////////
	 if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck())
	 {
		 WritePrivateProfileStringA("System","Hide","1",CAfx::filepath);
	 }
	 if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck())
	 {
		 WritePrivateProfileStringA("System","Hide","0",CAfx::filepath);
	 }
	 ///////////////////////////////////////   �����ϰ��   ///////////////////////////////////
	 
	 UpdateData();
	 if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck())
	 {
		 WritePrivateProfileStringA("Hot","Key1","1",CAfx::filepath);
	 }
	 if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck())
	 {
		 WritePrivateProfileStringA("Hot","Key1","0",CAfx::filepath);
	 }
	 WORD vk1, sk1;
	 m_hot1.GetHotKey(vk1,sk1);
	 CString m_vk1,m_sk1;
	 m_vk1.Format("%d",vk1);
	 m_sk1.Format("%d",sk1);
	 WritePrivateProfileStringA("Hot","vk1",m_vk1,CAfx::filepath);
	 WritePrivateProfileStringA("Hot","sk1",m_sk1,CAfx::filepath);

	 UINT fs1 = 0;
	 if (sk1 & HOTKEYF_ALT)	    fs1|= MOD_ALT;
	 if (sk1 & HOTKEYF_CONTROL)   fs1|= MOD_CONTROL;
	 if (sk1 & HOTKEYF_SHIFT) 	fs1|= MOD_SHIFT; 	

	 RegisterHotKey(m_hWnd, 111, fs1, vk1);

	//************************************�˳���*********************************// 
	 if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck())
	 {
		 WritePrivateProfileStringA("Hot","Key2","1",CAfx::filepath);
	 }
	 if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck())
	 {
		 WritePrivateProfileStringA("Hot","Key2","0",CAfx::filepath);
	 }
	 WORD vk2,sk2;
	 m_hot2.GetHotKey(vk2,sk2);
	 CString m_vk2,m_sk2;
	 m_vk2.Format("%d",vk2);
	 m_sk2.Format("%d",sk2);
	 WritePrivateProfileStringA("Hot","vk2",m_vk2,CAfx::filepath);
	 WritePrivateProfileStringA("Hot","sk2",m_sk2,CAfx::filepath);
	 UINT fs2 = 0;
	 if (sk2 & HOTKEYF_ALT)	    fs2|= MOD_ALT;
	 if (sk2 & HOTKEYF_CONTROL)   fs2|= MOD_CONTROL;
	 if (sk2 & HOTKEYF_SHIFT) 	fs2|= MOD_SHIFT; 	
	 RegisterHotKey(m_hWnd, 222, fs2, vk2);
	 ///////////////////////////////////////   �����˳���   ///////////////////////////////////

	 //*****************************************�����ö�****************************************//
	 if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck())
	 {
		 WritePrivateProfileStringA("System","PosW","1",CAfx::filepath);
		 AfxGetMainWnd()->SetWindowPos(&wndTopMost,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE);
	 }
	 if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck())
	 {
		 WritePrivateProfileStringA("System","PosW","0",CAfx::filepath);
		 AfxGetMainWnd()->SetWindowPos(&wndNoTopMost,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE);
	 }
	 //*******************************************************************************************//
}

void CSetDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nHotKeyId)
	{

	case 111:
		if (!AfxGetMainWnd()->ShowWindow(SW_HIDE))
		{
			CKeyborDlg dlg;
			dlg.OnSet();
		}
		break;
	case 222:
		//************************************����Ի�������**********************************//
		CString rt1,rt2;
		RECT r;
		AfxGetMainWnd()->GetWindowRect(&r);
		rt1.Format("%d",r.left);
		rt2.Format("%d",r.top);
		WritePrivateProfileStringA("System","PosX",rt1,CAfx::filepath);
		WritePrivateProfileStringA("System","PosY",rt2,CAfx::filepath);
        AfxGetMainWnd()->SendMessage(WM_CLOSE);    //�������ڷ�����Ϣ�Ƴ�����
		break;
	}

	CDialog::OnHotKey(nHotKeyId, nKey1, nKey2);
}


HBRUSH CSetDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if(nCtlColor == CTLCOLOR_DLG || CTLCOLOR_STATIC)
	{
		//pDC->SetTextColor(RGB(0,0,255));//����ɫ
		pDC->SetBkColor(RGB(245,245,255));//���屳��ɫ******
		HBRUSH B = CreateSolidBrush(RGB(245,245,255)); //����ɫ
		return B;
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
