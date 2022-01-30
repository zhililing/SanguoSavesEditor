#pragma once
#include "afxdialogex.h"


// CCityInfo 对话框

class CCityInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CCityInfo)

public:
	CCityInfo(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCityInfo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	unsigned int  m_cityIndex;
	CString m_cityName;
	CComboBox m_cmbMajor;
	CComboBox m_cmbJunShi;
	unsigned int m_cityCapability;
	unsigned int m_cityLevel;
	unsigned int m_maxSoilder;
	unsigned int m_soilder;
	unsigned int m_popular;
	unsigned int m_defender;
	unsigned int m_money;
	virtual void OnCancel();
	int NameToIndex(CString cstr);
	CString IndexToName(int index);
	afx_msg void OnBnClickedOk();
};
