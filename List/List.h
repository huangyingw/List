#include <fstream>
using namespace std;

class List;
class ListNode
{
	friend ostream& operator<<(ostream&out,List&x);
	friend class List;
	public:
		ListNode();
		ListNode(const int& item);
		ListNode *NextNode(){return next;}
		void InsertAfter(ListNode*p);
		
		int RetNodeValue();

		ListNode* GetNode(int item,ListNode* next);
		ListNode*RemoveAfter();
	private:
		int data;
		ListNode* next;
};

class List
{
	public:
		ListNode*first,*last;
        List(){last=first=NULL;}
		List(const int value){last=first=new ListNode(value);}
		~List();
		
		ListNode * FindValue(int value);
		
		List MergeCreateNew();
		
		int*Remove(int i);
		int*Get(int i);
		void List::RevList();
		ListNode* List::RevListWithRecursion(ListNode* head);
		void List::PrintFromNode(ListNode* node);
	private:
		ofstream fout; 	
		
};

int ListNode::RetNodeValue()
{
	return data;
}

List List::MergeCreateNew()
{
	List result(8);
	return result;
}

ListNode::ListNode():next(NULL){}

ListNode::ListNode(const int& item):data(item),next(NULL){}

void ListNode::InsertAfter(ListNode*p)
{
	p->next=next;
	next=p;
}

ListNode* ListNode::GetNode(int item,ListNode* next)
{
    ListNode*newnode=new ListNode(item);
	newnode->next=next;
	return newnode;
}

		
ListNode*ListNode::RemoveAfter()
{
 	ListNode*tmpptr=this->next;
	this->next=tmpptr->next;
	return tmpptr;
}

List::~List()
{
}

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


istream& operator>>(istream&in,List&x)
{
	char value;
    in>>value;
	while(value!='q')
	{
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
	ListNode* m=r;
	while(r->next)
	{
		r=r->next;
		if(m==first)
			m->next=NULL;
		else
			m->next=l;
		l=m;
		m=r;
	}
	r->next=l;
	first=r;
}

void List::PrintFromNode(ListNode* node)
{
	while(NULL!=node)
	{
		cout<<node->data<<",";
		node=node->next;
	}
	cout<<endl;
}

ListNode* List::RevListWithRecursion(ListNode* head)
{
	ListNode* rhead;
	if(NULL==head)
	{
		return head;
	}
	else if(NULL==head->next)
	{
		return head;
	}
	else
	{
		rhead=RevListWithRecursion(head->next);
		head->next->next=head;
		head->next=NULL;
		return rhead;
	}
}
