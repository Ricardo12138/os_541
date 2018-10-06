#pragma once
#include"stdafx.h"
#include"file.h"

static int Size = 100;

static int T = 0;

void Delete(node N);

node Create();//根节点

void Add(node &N);//N表示父节点

bool Search(node N, node target);//遍历


