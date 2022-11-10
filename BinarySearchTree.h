#ifndef BST
#define BST
#include<stdio.h>

struct Work
{
	char tiengAnh[20];
	char tiengViet[30];
};

struct TNode
{
	Work info;
	TNode* left;
	TNode* right;
};

struct BSTree
{
	TNode* root;
};

TNode* createTNode(int x);
void initBTree(BSTree& bt);
int insertTNodeLeft(TNode*& T, TNode* p);
int insertTNodeRight(TNode*& T, TNode* p);
int insertTNode(TNode*& root, TNode* p);
void traverseLNR(TNode* root);
TNode* createTNode(Work x);
TNode* findTNodeReplace(TNode*& p);
void createBSTree(TNode*& root);
void xoaXuongDong(char a[]);
int deleteTNodeX(TNode*& root, char x[]);
void traCuuNghia(TNode* root, char x[]);
void chinhSuaNghia(TNode*& root, char x[]);
int deleteTree(TNode*& root);
#endif