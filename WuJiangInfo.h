#pragma once
#include "CTabBase.h"
#include "CTabWuJiangJunShi.h"
#include "CTabWuPing.h"


// CWuJiangInfo 对话框

class CWuJiangInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CWuJiangInfo)

public:
	CWuJiangInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CWuJiangInfo();

// 对话框数据
	enum { IDD = IDD_WUJIANGINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
//	CEdit m_szName;
	afx_msg void OnBnClickedButton1();
	CString m_szName;
	unsigned int	m_nHPMax;
	unsigned int	m_nHP;
	unsigned int	m_nMPMax;
	unsigned int	m_nMP;
	unsigned int	m_nHPBasic;
	unsigned int	m_nMPBasic;
	unsigned int	m_nExp;
	unsigned int	m_nLevel;
	unsigned int	m_nWuLiBasic;
	unsigned int	m_nZhiLiBasic;
	unsigned int	m_nWuLi;
	unsigned int	m_nZhiLi;
	unsigned int	m_nShiQi;
	unsigned int	m_nPiLao;
	unsigned int	m_nZhongCheng;
	unsigned int	m_nBuBingMax;
	unsigned int	m_nBuBing;
	unsigned int	m_nQiBingMax;
	unsigned int	m_nQiBing;
	unsigned int	m_nType;
	unsigned int	m_nStatus;
	unsigned int	m_nLost;
	unsigned int	m_nWin;
	unsigned int	m_nKingIndex;




	/*DDX_Text(pDX, IDC_EDIT2, m_nHPMax);
	DDX_Text(pDX, IDC_EDIT3, m_nHPMax);
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

*/
	short m_ArrWuJiangJi[8];
	CTabCtrl m_tabctrl;
	CTabBase m_base;
	CTabWuJiangJunShi m_wujiangjunshi;
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	CTabWuPing m_wuPing;
};
