
����һ���Ǹ���������������Խ���һ�������е�������λ���������ܵõ������ֵ��

ʾ�� 1 :

����: 2736
���: 7236
����: ��������2������7��
ʾ�� 2 :

����: 9973
���: 9973
����: ����Ҫ������
ע��:

�������ֵķ�Χ��?[0, 108]


class Solution {
public:
    int maximumSwap(int num) {
        string cur = to_string(num);
        string tmp(cur);
        int n = cur.size();

        sort(tmp.begin(),tmp.end(),[](const char a,const char b)->bool{
            return a > b;
        });

        int p = -1;//��һ�����ϵ�λ��
        for(int i = 0; i < n; i++) {
            if(tmp[i] != cur[i]) {
                p = i;
                break;
            }
        }

        if(p == -1) return num;

        for(int i = n-1; i > p; i--) {
            if(cur[i] == tmp[p]) {
                swap(cur[i],cur[p]);
                break;
            }
        }
        return stoi(cur);
    }
};
