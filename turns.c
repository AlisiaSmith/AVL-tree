#include "header.h"

tree* BigRightCrook(tree *knot)
{

}


tree* BigLeftCrook(tree *knot)
{

}


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
