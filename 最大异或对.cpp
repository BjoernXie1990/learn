//�ڸ�����N������A1��A2����AN��ѡ����������xor��������㣬�õ��Ľ������Ƕ��٣�

//�����ʽ
//��һ������һ������N��

//�ڶ�������N������A1��AN��

//�����ʽ
//���һ��������ʾ�𰸡�

//���ݷ�Χ
//1��N��105,
//0��Ai<231
//����������
//3
//1 2 3
//���������
//3


#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
const int M = N * 31;

int num[N];
int son[M][2];
int id;

//�������ݵ��ֵ����У�һ��������ڵ���1���ҽڵ���0
void insert(int num)
{
    int p = 0;
    // for(int i = 30; i >= 0; i--)
    for(int i = 30; ~i; i--)
    {
        //��ȡ��iλ������ 0 ���� 1
        // int& s = son[p][num>>i & 1];
        // if(!s) s = ++id; //����һ���½��
        // p = s;
        int tmp = num>>i&1;
        if(!son[p][tmp]) son[p][tmp] = ++id;
        p = son[p][tmp];
    }
}

//�ҵ���������������Ľ��
int Find(int num)
{
    int ret = 0;
    int p = 0;
    for(int i = 30; ~i; i--)
    {
        int s = num>>i & 1;
        //���Ļ���ͬ��Ϊ0������Ϊ1
        if(son[p][!s])//������ڸ�λ�ò�ͬ���������������֧
        {
            ret += 1 << i;
            p = son[p][!s];
        }
        else
            p = son[p][s];
    }
    
    return ret;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>num[i];
        insert(num[i]);//��������ݵ��ֵ�����
    }
    
    int ans = 0;
    //���������ֵ
    for(int i = 0; i < n; i++)
        ans = max(ans,Find(num[i]));
    
    cout<<ans<<endl;
    return 0;
}

// //������
// int main()
// {
//     int n;
//     cin>>n;
//     for(int i = 0; i < n; i++)
//         cin>>num[i];
//     int ans = 0;
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             ans = max(ans,num[i]^num[j]);
//     cout<<ans<<endl;
//     return 0;
// }
