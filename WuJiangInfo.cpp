// WuJiangInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Externs.h"
#include "SanguoModify.h"
#include "WuJiangInfo.h"
#include "afxdialogex.h"
#include <map>
#include <string>
using namespace std;


// CWuJiangInfo �Ի���

IMPLEMENT_DYNAMIC(CWuJiangInfo, CDialogEx)

CWuJiangInfo::CWuJiangInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWuJiangInfo::IDD, pParent)
{


}

CWuJiangInfo::~CWuJiangInfo()
{
}

void CWuJiangInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	//DDX_Text(pDX, IDC_EDIT1, m_szName);
	//DDX_Text(pDX, IDC_EDIT2, m_nHPMax);
	//DDX_Text(pDX, IDC_EDIT3, m_nHP);
	//DDX_Text(pDX, IDC_EDIT4, m_nMPMax);
	//DDX_Text(pDX, IDC_EDIT5, m_nMP);
	//DDX_Text(pDX, IDC_EDIT6, m_nHPBasic);
	//DDX_Text(pDX, IDC_EDIT7, m_nMPBasic);
	//DDX_Text(pDX, IDC_EDIT8, m_nExp);
	//DDX_Text(pDX, IDC_EDIT9, m_nLevel);
	//DDX_Text(pDX, IDC_EDIT10, m_nWuLiBasic);
	//DDX_Text(pDX, IDC_EDIT11, m_nZhiLiBasic);
	//DDX_Text(pDX, IDC_EDIT12, m_nWuLi);
	//DDX_Text(pDX, IDC_EDIT13, m_nZhiLi);
	//DDX_Text(pDX, IDC_EDIT14, m_nShiQi);
	//DDX_Text(pDX, IDC_EDIT15, m_nPiLao);
	//DDX_Text(pDX, IDC_EDIT16, m_nZhongCheng);

	//DDX_Text(pDX, IDC_EDIT17, m_nBuBingMax);
	//DDX_Text(pDX, IDC_EDIT18, m_nBuBing);
	//DDX_Text(pDX, IDC_EDIT19, m_nQiBingMax);
	//DDX_Text(pDX, IDC_EDIT20, m_nQiBing);

	//DDX_Text(pDX, IDC_EDIT21, m_nType);
	//DDX_Text(pDX, IDC_EDIT22, m_nStatus);
	//DDX_Text(pDX, IDC_EDIT23, m_nLost);
	//DDX_Text(pDX, IDC_EDIT24, m_nWin);
	//DDX_Text(pDX, IDC_EDIT25, m_nKingIndex);
	//DDX_Control(pDX, IDC_EDIT26, m_nKingIndex);


	DDX_Control(pDX, IDC_TAB1, m_tabctrl);
}


