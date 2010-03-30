#include <fstream>
using namespace std;

class List
{
	public:
		List& MergeCreateNew();
	private:
		ofstream fout; 	
};

List& List::MergeCreateNew()
{
	List result;
	return result;
}
