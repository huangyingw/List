#include <fstream>
using namespace std;

class List;
class ListNode
{
	friend ostream& operator<<(ostream&out,List&x);
	friend class List;
	friend List MergeCreateNew(List list1,List list2);
	friend void MergeList(List list1,List list2);
	public:
		ListNode();
		ListNode(const int& item);
		ListNode *NextNode(){return next;}
		void InsertAfter(ListNode*p);//Insert node after current node
		
		int GetNodeValue();

		ListNode* CreateNode(int item,ListNode* next);
		ListNode*RemoveNextNode();//Remove the next node from current list and return the next node's pointer
	private:
		int data;
		ListNode* next;
};

class List
{
	friend ostream& operator<<(ostream&out,List&x);
	friend istream& operator>>(istream&,List&);
	friend List MergeCreateNew(List list1,List list2);
	friend void MergeList(List list1,List list2);
	public:
		ListNode*first,*last;
    List(){last=first=NULL;fout.open("output.txt");}
		List(const int value){last=first=new ListNode(value);fout.open("output.txt");}
		List(const List&);
		~List();
		void ClearList();
		int Length()const;
		
		ListNode * FindValue(int value);//search value in list.If succeed, return the pointer to that node, if not, return null
		
		ListNode * FindAppropriateNode(int value);
		ListNode * ReturnNodeObjctByIndex(int i);
		
		void IncInsertNode(ListNode *node);//Insert a node into current list, given that the current list is sorted already
		void InsertAtFirst(int value);
		void InsertAtLast(int value);
		int InsertAtIndex(int value,int i);//insert new value at index i
		int RemoveByIndex(int i);//remove the node by index i
		void RevList();//reverse list with pure pointer operation
		ListNode* RevListWithRecursion(ListNode* head);
		void PrintFromNode(ListNode* node);
	private:
		ofstream fout;
};

List::List(const List& list)
{
	
}

int ListNode::GetNodeValue()
{
	return data;
}


List MergeCreateNew(List list1,List list2)
{
	List result;
	ListNode*p1,*p2;
	p1=list1.first;
	p2=list2.first;
	if(p1->data<p2->data)
	{
		result.InsertAtLast(p1->data);
		p1=p1->next;
	}
	else
	{
		result.InsertAtLast(p2->data);
		p2=p2->next;
	}
	while(p1&&p2)
	{
		if(p1->data<p2->data)
		{
			result.InsertAtLast(p1->data);
			p1=p1->next;
		}
		else
		{
			result.InsertAtLast(p2->data);
			p2=p2->next;
		}
	}
	while(p1)
	{
		result.InsertAtLast(p1->data);
		p1=p1->next;
	}
	while(p2)
	{
		result.InsertAtLast(p2->data);
		p2=p2->next;
	}
	return result;
}


void MergeList(List list1,List list2)
{
	ListNode*p1,*p2,*temp;
	p1=list1.first;
	p2=list2.first;
	while(p2)
	{
		temp=new ListNode(p2->data);
		p2=p2->next;
		list1.IncInsertNode(temp);
	}
}


ListNode::ListNode():next(NULL){}

ListNode::ListNode(const int& item):data(item),next(NULL){}

void ListNode::InsertAfter(ListNode*p)//Insert node after current node
{
	p->next=next;
	next=p;
}

ListNode* ListNode::CreateNode(int item,ListNode* next)
{
	ListNode*newnode=new ListNode(item);
	newnode->next=next;
	return newnode;
}

//Insert a node into current list, given that the current list is sorted already
void List::IncInsertNode(ListNode *node)
{
	ListNode *pos=FindAppropriateNode(node->data);
	node->next=pos->next;
	pos->next=node;
}
		
/*
Search appropriate node for value to be inserted. The appropriate node's value should be less that value, while its next's value is greated than value
*/
ListNode * List::FindAppropriateNode(int value)
{
	ListNode*tmpptr=first;
	if(tmpptr->data>value)
		return tmpptr;
	while(tmpptr->next&&tmpptr->next->data<value)
	{
		tmpptr=tmpptr->next;
	}
	return tmpptr;
}
		
