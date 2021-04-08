#include <iostream>
#include <stack>

using namespace std;

const int N = 30;
int f[N];
int n,m;
struct node {
    int id,cur,len,state;
};

void dfs(int id,int cur,int len) {
    if(len == m) {
        for(int i = 0; i < len; i++)
            cout << f[i] << " ";
        cout << endl;
        return ;
    }
    
    for(int i = cur; i <= n; i++) {
        f[id] = i;
        dfs(id + 1,i + 1, len + 1);
    }
}

int main() {
    cin >> n >> m;
    // dfs(0,1,0);
    
    stack<node> st;
    st.push({0,1,0,0});
    
    while(st.size()) {
        node t = st.top();
        st.pop();
        
        int id= t.id, cur = t.cur, len = t.len;
        int state = t.state;
        
        if(len == m) {
            for(int i = 1; i <= n; i++)
                if((state >> i) & 1)
                    cout << i << " ";
            cout << endl;
            continue;
        }
        
        for(int i = n; i >= cur; i--) {
            st.push({t.id + 1,i + 1,len + 1,state | (1 << i)});
        }
    }
    
    return 0;
}

�� 1��n �� n �����������ѡ�� m ����������п��ܵ�ѡ�񷽰���

�����ʽ
�������� n,m ,��ͬһ���ÿո������

�����ʽ
���մ�С�����˳��������з�����ÿ�� 1 ����

���ȣ�ͬһ���ڵ����������У�������������һ���ո������

��Σ�����������ͬ���У���Ӧ�±����һһ�Ƚϣ��ֵ����С������ǰ�棨���� 1 3 5 7 ���� 1 3 6 8 ǰ�棩��

���ݷ�Χ
n>0 ,
0��m��n ,
n+(n?m)��25
����������
5 3
���������
1 2 3 
1 2 4 
1 2 5 
1 3 4 
1 3 5 
1 4 5 
2 3 4 
2 3 5 
2 4 5 
3 4 5 
˼���⣺���Ҫ��ʹ�÷ǵݹ鷽��������ô���أ�
