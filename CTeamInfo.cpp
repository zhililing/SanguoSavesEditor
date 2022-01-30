// CTeamInfo.cpp: 实现文件
//

#include "stdafx.h"
#include "Externs.h"
#include "SanguoModify.h"
#include "afxdialogex.h"
#include "CTeamInfo.h"


// CTeamInfo 对话框

IMPLEMENT_DYNAMIC(CTeamInfo, CDialogEx)

CTeamInfo::CTeamInfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG7, pParent)

{

}

CTeamInfo::~CTeamInfo()
{
}

void CTeamInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_index, m_index);
	DDX_Text(pDX, IDC_EDIT_type, m_type);
	DDX_Text(pDX, IDC_EDIT_money, m_money);
	DDX_Control(pDX, IDC_COMBO_major, m_major);
	DDX_Control(pDX, IDC_COMBO_junshi, m_junshi);
}


BEGIN_MESSAGE_MAP(CTeamInfo, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTeamInfo::OnBnClickedOk)
END_MESSAGE_MAP()


// CTeamInfo 消息处理程序


BOOL CTeamInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	pTeam = (Team*)(FileContent + nFirstTeamDataOffset + nCurrentTeamID * nTeamDataSize);

	m_index = pTeam->index;
	m_type = pTeam->type;
	m_money = pTeam->money;

	for (int n = 0; n <= pFileHeader->pWujiangTailNodeIndex; n++)
	{
		WuJiang* tpWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + n * 0x11F);
		if (tpWuJiang->duiWuIndex == pTeam->index)
		{
			m_major.AddString(BIG5ToUnicode(tpWuJiang->name));
			m_junshi.AddString(BIG5ToUnicode(tpWuJiang->name));
		}
	}
	CString strMajorName = IndexToName(pTeam->pMajorofTeamAtWuJiangNodeIndex);
	CString strJunShiName = IndexToName(pTeam->pJunShiofTeamAtWuJiangNodeIndex);
	((CComboBox*)GetDlgItem(IDC_COMBO_major))->SetWindowText(strMajorName);
	((CComboBox*)GetDlgItem(IDC_COMBO_junshi))->SetWindowText(strJunShiName);

	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

int CTeamInfo::NameToIndex(CString cstr)
{
	for (int n = 0; n <= pFileHeader->pWujiangTailNodeIndex; n++)
	{
		WuJiang* tpWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + n * 0x11F);
		if (BIG5ToUnicode(tpWuJiang->name) == cstr)
		{
			return n;
		}
	}
}

CString CTeamInfo::IndexToName(int index)
{
	WuJiang* tpWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F);
	return BIG5ToUnicode(tpWuJiang->name);
}


void CTeamInfo::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	CString str;
	m_major.GetWindowTextW(str);
	pTeam->pMajorofTeamAtWuJiangNodeIndex = NameToIndex(str);

	CString cstr;
	m_junshi.GetWindowTextW(cstr);
	pTeam->pJunShiofTeamAtWuJiangNodeIndex = NameToIndex(cstr);

	pTeam->type = m_type;
	pTeam->money = m_money;

	CDialogEx::OnOK();
}
