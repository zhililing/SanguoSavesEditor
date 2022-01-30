#pragma once
#include "afxdialogex.h"


// CTeamInfo 对话框

class CTeamInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CTeamInfo)

public:
	CTeamInfo(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTeamInfo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	unsigned int m_index;
	unsigned int   m_type;
	unsigned int m_money;
	CComboBox m_major;
	CComboBox m_junshi;
	virtual BOOL OnInitDialog();
	int NameToIndex(CString cstr);
	CString IndexToName(int index);
	afx_msg void OnBnClickedOk();
};
