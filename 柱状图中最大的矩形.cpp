//���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��

//���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������

//?



//��������״ͼ��ʾ��������ÿ�����ӵĿ��Ϊ 1�������ĸ߶�Ϊ?[2,1,5,6,2,3]��

//?



//ͼ����Ӱ����Ϊ���ܹ��ճ�������������������Ϊ?10?����λ��

//?

//ʾ��:

//����: [2,1,5,6,2,3]
//���: 10



class Solution {
public:
    //�����ⷨ ʱ�临�Ӷ�O(N * N)
    int largestRectangleArea1(vector<int>& heights) {
        int ret = 0;

        for(int i = 0; i < heights.size(); i++)
        {
            int left = i;
            int right = i;

            //��ߵ�һ������С�ĸ߶�
            while(left > 0 && heights[left-1] >= heights[i])
                left--;
            
            //�ұߵ�һ������С�ĸ߶�
            while(right < heights.size()-1 && heights[right+1] >= heights[i])
                right++;
            
            int area = (right-left+1) * heights[i];
            //cout<<left<<' '<<right<<' '<<area<<endl;
            ret = max(area,ret);
        }
        return ret;
    }

    //����ջ + ǰ���ڱ�λ
    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> st;
        int ret = 0;
        //ǰ���0����ֹ�����������͵����ݼ������
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        int len = heights.size();
        for(int i = 0; i < len; i++)
        {
            while(!st.empty() && heights[i] < heights[st.top()])
            {
                //����ջ��Ԫ�ؿ��Թ��ճ����ε����
                int top = st.top();
                st.pop();
                //i-top ���Ǿ��εĿ����εĸ߶�Ϊջ��Ԫ�ص��±�������ĵ�����
                int area = (i - st.top() - 1) * heights[top];
                ret = max(ret,area);
            }
            st.push(i);
        }

        return ret;
    }
};
