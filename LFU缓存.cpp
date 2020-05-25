//����Ϊ �����ʹ�ã�LFU�������㷨��Ʋ�ʵ�����ݽṹ����Ӧ��֧�����²�����get?��?put��

//get(key)?- ����������ڻ����У����ȡ����ֵ�����������������򷵻� -1��
//put(key, value)?- ������Ѵ��ڣ�������ֵ������������ڣ�������ֵ�ԡ�������ﵽ������ʱ����Ӧ���ڲ�������֮ǰ��ʹ�����ʹ�õ�����Ч���ڴ������У�������ƽ�֣���������������������ͬʹ��Ƶ�ʣ�ʱ��Ӧ��ȥ�����δʹ�õļ���
//�����ʹ�ô����������Բ����������������� get �� put �����Ĵ���֮�͡�ʹ�ô������ڶ�Ӧ��Ƴ�����Ϊ 0 ��

//?

//���ף�
//���Ƿ������?O(1)?ʱ�临�Ӷ���ִ�����������

//?

//ʾ����

//LFUCache cache = new LFUCache( 2 /* capacity (��������) */ );

//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // ���� 1
//cache.put(3, 3);    // ȥ�� key 2
//cache.get(2);       // ���� -1 (δ�ҵ�key 2)
//cache.get(3);       // ���� 3
//cache.put(4, 4);    // ȥ�� key 1
//cache.get(1);       // ���� -1 (δ�ҵ� key 1)
//cache.get(3);       // ���� 3
//cache.get(4);       // ���� 4


struct node
{
    int _key;
    int _value;
    int _freq;//���ֵ�Ƶ��

    node(int key,int value,int _freq)
        :_key(key)
        ,_value(value)
        ,_freq(_freq)
    {}
};

class LFUCache {
public:
    LFUCache(int capacity) {
        freq_map.clear();
        key_map.clear();
        _minfreq = 0;
        _capacity = capacity;
    }
    ~LFUCache()
    {
        freq_map.clear();
        key_map.clear();
        _capacity = _minfreq = -1;
    }

    int get(int key) {
        //�������Ϊ0 ��ֱ���˳�
        if(_capacity == 0) return -1;

        //�����ǰֵ�����ڣ�Ҳֱ���˳�
        if(key_map.find(key) == key_map.end()) return -1;

        list<node>::iterator cur = key_map[key];
        int val = cur->_value;
        int freq = cur->_freq;
 
        //�Ƴ�key�Ľڵ㣬��freq��ʹ��Ƶ��������
        freq_map[freq].erase(cur);

        //�����ǰ����ɾ����Ϊ��
        if(freq_map[freq].size() == 0)
        {
            freq_map.erase(freq);
            if(_minfreq == freq) _minfreq++;
        }

        //����key�ĵ㵽 freq+1 �ĳ���Ƶ����,ͷ�巨
        freq_map[freq+1].push_front(node(key,val,freq+1));
        key_map[key] = freq_map[freq+1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if(_capacity == 0) return ;
        //�������Key
        if(key_map.find(key) != key_map.end())
        {
            list<node>::iterator cur = key_map[key];
            int freq = cur->_freq;
            freq_map[freq].erase(cur);

            if(freq_map[freq].size() == 0)
            {
                freq_map.erase(freq);
                if(_minfreq == freq) _minfreq++;
            }
            freq_map[freq+1].push_front(node(key,value,freq+1));
            key_map[key] = freq_map[freq+1].begin();
            return ;
        }

        //�˴��ǲ�����key����Ҫ��������
        if(key_map.size() == _capacity)
        {
            //�����Ѿ�����
            //ͨ����ǰ����С����Ƶ�ʣ��õ������β������
            node tail = freq_map[_minfreq].back();
            key_map.erase(tail._key);
            freq_map[_minfreq].pop_back();

            if(freq_map[_minfreq].size() == 0) freq_map.erase(_minfreq);
        }

        _minfreq = 1;//���µ�ǰ��С���ʴ���
        freq_map[_minfreq].push_front(node(key,value,1));//�½��ֵ������һ��
        key_map[key] = freq_map[_minfreq].begin();
    }
private:
    unordered_map<int,list<node> > freq_map; //�Գ��ֵ�Ƶ������ͼ
    unordered_map<int,list<node>::iterator> key_map; //ͨ��keyֵ�ҵ�����ڵ�ĵ�����
    int _minfreq;  //��ǰ��Сʹ�ô���
    int _capacity;//���� 
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
