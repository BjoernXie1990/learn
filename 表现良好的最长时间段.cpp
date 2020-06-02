//����һ�ݹ���ʱ���?hours�������¼��ĳһλԱ��ÿ��Ĺ���Сʱ����

//������Ϊ��Ա��һ���еĹ���Сʱ������?8 Сʱ��ʱ����ô��һ����ǡ����۵�һ�졹��

//��ν���������õ�ʱ��Ρ�����ζ�����ʱ���ڣ������۵����������ϸ� ���ڡ������۵���������

//���㷵�ء���������ʱ��Ρ�����󳤶ȡ�

//?

//ʾ�� 1��

//���룺hours = [9,9,6,0,6,6,9]
//�����3
//���ͣ���ı�������ʱ����� [9,9,6]��

class Solution {
public:
    int longestWPI1(vector<int>& hours) {
        int len = hours.size(); 

        vector<int> arr(len,0);
        int sum = 0;
        for(int i = 0; i < len; i++)
        {
            sum += (hours[i]>8 ? 1 : -1);
            arr[i] = sum;
        }

        int ans = 0;
        for(int i = 0; i < len - ans; i++)
            for(int j = i + ans; j < len; j++)
            {
                if(i == 0)
                {
                    if(arr[j] > 0) ans = max(ans,j+1);
                }
                else if(arr[j] - arr[i-1] > 0)
                    ans = max(ans,j-i+1);
            }
        return ans;
    }

    int longestWPI(vector<int>& hours)
    {
        unordered_map<int,int> map;//��¼���� cur<1����С�±�
        int len = hours.size();
        int ans = 0;
        int cur = 0;
        for(int i = 0; i < len; i++)
        {
            cur += (hours[i] > 8) ? 1 : -1;
            if(cur > 0) 
                ans = i + 1;
            else
            {
                //map[cur-1] --> map[j] ��ʾ��0 -�� j ������cur-1�����
                // cur - (cur-1) == 1 > 0 ���������������Ҫ�жϵ�
                if(map.count(cur-1)) ans = max(ans,i - map[cur-1]);
                //���֮ǰû�г���cur�����������cur
                if(map.count(cur) < 1) map[cur] = i;
            }
        }
        return ans;
    }
};
