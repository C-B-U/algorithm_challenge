#include <iostream>
using namespace std;

struct Node 
{
    char left;
    char right;
    char data;
};

Node arr[27];

void PreOrder(Node node) 
{
    if (node.data == '\0' || node.data == '.')
        return;

    cout << node.data;

    if (node.left != '\0' && node.left != '.') 
    {
        PreOrder(arr[node.left - 'A']);
    }

    if (node.right != '\0' && node.right != '.') 
    {
        PreOrder(arr[node.right - 'A']);
    }
}

void InOrder(Node node) 
{
    if (node.left != '\0' && node.left != '.') 
    {
        InOrder(arr[node.left - 'A']);
    }

    if (node.data == '\0' || node.data == '.')
        return;

    if (node.data != '\0' && node.data != '.') 
    {
        cout << node.data;
    }

    if (node.right != '\0' && node.right != '.') 
    {
        InOrder(arr[node.right - 'A']);
    }
}

void PostOrder(Node node) 
{
    if (node.left != '\0' && node.left != '.') 
    {
        PostOrder(arr[node.left - 'A']);
    }

    if (node.right != '\0' && node.right != '.') 
    {
        PostOrder(arr[node.right - 'A']);
    }

    if (node.data != '\0' && node.data != '.') 
    {
        cout << node.data;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        char node, left, right;
        cin >> node >> left >> right;
        arr[node - 'A'].data = node;
        arr[node - 'A'].left = left;
        arr[node - 'A'].right = right;
    }

    PreOrder(arr['A' - 'A']);
    cout << '\n';
    InOrder(arr['A' - 'A']);
    cout << '\n';
    PostOrder(arr['A' - 'A']);
}