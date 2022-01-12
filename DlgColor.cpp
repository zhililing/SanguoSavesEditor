// DlgColor.cpp : 实现文件
//

#include "stdafx.h"

#include "DlgColor.h"
#define IDC_RADIO1                      1076

// CDlgColor 对话框

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


// CDlgColor 消息处理程序

BOOL CDlgColor::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	UpdateData(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

BOOL CDlgColor::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message == WM_KEYDOWN )
	{
		if( pMsg->wParam == VK_TAB && (GetKeyState(VK_CONTROL)>>8 != -1))
		{
			return FALSE;
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}
