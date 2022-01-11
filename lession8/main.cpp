#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int boolean;

int countDepth = 0;
int tempCount = 0;

typedef struct TreeNode
{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *insertIntoTree(TreeNode *root, int data)
{
    TreeNode *current_node = root;
    TreeNode *parent_node = root;
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
    if (new_node == NULL)
        return NULL;
    new_node->key = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if (root == NULL)
    {
        root = new_node;
        return root;
    }
    while (current_node->key != data)
    {
        parent_node = current_node;
        if (current_node->key >= data)
        {
            current_node = current_node->left;
            if (current_node == NULL)
            {
                parent_node->left = new_node;
                return root;
            }
        }
        else
        {
            current_node = current_node->right;
            if (current_node == NULL)
            {
                parent_node->right = new_node;
                return root;
            }
        }
    }
    return root;
}

void printTree(TreeNode *root)
{
    if (root)
    {
        printf("%d", root->key);
        if (root->left || root->right)
        {
            printf("(");
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

void depthCount(TreeNode *root)
{
    if (root != NULL)
    {
        tempCount++;
        if (root->left != NULL)
        {
            depthCount(root->left);
        }
        if (root->right != NULL)
        {
            depthCount(root->right);
        }
    }
    if (tempCount > countDepth)
    {
        countDepth = tempCount;
    }
    tempCount--;
}

int isBalanced(TreeNode *root, int num)
{
    int countRight = 0, countLeft = 0;

    depthCount(root->left);
    countLeft = countDepth;
    countDepth = 0;
    tempCount = 1;

    depthCount(root->right);
    countRight = countDepth;
    countDepth = 0;
    tempCount = 1;

    if (countLeft == countRight || countLeft == countRight + 1 || countLeft == countRight - 1)
    {
        return 1;
    }

    return 0;
}

TreeNode *treeBinarySearch(TreeNode *root, int value)
{
    if (root == NULL)
        return NULL;
    if (root->key == value)
    {
        return root;
    }
    else if (root->left != NULL && value <= root->key)
    {
        return treeBinarySearch(root->left, value);
    }
    else if (root->right != NULL && value > root->key)
    {
        return treeBinarySearch(root->right, value);
    }
    return NULL;
}

int main()
{
    printf("Первое задание.\n");

    int treesAmount = 50;
    int NodeQty = 10000;
    int balAmount = 0;

    TreeNode *treeRoots[treesAmount];

    for (int i = 0; i < treesAmount; i++)
    {
        int keyRand = rand() % NodeQty;
        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
        root->key = keyRand;
        root->left = NULL;
        root->right = NULL;
        treeRoots[i] = root;
        for (int j = 0; j < NodeQty; j++)
        {
            int keyRandNode = rand() % NodeQty;
            insertIntoTree(root, keyRandNode);
        }

        if (isBalanced(treeRoots[i], i) == 1)
        {
            balAmount++;
        }
    }

    printf("\n Cбалансированных деревьев : %0.0f%%\n", (balAmount * 100.0 / treesAmount));

    printf("Второе задание.\n");
    TreeNode *tree = (TreeNode *)malloc(sizeof(TreeNode));
    tree->key = (11);
    tree->left = NULL;
    tree->right = NULL;
    insertIntoTree(tree, 4);
    insertIntoTree(tree, 9);
    insertIntoTree(tree, 20);
    insertIntoTree(tree, 3);
    insertIntoTree(tree, 13);
    insertIntoTree(tree, 18);
    insertIntoTree(tree, 5);

    const int arrSize = 5;
    const int searchList[arrSize] = {1, 20, 9, 66, 5};
    for (int i = 0; i < arrSize; i++)
    {
        if (treeBinarySearch(tree, searchList[i]) != NULL)
        {
            printf("\tНайдено %d!\n", searchList[i]);
        }
        else
        {
            printf("\tНе найдено %d!\n", searchList[i]);
        }
    }
    return 0;
}