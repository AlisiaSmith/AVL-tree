#pragma once
#ifndef __HEADER_H__
#define __HEADER_H__
#define _CRT_SECURE_NO_WARNINGS


#include <stdlib.h>
#include <stdio.h>

typedef struct Tree_st
{
	int val;
	int height;
	struct Tree_st *right;
	struct Tree_st *left;
}tree;

tree* BigRightCrook(tree *knot);
tree* BigLeftCrook(tree *knot);
tree* SmallRightCrook(tree *knot);
tree* SmallLeftCrook(tree *knot);

#endif