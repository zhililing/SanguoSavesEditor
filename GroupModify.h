#pragma once


// CGroupModify �Ի���

class CGroupModify : public CDialogEx
{
	DECLARE_DYNAMIC(CGroupModify)

public:
	CGroupModify(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGroupModify();

// �Ի�������
	enum { IDD = IDD_GROUPMODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
