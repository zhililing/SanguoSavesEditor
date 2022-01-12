#pragma once
#include "afxdialogex.h"
#include "EditListCtrl.h"
#include "ListCtrlEx.h"
#include "DlgColor.h"


// CTabWuJiangJunShi 对话框

class CTabWuJiangJunShi : public CDialog
{
	DECLARE_DYNAMIC(CTabWuJiangJunShi)

public:
	CTabWuJiangJunShi(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabWuJiangJunShi();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	static BOOL InitEditor(CWnd** pWnd, int nRow, int nColumn, CString& strSubItemText, DWORD_PTR dwItemData, void* pThis, BOOL bUpdate);
	static BOOL EndEditor(CWnd** pWnd, int nRow, int nColumn, CString& strSubItemText, DWORD_PTR dwItemData, void* pThis, BOOL bUpdate);


	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrlEx m_onewujiangji;
	CListCtrlEx m_onejunshiji;
	CListBox m_allwujiangji;
	CListBox m_alljunshiji;
	short m_ArrWuJiangJi[8];
	afx_msg void OnBnClickedOk();

	void AddColumns(void);

	//CDateTimeCtrl m_wndDT;
	CComboBox m_wndCB;
	CEdit m_wndEdit;
	CComboBox m_wndCB2;
	CEdit m_wndEdit2;
	//CDlgColor m_dlgColor;
};
