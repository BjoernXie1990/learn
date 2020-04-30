//����һ����������?arr ��һ��Ŀ��ֵ?target �����㷵��һ������?value?��ʹ�ý����������д���?value ��ֵ���?value ������ĺ���ӽ�? target?����ӽ���ʾ����֮��ľ���ֵ��С����

//����ж���ʹ�ú���ӽ�?target?�ķ��������㷵����Щ�����е���Сֵ��

//��ע�⣬�𰸲�һ����?arr �е����֡�

//?

//ʾ�� 1��

//���룺arr = [4,9,3], target = 10
//�����3
//���ͣ���ѡ�� value Ϊ 3 ʱ��������� [3, 3, 3]����Ϊ 9 ��������ӽ� target �ķ�����
//ʾ�� 2��

//���룺arr = [2,3,5], target = 10
//�����5
//ʾ�� 3��

//���룺arr = [60864,25176,27249,21296,20204], target = 56803
//�����11361

class Solution {
public:
    //͵�����ˡ���������
    int findBestValue1(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int len = arr.size();
        int sum = 0;//����С������֮��
        int ans = 0;
        int tmp = INT_MAX;
        //ֱ�ӱ����������еĺ��ʵ�ֵ
        for(int i = 0; i < len; i++) {
            int count = sum + arr[i] * (len - i);
            if(abs(count - target) < tmp) {
                ans = arr[i];
                tmp = abs(count - target);
            }
            sum += arr[i];
        }

        //�жϲ��������е���
        int num = target / len;
        for(int i = num; i < arr[2]; i++) {
            //�������е�һ�����������
            int count = 0;
            for(int j = 0; j < len; j++) {
                if(arr[j] >= i){
                    count += i * (len - j);
                    break;
                }
                count += arr[j];
            }
            if(abs(count - target) < tmp) {
                ans = i;
                tmp = abs(count - target);
            }
        }
        return ans;
    }

    //����д��
    int findBestValue (vector<int>& arr, int target) {
        int len = arr.size();
        int left = target/len;
        int right = INT_MIN;

        //ȷ��һ����ֵ�ı߽�
        for(auto& eoch : arr) {
            left = min(left,eoch);
            right = max(right,eoch);
        }
        //���ѡ��һ����ֵ value ��ʹ������Ӧ�� sum �ǵ� 1 �����ڵ��� target �ģ���ôĿ��ֵ������ value Ҳ������ value - 1��
        while(left < right) {
            int mid = (left + right)>>1;
            int sum = Judge(arr,mid);
            if(sum < target) left = mid + 1;//С�ڵ�һ��������ӽ��Ľ�
            else if(sum >= target) right = mid;
        }

        int sum1 = Judge(arr,left-1);
        int sum2 = Judge(arr,left);
        if(target-sum1 <= sum2 - target) return left-1;
        
        return left;
    }

    int Judge(vector<int>& arr,int pos) {
        int sum = 0;
        for (int num : arr) {
            sum += min(num, pos);
        }
        return sum;
    }
};
