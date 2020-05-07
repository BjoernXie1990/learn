#define _CRT_SECURE_NO_WARNINGS 1

#include "tree.h"

//��ȡ����
vector<point> ReadData()
{
	ifstream fp;
	fp.open("data.txt", ios::in);	//�Զ�ģʽ�������ļ�
	vector<point> temp;
	string str;
	while (getline(fp, str))
	{
		//cout << str << endl;
		point p;
		char ch = '\t';
		int start = 0;
		int len = 0;	//��ȡ�ַ�������
		//��ȡ������
		auto pos = find(str.begin(), str.end(), ch);
		len = pos - str.begin() - start;
		string t = str.substr(start, len);
		p._id = stoi(t);
		start += len + 1;
		//��ȡ�������
		pos = find(str.begin() + start, str.end(), ch);
		len = pos - str.begin() - start;
		p._type = str.substr(start, len);
		start += len + 1;
		//��ȡ������
		pos = find(str.begin() + start, str.end(), ch);
		len = pos - str.begin() - start;
		t = str.substr(start, len);
		p._row = stoi(t);
		start += len + 1;
		//��ȡ������
		len = str.end() - str.begin() - start;
		t = str.substr(start, len);
		p._col = stoi(t);

		temp.push_back(p);
	}

	fp.close();	//�ر��ļ�
	return temp;
}

//���Ҷ�����ˮվ��ʼ��λ��
int FindSecond(vector<point>& points)
{
	for (size_t i = 1; i < points.size(); i++)
		if (points[i]._type[0] == 'P')
			return i;
	return points.size();//û�еڶ����㷵��ĩβλ��
}

double com(point l, point r)
{
	return sqrt(pow(abs(l._row - r._row), 2) +
		pow(abs(l._col - r._col), 2));
}

side Path(point l, point r)
{
	side tmp;
	tmp._start = l._id;
	tmp._end = r._id;
	tmp._distance = com(l, r);
	//cout << tmp._start << ' ' << tmp._end << ' ' << tmp._distance << endl;
	//Sleep(500);
	return tmp;
}

//���ɱ�
vector<side> SetSide(vector<point>& left, vector<point>& right)
{
	size_t len1 = left.size();
	size_t len2 = right.size();

	vector<side> tmp;
	//left �� right
	for (size_t i = 0; i < len1; i++)
		for (size_t j = 0; j < len2; j++)
			tmp.push_back(Path(left[i], right[j])); //����i�㵽j��ı�

	//right �� right
	for (size_t i = 0; i < len2; i++)
		for (size_t j = i + 1; j < len2; j++)
			tmp.push_back(Path(right[i], right[j])); //����i�㵽j��ı�
	return tmp;
}

//��С��������
bool cmp(const side a, const side b)
{
	return a._distance < b._distance;
}
//����һ��վ��ԭ��ľ���
bool point_cmp(const point a, const point b)
{
	static point center = { 0, "A", 26, 31 };
	return com(a, center) < com(b, center);
}

//���ߵľ���Ӵ�С����
bool side_cmp(const side a, const side b)
{
	return a._distance > b._distance;
}

//�ڲ��鼯�в��Ҹ��ڵ��λ��
int GetRoot(int k, vector<int>& V)
{
	while (k != V[k])
		k = V[k];//ֻ�и��ڵ������ k = V[k]
	return k;
}

//�жϸùܵ��Ƿ�Ϊһ���ܵ�
bool FindP(int start, int end, vector<point>& one)
{
	int ans = 0;
	for (size_t i = 0; i < one.size(); i++)
	{
		if (one[i]._id == start || one[i]._id == end)
			ans++;
	}
	if (start == 0 || end == 0)
		ans++;
	return ans != 2;
}
//Kruskal �㷨
double Kruskal(vector<side>& sides, vector<point>& points, vector<side>& sideTwo,vector<point>& one)
{
	double sum = 0;
	//����,���ձߵĴ�С��С����
	sort(sides.begin(), sides.end(), cmp);
	cout << "�����еı߰�װ��С�����˳���������" << endl;
	int pointNum = points.size();
	vector<int> V(pointNum, 0);//���岢�鼯����
	//��ʼ��ÿһ����㶼�Ǹ��ڵ㣬���鼯��
	for (int i = 0; i < pointNum; i++)
		V[i] = i;

	//ɸѡ
	int len = sides.size();//�ߵ���Ŀ
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		int start = GetRoot(sides[i]._start, V);
		int end = GetRoot(sides[i]._end, V);
		if (start != end)
		{
			V[start] = end;
			sum += sides[i]._distance;

			if (FindP(sides[i]._start, sides[i]._end,one))
			{	//��Ӷ����ܵ���������
				sideTwo.push_back(sides[i]);
				count++;
				if (count <= 89)
					cout << sides[i]._end << endl;
				//cout << points[sides[i]._start]._row << ' '<< points[sides[i]._start]._col <<' '<< points[sides[i]._end]._row << ' ' << points[sides[i]._end]._col << endl;
			}
			else
			{
				cout << points[sides[i]._start]._row << ' ' << points[sides[i]._start]._col << ' ' << points[sides[i]._end]._row << ' ' << points[sides[i]._end]._col << endl;
			}
			//cout << "�� " << i + 1 << " �Σ�ѡ�� " << sides[i]._start << " �� " << sides[i]._end << " �����㣬�ɹ��ϲ�" << endl;
			//printf("ѡ�� %3d �� %3d ��������һ��ˮ�ܣ�����Ϊ %.2lf\n", sides[i]._start, sides[i]._end, sides[i]._distance);
		}
		/*else
		{
			cout << "�� " << i + 1 << " �Σ�ѡ�� " << sides[i]._start << " �� " << sides[i]._end << " �����㣬��һ�������У��޷��ϲ�" << endl;
		}*/
	}
	//cout << count/2 << endl;
	return sum;
}

//�����  text2
void InsertSide(vector<side>& tmp, side s)
{
	if (tmp.size() < 2)
		tmp.push_back(s);
	else if (s._distance > tmp[1]._distance)
		tmp[1] = s;
	sort(tmp.begin(), tmp.end(), side_cmp);//�Ӵ�С����
}

//�������40���ﳤ�ȵĹܵ� --text3
void bfs(vector<vector<int> >& map, vector<vector<double> >& length, vector<int>& visit, vector<point>& one, int index,double& path)
{
	//�������
	queue<int> que;
	que.push(index);

	while (!que.empty())
	{
		size_t size = que.size();
		for (size_t i = 0; i < size; i++)
		{
			int start = que.front();//�����
			que.pop();

			for (size_t j = 0; j < map[start].size(); j++)
			{
				int end = map[start][j];//�յ���
				double len = length[start][j];
				if (visit[end] || len > path)
					continue;
				visit[end] = 1;
				path -= len;
				que.push(end);
			}
		}
	}
}