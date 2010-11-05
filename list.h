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
  List(){last=first=NULL;}
  List(const int value){last=first=new ListNode(value);}
  List(const List&);
  ~List();
  void ClearList();
  int Length()const;


  ListNode * FindAppropriateNode(int value);

  void IncInsertNode(ListNode *node);//Insert a node into current list, given that the current list is sorted already
  void InsertAtLast(int value);
  void RevList();
  ListNode* RevListWithRecursion(ListNode* head);
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
  //计算带表头结点的单链表的长度
  //定义一个变量len用于计数
  int len=0;
  for(ListNode* tmpptr=first->next;tmpptr!=NULL;tmpptr=tmpptr->next)
    len++;
  return len;    
}

//insert new value at index i
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
    cout<<head->data<<endl;
    head->next->next=head;
    head->next=NULL;
    return rhead;
  }
}
