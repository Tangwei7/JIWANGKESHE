#include"Graphmtx.h"
int Graphmtx::zhuan(string n)
{
	for (int i = 0; i < numVertices; i++)
	{
		if (VerticesList[i].name == n)
			return i;
	}
	return -1;
}
void Graphmtx::PrintItem(string s)	//输出路由表
{
	int v1 = zhuan(s);
	Node *ptr;
	ptr = VerticesList[v1].head;
	while (ptr) {
		cout << ptr->net_num << " " << ptr->next_hop << " " << ptr->distance << endl;
		ptr = ptr->next;
	}
}
bool Graphmtx::insertEdge(int v1, int v2, int cost)//插入边
{

	if (v1 > -1 && v1< numVertices && v2>-1 && v2 < numVertices && Edge[v1][v2] == maxWeight)
	{
		Edge[v1][v2] = Edge[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else return false;
}


bool Graphmtx::insertVertex(const Router vertex)//插入顶点
{

	if (numVertices == maxVertices)
		return false;
	VerticesList[numVertices++] = vertex;
	return true;
}


