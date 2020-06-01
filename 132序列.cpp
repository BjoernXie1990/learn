//����һ���������У�a1, a2, ..., an��һ��132ģʽ��������?ai, aj, ak?������Ϊ���� i < j < k ʱ��ai < ak < aj�����һ���㷨����������?n �����ֵ�����ʱ����֤����������Ƿ���132ģʽ�������С�

//ע�⣺n ��ֵС��15000��

//ʾ��1:

//����: [1, 2, 3, 4]

//���: False

//����: �����в�����132ģʽ�������С�
//ʾ�� 2:

//����: [3, 1, 4, 2]

//���: True

//����: �������� 1 ��132ģʽ�������У� [1, 4, 2].
//ʾ�� 3:

//����: [-1, 3, 2, 0]

//���: True

//����: �������� 3 ��132ģʽ�ĵ�������: [-1, 3, 2], [-1, 3, 0] �� [-1, 2, 0].

class Solution {
public:
    bool find132pattern1(vector<int>& nums) {
        stack<int> st;

        int two = INT_MIN;//��ʾ�ڶ���Ԫ��

        for(int i = nums.size()-1; i >= 0; i--)
        {
            int value = nums[i];
            if(value < two) return true;

            while(!st.empty() && value > st.top())
            {
                two = st.top();
                st.pop();
            }

            //��֤ջ���Ԫ����ջ�����¶��ǵ�����
            st.push(value);
        }
        return false;
    }
    bool find132pattern(vector<int>& nums)
    {
        int minNum = INT_MAX;

        for(int i = 0; i < nums.size(); i++)
        {
            minNum = min(minNum,nums[i]);
            if(minNum == nums[i]) continue;

            for(int j = nums.size()-1; j > i; j--)
                if(nums[i] > nums[j] && nums[j] > minNum)
                    return true;
        }

        return false;
    }
};
