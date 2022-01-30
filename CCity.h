#pragma once
#include "afxdialogex.h"


// CCity 对话框

class CCity : public CDialogEx
{
	DECLARE_DYNAMIC(CCity)

public:
	CCity(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCity();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_lstCity;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMDblclkListCity(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMRClickListCity(NMHDR* pNMHDR, LRESULT* pResult);
};
