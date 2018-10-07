#pragma once
#include"stdafx.h"
#include"file.h"

static int Size = 100;

static int T = 0;

void Delete(node &N);

void fileDelete(node &N);

node Create();//创建根节点

node * Add(node &N);//N表示父节点

void Addtxt(node& N, string filename);//找文件没找到时默认添加

bool Search(node N, string target);//遍历文件名/目录名

bool SearchFile(node N, string target);//遍历文件名

void Write(node N , string filename , int time ,int size);

void Read(node N, string filename , int time);

void fileWrite(string filename, int time, int size);

bool fileRead(string filename, int time);


