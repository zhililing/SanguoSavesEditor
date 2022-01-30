
// SanguoModifyDlg.h : ͷ�ļ�
//

#pragma once


// CSanguoModifyDlg �Ի���
class CSanguoModifyDlg : public CDialogEx
{
// ����
public:
	CSanguoModifyDlg(CWnd* pParent = NULL);	// ��׼���캯��



// �Ի�������
	enum { IDD = IDD_SANGUOMODIFY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOpen();

	//void TranslateNameToGB2312Unicode(void);
	void UpdateRecord(void);
	void AddRecord(int index);

	CComboBox m_ComboBoxWuJiangName;
	CComboBox m_ComboKingsName;
	CListCtrl m_ListWuJiang;
	CButton m_BtnOpen;
	
	afx_msg void OnBnClickedBtnexport();
	afx_msg void OnCbnSelchangeComboKingsname();
	afx_msg void OnNMRClickListWujiang(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnopen();
	afx_msg void OnBnClickedBtnsave();
	afx_msg void OnNMDblclkListWujiang(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtngroupmodify();
//	CButton m_mBtnGroupModify;
	CButton m_BtnGroupModify;
	CButton m_BtnSave;
	afx_msg void OnCbnSelchangeComboSelectversion();
	CComboBox m_selectVersion;
	afx_msg void OnBnClickedButton1();
	CButton m_city;
	afx_msg void OnBnClickedButton2();
	CButton m_team;
};
