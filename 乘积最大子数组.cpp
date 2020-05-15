//����һ���������� nums?�������ҳ������г˻��������������飨�������������ٰ���һ�����֣��������ظ�����������Ӧ�ĳ˻���

//?

//ʾ�� 1:

//����: [2,3,-2,4]
//���: 6
//����:?������ [2,3] �����˻� 6��
//ʾ�� 2:

//����: [-2,0,-1]
//���: 0
//����:?�������Ϊ 2, ��Ϊ [-2,-1] ���������顣


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len < 1) return 0;
        
        int Nmax = nums[0];
        int Nmin = nums[0];
        int ans = nums[0];

        for(int i = 1; i < len; i++)
        {
            int n = nums[i];
            int tmp = Nmax;

            //��ֹ�����������������
            Nmax = max(max(n*Nmax,n),Nmin*n);
            //���ǰ��ֻ��һ����������ô���Nmin����Сֵ��i����һ��ʱ������
            //����������ķ�Χһ���Ǵ���һ����������ת�ƹ�����
            Nmin = min(min(n*tmp,n),Nmin*n);

            ans = max(Nmax,ans);
        }

        return ans;
    }
};
