#pragma once
#include "afxdialogex.h"


// CTabBase 对话框

class CTabBase : public CDialog
{
	DECLARE_DYNAMIC(CTabBase)

public:
	CTabBase(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabBase();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
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
	afx_msg void OnBnClickedOk();
};
