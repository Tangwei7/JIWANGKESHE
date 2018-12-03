#pragma once
#ifndef GRAPHMTX_H
#define GRAPHMTX_H
#include"Router.h"
#include "Graph.h"
#include<string>
#include <iostream>
using namespace std;

//边信息类型定义
struct RowColWeight
{
	int row;							//行下标
	int col;							//列下标
	int weight;							//权值
};

class Graphmtx : public Graph
{
public:
	Graphmtx(int sz = DeafultVertices);
	~Graphmtx()
	{
		delete[] VerticesList;
		delete[] Edge;
	}
	Router getValue(int i)
	{
		string a = "##";
		return (i >= 0 && i <= numVertices) ? VerticesList[i] : a;
	}
	int getWeight(int v1, int v2)
	{
		return (v1 != -1 && v2 != -1) ? Edge[v1][v2] : 0;
	}
	bool insertVertex(const Router vertex);
	bool insertEdge(string s, string n, int cost) { return insertEdge(zhuan(s), zhuan(n), cost); }
	bool removeVertex(string n);
	bool removeEdge(string s, string n);
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	void Path();//生成路由表
	void CreatGraph(Router V[], int n, RowColWeight E[], int e);//输入拓扑信息构建图
	void PrintItem(string s);//输出s的路由表
	void chushihua();
protected:
	Router *VerticesList;		//顶点表
	int * *Edge;				//邻接矩阵
	int * Path(int v1, int w);//下标为v1的路由器下标为w的路由器生成路由表
	int zhuan(string n);//根据路由器名找到对应下表
	bool insertEdge(int v1, int v2, int cost);
};

#endif