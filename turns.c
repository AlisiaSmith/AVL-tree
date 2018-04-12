#include "header.h"

tree* SmallLeftCrook(tree *knot)
{
	tree *tmp = knot->right;
	knot->right = tmp->left;
	tmp->left = knot;

	return tmp;
}

tree* SmallRightCrook(tree *knot)
{
	tree *tmp = knot->left;
	knot->left = tmp->right;
	tmp->right = knot;

	return tmp;
}

tree* BigLeftCrook(tree *knot)
{
	knot->right = SmallRightCrook(knot->right);
	knot = SmallLeftCrook(knot);
	return knot;
}

tree* BigRightCrook(tree *knot)
{
	knot->left = SmallLefttCrook(knot->left);
	knot = SmallRightCrook(knot);
	return knot;
}