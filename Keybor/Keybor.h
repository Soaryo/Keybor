// Keybor.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#define WINDOWPLACEMENT_KEY "Window Placement"
#define SETTINGS_KEY "Software\\CompanyName\\ApplicationName\\Settings"

BOOL IsSameString(LPCSTR buff,int n,LPCSTR str);	//�ȶ������ַ�����ǰ����λ�Ƿ���ͬ
// CKeyborApp:
// �йش����ʵ�֣������ Keybor.cpp
//

class CKeyborApp : public CWinApp
{
public:
	CKeyborApp();
	CString pathfile;
// ��д
protected:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CKeyborApp theApp;