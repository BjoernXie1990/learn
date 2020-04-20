//����ÿ�� ���� �б�����������һ���б���Ӧλ�õ��������Ҫ�ٵȴ�����¶ȲŻ����߳������յ����������֮�󶼲������ߣ����ڸ�λ����?0 �����档

//���磬����һ���б�?temperatures = [73, 74, 75, 71, 69, 72, 76, 73]��������Ӧ����?[1, 1, 4, 2, 1, 1, 0, 0]��

//��ʾ������ �б��ȵķ�Χ��?[1, 30000]��ÿ�����µ�ֵ�ľ�Ϊ���϶ȣ�������?[30, 100]?��Χ�ڵ�������

class Solution {
public:
    //��ʱ
    vector<int> dailyTemperatures1(vector<int>& T){
        int len = T.size();
        vector<int> ans(len,0);

        for(int i = 0; i < len; i++){
            int count = T[i];
            for(int j = i + 1; j < len; j++){
                if(T[j] > count){
                    ans[i] = j - i;
                    break;
                }
            }
        }

        return ans;
    }
    //����ջ
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        int len = T.size();
        vector<int> ans(len,0);

        for(int i = 0; i < len; i++){
            while(!st.empty() && T[i] > T[st.top()]){
                int ret = st.top();
                st.pop();
                ans[ret] = i - ret;
            }
            st.push(i);
        }

        return ans;
    }
};
