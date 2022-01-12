// GroupModify.cpp : 实现文件
//

#include "stdafx.h"
#include "Externs.h"
#include "SanguoModify.h"
#include "GroupModify.h"
#include "afxdialogex.h"


// CGroupModify 对话框

IMPLEMENT_DYNAMIC(CGroupModify, CDialogEx)

CGroupModify::CGroupModify(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGroupModify::IDD, pParent)
{

}

CGroupModify::~CGroupModify()
{
}

void CGroupModify::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGroupModify, CDialogEx)
	ON_BN_CLICKED(IDC_BtnExportList, &CGroupModify::OnBnClickedBtnexportlist)
	ON_BN_CLICKED(IDC_BtnWuliUp, &CGroupModify::OnBnClickedBtnwuliup)
	ON_BN_CLICKED(IDC_BtnWuliDown, &CGroupModify::OnBnClickedBtnwulidown)
	ON_BN_CLICKED(IDC_BtnZhongChengDong, &CGroupModify::OnBnClickedBtnzhongchengdong)
	ON_BN_CLICKED(IDC_BtnJiLiUp, &CGroupModify::OnBnClickedBtnjiliup)
	ON_BN_CLICKED(IDC_BtnJiliDown, &CGroupModify::OnBnClickedBtnjilidown)
	ON_BN_CLICKED(IDOK, &CGroupModify::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BtnZhongChengDongUp, &CGroupModify::OnBnClickedBtnzhongchengdongup)
	ON_BN_CLICKED(IDC_BtnShiQiUp, &CGroupModify::OnBnClickedBtnshiqiup)
	ON_BN_CLICKED(IDC_BtnShiQiDown, &CGroupModify::OnBnClickedBtnshiqidown)
END_MESSAGE_MAP()


// CGroupModify 消息处理程序


void CGroupModify::OnBnClickedBtnexportlist()
{
	// TODO: 在此添加控件通知处理程序代码
		
	char strFilePath[1024],szTmp[1024];
	CString strFileName;

	FILE *fp;

	TCHAR szFilter[] = {L"All Files(*.*)|*.*|*.txt||"};	

	CFileDialog dlg(TRUE,NULL,L"C:\\temp\\",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,NULL);
	if(dlg.DoModal() == IDOK){	
		strFileName = dlg.GetPathName();
		wsprintfA(strFilePath,"%ls",dlg.GetPathName());
		//dlg.GetFileName();
	}else{	
		return;
	}

	fp = fopen(strFilePath,"wb");

	sprintf(szTmp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
		"序号","武将姓名","HP最大值","HP当前值","MP最大值","MP当前值","HP基础值","MP基础值","经验值","等级","武力基础值","智力基础值",
		"武力当前值","智力当前值","士气","疲劳","忠诚度","当前记录位置","下一记录位置","所属君主链表索引","未知（君主节点索引）",
		"所属队伍链表索引","所在城池链表索引","君主下一武将索引","队伍下一武将索引","城池下一武将索引","未知","未知","未知");
	
	fwrite(szTmp,1,strlen(szTmp),fp);

	for(int index = 0; index < pFileHeader->pWujiangTailNodeIndex+1 ;index++){	//武将数量为0x200=512,实际数量为409，最后一个为“黄皓”

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F );  //武将记录位置

		wsprintf(wujiangnamebig5char,L"%s",pWuJiang->name);
		TranslateNameToGB2312Unicode();
			
		sprintf(szTmp,"%d\t",index);
		fwrite(szTmp,1,strlen(szTmp),fp);

		fwrite(wujiangnamegb2312char,1,6,fp);
		fwrite("\t",1,1,fp);

		sprintf(szTmp,"%d\t",pWuJiang->hpmax);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->hp);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->mpmax);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->mp);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->hpbasic);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->mpbasic);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->exp);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->level);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->wulibasic);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->zhilibasic);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->wuli);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->zhili);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->shiqi);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->pilao);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->zhongcheng);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->nextindex-1);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->nextindex);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->suoyinzhi[0]);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->suoyinzhi[1]);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->suoyinzhi[2]);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->suoyinzhi[3]);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->suoyinzhi[4]);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->suoyinzhi[5]);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->suoyinzhi[6]);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->suoyinzhi[7]);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\t",pWuJiang->suoyinzhi[8]);
		fwrite(szTmp,1,strlen(szTmp),fp);

		sprintf(szTmp,"%d\n",pWuJiang->suoyinzhi[9]);
		fwrite(szTmp,1,strlen(szTmp),fp);
	}
	fclose(fp);

	GetDlgItem(IDC_BtnExportList)->EnableWindow(FALSE);
	CString szMsg;
	szMsg.Format(L"文件已经保存至：%s",strFileName);
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);
}


void CGroupModify::OnBnClickedBtnwuliup()
{
	// TODO: 在此添加控件通知处理程序代码

	for(int index = 0; index < pFileHeader->pWujiangTailNodeIndex+1 ;index++){	//武将数量为0x200=512,实际数量为409，最后一个为“黄皓”

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F );  //武将记录位置
		if(pWuJiang->suoyinzhi[0] == pFileHeader->SelectedKingIndex){
			pWuJiang->wuli = pWuJiang->wuli + 10;
		}

	}
	CString szMsg;
	szMsg.Format(L"所有己方武将武力值+10");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);

}


