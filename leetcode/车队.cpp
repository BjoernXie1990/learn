N ?��������һ������ʻ��λ��?target?Ӣ��֮��Ĺ�ͬĿ�ĵء�

ÿ����?i?�Ժ㶨���ٶ�?speed[i]?��Ӣ��/Сʱ�����ӳ�ʼλ��?position[i]?��Ӣ� �س���ʻ��Ŀ�ĵء�

һ������Զ���ᳬ��ǰ�����һ��������������׷��ȥ������ǰ������ͬ���ٶȽ�������ʻ��

��ʱ�����ǻ������������֮��ľ��룬Ҳ����˵�����Ǳ��ٶ�������ͬ��λ�á�

����?��һЩ����ʻ����ͬλ�á�������ͬ�ٶȵĳ���ɵķǿռ��ϡ�ע�⣬һ����Ҳ������һ�����ӡ�

����һ������Ŀ�ĵزŸ�����һ�����ӣ�������Ȼ�ᱻ������ͬһ�����ӡ�

?

���ж��ٳ��ӵ���Ŀ�ĵ�?

?

ʾ����

���룺target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
�����3
���ͣ�
�� 10 �� 8 ��ʼ�ĳ������һ�����ӣ������� 12 ��������
�� 0 ����ʼ�ĳ��޷�׷�����������������Լ�����һ�����ӡ�
�� 5 �� 3 ��ʼ�ĳ������һ�����ӣ������� 6 ��������
��ע�⣬�ڵ���Ŀ�ĵ�֮ǰû����������������Щ���ӣ����Դ��� 3��

��ʾ��

0 <= N <= 10 ^ 4
0 < target?<= 10 ^ 6
0 <?speed[i] <= 10 ^ 6
0 <= position[i] < target
���г��ĳ�ʼλ�ø�����ͬ��

class Solution {
public:
    using key = pair<int,double>;
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0)  return 0;
        vector<key> res(n);

        for(int i = 0; i < n; i++){
            res[i].first = position[i];
            res[i].second = (target - position[i]) / (double)speed[i];
        }
        sort(res.begin(),res.end(),[](const key& a,const key& b)->bool {
            return a.first > b.first;
        });

        int num = 1;
        double sign = res[0].second;
        for(int i = 1; i < n; i++) {
            if(res[i].second > sign) {
                num++;
                sign = res[i].second;
            }
        }
        return num;
    }
};
