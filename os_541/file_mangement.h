#pragma once
#include"stdafx.h"
#include"file.h"

static int Size = 100;

static int T = 0;

void Delete(node &N);

void fileDelete(node &N);

node Create();//�������ڵ�

node * Add(node &N);//N��ʾ���ڵ�

void Addtxt(node& N, string filename);//���ļ�û�ҵ�ʱĬ�����

bool Search(node N, string target);//�����ļ���/Ŀ¼��

bool SearchFile(node N, string target);//�����ļ���

void Write(node N , string filename , int time ,int size);

void Read(node N, string filename , int time);

void fileWrite(string filename, int time, int size);

bool fileRead(string filename, int time);