BEGIN_MESSAGE_MAP(CWuJiangInfo, CDialogEx)
	ON_BN_CLICKED(IDOK, &CWuJiangInfo::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CWuJiangInfo::OnBnClickedButton1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CWuJiangInfo::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CWuJiangInfo ��Ϣ�������


void CWuJiangInfo::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


BOOL CWuJiangInfo::OnInitDialog()
{

	this->SetWindowTextW(L"�佫��Ϣ");

	pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + nCurrentWuJiangID * 0x11F );  //�佫��¼λ��
	//wsprintf(wujiangnamebig5char,L"%s",pWuJiang->name);

	////TranslateNameToGB2312Unicode();
	//wsprintf(wujiangnameunicodechar, L"%s", BIG5ToUnicode(wujiangnamebig5char));
	//m_szName = wujiangnameunicodechar;

	//m_nHPMax = pWuJiang->hpmax;
	//m_nHP = pWuJiang->hp;
	//m_nMPMax = pWuJiang->mpmax;
	//m_nMP = pWuJiang->mp;
	//m_nHPBasic = pWuJiang->hpbasic;
	//m_nMPBasic = pWuJiang->mpbasic;
	//m_nExp = pWuJiang->exp;
	//m_nLevel = pWuJiang->level;
	//m_nWuLiBasic = pWuJiang->wulibasic;
	//m_nZhiLiBasic = pWuJiang->zhilibasic;
	//m_nWuLi = pWuJiang->wuli;
	//m_nZhiLi = pWuJiang->zhili;
	//m_nShiQi = pWuJiang->shiqi;
	//m_nPiLao = pWuJiang->pilao;
	//m_nZhongCheng = pWuJiang->zhongcheng;
	//m_nBuBingMax = pWuJiang->bubingmax;
	//m_nBuBing = pWuJiang->bubing;
	//m_nQiBingMax = pWuJiang->qibingmax;
	//m_nQiBing = pWuJiang->qibing;
	//m_nType = pWuJiang->wujiangleixing;
	//m_nStatus = pWuJiang->wujiangzhuangtai;
	//m_nLost = pWuJiang->baichang;
	//m_nWin = pWuJiang->shengchang;
	//m_nKingIndex = pWuJiang->suoyinzhi[0];

	//
	//for (size_t i = 0; i < sizeof (pWuJiang->wujiangji) / sizeof(pWuJiang->wujiangji[0]); i++)
	//{
	//	m_ArrWuJiangJi[i] = pWuJiang->wujiangji[i];
	//}


	
	//SetDlgItemText(IDC_STATIC1,L"�佫����");
	//SetDlgItemText(IDC_STATIC2,L"HP���ֵ");
	//SetDlgItemText(IDC_STATIC3,L"HP��ǰֵ");
	//SetDlgItemText(IDC_STATIC4,L"MP���ֵ");
	//SetDlgItemText(IDC_STATIC5,L"MP��ǰֵ");
	//SetDlgItemText(IDC_STATIC6,L"HP����ֵ");
	//SetDlgItemText(IDC_STATIC7,L"MP����ֵ");
	//SetDlgItemText(IDC_STATIC8,L"����ֵ");
	//SetDlgItemText(IDC_STATIC9,L"�ȼ�");
	//SetDlgItemText(IDC_STATIC10,L"��������ֵ");
	//SetDlgItemText(IDC_STATIC11,L"��������ֵ");
	//SetDlgItemText(IDC_STATIC12,L"������ǰֵ");
	//SetDlgItemText(IDC_STATIC13,L"������ǰֵ");
	//SetDlgItemText(IDC_STATIC14,L"ʿ��");
	//SetDlgItemText(IDC_STATIC15,L"ƣ��");
	//SetDlgItemText(IDC_STATIC16,L"�ҳ϶�");
	//SetDlgItemText(IDC_STATIC17,L"�����������ֵ");
	//SetDlgItemText(IDC_STATIC18,L"����������ǰֵ");

	//SetDlgItemText(IDC_STATIC19,L"����������ֵ");
	//SetDlgItemText(IDC_STATIC20,L"���������ǰֵ");
	//SetDlgItemText(IDC_STATIC21,L"�佫����");
	//SetDlgItemText(IDC_STATIC22,L"�佫״̬");
	//SetDlgItemText(IDC_STATIC23,L"ʤ������");
	//SetDlgItemText(IDC_STATIC24,L"�ܳ�����");
	//SetDlgItemText(IDC_STATIC25,L"��������ֵ");
	//SetDlgItemText(IDC_STATIC26,L"......");
	//SetDlgItemText(IDC_STATIC27,L"......");
	//SetDlgItemText(IDC_STATIC28,L"......");
	//SetDlgItemText(IDC_STATIC29,L"......");
	//SetDlgItemText(IDC_STATIC30,L"......");


	CDialogEx::OnInitDialog();
	
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_tabctrl.InsertItem(0, L"����");      //��Ӳ���һѡ� 

	m_tabctrl.InsertItem(1, L"�佫��ʦ��");      //��Ӳ�����ѡ�
	m_tabctrl.InsertItem(2, L"��Ʒ");
	m_base.Create(IDD_DIALOG1, GetDlgItem(IDC_TAB1));
	m_wujiangjunshi.Create(IDD_DIALOG2, GetDlgItem(IDC_TAB1));
	m_wuPing.Create(IDD_DIALOG3, GetDlgItem(IDC_TAB1));
	//���IDC_TABTEST�ͻ�����С

	CRect rs;
	m_tabctrl.GetClientRect(&rs);
	//�����ӶԻ����ڸ������е�λ��
	rs.top += 20;
	//rs.bottom -= 20;
	rs.left += 1;
	rs.right -= 2;
	//�����ӶԻ���ߴ粢�ƶ���ָ��λ��
	m_base .MoveWindow(&rs);
	m_wujiangjunshi.MoveWindow(&rs);
	m_wuPing.MoveWindow(&rs);
	//�ֱ��������غ���ʾ
	m_base.ShowWindow(1);
	m_wujiangjunshi.ShowWindow(0);

	//����Ĭ�ϵ�ѡ�
	m_tabctrl.SetCurSel(0);
	//m_tabctrl.SetCurSel(0);
	//OnTcnSelchangeTab1(NULL, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CWuJiangInfo::OnBnClickedButton1()
{
	
	//UpdateData(TRUE);
	// pWuJiang->hpmax = m_nHPMax ;
	// pWuJiang->hp = m_nHP ;
	// pWuJiang->mpmax = m_nMPMax ;
	// pWuJiang->mp = m_nMP ;
	// pWuJiang->hpbasic = m_nHPBasic ;
	// pWuJiang->mpbasic = m_nMPBasic ;
	// pWuJiang->exp = m_nExp ;
	// pWuJiang->level = m_nLevel ;
	// pWuJiang->wulibasic = m_nWuLiBasic ;
	// pWuJiang->zhilibasic = m_nZhiLiBasic ;
	// pWuJiang->wuli = m_nWuLi ;
	// pWuJiang->zhili = m_nZhiLi ;
	// pWuJiang->shiqi = m_nShiQi ;
	// pWuJiang->pilao = m_nPiLao ;
	// pWuJiang->zhongcheng = m_nZhongCheng ;
	// pWuJiang->bubingmax = m_nBuBingMax ;
	// pWuJiang->bubing = m_nBuBing ;
	// pWuJiang->qibingmax = m_nQiBingMax ;
	// pWuJiang->qibing = m_nQiBing ;
	// pWuJiang->wujiangleixing = m_nType ;
	// pWuJiang->wujiangzhuangtai = m_nStatus ;
	// pWuJiang->baichang = m_nLost ;
	// pWuJiang->shengchang = m_nWin ;
	//OnOK();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CWuJiangInfo::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int CurSel = m_tabctrl.GetCurSel();

	switch (CurSel)
	{
		case 0:
			m_base.ShowWindow(true);
			m_wujiangjunshi.ShowWindow(false);
			m_wuPing.ShowWindow(false);
			break;
		case 1:
			m_base.ShowWindow(false);
			m_wujiangjunshi.ShowWindow(true);
			m_wuPing.ShowWindow(false);
			break;
		case 2:
			m_base.ShowWindow(false);
			m_wujiangjunshi.ShowWindow(false);
			m_wuPing.ShowWindow(true);
			break;
		default:
			break;
	}
	*pResult = 0;
}


void CWuJiangInfo::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	m_wuPing.isinit = false;
	CDialogEx::OnCancel();
}
