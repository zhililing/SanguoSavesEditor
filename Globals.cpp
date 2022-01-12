#include "stdafx.h"
#include "Globals.h"

//#pragma pack(1)
//
//
////#pragma once
//


#include <map>
#include <iostream>
#include <fstream>
using namespace std; 



map<int, string> SGQY2_WUJIANGJI;
//	 = { {0x00, "无"},{0x01, "命疗术"}, {0x02, "落月弓"}, {0x03, "地泉"}, {0x04, "火箭"},
//{0x05, "伏兵组阵"}, {0x06, "木轮攻"}, {0x07, "虎咆"}, {0x08, "火雷"}, {0x09, "雷击"}, {0x0A, "炎龙"}, 
//{0x0B, "伏焰"}, {0x0C, "拒陆马"}, {0x0D, "御飞刀"}, {0x0E, "雷光波动"}, {0x0F, "火箭烈"}, {0x10, "虎咆震"}, 
//{0x11, "伏兵排阵"}, {0x12, "地泉裂劲"}, {0x13, "后伏连兵"}, {0x14, "木轮强袭"}, {0x15, "炎龙无双"}, {0x16, "雷光振杀"}, 
//{0x17, "虎咆阳炎"}, {0x18, "火雷爆"}, {0x19, "黄龙天翔"}, {0x1A, "地泉鲸浪"}, {0x1B, "绝命地"}, {0x1C, "雷击闪"}, 
//{0x1D, "炎龙杀阵"}, {0x1E, "火箭天袭"}, {0x1F, "后伏兵阵"}, {0x20, "火雷星雨"}, {0x21, "炎龙怒涛"}, {0x22, "赤焰洪流"}, 
//{0x23, "木轮涛击"}, {0x24, "赤焰火海"}, {0x25, "后伏军阵"},{0x26, "大地狂啸"}, {0x27, "雷光焦狱"}, {0x28, "十面埋伏"},
//{0x29, "炎龙电杀"}, {0x2A, "五雷轰顶"}, {0x2B, "狂雷天牢"},{0x2C, "天地无用"}, {0x2D, "飞矢"}, {0x2E, "连弩"},
//{0x2F, "突石"}, {0x30, "落石"}, {0x31, "刀剑乱"},{0x32, "半月斩"}, {0x33, "旋龙"}, {0x34, "落日弓"},
//{0x35, "八面火"}, {0x36, "旋灯火"},{0x37, "突石剑"},{0x38, "太极门"}, {0x39, "伏兵班阵"},{0x3A, "八门金锁"},
//{0x3B, "鬼戟"}, {0x3C, "回天术"},{0x3D, "地矛刺"},{0x3E, "连弩激射"}, {0x3F, "冰柱刺"},{0x40, "突剑四方"},
//{0x41, "冲车"}, {0x42, "神剑"},{0x43, "八面火转"},{0x44, "突袭石"}, {0x45, "龙炮"},{0x46, "火牛阵"},
//{0x47, "生死门"}, {0x48, "乱飞矢"},{0x49, "地茅乱刺"},{0x4A, "龙炮激射"}, {0x4B, "旋龙合壁"},{0x4C, "冰柱群锋"},
//{0x4D, "烈火旋灯"},{0x4E, "太极华阵"}, {0x4F, "滚石碾压"},{0x50, "八卦奇阵"},{0x51, "伏兵连阵"},{0x52, "驷冲车"},
//{0x53, "三日月斩"},{0x54, "神剑闪"},{0x55, "连弩狂涛"},{0x56, "乱刀狂舞"},{0x57, "飞矢烈震"},{0x58, "三圣华斩"},
//{0x59, "神火旋张"},{0x5A, "龙炮灭杀"},{0x5B, "炬石轰"},{0x5C, "火牛群舞"},{0x5D, "茅刺遍地"},{0x5E, "滚石怒冲"},
//{0x5F, "剑轮舞"},{0x60, "分身斩"},{0x61, "冰岚刀舞"},{0x62, "神剑闪华"},{0x63, "炎墙"},{0x64, "旋龙天舞"},{0x65, "地狱之门"},
//{0x66, "集火柱"},{0x67, "神火怒张"},{0x68, "神鬼乱舞"}, { 0x69, "炬石炼狱" }, { 0x6A, "炎墙烈烧" }, { 0x6B, "日月轮斩" }, 
//{0x6C, "火牛烈崩" }, { 0x6D, "五岳华斩" }, { 0x6E, "鬼哭神号" }
//
//};
map<int, string> SGQY2_JUNSHIJI;
//	 = {
//	{ 0x00, "无"},{0x01, "鼓舞士气（初）" }, { 0x02, "降敌士气（初）" }, { 0x03, "后选出阵（初）" }, { 0x04, "扰乱乱将（初）" }, { 0x05, "减少疲劳（初）" }, { 0x06, "离间计（初）" },{ 0x07, "减缓集气（初）" }, { 0x08, "保留气力（初）" },
//	{ 0x09, "快速集气（初）" }, { 0x0A, "诈败" }, { 0x0B, "恢复体力（初" }, { 0x0C, "恢复技力（初)" }, { 0x0D, "增加技力（初）" }, { 0x0E, "增加体力（初）" },{ 0x0F, "混乱敌军（初）" },
//	{ 0x10, "强化士兵（初）" }, { 0x11, "增强攻击（初）" }, { 0x12, "鼓舞士气（中）" }, { 0x13, "降敌士气（中）" }, { 0x14, "喝咀敌军（初）" }, { 0x15, "增加经验（初）" },{ 0x16, "强化武将（初）" }, { 0x17, "逼近敌军" },
//	{ 0x18, "化解计策 " }, { 0x19, "扰乱敌将（中）" }, { 0x1A, "包围敌军" }, { 0x1B, "减少疲劳（中）" }, { 0x1C, "乱阵" }, { 0x1D, "太公阵" },{ 0x1E, "偷袭敌军" },{ 0x1F, "保护主将" },
//	{ 0x20, "劝降" }, { 0x21, "金蝉脱壳" }, { 0x22, "离间计（中）" }, { 0x23, "减缓集气（中）" }, { 0x24, "保留集气（中）" }, { 0x25, "快速集气（中）" },{ 0x26, "鼓舞士气（高）" }, { 0x27, "降敌士气（高）" },
//	{ 0x28, "恢复体力（中）" }, { 0x29, "恢复技力（中）" }, { 0x2A, "增加技力（中)" }, { 0x2B, "增加体力（中）" }, { 0x2C, "混乱敌军（中）" }, { 0x2D, "强化士兵（中）" },{ 0x2E, "增强攻击（中）" },{ 0x2F, "增加经验（中）" },
//	{ 0x30, "喝咀敌军（中）" }, { 0x31, "强化武将（中）" }, { 0x32, "减少疲劳（高）" }, { 0x33, "扰乱敌将（高）" }, { 0x34, "快速集气（高）" }, { 0x35, "减缓集气（高）" },{ 0x36, "十面埋伏" }, { 0x37, " 离间计（高）" },
//	{ 0x38, "保留集气（高）" }, { 0x39, "恢复体力（高）" }, { 0x3A, "恢复技力（高）" }, { 0x3B, "封武将技" }, { 0x3C, "增加技力（高）" }, { 0x3D, "增加体力（高）" },{ 0x3E, "混乱敌军（高）" },{ 0x3F, "强化士兵（高）" },
//	{ 0x40, "增强攻击（高）" }, { 0x41, "增加经验（高）" }, { 0x42, "喝咀敌军（高）" }, { 0x43, "强化武将（高）" }
//};

