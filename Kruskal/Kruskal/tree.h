#pragma once

#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <queue>
using namespace std;


struct point
{
	int _id;		//������
	string _type;	//�������
	int _row;		//��ĺ�����
	int _col;		//���������
};

struct side
{
	int _start;	//��ʼ���id
	int _end;	//�յ��id
	double _distance;	//ŷʽ����
};

void Text2(vector<side>& sideTwo, vector<point> points);
double text1(vector<point>& points, vector<point>& zero, vector<point>& one, vector<point>& two);
void text3(vector<point>& points, vector<point>& zero, vector<point>& one, vector<point>& two);

//���ߵľ���Ӵ�С����
bool side_cmp(const side a, const side b);
//��С��������
bool cmp(const side a, const side b);
//����һ��վ��ԭ��ľ���
bool point_cmp(const point a, const point b);
//��������֮�����
double com(point l, point r);

//���Ҷ�����ˮվ��ʼ��λ��
int FindSecond(vector<point>& points);

//����һ����
side Path(point l, point r);

//�ڲ��鼯�в��Ҹ��ڵ��λ��
int GetRoot(int k, vector<int>& V);

//���ɱ�
vector<side> SetSide(vector<point>& left, vector<point>& right);

//Kruskal �㷨
double Kruskal(vector<side>& sides, vector<point>& points, vector<side>& sideTwo, vector<point>& one);

//չʾ��
void Show(vector<point>& a);

//����һ���� text2
void InsertSide(vector<side>& tmp, side s);

//��ȡ����
vector<point> ReadData();

//�������40���ﳤ�ȵĹܵ�
void bfs(vector<vector<int> >& map, vector<vector<double> >& length, vector<int>& visit, vector<point>& one, int index, double& path);