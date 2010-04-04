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
		void InsertAfter(ListNode*p);//当前结点插入
		
		int RetNodeValue();//返回指定结点的值

		ListNode* CreateNode(int item,ListNode* next);//建立一个新结点
		ListNode*RemoveAfter();//删除当前结点的下一结点
	private:
		int data;//数据域
		ListNode* next;//链指针域
};

class List//单链表类定义
{
	friend ostream& operator<<(ostream&out,List&x);
	friend istream& operator>>(istream&,List&);
	friend List MergeCreateNew(List list1,List list2);//将两个链表合成第三个，
	friend void MergeList(List list1,List list2);//将两个链表合成一个，
	public:
		ListNode*first,*last;//链表的表头指针，表尾指针
        List(){last=first=NULL;}
		List(const int value){last=first=new ListNode(value);}
		List(const List&);
		~List();
		void MakeEmpty();
		int Length()const;
		
		ListNode * FindValue(int value);//在单链表中搜索含数据value的结点，搜索成功时，函数返回该结点地址；否则返回NULL值
		
		ListNode * FindAppropriateNode(int value);//在单链表中搜索数据value的适合插入结点，也即当前结点的值小于value而其后一个结点的值大于value
		ListNode * FindIndex(int i);//搜索链表中第i个元素的地址
		
		void IncreInsertNode(ListNode *node);//以递增的方式建链表
		void PreInsert(int value);
		void AftInsert(int value);
		int InsertAtIndex(int value,int i);//将新元素value插入在链表中第i个位置
		int*Remove(int i);//将链表中的第i个元素删去
		int*Get(int i);//取出链表中第i个元素
		void RevList();
		ListNode* RevListWithRecursion(ListNode* head);//用递归的方法实现的链表逆序
		void PrintFromNode(ListNode* node);//从某个指定结点开始打印链表
	private:
		ofstream fout; 	
};

List::List(const List& list)
{
	
}

int ListNode::RetNodeValue()//返回指定结点的值
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


//将两个链表合并成一个，改变list1
void MergeList(List list1,List list2)
{
	ListNode*p1,*p2,*temp;
	p1=list1.first;
	p2=list2.first;
	while(p2)
	{
		temp=new ListNode(p2->data);
		p2=p2->next;
		list1.IncreInsertNode(temp);
	}
}


//下面给出类ListNode和类List的成员函数的实现
ListNode::ListNode():next(NULL){}

//构造函数，仅初始化指针成员
ListNode::ListNode(const int& item):data(item),next(NULL){}

void ListNode::InsertAfter(ListNode*p)//从当前结点插入p结点
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

//将一个结点插入当前链表的按data递增的合适位置，此方法使用的前提是本list已经排好序
void List::IncreInsertNode(ListNode *node)
{
	ListNode *pos=FindAppropriateNode(node->data);
	node->next=pos->next;
	pos->next=node;
}
		
ListNode * List::FindAppropriateNode(int value)//在单链表中搜索数据value的适合插入结点，也即当前结点的值小于value而其后一个结点的值大于value
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

ListNode*List::FindValue(int value)//在单链表中搜索含数据value的结点，搜索成功时，函数返回该结点地址；否则返回NULL值
{
	
	ListNode* tmpptr=new ListNode;
	for(tmpptr=this->first;tmpptr!=NULL;tmpptr=tmpptr->next)
	{
		if(tmpptr->data==value)
			break;
    }
    return tmpptr;
}

ListNode* List::FindIndex(int i)//定位函数。函数返回链表中第i个元素的地址。若i<-1或i超出表中结点个数，则返回NULL。
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

int List::InsertAtIndex(int value,int i)//将新元素value插入在链表中第i个位置
{
	ListNode*tmpptr=FindIndex(i-1);//返回第i-1个元素的地址
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

void List::PrintFromNode(ListNode* node)//从某个指定结点开始打印链表
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
