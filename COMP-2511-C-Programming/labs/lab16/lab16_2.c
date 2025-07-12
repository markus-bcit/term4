typedef struct TreeNode TreeNode;
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
typedef TreeNode *TreeNodePtr;

void postorder(TreeNode *pNode)
{
    if (pNode != NULL)
    {
        postorder(pNode->left);
        postorder(pNode->right);
        printf(" %d ", pNode->data);
    }
}