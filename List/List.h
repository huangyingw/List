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
	friend ostream& operator<<(ostream&out,List&x);
	friend istream& operator>>(istream&,List&);
	friend List MergeCreateNew(List list1,List list2);
	friend void MergeList(List list1,List list2);
	public:
		ListNode*first,*last;
        List(){last=first=NULL;}
		List(const int value){last=first=new ListNode(value);}
		~List();
		void MakeEmpty();
		int Length()const;
		
		ListNode * FindValue(int value);
		
		ListNode * FindAppropriateNode(int value);
		ListNode * FindIndex(int i);
		
		void IncreInsertNode(ListNode *node);
		void PreInsert(int value);
		void AftInsert(int value);
		int InsertAtIndex(int value,int i);
		int*Remove(int i);
		int*Get(int i);
		void List::RevList();
		ListNode* List::RevListWithRecursion(ListNode* head);
		void List::PrintFromNode(ListNode* node);
	
		
};

int ListNode::RetNodeValue()
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


//����������ϲ���һ�����ı�list1
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


//���������ListNode����List�ĳ�Ա������ʵ��
ListNode::ListNode():next(NULL){}

//���캯��������ʼ��ָ���Ա
ListNode::ListNode(const int& item):data(item),next(NULL){}

void ListNode::InsertAfter(ListNode*p)//�ӵ�ǰ������p���
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

//��һ�������뵱ǰ����İ�data�����ĺ���λ�ã��˷���ʹ�õ�ǰ���Ǳ�list�Ѿ��ź���
void List::IncreInsertNode(ListNode *node)
{
	ListNode *pos=FindAppropriateNode(node->data);
	node->next=pos->next;
	pos->next=node;
}
		
ListNode * List::FindAppropriateNode(int value)//�ڵ���������������value���ʺϲ����㣬Ҳ����ǰ����ֵС��value�����һ������ֵ����value
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
		
ListNode*ListNode::RemoveAfter()//������ժ�µ�ǰ������һ��㣬��Ϊɾ�������������ַ
{
 	ListNode*tmpptr=this->next;//tmpptrΪ���Լ��������ʱ����;
	this->next=tmpptr->next;
	return tmpptr;
}

List::~List()
{
	//��������
}

void List::MakeEmpty()//��������Ϊ�ձ�
{
	ListNode*q;
	while(first->next!=NULL)
    {
		q=first->next;//qΪ��ʱ����ı���������֮���ɾ��
		first=q->next;
		delete q;
	}
	last=first;//��βָ��ָ��first
}

int List::Length()const//
{
	//�������ͷ���ĵ�����ĳ���
	//����һ������len���ڼ���
	int len=0;
	for(ListNode* tmpptr=first->next;tmpptr!=NULL;tmpptr=tmpptr->next)
		len++;
    return len;    
}

ListNode*List::FindValue(int value)//�ڵ�����������������value�Ľ�㣬�����ɹ�ʱ���������ظý���ַ�����򷵻�NULLֵ
{
	
	ListNode* tmpptr=new ListNode;
	for(tmpptr=this->first;tmpptr!=NULL;tmpptr=tmpptr->next)
	{
		if(tmpptr->data==value)
			break;
    }
    return tmpptr;
}

ListNode* List::FindIndex(int i)//��λ�������������������е�i��Ԫ�صĵ�ַ����i<-1��i�������н��������򷵻�NULL��
{
	if(i<-1)return NULL;
	if(i==-1)return first;
	//���н�������lenth�������ظ���ʱ����t
	int t=Length();
	if(i>t)return NULL;
	ListNode*tmpptr=first;
	for(int j=0;j<i;j++)
		tmpptr=tmpptr->next;
	return tmpptr->next;
}

int List::InsertAtIndex(int value,int i)//����Ԫ��value�����������е�i��λ��
{
	ListNode*tmpptr=FindIndex(i-1);//���ص�i-1��Ԫ�صĵ�ַ
	tmpptr->next=tmpptr->GetNode(value,tmpptr->next);
	return 1;
}

void List::PreInsert(int value)//��firstͷ��㴦��������
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


void List::AftInsert(int value)//�ڽ�β��������
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

void List::PrintFromNode(ListNode* node)//��ĳ��ָ����㿪ʼ��ӡ����
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
