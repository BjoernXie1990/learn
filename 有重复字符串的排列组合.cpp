//���ظ��ַ�����������ϡ���дһ�ַ���������ĳ�ַ���������������ϡ�

//ʾ��1:

// ���룺S = "qqe"
// �����["eqq","qeq","qqe"]
//ʾ��2:

// ���룺S = "ab"
// �����["ab", "ba"]



class Solution {
public:
    vector<string> permutation(string S) {
        vector<string> ans;
        int len = S.size();
        sort(S.begin(),S.end());//���򣬱�֤��ͬ���ַ�������һ��
        dfs(ans,S,0,len);
        return ans;
    }

    void dfs(vector<string>& ans, string& S,int index,int len) {
        //�ж��Ƿ�Խ��
        if(index == len) {
            string tmp = S;
            ans.push_back(tmp);
            return;
        }

        for(int i = index; i < len; i++) {
            //�ų���ͬ�ַ��������,�����Ǻ���ʼλ����ͬ��Ҳ�����Ǻ�ǰһ��λ����ͬ
            if(i > index && 
                (S[i] == S[index] || S[i] == S[i-1]) ) continue;
            swap(S[i],S[index]);//����
            dfs(ans,S,index+1,len);
            swap(S[i],S[index]);//����
        }
    }
};
