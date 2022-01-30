
// SanguoModifyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"

#include "externs.h"

#include "SanguoModify.h"
#include "SanguoModifyDlg.h"
#include "afxdialogex.h"

#include "WuJiangInfo.h"
#include "GroupModify.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <iostream>
#include "CCity.h"
#include "CCityInfo.h"
#include "CTeam.h"






// CSanguoModifyDlg �Ի���


CSanguoModifyDlg::CSanguoModifyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSanguoModifyDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSanguoModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_KingsName, m_ComboKingsName);
	DDX_Control(pDX, IDC_LIST_WUJIANG, m_ListWuJiang);
	DDX_Control(pDX, IDC_BtnOpen, m_BtnOpen);
	//  DDX_Control(pDX, IDC_BtnGroupModify, m_mBtnGroupModify);
	DDX_Control(pDX, IDC_BtnGroupModify, m_BtnGroupModify);
	DDX_Control(pDX, IDC_BtnSave, m_BtnSave);
	DDX_Control(pDX, IDC_COMBO_SelectVersion, m_selectVersion);
	DDX_Control(pDX, IDC_BUTTON1, m_city);
	DDX_Control(pDX, IDC_BUTTON2, m_team);
}

BEGIN_MESSAGE_MAP(CSanguoModifyDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_KingsName, &CSanguoModifyDlg::OnCbnSelchangeComboKingsname)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_WUJIANG, &CSanguoModifyDlg::OnNMRClickListWujiang)
	ON_BN_CLICKED(IDC_BtnOpen, &CSanguoModifyDlg::OnBnClickedBtnopen)
	ON_BN_CLICKED(IDC_BtnSave, &CSanguoModifyDlg::OnBnClickedBtnsave)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_WUJIANG, &CSanguoModifyDlg::OnNMDblclkListWujiang)
	ON_BN_CLICKED(IDC_BtnGroupModify, &CSanguoModifyDlg::OnBnClickedBtngroupmodify)
	ON_CBN_SELCHANGE(IDC_COMBO_SelectVersion, &CSanguoModifyDlg::OnCbnSelchangeComboSelectversion)
	ON_BN_CLICKED(IDC_BUTTON1, &CSanguoModifyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSanguoModifyDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSanguoModifyDlg ��Ϣ�������

BOOL CSanguoModifyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CRect	rect;
	m_ListWuJiang.GetClientRect(&rect);

	m_ListWuJiang.SetExtendedStyle(m_ListWuJiang.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_BtnGroupModify.EnableWindow(FALSE);
	m_BtnSave.EnableWindow(FALSE);
	m_ComboKingsName.EnableWindow(FALSE);
	m_city.EnableWindow(FALSE);
	m_team.EnableWindow(FALSE);

	SetDlgItemText(IDC_STATIC_Kings,L"ѡ�����");
	SetDlgItemText(IDC_STATIC,L"\n��� \"���ļ�\" ����浵�ļ�");

	m_ListWuJiang.InsertColumn(0, _T("�佫ID"), LVCFMT_LEFT, 60, 0);   
    m_ListWuJiang.InsertColumn(1, _T("�佫����"), LVCFMT_LEFT, 60, 1);   
    m_ListWuJiang.InsertColumn(2, _T("HP���ֵ"), LVCFMT_LEFT, 65, 2);
	m_ListWuJiang.InsertColumn(3, _T("HP��ǰֵ"), LVCFMT_LEFT, 65, 3);
	m_ListWuJiang.InsertColumn(4, _T("MP���ֵ"), LVCFMT_LEFT, 65, 4);
	m_ListWuJiang.InsertColumn(5, _T("MP��ǰֵ"), LVCFMT_LEFT, 65, 5);
	m_ListWuJiang.InsertColumn(6, _T("HP����ֵ"), LVCFMT_LEFT, 65, 6);
	m_ListWuJiang.InsertColumn(7, _T("MP����ֵ"), LVCFMT_LEFT, 65, 7);
	m_ListWuJiang.InsertColumn(8, _T("����ֵ"), LVCFMT_LEFT, 70, 8);
	m_ListWuJiang.InsertColumn(9, _T("�ȼ�"), LVCFMT_LEFT, 40, 9);
	m_ListWuJiang.InsertColumn(10, _T("��������ֵ"), LVCFMT_LEFT, 75, 10);
	m_ListWuJiang.InsertColumn(11, _T("��������ֵ"), LVCFMT_LEFT, 75, 11);
	m_ListWuJiang.InsertColumn(12, _T("������ǰֵ"), LVCFMT_LEFT, 75, 12);
	m_ListWuJiang.InsertColumn(13, _T("������ǰֵ"), LVCFMT_LEFT, 75, 12);
	m_ListWuJiang.InsertColumn(14, _T("ʿ��"), LVCFMT_LEFT, 40, 13);
	m_ListWuJiang.InsertColumn(15, _T("ƣ��"), LVCFMT_LEFT, 40, 14);
	m_ListWuJiang.InsertColumn(16, _T("�ҳ϶�"), LVCFMT_LEFT, 50, 15);
	m_ListWuJiang.InsertColumn(17, _T("��ǰ��¼λ��"), LVCFMT_LEFT, 90, 16);
	m_ListWuJiang.InsertColumn(18, _T("��һ��¼λ��"), LVCFMT_LEFT, 90, 17);

	m_ListWuJiang.InsertColumn(19, _T("����������������"), LVCFMT_LEFT, 110, 18);
	m_ListWuJiang.InsertColumn(20, _T("δ֪�������ڵ�������"), LVCFMT_LEFT, 110, 19);
	m_ListWuJiang.InsertColumn(21, _T("����������������"), LVCFMT_LEFT, 110, 20);
	m_ListWuJiang.InsertColumn(22, _T("���ڳǳ���������"), LVCFMT_LEFT, 110, 21);
	m_ListWuJiang.InsertColumn(23, _T("������һ�佫����"), LVCFMT_LEFT, 110, 22);
	m_ListWuJiang.InsertColumn(24, _T("������һ�佫����"), LVCFMT_LEFT, 110, 23);
	m_ListWuJiang.InsertColumn(25, _T("�ǳ���һ�佫����"), LVCFMT_LEFT, 110, 24);
	m_ListWuJiang.InsertColumn(26, _T("δ֪"), LVCFMT_LEFT, 40, 24);
	m_ListWuJiang.InsertColumn(27, _T("δ֪"), LVCFMT_LEFT, 40, 24);
	m_ListWuJiang.InsertColumn(28, _T("δ֪"), LVCFMT_LEFT, 40, 24);

	string str = GetExePath();
	CString cstr(str.c_str());
	vector<string> dirVec = ScanFile(cstr);
	for (size_t i = 0; i < dirVec.size(); i++)
	{
		//LPCTSTR cstr = (LPCTSTR)dirVec[i].c_str();
		CString cstr2(dirVec[i].c_str());
		m_selectVersion.AddString(cstr2);
	}
	//m_selectVersion.SetCurSel(0);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSanguoModifyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSanguoModifyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSanguoModifyDlg::AddRecord(int index)
{
	TCHAR szTmp[100];
	int nLastRow;
	
	wsprintf(wujiangnamebig5char,L"%s",pWuJiang->name);
	//TranslateNameToGB2312Unicode();

	wsprintf(szTmp,L"%d",index);
	nLastRow = m_ListWuJiang.InsertItem(index, szTmp);


	//wsprintf(wujiangnameunicodechar, L"%s", BIG5ToUnicode((const TCHAR*)wujiangnamebig5char));
	//m_ListWuJiang.SetItemText(nLastRow, 1,wujiangnameunicodechar);
	m_ListWuJiang.SetItemText(nLastRow, 1, BIG5ToUnicode((const TCHAR*)wujiangnamebig5char));
	//m_ListWuJiang.SetItemText(nLastRow, 1, (const TCHAR*)BIG5ToGB2312((const char*)wujiangnameunicodechar));
	wsprintf(szTmp,L"%d",pWuJiang->hpmax);
	m_ListWuJiang.SetItemText(nLastRow, 2,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->hp);
	m_ListWuJiang.SetItemText(nLastRow, 3,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->mpmax);
	m_ListWuJiang.SetItemText(nLastRow, 4,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->mp);
	m_ListWuJiang.SetItemText(nLastRow, 5,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->hpbasic);
	m_ListWuJiang.SetItemText(nLastRow, 6,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->mpbasic);
	m_ListWuJiang.SetItemText(nLastRow, 7,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->exp);
	m_ListWuJiang.SetItemText(nLastRow, 8,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->level);
	m_ListWuJiang.SetItemText(nLastRow, 9,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->wulibasic);
	m_ListWuJiang.SetItemText(nLastRow, 10,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->zhilibasic);
	m_ListWuJiang.SetItemText(nLastRow, 11,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->wuli);
	m_ListWuJiang.SetItemText(nLastRow, 12,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->zhili);
	m_ListWuJiang.SetItemText(nLastRow, 13,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->shiqi);
	m_ListWuJiang.SetItemText(nLastRow, 14,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->pilao);
	m_ListWuJiang.SetItemText(nLastRow, 15,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->zhongcheng);
	m_ListWuJiang.SetItemText(nLastRow, 16,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->nextindex-1);
	m_ListWuJiang.SetItemText(nLastRow, 17,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->nextindex);
	m_ListWuJiang.SetItemText(nLastRow, 18,szTmp);

	wsprintf(szTmp,L"%d",pWuJiang->suoyinzhi);
	m_ListWuJiang.SetItemText(nLastRow, 19,szTmp);

	//wsprintf(szTmp,L"%d",pWuJiang->suoyinzhi[1]);
	//m_ListWuJiang.SetItemText(nLastRow, 20,szTmp);

	//wsprintf(szTmp,L"%d",pWuJiang->suoyinzhi[2]);
	//m_ListWuJiang.SetItemText(nLastRow, 21,szTmp);

	//wsprintf(szTmp,L"%d",pWuJiang->suoyinzhi[3]);
	//m_ListWuJiang.SetItemText(nLastRow, 22,szTmp);

	//wsprintf(szTmp,L"%d",pWuJiang->suoyinzhi[4]);
	//m_ListWuJiang.SetItemText(nLastRow, 23,szTmp);

	//wsprintf(szTmp,L"%d",pWuJiang->suoyinzhi[5]);
	//m_ListWuJiang.SetItemText(nLastRow, 24,szTmp);

	//wsprintf(szTmp,L"%d",pWuJiang->suoyinzhi[6]);
	//m_ListWuJiang.SetItemText(nLastRow, 25,szTmp);

	//wsprintf(szTmp,L"%d",pWuJiang->suoyinzhi[7]);
	//m_ListWuJiang.SetItemText(nLastRow, 26,szTmp);

	//wsprintf(szTmp,L"%d",pWuJiang->suoyinzhi[8]);
	//m_ListWuJiang.SetItemText(nLastRow, 27,szTmp);

	//wsprintf(szTmp,L"%d",pWuJiang->suoyinzhi[9]);
	//m_ListWuJiang.SetItemText(nLastRow, 28,szTmp);
}


void CSanguoModifyDlg::UpdateRecord(void)
{
	
	
	wsprintf(wujiangnamebig5char,L"%s",pWuJiang->name);

	TranslateNameToGB2312Unicode();
	
}




void CSanguoModifyDlg::OnCbnSelchangeComboKingsname()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nSel;
	nSel = m_ComboKingsName.GetCurSel();

	//�����佫���ݵ�ListControl
	memset(wujiangnamebig5char,0,sizeof(wujiangnamebig5char));
	memset(wujiangnamegb2312char,0,sizeof(wujiangnamegb2312char));
	memset(Wujiangliebiao,0,sizeof(Wujiangliebiao));

	m_ListWuJiang.DeleteAllItems();		//���ListControl

	for(int i = 0; i < pFileHeader->pWujiangTailNodeIndex+1 ;i++){	//�佫����Ϊ0x200=512,ʵ������Ϊ409�����һ��Ϊ����𩡱
		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + i * 0x11F );  //�佫��¼λ��
		if(nSel == m_ComboKingsName.GetCount()-1){
			AddRecord(i);								//ȫ���佫
		}else if(nSel == pWuJiang->suoyinzhi) {
			AddRecord(i);								//�����佫
		}	
	}

	LPTSTR pszDestText = new TCHAR[1024];
	_swprintf(pszDestText,L"����1. ˫�����һ��б����佫��¼,�޸�ָ���佫����. \n����2. ���\"�����޸�\" �޸Ķ���佫����\n�޸Ľ���,���\"�����޸�\",�������");
	SetDlgItemText(IDC_STATIC,pszDestText);


}





