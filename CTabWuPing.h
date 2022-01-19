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
};
