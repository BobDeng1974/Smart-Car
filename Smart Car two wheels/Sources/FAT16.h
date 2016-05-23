#ifndef   FAT16_H
#define   FAT16_H

#include"MC9S12XS128.h"

typedef struct
{
	byte BS_jmpBoot[3];       //jumpinstruction
	byte BS_OEMName[8];       //system name
	word BPB_BytesPerSec;     //logical bytes per sector
	byte BPB_SecPerClus;      //sectors per cluster
	word BPB_RsvdSecCnt;      //number of reserved sectors starting from 0
	byte BPB_NumFATs;         //number of FATs
	word BPB_RootEntCnt;      //number of root dir entries
	word BPB_TotSec16;        //total sectors. 0 if ofs 15h used 
	byte BPB_Media;           //media descriptor 
	word BPB_FATSz16;         //number of sectors per FAT
	word BPB_SecPerTrk;       //number of logical sectors per track
	word BPB_NumHeads;        //number of logical heads
	dword BPB_HiddSec;        //number of hidden sectors
	dword BPB_TotSec32;       //total sectors
	byte BS_DrvNum;           //physical drive number
	byte BS_Reservedl;        //reserved
	byte BS_BootSig;          //signature byte for extended boot record
	dword BS_VolID;           //serial number
	byte BS_VolLab[11];       //label
	byte BS_FilSysType[8];    //FAT type 
	//byte ExecutableCode[448];
	//byte ExecutableMarker[2];
} FAT_BPB;

typedef struct
{
	byte NAME[8];
	byte TYPE[3];
} FILE_NAME;

typedef struct
{
	word Start;
	dword Size;
} FILE_POSIT;

typedef struct
{
	FILE_NAME FileName;     //name
	byte FileAttrib;        //extension
	byte UnUsed[10];        //flags and reserved
	byte FileUpdateTime[2]; //time and data
	byte FileUpdateData[2]; //first cluter
	FILE_POSIT FilePosit;   //size
} DIR;

typedef struct
{
	word ClusID;
	word SecOfClus;
	word ByteOfSec;
} DATA_POSIT;

/* File object structure */
typedef struct _FIL 
{
  word	Id;				       /* Owner file system mount ID */
	byte	Csect;			     /* Sector address in the cluster */
	dword	Fsize;			     /* File size */
	word	Org_clust;	     /* File start cluster */
	word	Curr_clust;	     /* Current cluster */
  word  Curr_clustnum;   /* Current cluster */
	dword	Curr_sect;       /* Current sector */
} FIL;

//********************************************************************************************
//��һ������
void ReadBlock(dword LBA);
//********************************************************************************************
//дһ������
void WriteBlock(dword LBA);
//********************************************************************************************
void CopyBytes(byte *s, byte *d, word size);
//********************************************************************************************
byte IsEqual(void *A, void *B, byte Size);
//********************************************************************************************
void EmptyBytes(byte *data, word size);
//********************************************************************************************
//дBPB���ݽṹ
void FATInit(void);
//********************************************************************************************
//��ȡBPB���ݽṹ
void ReadBPB(void);
//********************************************************************************************
//��ȡFAT��ʼ������
dword FATStartSec(void);
//********************************************************************************************
//��ȡ��Ŀ¼��ʼ������
dword DirStartSec(void);
//********************************************************************************************
//��ȡ��������ʼ������
dword DataStartSec(void);
//********************************************************************************************
//Ŀ¼��ռ�õ�������
word GetDirSecCount(void);
//********************************************************************************************
//��ȡһ���صĿ�ʼ����
dword ClusConvLBA(word ClusID);
//********************************************************************************************
//��ȡ�ļ�������ָ����
word ReadFAT(word Index, unsigned char flag);
//********************************************************************************************
//д�ļ�������ָ����
void WriteFAT(word Index, word Value);
//********************************************************************************************
//д�����ļ������
void WriteFAT2(word Index, word Value);
//********************************************************************************************
//��ȡ��Ŀ¼�п���ʹ�õ�һ��
word GetEmptyDIR(void);
//********************************************************************************************
//��ú��ļ�����Ӧ��Ŀ¼��
byte GetFileID(byte Name[11], DIR* ID);
//********************************************************************************************
//��ȡһ���յ�FAT��
word GetNextFAT(word FATnum);
//********************************************************************************************
//��ȡ��Ŀ¼��ָ����
void ReadDIR(word Index, DIR* Value);
//********************************************************************************************
//д��Ŀ¼��ָ����
void WriteDIR(word Index, DIR* Value);
//********************************************************************************************
//����һ�����ļ�
void CreateFile(byte *FileName, FIL *file, DIR *FileDir);
//********************************************************************************************
//�����ļ������,ʹ��ͱ���һ��
void CopyFAT(void);
//********************************************************************************************
//�����ļ�������
void OperateFile(byte Write ,byte Name[11], dword Start, dword Length, byte* Data, FIL *file,DIR *FileDir);
//********************************************************************************************
//ɾ���ļ�
void DelFile(byte Name[11]);
//********************************************************************************************
//��ʽ��
void FormatCard(void);
//********************************************************************************************
//---------------------------------------------------------------------------------------------------------------------------------
#endif