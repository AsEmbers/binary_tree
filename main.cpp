#include "binary_tree.h"

/**
 * 二叉树：
 * 读取字符串abcdefghij，然后层次建树建立一颗二叉树，
 * 然后前序遍历（深度优先遍历）输出abdhiejcfg
 */
int main() {
    BiTree binary_tree;//声明树的根结点
    LevelBuildBiTree(binary_tree);
    PrevOrder(binary_tree);
    printf("\n");
    InOrder(binary_tree);
    printf("\n");
    PostOrder(binary_tree);
    printf("\n");
    LevelOrder(binary_tree);
    return 0;
}