void CSanguoModifyDlg::OnBnClickedBtnopen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//TCHAR* p;
	//TCHAR* q;
	//q= _T("��ͳ���");
	//TCHAR aa[6];
	////p = (TCHAR*)GB2312ToBIG5((const char*)q);
	//wsprintf(aa, L"%s", GB2312ToBIG5(q));
	//
	//MessageBox(aa);

	char strFilePath[1024];
	CString strFileName;

	TCHAR szFilter[] = {L"All Files(*.*)|*.*|*.txt||"};	

	CFileDialog dlg(TRUE,NULL,L"C:\\temp\\",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,NULL);
	if(dlg.DoModal() == IDOK){	
		strFileName = dlg.GetPathName();
		wsprintfA(strFilePath,"%ls",dlg.GetPathName());
		//dlg.GetFileName();
	}else{	
		return;
	}
	
	errno_t err;	
	err = fopen_s(&fp,strFilePath,"rb");

	if( ! fp ) {
		MessageBox(L"File Open Failed !");
	}
	else{
		//m_BtnOpen.EnableWindow(FALSE);
		m_BtnGroupModify.EnableWindow(TRUE);
		m_BtnSave.EnableWindow(TRUE);
		m_ComboKingsName.EnableWindow(TRUE);
		m_city.EnableWindow(TRUE);
		m_team.EnableWindow(TRUE);
		memset(FileContent,0,sizeof(FileContent));
	}
	nFileSize = fread(FileContent,1,300000,fp);
	if(nFileSize){
	//below three lines are for debug purpose only
		LPTSTR pszDestText = new TCHAR[1024];
		_swprintf(pszDestText,L"�ļ� %s �Ѷ���, %d �ֽ�\n\n\"ѡ�����\" --�����佫�б�",strFileName,nFileSize);
		SetDlgItemText(IDC_STATIC,pszDestText);
	}	
	fclose(fp);

	pFileHeader = (FileHeader*)(FileContent);


	//���������б�ComboBox
	m_ComboKingsName.ResetContent();
	m_ListWuJiang.DeleteAllItems();		//���ListControl
	for( int n = 0;n <= pFileHeader->pKingTailNodeIndex; n++){						//���������б�
		pKing = (King*)(FileContent + nFirstKingDataOffset + n * nKingDataSize );
		wsprintf(wujiangnamebig5char,L"%s",pKing->szName);
		wsprintf(wujiangnameunicodechar, L"%s", BIG5ToUnicode((const TCHAR*)wujiangnamebig5char));
		

		//TranslateNameToGB2312Unicode();
		if(n != pFileHeader->SelectedKingIndex){
			m_ComboKingsName.AddString(wujiangnameunicodechar);
		}
		else{				//��Ϸ��Ҿ�����ʶ
			TCHAR szPlayerName[20];
			_swprintf(szPlayerName,L"%s (���)",wujiangnameunicodechar);
			m_ComboKingsName.AddString(szPlayerName);

		}
	}
	m_ComboKingsName.AddString(L"ȫ���佫");
}


