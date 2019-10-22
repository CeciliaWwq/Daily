#define _CRT_SECURE_NO WARNINGS 1
#include<stdio.h>
//根据前序和中序确定二叉树
typedef struct	TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
}TreeNode;
struct TreeNode* BuildTree(int* preorder,int preordersize,int* inorder,int inordersize)
{
	if (preordersize == 0) { return NULL; }
	int size = preordersize;
	int rootvalue = preorder[0];
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
	root->val = rootvalue;
	int leftsize = -1;
	for (int i = 0; i < size; i++) {
		if (inorder[i] = rootvalue) {
			leftsize = i;
			break;
		}
	}
	root->left = BuildTree(preorder + 1, leftsize, inorder, leftsize);
	root->right = BuildTree(preorder + leftsize + 1, size - 1 - leftsize, inorder + leftsize + 1,size - 1 - leftsize);

}
//根据中序和后续确定二叉树
struct TreeNode* BuildTree(int* afterorder, int afterordersize, int* inorder, int inordersize) {
	if (afterordersize == NULL) { return NULL; }
	int size = afterordersize;
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode*));
	int rootvalue = afterorder[afterordersize - 1];
	int leftsize = -1;
	for (int i = 0; i < size; i++) {
		if (inorder[i] == rootvalue) {
			leftsize = i;
			break;
		}
	}
	root->left = BuildTree(afterorder, leftsize, inorder, leftsize);
	root->right = BuildTree(afterorder + leftsize, size - 1 - leftsize, inorder + leftsize + 1, size - leftsize - 1);
}
