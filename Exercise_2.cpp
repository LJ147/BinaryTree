// Exercise_2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
#include"BTNode.h"
#include"BinaryTree.h"
using namespace std;
int main() {
	BinaryTree<char>a, b, x, y, z, p;                           // �����������������ӵ�           //
	y.MakeTree('E', a, b);                                     //               B               //
	z.MakeTree('F', a, b);                                     //              / \              //
	x.MakeTree('C', y, z);                                     //             C   D             //
	y.MakeTree('D', a, b);                                     //            / \                //
	z.MakeTree('B', y, x);                                     //           E   F               //
	//z.MakeTree('B', y, x);
	cout << "ǰ�������ǰ������Ϊ��";
	z.PreOrder(Visit);
	cout << endl;
	cout << endl;

	cout << "���������ǰ������Ϊ��";
	z.PostOrder(Visit);
	cout << endl;
	cout << endl;

	cout << "���������ǰ������Ϊ��";
	z.InOrder(Visit);
	cout << endl;
	cout << endl;

	cout << "��α���������Ϊ�� ";
	cout << endl;
	z.HierarchicalOrder(Visit);
	cout << endl;

	char e = 'X';
	cout << "�߶�Ϊ�� " << z.Height() << endl;
	cout << endl;

	int k = 0;
	z.NumOfOne(k);
	cout << "�����Ϊ�� " << k << endl;
	cout << endl;

	cout << "���ƶ�����" << endl;
	p.Copy(z);
	p.PreOrder(Visit);
	cout << endl;
	cout << endl;

	cout << "�����������Ľڵ㣺" << endl;
	z.Exch();
	cout << endl;
	z.HierarchicalOrder(Visit);
	cout << endl;

	cout << "��ֶ�����" << endl;
	z.BreakTree(e, y, x);
	cout << "��ֺ��������ǰ������� ";
	y.PreOrder(Visit);
	cout << endl;
	cout << "��ֺ��������ǰ������� ";
	x.PreOrder(Visit);
	cout << endl;

	cin >> e;
	return 0;
}