map<int, string> SGQY2_BINGFU;
//	 = {
//	{ 0x01, "朴刀" }, { 0x02, "长枪" }, { 0x03, "大刀" }, { 0x04, "弓箭" }, { 0x05, "链锤" }, { 0x06, "飞刀" },{ 0x07, "武斗" }, { 0x08, "蛮族" },
//	{ 0x09, "铁槌" }, { 0x0A, "藤甲" }, { 0x0B, "黄巾" }, { 0x0C, "弩兵" }, { 0x0D, "女兵" }
//};


map<int, string> SGQY2_BINGSHU;
//; = {
//	{ 48, "孙子兵法" }, { 49, "兵书24篇" }, { 50, "孟得新书" }, { 51, "史记" }, { 52, "春秋左传" }, { 53, "遁甲天书" },{ 54, "青囊书" }, { 55, "太平要术 " }
//};


map<int, string> SGQY2_MALEI;
//	 = {
//	{ 56, "黄鬃马" }, { 57, "褐鬃马" }, { 58, "黑鬃马" }, { 59, "大宛马" }, { 60, "铁骑马" }, { 61, "的卢" },{ 62, "爪黄飞电" }, { 63, "赤兔马" }
//};


map<int, string> SGQY2_ZHENFA;
//= {
//	{ 64, "方形" }, { 65, "圆形" }, { 66, "锥形" }, { 67, "雁形" }, { 68, "玄襄" }, { 69, "鱼丽" },{ 70, "钩形" }, { 71, "冲锋" }, { 72, "箭矢 " }
//};

map<int, string> SGQY2_ZHUBAO;
//= {
//	{ 73, "珠宝" }, { 74, "黄金" }, { 75, "美女" }, { 76, "玉器" }, { 77, "布匹 " }
//};


