//����һ���ַ��� S��һ���ַ��� T�������ַ��� S �����ҳ������� T ������ĸ����С�Ӵ���

//ʾ����

//����: S = "ADOBECODEBANC", T = "ABC"
//���: "BANC"
//˵����

//��� S �в����������Ӵ����򷵻ؿ��ַ��� ""��
//��� S �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�

class Solution {
public:
    string minWindow(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        vector<int> need(256,0);
        vector<int> n(256,0);

        //�ж���Ҫ���ַ���
        for(auto& eoch : t) need[eoch]++;
        //�ж���Ҫ���ַ�
        for(auto& eoch : t) n[eoch]++;
        vector<int> copy = need;

        int left = 0;
        int right = 0;
        int l,r;
        int ans = INT_MAX;
        int selNum = 0;//t�ַ�������ѡ���ַ���
        
        while(right < lens) {
            //�ƶ��Ҵ��ڣ���ȫ������t���ַ�Ϊֹ
            while(right < lens && selNum != lent) {
                if(need[s[right]]){
                    need[s[right]]--;
                    selNum++;
                }
                right++;
            }
            if(selNum != lent) break;
            else if(selNum == lent) right--;
            
            //��ʱ���ұ߽�һ����һ���Ϸ�������
            //�����󴰿�,������������
            vector<int> tmp = copy;
            left = right;
            int num = lent;
            while(num) {
                if(tmp[s[left]]) {
                    tmp[s[left]]--;
                    num--;
                }
                left--;
            }
            left++;//��left λ���ǵ�һ���Ϸ���λ��
            //������󳤶�
            if(ans > (right - left + 1)) {
                l = left;
                r = right;
                ans = r - l + 1;
            }

            //�����󴰿ڵ���һ�������Ҫ���ַ���
            need[s[left]]++;
            left++;
            while(left < right && n[s[left]])
                left++;
            left--;
            selNum--;
            right++;
        }

        return ans == INT_MAX ? "" : s.substr(l,r-l+1);
    }
};
