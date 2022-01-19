// CTabWuPing.cpp: 实现文件
//

#include "stdafx.h"
#include "Externs.h"
#include "SanguoModify.h"
#include "afxdialogex.h"
#include "CTabWuPing.h"



// CTabWuPing 对话框

IMPLEMENT_DYNAMIC(CTabWuPing, CDialogEx)

CTabWuPing::CTabWuPing(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CTabWuPing::~CTabWuPing()
{
}

void CTabWuPing::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_cmbBingFu, m_bingFu);
	DDX_Control(pDX, IDC_cmbBingShu, m_bingShu);
	DDX_Control(pDX, IDC_cmbMa, m_ma);
	DDX_Control(pDX, IDC_cmbWuQi, m_wuQi);
	DDX_Control(pDX, IDC_cmbZhenXing, m_zhenXing);
	DDX_Control(pDX, IDC_cmbZhuBao, m_zhuBao);
}


BEGIN_MESSAGE_MAP(CTabWuPing, CDialogEx)
END_MESSAGE_MAP()


// CTabWuPing 消息处理程序


BOOL CTabWuPing::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	IniWuPing();

	for (size_t i = 0; i < SGQY2_BINGFU.size(); i++)
	{
		string str = SGQY2_BINGFU[i];
		CString str2(str.c_str());
		//m_allwujiangji.AddString(str2);
		m_bingFu.AddString(str2);
	}
	for (size_t i = 0; i < SGQY2_BINGQI.size(); i++)
	{
		string str = SGQY2_BINGQI[i];
		CString str2(str.c_str());
		//m_allwujiangji.AddString(str2);
		m_wuQi.AddString(str2);
	}
	for (size_t i = 0; i < SGQY2_BINGSHU.size(); i++)
	{
		string str = SGQY2_BINGSHU[i];
		CString str2(str.c_str());
		//m_allwujiangji.AddString(str2);
		m_bingShu.AddString(str2);
	}
	for (size_t i = 0; i < SGQY2_MALEI.size(); i++)
	{
		string str = SGQY2_MALEI[i];
		CString str2(str.c_str());
		//m_allwujiangji.AddString(str2);
		m_ma.AddString(str2);
	}
	for (size_t i = 0; i < SGQY2_ZHENFA.size(); i++)
	{
		string str = SGQY2_ZHENFA[i];
		CString str2(str.c_str());
		//m_allwujiangji.AddString(str2);
		m_zhenXing.AddString(str2);
	}
	for (size_t i = 0; i < SGQY2_ZHUBAO.size(); i++)
	{
		string str = SGQY2_ZHUBAO[i];
		CString str2(str.c_str());
		//m_allwujiangji.AddString(str2);
		m_zhuBao.AddString(str2);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
