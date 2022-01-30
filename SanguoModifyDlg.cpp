
// SanguoModifyDlg.cpp : 实现文件
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






// CSanguoModifyDlg 对话框


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


// CSanguoModifyDlg 消息处理程序

BOOL CSanguoModifyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CRect	rect;
	m_ListWuJiang.GetClientRect(&rect);

	m_ListWuJiang.SetExtendedStyle(m_ListWuJiang.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_BtnGroupModify.EnableWindow(FALSE);
	m_BtnSave.EnableWindow(FALSE);
	m_ComboKingsName.EnableWindow(FALSE);
	m_city.EnableWindow(FALSE);
	m_team.EnableWindow(FALSE);

	SetDlgItemText(IDC_STATIC_Kings,L"选择君主");
	SetDlgItemText(IDC_STATIC,L"\n点击 \"打开文件\" 读入存档文件");

	m_ListWuJiang.InsertColumn(0, _T("武将ID"), LVCFMT_LEFT, 60, 0);   
    m_ListWuJiang.InsertColumn(1, _T("武将姓名"), LVCFMT_LEFT, 60, 1);   
    m_ListWuJiang.InsertColumn(2, _T("HP最大值"), LVCFMT_LEFT, 65, 2);
	m_ListWuJiang.InsertColumn(3, _T("HP当前值"), LVCFMT_LEFT, 65, 3);
	m_ListWuJiang.InsertColumn(4, _T("MP最大值"), LVCFMT_LEFT, 65, 4);
	m_ListWuJiang.InsertColumn(5, _T("MP当前值"), LVCFMT_LEFT, 65, 5);
	m_ListWuJiang.InsertColumn(6, _T("HP基础值"), LVCFMT_LEFT, 65, 6);
	m_ListWuJiang.InsertColumn(7, _T("MP基础值"), LVCFMT_LEFT, 65, 7);
	m_ListWuJiang.InsertColumn(8, _T("经验值"), LVCFMT_LEFT, 70, 8);
	m_ListWuJiang.InsertColumn(9, _T("等级"), LVCFMT_LEFT, 40, 9);
	m_ListWuJiang.InsertColumn(10, _T("武力基础值"), LVCFMT_LEFT, 75, 10);
	m_ListWuJiang.InsertColumn(11, _T("智力基础值"), LVCFMT_LEFT, 75, 11);
	m_ListWuJiang.InsertColumn(12, _T("武力当前值"), LVCFMT_LEFT, 75, 12);
	m_ListWuJiang.InsertColumn(13, _T("智力当前值"), LVCFMT_LEFT, 75, 12);
	m_ListWuJiang.InsertColumn(14, _T("士气"), LVCFMT_LEFT, 40, 13);
	m_ListWuJiang.InsertColumn(15, _T("疲劳"), LVCFMT_LEFT, 40, 14);
	m_ListWuJiang.InsertColumn(16, _T("忠诚度"), LVCFMT_LEFT, 50, 15);
	m_ListWuJiang.InsertColumn(17, _T("当前记录位置"), LVCFMT_LEFT, 90, 16);
	m_ListWuJiang.InsertColumn(18, _T("下一记录位置"), LVCFMT_LEFT, 90, 17);

	m_ListWuJiang.InsertColumn(19, _T("所属君主链表索引"), LVCFMT_LEFT, 110, 18);
	m_ListWuJiang.InsertColumn(20, _T("未知（君主节点索引）"), LVCFMT_LEFT, 110, 19);
	m_ListWuJiang.InsertColumn(21, _T("所属队伍链表索引"), LVCFMT_LEFT, 110, 20);
	m_ListWuJiang.InsertColumn(22, _T("所在城池链表索引"), LVCFMT_LEFT, 110, 21);
	m_ListWuJiang.InsertColumn(23, _T("君主下一武将索引"), LVCFMT_LEFT, 110, 22);
	m_ListWuJiang.InsertColumn(24, _T("队伍下一武将索引"), LVCFMT_LEFT, 110, 23);
	m_ListWuJiang.InsertColumn(25, _T("城池下一武将索引"), LVCFMT_LEFT, 110, 24);
	m_ListWuJiang.InsertColumn(26, _T("未知"), LVCFMT_LEFT, 40, 24);
	m_ListWuJiang.InsertColumn(27, _T("未知"), LVCFMT_LEFT, 40, 24);
	m_ListWuJiang.InsertColumn(28, _T("未知"), LVCFMT_LEFT, 40, 24);

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
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSanguoModifyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
	// TODO: 在此添加控件通知处理程序代码
	int nSel;
	nSel = m_ComboKingsName.GetCurSel();

	//读出武将数据到ListControl
	memset(wujiangnamebig5char,0,sizeof(wujiangnamebig5char));
	memset(wujiangnamegb2312char,0,sizeof(wujiangnamegb2312char));
	memset(Wujiangliebiao,0,sizeof(Wujiangliebiao));

	m_ListWuJiang.DeleteAllItems();		//清空ListControl

	for(int i = 0; i < pFileHeader->pWujiangTailNodeIndex+1 ;i++){	//武将数量为0x200=512,实际数量为409，最后一个为“黄皓”
		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + i * 0x11F );  //武将记录位置
		if(nSel == m_ComboKingsName.GetCount()-1){
			AddRecord(i);								//全部武将
		}else if(nSel == pWuJiang->suoyinzhi) {
			AddRecord(i);								//君主武将
		}	
	}

	LPTSTR pszDestText = new TCHAR[1024];
	_swprintf(pszDestText,L"方法1. 双击或右击列表中武将记录,修改指定武将数据. \n方法2. 点击\"批量修改\" 修改多个武将数据\n修改结束,点击\"保存修改\",保存更新");
	SetDlgItemText(IDC_STATIC,pszDestText);


}





