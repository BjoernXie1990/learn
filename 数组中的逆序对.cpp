//�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ�����飬�����������е�����Ե�������

//?

//ʾ�� 1:

//����: [7,5,6,4]
//���: 5


class Solution {
public:
    //�鲢����
    int reversePairs(vector<int>& nums) {
        vector<int> copy = nums;
        int len = nums.size();
        vector<int> tmp(len,0);

        return MergerSlove(copy, 0, len-1, tmp);
    }

    int MergerSlove(vector<int>& copy, int left, int right, vector<int>& tmp){
        //�ų�ֻ��һ����������û���������
        if(left >= right)
            return 0;

        int mid = (left + right) / 2;
        int leftNum = MergerSlove(copy, left, mid, tmp);//�����������
        int rightNum = MergerSlove(copy, mid + 1, right, tmp);//�ұ���������
       
        //���˳��ϲ�������������䣬�Ͳ��úϲ���
        if(copy[mid] <= copy[mid+1])
            return leftNum + rightNum;
        int mergeNum = MergerAllSlove(copy, left, mid, right, tmp);//�ϲ���������

        return leftNum + rightNum + mergeNum;
    }

    int MergerAllSlove(vector<int>& copy, int left, int mid, int right, vector<int>& tmp){
        for(int i = left; i <= right; i++)
            tmp[i] = copy[i];
        
        int l = left;
        int r = mid + 1;
        int count = 0;

        for(int i = left; i <= right; i++){
            if(l == mid + 1)//�������Ԫ�غϲ����
                copy[i] = tmp[r++];
            else if(r == right + 1)//�ұ�����Ԫ�غϲ����
                copy[i] = tmp[l++];
            else if(tmp[l] <= tmp[r])//���Ԫ�� С�ڵ��� �ұ�Ԫ�أ����ṹ�������
                copy[i] = tmp[l++];
            else{//���Ԫ�ش����ұ�Ԫ�أ����������
                copy[i] = tmp[r++];
                count += (mid - l + 1); //��ǰ����Ԫ�صĺ����ж��ٸ���������Ԫ�أ�+1����Ϊ����͹�����һ�������
            }
        }

        return count;
    }
};
