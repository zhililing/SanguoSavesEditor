// CTabBase.cpp: 实现文件
//

#include "stdafx.h"
#include "Externs.h"
#include "SanguoModify.h"
#include "afxdialogex.h"
#include "CTabBase.h"


// CTabBase 对话框

IMPLEMENT_DYNAMIC(CTabBase, CDialog)

CTabBase::CTabBase(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CTabBase::~CTabBase()
{
}

void CTabBase::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_szName);
	DDX_Text(pDX, IDC_EDIT2, m_nHPMax);
	DDX_Text(pDX, IDC_EDIT3, m_nHP);
	DDX_Text(pDX, IDC_EDIT4, m_nMPMax);
	DDX_Text(pDX, IDC_EDIT5, m_nMP);
	DDX_Text(pDX, IDC_EDIT6, m_nHPBasic);
	DDX_Text(pDX, IDC_EDIT7, m_nMPBasic);
	DDX_Text(pDX, IDC_EDIT8, m_nExp);
	DDX_Text(pDX, IDC_EDIT9, m_nLevel);
	DDX_Text(pDX, IDC_EDIT10, m_nWuLiBasic);
	DDX_Text(pDX, IDC_EDIT11, m_nZhiLiBasic);
	DDX_Text(pDX, IDC_EDIT12, m_nWuLi);
	DDX_Text(pDX, IDC_EDIT13, m_nZhiLi);
	DDX_Text(pDX, IDC_EDIT14, m_nShiQi);
	DDX_Text(pDX, IDC_EDIT15, m_nPiLao);
	DDX_Text(pDX, IDC_EDIT16, m_nZhongCheng);

	DDX_Text(pDX, IDC_EDIT17, m_nBuBingMax);
	DDX_Text(pDX, IDC_EDIT18, m_nBuBing);
	DDX_Text(pDX, IDC_EDIT19, m_nQiBingMax);
	DDX_Text(pDX, IDC_EDIT20, m_nQiBing);

	DDX_Text(pDX, IDC_EDIT21, m_nType);
	DDX_Text(pDX, IDC_EDIT22, m_nStatus);
	DDX_Text(pDX, IDC_EDIT23, m_nLost);
	DDX_Text(pDX, IDC_EDIT24, m_nWin);
	DDX_Text(pDX, IDC_EDIT25, m_nKingIndex);
	//DDX_Control(pDX, IDC_EDIT26, m_nKingIndex);
}


BEGIN_MESSAGE_MAP(CTabBase, CDialog)
	ON_BN_CLICKED(IDOK, &CTabBase::OnBnClickedOk)
END_MESSAGE_MAP()


// CTabBase 消息处理程序


