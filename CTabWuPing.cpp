// CTabWuPing.cpp: 实现文件
//

#include "stdafx.h"
#include "Externs.h"
#include "SanguoModify.h"
#include "afxdialogex.h"
#include "CTabWuPing.h"
#include <bitset>



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
	DDX_Control(pDX, IDC_LIST_BingFu, m_lstBingFu);
	DDX_Control(pDX, IDC_LIST_ZhenXing, m_lstZhenXing);
}


BEGIN_MESSAGE_MAP(CTabWuPing, CDialogEx)
	ON_CBN_SELCHANGE(IDC_cmbBingFu, &CTabWuPing::OnCbnSelchangecmbbingfu)
	ON_CBN_SELCHANGE(IDC_cmbWuQi, &CTabWuPing::OnCbnSelchangecmbwuqi)
	ON_CBN_SELCHANGE(IDC_cmbBingShu, &CTabWuPing::OnCbnSelchangecmbbingshu)
	ON_CBN_SELCHANGE(IDC_cmbMa, &CTabWuPing::OnCbnSelchangecmbma)
	ON_CBN_SELCHANGE(IDC_cmbZhuBao, &CTabWuPing::OnCbnSelchangecmbzhubao)
	ON_CBN_SELCHANGE(IDC_cmbZhenXing, &CTabWuPing::OnCbnSelchangecmbzhenxing)
	ON_BN_CLICKED(IDOK, &CTabWuPing::OnBnClickedOk)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_BingFu, &CTabWuPing::OnLvnItemchangedListBingfu)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ZhenXing, &CTabWuPing::OnLvnItemchangedListZhenxing)
END_MESSAGE_MAP()


// CTabWuPing 消息处理程序


BOOL CTabWuPing::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	ListView_SetExtendedListViewStyle(m_lstBingFu.m_hWnd, LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT);
	ListView_SetExtendedListViewStyle(m_lstZhenXing.m_hWnd, LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT);

	IniWuPing();
	m_bingFu.Clear();
	m_zhenXing.Clear();
	m_bingShu.Clear();
	m_ma.Clear();
	m_wuQi.Clear();
	m_zhuBao.Clear();

	m_lstBingFu.DeleteAllItems();
	m_lstZhenXing.DeleteAllItems();
	for (size_t i = 0; i < SGQY2_BINGFU.size(); i++)
	{
		string str = SGQY2_BINGFU[i];
		CString str2(str.c_str());
		//m_allwujiangji.AddString(str2);
		m_bingFu.AddString(str2);
		m_lstBingFu.InsertItem(i, str2);
	}

	int allUseBingFu = pWuJiang->keyongbingzhong;
	int allUseZhenXing = pWuJiang->kexuanzhenxing;

	int useBingFu = pWuJiang->bingzhong;
	int useZhenXing = pWuJiang->zhenxing;

	short shtMa = pWuJiang->mapisuoyin;
	short shtWuQi = pWuJiang->wuqisuoyin;
	short shtShuJi = pWuJiang->shujisuoyin;

	bitset<32> bitsUseBingFu; //7位长度
	bitsUseBingFu = useBingFu;

	bitset<32> bitsUseZhenXing; //7位长度
	bitsUseZhenXing = useZhenXing;

	bitset<32> bits; //7位长度
	bits = allUseBingFu;

	string strnew  = bits.to_string();
	string strnewUseBingFu = bitsUseBingFu.to_string();
	string strnewUseZhenXing = bitsUseZhenXing.to_string();

	for (size_t i = 0; i < SGQY2_BINGFU.size(); i++)
	{
		if (strnew.substr(strnew.length() - 1 - i, 1) == "1")
		{
			m_lstBingFu.SetCheck(i);
		}
		if (strnewUseBingFu.substr(strnewUseBingFu.length() - 1 - i, 1) == "1")
		{
			m_bingFu.SetCurSel(i);
		}
	}

	for (size_t i = 0; i < SGQY2_BINGQI.size(); i++)
	{
		string str = SGQY2_BINGQI[i + indexBingQi];
		CString str2(str.c_str());
		//m_allwujiangji.AddString(str2);
		m_wuQi.AddString(str2);
	}
	for (size_t i = 0; i < SGQY2_BINGSHU.size(); i++)
	{
		string str = SGQY2_BINGSHU[i + indexBingShu];
		CString str2(str.c_str());
		//m_allwujiangji.AddString(str2);
		m_bingShu.AddString(str2);
	}
	for (size_t i = 0; i < SGQY2_MALEI.size(); i++)
	{
		string str = SGQY2_MALEI[i + indexMa];
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
		m_lstZhenXing.InsertItem(i, str2);
	}

	bitset<32> bitsZhenFa; //7位长度
	bitsZhenFa = allUseZhenXing;

	string strnewZhenFa = bitsZhenFa.to_string();

	for (size_t i = 0; i < SGQY2_ZHENFA.size(); i++)
	{
		if (strnewZhenFa.substr(strnewZhenFa.length() - 1 - i, 1) == "1")
		{
			m_lstZhenXing.SetCheck(i);
		}
		if (strnewUseZhenXing.substr(strnewUseZhenXing.length() - 1 - i, 1) == "1")
		{
			m_zhenXing.SetCurSel(i);
		}
	}


	for (size_t i = 0; i < SGQY2_ZHUBAO.size(); i++)
	{
		string str = SGQY2_ZHUBAO[i + indexZhuBao];
		CString str2(str.c_str());
		//m_allwujiangji.AddString(str2);
		m_zhuBao.AddString(str2);
	}

	m_wuQi.SetCurSel(shtWuQi - indexBingQi);
	m_bingShu.SetCurSel(shtShuJi - indexBingShu);
	m_ma.SetCurSel(shtMa - indexMa);

	isinit = true;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CTabWuPing::OnCbnSelchangecmbbingfu()
{
	// TODO: 在此添加控件通知处理程序代码
	//pWuJiang->bingzhong = m_bingFu.GetCurSel() + indexbing
	string str = "";
	for (size_t i = 0; i < m_bingFu.GetCount(); i++)
	{
		if (i != m_bingFu.GetCurSel())
		{
			str = "0" + str;
		}
		else
		{
			str = "1" + str;
		}
	}
	bitset<32> bit(str);
	pWuJiang->bingzhong =(int)(bit.to_ulong());;
}


