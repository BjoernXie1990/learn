//����һ���б�?nums?������ÿһ��Ԫ�ض���һ�������б��������������ͼ�Ĺ��򣬰�˳�򷵻�?nums?�жԽ����ϵ�������

//?

//ʾ�� 1��



//���룺nums = [[1,2,3],[4,5,6],[7,8,9]]
//�����[1,4,2,7,5,3,8,6,9]
//ʾ�� 2��



//���룺nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
//�����[1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
//ʾ�� 3��

//���룺nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
//�����[1,4,2,5,3,8,6,9,7,10,11]
//ʾ�� 4��

//���룺nums = [[1,2,3,4,5,6]]
//�����[1,2,3,4,5,6]



class Solution {
public:
    //�Խ���Ԫ�أ��к�+�кŵ�ֵ���
    vector<int> tmp[200500];
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++){
            for(int j = 0; j < nums[i].size(); j++)
                tmp[i+j].push_back(nums[i][j]);
        }

        vector<int> ans;
        for(int i = 0; i < 200500; i++){
            int num = tmp[i].size();
            if(num == 0) continue;
            for(int j = num-1; j >= 0; j--)
                ans.push_back(tmp[i][j]);
        }
        
        return ans;
    }
};
