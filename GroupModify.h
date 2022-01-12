#pragma once


// CGroupModify 对话框

class CGroupModify : public CDialogEx
{
	DECLARE_DYNAMIC(CGroupModify)

public:
	CGroupModify(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGroupModify();

// 对话框数据
	enum { IDD = IDD_GROUPMODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnexportlist();
	afx_msg void OnBnClickedBtnwuliup();
	afx_msg void OnBnClickedBtnwulidown();
	afx_msg void OnBnClickedBtnzhongchengdong();
	afx_msg void OnBnClickedBtnjiliup();
	afx_msg void OnBnClickedBtnjilidown();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnzhongchengdongup();
	afx_msg void OnBnClickedBtnshiqiup();
	afx_msg void OnBnClickedBtnshiqidown();
};
