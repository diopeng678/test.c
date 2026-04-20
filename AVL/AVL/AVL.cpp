#define _CRT_SECURE_NO_WARNINGS

template<class K, class V>
struct AVLTreeNode
{
    pair<K, V> _kv;
    AVLTreeNode<K, V>* _left;
    AVLTreeNode<K, V>* _right;
    AVLTreeNode<K, V>* _parent;
    int _bf;

    AVLTreeNode(const pair<K, V>& kv)
        :_kv(kv)
        , _left(nullptr)
        , _right(nullptr)
        , _parent(nullptr)
        , _bf(0)
    {
    }
};

template<class K, class V>
class AVLTree
{
    typedef AVLTreeNode<K, V> Node;
private:
    Node* _root = nullptr;
public:
    bool Insert(const pair<K, V>& kv);
    // 其他接口下篇实现
};
