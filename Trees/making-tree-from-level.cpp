//Making tree from level order
// #include <bits/stdc++.h>

// using namespace std;

// class node
// {
// public:
//     int data;
//     node *right;
//     node *left;
//     node(int val = 0)
//     {
//         data = val;
//         right = NULL;
//         left = NULL;
//     }
// };

// //Here is the reason why should we choose queue because of the fact that
// // We are making tree filling left child all predecessor and then right child predecessor so that why we chose queue in order to eleminate left first and then we will pop right child and the series continues till all the -1 finishes.

// node *buildtree()
// {
//     queue<node *> q;
//     int d;
//     cin >> d;
//     node *root = new node(d);

//     q.push(root);
//     int c1, c2;
//     while (!q.empty())
//     {
//         cin >> c1 >> c2;
//         node *f = q.front();
//         q.pop();
//         if (c1 != -1)
//         {
//             f->left = new node(c1);
//             q.push(f->left);
//         }
//         if (c2 != -1)
//         {
//             f->right = new node(c2);
//             q.push(f->right);
//         }
//     }
//     return root;
// }

// int height(node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     return 1 + max(height(root->left), height(root->right));
// }

// void printlevelorder(node *root, int level)
// {

//     if (root == NULL)
//     {
//         return;
//     }

//     if (level == 1)
//     {
//         cout << root->data << " ";
//     }

//     printlevelorder(root->left, level - 1);
//     printlevelorder(root->right, level - 1);
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

//     node *root = buildtree();
//     for (int i = 1; i < height(root) + 1; i++)
//     {
//         printlevelorder(root, i);
//         cout << endl;
//     }

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

node *buildTree()
{
    queue<node *> q;
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);

    q.push(root);
    int c1, c2;

    while (!q.empty())
    {
        cin >> c1 >> c2;
        node *f = q.front();
        q.pop();

        if (c1 != -1)
        {
            f->left = new node(c1);
            q.push(f->left);
        }

        if (c2 != -1)
        {
            f->right = new node(c2);
            q.push(f->right);
        }
    }

    return root;
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

void levelPrint(node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level == 1)
    {
        cout << root->data << " ";
    }

    levelPrint(root->left, level - 1);
    levelPrint(root->right, level - 1);
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

    node *root = buildTree();

    for (int i = 1; i <= height(root); i++)
    {
        levelPrint(root, i);
        cout << endl;
    }

    return 0;
}
