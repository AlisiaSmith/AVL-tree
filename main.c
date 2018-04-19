#include "header.h"

 tree *insert(tree *root, int value)
 {

 if (!root)
 {
 root = (tree*)calloc(1, sizeof(tree));
 root->val = value;
 root->height = 1;

 return root;
 }
 if (root->val <= value)
 {
	 root->left = (insert(root->left, value));
	 root->height = root->left->height + 1;
 }
 else
 {
	 root->right = (insert(root->right, value));
	 root->height = root->right->height + 1;
 }
 if (def(root) == 2)
 {
	 if (def(root->left) >= 0) root = SmallRightCrook(root);
	 else root = BigRightCrook(root);
 }
 if (def(root) == -2)
 {
	 if (def(root->right) <= 0) root = SmallLeftCrook(root);
	 else root = BigLeftCrook(root);
 }
 return root;
 }

 void delet_tree(tree* root)
 {
	 if (!root) return ;
	 delet_tree(root->right);
	 delet_tree(root->left);
	 free(root);
 }


 unsigned int build_tree(unsigned int num, tree *root)
 {
	 unsigned int max_height = 0;
	 int n;
	 for (unsigned int i = 0; i < num; i++)
	 {
		 fscanf(stdin, "%d", &n);
		 root = insert(root, n);
		 max_height = root->height;
	 }

	 delet_tree(root);
	 return max_height;
 }

int main(int argv, char *argc[])
{	

	unsigned int num, height;
	tree *root = NULL;

	fscanf(stdin, "%d", &num);

	height = build_tree(num, root);

	fprintf(stdout, "%d", height);

	return 0;
}