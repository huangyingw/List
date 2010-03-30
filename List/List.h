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
		
		
		List MergeCreateNew();
		
		int*Remove(int i);
		int*Get(int i);
		void List::RevList();
		ListNode* List::RevListWithRecursion(ListNode* head);
		void List::PrintFromNode(ListNode* node);
	private:
		ofstream fout; 	
		
};

List List::MergeCreateNew()
{
	List result(8);
	return result;
}

ListNode::ListNode():next(NULL){}

ListNode::ListNode(const int& item):data(item),next(NULL){}

List::~List()
{
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
