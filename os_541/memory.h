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

STATUS initialization();
STATUS allocation(int request);
STATUS recycle(int address);
useCondition* show();