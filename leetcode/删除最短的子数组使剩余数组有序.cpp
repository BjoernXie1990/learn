����һ���������� arr?������ɾ��һ�������飨����Ϊ�գ���ʹ�� arr?��ʣ�µ�Ԫ���� �ǵݼ� �ġ�

һ��������ָ����ԭ������������һ�������С�

���㷵��������ĿҪ������������ĳ��ȡ�

?

ʾ�� 1��

���룺arr = [1,2,3,10,4,2,3,5]
�����3
���ͣ�������Ҫɾ��������������� [10,4,2] ������Ϊ 3 ��ʣ��Ԫ���γɷǵݼ����� [1,2,3,3,5] ��
��һ����ȷ�Ľ�Ϊɾ�������� [3,10,4] ��
ʾ�� 2��

���룺arr = [5,4,3,2,1]
�����4
���ͣ������������ϸ�ݼ��ģ�����ֻ�ܱ���һ��Ԫ�ء�����������Ҫɾ������Ϊ 4 �������飬Ҫôɾ�� [5,4,3,2]��Ҫôɾ�� [4,3,2,1]��
ʾ�� 3��

���룺arr = [1,2,3]
�����0
���ͣ������Ѿ��Ƿǵݼ����ˣ����ǲ���Ҫɾ���κ�Ԫ�ء�
ʾ�� 4��

���룺arr = [1]
�����0
?

��ʾ��

1 <= arr.length <= 10^5
0 <= arr[i] <= 10^9

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int le = -1;
        int ri = -1;
        
        for(int i = 0; i < n - 1; i++) {
            if(arr[i] > arr[i+1]) {
                le = i;
                break;
            }
        }
        if(le == -1) return 0;//�ϸ����
        
        for(int i = n - 1; i > 0; i--) {
            if(arr[i] < arr[i-1]) {
                ri = i;
                break;
            }
        }
        
        int start = le;
        int end = ri;
        for(; start >= 0; start--) {
            if(arr[start] <= arr[ri]) {
                break;
            }
        }
        //if(start == -1) return ri;
        
        for(; end < n; end++) {
            if(arr[end] >= arr[le]) {
                break;
            }
        }
        //if(end == n)  return n - le - 1;
        
        return min(min(ri - start - 1,ri),min(end - le - 1,n - le - 1));
    }
};
