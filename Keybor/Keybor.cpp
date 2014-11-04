// Keybor.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Keybor.h"
#include "KeyborDlg.h"
#include "Afx.h"
#include "XMessageBox.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CKeyborApp

BEGIN_MESSAGE_MAP(CKeyborApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CKeyborApp ����

CKeyborApp::CKeyborApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CKeyborApp ����

CKeyborApp theApp;


// CKeyborApp ��ʼ��

BOOL CKeyborApp::InitInstance()
{
	XMSGBOXPARAMS xmb;
	xmb.nTimeoutSeconds  = 2;
	//xmb.nDisabledSeconds = 0;
	xmb.nIdIcon          = 0;

	//xmb.x = 50;
	//xmb.y = 20;

	xmb.dwOptions |= XMSGBOXPARAMS::VistaStyle;

	HANDLE m_hMutex=CreateMutex(NULL,TRUE, m_pszAppName); 
	if(GetLastError()==ERROR_ALREADY_EXISTS) {XMessageBox(NULL,"�ó�����������!","Keybor",MB_OK | MB_ICONQUESTION, &xmb); return FALSE; }
	/////////////////һ��ʵ��


	if (!AfxSocketInit())
	{
		//AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}
//  char pathfile[100];
//  GetCurrentDirectory(sizeof(pathfile),pathfile);


  //pathfile="C:\\Program Files\\Keybor";  
//   if(PathFileExistsA(pathfile)==FALSE)//�ж�Ŀ¼�Ƿ����   
//   {   
//           if(CreateDirectory(pathfile,NULL)==FALSE)          //�������򴴽�·���ļ���
//           AfxMessageBox("�����ĵ�Ŀ¼����");   
//   }
//   CreateDirectory(pathfile,NULL);


	TCHAR exeFullPath[MAX_PATH]; 
	CString strPath; 
	GetModuleFileName(NULL,exeFullPath,MAX_PATH); 
	strPath=(CString)exeFullPath; 
	int position=strPath.ReverseFind('\\'); 
	strPath=strPath.Left(position+1);  
	TCHAR FilePath[MAX_PATH]; 
	GetModuleFileName(NULL,FilePath,MAX_PATH); 
	(_tcsrchr(FilePath,'\\'))[1] = 0;
	CAfx::Directorypath=FilePath;
	lstrcat(FilePath,_T("Keybor.ini"));
	CAfx::filepath=FilePath;

	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CKeyborDlg dlg;
	 
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�

	return FALSE;
}
BOOL IsSameString(LPCSTR buff,int n,LPCSTR str)	//�ȶ������ַ�����ǰ����λ�Ƿ���ͬ
{
	int i;

	for (i=0;i<n;i++)
	{
		if (buff[i]!=str[i]) return FALSE;
	}
	return TRUE;
}