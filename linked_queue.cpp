//
// Created by shy on 2022/11/10.
//

#include "linked_queue.h"

//初始化链表
void InitLinkedQueue(LinkedQueue &linked_queue) {
    linked_queue.rear = linked_queue.front = (Node *) malloc(sizeof(Node));
    linked_queue.front->next = NULL;
}

//判空
bool IsEmptyLinkedQueue(LinkedQueue linked_queue) {
    return linked_queue.rear == linked_queue.front;
}

//入队：尾部插入
void EnLinkedQueue(LinkedQueue &linked_queue, LinkedElemType m) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = m;
    new_node->next = NULL;//设置遍历结束条件
    linked_queue.rear->next = new_node;
    linked_queue.rear = new_node;
}

//出队：头部删除
bool DeLinkedQueue(LinkedQueue &linked_queue, LinkedElemType &m) {
    if (IsEmptyLinkedQueue(linked_queue)) {
        return false;
    }
    //获取将要删除的结点
    Node *delete_node = linked_queue.front->next;
    m = delete_node->data;
    linked_queue.front->next = delete_node->next;
    if (delete_node == linked_queue.rear) {
        linked_queue.rear=linked_queue.front;//如果要删除的结点是最后一个结点，队列置空
    }
    free(delete_node);
    return true;
}

//初始化循环链表
void InitCircularLinkedQueue(CircularLinkedQueue &cir_linked_queue) {
    //循环链表的头结点和尾结点指向同一个结点，此时队列即是空的，也是满的
    cir_linked_queue.rear = cir_linked_queue.front = (Node *) malloc(sizeof(Node));
    cir_linked_queue.rear->next = cir_linked_queue.front;//循环链表的尾结点的下一个结点指向头结点
}

//是否已满
bool IsFullCircularLinkedQueue(LinkedQueue linked_queue) {
    return linked_queue.rear->next = linked_queue.front;
}