void CSanguoModifyDlg::OnBnClickedBtnsave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	
	char strFilePath[1024];
	CString strFileName;

	TCHAR szFilter[] = {L"All Files(*.*)|*.*|*.txt||"};	

	CFileDialog dlg(FALSE,NULL,L"C:\\temp\\",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,NULL);
	if(dlg.DoModal() == IDOK){	
		strFileName = dlg.GetPathName();
		wsprintfA(strFilePath,"%ls",dlg.GetPathName());
	}else{	
		return;
	}	
	
	FILE *fpSave;

	fpSave = fopen( strFilePath,"wb");

	int nWriteSize = fwrite(FileContent,1,nFileSize,fpSave);

	fclose(fpSave);

	if(nWriteSize){
	//below three lines are for debug purpose only
		LPTSTR pszDestText = new TCHAR[1024];
		_swprintf(pszDestText,L"\n�ļ� %s ��д�룬 %d �ֽ�",strFileName,nWriteSize);
		SetDlgItemText(IDC_STATIC,pszDestText);
	}	


}


void CSanguoModifyDlg::OnNMDblclkListWujiang(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	OnNMRClickListWujiang( pNMHDR,  pResult);  //�����һ�������
}


void CSanguoModifyDlg::OnNMRClickListWujiang(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	int nCurrSel;

	if(0==m_ListWuJiang.GetItemCount() ) return;	//����б�Ϊ�գ�ֱ�ӷ���

	nCurrSel = (int)m_ListWuJiang.GetFirstSelectedItemPosition();

	if( 0 == nCurrSel ) return;

	CString szWuJiangID = m_ListWuJiang.GetItemText(nCurrSel-1,0);

	nCurrentWuJiangID = _ttoi(szWuJiangID);
	CWuJiangInfo m_WuJiangInfo;
	m_WuJiangInfo.DoModal();

	OnCbnSelchangeComboKingsname();		//ˢ����ʾ
	
}

void CSanguoModifyDlg::OnBnClickedBtngroupmodify()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CGroupModify m_GroupModify;
	m_GroupModify.DoModal();

	OnCbnSelchangeComboKingsname();		//ˢ����ʾ

}


void CSanguoModifyDlg::OnCbnSelchangeComboSelectversion()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	string str = GetExePath();
	CString cstr(str.c_str());
	CString temp;
	int i = m_selectVersion.GetCurSel();//��ȡ������0-N
	m_selectVersion.GetLBText(i, temp);
	int i2 = 5;
	i2 = CopyFile(cstr + "//" + temp + L"//AttackSkill.TXT", cstr + L"//SYS//AttackSkill.TXT", FALSE);
	i2 = CopyFile(cstr + "//" + temp + L"//Item.txt", cstr + L"//SYS//Item.txt", FALSE);
	i2 = CopyFile(cstr + "//" + temp + L"//StrategicSkill.TXT", cstr + L"//SYS//StrategicSkill.TXT", FALSE);
}


void CSanguoModifyDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCity m_dlgCity;
	m_dlgCity.DoModal();
}


void CSanguoModifyDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTeam m_dlgTeam;
	m_dlgTeam.DoModal();
}