BOOL CTabBase::OnInitDialog()
{
	

	// TODO:  在此添加额外的初始化
	//pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + nCurrentWuJiangID * 0x11F);  //武将记录位置
	wsprintf(wujiangnamebig5char, L"%s", pWuJiang->name);

	//TranslateNameToGB2312Unicode();
	wsprintf(wujiangnameunicodechar, L"%s", BIG5ToUnicode(wujiangnamebig5char));
	m_szName = wujiangnameunicodechar;

	m_nHPMax = pWuJiang->hpmax;
	m_nHP = pWuJiang->hp;
	m_nMPMax = pWuJiang->mpmax;
	m_nMP = pWuJiang->mp;
	m_nHPBasic = pWuJiang->hpbasic;
	m_nMPBasic = pWuJiang->mpbasic;
	m_nExp = pWuJiang->exp;
	m_nLevel = pWuJiang->level;
	m_nWuLiBasic = pWuJiang->wulibasic;
	m_nZhiLiBasic = pWuJiang->zhilibasic;
	m_nWuLi = pWuJiang->wuli;
	m_nZhiLi = pWuJiang->zhili;
	m_nShiQi = pWuJiang->shiqi;
	m_nPiLao = pWuJiang->pilao;
	m_nZhongCheng = pWuJiang->zhongcheng;
	m_nBuBingMax = pWuJiang->bubingmax;
	m_nBuBing = pWuJiang->bubing;
	m_nQiBingMax = pWuJiang->qibingmax;
	m_nQiBing = pWuJiang->qibing;
	m_nType = pWuJiang->wujiangleixing;
	m_nStatus = pWuJiang->wujiangzhuangtai;
	m_nLost = pWuJiang->baichang;
	m_nWin = pWuJiang->shengchang;
	m_nKingIndex = pWuJiang->suoyinzhi;


	SetDlgItemText(IDC_STATIC1, L"武将姓名");
	SetDlgItemText(IDC_STATIC2, L"HP最大值");
	SetDlgItemText(IDC_STATIC3, L"HP当前值");
	SetDlgItemText(IDC_STATIC4, L"MP最大值");
	SetDlgItemText(IDC_STATIC5, L"MP当前值");
	SetDlgItemText(IDC_STATIC6, L"HP基础值");
	SetDlgItemText(IDC_STATIC7, L"MP基础值");
	SetDlgItemText(IDC_STATIC8, L"经验值");
	SetDlgItemText(IDC_STATIC9, L"等级");
	SetDlgItemText(IDC_STATIC10, L"武力基础值");
	SetDlgItemText(IDC_STATIC11, L"智力基础值");
	SetDlgItemText(IDC_STATIC12, L"武力当前值");
	SetDlgItemText(IDC_STATIC13, L"智力当前值");
	SetDlgItemText(IDC_STATIC14, L"士气");
	SetDlgItemText(IDC_STATIC15, L"疲劳");
	SetDlgItemText(IDC_STATIC16, L"忠诚度");
	SetDlgItemText(IDC_STATIC17, L"步兵数量最大值");
	SetDlgItemText(IDC_STATIC18, L"步兵数量当前值");

	SetDlgItemText(IDC_STATIC19, L"骑兵数量最大值");
	SetDlgItemText(IDC_STATIC20, L"骑兵数量当前值");
	SetDlgItemText(IDC_STATIC21, L"武将类型");
	SetDlgItemText(IDC_STATIC22, L"武将状态");
	SetDlgItemText(IDC_STATIC23, L"胜场次数");
	SetDlgItemText(IDC_STATIC24, L"败场次数");
	SetDlgItemText(IDC_STATIC25, L"君主索引值");
	SetDlgItemText(IDC_STATIC26, L"......");
	SetDlgItemText(IDC_STATIC27, L"......");
	SetDlgItemText(IDC_STATIC28, L"......");
	SetDlgItemText(IDC_STATIC29, L"......");
	SetDlgItemText(IDC_STATIC30, L"......");

	CDialog::OnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CTabBase::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	pWuJiang->hpmax = m_nHPMax;
	pWuJiang->hp = m_nHP;
	pWuJiang->mpmax = m_nMPMax;
	pWuJiang->mp = m_nMP;
	pWuJiang->hpbasic = m_nHPBasic;
	pWuJiang->mpbasic = m_nMPBasic;
	pWuJiang->exp = m_nExp;
	pWuJiang->level = m_nLevel;
	pWuJiang->wulibasic = m_nWuLiBasic;
	pWuJiang->zhilibasic = m_nZhiLiBasic;
	pWuJiang->wuli = m_nWuLi;
	pWuJiang->zhili = m_nZhiLi;
	pWuJiang->shiqi = m_nShiQi;
	pWuJiang->pilao = m_nPiLao;
	pWuJiang->zhongcheng = m_nZhongCheng;
	pWuJiang->bubingmax = m_nBuBingMax;
	pWuJiang->bubing = m_nBuBing;
	pWuJiang->qibingmax = m_nQiBingMax;
	pWuJiang->qibing = m_nQiBing;
	pWuJiang->wujiangleixing = m_nType;
	pWuJiang->wujiangzhuangtai = m_nStatus;
	pWuJiang->baichang = m_nLost;
	pWuJiang->shengchang = m_nWin;
	//CDialog::OnOK();
}
