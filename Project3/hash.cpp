#include <iostream>
#include <vector>
#include <list>
#include <functional>

using namespace std;

template<typename K, typename V>
class HashTable
{
private:
    // 桶数组：每个桶是一个链表（链地址法解决哈希冲突）
    vector<list<pair<K, V>>> buckets;
    int _size;
    hash<K> hash_fn;  // C++标准哈希函数对象
    // 哈希函数 → 桶索引：先 hash 再取模，确保落在 [0, buckets.size()-1]
    int get_bucket_index(const K& key) const
    {
        return hash_fn(key) % buckets.size();
    }
public:
    HashTable(int capacity = 16) : buckets(capacity), _size(0) {}
    // 插入 / 更新：键已存在则覆盖值，否则追加到链表尾部
    void put(const K& key, const V& value)
    {
        int index = get_bucket_index(key);
        for (auto& pair : buckets[index])
        {
            if (pair.first == key)
            {
                pair.second = value;  // 键已存在 → 更新
                return;
            }
        }
        buckets[index].push_back({ key, value });  // 键不存在 → 新增节点
        _size++;
    }
    // 查找：通过输出参数 value 返回结果，返回是否找到
    bool get(const K& key, V& value) const
    {
        int index = get_bucket_index(key);
        for (const auto& pair : buckets[index])
        {
            if (pair.first == key)
            {
                value = pair.second;
                return true;
            }
        }
        return false;
    }
    // 删除：遍历链表找到后 erase，注意 erase 后迭代器失效要立即 return
    bool remove(const K& key)
    {
        int index = get_bucket_index(key);
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it)
        {
            if (it->first == key)
            {
                buckets[index].erase(it);  // 从链表中移除
                _size--;
                return true;
            }
        }
        return false;
    }
    int size() const
    {
        return _size;
    }
};
int main()
{
    HashTable<string, int> ht;
    ht.put("apple", 5);
    ht.put("banana", 3);
    ht.put("cherry", 8);
    int val;
    if (ht.get("banana", val))
    {
        cout << "banana -> " << val << endl;
    }
    ht.remove("apple");
    cout << "size: " << ht.size() << endl;
    return 0;
}