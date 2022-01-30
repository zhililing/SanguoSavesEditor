#pragma once
#include "afxdialogex.h"


// CTeam 对话框

class CTeam : public CDialogEx
{
	DECLARE_DYNAMIC(CTeam)

public:
	CTeam(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTeam();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_lstTeam;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMDblclkListTeam(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMRClickListTeam(NMHDR* pNMHDR, LRESULT* pResult);
};
