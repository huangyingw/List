#include <fstream>
using namespace std;

class List
{
	public:
		List(const List& list);
		List();
		List MergeCreateNew();
	private:
		ofstream fout; 	
};

List::List()
{
	//fout=list.fout;
}

List::List(const List& list)
{
	//fout=list.fout;
}

List List::MergeCreateNew()
{
	List result;
	return result;
}
