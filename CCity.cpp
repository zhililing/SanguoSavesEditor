// CCity.cpp: 实现文件
//

#include "stdafx.h"
#include "Externs.h"
#include "SanguoModify.h"
#include "afxdialogex.h"
#include "CCity.h"
#include "CCityInfo.h"


// CCity 对话框

IMPLEMENT_DYNAMIC(CCity, CDialogEx)

CCity::CCity(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

CCity::~CCity()
{
}

void CCity::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_City, m_lstCity);
}


BEGIN_MESSAGE_MAP(CCity, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_City, &CCity::OnNMDblclkListCity)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_City, &CCity::OnNMRClickListCity)
END_MESSAGE_MAP()


// CCity 消息处理程序


BOOL CCity::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect	rect;
	m_lstCity.GetClientRect(&rect);

	m_lstCity.SetExtendedStyle(m_lstCity.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);



	//SetDlgItemText(IDC_STATIC_Kings, L"选择君主");
	//SetDlgItemText(IDC_STATIC, L"\n点击 \"打开文件\" 读入存档文件");

	m_lstCity.InsertColumn(0, _T("城池索引"), LVCFMT_LEFT, 60, 0);
	m_lstCity.InsertColumn(1, _T("城池名称"), LVCFMT_LEFT, 60, 1);
	m_lstCity.InsertColumn(2, _T("城池主将"), LVCFMT_LEFT, 65, 2);
	m_lstCity.InsertColumn(3, _T("城池军师"), LVCFMT_LEFT, 65, 3);
	m_lstCity.InsertColumn(4, _T("城池容量"), LVCFMT_LEFT, 65, 4);
	m_lstCity.InsertColumn(5, _T("城池等级"), LVCFMT_LEFT, 65, 5);
	m_lstCity.InsertColumn(6, _T("城池最大预备兵"), LVCFMT_LEFT, 100, 6);
	m_lstCity.InsertColumn(7, _T("城池现有预备兵"), LVCFMT_LEFT, 100, 7);
	m_lstCity.InsertColumn(8, _T("城池人口数"), LVCFMT_LEFT, 80, 8);
	m_lstCity.InsertColumn(9, _T("城池防御"), LVCFMT_LEFT, 60, 9);
	m_lstCity.InsertColumn(10, _T("城池金钱"), LVCFMT_LEFT, 60, 10);
	
	for (int n = 0; n <= pFileHeader->pCityTailNodeIndex; n++) 
	{
		pCity = (City*)(FileContent + nFirstCityDataOffset + n * nCityDataSize);
		TCHAR szTmp[100];
		int nLastRow;

		wsprintf(wujiangnamebig5char, L"%s", pCity->szName);
		//TranslateNameToGB2312Unicode();

		wsprintf(szTmp, L"%d", n);
		nLastRow = m_lstCity.InsertItem(n, szTmp);

		m_lstCity.SetItemText(nLastRow, 1, BIG5ToUnicode((const TCHAR*)wujiangnamebig5char));
		
		wsprintf(szTmp, L"%d", pCity->pMajorofCityAtWuJiangNodeIndex);
		m_lstCity.SetItemText(nLastRow, 2, szTmp);

		wsprintf(szTmp, L"%d", pCity->pJunShioffCityAtWuJiangNodeIndex);
		m_lstCity.SetItemText(nLastRow, 3, szTmp);

		wsprintf(szTmp, L"%d", pCity->nCapacityWuJiangofcity);
		m_lstCity.SetItemText(nLastRow, 4, szTmp);

		wsprintf(szTmp, L"%d", pCity->Level);
		m_lstCity.SetItemText(nLastRow, 5, szTmp);

		wsprintf(szTmp, L"%d", pCity->nMaxSoilder);
		m_lstCity.SetItemText(nLastRow, 6, szTmp);

		wsprintf(szTmp, L"%d", pCity->nSoilder);
		m_lstCity.SetItemText(nLastRow, 7, szTmp);

		wsprintf(szTmp, L"%d", pCity->nPersonalofCity);
		m_lstCity.SetItemText(nLastRow, 8, szTmp);

		wsprintf(szTmp, L"%d", pCity->nDefenderofCity);
		m_lstCity.SetItemText(nLastRow, 9, szTmp);

		wsprintf(szTmp, L"%d", pCity->nMoneyofCity);
		m_lstCity.SetItemText(nLastRow, 10, szTmp);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CCity::OnNMDblclkListCity(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	int nCurrSel;

	if (0 == m_lstCity.GetItemCount()) return;	//如果列表为空，直接返回

	nCurrSel = (int)m_lstCity.GetFirstSelectedItemPosition();

	if (0 == nCurrSel) return;

	CString szCityID = m_lstCity.GetItemText(nCurrSel - 1, 0);

	nCurrentCityID = _ttoi(szCityID);
	CCityInfo m_cityInfo = new CCityInfo();
	m_cityInfo.DoModal();
	
	//OnCbnSelchangeComboKingsname();		//刷新显示
}


void CCity::OnNMRClickListCity(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	OnNMDblclkListCity(pNMHDR, pResult);
}
