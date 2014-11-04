// LoadDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Keybor.h"
#include "LoadDlg.h"
#include "Afx.h"

// CLoadDlg �Ի���

IMPLEMENT_DYNAMIC(CLoadDlg, CDialog)

CLoadDlg::CLoadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoadDlg::IDD, pParent)
{

}

CLoadDlg::~CLoadDlg()
{
}

void CLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoadDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoadDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON11, &CLoadDlg::OnBnClickedButton11)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CLoadDlg ��Ϣ�������

BOOL CLoadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(GetPrivateProfileIntA("Load","�ǿ��ƽ�",0,CAfx::filepath));
	((CButton*)GetDlgItem(IDC_CHECK7))->SetCheck(GetPrivateProfileIntA("Load","���ٲ���",0,CAfx::filepath));
	((CButton*)GetDlgItem(IDC_CHECK8))->SetCheck(GetPrivateProfileIntA("Load","�ƻ��ػ�",0,CAfx::filepath));
	((CButton*)GetDlgItem(IDC_CHECK9))->SetCheck(GetPrivateProfileIntA("Load","Web����",0,CAfx::filepath));
	((CButton*)GetDlgItem(IDC_CHECK10))->SetCheck(GetPrivateProfileIntA("Load","Keybor����",0,CAfx::filepath));
	((CButton*)GetDlgItem(IDC_CHECK11))->SetCheck(GetPrivateProfileIntA("Load","Keybor����",0,CAfx::filepath));
	((CButton*)GetDlgItem(IDC_CHECK12))->SetCheck(GetPrivateProfileIntA("Load","�������",0,CAfx::filepath));
    ((CButton*)GetDlgItem(IDC_CHECK13))->SetCheck(GetPrivateProfileIntA("Load","��������",0,CAfx::filepath));


	return TRUE;
}
void CLoadDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//�ǿ��ƽ�
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		WritePrivateProfileStringA("Load","�ǿ��ƽ�","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		WritePrivateProfileStringA("Load","�ǿ��ƽ�","0",CAfx::filepath);
	}
	//���ٲ���
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck())
	{
		WritePrivateProfileStringA("Load","���ٲ���","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck())
	{
		WritePrivateProfileStringA("Load","���ٲ���","0",CAfx::filepath);
	}

	//�ƻ��ػ�
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck())
	{
		WritePrivateProfileStringA("Load","�ƻ��ػ�","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck())
	{
		WritePrivateProfileStringA("Load","�ƻ��ػ�","0",CAfx::filepath);
	}

	//Web����
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck())
	{
		WritePrivateProfileStringA("Load","Web����","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck())
	{
		WritePrivateProfileStringA("Load","Web����","0",CAfx::filepath);
	}
	//Keybor����
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK10))->GetCheck())
	{
		WritePrivateProfileStringA("Load","Keybor����","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK10))->GetCheck())
	{
		WritePrivateProfileStringA("Load","Keybor����","0",CAfx::filepath);
	}
	//Keybor����
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck())
	{
		WritePrivateProfileStringA("Load","Keybor����","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck())
	{
		WritePrivateProfileStringA("Load","Keybor����","0",CAfx::filepath);
	}
	//�������
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck())
	{
		WritePrivateProfileStringA("Load","�������","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck())
	{
		WritePrivateProfileStringA("Load","�������","0",CAfx::filepath);
	}
	//��������
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK13))->GetCheck())
	{
		WritePrivateProfileStringA("Load","��������","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK13))->GetCheck())
	{
		WritePrivateProfileStringA("Load","��������","0",CAfx::filepath);
	}
}


void CLoadDlg::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}


HBRUSH CLoadDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
