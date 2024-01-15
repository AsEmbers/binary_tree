//
// Created by shy on 2022/11/10.
//

#ifndef BINARY_TREE_LINKED_QUEUE_H
#define BINARY_TREE_LINKED_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
/**
 * 链表实现队列以及循环队列:先进先出
 */

typedef BiTree LinkedElemType;
//链表结点结构体定义
typedef struct Node {
    LinkedElemType data;
    struct Node *next;
} Node;
//链表头结点，尾结点定义
typedef struct {
    Node *front, *rear;
} LinkedQueue, CircularLinkedQueue;

//初始化链表
void InitLinkedQueue(LinkedQueue &linked_queue);

//判空
bool IsEmptyLinkedQueue(LinkedQueue linked_queue);

//入队：尾部插入
void EnLinkedQueue(LinkedQueue &linked_queue, LinkedElemType m);

//出队：头部删除
bool DeLinkedQueue(LinkedQueue &linked_queue, LinkedElemType &m);

//初始化循环链表
void InitCircularLinkedQueue(CircularLinkedQueue &cir_linked_queue);

//是否已满
bool IsFullCircularLinkedQueue(LinkedQueue linked_queue);

#endif //BINARY_TREE_LINKED_QUEUE_H
