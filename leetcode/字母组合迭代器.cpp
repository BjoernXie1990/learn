�������һ���������࣬�����������ݣ�

һ�����캯�����������������һ��?�������ַ�Ψһ?���ַ���?characters�����ַ���ֻ����СдӢ����ĸ����һ������?combinationLength?��
����?next()?����?�ֵ���?���س���Ϊ?combinationLength ����һ����ĸ��ϡ�
����?hasNext()?��ֻ�д��ڳ���Ϊ?combinationLength ����һ����ĸ���ʱ���ŷ���?True�����򣬷��� False��
?

ʾ����

CombinationIterator iterator = new CombinationIterator("abc", 2); // ���������� iterator

iterator.next(); // ���� "ab"
iterator.hasNext(); // ���� true
iterator.next(); // ���� "ac"
iterator.hasNext(); // ���� true
iterator.next(); // ���� "bc"
iterator.hasNext(); // ���� false
?

��ʾ��

1 <= combinationLength <=?characters.length <= 15
ÿ���������������?10^4?�κ������á�
��Ŀ��֤ÿ�ε��ú���?next?ʱ��������һ����ĸ��ϡ�


class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        str = characters;
        len = combinationLength;
        dfs("",0,0,len);
        index = 0;
    }
    
    string next() {
        return ans[index++];
    }
    
    bool hasNext() {
        return index != ans.size();
    }
private:
    void dfs(string s,int idx,int size,int len)
    {
        if(size == len)
        {
            ans.push_back(s);
            return ;
        }

        for(int i = idx; i <= str.size() - len + size; i++)
            dfs(s + str[i],i+1,size+1,len);
    }
private:
    vector<string> ans;
    string str;
    int len;
    int index;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
