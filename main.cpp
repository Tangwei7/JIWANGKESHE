#include <stdlib.h>
#include <iomanip>
#include "Graphmtx.h"

using namespace std;
const int MaxVertices = 100;	//ͼ�е���󶥵���Ŀ
const int MaxWeight = 16;	//������Ȩֵ

void meau() {
	cout << "*********************�˵�*********************" << endl;
	cout << "            1�����ָ��·������·�ɱ�       " << endl;
	cout << "            2�����·����                   " << endl;
	cout << "            3����ӱ�                       " << endl;
	cout << "            4��ɾ��·����                   " << endl;
	cout << "            5��ɾ����                       " << endl;
	cout << "            6���˳�                         " << endl;
	cout << "*********************************************" << endl;
	cout << "            ���������֣�";
}
int main()
{
	Router v1[] = { {"r1"},{"r2"},{"r3"},{"r4"},{"r5"},{"r6"},{"r7"},{"r8"},{"r9"} };//������Ϣ
	RowColWeight rcw1[] = { {0,1,2},{0,5,1},{0,6,1},
							{1,2,2},{1,3,4},
							{2,3,1},{ 2,5,3 },{2,6,2},
							{3,4,1},{3,6,6},{3,7,5},{ 3,8,2 },
							{4,5,5},
							{5,6,1},
							{6,7,3},
							{7,8,2} };//����Ϣ
	int d = 9, e = 16;
	Graphmtx g1;
	g1.CreatGraph(v1, d, rcw1, e);
	//g1.chushihua();
	//cout << g1<<endl;
	cout << "            ��������ɹ�����ѡ��������Ĳ���" << endl;

	meau();
	int ch; string s, n; int c;
	cin >> ch;
	cout << "*********************************************" << endl;
	while (1) {
		switch (ch) {
		case 1:
			g1.chushihua();
			g1.Path();
			cout << "������·����������r1" << endl;
			cin >> s;
			g1.PrintItem(s);
			break;
		case 2:
			cout << "����������·����������r1" << endl;
			cin >> s;
			g1.insertVertex(s);
			break;
		case 3:
			cout << "���������ӱߣ��磺r1 r2 3" << endl;
			cin >> s >> n >> c;
			g1.insertEdge(s, n, c); break;
		case 4:
			cout << "��������Ҫɾ��·����������r1" << endl;
			cin >> s;
			g1.removeVertex(s); break;
		case 5:
			cout << "��������Ҫɾ���ı߶�Ӧ������·����������r1 r2" << endl;
			cin >> s >> n;
			g1.removeEdge(s, n); break;
		case 6:return 0;
		default:cout << "����������1-6" << endl;
		}
		meau(); cin >> ch;
	}
	return 0;
}