ListNode*ListNode::RemoveNextNode()//Remove the next node from current list and return the next node's pointer
{
 	ListNode*tmpptr=this->next;
	this->next=tmpptr->next;
	return tmpptr;
}

List::~List()
{
	fout.close();
}

void List::ClearList()
{
	ListNode*q;
	while(first->next!=NULL)
  {
		q=first->next;
		first=q->next;
		delete q;
	}
	last=first;
}

int List::Length()const//
{
	int len=0;
	for(ListNode* tmpptr=first->next;tmpptr!=NULL;tmpptr=tmpptr->next)
		len++;
  return len;    
}

//search value in list.If succeed, return the pointer to that node, if not, return null
ListNode*List::FindValue(int value)
{
	
	ListNode* tmpptr=new ListNode;
	for(tmpptr=this->first;tmpptr!=NULL;tmpptr=tmpptr->next)
	{
		if(tmpptr->data==value)
			break;
    }
    return tmpptr;
}

ListNode* List::ReturnNodeObjctByIndex(int i)
{
	if(i<-1)return NULL;
	if(i==-1)return first;
	int t=Length();
	if(i>t)return NULL;
	ListNode*tmpptr=first;
	for(int j=0;j<i;j++)
		tmpptr=tmpptr->next;
	return tmpptr->next;
}

//insert new value at index i
int List::InsertAtIndex(int value,int i)
{
	ListNode*tmpptr=ReturnNodeObjctByIndex(i-1);
	tmpptr->next=tmpptr->CreateNode(value,tmpptr->next);
	return 1;
}

void List::InsertAtFirst(int value)
{
	if(!first)
	{
		first=new ListNode(value);
		first->next=NULL;
	}
	else
	{
		ListNode* temp=new ListNode(value);
		temp->next=first->next;
		first=temp;
	}
}


void List::InsertAtLast(int value)
{
	if(!first)
	{
		first=new ListNode(value);
		first->next=NULL;
		last=first;
  }
	else
	{
		ListNode* temp=new ListNode(value);
		last->next=temp;
		temp->next=NULL;
		last=temp;
	}
}

istream& operator>>(istream&in,List&x)
{
	char value;
    in>>value;
	while(value!='q')
	{
		x.InsertAtLast(value-48);
		in>>value;
	}
	return in;
}

ostream& operator<<(ostream&out,List&x)
{
	for(ListNode* tmpptr=x.first;tmpptr!=NULL;tmpptr=tmpptr->next)
		out<<tmpptr->data;
	return out;
}

void List::RevList()
{
	ListNode* r=first;
	ListNode* l=r;
	while(r->next)
	{
		fout<<"l->"<<l->data<<",r->"<<r->data<<endl;
		r=r->next;
		if(l==first)
			l->next=NULL;
		else
			l->next->next=l;
		fout<<"l->"<<l->data<<",r->"<<r->data<<endl<<endl;
		PrintFromNode(r);
		l=r;
	}
	r->next=l;
	first=r;
}

void List::PrintFromNode(ListNode* node)
{
	while(NULL!=node)
	{
		fout<<node->data<<",";
		node=node->next;
	}
	fout<<endl;
}

ListNode* List::RevListWithRecursion(ListNode* head)
{
	ListNode* rhead;
	if(NULL==head)
	{
		fout<<endl;
		return head;
	}
	else if(NULL==head->next)
	{
		fout<<endl;
		return head;
	}
	else
	{
		fout<<"before->"<<head->data<<",";
		rhead=RevListWithRecursion(head->next);
		fout<<"after->"<<head->data<<endl;
		head->next->next=head;
		head->next=NULL;
		fout<<"return->"<<rhead->data<<endl;
		return rhead;
	}
}
