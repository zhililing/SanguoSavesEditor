
#pragma pack(1)

#pragma once
#include <string>
#include <map>
using namespace std;

#define	nFirstWuJiangDataOffset		0x0000D090
#define	nFirstKingDataOffset		0x000001D0
#define nKingDataSize				0x00000352
#define	nFirstCityDataOffset		0x00006C10
#define	nWupinSearchedDataOffset	0x00033230
#define nFirstCityDataOffset		0x00006C10
#define nCityDataSize				0x000000B2
#define	nFirstTeamDataOffset		0x00009890
#define	nTeamDataSize				0x00000070
struct FileHeader{
	unsigned int	nIdentify;
	unsigned int	nVersion;
	unsigned int	nReserve;
	char			szGeneralDescription[0x40];
	unsigned int	unKnow1;
	unsigned int	SelectedKingIndex;
	unsigned int	DaozeiKingIndex;
	unsigned int	nYear;
	unsigned short	unKnow2;
	unsigned short	unKnow3;
	unsigned int	unKnow4;
	unsigned int	unKnow5;
	unsigned int	nMaxKing;
	unsigned int	pKingDataOffset;
	unsigned int	pKingHeadNodeIndex;
	unsigned int	pKingNextNodeIndex;
	unsigned int	pKingTailNodeIndex;
	unsigned int	nMaxCity;
	unsigned int	pCityDataOffset;
	unsigned int	pCityHeadNodeIndex;
	unsigned int	pCityNextNodeIndex;
	unsigned int	pCityTailNodeIndex;
	unsigned int	pCityNodeIndex[0x40];
	unsigned int	nMaxTeam;
	unsigned int	pTeamDataOffset;
	unsigned int	pTeamHeadNodeIndex;
	unsigned int	pTeamNextNodeIndex;
	unsigned int	pTeamTailNodeIndex;
	unsigned int	nMaxWujiang;
	unsigned int	pWujiangDataOffset;
	unsigned int	pWujiangHeadNodeIndex;
	unsigned int	pWujiangNextNodeIndex;
	unsigned int	pWujiangTailNodeIndex;
	unsigned int	nTotalPath;
	unsigned int	pPathDataOffset;
	unsigned int	nTotalPathPoint;
	unsigned int	pPathPointDataOffset;
	unsigned int	nMaxWupin;
	unsigned int	pWupinSearchedDataOffset;
};


struct King{
	unsigned int	size;
	TCHAR			szName[6];
	unsigned int	pKingAtWujiangNodeIndex;
	unsigned int	unKnow1;		//��Ϊ0
	unsigned int	unKnow2;		//��Ϊ0
	unsigned int	pWujiangOfKingNextNodeIndex;	//���ھ������佫�������һ���ڵ㣬����Ϊ��һ���佫
	unsigned int	unKnow3;
	unsigned int	unKnow4;
	unsigned int	pKingFlag1;
	unsigned int	pKingFlag2;
	unsigned int	nKingExp;
	unsigned int	nKingType;
	char			unKnow5[0x100];
	unsigned short	nKingWupinQty[0x100];
	unsigned int	unKnow6;
	unsigned int	pKingCityNodeIndex;
	unsigned int	pKingTeamNodeIndex;
	unsigned short	nKingYinGui;
	unsigned int	unKnow7;
	unsigned int	unKnow8;
	unsigned int	pKingAtKingNodeIndex;
};

struct City {
	unsigned int	size;
	unsigned int	isUsed;
	TCHAR			szName[6];
	unsigned int	pKingofCityAtKingNodeIndex;
	unsigned int	pMajorofCityAtWuJiangNodeIndex;
	unsigned int	pJunShioffCityAtWuJiangNodeIndex;
	unsigned int	unKnow1;		//��Ϊ0
	unsigned int	unKnow2;		//��Ϊ0
	unsigned int	pFirstWujiangOfCityAtWuJiangNodeIndex;	//���ھ������佫�������һ���ڵ㣬����Ϊ��һ���佫
	unsigned int	unKnow3;
	unsigned int	unKnow4;
	unsigned int	pNumWuJiangofCity;
	unsigned int	pNumWuJiangCapturedofCity;
	unsigned int	unKnow5;
	unsigned int	unKnow6;
	unsigned int	unKnow7;

	unsigned int	nCapacityWuJiangofcity;

	unsigned int	nPathofCity[9];

	short			Level;
	unsigned int	unKnow8;

	short			CenterX;
	short			CenterY;

	short			Left;
	short			ToP;

	short			Right;
	short			Bottom;

	short			FlagX;
	short			FlagY;

	unsigned int	unKnow9;

	unsigned int	nMaxSoilder;
	unsigned int	nSoilder;
	unsigned int	nPersonalofCity;
	unsigned int	nDefenderofCity;
	unsigned int	nMoneyofCity;
	unsigned int	nIndexofCity;
	unsigned int	nSpeedofCity;
	unsigned int	nFlagIndexofCity;
	unsigned int	nNextCityIndex;
	unsigned int	pNextCityAtCityIndex;
};

