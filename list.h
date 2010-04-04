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
		ListNode*RemoveAfter();
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
        List(){last=first=NULL;}
		List(const int value){last=first=new ListNode(value);}
		List(const List&);
		~List();
		void MakeEmpty();
		int Length()const;
		
		ListNode * FindValue(int value);//search value in list.If succeed, return the pointer to that node, if not, return null
		
		ListNode * FindAppropriateNode(int value);
		ListNode * ReturnNodeObjctByIndex(int i);
		
		void IncInsertNode(ListNode *node);//Insert a node into current list, given that the current list is sorted already
		void PreInsert(int value);
		void AftInsert(int value);
		int InsertAtIndex(int value,int i);//insert new value at index i
		int RemoveByIndex(int i);//remove the node by index i
		void RevList();
		ListNode* RevListWithRecursion(ListNode* head);
		void PrintFromNode(ListNode* node);
	private:
		ofstream fout; 	
};

List::List(const List& list)
{
	
}

int ListNode::GetNodeValue()//返回指定结点的值
{
	return data;
}


List MergeCreateNew(List list1,List list2)//将两个链表合成第三个，
{
	List result;
	ListNode*p1,*p2;
	p1=list1.first;
	p2=list2.first;
	if(p1->data<p2->data)
	{
		result.AftInsert(p1->data);
		p1=p1->next;
	}
	else
	{
		result.AftInsert(p2->data);
		p2=p2->next;
	}
	while(p1&&p2)
	{
		if(p1->data<p2->data)
		{
			result.AftInsert(p1->data);
			p1=p1->next;
		}
		else
		{
			result.AftInsert(p2->data);
			p2=p2->next;
		}
	}
	while(p1)
	{
		result.AftInsert(p1->data);
		p1=p1->next;
	}
	while(p2)
	{
		result.AftInsert(p2->data);
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
		
ListNode*ListNode::RemoveAfter()//从链中摘下当前结点的下一结点，并为删除它而返回其地址
{
 	ListNode*tmpptr=this->next;//tmpptr为我自己定义的临时变量;
	this->next=tmpptr->next;
	return tmpptr;
}

List::~List()
{
	//析构函数
}

void List::MakeEmpty()//将链表置为空表
{
	ListNode*q;
	while(first->next!=NULL)
    {
		q=first->next;//q为临时定义的变量，用完之后得删除
		first=q->next;
		delete q;
	}
	last=first;//将尾指针指向first
}

int List::Length()const//
{
	//计算带表头结点的单链表的长度
	//定义一个变量len用于计数
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

ListNode* List::ReturnNodeObjctByIndex(int i)//定位函数。函数返回链表中第i个元素的地址。若i<-1或i超出表中结点个数，则返回NULL。
{
	if(i<-1)return NULL;
	if(i==-1)return first;
	//表中结点个数用lenth函数返回给临时变量t
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
	ListNode*tmpptr=ReturnNodeObjctByIndex(i-1);//返回第i-1个元素的地址
	tmpptr->next=tmpptr->CreateNode(value,tmpptr->next);
	return 1;
}

void List::PreInsert(int value)//在first头结点处插入数据
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


void List::AftInsert(int value)//在结尾插入数据
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
		x.AftInsert(value-48);
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
