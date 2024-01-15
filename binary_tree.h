//
// Created by shy on 2022/11/10.
//

#ifndef BINARY_TREE_BINARY_TREE_H
#define BINARY_TREE_BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

//树结点定义
typedef char BiElemType;
typedef struct BiTreeNode
{
    BiElemType data;
    struct BiTreeNode *left_node;
    struct BiTreeNode *right_node;
}BiTreeNode,*BiTree;

//辅助队列
typedef struct SecondaryQueue
{
    BiTree tree_pointer;//树的某一个结点的地址
    struct SecondaryQueue *next;
}SecondaryQueue,*SecQueue;

//层次建树
void LevelBuildBiTree(BiTree &binary_tree);
//前序遍历，也叫深度优先遍历
void PrevOrder(BiTree binary_tree);
//中序遍历
void InOrder(BiTree binary_tree);
//后序遍历
void PostOrder(BiTree binary_tree);
//层序遍历，也叫广度优先遍历
void LevelOrder(BiTree binary_tree);

#endif //BINARY_TREE_BINARY_TREE_H
