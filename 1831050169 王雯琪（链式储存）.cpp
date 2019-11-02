#include<iostream>
#pragma once
using namespace std;
class BTree {
public:
	int FindleafNode(BTree* root) {  //查找叶子节点
		if (root == NULL) {
			return;
		}
		if (root->left == NULL && root->right == NULL)
		{
			return 1;
		}
		else { return FindleafNode(left) + FindleafNode(right); }
	}
	int FindTNode(BTree* root) {  //查找总结点个数
		if (root == NULL) {
			return;
		}
		int left = FindTNode(root->left);
		int right = FindTNode(root->right);
		return left + right + 1;
	}
	int DleafNode(BTree*root)
	{
		int count = FindTNode(root) - FindleafNode(root);
		return count;
	}
private:
		int value;
		BTree* left;
		BTree* right;
	
};