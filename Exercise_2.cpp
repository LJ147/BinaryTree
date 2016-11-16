// Exercise_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include"BTNode.h"
#include"BinaryTree.h"
using namespace std;
int main() {
	BinaryTree<char>a, b, x, y, z, p;                           // 二叉树大概是这个样子的           //
	y.MakeTree('E', a, b);                                     //               B               //
	z.MakeTree('F', a, b);                                     //              / \              //
	x.MakeTree('C', y, z);                                     //             C   D             //
	y.MakeTree('D', a, b);                                     //            / \                //
	z.MakeTree('B', y, x);                                     //           E   F               //
	//z.MakeTree('B', y, x);
	cout << "前序遍历当前二叉树为：";
	z.PreOrder(Visit);
	cout << endl;
	cout << endl;

	cout << "中序遍历当前二叉树为：";
	z.PostOrder(Visit);
	cout << endl;
	cout << endl;

	cout << "后序遍历当前二叉树为：";
	z.InOrder(Visit);
	cout << endl;
	cout << endl;

	cout << "层次遍历二叉树为： ";
	cout << endl;
	z.HierarchicalOrder(Visit);
	cout << endl;

	char e = 'X';
	cout << "高度为： " << z.Height() << endl;
	cout << endl;

	int k = 0;
	z.NumOfOne(k);
	cout << "结点数为： " << k << endl;
	cout << endl;

	cout << "复制二叉树" << endl;
	p.Copy(z);
	p.PreOrder(Visit);
	cout << endl;
	cout << endl;

	cout << "交换二叉树的节点：" << endl;
	z.Exch();
	cout << endl;
	z.HierarchicalOrder(Visit);
	cout << endl;

	cout << "拆分二叉树" << endl;
	z.BreakTree(e, y, x);
	cout << "拆分后的左子树前序遍历： ";
	y.PreOrder(Visit);
	cout << endl;
	cout << "拆分后的右子树前序遍历： ";
	x.PreOrder(Visit);
	cout << endl;

	cin >> e;
	return 0;
}