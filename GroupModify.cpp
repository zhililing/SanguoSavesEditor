// GroupModify.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Externs.h"
#include "SanguoModify.h"
#include "GroupModify.h"
#include "afxdialogex.h"


// CGroupModify �Ի���

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


// CGroupModify ��Ϣ�������


void CGroupModify::OnBnClickedBtnexportlist()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		
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
		"���","�佫����","HP���ֵ","HP��ǰֵ","MP���ֵ","MP��ǰֵ","HP����ֵ","MP����ֵ","����ֵ","�ȼ�","��������ֵ","��������ֵ",
		"������ǰֵ","������ǰֵ","ʿ��","ƣ��","�ҳ϶�","��ǰ��¼λ��","��һ��¼λ��","����������������","δ֪�������ڵ�������",
		"����������������","���ڳǳ���������","������һ�佫����","������һ�佫����","�ǳ���һ�佫����","δ֪","δ֪","δ֪");
	
	fwrite(szTmp,1,strlen(szTmp),fp);

	for(int index = 0; index < pFileHeader->pWujiangTailNodeIndex+1 ;index++){	//�佫����Ϊ0x200=512,ʵ������Ϊ409�����һ��Ϊ����𩡱

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F );  //�佫��¼λ��

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
	szMsg.Format(L"�ļ��Ѿ���������%s",strFileName);
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);
}


void CGroupModify::OnBnClickedBtnwuliup()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	for(int index = 0; index < pFileHeader->pWujiangTailNodeIndex+1 ;index++){	//�佫����Ϊ0x200=512,ʵ������Ϊ409�����һ��Ϊ����𩡱

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F );  //�佫��¼λ��
		if(pWuJiang->suoyinzhi[0] == pFileHeader->SelectedKingIndex){
			pWuJiang->wuli = pWuJiang->wuli + 10;
		}

	}
	CString szMsg;
	szMsg.Format(L"���м����佫����ֵ+10");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);

}


void CGroupModify::OnBnClickedBtnwulidown()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	for(int index = 0; index < pFileHeader->pWujiangTailNodeIndex+1 ;index++){	//�佫����Ϊ0x200=512,ʵ������Ϊ409�����һ��Ϊ����𩡱

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F );  //�佫��¼λ��
		if( (pWuJiang->suoyinzhi[0] != pFileHeader->SelectedKingIndex) &&  (pWuJiang->wuli > 60) ){
			pWuJiang->wuli = pWuJiang->wuli - 10;
		}
	}
	CString szMsg;
	szMsg.Format(L"���ез��佫����ֵ-10,���50");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);

}


void CGroupModify::OnBnClickedBtnzhongchengdong()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for(int index = 0; index < pFileHeader->pWujiangTailNodeIndex+1 ;index++){	//�佫����Ϊ0x200=512,ʵ������Ϊ409�����һ��Ϊ����𩡱

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F );  //�佫��¼λ��
		if( (pWuJiang->suoyinzhi[0] != pFileHeader->SelectedKingIndex) &&  (pWuJiang->zhongcheng > 30) ){
			pWuJiang->zhongcheng = pWuJiang->zhongcheng - 10;
		}
	}
	CString szMsg;
	szMsg.Format(L"���ез��佫�ҳ϶�-10,���20");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);

}


void CGroupModify::OnBnClickedBtnjiliup()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	for(int index = 0; index < pFileHeader->pWujiangTailNodeIndex+1 ;index++){	//�佫����Ϊ0x200=512,ʵ������Ϊ409�����һ��Ϊ����𩡱

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F );  //�佫��¼λ��
		if(pWuJiang->suoyinzhi[0] == pFileHeader->SelectedKingIndex){
			pWuJiang->zhili = pWuJiang->zhili + 10;
		}
	}
	CString szMsg;
	szMsg.Format(L"���м����佫����+10");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);


}


void CGroupModify::OnBnClickedBtnjilidown()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	for(int index = 0; index < pFileHeader->pWujiangTailNodeIndex+1 ;index++){	//�佫����Ϊ0x200=512,ʵ������Ϊ409�����һ��Ϊ����𩡱

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F );  //�佫��¼λ��
		if( (pWuJiang->suoyinzhi[0] != pFileHeader->SelectedKingIndex) &&  (pWuJiang->zhili > 60) ){
			pWuJiang->zhili = pWuJiang->zhili - 10;
		}
	}
	CString szMsg;
	szMsg.Format(L"���ез��佫����-10,���50");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);


}


void CGroupModify::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();


}


BOOL CGroupModify::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(L"......");

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CGroupModify::OnBnClickedBtnzhongchengdongup()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for (int index = 0; index < pFileHeader->pWujiangTailNodeIndex + 1; index++) {	//�佫����Ϊ0x200=512,ʵ������Ϊ409�����һ��Ϊ����𩡱

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F);  //�佫��¼λ��
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
	szMsg.Format(L"���ез��佫�ҳ϶�+10,���100");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);
}


void CGroupModify::OnBnClickedBtnshiqiup()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for (int index = 0; index < pFileHeader->pWujiangTailNodeIndex + 1; index++) {	//�佫����Ϊ0x200=512,ʵ������Ϊ409�����һ��Ϊ����𩡱

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F);  //�佫��¼λ��
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
	szMsg.Format(L"���ез��佫ʿ��+10,���100");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);
}


void CGroupModify::OnBnClickedBtnshiqidown()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for (int index = 0; index < pFileHeader->pWujiangTailNodeIndex + 1; index++) {	//�佫����Ϊ0x200=512,ʵ������Ϊ409�����һ��Ϊ����𩡱

		pWuJiang = (WuJiang*)(FileContent + nFirstWuJiangDataOffset + index * 0x11F);  //�佫��¼λ��
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
	szMsg.Format(L"���ез��佫ʿ��-10,���0");
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(szMsg);
}
