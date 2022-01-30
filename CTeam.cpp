// CTeam.cpp: 实现文件
//

#include "stdafx.h"
#include "externs.h"
#include "SanguoModify.h"
#include "afxdialogex.h"
#include "CTeam.h"
#include "CTeamInfo.h"


// CTeam 对话框

IMPLEMENT_DYNAMIC(CTeam, CDialogEx)

CTeam::CTeam(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

CTeam::~CTeam()
{
}

void CTeam::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Team, m_lstTeam);
}


BEGIN_MESSAGE_MAP(CTeam, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_Team, &CTeam::OnNMDblclkListTeam)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_Team, &CTeam::OnNMRClickListTeam)
END_MESSAGE_MAP()


// CTeam 消息处理程序


BOOL CTeam::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect	rect;
	m_lstTeam.GetClientRect(&rect);

	m_lstTeam.SetExtendedStyle(m_lstTeam.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);



	//SetDlgItemText(IDC_STATIC_Kings, L"选择君主");
	//SetDlgItemText(IDC_STATIC, L"\n点击 \"打开文件\" 读入存档文件");

	m_lstTeam.InsertColumn(0, _T("队伍索引"), LVCFMT_LEFT, 60, 0);
	m_lstTeam.InsertColumn(1, _T("队伍类型"), LVCFMT_LEFT, 60, 1);
	m_lstTeam.InsertColumn(2, _T("队伍主将"), LVCFMT_LEFT, 65, 2);
	m_lstTeam.InsertColumn(3, _T("队伍军师"), LVCFMT_LEFT, 65, 3);
	m_lstTeam.InsertColumn(4, _T("金钱"), LVCFMT_LEFT, 65, 4);

	for (int n = 0; n <= pFileHeader->pTeamTailNodeIndex; n++)
	{
		pTeam = (Team*)(FileContent + nFirstTeamDataOffset + n * nTeamDataSize);

		TCHAR szTmp[100];
		int nLastRow;
		wsprintf(szTmp, L"%d", n);
		nLastRow = m_lstTeam.InsertItem(n, szTmp);

		wsprintf(szTmp, L"%d", pTeam->type);
		m_lstTeam.SetItemText(nLastRow, 1, szTmp);

		wsprintf(szTmp, L"%d", pTeam->pMajorofTeamAtWuJiangNodeIndex);
		m_lstTeam.SetItemText(nLastRow, 2, szTmp);

		wsprintf(szTmp, L"%d", pTeam->pJunShiofTeamAtWuJiangNodeIndex);
		m_lstTeam.SetItemText(nLastRow, 3, szTmp);

		wsprintf(szTmp, L"%d", pTeam->money);
		m_lstTeam.SetItemText(nLastRow, 4, szTmp);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CTeam::OnNMDblclkListTeam(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CTeamInfo m_dlgTeam;
	m_dlgTeam.DoModal();
	*pResult = 0;
}


void CTeam::OnNMRClickListTeam(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnNMDblclkListTeam(pNMHDR, pResult);
	*pResult = 0;
}
