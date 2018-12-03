#pragma once
#ifndef ROUTER_H
#define ROUTER_H
#include<string>
#include <iostream>
using namespace std;
struct Node
{
	string net_num;//网络号，目的
	int distance;//距离
	string next_hop;//下一跳
	Node *next;
	Node() :next(NULL) {}
	Node(string x, int y, string z, Node *n = NULL) :net_num(x), distance(y), next_hop(z), next(n) {};
};
struct Router//路由器
{
	string name;//路由器名
	Node *head;//路由表头
	Router() :head(NULL) {}
	Router(string n) :name(n), head(NULL) {}
};
#endif