map<int, string> SGQY2_BINGQI;
//= {
//
//	{14, "直剑" }, { 15, "短锥枪" }, { 16, "铜枪" }, { 17, "眉尖刀" }, { 18, "吴钩" }, { 19, "钩镰枪" }, { 20, "蛇矛" }, { 21, "凤嘴刀" },
//	{ 22, "马叉" }, { 23, "青铜剑" }, { 24, "大斧" }, { 25, "铜长刀" }, { 26, "流星锤" }, { 27, "无名" }, { 28, "铁钺戟" },
//	{ 29, "狼牙棒" }, { 30, "弧月刀" }, { 31, "月牙戟" }, { 32, "三尖刀" }, { 33, "两刃斧" }, { 34, "铁蒺藜骨朵" }, { 35, "双股剑" }, { 36, "龙渊剑" },
//	{ 37, "双铁戟 " }, { 38, "青杠剑" }, { 39, "古锭刀" }, { 40, "紫龙戟" }, { 41, "铁脊蛇矛" }, { 42, "七星剑" }, { 43, "青龙刀" }, { 44, "倚天剑" },
//	{ 45, "方天画戟" }, { 46, "丈八蛇矛" }, { 47, "青龙偃月刀 " }
//};
unsigned short BIG5_GB2312SANGUO[][3] =		//此列表为武将名中所有中文的BIG编码对应GB2312汉字
{
0xa442,'丁',0x4E01,		//第一列为big5编码，第二列为GB2312编码，第三列为Unicode编码
0xa448,'人',0x4EBA,
0xa454,'三',0x4E09,
0xa45f,'于',0x4E8E,
0xa461,'兀',0x5140,
0xa467,'土',0x571F,
0xa468,'士',0x58EB,
0xa46a,'大',0x5927,
0xa46c,'子',0x5B50,
0xa470,'小',0x5C0F,
0xa4a4,'中',0x4E2D,
0xa4a6,'丹',0x4E39,
0xa4af,'仁',0x4EC1,
0xa4b8,'元',0x5143,
0xa4b9,'允',0x5141,
0xa4bd,'公',0x516C,
0xa4c6,'化',0x5316,
0xa4cb,'卞',0x535E,
0xa4d2,'夫',0x592B,
0xa4d3,'太',0x592A,
0xa4d5,'孔',0x5B54,
0xa4da,'巴',0x5DF4,
0xa4e5,'文',0x6587,
0xa4eb,'月',0x6708,
0xa4ec,'木',0x6728,
0xa4f0,'毋',0x6BCB,
0xa4f1,'比',0x6BD4,
0xa4f2,'毛',0x6BDB,
0xa4fa,'牙',0x7259,
0xa4fb,'牛',0x725B,
0xa4fd,'王',0x738B,
0xa541,'丕',0x4E15,
0xa543,'丘',0x4E18,
0xa544,'主',0x4E3B,
0xa552,'充',0x5145,
0xa571,'司',0x53F8,
0xa576,'史',0x53F2,
0xa5aa,'左',0x5DE6,
0xa5ac,'布',0x5E03,
0xa5ad,'平',0x5E73,
0xa5b0,'弘',0x5F18,
0xa5bf,'正',0x6B63,
0xa5c8,'玄',0x7384,
0xa5cc,'甘',0x7518,
0xa5d0,'田',0x7530,
0xa5d3,'申',0x7533,
0xa5d5,'白',0x767D,
0xa5e8,'亥',0x4EA5,
0xa5ec,'伊',0x4F0A,
0xa5f0,'休',0x4F11,
0xa5f4,'任',0x4EFB,
0xa5fe,'全',0x5168,
0xa64e,'吉',0x5409,
0xa656,'向',0x5411,
0xa658,'合',0x5408,
0xa677,'安',0x5B89,
0xa6a1,'式',0x5F0F,
0xa6a3,'忙',0x5FD9,
0xa6a8,'成',0x6210,
0xa6b6,'朱',0x6731,
0xa6b7,'朵',0x6735,
0xa6cf,'羊',0x7F8A,
0xa6d0,'羽',0x7FBD,
0xa6e3,'艾',0x827E,
0xa6e6,'行',0x884C,
0xa6ef,'佗',0x4F57,
0xa6f3,'何',0x4F55,
0xa764,'吴',0x5434,
0xa766,'吕',0x5415,
0xa7a1,'均',0x5747,
0xa7b7,'孚',0x5B5A,
0xa7ba,'宋',0x5B8B,
0xa7cd,'彤',0x5F64,
0xa7d3,'志',0x5FD7,
0xa7dc,'抗',0x6297,
0xa7f1,'攸',0x6538,
0xa7f5,'李',0x674E,
0xa7f9,'杜',0x675C,
0xa842,'步',0x6B65,
0xa846,'沙',0x6C99,
0xa84b,'沛',0x6C9B,
0xa86a,'甫',0x752B,
0xa87d,'良',0x826F,
0xa8a4,'角',0x89D2,
0xa8ae,'车',0x8F66,
0xa8af,'辛',0x8F9B,
0xa8b7,'邢',0x90A2,
0xa8ba,'那',0x90A3,
0xa8bd,'里',0x91CC,
0xa8d3,'来',0x6765,
0xa8e0,'儿',0x513F,
0xa8e5,'典',0x5178,
0xa8f4,'卓',0x5353,
0xa94d,'和',0x548C,
0xa950,'周',0x5468,
0xa95e,'奉',0x5949,
0xa973,'孟',0x5B5F,
0xa977,'定',0x5B9A,
0xa97c,'尚',0x5C1A,
0xa9a6,'岫',0x5CAB,
0xa9a7,'岱',0x5CB1,
0xa9b5,'延',0x5EF6,
0xa9be,'忠',0x5FE0,
0xa9ca,'性',0x6027,
0xa9d3,'承',0x627F,
0xa9f9,'昂',0x6602,
0xa9fd,'昕',0x6615,
0xaa41,'服',0x670D,
0xaa51,'松',0x677E,
0xaa5a,'武',0x6B66,
0xaa6b,'法',0x6CD5,
0xaa71,'沮',0x6CAE,
0xaa76,'治',0x6CBB,
0xaaa2,'炎',0x708E,
0xaab1,'玩',0x73A9,
0xaac3,'秉',0x79C9,
0xaac7,'竺',0x7AFA,
0xaada,'芳',0x82B3,
0xaadb,'芝',0x829D,
0xaaea,'虎',0x864E,
0xaaed,'表',0x8868,
0xaaf7,'金',0x91D1,
0xaaf8,'长',0x957F,
0xaafc,'阿',0x963F,
0xab47,'亮',0x4EAE,
0xab4a,'侯',0x4FAF,
0xabb3,'奕',0x5955,
0xabc2,'威',0x5A01,
0xabca,'封',0x5C01,
0xabd7,'度',0x5EA6,
0xabe4,'思',0x601D,
0xabec,'恢',0x6062,
0xabf1,'恪',0x606A,
0xac46,'政',0x653F,
0xac4c,'昭',0x662D,
0xac52,'昱',0x6631,
0xac73,'毗',0x6BD7,
0xac78,'洪',0x6D2A,
0xac7d,'洞',0x6D1E,
0xacd3,'皇',0x7687,
0xacee,'秋',0x79CB,
0xacf0,'突',0x7A81,
0xacf6,'纪',0x7EAA,
0xad48,'胄',0x80C4,
0xad4a,'胡',0x80E1,
0xad4e,'胤',0x80E4,
0xad5a,'茂',0x8302,
0xad5e,'英',0x82F1,
0xad63,'苞',0x82DE,
0xadb3,'韦',0x97E6,
0xadb8,'飞',0x98DE,
0xadbb,'香',0x9999,
0xadd7,'修',0x4FEE,
0xaddc,'仓',0x4ED3,
0xadec,'原',0x539F,
0xae45,'圃',0x5703,
0xae4c,'夏',0x590F,
0xae5d,'孙',0x5B59,
0xae63,'宫',0x5BAB,
0xae6d,'峻',0x5CFB,
0xae76,'师',0x5E08,
0xae7d,'徐',0x5F90,
0xaea5,'恭',0x606D,
0xaea6,'恩',0x6069,
0xaecc,'晃',0x6643,
0xaed4,'朗',0x6717,
0xaed9,'桓',0x6853,
0xaef5,'泰',0x6CF0,
0xaf43,'浚',0x6D5A,
0xaf45,'浩',0x6D69,
0xaf5a,'班',0x73ED,
0xaf75,'真',0x771F,
0xafaa,'祖',0x7956,
0xafac,'祝',0x795D,
0xafae,'祚',0x795A,
0xafb3,'秦',0x79E6,
0xafc1,'索',0x7D22,
0xafc2,'纯',0x7EAF,
0xafd4,'耽',0x803D,
0xafd5,'耿',0x803F,
0xafe0,'能',0x80FD,
0xaffb,'荀',0x8340,
0xb040,'虔',0x8654,
0xb04b,'袁',0x8881,
0xb05c,'豹',0x8C79,
0xb067,'迷',0x8FF7,
0xb06f,'邕',0x9095,
0xb071,'郝',0x90DD,
0xb074,'配',0x914D,
0xb0a8,'马',0x9A6C,
0xb0a9,'骨',0x9AA8,
0xb0aa,'高',0x9AD8,
0xb0ae,'干',0x5E72,
0xb0ea,'国',0x56FD,
0xb0ed,'坚',0x575A,
0xb0f2,'基',0x57FA,
0xb14e,'将',0x5C06,
0xb161,'带',0x5E26,
0xb164,'康',0x5EB7,
0xb166,'庶',0x5EB6,
0xb169,'张',0x5F20,
0xb1ac,'惇',0x60C7,
0xb1c2,'授',0x6388,
0xb1db,'旋',0x65CB,
0xb1e4,'曹',0x66F9,
0xb1e7,'梁',0x6881,
0xb245,'淳',0x6DF3,
0xb257,'渊',0x6E0A,
0xb26a,'焉',0x7109,
0xb26e,'爽',0x723D,
0xb2a7,'异',0x5F02,
0xb2b1,'盛',0x76DB,
0xb2c8,'笮',0x7B2E,
0xb2ce,'统',0x7EDF,
0xb2d0,'绍',0x7ECD,
0xb2d6,'累',0x7D2F,
0xb2df,'习',0x4E60,
0xb2fe,'荼',0x837C,
0xb343,'彪',0x5F6A,
0xb34e,'术',0x672F,
0xb35c,'许',0x8BB8,
0xb37b,'逢',0x9022,
0xb3a2,'郭',0x90ED,
0xb3a3,'都',0x90FD,
0xb3af,'陈',0x9648,
0xb3b0,'陆',0x9646,
0xb3b3,'陶',0x9676,
0xb3c0,'鹿',0x9E7F,
0xb3c5,'傅',0x5085,
0xb3c6,'备',0x5907,
0xb3cd,'凯',0x51EF,
0xb3df,'喜',0x559C,
0xb3e4,'喃',0x5583,
0xb3ec,'乔',0x4E54,
0xb453,'巽',0x5DFD,
0xb460,'循',0x5FAA,
0xb4b6,'普',0x666E,
0xb4ba,'景',0x666F,
0xb4d3,'植',0x690D,
0xb4dc,'钦',0x94A6,
0xb4eb,'渠',0x6E20,
0xb4fd,'浑',0x6D51,
0xb54d,'然',0x7136,
0xb559,'琳',0x7433,
0xb561,'琦',0x7426,
0xb56e,'登',0x767B,
0xb571,'皓',0x7693,
0xb573,'盗',0x76D7,
0xb57b,'程',0x7A0B,
0xb5a6,'策',0x7B56,
0xb5b2,'结',0x7ED3,
0xb5be,'翔',0x7FD4,
0xb5c2,'肃',0x8083,
0xb5d8,'华',0x534E,
0xb5fb,'评',0x8BC4,
0xb646,'诃',0x8BC3,
0xb649,'貂',0x8C82,
0xb64f,'费',0x8D39,
0xb656,'越',0x8D8A,
0xb657,'超',0x8D85,
0xb661,'轲',0x8F72,
0xb666,'逵',0x9035,
0xb669,'进',0x8FDB,
0xb6a9,'隆',0x9686,
0xb6ae,'雅',0x96C5,
0xb6af,'雄',0x96C4,
0xb6b3,'云',0x4E91,
0xb6b6,'顺',0x987A,
0xb6be,'冯',0x51AF,
0xb6c0,'黄',0x9EC4,
0xb743,'嵩',0x5D69,
0xb74f,'慈',0x6148,
0xb77c,'会',0x4F1A,
0xb7a8,'杨',0x6768,
0xb7c5,'温',0x6E29,
0xb7e8,'瑁',0x7441,
0xb7ec,'瑜',0x745C,
0xb7ed,'当',0x5F53,
0xb854,'禁',0x7981,
0xb859,'稠',0x7A20,
0xb871,'义',0x4E49,
0xb873,'群',0x7FA4,
0xb875,'聘',0x8058,
0xb8af,'葛',0x845B,
0xb8b3,'董',0x8463,
0xb8b7,'虞',0x865E,
0xb8e9,'贼',0x8D3C,
0xb8eb,'贾',0x8D3E,
0xb940,'辟',0x8F9F,
0xb944,'道',0x9053,
0xb945,'遂',0x9042,
0xb946,'达',0x8FBE,
0xb951,'邹',0x90B9,
0xb96c,'雍',0x96CD,
0xb96d,'隽',0x96BD,
0xb970,'雷',0x96F7,
0xb974,'靖',0x9756,
0xb977,'预',0x9884,
0xb9c5,'嘉',0x5609,
0xb9cf,'图',0x56FE,
0xb9e7,'宁',0x5B81,
0xb9f9,'廖',0x5ED6,
0xb9fc,'彰',0x5F70,
0xb9fd,'彻',0x5F7B,
0xba61,'荣',0x8363,
0xbaa1,'满',0x6EE1,
0xbab3,'熙',0x7199,
0xbadd,'端',0x7AEF,
0xbade,'管',0x7BA1,
0xbaee,'综',0x7EFC,
0xbaf5,'纲',0x7EB2,
0xbb4e,'臧',0x81E7,
0xbb58,'蒙',0x8499,
0xbb5c,'盖',0x76D6,
0xbb70,'裴',0x88F4,
0xbb75,'褚',0x891A,
0xbbaf,'赵',0x8D75,
0xbbb7,'远',0x8FDC,
0xbbb9,'逊',0x900A,
0xbbc8,'银',0x94F6,
0xbbc9,'铜',0x94DC,
0xbbe0,'韶',0x97F6,
0xbbf1,'凤',0x51E4,
0xbbf6,'仪',0x4EEA,
0xbbfc,'俭',0x4FED,
0xbc42,'刘',0x5218,
0xbc66,'审',0x5BA1,
0xbc73,'广',0x5E7F,
0xbc77,'德',0x5FB7,
0xbcaf,'摩',0x6469,
0xbcd4,'樊',0x6A0A,
0xbcd6,'乐',0x4E50,
0xbcef,'潘',0x6F58,
0xbcfd,'璋',0x748B,
0xbd40,'瑾',0x747E,
0xbd64,'范',0x8303,
0xbdb1,'蒋',0x848B,
0xbdb2,'蔡',0x8521,
0xbdc3,'卫',0x536B,
0xbdcf,'诞',0x8BDE,
0xbdd1,'诸',0x8BF8,
0xbde5,'贤',0x8D24,
0xbde8,'质',0x8D28,
0xbe48,'邓',0x9093,
0xbe57,'锋',0x950B,
0xbe5f,'震',0x9707,
0xbe7c,'鲁',0x9C81,
0xbea7,'儒',0x5112,
0xbeb1,'勋',0x52CB,
0xbecb,'宪',0x5BAA,
0xbede,'操',0x64CD,
0xbee6,'暹',0x66B9,
0xbee7,'晔',0x6654,
0xbeee,'横',0x6A2A,
0xbf41,'泽',0x6CFD,
0xbf50,'燕',0x71D5,
0xbf63,'卢',0x5362,
0xbfaa,'羲',0x7FB2,
0xbfb3,'兴',0x5174,
0xbfc4,'融',0x878D,
0xbfc5,'衡',0x8861,
0xbff1,'辽',0x8FBD,
0xc046,'阎',0x960E,
0xc04e,'霍',0x970D,
0xc052,'静',0x9759,
0xc064,'骆',0x9A86,
0xc06a,'鲍',0x9C8D,
0xc06d,'鸯',0x9E2F,
0xc075,'优',0x4F18,
0xc0a6,'婴',0x5A74,
0xc0b2,'徽',0x5FBD,
0xc0d9,'济',0x6D4E,
0xc0f2,'获',0x83B7,
0xc0f4,'环',0x73AF,
0xc142,'矫',0x77EB,
0xc149,'禅',0x7985,
0xc153,'糜',0x7CDC,
0xc15a,'绩',0x7EE9,
0xc16c,'翼',0x7FFC,
0xc174,'膺',0x81BA,
0xc1a1,'薄',0x8584,
0xc1a7,'薛',0x859B,
0xc1be,'谦',0x8C26,
0xc1d6,'舆',0x8206,
0xc1e0,'丑',0x4E11,
0xc1e9,'钟',0x949F,
0xc1fa,'韩',0x97E9,
0xc2a4,'瞻',0x77BB,
0xc2a7,'礼',0x793C,
0xc2b2,'简',0x7B80,
0xc2b8,'绣',0x7EE3,
0xc2bd,'翻',0x7FFB,
0xc2cd,'蝉',0x8749,
0xc2d7,'丰',0x4E30,
0xc2e4,'邈',0x9088,
0xc2f9,'双',0x53CC,
0xc343,'颜',0x989C,
0xc34c,'馥',0x99A5,
0xc351,'魏',0x9B4F,
0xc35b,'鹄',0x9E44,
0xc364,'宠',0x5BA0,
0xc365,'庞',0x5E9E,
0xc368,'怀',0x6000,
0xc36d,'旷',0x65F7,
0xc3a3,'琼',0x743C,
0xc3a5,'畴',0x7574,
0xc3a6,'疆',0x7586,
0xc3d3,'谭',0x8C2D,
0xc3d7,'谯',0x8C2F,
0xc3f6,'关',0x5173,
0xc450,'鹏',0x9E4F,
0xc459,'严',0x4E25,
0xc45f,'宝',0x5B9D,
0xc479,'籍',0x7C4D,
0xc4ac,'苏',0x82CF,
0xc4cb,'腾',0x817E,
0xc4f2,'续',0x7EED,
0xc4f5,'兰',0x5170,
0xc4fd,'览',0x89C8,
0xc54b,'铁',0x94C1,
0xc551,'霸',0x9738,
0xc555,'顾',0x987E,
0xc574,'懿',0x61FF,
0xc576,'权',0x6743,
0xc5a7,'袭',0x88AD,
0xc5c7,'龚',0x9F9A,
0xc5d0,'瓒',0x74D2,
0xc646,'灵',0x7075,
0xc64f,'鹭',0x9E6D,
0xc9fa,'汜',0x6C5C,
0xcc57,'宓',0x5B93,
0xccc9,'旻',0x65FB,
0xcd6b,'玠',0x73A0,
0xd17b,'彧',0x5F67,
0xd2e9,'祜',0x795C,
0xd354,'纮',0x7EAE,
0xd5e6,'凌',0x51CC,
0xd6f6,'翊',0x7FCA,
0xd852,'傕',0x5095,
0xda7a,'琮',0x742E,
0xda7b,'琬',0x742C,
0xda7c,'琰',0x7430,
0xdaad,'畯',0x756F,
0xdcc2,'佥',0x4F65,
0xddd5,'楙',0x6959,
0xddf5,'歆',0x6B46,
0xdf54,'粲',0x7CB2,
0xe048,'诩',0x8BE9,
0xe078,'辂',0x8F82,
0xe0e0,'颀',0x9880,
0xe3c7,'蒯',0x84AF,
0xe7c7,'袆',0x8886,
0xe8b0,'靓',0x9753,
0xe8db,'鲂',0x9C82,
0xe8fb,'叡',0x53E1,
0xecda,'嶷',0x5DB7,
0xedd9,'繇',0x7E47,
0xeea2,'谡',0x8C21,
0xf16d,'闿',0x95FF,
0xf2a5,'祢',0x7962,
0xf545,'阚',0x961A

};

