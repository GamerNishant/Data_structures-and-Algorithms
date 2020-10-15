#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val = 0)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void insert(node **root, int val)
{
    if ((*root) == NULL)
    {
        *root = new node(val);
    }

    else if ((*root)->data > val)
    {
        insert(&((*root)->left), val);
    }
    else if ((*root)->data <= val)
    {
        insert(&((*root)->right), val);
    }
}

node *getBST(int arr[], int n)
{
    node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        insert(&root, arr[i]);
    }

    return root;
}

int searchbst(node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == key)
    {
        return 1;
    }

    if (root->data < key)
    {
        return searchbst(root->right, key);
    }

    else
    {
        return searchbst(root->left, key);
    }
}

void inorder(node *root)
{
    if (root != NULL && root->left != NULL)
    {
        inorder(root->left);
    }

    if (root != NULL)
    {
        cout << root->data << " ";
    }

    if (root != NULL && root->right != NULL)
    {
        inorder(root->right);
    }
}

int main()
{

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    // cout.setf(std::ios::boolalpha);

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    node *root = getBST(arr, n);
    inorder(root);
    int value = searchbst(root, 22);
    cout << '\n'<< value << endl;

    return 0;
}
