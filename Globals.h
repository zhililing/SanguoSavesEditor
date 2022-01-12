
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
	unsigned int	unKnow1;		//恒为0
	unsigned int	unKnow2;		//恒为0
	unsigned int	pWujiangOfKingNextNodeIndex;	//属于君主的武将链表的下一个节点，君主为第一个武将
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

// CSanguo2SaveChangeDlg 對話方塊
struct WuJiang{
	int size;			//武将存档大小
    wchar_t name[0x06];	//武将姓名
	char namepath[0x20];	//武将头像文件相对路径
	short hpmax;		//HP最大值
	short hp;			//HP当前值
	short mpmax;		//MP最大值
	short mp;			//MP当前值
	short hpbasic;		//HP基础值
	short mpbasic;		//MP基础值
	char	unknow[14];   //未知Word值 0x02 * 0x07
	int	exp;			//武将经验值
	short level;		//武将等级
	short wulibasic;	//武力基础值
	short zhilibasic;	//智力基础值
	short wuli;			//武力当前值
	short zhili;		//智力当前值
	short shiqi;		//士气
	short pilao;		//疲劳
	short zhongcheng;		//忠诚度
	short unknow1;		//未知Word值
	short unknow2;		//未知Word值
	short bubingmax;	//步兵数量最大值
	short bubing;		//步兵数量当前值
	short qibingmax;	//骑兵数量最大值
	short qibing;		//骑兵数量当前值
	short	dengluweizhi[5];   //武将在5个时期的登录位置（城池索引）
	short	wujiangji[8];		//武将技
	byte	junshiji[8];		//军师技
	byte  junshi;				//当前选中的军师技（0-7）
	byte wujiangjixuexi[16];	//武将技学习数据（武将技索引-学习等级）*8
	byte junshijixuexi[16];		//军师技学习数据（军师技索引-学习等级）*8
	short	unknow3;		//未知Word
	int		keyongbingzhong;		//可用兵种（BIT值有效）
	int		bingzhong;				//当前使用兵种（BIT MASK）
	short	wujiangleixing;			//武将类型
	int		wujiangzhuangtai;		//武将状态
	int		unknow4;				//未知
	short	mapisuoyin;		//马匹索引
	short	wuqisuoyin;		//武器索引
	short	shujisuoyin;	//书籍索引
	short	baichang;		//败场次数
	short	shengchang;		//胜场次数
	short	unknow5;		//未知
	short	unknow6;		//未知
	int		kexuanzhenxing;		//可选用阵型
	short	zhenxing;			//选用阵型
	short	unknow7[5];			//未知
	byte	unknow8[8];			//未知
	int		junzhusuoyin;		//武将所属君主在君主链表中的索引
	int		xuetongsuoyin;		//武将血统将的索引
	short	jiecao;				//武将节操值
	short	unknow9;			//未知
	int		suoyinzhi[10];		//链表索引值，默认为FFFFFF
	int		nextindex;			//武将链表中下一个武将的索引
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




