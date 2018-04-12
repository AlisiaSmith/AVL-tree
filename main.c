#include "header.h"


int verify(FILE *in)
{
	if (in == NULL)
	{
		printf("%s", "Error: file not found");
		fclose(in);
		return 1;
	}
	return 0;
}

tree *build_tree(int num, FILE *in, tree *root)
{

	return root;
}

/*
{
int value;
for(int i = 0; i < num; i++)
{
fscanf(in, "%d", value);
insert(root, value);
}
}
*/


 int insert(tree *root, int value, int h)
{
	int  weight = 0;
	if (!root) 
	{
		root = (tree*)calloc(1, sizeof(tree));
		root->val = value;
		root->height = h;
		return 0;
	}
	if (root->val <= value)
	{
		weight = insert(root->left, value, h + 1) - 1;
	}
	else
	{
		weight = insert(root->right, value, h + 1) + 1;
	}

	return weight;
}



int main(int argv, char *argc[])
{
	if (argv < 2) return 0;
	
	FILE *in;
	int num;
	tree *root = NULL;

	in = fopen(argc[1], "r");
	if (verify(in)) return 0;

	fscanf(in, "%d", &num);

	if (num > 1)
		root = build_tree(num, in, root);
	else
		printf("%d", num);

	fclose(in);
	return 0;
}