WuJiang* pWuJiang;
FileHeader* pFileHeader;
King* pKing;
int		nCurrentWuJiangID(0);
FILE* fp;
int nFileSize;
byte FileContent[300000];
unsigned int		nNextWuJiangPosition;
//Wujiangliebiao
FILE* fpnamelist;
char Wujiangliebiao[60];	//导出武将姓名列表文件行数据
TCHAR wujiangnamegb2312char[6]; //GB2312武将名
TCHAR wujiangnamebig5char[6]; //Big5武将名
TCHAR wujiangnameunicodechar[6]; //Unicode武将名

int UnicodeBinarySearch(unsigned short key, const unsigned short lookup_table[][3], unsigned int start, unsigned int end)
{
	// printf("start=%d,end=%d\n",start,end);   
	unsigned short code;
	if (key == 0)
		return -1;
	while (start <= end)
	{
		unsigned int mid = (start + end) / 2;

		code = lookup_table[mid][0];

		if (key > code)
		{
			start = mid + 1;
		}
		else if (key < code)
		{
			end = mid - 1;
		}
		else //found	   
		{
			return mid;
		}
	}   return -1;
}

unsigned short GetGB2312ByBIG5(unsigned short big5)
{
	int big5unicodelen = 0;
	//big5unicodelen = sizeof(BIG5_Unicode)/sizeof(unsigned int)/2;
	big5unicodelen = sizeof(BIG5_GB2312SANGUO) / sizeof(unsigned short) / 3;
	int index = UnicodeBinarySearch(big5, BIG5_GB2312SANGUO, 0, big5unicodelen - 1);
	if (index != -1)
	{
		//return BIG5_Unicode[index][1]; 
		return BIG5_GB2312SANGUO[index][1];
	}
	return 0xFFFF;
}

