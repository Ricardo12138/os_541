#pragma once
#include <Windows.h>
//#define BUFFER_SIZE 5
//#include <QThread>
//#include <QMutex>
//#include <QSemaphore>
//typedef int buffer_item;
void startProducerConsumer();

/*
class ProduceAndComsume:public QThread
{
    Q_OBJECT
public:
    void run();
    int insert_item(buffer_item item);
    int remove_item(buffer_item *item);
    void producer();
    void consumer();
    struct v { int i; };
    buffer_item buffer[BUFFER_SIZE + 1];
    buffer_item front = 0, rear = 0;//队列头尾
}
*/
