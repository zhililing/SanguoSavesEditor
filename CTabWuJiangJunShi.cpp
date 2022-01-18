// CTabWuJiangJunShi.cpp: 实现文件
//

#include "stdafx.h"
#include "Externs.h"
#include "SanguoModify.h"
#include "afxdialogex.h"
#include "CTabWuJiangJunShi.h"
#include <string>
using namespace std;


// CTabWuJiangJunShi 对话框

IMPLEMENT_DYNAMIC(CTabWuJiangJunShi, CDialog)

CTabWuJiangJunShi::CTabWuJiangJunShi(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

CTabWuJiangJunShi::~CTabWuJiangJunShi()
{
}

void CTabWuJiangJunShi::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_onewujiangji);
	//DDX_Control(pDX, IDC_LIST2, m_allwujiangji);
	DDX_Control(pDX, IDC_LIST3, m_onejunshiji);
	//DDX_Control(pDX, IDC_LIST4, m_alljunshiji);
	DDX_Control(pDX, IDC_COMBO, m_wndCB);
	DDX_Control(pDX, IDC_EDIT, m_wndEdit);
	DDX_Control(pDX, IDC_COMBO2, m_wndCB2);
	DDX_Control(pDX, IDC_EDIT31, m_wndEdit2);
}


BEGIN_MESSAGE_MAP(CTabWuJiangJunShi, CDialog)
	ON_BN_CLICKED(IDOK, &CTabWuJiangJunShi::OnBnClickedOk)
END_MESSAGE_MAP()


// CTabWuJiangJunShi 消息处理程序


