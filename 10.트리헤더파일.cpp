#ifndef _BIN_TREE_HPP_ //정의가 안되어있으면 가져갈수있음
#define _BIN_TREE_HPP_ //정의하는것

#include <string>
#include <stack>
#include <queue>
#include <iostream>

class BinTree;

class Node {
public:
    friend class BinTree;
    Node(int);
private:
    int data;
    Node* left;
    Node* right;
};

Node::Node(int v)
    :data(v), left(0), right(0) //초기화 리스트
{}

class BinTree {
public:
    BinTree();
    ~BinTree();
    void insert(int);
    void dfs(); //depth first search (깊이 우선 탐색) => 스택, 재귀
    void bfs(); //breadth first search (너비 우선 탐색) => 큐
    bool search(int);
    bool remove(int);
private:
    Node* root;
};

BinTree::BinTree()
    :root(0)
{}

BinTree::~BinTree()
{}

void BinTree::insert(int v)
{
    if (root == 0)
    {
        root = new Node(v);
    }
    else
    {
        Node* current = root;
        Node* parent = 0;

        while (current != 0)
        {
            parent = current;

            if (current->data > v)
            {
                current = current->left;
            }
            else if (current->data < v)
            {
                current = current->right;
            }
            else
            {
                throw std::string(std::to_string(v) + "is already existed.");
            }
        }

        if (parent->data > v)
            parent->left = new Node(v);
        else
            parent->right = new Node(v);
    }
}

void BinTree::dfs()
{
    std::stack<Node*> nst;
    nst.push(root);

    while (!nst.empty())
    {
        Node* nd = nst.top(); nst.pop();
        std::cout << nd->data << ' ';

        if (nd->right != 0)
            nst.push(nd->right);

        if (nd->left != 0)
            nst.push(nd->left);
    }
}

void BinTree::bfs()
{}

bool BinTree::search(int v)
{
    return true;
}

bool BinTree::remove(int v)
{
    return true;
}




#endif