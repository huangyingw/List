#include <fstream>
using namespace std;

class List;

class List
{
	public:
		List MergeCreateNew();
		
		int*Remove(int i);
		int*Get(int i);
	private:
		ofstream fout; 	
		
};

List List::MergeCreateNew()
{
	List result;
	return result;
}