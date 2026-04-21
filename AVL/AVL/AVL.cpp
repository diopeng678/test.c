#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<map>
#include<assert.h>
using namespace std;

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
    //插入接口
    bool Insert(const pair<K, V>& kv)
    {
        //判断是否为空
        if (_root == nullptr)
        {
            _root = new Node(kv);
            return true;
        }
        Node* parent = nullptr;
        Node* cur = _root;
		//找到插入位置 确定父节点
        while (cur)
        {
            if (kv.first < cur->_kv.first)
            {
                parent = cur;
                cur = cur->_left;
            }
			else if (kv.first > cur->_kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else
            {
                return false; //不允许插入重复的key
            }
        }
		//将新节点插入到父节点的左子树或右子树
        cur = new Node(kv);
        if ( parent->_kv.first < kv.first)
        {
            parent->_right= cur;
        }
        else
        {
            parent->_left = cur;
        }
        cur->_parent = parent;

		//更新平衡因子
        while (parent)
        {
            if (cur == parent->_left)
            {
                parent->_bf++;
            }
            else
            {
                parent->_bf--;
            }

            if (parent->_bf == 0)
            {
                break;
            }

            if (parent->_bf == 1 || parent->_bf == -1)
            {
                cur = parent;
                parent = parent->_parent;
            }
            else if (parent->_bf == 2 || parent->_bf == -2)
            {
                break;
            }
            else
            {
                assert(false);
            }
        }

        return true;
        
    }
};
//我操了 这么难

int main()
{
    AVLTree<int, int> avl;
    avl.Insert(make_pair(1, 1));
    avl.Insert(make_pair(2, 2));
    avl.Insert(make_pair(3, 3));
    avl.Insert(make_pair(4, 4));
    avl.Insert(make_pair(5, 5));
    
    return 0;
}