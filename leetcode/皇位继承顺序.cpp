class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        um[kingName] = {};
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        um[parentName].push_back(childName);
        um[childName] = {};
    }
    
    void death(string name) {
        dus.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(ans,king);
        return ans;
    }
private:
    void dfs(vector<string>& ans,string& fa) {
        if(dus.find(fa) == dus.end()) ans.push_back(fa);

        for(auto& child : um[fa]) {
            dfs(ans,child);
        }
    }

private:
    unordered_map<string,vector<string> > um;
    unordered_set<string> dus;
    string king;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
 
 
 һ��������ס�Ź��������ĺ����ǡ����������ǵȵȡ�ÿһ��ʱ��㣬�����ͥ�����˳���Ҳ����������

���������һ����ȷ�涨�Ļ�λ�̳�˳�򣬵�һ�̳������ǹ����Լ������Ƕ���ݹ麯��?Successor(x, curOrder)?������һ����?x?�͵�ǰ�ļ̳�˳�򣬸ú������� x?����һ�̳��ˡ�

Successor(x, curOrder):
    ��� x û�к��ӻ������� x �ĺ��Ӷ��� curOrder �У�
        ��� x �ǹ�������ô���� null
        ���򣬷��� Successor(x �ĸ���, curOrder)
    ���򣬷��� x ���� curOrder �����곤�ĺ���
�ȷ�˵�����������ɹ��������ĺ���?Alice �� Bob ��Alice �� Bob?�곤���� Alice �ĺ���?Jack ��ɡ�

һ��ʼ��?curOrder?Ϊ?["king"].
����?Successor(king, curOrder)?������ Alice ���������ǽ� Alice ���� curOrder?�У��õ�?["king", "Alice"]?��
����?Successor(Alice, curOrder)?������ Jack ���������ǽ� Jack ����?curOrder?�У��õ�?["king", "Alice", "Jack"]?��
����?Successor(Jack, curOrder)?������ Bob ���������ǽ� Bob ����?curOrder?�У��õ�?["king", "Alice", "Jack", "Bob"]?��
����?Successor(Bob, curOrder)?������?null?�����յõ��̳�˳��Ϊ?["king", "Alice", "Jack", "Bob"]?��
ͨ�����ϵĺ��������������ܵõ�һ��Ψһ�ļ̳�˳��

����ʵ��?ThroneInheritance?�ࣺ

ThroneInheritance(string kingName) ��ʼ��һ��?ThroneInheritance?��Ķ��󡣹�����������Ϊ���캯���Ĳ������롣
void birth(string parentName, string childName)?��ʾ?parentName?��ӵ����һ����Ϊ?childName?�ĺ��ӡ�
void death(string name)?��ʾ��Ϊ?name?����������һ���˵���������Ӱ��?Successor?������Ҳ����Ӱ�쵱ǰ�ļ̳�˳�������ֻ������˱��Ϊ����״̬��
string[] getInheritanceOrder()?���� ��ȥ?������Ա�ĵ�ǰ�̳�˳���б�
?

ʾ����

���룺
["ThroneInheritance", "birth", "birth", "birth", "birth", "birth", "birth", "getInheritanceOrder", "death", "getInheritanceOrder"]
[["king"], ["king", "andy"], ["king", "bob"], ["king", "catherine"], ["andy", "matthew"], ["bob", "alex"], ["bob", "asha"], [null], ["bob"], [null]]
�����
[null, null, null, null, null, null, null, ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"], null, ["king", "andy", "matthew", "alex", "asha", "catherine"]]

���ͣ�
ThroneInheritance t= new ThroneInheritance("king"); // �̳�˳��king
t.birth("king", "andy"); // �̳�˳��king > andy
t.birth("king", "bob"); // �̳�˳��king > andy > bob
t.birth("king", "catherine"); // �̳�˳��king > andy > bob > catherine
t.birth("andy", "matthew"); // �̳�˳��king > andy > matthew > bob > catherine
t.birth("bob", "alex"); // �̳�˳��king > andy > matthew > bob > alex > catherine
t.birth("bob", "asha"); // �̳�˳��king > andy > matthew > bob > alex > asha > catherine
t.getInheritanceOrder(); // ���� ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
t.death("bob"); // �̳�˳��king > andy > matthew > bob���Ѿ�ȥ����> alex > asha > catherine
t.getInheritanceOrder(); // ���� ["king", "andy", "matthew", "alex", "asha", "catherine"]
?

��ʾ��

1 <= kingName.length, parentName.length, childName.length, name.length <= 15
kingName��parentName��?childName?��?name?������СдӢ����ĸ��
���еĲ���?childName ��?kingName?������ͬ��
����?death?�����е��������� name?Ҫô�ǹ�����Ҫô���Ѿ������˵���Ա���֡�
ÿ�ε��� birth(parentName, childName) ʱ��������������֤ parentName ��Ӧ����Ա�ǻ��ŵġ�
������?105?��birth ��?death?��
������?10?��?getInheritanceOrder?��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/throne-inheritance
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
