#pragma once
#define IDD_DIALOGBAR 139

// CDlgColor �Ի���

class CDlgColor : public CDialog
{
	DECLARE_DYNAMIC(CDlgColor)

public:
	CDlgColor(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgColor();

// �Ի�������
	enum { IDD = IDD_DIALOGBAR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_nColor;
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
