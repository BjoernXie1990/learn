����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������������򷵻�?true�����򷵻�?false���������������������������ֶ�������ͬ��

?

�ο�������Ŷ�����������

     5
    / \
   2   6
  / \
 1   3
ʾ�� 1��

����: [1,6,3,2,5]
���: false
ʾ�� 2��

����: [1,3,2,6,5]
���: true
?

��ʾ��

���鳤�� <= 1000

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        
        return dfs(postorder,0,n-1);
    }

    bool dfs(vector<int>& arr,int le,int ri){
        if(le >= ri)    return true;

        int idx = le;
        while(idx < ri && arr[idx] < arr[ri]){
            idx++;
        }

        // [le,idx) left
        // [idx,ri-1] right
        for(int i = idx + 1; i < ri; i++){
            if(arr[i] < arr[ri])    return false;
        }

        return dfs(arr,le,idx-1) && dfs(arr,idx,ri-1);
    }
};
