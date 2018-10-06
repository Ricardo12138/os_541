#define BUSY 1
#define FREE 0
#define OK 1
#define WRONG -1
#define MAXSIZE 640			//内存容量为640KB,若要更改,请在这更改
typedef int STATUS;

//连续分区数据结构，基于链表
typedef struct cPartition
{
	int size;				//长度
	int state;				//状态(0:空闲；1:已分配)
	int address;			//起始地址
	cPartition *next;		//下一个
}cPartition;

//内存使用情况
typedef struct useCondition
{
	int size;				//长度
	int state;				//状态(0:空闲；1:已分配)
	int address;			//起始地址
	useCondition *next;		//下一个
}useCondition;

/*
** 连续分区初始化
** 初始化成功返回1，否则返回-1
*/
STATUS initialization();

/*
** 连续分区分配内存,采用最佳匹配法
** 接收参数：请求内存的大小
** 分配成功返回该内存块的首地址，否则返回-1
*/
STATUS allocation(int request);

/*
** 连续分区回收内存
** 接收参数：内存块的起始地址
** 回收成功返回1，否则返回-1
*/
STATUS recycle(int address);

/*
** 内存的使用情况
** 用链表形式返回内存的使用情况
*/
useCondition* show();