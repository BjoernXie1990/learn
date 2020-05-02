//����һ������ nums����һ����СΪ?k?�Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k?�����֡���������ÿ��ֻ�����ƶ�һλ��

//���ػ��������е����ֵ��

//?

//���ף�

//����������ʱ�临�Ӷ��ڽ��������

//?

//ʾ��:

//����: nums = [1,3,-1,-3,5,3,6,7], �� k = 3
//���: [3,3,5,5,6,7] 
//����: 

//  �������ڵ�λ��                ���ֵ
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7



class Solution {
public:
    ��������
    class priorityQueue {
        public:
            void push(int num) {
                //����һ��Ԫ�ص�ʱ��ǰ�����С��Ԫ�ؾ�û��Ҫ������
                //β�巨
                while(!data.empty() && data.back() < num)
                    data.pop_back();
                data.push_back(num);
            }
            //���ֵ��Ϊ���Ԫ��
            int max() {
                return data.front();
            }

            void pop(int num) {
                //��������pop�ǽ�����num�ǵ�ǰ��������Ԫ��
                //��Ϊ����С��Ԫ���ڲ����ʱ���ɾ����
                if(!data.empty() && data.front() == num)
                    data.pop_front();//ͷɾ
            } 
        private:
            deque<int> data;
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priorityQueue window;
        vector<int> ans;
        //�Ȱ�ǰk-1��Ԫ�ز������
        for(int i = 0; i < k - 1; i++)
            window.push(nums[i]);
        //��ʼ��������
        for(int i = k-1; i < nums.size(); i++) {
            window.push(nums[i]);
            ans.push_back(window.max());
            window.pop(nums[i-k+1]);//�����߼��ϵ�һ��Ԫ�س���
        }
        return ans;
    }
};
