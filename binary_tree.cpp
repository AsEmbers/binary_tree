//
// Created by shy on 2022/11/10.
//
#include "binary_tree.h"
#include "linked_queue.h"

void LevelBuildBiTree(BiTree &binary_tree)
{
    binary_tree=NULL;//树的根节点赋值为NULL,树的根节点也是需要存储数据的
    BiTreeNode *new_tree_node;//用来指向新申请的树结点
    SecondaryQueue *queue_head,*queue_tail,*queue_current,*queue_new_node;//辅助队列
    BiElemType elem;
    while (scanf("%c",&elem))
    {
        if('\n'==elem)
        {
            break;
        }
        //calloc()申请空间的大小为两个参数的乘积，并对空间进行初始化，赋值为0
        new_tree_node=(BiTreeNode*)calloc(1,sizeof(BiTreeNode));
        new_tree_node->data=elem;
        queue_new_node=(SecondaryQueue*)calloc(1,sizeof(SecondaryQueue));
        queue_new_node->tree_pointer=new_tree_node;
        if(NULL==binary_tree)
        {
            binary_tree=new_tree_node;
            queue_head=queue_new_node;
            queue_tail=queue_new_node;
            queue_current=queue_new_node;
        }else{
            queue_tail->next=queue_new_node;
            queue_tail=queue_new_node;
            if(NULL==queue_current->tree_pointer->left_node)
            {
                queue_current->tree_pointer->left_node=new_tree_node;
            }else if(NULL==queue_current->tree_pointer->right_node)
            {
                queue_current->tree_pointer->right_node=new_tree_node;
                queue_current=queue_current->next;
            }
        }
    }
}

//前序遍历，也叫深度优先遍历
void PrevOrder(BiTree binary_tree)
{
    if(NULL!=binary_tree)
    {
        putchar(binary_tree->data);
        PrevOrder(binary_tree->left_node);
        PrevOrder(binary_tree->right_node);
    }
}
//中序遍历
void InOrder(BiTree binary_tree)
{
    if(NULL!=binary_tree)
    {
        InOrder(binary_tree->left_node);
        putchar(binary_tree->data);
        InOrder(binary_tree->right_node);
    }
}
//后序遍历
void PostOrder(BiTree binary_tree)
{
    if(NULL!=binary_tree)
    {
        PostOrder(binary_tree->left_node);
        PostOrder(binary_tree->right_node);
        putchar(binary_tree->data);
    }
}
//层序遍历，也叫广度优先遍历
void LevelOrder(BiTree binary_tree)
{
    //初始化辅助队列
    LinkedQueue linked_queue;
    InitLinkedQueue(linked_queue);
    EnLinkedQueue(linked_queue,binary_tree);
    BiTreeNode *tree_node;//存储出队元素
    while (!IsEmptyLinkedQueue(linked_queue))
    {
        DeLinkedQueue(linked_queue,tree_node);
        putchar(tree_node->data);
        if(NULL!=tree_node->left_node)
        {
            EnLinkedQueue(linked_queue,tree_node->left_node);
        }
        if(NULL!=tree_node->right_node)
        {
            EnLinkedQueue(linked_queue,tree_node->right_node);
        }
    }
}

