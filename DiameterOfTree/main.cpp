#include "tree.h"

int main()
{
    int T, N, x;
    vector<int> v;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        Tree *tree = new Tree;
        // Build tree with the given values
        TreeNode * root = tree->buildTree(v);
        
        cout << tree->diameter() << endl;
        v.clear();
    }
    
    return 0;
}
