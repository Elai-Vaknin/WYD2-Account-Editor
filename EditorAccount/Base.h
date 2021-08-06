#pragma once

#include <iostream>

string		imagesPath = "images/";

#define		ACCOUNTNAME_LENGTH		16
#define		ACCOUNTPASS_LENGTH		12 
#define		REALNAME_LENGTH			24 
#define		EMAIL_LENGTH			48 
#define		ADDRESS_LENGTH			78 
#define		TELEPHONE_LENGTH		16 
#define		MOB_PER_ACCOUNT			4  
#define		MAX_EQUIP				16
#define		MAX_CARRY				64
#define		MAX_CARGO				128
#define		NAME_LENGTH				16
#define		MAX_AFFECT				32

enum {
	TK = 0,
	FM,
	BM,
	HT,
	CLASSES
};

char Classes[CLASSES][16] = {
	"TransKnight",
	"Foema",
	"BeastMaster",
	"Hunter"
};

struct STRUCT_ITEM
{
	short sIndex;
	union
	{
		short sValue;

		struct
		{
			unsigned char cEffect;
			unsigned char cValue;
		};

	}stEffect[3];
};

struct STRUCT_AFFECT
{
	unsigned char Type;
	unsigned char Value;
	unsigned short Level;
	unsigned int Time;
};

struct STRUCT_SCORE
{
	int Level;
	int Ac;
	int Damage;

	unsigned char  Merchant;
	unsigned char  AttackRun;
	unsigned char  Direction;
	unsigned char  ChaosRate;

	int MaxHp;
	int MaxMp;
	int Hp;
	int Mp;

	short	Str;
	short	Int;
	short	Dex;
	short	Con;

	short  Special[4];
};

struct STRUCT_ACCOUNTINFO
{
	char AccountName[ACCOUNTNAME_LENGTH];
	char AccountPass[ACCOUNTPASS_LENGTH];

	char RealName[REALNAME_LENGTH];
	int  SSN1;
	int  SSN2;
	char Email[EMAIL_LENGTH];
	char Telephone[TELEPHONE_LENGTH];
	char Address[ADDRESS_LENGTH];
	char NumericToken[6];

	int Year;
	int YearDay;
};

struct STRUCT_MOB
{
	char		   MobName[NAME_LENGTH];
	char		   Clan;
	unsigned char  Merchant;
	unsigned short Guild;
	unsigned char  Class;
	unsigned short  Rsv;
	unsigned char Quest;

	int			   Coin;

	long long   Exp;

	short		   SPX;
	short		   SPY;

	STRUCT_SCORE   BaseScore;
	STRUCT_SCORE   CurrentScore;

	STRUCT_ITEM    Equip[MAX_EQUIP];
	STRUCT_ITEM	   Carry[MAX_CARRY];

	long LearnedSkill;

	unsigned int Magic;

	unsigned short ScoreBonus;
	unsigned short SpecialBonus;
	unsigned short SkillBonus;

	unsigned char  Critical;
	unsigned char  SaveMana;

	unsigned char  SkillBar[4];

	unsigned char  GuildLevel;

	unsigned short  RegenHP;
	unsigned short  RegenMP;

	char  Resist[4];
};

struct STRUCT_MOBEXTRA
{
	short ClassMaster;
	char  Citizen;

	int	  Fame;
	char  Soul;

	short MortalFace;

	struct
	{
		struct
		{
			char Newbie;
			char TerraMistica;
			char MolarGargula;
			char PilulaOrc;

			char EMPTY[30];
		}Mortal;

		struct
		{
			char MortalSlot;
			char MortalLevel;

			char Level355;
			char Level370;

			char Cristal;

			char EMPTY[30];
		}Arch;

		struct
		{
			short ArchLevel;
			short CelestialLevel;
			short SubCelestialLevel;

			char Lv40;
			char Lv90;
			char Lv240;
			char Lv280;
			char Lv320;

			char Add120;
			char Add150;
			char Add180;
			char Add200;

			char Arcana;
			char Reset;

			char EMPTY[30];
		}Celestial;

		char Circle;
		char EMPTY[30];

	}QuestInfo;

	struct
	{
		int Class;

		long long   Exp;

		short		   SPX;
		short		   SPY;

		STRUCT_SCORE   BaseScore;

		long LearnedSkill;


		unsigned short ScoreBonus;
		unsigned short SpecialBonus;
		unsigned short SkillBonus;

		unsigned char  SkillBar1[4];
		unsigned char  SkillBar2[16];

		char Soul;
		char EMPTY[30];
	}SaveCelestial[2];

	time_t LastNT;
	int NT;

	int KefraTicket;

	time_t DivineEnd;

	unsigned int Hold;

	struct
	{
		long long Exp;
		int		  YearDay;
	}DayLog;

	struct
	{
		time_t LastTime;
		int Count;
	}DonateInfo;

	int EMPTY[9];
};

struct STRUCT_ACCOUNTFILE
{
	STRUCT_ACCOUNTINFO Info; // 0 - 216

	STRUCT_MOB	Char[MOB_PER_ACCOUNT]; // 216 - 3480
	STRUCT_ITEM Cargo[MAX_CARGO]; // 3480 - 4504
	int			Coin; // 4504 - 4508

	unsigned char ShortSkill[MOB_PER_ACCOUNT][16]; // 4508 - 4572

	STRUCT_AFFECT affect[MOB_PER_ACCOUNT][MAX_AFFECT];
	STRUCT_MOBEXTRA mobExtra[MOB_PER_ACCOUNT];

	int Donate;

	char TempKey[52];
};
