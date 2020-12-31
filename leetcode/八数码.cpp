#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

string start;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};

int bfs() {
    string end = "12345678x";
    
    queue<string> que;
    que.push(start);
    unordered_map<string,int> mp;
    mp[start] = 0;
    
    while(!que.empty()) {
        auto f = que.front();
        que.pop();
        
        int dis = mp[f];
        if(f == end) return dis;
        
        int p = f.find('x');
        int x = p / 3, y = p % 3;
        
        for(int i = 0; i < 4; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            
            if(tx < 0 || tx >= 3 || ty < 0 || ty >= 3) continue;
            
            string t = f;
            swap(t[p],t[tx*3 + ty]);
            if(mp.count(t)) continue;
            
            que.push(t);
            mp[t] = dis + 1;
        }
    }
    
    return -1;
}

int main() {
    char ch;
    for(int i = 0; i < 9; i++) {
        cin >> ch;
        start += ch;
    }
    
    cout << bfs() << endl;
    return 0;
}


��һ��3��3�������У�1~8��8�����ֺ�һ����x��ǡ�ò��ز�©�طֲ�����3��3�������С�

���磺

1 2 3
x 4 6
7 5 8
����Ϸ�����У����԰ѡ�x�������ϡ��¡������ĸ�����֮һ�����ֽ�����������ڣ���

���ǵ�Ŀ����ͨ��������ʹ�������Ϊ�������У���Ϊ��ȷ���У���

1 2 3
4 5 6
7 8 x
���磬ʾ����ͼ�ξͿ���ͨ���á�x���Ⱥ����ҡ��¡���������������ֽ����ɹ��õ���ȷ���С�

�����������£�

1 2 3   1 2 3   1 2 3   1 2 3
x 4 6   4 x 6   4 5 6   4 5 6
7 5 8   7 5 8   7 x 8   7 8 x
���ڣ�����һ����ʼ������������õ���ȷ����������Ҫ���ж��ٴν�����

�����ʽ
����ռһ�У���3��3�ĳ�ʼ������������

���磬�����ʼ����������ʾ��
1 2 3

x 4 6

7 5 8

������Ϊ��1 2 3 x 4 6 7 5 8

�����ʽ
���ռһ�У�����һ����������ʾ���ٽ���������

��������ڽ���������������-1����

����������
2  3  4  1  5  x  7  6  8 
�������
19
