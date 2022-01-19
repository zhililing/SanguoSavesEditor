#pragma once
#include "afxdialogex.h"


// CTabWuPing 对话框

class CTabWuPing : public CDialogEx
{
	DECLARE_DYNAMIC(CTabWuPing)

public:
	CTabWuPing(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabWuPing();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_bingFu;
	CComboBox m_bingShu;
	CComboBox m_ma;
	CComboBox m_wuQi;
	CComboBox m_zhenXing;
	CComboBox m_zhuBao;
	virtual BOOL OnInitDialog();
	CListCtrl m_lstBingFu;
	CListCtrl m_lstZhenXing;
	bool isinit = false;
	afx_msg void OnCbnSelchangecmbbingfu();
	afx_msg void OnCbnSelchangecmbwuqi();
	afx_msg void OnCbnSelchangecmbbingshu();
	afx_msg void OnCbnSelchangecmbma();
	afx_msg void OnCbnSelchangecmbzhubao();
	afx_msg void OnCbnSelchangecmbzhenxing();
	afx_msg void OnBnClickedOk();
	afx_msg void OnLvnItemchangedListBingfu(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLvnItemchangedListZhenxing(NMHDR* pNMHDR, LRESULT* pResult);
};
