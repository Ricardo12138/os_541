#include "stdafx.h"
#include "ProducerConsumer.h"
#include <Windows.h>
#include <ctime>
#include <mutex>
#include <cstdlib>
//#define BUFFER_SIZE 5
using namespace std;


typedef int buffer_item;
struct v { int i; };
buffer_item buffer[BUFFER_SIZE + 1];
buffer_item front = 0, rear = 0;//����ͷβ
HANDLE Mutex, Empty, full;//�������,���ź���,���ź���
int insert_item(buffer_item item)
{
	if ((rear + 1) % (BUFFER_SIZE + 1) == front)
		return 1;
	buffer[rear] = item;
	rear = (rear + 1) % (BUFFER_SIZE + 1);
	return 0;
}
int remove_item(buffer_item *item)
{
	if (front == rear)
		return 1;
	*item = buffer[front];
	front = (front + 1) % (BUFFER_SIZE + 1);
	return 0;
}
DWORD WINAPI producer(PVOID param)//�������߳�
{
	int rand1;
	srand((unsigned)time(0));
	while (1)
	{
		Sleep(rand() % 101 * 10);
		WaitForSingleObject(Empty, INFINITE);
		WaitForSingleObject(Mutex, INFINITE);
		rand1 = rand();
		cout << "producer has producerd " << rand1 << endl;
		if (insert_item(rand1))
			cout << "insert data error!" << endl;
		ReleaseMutex(Mutex);
		ReleaseSemaphore(full, 1, NULL);
	}
}
DWORD WINAPI consumer(PVOID param)//�������߳�
{
	int rand1;
	srand((unsigned)time(0));
	while (1)
	{
		Sleep(rand() % 101 * 10);
		WaitForSingleObject(full, INFINITE);
		WaitForSingleObject(Mutex, INFINITE);
		if (remove_item(&rand1))
			cout << "remove data error!" << endl;
		else
			cout << "consumer consumed " << rand1 << endl;
		ReleaseMutex(Mutex);
		ReleaseSemaphore(Empty, 1, NULL);
	}
}

//���Գ��� 
void startProducerConsumer()
{
	int sleeptime, pnum = 0, cnum = 0;
	DWORD *ThreadIdP, *ThreadIdC, i = 0;
	struct v *countp, *countc;
	HANDLE *ThreadHandleP, *ThreadHandleC;
	sleeptime = 10000;

	ThreadHandleP = (HANDLE *)malloc(pnum * sizeof(HANDLE));
	ThreadHandleC = (HANDLE *)malloc(cnum * sizeof(HANDLE));
	ThreadIdP = (DWORD *)malloc(pnum * sizeof(DWORD));
	ThreadIdC = (DWORD *)malloc(pnum * sizeof(DWORD));
	//�����ź���
	Mutex = CreateMutex(NULL, FALSE, NULL);
	Empty = CreateSemaphore(NULL, BUFFER_SIZE, BUFFER_SIZE, NULL);
	full = CreateSemaphore(NULL, 0, BUFFER_SIZE, NULL);

	countp = (struct v *)malloc((pnum + 1) * sizeof(struct v));
	countc = (struct v *)malloc((cnum + 1) * sizeof(struct v));

	countp[i + 1].i = i + 1;
	ThreadHandleP[i] = CreateThread(NULL, 0, producer, &countp[i + 1], 0, &ThreadIdP[i]);//�����������߳�

	countc[i + 1].i = i + 1;
	ThreadHandleC[i] = CreateThread(NULL, 0, consumer, &countc[i + 1], 0, &ThreadIdC[i]);//�����������߳�

	Sleep(sleeptime);
}

/*
int ProduceAndComsume::insert_item(buffer_item item)
{
    if ((rear + 1) % (BUFFER_SIZE + 1) == front)
        return 1;
    buffer[rear] = item;
    rear = (rear + 1) % (BUFFER_SIZE + 1);
    return 0;
}
int ProduceAndComsume::remove_item(buffer_item *item)
{
    if (front == rear)
        return 1;
    *item = buffer[front];
    front = (front + 1) % (BUFFER_SIZE + 1);
    return 0;
}
void ProduceAndComsume::producer()//�������߳�
{
    int rand1;
    srand((unsigned)time(0));
    while (1)
    {
        Sleep(rand() % 101 * 10);
        WaitForSingleObject(Empty, INFINITE);
        WaitForSingleObject(Mutex, INFINITE);
        rand1 = rand();
        cout << "producer has producerd " << rand1 << endl;
        if (insert_item(rand1))
            cout << "insert data error!" << endl;
        ReleaseMutex(Mutex);
        ReleaseSemaphore(full, 1, NULL);
    }
}
void ProduceAndComsume::consumer()//�������߳�
{
    int rand1;
    srand((unsigned)time(0));
    while (1)
    {
        Sleep(rand() % 101 * 10);
        WaitForSingleObject(full, INFINITE);
        WaitForSingleObject(Mutex, INFINITE);
        if (remove_item(&rand1))
            cout << "remove data error!" << endl;
        else
            cout << "consumer consumed " << rand1 << endl;
        ReleaseMutex(Mutex);
        ReleaseSemaphore(Empty, 1, NULL);
    }
}

//���Գ���
void ProduceAndComsume::run()
{
    int sleeptime, pnum = 0, cnum = 0;
    DWORD *ThreadIdP, *ThreadIdC, i = 0;
    struct v *countp, *countc;
    HANDLE *ThreadHandleP, *ThreadHandleC;
    sleeptime = 10000;

    //ThreadHandleP = (HANDLE *)malloc(pnum * sizeof(HANDLE));
    //ThreadHandleC = (HANDLE *)malloc(cnum * sizeof(HANDLE));
    //ThreadIdP = (DWORD *)malloc(pnum * sizeof(DWORD));
    //ThreadIdC = (DWORD *)malloc(pnum * sizeof(DWORD));
    //�����ź���
    //Mutex = CreateMutex(NULL, FALSE, NULL);
    //Empty = CreateSemaphore(NULL, BUFFER_SIZE, BUFFER_SIZE, NULL);
    //full = CreateSemaphore(NULL, 0, BUFFER_SIZE, NULL);

    countp = (struct v *)malloc((pnum + 1) * sizeof(struct v));
    countc = (struct v *)malloc((cnum + 1) * sizeof(struct v));

    countp[i + 1].i = i + 1;
    ThreadHandleP[i] = CreateThread(NULL, 0, producer, &countp[i + 1], 0, &ThreadIdP[i]);//�����������߳�

    countc[i + 1].i = i + 1;
    ThreadHandleC[i] = CreateThread(NULL, 0, consumer, &countc[i + 1], 0, &ThreadIdC[i]);//�����������߳�

    Sleep(sleeptime);
}
*/
