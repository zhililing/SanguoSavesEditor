// DlgColor.cpp : ʵ���ļ�
//

#include "stdafx.h"

#include "DlgColor.h"
#define IDC_RADIO1                      1076

// CDlgColor �Ի���

IMPLEMENT_DYNAMIC(CDlgColor, CDialog)

CDlgColor::CDlgColor(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgColor::IDD, pParent)
	, m_nColor(0)
{

}

CDlgColor::~CDlgColor()
{
}

void CDlgColor::DoDataExchange(CDataExchange* pDX)
{
	DDX_Radio(pDX, IDC_RADIO1, m_nColor);
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgColor, CDialog)
END_MESSAGE_MAP()


// CDlgColor ��Ϣ�������

BOOL CDlgColor::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	UpdateData(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

BOOL CDlgColor::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message == WM_KEYDOWN )
	{
		if( pMsg->wParam == VK_TAB && (GetKeyState(VK_CONTROL)>>8 != -1))
		{
			return FALSE;
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}
