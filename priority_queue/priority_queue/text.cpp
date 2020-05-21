#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.hpp"
#include <vld.h>
#include <time.h>

void text()
{
	srand((int)time(0));
	//priority_queue<int,vector<int>,greater<int> > que;//С����
	priority_queue<int, vector<int>, less<int> > que;//�����

	for (int i = 0; i < 10; i++)
		que.push(rand() % 100);
	que.show();
	while (!que.empty())
	{
		cout << que.top() << ',';
		que.pop();
		que.show();
	}
}

int main()
{
	text();

	return 0;
}