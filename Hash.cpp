// Hash.cpp : 定义控制台应用程序的入口点。
//
//  main.cpp
//  hash List
//
//  Created by 蓝猫 on 16/2/19.
//  Copyright © 2016年 蓝猫. All rights reserved.
//＃表长➖1是存储的空间 （主函数while）
#include "stdafx.h"
#include <conio.h>
#include <string>
#include <iostream>
#define Datatype int
#define max 100
using namespace std;
typedef struct {
	int num;
	string a;
}Node;
typedef struct hash {
	Node data[max];
	int Listsize;
}Hash;
void ins_hash(Hash *hash, int key, string a);
void out_hash(Hash *hash);
void search_hash(Hash *hash, int key);
int main(int argc, const char * argv[]) {
	static int sum, i;
	int n;
	string a;
	Hash h1;
	cout << "输入散列表的存储个数" << endl;
	cin >> h1.Listsize;
	for (i = 0; i<h1.Listsize; i++) {
		h1.data[i].num = 0;
		h1.data[i].a = '0';
	}
	cout << "输入数据的key和结点信息 用0 0结束" << endl;
	cout << "输出第" << sum + 1 << "个结点信息" << endl;
	cin >> n >> a;
	sum++;
	/*while (n&&sum<h1.Listsize) {
	ins_hash(&h1,n,a);
	cout<<"输出第"<<sum+1<<"个结点信息"<<endl;
	cin>>n>>a;
	sum++;
	}*/
	while (n&&sum <= h1.Listsize)
	{
		ins_hash(&h1, n, a);
		if (sum == h1.Listsize)
		{
			cout << "输出“0 0”表示结束" << endl;
		}
		else
			cout << "输出第" << sum + 1 << "个结点信息" << endl;
		cin >> n >> a;
		sum++;
	}
	out_hash(&h1);
	cout << endl << "请输入你要查找的结点的关键字key" << endl;
	cin >> n;
	search_hash(&h1, n);
	cout << endl;
	_getch();
	return 0;
}
void ins_hash(Hash *hash, int key, string a) {
	int k, k1, k2, m;
	m = hash->Listsize;
	k = key%m;
	if (hash->data[k].num == 0) {
		hash->data[k].num = key;
		hash->data[k].a = a;
		return;
	}
	else
	{
		k1 = k + 1;
		while (k1<m&&hash->data[k1].num != 0)
		{
			k1++;
		}
		if (k1<m)
		{
			hash->data[k1].num = key;
			hash->data[k1].a = a;
			return;
		}
		k2 = 0;
		while (k2<k&&hash->data[k2].num != 0)
		{
			k2++;
		}
		if (k2<k)
		{
			hash->data[k2].num = key;
			hash->data[k2].a = a;
			return;
		}

	}

}
void out_hash(Hash *hash) {
	int i;
	for (i = 0; i<hash->Listsize; i++)
	{
		if (hash->data[i].num)
		{
			cout << "hash[" << i << "]:" << hash->data[i].num << " " << hash->data[i].a << endl;
		}
	}
}
void search_hash(Hash *hash, int key)
{
	static int k, k1, k2, flag;
	k = key%hash->Listsize;
	if (hash->data[k].num == key)
	{
		cout << "hash[" << k << "]:" << hash->data[k].num << " " << hash->data[k].a << endl;
		flag = 1;
	}
	else
	{
		k1 = k + 1;
		while (k1<hash->Listsize&&hash->data[k1].num != key)
		{
			k1++;
		}
		if (k1<hash->Listsize)
		{
			cout << "hash[" << k1 << "]:" << hash->data[k1].num << " " << hash->data[k1].a << endl;
			flag = 1;
		}
		if (!flag)
		{
			while (k2<k&&hash->data[k2].num != key) {
				k2++;
			}
			if (k2<k)
			{
				cout << "hash[" << k2 << "]:" << hash->data[k2].num << " " << hash->data[k2].a << endl;
				flag = 1;
			}
		}
	}
	if (flag)
	{
		cout << "查找成功" << endl;
		return;
	}
	else
	{
		cout << "查找不成功" << endl;
	}
}