void CTabWuPing::OnCbnSelchangecmbwuqi()
{
	// TODO: 在此添加控件通知处理程序代码
	pWuJiang->wuqisuoyin = m_wuQi.GetCurSel() + indexBingQi;
}


void CTabWuPing::OnCbnSelchangecmbbingshu()
{
	// TODO: 在此添加控件通知处理程序代码
	pWuJiang->shujisuoyin = m_bingShu.GetCurSel() + indexBingShu;
}


void CTabWuPing::OnCbnSelchangecmbma()
{
	// TODO: 在此添加控件通知处理程序代码
	pWuJiang->mapisuoyin = m_ma.GetCurSel() + indexMa;
}


void CTabWuPing::OnCbnSelchangecmbzhubao()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void CTabWuPing::OnCbnSelchangecmbzhenxing()
{
	// TODO: 在此添加控件通知处理程序代码
	string str = "";
	for (size_t i = 0; i < m_zhenXing.GetCount(); i++)
	{
		if (i != m_zhenXing.GetCurSel())
		{
			str = "0" + str;
		}
		else
		{
			str = "1" + str;
		}
	}
	bitset<32> bit(str);
	pWuJiang->zhenxing = (int)(bit.to_ulong());;
}


void CTabWuPing::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData();
	isinit = false;
	//CDialogEx::OnOK();
}


void CTabWuPing::OnLvnItemchangedListBingfu(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if (isinit == false)
	{
		*pResult = 0;
		return;
	}
	if ((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(1)) /* old state : unchecked */
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(2)) /* new state : checked */
		)
	{
		TRACE("Item %d is checked\n", pNMLV->iItem);
		pWuJiang->keyongbingzhong = pWuJiang->keyongbingzhong + pow(2, pNMLV->iItem);
	}
	else if ((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(2)) /* old state : checked */
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(1)) /* new state : unchecked */
		)
	{
		TRACE("Item %d is unchecked\n", pNMLV->iItem);
		pWuJiang->keyongbingzhong = pWuJiang->keyongbingzhong - pow(2, pNMLV->iItem);
	}
	else
	{
		TRACE("Item %d does't change the check-status\n", pNMLV->iItem);
	}

	*pResult = 0;
}


void CTabWuPing::OnLvnItemchangedListZhenxing(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if (isinit == false)
	{
		*pResult = 0;
		return;
	}
	if ((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(1)) /* old state : unchecked */
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(2)) /* new state : checked */
		)
	{
		TRACE("Item %d is checked\n", pNMLV->iItem);
		pWuJiang->kexuanzhenxing = pWuJiang->kexuanzhenxing + pow(2, pNMLV->iItem);
	}
	else if ((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(2)) /* old state : checked */
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(1)) /* new state : unchecked */
		)
	{
		TRACE("Item %d is unchecked\n", pNMLV->iItem);
		pWuJiang->kexuanzhenxing = pWuJiang->kexuanzhenxing - pow(2, pNMLV->iItem);
	}
	else
	{
		TRACE("Item %d does't change the check-status\n", pNMLV->iItem);
	}
	*pResult = 0;
}
