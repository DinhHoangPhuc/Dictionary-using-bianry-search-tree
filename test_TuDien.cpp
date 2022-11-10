#include"BinarySearchTree.h"
#include"asciinode.h"
#include<stdio.h>
#include<conio.h>

void main()
{
	int luachon;
	do
	{
		do
		{
			printf("\n");
			printf("------------------------------MENU------------------------------\n");
			printf("1. Xuat cay nhi phan tim kiem ra man hinh(doc tu file)\n");
			printf("2. Duyet cay theo NLR\n");
			printf("3. Them 1 tu bat ki vao cay\n");
			printf("4. Xoa 1 tu bat ki trong cay\n");
			printf("5. Tra nghia cua 1 tu\n");
			printf("6. Chinh sua nghia cua 1 tu\n");
			printf("7. Xoa toan bo cay\n");
			printf("0. Ket thuc chuong trinh\n");
			printf("Nhap lua chon cua ban: ");
			scanf_s("%d", &luachon);
		} while (luachon < 0);

		switch (luachon)
		{
		case 1:
		{
			BSTree bt;
			initBTree(bt);
			createBSTree(bt.root);
			printf("Cay NPTK hien tai:\n");
			print_ascii_tree(bt.root);
			break;
		}

		case 2:
		{
			BSTree bt;
			initBTree(bt);
			createBSTree(bt.root);
			printf("Cay NPTK hien tai:\n");
			print_ascii_tree(bt.root);
			printf("Duyet cay bang LNR:\n");
			traverseLNR(bt.root);
			break;
		}

		case 3:
		{
			BSTree bt;
			initBTree(bt);
			createBSTree(bt.root);
			printf("Cay NPTK hien tai:\n");
			print_ascii_tree(bt.root);
			Work x;
			rewind(stdin);
			printf("Nhap tu tieng anh: ");
			gets_s(x.tiengAnh);
			printf("Nhap nghia tieng viet: ");
			gets_s(x.tiengViet);
			TNode* p = createTNode(x);
			insertTNode(bt.root, p);
			printf("Cay NPTK sau khi them 1 tu:\n");
			print_ascii_tree(bt.root);
			break;
		}

		case 4:
		{
			BSTree bt;
			initBTree(bt);
			createBSTree(bt.root);
			printf("Cay NPTK hien tai:\n");
			print_ascii_tree(bt.root);
			char x[15];
			rewind(stdin);
			printf("Nhap tu tieng anh can xoa: ");
			gets_s(x);
			deleteTNodeX(bt.root, x);
			printf("Cay NPTK sau khi xoa 1 tu:\n");
			print_ascii_tree(bt.root);
			break;
		}

		case 5:
		{
			BSTree bt;
			initBTree(bt);
			createBSTree(bt.root);
			printf("Cay NPTK hien tai:\n");
			print_ascii_tree(bt.root);
			char x[15];
			rewind(stdin);
			printf("Nhap tu tieng anh can tra nghia: ");
			gets_s(x);
			traCuuNghia(bt.root, x);
			break;
		}

		case 6:
		{
			BSTree bt;
			initBTree(bt);
			createBSTree(bt.root);
			printf("Cay NPTK hien tai:\n");
			print_ascii_tree(bt.root);
			char x[15];
			rewind(stdin);
			printf("Nhap tu tieng anh can chinh sua nghia: ");
			gets_s(x);
			chinhSuaNghia(bt.root, x);
			printf("Nghia cua tu %s sau khi chinh sua la:\n", x);
			traCuuNghia(bt.root, x);
			break;
		}

		case 7:
		{
			BSTree bt;
			initBTree(bt);
			createBSTree(bt.root);
			printf("Cay NPTK hien tai:\n");
			print_ascii_tree(bt.root);
			if (deleteTree(bt.root) == 1)
				printf("Da xoa cay thanh cong\n");
			/*print_ascii_tree(bt.root);*/
			break;
		}

		default:
			break;
		}
	} while (luachon > 0 && luachon <= 7);
}