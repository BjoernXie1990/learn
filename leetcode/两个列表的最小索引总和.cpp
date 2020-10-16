class Solution {
public:
    struct node {
        node* _son[55];
        int _index;
        node() {
            for(int i = 0; i < 55; i++)    _son[i] = nullptr;
            _index = -1;
        }
    };

    node* root;

    inline int GetIdx(char ch) {
        if(ch == ' ') return 26 * 2;
        else if(ch <= 'Z' && ch >= 'A') return ch - 'A';

        return 26 + ch - 'a';
    }

    void insert(const string& str,int idx) {
        int n = str.size();
        node* cur = root;
        for(int i = 0; i < n; i++) {
            int p = GetIdx(str[i]);
            if(cur->_son[p] == nullptr)    cur->_son[p] = new node();
            
            cur = cur->_son[p];
        }
        cur->_index = idx;
    }

    bool check(const string& str,int& idx) {
        int n = str.size();
        node* cur = root;
        for(int i = 0; i < n; i++) {
            int p = GetIdx(str[i]);
            if(cur->_son[p] == nullptr) return false;

            cur = cur->_son[p];
        }
        if(cur->_index == -1) return false;

        idx = cur->_index;
        return true;
    }

    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        root = new node();
        for(int i = 0; i < list1.size(); i++) insert(list1[i],i);
        
        vector<string> ans;
        int minN = INT_MAX;
        for(int i = 0; i < list2.size(); i++) {
            int idx = -1;
            if(check(list2[i],idx) == true){
                if(idx + i <= minN) {
                    if(idx + i < minN) ans.clear(), minN = idx + i;
                    ans.push_back(list2[i]);
                }
            } 
        }

        return ans;
    }
};

����Andy��Doris�������ʱѡ��һ�Ҳ������������Ƕ���һ����ʾ��ϲ���������б�ÿ���������������ַ�����ʾ��

����Ҫ�������������ٵ��������ҳ����ǹ�ͬϲ���Ĳ����� ����𰸲�ֹһ������������д𰸲��Ҳ�����˳�� ����Լ������Ǵ���һ���𰸡�

ʾ�� 1:

����:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
���: ["Shogun"]
����: ����Ψһ��ͬϲ���Ĳ����ǡ�Shogun����
ʾ�� 2:

����:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
���: ["Shogun"]
����: ���ǹ�ͬϲ���Ҿ�����С�����͵Ĳ����ǡ�Shogun����������С��������1(0+1)��
��ʾ:

�����б�ĳ��ȷ�Χ����?[1, 1000]�ڡ�
�����б��е��ַ����ĳ��Ƚ���[1��30]�ķ�Χ�ڡ�
�±��0��ʼ�����б�ĳ��ȼ�1��
�����б�û���ظ���Ԫ�ء�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
