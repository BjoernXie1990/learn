���и���һ�� n_rows �� n_cols �еĶ�ά����������ֵ����ʼ��Ϊ 0��Ҫ���дһ�� flip ��������������Ľ������е� 0 ��Ϊ 1�������ظ�ֵ��λ���±� [row_id,col_id]��ͬ����дһ�� reset �����������е�ֵ��������Ϊ 0���������ٵ���������� Math.random()�������Ż�ʱ��Ϳռ临�Ӷȡ�

ע��:

1 <= n_rows, n_cols <= 10000
0 <= row.id < n_rows ���� 0 <= col.id < n_cols
��������û��ֵΪ 0 ʱ�������Ե��� flip ����
���� flip �� reset �����Ĵ������������ᳬ�� 1000 ��
ʾ�� 1��

����: 
["Solution","flip","flip","flip","flip"]
[[2,3],[],[],[],[]]
���: [null,[0,1],[1,2],[1,0],[1,1]]
ʾ�� 2��

����: 
["Solution","flip","flip","reset","flip"]
[[1,2],[],[],[],[]]
���: [null,[0,0],[0,1],null,[0,0]]
�����﷨���ͣ�

������������б������õ��ӳ�������ǵĲ�����Solution �Ĺ��캯���������������ֱ�Ϊ n_rows �� n_cols��flip?�� reset û�в����������ܻ����б���ʽ���������¸��б�Ϊ��


class Solution {
public:
    Solution(int n_rows, int n_cols) {
        _n = n_rows;
        _m = n_cols;
        _num = _n * _m;
    }
    
    vector<int> flip() {
        if(_num == 0) return {};

        int mul = _n * _m;
        while(true){
            int idx = rand() % mul;
            if(_set.count(idx) > 0){
                continue;
            }

            int x = idx / _m;
            int y = idx % _m;
            _set.insert(idx);
            return {x,y};
        }
    }
    
    void reset() {
        _num = _n * _m;
        _set.clear();
    }
private:
    unordered_set<int> _set;
    int _n;
    int _m;
    int _num;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
