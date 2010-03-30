#include <fstream>
using namespace std;

class List;
class ListNode
{
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