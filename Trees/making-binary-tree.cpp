#include <bits/stdc++.h>

using namespace std;

class treenode
{
public:
    int data;
    treenode *left;
    treenode *right;

    treenode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//By recursion

treenode *buildtree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    treenode *root = new treenode(d);
    root->left = buildtree();
    root->right = buildtree();

    return root;
}

//Printing tree

void print(treenode *root)
{
    if (root == NULL)
    {
        return; // cout<<"Tree is empty."<<endl;
    }

    //Otherwise print the elements

    cout << root->data << " ";
    print(root->left);
    print(root->right);

    // return;
}

int main()
{

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cout.setf(std::ios::boolalpha);

    //Program code
    treenode *root = buildtree();
    print(root);
    return 0;
}
