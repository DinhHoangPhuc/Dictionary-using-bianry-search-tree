#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<random>
#include<string.h>
#include"BinarySearchTree.h"

TNode* createTNode(Work x)
{
	TNode* p = new TNode;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void initBTree(BSTree& bt)
{
	bt.root = NULL;
}

int insertTNodeLeft(TNode*& T, TNode* p)
{
	if (T == NULL || p == NULL)
		return 0;
	if (T->left != NULL)
		return 0;
	T->left = p;
	return 1;
}

int insertTNodeRight(TNode*& T, TNode* p)
{
	if (T == NULL || p == NULL)
		return 0;
	if (T->right != NULL)
		return 0;
	T->right = p;
	return 1;
}

int insertTNode(TNode*& root, TNode* p)
{
	if (p == NULL)
		return 0;
	if (root == NULL)
	{
		root = p;
		return 1;
	}
	if (_strcmpi(root->info.tiengAnh, p->info.tiengAnh) == 0)
		return 0;
	if (_strcmpi(p->info.tiengAnh, root->info.tiengAnh) < 0)
		insertTNode(root->left, p);
	else
		insertTNode(root->right, p);
	return 1;
}

void traverseLNR(TNode* root)
{
	if (root == NULL)
		return;
	traverseLNR(root->left);
	printf("%s\n", root->info.tiengAnh);
	traverseLNR(root->right);
}

void xoaXuongDong(char a[])
{
	size_t len = strlen(a);
	if (a[0] == '\n')
		for (int i = 0; i < len; i++)
			a[i] = a[i + 1];
		/*a[len - 1] = '\0';*/
}

void createBSTree(TNode*& root)
{
	FILE* f = fopen("input.txt", "r");
	int n;
	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; i++)
	{
		Work x;
		fscanf(f, "%[^\#]#%[^\n]\n", &x.tiengAnh, &x.tiengViet);
		xoaXuongDong(x.tiengAnh);
		xoaXuongDong(x.tiengViet);
		TNode* p = createTNode(x);
		insertTNode(root, p);
	}
	fclose(f);
}

TNode* findTNodeReplace(TNode*& p)
{
	TNode* f = p;
	TNode* q = p->right;
	while (q->left != NULL)
	{
		f = q;
		q = q->left;
	}
	p->info = q->info;
	if (f == p)
		f->right = q->right;
	else
		f->left = q->right;
	return q;
}

int deleteTNodeX(TNode*& root, char x[])
{
	if (root == NULL)
		return 0;
	if (_strcmpi(root->info.tiengAnh, x) > 0)
		return deleteTNodeX(root->left, x);
	else
		if (_strcmpi(root->info.tiengAnh, x) < 0)
			return deleteTNodeX(root->right, x);
		else
		{
			TNode* p = root;
			if (root->left == NULL)
			{
				root = root->right;
				delete p;
			}
			else
				if (root->right == NULL)
				{
					root = root->left;
					delete p;
				}
				else
				{
					TNode* q = findTNodeReplace(p);
					delete q;
				}
			return 1;
		}
}

void traCuuNghia(TNode* root, char x[])
{
	if (root == NULL)
		return;
	traCuuNghia(root->left, x);
	if (_strcmpi(root->info.tiengAnh, x) == 0)
	{
		printf("Nghia cua tu %s la %s\n", x, root->info.tiengViet);
		return;
	}
	traCuuNghia(root->right, x);
}

void chinhSuaNghia(TNode*& root, char x[])
{
	if (root == NULL)
		return;
	chinhSuaNghia(root->left, x);
	if (_strcmpi(root->info.tiengAnh, x) == 0)
	{
		char str[20];
		rewind(stdin);
		printf("Nhap nghia chinh sua: ");
		gets_s(str);
		strcpy(root->info.tiengViet, str);
		return;
	}
	chinhSuaNghia(root->right, x);
}

int deleteTree(TNode*& root)
{
	if (root == NULL)
		return 1;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
	return 1;
}