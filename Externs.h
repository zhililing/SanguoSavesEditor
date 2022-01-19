
#pragma pack(1)

#pragma once
#include "Globals.h"
#include <map>
#include <iostream>
#include <vector>
using namespace std;

extern WuJiang *pWuJiang;
extern FileHeader *pFileHeader;
extern King	*pKing;
extern int		nCurrentWuJiangID;
extern FILE *fp;
extern int nFileSize;
extern byte FileContent[300000];
//extern unsigned int		nNextWuJiangPosition = 0;
extern FILE *fpnamelist;
extern char Wujiangliebiao[60];	//导出武将姓名列表文件行数据
extern TCHAR wujiangnamegb2312char[6]; //GB2312武将名
extern TCHAR wujiangnamebig5char[6]; //Big5武将名
extern TCHAR wujiangnameunicodechar[6]; //Unicode武将名
extern int UnicodeBinarySearch(unsigned short key,const unsigned short lookup_table[][3],unsigned int start,unsigned int end);
extern unsigned short GetGB2312ByBIG5(unsigned short big5);
extern unsigned short GetUnicodeByBIG5(unsigned short big5);
extern void TranslateNameToGB2312Unicode(void);
extern wchar_t* BIG5ToUnicode(const TCHAR* szBIG5String);
extern  map<int, string> SGQY2_WUJIANGJI;
extern  map<int, string> SGQY2_JUNSHIJI;
extern  vector<string> SGQY2_BINGFU;
extern  vector<string> SGQY2_BINGSHU;
extern  vector<string> SGQY2_MALEI;
extern  vector<string> SGQY2_ZHENFA;
extern  vector<string> SGQY2_ZHUBAO;
extern  vector<string> SGQY2_BINGQI;
extern	bool IniWuJiangJi();
extern	bool IniJunShiJi();
extern	bool IniWuPing();