void CSanguoModifyDlg::OnBnClickedBtnopen()
{
	// TODO: 在此添加控件通知处理程序代码
	//TCHAR* p;
	//TCHAR* q;
	//q= _T("凌统马国");
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
		_swprintf(pszDestText,L"文件 %s 已读入, %d 字节\n\n\"选择君主\" --更新武将列表",strFileName,nFileSize);
		SetDlgItemText(IDC_STATIC,pszDestText);
	}	
	fclose(fp);

	pFileHeader = (FileHeader*)(FileContent);


	//导出君主列表到ComboBox
	m_ComboKingsName.ResetContent();
	m_ListWuJiang.DeleteAllItems();		//清空ListControl
	for( int n = 0;n <= pFileHeader->pKingTailNodeIndex; n++){						//导出君主列表
		pKing = (King*)(FileContent + nFirstKingDataOffset + n * nKingDataSize );
		wsprintf(wujiangnamebig5char,L"%s",pKing->szName);
		wsprintf(wujiangnameunicodechar, L"%s", BIG5ToUnicode((const TCHAR*)wujiangnamebig5char));
		

		//TranslateNameToGB2312Unicode();
		if(n != pFileHeader->SelectedKingIndex){
			m_ComboKingsName.AddString(wujiangnameunicodechar);
		}
		else{				//游戏玩家君主标识
			TCHAR szPlayerName[20];
			_swprintf(szPlayerName,L"%s (玩家)",wujiangnameunicodechar);
			m_ComboKingsName.AddString(szPlayerName);

		}
	}
	m_ComboKingsName.AddString(L"全部武将");
}


void CSanguoModifyDlg::OnBnClickedBtnsave()
{
	// TODO: 在此添加控件通知处理程序代码

	
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
		_swprintf(pszDestText,L"\n文件 %s 已写入， %d 字节",strFileName,nWriteSize);
		SetDlgItemText(IDC_STATIC,pszDestText);
	}	


}


void CSanguoModifyDlg::OnNMDblclkListWujiang(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	OnNMRClickListWujiang( pNMHDR,  pResult);  //调用右击处理函数
}


void CSanguoModifyDlg::OnNMRClickListWujiang(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	int nCurrSel;

	if(0==m_ListWuJiang.GetItemCount() ) return;	//如果列表为空，直接返回

	nCurrSel = (int)m_ListWuJiang.GetFirstSelectedItemPosition();

	if( 0 == nCurrSel ) return;

	CString szWuJiangID = m_ListWuJiang.GetItemText(nCurrSel-1,0);

	nCurrentWuJiangID = _ttoi(szWuJiangID);
	CWuJiangInfo m_WuJiangInfo;
	m_WuJiangInfo.DoModal();

	OnCbnSelchangeComboKingsname();		//刷新显示
	
}

void CSanguoModifyDlg::OnBnClickedBtngroupmodify()
{
	// TODO: 在此添加控件通知处理程序代码

	CGroupModify m_GroupModify;
	m_GroupModify.DoModal();

	OnCbnSelchangeComboKingsname();		//刷新显示

}


void CSanguoModifyDlg::OnCbnSelchangeComboSelectversion()
{
	// TODO: 在此添加控件通知处理程序代码
	string str = GetExePath();
	CString cstr(str.c_str());
	CString temp;
	int i = m_selectVersion.GetCurSel();//获取索引，0-N
	m_selectVersion.GetLBText(i, temp);
	int i2 = 5;
	i2 = CopyFile(cstr + "//" + temp + L"//AttackSkill.TXT", cstr + L"//SYS//AttackSkill.TXT", FALSE);
	i2 = CopyFile(cstr + "//" + temp + L"//Item.txt", cstr + L"//SYS//Item.txt", FALSE);
	i2 = CopyFile(cstr + "//" + temp + L"//StrategicSkill.TXT", cstr + L"//SYS//StrategicSkill.TXT", FALSE);
}


void CSanguoModifyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CCity m_dlgCity;
	m_dlgCity.DoModal();
}


void CSanguoModifyDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CTeam m_dlgTeam;
	m_dlgTeam.DoModal();
}
