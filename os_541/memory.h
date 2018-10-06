#define BUSY 1
#define FREE 0
#define OK 1
#define WRONG -1
#define MAXSIZE 640			//�ڴ�����Ϊ640KB,��Ҫ����,���������
typedef int STATUS;

//�����������ݽṹ����������
typedef struct cPartition
{
	int size;				//����
	int state;				//״̬(0:���У�1:�ѷ���)
	int address;			//��ʼ��ַ
	cPartition *next;		//��һ��
}cPartition;

//�ڴ�ʹ�����
typedef struct useCondition
{
	int size;				//����
	int state;				//״̬(0:���У�1:�ѷ���)
	int address;			//��ʼ��ַ
	useCondition *next;		//��һ��
}useCondition;

STATUS initialization();
STATUS allocation(int request);
STATUS recycle(int address);
useCondition* show();