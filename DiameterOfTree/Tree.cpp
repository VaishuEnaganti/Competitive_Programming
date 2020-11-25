#include "tree.h"

namespace {

// Function to find the height of a tree
int height(TreeNode* root)
{
    if (!root)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else if (root->left == NULL && root->right != NULL)
    {
        return 1 + root->right->height;
    }
    else if (root->right == NULL && root->left != NULL)
    {
        return 1 + root->left->height;
    }
    
    return 1 + max(root->left->height, root->right->height);
}

// Post order traversal of the tree
// to calculate height of all nodes
void postOrder(TreeNode * root)
{
    if (root->left)
    {
        postOrder(root->left);
    }
    if (root->right)
    {
        postOrder(root->right);
    }
    
    root->height = height(root);
}
}

// Calculate the diameter of tree rooted at 'root'
int Tree::diameter()
{
    postOrder(root);
    // Use a queue to traverse the tree
    queue<TreeNode*> q;
    q.push(root);
    int maxSofar = 0, h1, h2;
    while (!q.empty())
    {
        TreeNode * n = q.front();
        h1 = h2 = 0;
        q.pop();
        if (n->left)
        {
            h1 = n->left->height;
            q.push(n->left);
        }
        if (n->right)
        {
            h2 = n->right->height;
            q.push(n->right);
        }
        if (h1+h2+1 > maxSofar)
        {
            maxSofar = h1 + h2 + 1;
        }
    }
    
    return maxSofar;
}


// Function to insert elements into the tree
void Tree::insert(int val)
{
    TreeNode * curr = root;
    TreeNode * newNode = new TreeNode(val);
    
    while (curr)
    {
        if (val < curr->val)
        {
            if (!curr->left)
            {
                curr->left = newNode;
                break;
            }
            else
            {
                curr = curr->left;
            }
        }
        else
        {
            if (!curr->right)
            {
                curr->right = newNode;
                break;
            }
            else
            {
                curr = curr->right;
            }
        }
    }
}


// Building a tree such that the node values are
// as in the given input vector v
TreeNode* Tree::buildTree(const vector<int>& v)
{
    int len = v.size();
    this->root = new TreeNode(v[0]);
    
    for (int i = 1; i < len; i++)
    {
        insert(v[i]);
    }
    
    return this->root;
}
