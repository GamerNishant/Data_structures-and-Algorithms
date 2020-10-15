// #include <iostream>

// using namespace std;

// typedef struct node
// {
//     int value;
//     node *pLeft;
//     node *pRight;
//     node(int val = 0)
//     {
//         value = val;
//         pRight = NULL;
//         pLeft = NULL;
//     }
// } node;

// void insert(node **pRoot, int val)
// {
//     if (*pRoot == NULL)
//         *pRoot = new node(val);
//     else if ((*pRoot)->value <= val)
//         insert(&((*pRoot)->pRight), val);
//     else if ((*pRoot)->value > val)
//         insert(&((*pRoot)->pLeft), val);
// }

// node *getBST(int *arr, int size)
// {
//     node *pRoot = NULL;
//     for (int i = 0; i < size; i++)
//         insert(&pRoot, arr[i]);
//     return pRoot;
// }

// void inOrderTraversal(node *pRoot)
// {
//     if (pRoot && pRoot->pLeft)
//         inOrderTraversal(pRoot->pLeft);
//     if (pRoot)
//         std::cout << pRoot->value << " , ";
//     if (pRoot && pRoot->pRight)
//         inOrderTraversal(pRoot->pRight);
// }
// int main()
// {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cout.setf(std::ios::boolalpha);
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int  i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     node *pRoot = getBST(arr, n);
//     inOrderTraversal(pRoot);
//     std::cout << std::endl;
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
    node(int val = 0)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

void insert(node **root, int val)
{
    if (*root == NULL)
        *root = new node(val);
    else if ((*root)->data <= val)
        insert(&((*root)->right), val);
    else if ((*root)->data > val)
        insert(&((*root)->left), val);
}

node *getBST(int arr[], int n)
{
    node *root = NULL;
    for (int i = 0; i < n; i++)
        insert(&root, arr[i]);
    return root;
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
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cout.setf(std::ios::boolalpha);

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    node *root = getBST(arr, n);

    inorder(root);

    return 0;
}
