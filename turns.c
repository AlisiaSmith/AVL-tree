#include "header.h"


int def(tree * knot)
{
	if (knot->left && knot->right)
		return knot->left->height - knot->right->height;
	
	if (knot->left)
		return knot->left->height;

	if (knot->right)
		return  -knot->right->height;
	
	return 0;
}

int recount(tree *knot)
{
	if (knot->right && knot->left)
	{
		int max = 0;
		if (knot->right->height >= knot->left->height)
			max = knot->right->height + 1;
		else
			max = knot->left->height + 1;
		return max;
	}
	
	if (knot->right)
		return knot->right->height + 1;
	
	if (knot->left)
		return knot->left->height + 1;
	
	return 1;
}

tree* SmallLeftCrook(tree *knot)
{
	tree *tmp = knot->right;
	knot->right	= tmp->left;
	tmp->left = knot;

	if (tmp->right)		tmp->right->height		= recount(tmp->right);
	if(tmp->left)		tmp->left->height		= recount(tmp->left);
						tmp->height				= recount(tmp);

	return tmp;
}

tree* SmallRightCrook(tree *knot)
{
	tree *tmp = knot->left;
	knot->left = tmp->right;
	tmp->right = knot;
	
	if (tmp->left)		tmp->left->height		= recount(tmp->left);
	if(tmp ->right)		tmp->right->height		= recount(tmp->right);
						tmp->height				= recount(tmp);

	return tmp;
}

tree* BigLeftCrook(tree *knot)
{
	knot->right = SmallRightCrook(knot->right);
	knot->right->height++;
	knot = SmallLeftCrook(knot);

	return knot;
}

tree* BigRightCrook(tree *knot)
{
	knot->left = SmallLeftCrook(knot->left);
	knot->left->height++;
	knot = SmallRightCrook(knot);

	return knot;
}