void CGroupModify::OnBnClickedBtnwulidown()
{
	// TODO: 在此添加控件通知处理程序代码

	for(int index = 0; index < pFileHeader->pWujiangTailNodeIndex+1 ;index++){	//武将数量为0x200=512,实际数量为409，最后一个为“黄皓”

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F );  //武将记录位置
		if( (pWuJiang->suoyinzhi[0] != pFileHeader->SelectedKingIndex) &&  (pWuJiang->wuli > 60) ){
			pWuJiang->wuli = pWuJiang->wuli - 10;
		}
	}
	CString szMsg;
	szMsg.Format(L"所有敌方武将武力值-10,最低50");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);

}


void CGroupModify::OnBnClickedBtnzhongchengdong()
{
	// TODO: 在此添加控件通知处理程序代码
	for(int index = 0; index < pFileHeader->pWujiangTailNodeIndex+1 ;index++){	//武将数量为0x200=512,实际数量为409，最后一个为“黄皓”

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F );  //武将记录位置
		if( (pWuJiang->suoyinzhi[0] != pFileHeader->SelectedKingIndex) &&  (pWuJiang->zhongcheng > 30) ){
			pWuJiang->zhongcheng = pWuJiang->zhongcheng - 10;
		}
	}
	CString szMsg;
	szMsg.Format(L"所有敌方武将忠诚度-10,最低20");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);

}


void CGroupModify::OnBnClickedBtnjiliup()
{
	// TODO: 在此添加控件通知处理程序代码

	for(int index = 0; index < pFileHeader->pWujiangTailNodeIndex+1 ;index++){	//武将数量为0x200=512,实际数量为409，最后一个为“黄皓”

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F );  //武将记录位置
		if(pWuJiang->suoyinzhi[0] == pFileHeader->SelectedKingIndex){
			pWuJiang->zhili = pWuJiang->zhili + 10;
		}
	}
	CString szMsg;
	szMsg.Format(L"所有己方武将智力+10");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);


}


void CGroupModify::OnBnClickedBtnjilidown()
{
	// TODO: 在此添加控件通知处理程序代码

	for(int index = 0; index < pFileHeader->pWujiangTailNodeIndex+1 ;index++){	//武将数量为0x200=512,实际数量为409，最后一个为“黄皓”

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F );  //武将记录位置
		if( (pWuJiang->suoyinzhi[0] != pFileHeader->SelectedKingIndex) &&  (pWuJiang->zhili > 60) ){
			pWuJiang->zhili = pWuJiang->zhili - 10;
		}
	}
	CString szMsg;
	szMsg.Format(L"所有敌方武将智力-10,最低50");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);


}


void CGroupModify::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();


}


BOOL CGroupModify::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(L"......");

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CGroupModify::OnBnClickedBtnzhongchengdongup()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int index = 0; index < pFileHeader->pWujiangTailNodeIndex + 1; index++) {	//武将数量为0x200=512,实际数量为409，最后一个为“黄皓”

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F);  //武将记录位置
		if ((pWuJiang->suoyinzhi[0] == pFileHeader->SelectedKingIndex)) {
			

			if (pWuJiang->zhongcheng <= 90)
			{
				pWuJiang->zhongcheng = pWuJiang->zhongcheng + 10;
			}
			else
			{
				pWuJiang->zhongcheng = 100;
			}
		}
	}
	CString szMsg;
	szMsg.Format(L"所有敌方武将忠诚度+10,最高100");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);
}


void CGroupModify::OnBnClickedBtnshiqiup()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int index = 0; index < pFileHeader->pWujiangTailNodeIndex + 1; index++) {	//武将数量为0x200=512,实际数量为409，最后一个为“黄皓”

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F);  //武将记录位置
		if ((pWuJiang->suoyinzhi[0] == pFileHeader->SelectedKingIndex)) {
			
			if (pWuJiang->shiqi <= 90)
			{
				pWuJiang->shiqi = pWuJiang->shiqi + 10;
			}
			else
			{
				pWuJiang->shiqi = 100;
			}

			
		}
	}
	CString szMsg;
	szMsg.Format(L"所有敌方武将士气+10,最高100");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);
}


void CGroupModify::OnBnClickedBtnshiqidown()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int index = 0; index < pFileHeader->pWujiangTailNodeIndex + 1; index++) {	//武将数量为0x200=512,实际数量为409，最后一个为“黄皓”

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F);  //武将记录位置
		if ((pWuJiang->suoyinzhi[0] != pFileHeader->SelectedKingIndex)) {
			

			if (pWuJiang->shiqi >= 10)
			{
				pWuJiang->shiqi = pWuJiang->shiqi - 10;
			}
			else
			{
				pWuJiang->shiqi = 0;
			}
		}
	}
	CString szMsg;
	szMsg.Format(L"所有敌方武将士气-10,最低0");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);
}
