// PPDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Keybor.h"
#include "PPDlg.h"
#include "afxdialogex.h"


// CPPDlg �Ի���

IMPLEMENT_DYNAMIC(CPPDlg, CDialog)

CPPDlg::CPPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPPDlg::IDD, pParent)
{

}

CPPDlg::~CPPDlg()
{
}

void CPPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROG1, m_p);
}


BEGIN_MESSAGE_MAP(CPPDlg, CDialog)

	ON_WM_PAINT()
END_MESSAGE_MAP()


// CPPDlg ��Ϣ�������



void CPPDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������

	// ��Ϊ��ͼ��Ϣ���� 
	CDialog::OnPaint();
}
BOOL CPPDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    //����Բ�Ǵ���
	CRect r;
	GetClientRect(&r);
	HRGN rgn;
	rgn = CreateRoundRectRgn(0,0,r.Width()+1,r.Height()+1,4,4);
	SetWindowRgn(rgn,TRUE);

	ModifyStyleEx(WS_EX_APPWINDOW, WS_EX_TOOLWINDOW);     //ʹ���ڲ���ʾ��������
	return TRUE;
}	