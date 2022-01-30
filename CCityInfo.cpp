// CCityInfo.cpp: 实现文件
//

#include "stdafx.h"
#include "Externs.h"
#include "SanguoModify.h"
#include "afxdialogex.h"
#include "CCityInfo.h"


// CCityInfo 对话框

IMPLEMENT_DYNAMIC(CCityInfo, CDialogEx)

CCityInfo::CCityInfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

CCityInfo::~CCityInfo()
{
}

void CCityInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_index, m_cityIndex);
	DDX_Text(pDX, IDC_EDIT_name, m_cityName);
	DDX_Control(pDX, IDC_COMBO_major, m_cmbMajor);
	DDX_Control(pDX, IDC_COMBO_junshi, m_cmbJunShi);
	DDX_Text(pDX, IDC_EDIT_capacity, m_cityCapability);
	DDX_Text(pDX, IDC_EDIT_level, m_cityLevel);
	DDX_Text(pDX, IDC_EDIT_maxSoilder, m_maxSoilder);
	DDX_Text(pDX, IDC_EDIT_soilder, m_soilder);
	DDX_Text(pDX, IDC_EDIT_personal, m_popular);
	DDX_Text(pDX, IDC_EDIT_defender, m_defender);
	DDX_Text(pDX, IDC_EDIT_money, m_money);
}


BEGIN_MESSAGE_MAP(CCityInfo, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCityInfo::OnBnClickedOk)
END_MESSAGE_MAP()


// CCityInfo 消息处理程序


BOOL CCityInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	pCity = (City*)(FileContent + nFirstCityDataOffset + nCurrentCityID * nCityDataSize);

	m_cityIndex = pCity->nIndexofCity;

	wsprintf(wujiangnamebig5char, L"%s", pCity->szName);
	wsprintf(wujiangnameunicodechar, L"%s", BIG5ToUnicode(wujiangnamebig5char));
	m_cityName = wujiangnameunicodechar;

	for (int n = 0; n <= pFileHeader->pWujiangTailNodeIndex; n++) 
	{
		WuJiang*  tpWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + n * 0x11F);
		if (tpWuJiang->cityIndex == pCity->nIndexofCity)
		{
			m_cmbMajor.AddString(BIG5ToUnicode(tpWuJiang->name));
			m_cmbJunShi.AddString(BIG5ToUnicode(tpWuJiang->name));
		}	
	}
	CString strMajorName = IndexToName(pCity->pMajorofCityAtWuJiangNodeIndex);
	CString strJunShiName = IndexToName(pCity->pJunShioffCityAtWuJiangNodeIndex);
	((CComboBox*)GetDlgItem(IDC_COMBO_major))->SetWindowText(strMajorName);
	((CComboBox*)GetDlgItem(IDC_COMBO_junshi))->SetWindowText(strJunShiName);
	m_cityCapability = pCity->nCapacityWuJiangofcity;
	m_cityLevel = pCity->Level;
	m_maxSoilder = pCity->nMaxSoilder;
	m_soilder = pCity->nSoilder;
	m_popular = pCity->nPersonalofCity;
	m_defender = pCity->nDefenderofCity;
	m_money = pCity->nMoneyofCity;
	UpdateData(false);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CCityInfo::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::OnCancel();
}

int CCityInfo::NameToIndex(CString cstr)
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

CString CCityInfo::IndexToName(int index)
{
	WuJiang* tpWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F);
	return BIG5ToUnicode(tpWuJiang->name);
}

void CCityInfo::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	CString str;
	m_cmbMajor.GetWindowTextW(str);
	pCity->pMajorofCityAtWuJiangNodeIndex = NameToIndex(str);

	CString cstr;
	m_cmbJunShi.GetWindowTextW(cstr);
	pCity->pJunShioffCityAtWuJiangNodeIndex = NameToIndex(cstr);

	pCity->nCapacityWuJiangofcity = m_cityCapability;
	pCity->Level = m_cityLevel;
	pCity->nMaxSoilder = m_maxSoilder;
	pCity->nSoilder = m_soilder;
	pCity->nPersonalofCity = m_popular;
	pCity->nDefenderofCity = m_defender;
	pCity->nMoneyofCity = m_money;

	CDialogEx::OnOK();
}
