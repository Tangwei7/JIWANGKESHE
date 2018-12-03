#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include<string>
#include"Router.h"
using namespace std;
const int maxWeight = INT_MAX;
const int DeafultVertices = 30;			//代表最大顶点数 =n

struct Edge
{
	int dest;			//边的另一个顶点位置
	int cost;				//边上的权值
	Edge * link;	//下一条边链指针
	Edge() { cost = maxWeight; }
	Edge(int num, int weight) : dest(num), cost(weight), link(NULL) {}
	bool operator != (Edge& R)const
	{
		return (dest != R.dest) ? true : false;
	}
};

struct Vertex
{
	Router data;
	Edge *adj;			//边链表的头指针
};

class Graph
{
public:
	Graph(int sz = DeafultVertices) {};
	~Graph() {}
	bool GraphEmpty()const
	{
		if (numEdges == 0)
			return true;
		else
		{
			return false;
		}
	}
	bool GraphFull()const
	{
		if (numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2)
			return true;
		else return false;
	}
	int NumberOfVertices() { return numVertices; }		//返回当前顶点数
	int NunberOfEdges() { return numEdges; }			//返回当前边数
	virtual Router getValue(int i) = 0;							//取顶点i的值
	virtual int getWeight(int v1, int v2) = 0;					//取边（v1，v2）上的权值
	virtual bool insertVertex(const Router vertex) = 0;			//插入一个顶点vertex
	virtual bool insertEdge(string s, string n, int cost) = 0;		//插入边(v1,v2),权为cost
	virtual bool removeVertex(string s) = 0;					//删去顶点v和所有与v相关的边
	virtual bool removeEdge(string s, string n) = 0;				//删去边(v1,v2)
protected:
	int maxVertices;
	int numEdges;
	int numVertices;
};
#endif