// List.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include"list.h"

int main()
{
	List list1,list2;
	
	//cin>>list1;
	list1.InsertAtLast('4'-48);
	list1.InsertAtLast('3'-48);
	list1.InsertAtLast('2'-48);
	list1.InsertAtLast('1'-48);
	
	//cout<<list1<<endl;
	/*
	cin>>list2;
	cout<<MergeCreateNew(list1,list2);
	cout<<endl;
	MergeList(list1,list2);
	*/
	list1.PrintFromNode(list1.first);
	//list1.first=list1.RevListWithRecursion(list1.first);
	list1.RevList();
	list1.PrintFromNode(list1.first);
	//cout<<list1<<endl;
	return 0;
}

