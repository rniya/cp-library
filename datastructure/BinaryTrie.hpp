/**
 * @brief Binary Trie
 * @docs docs/datastructure/BinaryTrie.md
 */

#pragma once

#include "../base.hpp"

template<typename T,int MAX_LOG>
class BinaryTrie{
    struct Node{
        int cnt;
        Node *ch[2];
        Node():cnt(0),ch{nullptr,nullptr}{}
    };
    Node *root;
    Node *add(Node *node,T val,int b=MAX_LOG-1){
        if (!node) node=new Node;
        node->cnt+=1;
        if (b<0) return node;
        bool f=(val>>(T)b)&(T)1;
        node->ch[f]=add(node->ch[f],val,b-1);
        return node;
    }
    Node *sub(Node *node,T val,int b=MAX_LOG-1){
        node->cnt-=1;
        if (node->cnt==0) return nullptr;
        if (b<0) return node;
        bool f=(val>>(T)b)&(T)1;
        node->ch[f]=sub(node->ch[f],val,b-1);
        return node;
    }
    T get_min(Node *node,T val,int b=MAX_LOG-1) const {
        if (b<0) return 0;
        bool f=(val>>(T)b)&(T)1; f^=!node->ch[f];
        return get_min(node->ch[f],val,b-1)|(T)f<<(T)b;
    }
    T get(Node *node,int k,int b=MAX_LOG-1) const {
        if (b<0) return 0;
        int m=node->ch[0]?node->ch[0]->cnt:0;
        return k<m?get(node->ch[0],k,b-1):get(node->ch[1],k-m,b-1)|(T)1<<(T)b;
    }
    int count_lower(Node *node,T val,int b=MAX_LOG-1){
        if (!node||b<0) return 0;
        bool f=(val>>(T)b)&(T)1;
        return (f&&node->ch[0]?node->ch[0]->cnt:0)+count_lower(node->ch[f],val,b-1);
    }

public:
    BinaryTrie():root(nullptr){}
    int size() const {return root?root->cnt:0;}
    bool empty() const {return !root;}
    void insert(T val){root=add(root,val);}
    void erase(T val){root=sub(root,val);}
    T max_element(T bias=0) const {return get_min(root,~bias);}
    T min_element(T bias=0) const {return get_min(root,bias);}
    int lower_bound(T val){return count_lower(root,val);}
    int upper_bound(T val){return count_lower(root,val+1);}
    T operator[](int k) const {return get(root,k);}
    int count(T val) const {
        if (!root) return 0;
        Node *node=root;
        for (int i=MAX_LOG-1;i>=0;--i){
            node=node->ch[(val>>(T)i)&(T)1];
            if (!node) return 0;
        }
        return node->cnt;
    }
};