struct Team {
	unsigned int	size;
	unsigned int	type;
	unsigned short  index;
	unsigned short  startindex;
	
	unsigned int	pKingofTeamAtKingNodeIndex;
	unsigned int	pMajorofTeamAtWuJiangNodeIndex;
	unsigned int	pJunShiofTeamAtWuJiangNodeIndex;
	unsigned int	unKnow1;		//��Ϊ0
	unsigned int	unKnow2;		//��Ϊ0
	unsigned int	pFirstWujiangOfTeamAtWuJiangNodeIndex;	//���ھ������佫�������һ���ڵ㣬����Ϊ��һ���佫
	unsigned int	money;
	unsigned int	teamDirect;
	unsigned int	x;
	unsigned int	y;
	unsigned short	status;
	unsigned short	unKnow3;
	unsigned short	unKnow4;
	unsigned int	unKnow5;

	unsigned int	nearCityIndex;

	unsigned int	teamStartCity;

	unsigned int	teamDestCity;
	unsigned int	teamCrossCity;
	unsigned int	teamPathIndex;
	unsigned int	unknow6;
	unsigned int	unknow7;
	unsigned int	unknow8;
	unsigned int	unknow9;
	unsigned int	ever01;
	unsigned int	ever02;
	unsigned int	pNextTeamAtSameKingIndex;
	unsigned int	pNextTeamIndex;
};

// CSanguo2SaveChangeDlg ��Ԓ���K
struct WuJiang{
	int size;			//�佫�浵��С
    wchar_t name[0x06];	//�佫����
	char namepath[0x20];	//�佫ͷ���ļ����·��
	short hpmax;		//HP���ֵ
	short hp;			//HP��ǰֵ
	short mpmax;		//MP���ֵ
	short mp;			//MP��ǰֵ
	short hpbasic;		//HP����ֵ
	short mpbasic;		//MP����ֵ
	char	unknow[14];   //δ֪Wordֵ 0x02 * 0x07
	int	exp;			//�佫����ֵ
	short level;		//�佫�ȼ�
	short wulibasic;	//��������ֵ
	short zhilibasic;	//��������ֵ
	short wuli;			//������ǰֵ
	short zhili;		//������ǰֵ
	short shiqi;		//ʿ��
	short pilao;		//ƣ��
	short zhongcheng;		//�ҳ϶�
	short unknow1;		//δ֪Wordֵ
	short unknow2;		//δ֪Wordֵ
	short bubingmax;	//�����������ֵ
	short bubing;		//����������ǰֵ
	short qibingmax;	//����������ֵ
	short qibing;		//���������ǰֵ
	short	dengluweizhi[5];   //�佫��5��ʱ�ڵĵ�¼λ�ã��ǳ�������
	short	wujiangji[8];		//�佫��
	byte	junshiji[8];		//��ʦ��
	byte  junshi;				//��ǰѡ�еľ�ʦ����0-7��
	byte wujiangjixuexi[16];	//�佫��ѧϰ���ݣ��佫������-ѧϰ�ȼ���*8
	byte junshijixuexi[16];		//��ʦ��ѧϰ���ݣ���ʦ������-ѧϰ�ȼ���*8
	short	unknow3;		//δ֪Word
	int		keyongbingzhong;		//���ñ��֣�BITֵ��Ч��
	int		bingzhong;				//��ǰʹ�ñ��֣�BIT MASK��
	short	wujiangleixing;			//�佫����
	int		wujiangzhuangtai;		//�佫״̬
	int		unknow4;				//δ֪
	short	mapisuoyin;		//��ƥ����
	short	wuqisuoyin;		//��������
	short	shujisuoyin;	//�鼮����
	short	baichang;		//�ܳ�����
	short	shengchang;		//ʤ������
	short	unknow5;		//δ֪
	short	unknow6;		//δ֪
	int		kexuanzhenxing;		//��ѡ������
	short	zhenxing;			//ѡ������
	short	unknow7[5];			//δ֪
	byte	unknow8[8];			//δ֪
	int		junzhusuoyin;		//�佫���������ھ��������е�����
	int		xuetongsuoyin;		//�佫Ѫͳ��������
	short	jiecao;				//�佫�ڲ�ֵ
	short	unknow9;			//δ֪
	int		suoyinzhi;		//��������ֵ��Ĭ��ΪFFFFFF
	int		nextindex;			//�佫��������һ���佫������
	int		duiWuIndex;
	int     cityIndex;
};

class finder
{
public:
	finder(const std::string& cmp_string) :s_(cmp_string) {}
	bool operator ()(const std::map<int, std::string>::value_type& item)
	{
		return item.second == s_;
	}
private:
	const std::string& s_;
};

int UnicodeBinarySearch(unsigned short key,const unsigned short lookup_table[][3],unsigned int start,unsigned int end);
unsigned short GetGB2312ByBIG5(unsigned short big5);
unsigned short GetUnicodeByBIG5(unsigned short big5);
void TranslateNameToGB2312Unicode(void);