BOOL CTabWuJiangJunShi::OnInitDialog()
{
	
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	IniWuJiangJi();
	IniJunShiJi();
	///////kkkkkk
	CRect	rect;
	m_onewujiangji.GetClientRect(&rect);
	m_onewujiangji.SetExtendedStyle(m_onewujiangji.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//m_onewujiangji.SetExtendedStyle( LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_onewujiangji.InsertColumn(0, _T("学习等级"), LVCFMT_LEFT, 60, 0);
	m_onewujiangji.InsertColumn(1, _T("武将计"), LVCFMT_LEFT, 100, 1);


	//m_onewujiangji.SetColumnEditor(0, &CTabWuJiangJunShi::InitEditor, &CTabWuJiangJunShi::EndEditor, &m_wndEdit);
	m_onewujiangji.SetColumnEditor(1, &CTabWuJiangJunShi::InitEditor, &CTabWuJiangJunShi::EndEditor, &m_wndCB);
	m_onewujiangji.SetDefaultEditor(NULL, NULL, &m_wndEdit);
	CRect	rect2;
	m_onejunshiji.GetClientRect(&rect2);
	m_onejunshiji.SetExtendedStyle(m_onewujiangji.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_onejunshiji.InsertColumn(0, _T("学习等级"), LVCFMT_LEFT, 60, 0);
	m_onejunshiji.InsertColumn(1, _T("军师计"), LVCFMT_LEFT, 100, 1);
	//m_onejunshiji.SetColumnEditor(0, &CTabWuJiangJunShi::InitEditor, &CTabWuJiangJunShi::EndEditor, &m_wndEdit2);
	m_onejunshiji.SetColumnEditor(1, &CTabWuJiangJunShi::InitEditor, &CTabWuJiangJunShi::EndEditor, &m_wndCB2);
	m_onejunshiji.SetDefaultEditor(NULL, NULL, &m_wndEdit2);

	int j = 0;
	for (size_t i = 0; i < sizeof(pWuJiang->wujiangjixuexi) / sizeof(pWuJiang->wujiangjixuexi[0]); i+=2,j++)
	{
		byte xxdj = pWuJiang->wujiangjixuexi[i];
		byte wjj = pWuJiang->wujiangjixuexi[i + 1];

		string str = SGQY2_WUJIANGJI[wjj];
		CString str2(str.c_str());

		TCHAR szTmp[100];
		int nLastRow;

		wsprintf(szTmp, L"%d", xxdj);
		nLastRow = m_onewujiangji.InsertItem(j, szTmp);
		m_onewujiangji.SetItemText(nLastRow, 1, str2);

	}

	int k = 0;
	for (size_t i = 0; i < sizeof(pWuJiang->junshijixuexi) / sizeof(pWuJiang->junshijixuexi[0]); i += 2, k++)
	{
		byte xxdj = pWuJiang->junshijixuexi[i];
		byte jsj = pWuJiang->junshijixuexi[i + 1];

		string str = SGQY2_JUNSHIJI[jsj];
		CString str2(str.c_str());

		TCHAR szTmp[100];
		int nLastRow;

		wsprintf(szTmp, L"%d", xxdj);
		nLastRow = m_onejunshiji.InsertItem(k, szTmp);
		m_onejunshiji.SetItemText(nLastRow, 1, str2);

	}


	for (size_t i = 0; i < SGQY2_WUJIANGJI.size(); i++)
	{
		string str = SGQY2_WUJIANGJI[i];
		CString str2(str.c_str());
		//m_allwujiangji.AddString(str2);
		m_wndCB.AddString(str2);
	}

	for (size_t i = 0; i < SGQY2_JUNSHIJI.size(); i++)
	{
		string str = SGQY2_JUNSHIJI[i];
		CString str2(str.c_str());
		//m_alljunshiji.AddString(str2);
		m_wndCB2.AddString(str2);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CTabWuJiangJunShi::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData();

	for (size_t i = 0, j = 0, k = 0; i < sizeof(pWuJiang->wujiangjixuexi) / sizeof(pWuJiang->wujiangjixuexi[0]); i += 2, j++, k++)
	{
		CString xxdj, wjj;
		xxdj = m_onewujiangji.GetItemText(k, 0);
		wjj = m_onewujiangji.GetItemText(k, 1);
		std::string STDStr(CW2A(wjj.GetString()));
		int n = 0;
		auto it = std::find_if(SGQY2_WUJIANGJI.begin(), SGQY2_WUJIANGJI.end(), finder(STDStr));
		if (it != SGQY2_WUJIANGJI.end())
		{
			n = (*it).first;
		}
		else {
			n = 0;
		}
		int xxdjb;
		swscanf(xxdj.GetString(), L"%2d", &xxdjb);

		pWuJiang->wujiangjixuexi[i] = (byte)xxdjb;
		pWuJiang->wujiangjixuexi[i + 1] = (byte)n;
	}
	

	for (size_t i = 0; i < sizeof(pWuJiang->wujiangji) / sizeof(pWuJiang->wujiangji[0]); i++)
	{
		CString xxdj, wjj;
		//xxdj = m_onewujiangji.GetItemText(k, 0);
		wjj = m_onewujiangji.GetItemText(i, 1);
		std::string STDStr(CW2A(wjj.GetString()));
		int n = 0;
		auto it = std::find_if(SGQY2_WUJIANGJI.begin(), SGQY2_WUJIANGJI.end(), finder(STDStr));
		if (it != SGQY2_WUJIANGJI.end())
		{
			n = (*it).first;
		}
		else {
			n = 0;
		}
		//int xxdjb;
		//swscanf(xxdj.GetString(), L"%2d", &xxdjb);

		//pWuJiang->wujiangjixuexi[i] = (byte)xxdjb;
		pWuJiang->wujiangji[i] = (byte)n;
	}

	for (size_t i = 0, j = 0, k = 0; i < sizeof(pWuJiang->junshijixuexi) / sizeof(pWuJiang->junshijixuexi[0]); i += 2, j++, k++)
	{
		CString xxdj, jsj;
		xxdj = m_onejunshiji.GetItemText(k, 0);
		jsj = m_onejunshiji.GetItemText(k, 1);
		std::string STDStr(CW2A(jsj.GetString()));
		int n = 0;
		auto it = std::find_if(SGQY2_JUNSHIJI.begin(), SGQY2_JUNSHIJI.end(), finder(STDStr));
		if (it != SGQY2_JUNSHIJI.end())
		{
			n = (*it).first;
		}
		else {
			n = 0;
		}
		int xxdjb;
		swscanf(xxdj.GetString(), L"%2d", &xxdjb);

		pWuJiang->junshijixuexi[i] = (byte)xxdjb;
		pWuJiang->junshijixuexi[i + 1] = (byte)n;
	}

	for (size_t i = 0; i < sizeof(pWuJiang->junshiji) / sizeof(pWuJiang->junshiji[0]); i++)
	{
		CString xxdj, jsj;
		//xxdj = m_onejunshiji.GetItemText(k, 0);
		jsj = m_onejunshiji.GetItemText(i, 1);
		std::string STDStr(CW2A(jsj.GetString()));
		int n = 0;
		auto it = std::find_if(SGQY2_JUNSHIJI.begin(), SGQY2_JUNSHIJI.end(), finder(STDStr));
		if (it != SGQY2_JUNSHIJI.end())
		{
			n = (*it).first;
		}
		else {
			n = 0;
		}
		//int xxdjb;
		//swscanf(xxdj.GetString(), L"%2d", &xxdjb);

		//pWuJiang->junshijixuexi[i] = (byte)xxdjb;
		pWuJiang->junshiji[i] = (byte)n;
	}

}


BOOL CTabWuJiangJunShi::InitEditor(CWnd** pWnd, int nRow, int nColumn, CString& strSubItemText, DWORD_PTR dwItemData, void* pThis, BOOL bUpdate)
{
	ASSERT(*pWnd);
	switch (nColumn)
	{
	//case 1:
	//case 5:
	//{
	//	CDateTimeCtrl* pDTC = dynamic_cast<CDateTimeCtrl*>(*pWnd);
	//	COleDateTime dt;
	//	if (dt.ParseDateTime(strSubItemText)) pDTC->SetTime(dt);
	//}
	//break;
	case 1:
	{
		CComboBox* pCmb = dynamic_cast<CComboBox*>(*pWnd);
		pCmb->SelectString(0, strSubItemText);
	}
	break;
	case 3:
	{
		CDlgColor* pDlg = dynamic_cast<CDlgColor*>(*pWnd);
		pDlg->m_nColor = strSubItemText.CompareNoCase(L"green") ? (strSubItemText.CompareNoCase(L"blue") ? 0 : 2) : 1;
		pDlg->Create(CDlgColor::IDD, (CWnd*)pThis);
		pDlg->UpdateData(FALSE);
	}
	break;
	}
	return TRUE;
}
BOOL CTabWuJiangJunShi::EndEditor(CWnd** pWnd, int nRow, int nColumn, CString& strSubItemText, DWORD_PTR dwItemData, void* pThis, BOOL bUpdate)
{
	ASSERT(pWnd);
	switch (nColumn)
	{
	//case 1:
	//case 5:
	//{
	//	CDateTimeCtrl* pDTC = dynamic_cast<CDateTimeCtrl*>(*pWnd);
	//	COleDateTime dt;
	//	pDTC->GetTime(dt);
	//	strSubItemText = dt.Format();
	//}
	//break;
	case 1:
	{
		CComboBox* pCmb = dynamic_cast<CComboBox*>(*pWnd);
		int index = pCmb->GetCurSel();
		if (index >= 0) pCmb->GetLBText(index, strSubItemText);
	}
	break;
	case 3:
	{
		CDlgColor* pDlg = dynamic_cast<CDlgColor*>(*pWnd);
		CListCtrlEx* pList = reinterpret_cast<CListCtrlEx*>(pThis);
		pDlg->UpdateData(TRUE);
		switch (pDlg->m_nColor)
		{
		case 1:
			strSubItemText = "Green";
			pList->SetCellColors(nRow, nColumn, RGB(0, 255, 0), -1);
			break;
		case 2:
			strSubItemText = "Blue";
			pList->SetCellColors(nRow, nColumn, RGB(0, 0, 255), -1);
			break;
		default:
			strSubItemText = "Red";
			pList->SetCellColors(nRow, nColumn, RGB(255, 0, 0), -1);
			break;
		}
		pDlg->DestroyWindow();
	}
	break;
	}
	return TRUE;
}

