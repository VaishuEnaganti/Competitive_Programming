#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    int height;
    TreeNode * left, * right;
    
    TreeNode(int value): val(value), left(NULL), right(NULL) {}
};

// Define the TreeNode structure
class Tree
{
private:
    void insert(int val);
    
public:
    int diameter();
    TreeNode* buildTree(const vector<int>& v);
    
//    Tree() {root = NULL;}
    
private:
    TreeNode *root;
};
