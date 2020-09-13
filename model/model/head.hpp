#pragma once

///////////////////////////////////////////
///		�������룬ͷ�ļ�
//////////////////////////////////////////

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

// ʳ����������ÿ������������
struct goods {
	int _id;		//	0 ˮ��1 ʳ��
	int _weightA;	//	ÿ������
	int _basicM;	//	��׼�۸�
	int _expend[3];	// ÿ��Ļ������� 0 �����죬1 �����죬2 ɳ����

	goods(int id, int w, int b, int n1, int n2, int n3)
		:_id(id), _weightA(w), _basicM(b)
	{
		_expend[0] = n1;
		_expend[1] = n2;
		_expend[2] = n3;
	}
};

struct node {
	vector<int> _path;
	int _weight;
	int _money;
	int _day;
};


void DFS(int idx, int to, vector<int>& ans, unordered_map<int, set<int> >& map_t, vector<int>& arr, bool& flag);
vector<int> BFS(int start, int end, unordered_map<int, set<int> >& map_t, int n);
void ReadPath(unordered_map<int, set<int> >& map_t, const string filename);
void ReadWeather(vector<int>& w, const string fileName);

///////////////////////////////////////////
////	����������� �õ�ָ����������·��
//////////////////////////////////////////
vector<int> BFS(int start, int end, unordered_map<int, set<int> >& map_t, int n) {
	vector<int> arr(n, -1);
	queue<int> que;

	que.push(start);
	int idx = 1;
	arr[start] = idx++;

	while (que.empty() == false) {
		int size = que.size();
		bool flag = false;

		while (size--) {
			int from = que.front();
			que.pop();
			for (int to : map_t[from]) {
				if (arr[to] != -1)	continue;
				que.push(to);
				arr[to] = idx;
				if (to == end)	flag = true;
			}
		}

		idx++;
		if (flag == true) break;
	}

	// dfs �Ӻ���ǰ�Ƴ�·��
	vector<int> ans;
	bool flag = false;
	DFS(idx - 1, end, ans, map_t, arr, flag);
	reverse(ans.begin(), ans.end());

	return ans;
}

/////////////////////////////////////////////////
////////	dfs  �Ӻ���ǰ��·��
////////////////////////////////////////////////
void DFS(int idx, int to, vector<int>& ans, unordered_map<int, set<int> >& map_t, vector<int>& arr, bool& flag) {
	if (idx == 1) {
		ans.push_back(to);
		flag = true;
		return;
	}

	ans.push_back(to);
	for (int from : map_t[to]) {
		if (arr[from] != idx - 1) continue;

		DFS(idx - 1, from, ans, map_t, arr, flag);
		if (flag == true) return;
	}
	ans.pop_back();
}


/////////////////////////////////////////////
/////		��ȡ�ļ��б���ߵĹ�ϵ
////////////////////////////////////////////
void ReadPath(unordered_map<int, set<int> >& map_t, const string fileName) {
	ifstream  fp;
	fp.open(fileName.c_str(), ios::in);
	int u = 0;
	int v = 0;

	while (!fp.eof()) {
		fp >> u >> v;
		//cout << u << ' ' << v<<endl;
		map_t[u].insert(v);
		map_t[v].insert(u);
	}

	fp.close();
}

///////////////////////////////////////////////
///////		ȥ���ļ���ÿ����������
//////////////////////////////////////////////
void ReadWeather(vector<int>& w, const string fileName) {
	ifstream  fp;
	fp.open(fileName.c_str(), ios::in);
	int id = 0;
	int stauts = 0;

	while (!fp.eof()) {
		fp >> id >> stauts;
		/*if (stauts == 0) cout << "���� ";
		else if (stauts == 1) cout << "���� ";
		else cout << "ɳ�� ";*/
		w[id] = stauts;
	}

	fp.close();
}