unsigned short GetUnicodeByBIG5(unsigned short big5)
{
	int big5unicodelen = 0;
	//big5unicodelen = sizeof(BIG5_Unicode)/sizeof(unsigned int)/2;
	big5unicodelen = sizeof(BIG5_GB2312SANGUO) / sizeof(unsigned short) / 3;
	int index = UnicodeBinarySearch(big5, BIG5_GB2312SANGUO, 0, big5unicodelen - 1);
	if (index != -1)
	{
		//return BIG5_Unicode[index][1]; 
		return BIG5_GB2312SANGUO[index][2];
	}
	return 0xFFFF;
}

void __fastcall BIG52GBK(char* szBuf);

void TranslateNameToGB2312Unicode(void)
{
	memset(wujiangnameunicodechar, 0, sizeof(wujiangnameunicodechar));
	memset(wujiangnamegb2312char, 0, sizeof(wujiangnamegb2312char));

	for (int j = 0; j < 6; j++) {
		if (wujiangnamebig5char[j] == 0) break;
		TCHAR tmpchar = wujiangnamebig5char[j] >> 8;
		wujiangnamebig5char[j] = (wujiangnamebig5char[j] << 8) | tmpchar;
		wujiangnameunicodechar[j] = GetUnicodeByBIG5(wujiangnamebig5char[j]);
		//wujiangnameunicodechar[j] = BIG52GBK((char*)wujiangnamebig5char[j]);
		wujiangnamegb2312char[j] = GetGB2312ByBIG5(wujiangnamebig5char[j]);
		if (0xFFFF != wujiangnameunicodechar[j]) {				//只判断了一种，应该2种都判断
			tmpchar = wujiangnamegb2312char[j] >> 8;
			wujiangnamegb2312char[j] = (wujiangnamegb2312char[j] << 8) | tmpchar;	//gb2312需要交换高低字节
		}
		else {
			wujiangnameunicodechar[j] = 0x00;
			wujiangnamegb2312char[j] = 0x00;
		}
	}

}
//---------------------------------------------------------------------------
// 大五码转GBK码：
// い地チ㎝瓣 --> 中華人民共和國
void __fastcall BIG52GBK(char* szBuf)
{
	if (!strcmp(szBuf, ""))
		return;
	int nStrLen = strlen(szBuf);
	wchar_t* pws = new wchar_t[nStrLen + 1];
	try
	{
		int nReturn = MultiByteToWideChar(950, 0, szBuf, nStrLen, pws, nStrLen + 1);
		BOOL bValue = false;
		nReturn = WideCharToMultiByte(936, 0, pws, nReturn, szBuf, nStrLen + 1, "?", &bValue);
		szBuf[nReturn] = 0;
	}
	//__finally
	catch (...)
	{
		delete[] pws;
	}
}
//---------------------------------------------------------------------------
// GBK转大五码
// 中華人民共和國 --> い地チ㎝瓣
void __fastcall GBK2BIG5(char* szBuf)
{
	if (!strcmp(szBuf, ""))
		return;
	int nStrLen = strlen(szBuf);
	wchar_t* pws = new wchar_t[nStrLen + 1];
	try
	{
		MultiByteToWideChar(936, 0, szBuf, nStrLen, pws, nStrLen + 1);
		BOOL bValue = false;
		WideCharToMultiByte(950, 0, pws, nStrLen, szBuf, nStrLen + 1, "?", &bValue);
		szBuf[nStrLen] = 0;
	}
	//__finally
	catch (...)
	{
		delete[] pws;
	}
}
//----------------------------------------------------------------------------
// 抱歉，这个提示又来了，为了防止不负责任的转载者，只好在此留些信息。
// 作者：ccrun(老妖) info@ccrun.com
// 本文转自 C++Builder 研究 - http://www.ccrun.com/article/go.asp?i=634&d=04g63p
//---------------------------------------------------------------------------
// GB2312码转GBK码
// 本文转自 C++Builder研究 - http://www.ccrun.com/article.asp?i=634&d=04g63p
// 中华人民共和国 --> 中華人民共和國
void __fastcall GB2GBK(char* szBuf)
{
	if (!strcmp(szBuf, ""))
		return;
	int nStrLen = strlen(szBuf);
	WORD wLCID = MAKELCID(MAKELANGID
	(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_CHINESE_PRC);
	int nReturn = LCMapString(wLCID, LCMAP_TRADITIONAL_CHINESE, (TCHAR*)szBuf, nStrLen, NULL, 0);
	if (!nReturn)
		return;
	char* pcBuf = new char[nReturn + 1];
	try
	{
		wLCID = MAKELCID(MAKELANGID
		(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_CHINESE_PRC);
		LCMapString(wLCID, LCMAP_TRADITIONAL_CHINESE, (TCHAR*)szBuf, nReturn, (TCHAR*)pcBuf, nReturn + 1);
		strncpy(szBuf, pcBuf, nReturn);
	}
	//__finally
	catch (...)
	{
		delete[] pcBuf;
	}
}
//---------------------------------------------------------------------------
// GBK码转GB2312码
// 中華人民共和國 --> 中华人民共和国
void __fastcall GBK2GB(char* szBuf)
{
	if (!strcmp(szBuf, ""))
		return;
	int nStrLen = strlen(szBuf);
	WORD wLCID = MAKELCID(MAKELANGID
	(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_CHINESE_BIG5);
	int nReturn = LCMapString(wLCID, LCMAP_SIMPLIFIED_CHINESE, (TCHAR*)szBuf, nStrLen, NULL, 0);
	if (!nReturn)
		return;
	char* pcBuf = new char[nReturn + 1];
	try
	{
		wLCID = MAKELCID(MAKELANGID
		(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_CHINESE_BIG5);
		LCMapString(wLCID, LCMAP_SIMPLIFIED_CHINESE, (TCHAR*)szBuf, nReturn, (TCHAR*)pcBuf, nReturn + 1);
		strncpy(szBuf, pcBuf, nReturn);
	}
	//__finally
	catch (...)
	{
		delete[]pcBuf;
	}
}
//---------------------------------------------------------------------------
// 测试代码
//void __fastcall TForm1::Button1Click(TObject* Sender)
//{
//	char szBuf[255];
//	// 从GB2312转到GBK
//	strcpy(szBuf, Edit1->Text.c_str());
//	GB2GBK(szBuf);
//	Edit2->Text = String(szBuf);
//	// 从GB2312转到BIG5，通过GBK中转
//	strcpy(szBuf, Edit1->Text.c_str());
//	GB2GBK(szBuf);
//	GBK2BIG5(szBuf);
//	Edit3->Text = String(szBuf);
//}

//GB2312 转换成 Unicode：
wchar_t* GB2312ToUnicode(const TCHAR* szGBString)
{
	UINT nCodePage = 936; //GB2312
	int nLength = MultiByteToWideChar(nCodePage, 0, (const char*)szGBString, -1, NULL, 0);
	TCHAR* pBuffer = new TCHAR[nLength + 1];
	MultiByteToWideChar(nCodePage, 0, (const char*)szGBString, -1, pBuffer, nLength);
	pBuffer[nLength] = 0;
	return pBuffer;
}
//BIG5 转换成 Unicode：
TCHAR* BIG5ToUnicode(const TCHAR* szBIG5String)
{
	UINT nCodePage = 950; //BIG5
	int nLength = MultiByteToWideChar(nCodePage, 0, (const char*)szBIG5String, -1, NULL, 0);
	TCHAR* pBuffer = new TCHAR[nLength + 1];
	MultiByteToWideChar(nCodePage, 0, (const char*)szBIG5String, -1, pBuffer, nLength);
	pBuffer[nLength] = 0;
	return pBuffer;
}
//Unicode 转换成 GB2312：
TCHAR* UnicodeToGB2312(const TCHAR* szUnicodeString)
{
	UINT nCodePage = 936; //GB2312
	int nLength = WideCharToMultiByte(nCodePage, 0, szUnicodeString, -1, NULL, 0, NULL, NULL);
	TCHAR* pBuffer = new TCHAR[nLength + 1];
	WideCharToMultiByte(nCodePage, 0, szUnicodeString, -1, (char*)pBuffer, nLength, NULL, NULL);
	pBuffer[nLength] = 0;
	return pBuffer;
}
//Unicode 转换成 BIG5：
TCHAR* UnicodeToBIG5(const TCHAR* szUnicodeString)
{
	UINT nCodePage = 950; //BIG5
	int nLength = WideCharToMultiByte(nCodePage, 0, szUnicodeString, -1, NULL, 0, NULL, NULL);
	TCHAR* pBuffer = new TCHAR[nLength + 1];
	WideCharToMultiByte(nCodePage, 0, szUnicodeString, -1, (char*)pBuffer, nLength, NULL, NULL);
	pBuffer[nLength] = 0;
	return pBuffer;
}
////繁体中文BIG5 转换成 简体中文 GB2312
//wchar_t* BIG5ToGB2312(const TCHAR* szBIG5String)
//{
//	LCID lcid = MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_CHINESE_PRC);
//	TCHAR* szUnicodeBuff = BIG5ToUnicode(szBIG5String);
//	TCHAR* szGB2312Buff = UnicodeToGB2312(szUnicodeBuff);
//	int nLength = LCMapString(lcid, LCMAP_SIMPLIFIED_CHINESE, szGB2312Buff, -1, NULL, 0);
//	TCHAR* pBuffer = new TCHAR[nLength + 1];
//	LCMapString(0x0804, LCMAP_SIMPLIFIED_CHINESE, szGB2312Buff, -1, pBuffer, nLength);
//	pBuffer[nLength] = 0;
//
//	delete[] szUnicodeBuff;
//	delete[] szGB2312Buff;
//	return pBuffer;
//}
////简体中文 GB2312 转换成 繁体中文BIG5
//wchar_t* GB2312ToBIG5(const TCHAR* szGBString)
//{
//	LCID lcid = MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_CHINESE_PRC);
//	int nLength = LCMapString(lcid, LCMAP_TRADITIONAL_CHINESE, szGBString, -1, NULL, 0);
//	TCHAR* pBuffer = new TCHAR[nLength + 1];
//	LCMapString(lcid, LCMAP_TRADITIONAL_CHINESE, szGBString, -1, pBuffer, nLength);
//	pBuffer[nLength] = 0;
//	TCHAR* pUnicodeBuff = GB2312ToUnicode(pBuffer);
//	TCHAR* pBIG5Buff = UnicodeToBIG5(pUnicodeBuff);
//	delete[] pBuffer;
//	delete[] pUnicodeBuff;
//	return pBIG5Buff;
//}

////繁体中文BIG5 转换成 简体中文 GB2312   
//TCHAR* BIG5ToGB2312(const TCHAR* szBIG5String) {
//	LCID lcid = MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_CHINESE_PRC);
//	int nLength = LCMapStringA(lcid, LCMAP_SIMPLIFIED_CHINESE, (LPCSTR)szBIG5String, -1, NULL, 0);
//	TCHAR* pBuffer = new TCHAR[nLength + 1];
//	memset(pBuffer, 0, nLength + 1);
//	LCMapStringA(lcid, LCMAP_SIMPLIFIED_CHINESE, (LPCSTR)szBIG5String, -1, (LPSTR)pBuffer, nLength);
//	return pBuffer;
//}
//
//
////简体中文 GB2312 转换成 繁体中文BIG5  
//TCHAR* GB2312ToBIG5(const TCHAR* szGBString)
//{
//	LCID lcid = MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_CHINESE_PRC);
//	int nLength = LCMapStringA(lcid, LCMAP_TRADITIONAL_CHINESE, (LPCSTR)szGBString, -1, NULL, 0);
//	TCHAR* pBuffer = new TCHAR[nLength + 1];
//	memset(pBuffer, 0, nLength + 1);
//	LCMapStringA(lcid, LCMAP_TRADITIONAL_CHINESE, (LPCSTR)szGBString, -1, (LPSTR)pBuffer, nLength);
//	return pBuffer;
//}

bool IniWuJiangJi()
{
	USES_CONVERSION;
	CStdioFile file;

	TCHAR cPath[MAX_PATH];
	GetModuleFileName(NULL, cPath, MAX_PATH);

	int ss = CString(cPath).ReverseFind((TCHAR)'\\');
	CString strFileName = CString(cPath).Left(ss) + "\\SYS\\AttackSkill.TXT";

	//if (!file.Open(strFileName, CFile::modeRead))
	//{
	//	return FALSE;
	//}
	
	//CString strValue = _T("");
	int i = 0;

	ifstream ifs(strFileName);

	string str;
	while (getline(ifs, str))
	{
		SGQY2_WUJIANGJI.insert(make_pair(i++, str));
	}


	//while (file.ReadString(strValue))
	//{
	//	SGQY2_WUJIANGJI.insert(make_pair(i++, W2A(strValue)));
	//}
	//file.Close();
	ifs.close();
	return true;
}
bool IniJunShiJi()
{
	USES_CONVERSION;
	CStdioFile file;
	TCHAR cPath[MAX_PATH];
	GetModuleFileName(NULL, cPath, MAX_PATH);
	int ss = CString(cPath).ReverseFind((TCHAR)'\\');
	CString strFileName = CString(cPath).Left(ss) + "\\SYS\\StrategicSkill.TXT";;
	//if (!file.Open(strFileName, CFile::modeRead))
	//{
	//	return FALSE;
	//}

	//CString strValue = _T("");
	int i = 0;

	ifstream ifs(strFileName);

	string str;
	while (getline(ifs, str))
	{
		SGQY2_JUNSHIJI.insert(make_pair(i++, str));
	}

	//while (file.ReadString(strValue))
	//{
	//	SGQY2_JUNSHIJI.insert(make_pair(i++, W2A(strValue)));
	//}
	//file.Close();
	ifs.close();
	return true;
}

int CharToUnicode(char* pchIn, CString* pstrOut)

{
	int nLen;

	WCHAR* ptch;

	if (pchIn == NULL)

	{
		return 0;

	}

	nLen = MultiByteToWideChar(CP_ACP, 0, pchIn, -1, NULL, 0);

	ptch = new WCHAR[nLen];

	MultiByteToWideChar(CP_ACP, 0, pchIn, -1, ptch, nLen);

	pstrOut->Format(_T("%s"), ptch);



	delete[] ptch;

	return nLen;

}

//int UnicodeToChar(CString& strIn, char* pchOut, int nCharLen)
//
//{
//	if (pchOut == NULL)
//
//	{
//		return 0;
//
//	}
//
//	int nLen = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)strIn.GetBuffer(BUFFER_SIZE_KILO), -1, NULL, 0, NULL, NULL);
//
//	nLen = min(nLen, nCharLen);
//
//	WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)strIn.GetBuffer(BUFFER_SIZE_KILO), -1, pchOut,
//
//		nLen, NULL, NULL);
//
//
//
//	if (nLen < nCharLen)
//
//	{
//		pchOut[nLen] = 0;
//
//	}
//
//	return nLen;
//
//}





