list.cpp:(.text+0x80b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
list.cpp:(.text+0x813): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))'
list.o: In function `__static_initialization_and_destruction_0(int, int)':
list.cpp:(.text+0x886): undefined reference to `std::ios_base::Init::Init()'
list.cpp:(.text+0x88b): undefined reference to `std::ios_base::Init::~Init()'
list.o:(.eh_frame+0x12): undefined reference to `__gxx_personality_v0'
list.o:(.eh_frame+0x67): undefined reference to `__gxx_personality_v0'
collect2: ld returned 1 exit status
make: *** [run] Error 1
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
gcc -c list.cpp
list.cpp:1:22: error: iostream.h: No such file or directory
In file included from list.cpp:2:
list.h:6: error: ISO C++ forbids declaration of ¡®ostream¡¯ with no type
list.h:6: error: ¡®ostream¡¯ is neither function nor member function; cannot be declared friend
list.h:6: error: expected ¡®;¡¯ before ¡®&¡¯ token
list.h:27: error: ISO C++ forbids declaration of ¡®ostream¡¯ with no type
list.h:27: error: ¡®ostream¡¯ is neither function nor member function; cannot be declared friend
list.h:27: error: expected ¡®;¡¯ before ¡®&¡¯ token
list.h:28: error: ISO C++ forbids declaration of ¡®istream¡¯ with no type
list.h:28: error: ¡®istream¡¯ is neither function nor member function; cannot be declared friend
list.h:28: error: expected ¡®;¡¯ before ¡®&¡¯ token
list.h: In constructor ¡®List::List()¡¯:
list.h:33: error: ¡®NULL¡¯ was not declared in this scope
In file included from list.cpp:2:
list.h: In constructor ¡®ListNode::ListNode()¡¯:
list.h:123: error: ¡®NULL¡¯ was not declared in this scope
list.h: In constructor ¡®ListNode::ListNode(const int&)¡¯:
list.h:126: error: ¡®NULL¡¯ was not declared in this scope
list.h: In member function ¡®void List::MakeEmpty()¡¯:
list.h:176: error: ¡®NULL¡¯ was not declared in this scope
list.h: In member function ¡®int List::Length() const¡¯:
list.h:190: error: ¡®NULL¡¯ was not declared in this scope
list.h: In member function ¡®ListNode* List::FindValue(int)¡¯:
list.h:199: error: ¡®NULL¡¯ was not declared in this scope
list.h: In member function ¡®ListNode* List::FindIndex(int)¡¯:
list.h:209: error: ¡®NULL¡¯ was not declared in this scope
list.h:213: error: ¡®NULL¡¯ was not declared in this scope
list.h: In member function ¡®void List::PreInsert(int)¡¯:
list.h:232: error: ¡®NULL¡¯ was not declared in this scope
list.h: In member function ¡®void List::AftInsert(int)¡¯:
list.h:248: error: ¡®NULL¡¯ was not declared in this scope
list.h:255: error: ¡®NULL¡¯ was not declared in this scope
list.h: At global scope:
list.h:260: error: expected constructor, destructor, or type conversion before ¡®&¡¯ token
make: *** [list.o] Error 1
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
gcc -c list.cpp
gcc -o run list.o
/usr/lib/gcc/i486-linux-gnu/4.4.1/../../../../lib/crt1.o: In function `_start':
/build/buildd/eglibc-2.10.1/csu/../sysdeps/i386/elf/start.S:115: undefined reference to `main'
list.o: In function `MergeList(List, List)':
list.cpp:(.text+0x17b): undefined reference to `operator new(unsigned int)'
list.o: In function `ListNode::GetNode(int, ListNode*)':
list.cpp:(.text+0x23f): undefined reference to `operator new(unsigned int)'
list.o: In function `List::MakeEmpty()':
list.cpp:(.text+0x343): undefined reference to `operator delete(void*)'
list.o: In function `List::FindValue(int)':
list.cpp:(.text+0x3ad): undefined reference to `operator new(unsigned int)'
list.o: In function `List::PreInsert(int)':
list.cpp:(.text+0x4c4): undefined reference to `operator new(unsigned int)'
list.cpp:(.text+0x4f8): undefined reference to `operator new(unsigned int)'
list.o: In function `List::AftInsert(int)':
list.cpp:(.text+0x546): undefined reference to `operator new(unsigned int)'
list.cpp:(.text+0x585): undefined reference to `operator new(unsigned int)'
list.o: In function `operator>>(std::basic_istream<char, std::char_traits<char> >&, List&)':
list.cpp:(.text+0x5d8): undefined reference to `std::basic_istream<char, std::char_traits<char> >& std::operator>><char, std::char_traits<char> >(std::basic_istream<char, std::char_traits<char> >&, char&)'
list.cpp:(.text+0x605): undefined reference to `std::basic_istream<char, std::char_traits<char> >& std::operator>><char, std::char_traits<char> >(std::basic_istream<char, std::char_traits<char> >&, char&)'
list.o: In function `operator<<(std::basic_ostream<char, std::char_traits<char> >&, List&)':
list.cpp:(.text+0x63b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(int)'
list.o: In function `List::PrintFromNode(ListNode*)':
list.cpp:(.text+0x6de): undefined reference to `std::cout'
list.cpp:(.text+0x6e3): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(int)'
list.cpp:(.text+0x6f3): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)'
list.cpp:(.text+0x70f): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
list.cpp:(.text+0x716): undefined reference to `std::cout'
list.cpp:(.text+0x71b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))'
list.o: In function `_tmain()':
list.cpp:(.text+0x7fe): undefined reference to `std::cout'
list.cpp:(.text+0x80b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
list.cpp:(.text+0x813): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))'
list.o: In function `__static_initialization_and_destruction_0(int, int)':
list.cpp:(.text+0x886): undefined reference to `std::ios_base::Init::Init()'
list.cpp:(.text+0x88b): undefined reference to `std::ios_base::Init::~Init()'
list.o:(.eh_frame+0x12): undefined reference to `__gxx_personality_v0'
list.o:(.eh_frame+0x67): undefined reference to `__gxx_personality_v0'
collect2: ld returned 1 exit status
make: *** [run] Error 1
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
gcc -c list.cpp
gcc -o run list.o
/usr/lib/gcc/i486-linux-gnu/4.4.1/../../../../lib/crt1.o: In function `_start':
/build/buildd/eglibc-2.10.1/csu/../sysdeps/i386/elf/start.S:115: undefined reference to `main'
list.o: In function `MergeList(List, List)':
list.cpp:(.text+0x17b): undefined reference to `operator new(unsigned int)'
list.o: In function `ListNode::GetNode(int, ListNode*)':
list.cpp:(.text+0x23f): undefined reference to `operator new(unsigned int)'
list.o: In function `List::MakeEmpty()':
list.cpp:(.text+0x343): undefined reference to `operator delete(void*)'
list.o: In function `List::FindValue(int)':
list.cpp:(.text+0x3ad): undefined reference to `operator new(unsigned int)'
list.o: In function `List::PreInsert(int)':
list.cpp:(.text+0x4c4): undefined reference to `operator new(unsigned int)'
list.cpp:(.text+0x4f8): undefined reference to `operator new(unsigned int)'
list.o: In function `List::AftInsert(int)':
list.cpp:(.text+0x546): undefined reference to `operator new(unsigned int)'
list.cpp:(.text+0x585): undefined reference to `operator new(unsigned int)'
list.o: In function `operator>>(std::basic_istream<char, std::char_traits<char> >&, List&)':
list.cpp:(.text+0x5d8): undefined reference to `std::basic_istream<char, std::char_traits<char> >& std::operator>><char, std::char_traits<char> >(std::basic_istream<char, std::char_traits<char> >&, char&)'
list.cpp:(.text+0x605): undefined reference to `std::basic_istream<char, std::char_traits<char> >& std::operator>><char, std::char_traits<char> >(std::basic_istream<char, std::char_traits<char> >&, char&)'
list.o: In function `operator<<(std::basic_ostream<char, std::char_traits<char> >&, List&)':
list.cpp:(.text+0x63b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(int)'
list.o: In function `List::PrintFromNode(ListNode*)':
list.cpp:(.text+0x6de): undefined reference to `std::cout'
list.cpp:(.text+0x6e3): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(int)'
list.cpp:(.text+0x6f3): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)'
list.cpp:(.text+0x70f): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
list.cpp:(.text+0x716): undefined reference to `std::cout'
list.cpp:(.text+0x71b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))'
list.o: In function `_tmain()':
list.cpp:(.text+0x7fe): undefined reference to `std::cout'
list.cpp:(.text+0x80b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
list.cpp:(.text+0x813): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))'
list.o: In function `__static_initialization_and_destruction_0(int, int)':
list.cpp:(.text+0x886): undefined reference to `std::ios_base::Init::Init()'
list.cpp:(.text+0x88b): undefined reference to `std::ios_base::Init::~Init()'
list.o:(.eh_frame+0x12): undefined reference to `__gxx_personality_v0'
list.o:(.eh_frame+0x67): undefined reference to `__gxx_personality_v0'
collect2: ld returned 1 exit status
make: *** [run] Error 1
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
gcc -c list.cpp
gcc -o run list.o
/usr/lib/gcc/i486-linux-gnu/4.4.1/../../../../lib/crt1.o: In function `_start':
/build/buildd/eglibc-2.10.1/csu/../sysdeps/i386/elf/start.S:115: undefined reference to `main'
list.o: In function `MergeList(List, List)':
list.cpp:(.text+0x17b): undefined reference to `operator new(unsigned int)'
list.o: In function `ListNode::GetNode(int, ListNode*)':
list.cpp:(.text+0x23f): undefined reference to `operator new(unsigned int)'
list.o: In function `List::MakeEmpty()':
list.cpp:(.text+0x343): undefined reference to `operator delete(void*)'
list.o: In function `List::FindValue(int)':
list.cpp:(.text+0x3ad): undefined reference to `operator new(unsigned int)'
list.o: In function `List::PreInsert(int)':
list.cpp:(.text+0x4c4): undefined reference to `operator new(unsigned int)'
list.cpp:(.text+0x4f8): undefined reference to `operator new(unsigned int)'
list.o: In function `List::AftInsert(int)':
list.cpp:(.text+0x546): undefined reference to `operator new(unsigned int)'
list.cpp:(.text+0x585): undefined reference to `operator new(unsigned int)'
list.o: In function `operator>>(std::basic_istream<char, std::char_traits<char> >&, List&)':
list.cpp:(.text+0x5d8): undefined reference to `std::basic_istream<char, std::char_traits<char> >& std::operator>><char, std::char_traits<char> >(std::basic_istream<char, std::char_traits<char> >&, char&)'
list.cpp:(.text+0x605): undefined reference to `std::basic_istream<char, std::char_traits<char> >& std::operator>><char, std::char_traits<char> >(std::basic_istream<char, std::char_traits<char> >&, char&)'
list.o: In function `operator<<(std::basic_ostream<char, std::char_traits<char> >&, List&)':
list.cpp:(.text+0x63b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(int)'
list.o: In function `List::PrintFromNode(ListNode*)':
list.cpp:(.text+0x6de): undefined reference to `std::cout'
list.cpp:(.text+0x6e3): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(int)'
list.cpp:(.text+0x6f3): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)'
list.cpp:(.text+0x70f): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
list.cpp:(.text+0x716): undefined reference to `std::cout'
list.cpp:(.text+0x71b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))'
list.o: In function `_tmain()':
list.cpp:(.text+0x7fe): undefined reference to `std::cout'
list.cpp:(.text+0x80b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
list.cpp:(.text+0x813): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))'
list.o: In function `__static_initialization_and_destruction_0(int, int)':
list.cpp:(.text+0x886): undefined reference to `std::ios_base::Init::Init()'
list.cpp:(.text+0x88b): undefined reference to `std::ios_base::Init::~Init()'
list.o:(.eh_frame+0x12): undefined reference to `__gxx_personality_v0'
list.o:(.eh_frame+0x67): undefined reference to `__gxx_personality_v0'
collect2: ld returned 1 exit status
make: *** [run] Error 1
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
gcc -c list.cpp
gcc -o run list.o
/usr/lib/gcc/i486-linux-gnu/4.4.1/../../../../lib/crt1.o: In function `_start':
/build/buildd/eglibc-2.10.1/csu/../sysdeps/i386/elf/start.S:115: undefined reference to `main'
list.o: In function `MergeList(List, List)':
list.cpp:(.text+0x17b): undefined reference to `operator new(unsigned int)'
list.o: In function `ListNode::GetNode(int, ListNode*)':
list.cpp:(.text+0x23f): undefined reference to `operator new(unsigned int)'
list.o: In function `List::MakeEmpty()':
list.cpp:(.text+0x343): undefined reference to `operator delete(void*)'
list.o: In function `List::FindValue(int)':
list.cpp:(.text+0x3ad): undefined reference to `operator new(unsigned int)'
list.o: In function `List::PreInsert(int)':
list.cpp:(.text+0x4c4): undefined reference to `operator new(unsigned int)'
list.cpp:(.text+0x4f8): undefined reference to `operator new(unsigned int)'
list.o: In function `List::AftInsert(int)':
list.cpp:(.text+0x546): undefined reference to `operator new(unsigned int)'
list.cpp:(.text+0x585): undefined reference to `operator new(unsigned int)'
list.o: In function `operator>>(std::basic_istream<char, std::char_traits<char> >&, List&)':
list.cpp:(.text+0x5d8): undefined reference to `std::basic_istream<char, std::char_traits<char> >& std::operator>><char, std::char_traits<char> >(std::basic_istream<char, std::char_traits<char> >&, char&)'
list.cpp:(.text+0x605): undefined reference to `std::basic_istream<char, std::char_traits<char> >& std::operator>><char, std::char_traits<char> >(std::basic_istream<char, std::char_traits<char> >&, char&)'
list.o: In function `operator<<(std::basic_ostream<char, std::char_traits<char> >&, List&)':
list.cpp:(.text+0x63b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(int)'
list.o: In function `List::PrintFromNode(ListNode*)':
list.cpp:(.text+0x6de): undefined reference to `std::cout'
list.cpp:(.text+0x6e3): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(int)'
list.cpp:(.text+0x6f3): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)'
list.cpp:(.text+0x70f): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
list.cpp:(.text+0x716): undefined reference to `std::cout'
list.cpp:(.text+0x71b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))'
list.o: In function `_tmain()':
list.cpp:(.text+0x7fe): undefined reference to `std::cout'
list.cpp:(.text+0x80b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
list.cpp:(.text+0x813): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))'
list.o: In function `__static_initialization_and_destruction_0(int, int)':
list.cpp:(.text+0x886): undefined reference to `std::ios_base::Init::Init()'
list.cpp:(.text+0x88b): undefined reference to `std::ios_base::Init::~Init()'
list.o:(.eh_frame+0x12): undefined reference to `__gxx_personality_v0'
list.o:(.eh_frame+0x67): undefined reference to `__gxx_personality_v0'
collect2: ld returned 1 exit status
make: *** [run] Error 1
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
gcc -o run list.o
/usr/lib/gcc/i486-linux-gnu/4.4.1/../../../../lib/crt1.o: In function `_start':
/build/buildd/eglibc-2.10.1/csu/../sysdeps/i386/elf/start.S:115: undefined reference to `main'
list.o: In function `MergeList(List, List)':
list.cpp:(.text+0x17b): undefined reference to `operator new(unsigned int)'
list.o: In function `ListNode::GetNode(int, ListNode*)':
list.cpp:(.text+0x23f): undefined reference to `operator new(unsigned int)'
list.o: In function `List::MakeEmpty()':
list.cpp:(.text+0x343): undefined reference to `operator delete(void*)'
list.o: In function `List::FindValue(int)':
list.cpp:(.text+0x3ad): undefined reference to `operator new(unsigned int)'
list.o: In function `List::PreInsert(int)':
list.cpp:(.text+0x4c4): undefined reference to `operator new(unsigned int)'
list.cpp:(.text+0x4f8): undefined reference to `operator new(unsigned int)'
list.o: In function `List::AftInsert(int)':
list.cpp:(.text+0x546): undefined reference to `operator new(unsigned int)'
list.cpp:(.text+0x585): undefined reference to `operator new(unsigned int)'
list.o: In function `operator>>(std::basic_istream<char, std::char_traits<char> >&, List&)':
list.cpp:(.text+0x5d8): undefined reference to `std::basic_istream<char, std::char_traits<char> >& std::operator>><char, std::char_traits<char> >(std::basic_istream<char, std::char_traits<char> >&, char&)'
list.cpp:(.text+0x605): undefined reference to `std::basic_istream<char, std::char_traits<char> >& std::operator>><char, std::char_traits<char> >(std::basic_istream<char, std::char_traits<char> >&, char&)'
list.o: In function `operator<<(std::basic_ostream<char, std::char_traits<char> >&, List&)':
list.cpp:(.text+0x63b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(int)'
list.o: In function `List::PrintFromNode(ListNode*)':
list.cpp:(.text+0x6de): undefined reference to `std::cout'
list.cpp:(.text+0x6e3): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(int)'
list.cpp:(.text+0x6f3): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)'
list.cpp:(.text+0x70f): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
list.cpp:(.text+0x716): undefined reference to `std::cout'
list.cpp:(.text+0x71b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))'
list.o: In function `_tmain()':
list.cpp:(.text+0x7fe): undefined reference to `std::cout'
list.cpp:(.text+0x80b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
list.cpp:(.text+0x813): undefined reference to `std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))'
list.o: In function `__static_initialization_and_destruction_0(int, int)':
list.cpp:(.text+0x886): undefined reference to `std::ios_base::Init::Init()'
list.cpp:(.text+0x88b): undefined reference to `std::ios_base::Init::~Init()'
list.o:(.eh_frame+0x12): undefined reference to `__gxx_personality_v0'
list.o:(.eh_frame+0x67): undefined reference to `__gxx_personality_v0'
collect2: ld returned 1 exit status
make: *** [run] Error 1
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
makefile:6: *** empty variable name.  Stop.
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
makefile:6: *** empty variable name.  Stop.
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# clear

root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
makefile:6: *** empty variable name.  Stop.
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
makefile:6: *** empty variable name.  Stop.
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
g++ -c list.cpp
list.cpp:4:20: error: stdafx.h: No such file or directory
list.cpp:6:17: error: List.h: No such file or directory
list.cpp:8: error: ¡®_TCHAR¡¯ has not been declared
list.cpp: In function ¡®int _tmain(int, int**)¡¯:
list.cpp:10: error: ¡®List¡¯ was not declared in this scope
list.cpp:10: error: expected ¡®;¡¯ before ¡®list1¡¯
list.cpp:12: error: ¡®list1¡¯ was not declared in this scope
list.cpp:23: error: ¡®cout¡¯ was not declared in this scope
list.cpp:23: error: ¡®endl¡¯ was not declared in this scope
make: *** [list.o] Error 1
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
g++ -c list.cpp
In file included from list.cpp:5:
list.h:49: error: extra qualification ¡®List::¡¯ on member ¡®RevList¡¯
list.h:50: error: extra qualification ¡®List::¡¯ on member ¡®RevListWithRecursion¡¯
list.h:51: error: extra qualification ¡®List::¡¯ on member ¡®PrintFromNode¡¯
make: *** [list.o] Error 1
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
g++ -c list.cpp
g++ -o run list.o
/usr/lib/gcc/i486-linux-gnu/4.4.1/../../../../lib/crt1.o: In function `_start':
/build/buildd/eglibc-2.10.1/csu/../sysdeps/i386/elf/start.S:115: undefined reference to `main'
collect2: ld returned 1 exit status
make: *** [run] Error 1
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
g++ -c list.cpp
g++ -o run list.o
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
make: `run' is up to date.
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
make: `run' is up to date.
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
make: `run' is up to date.
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
g++ -c list.cpp
g++ -o run list.o
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
g++ -c list.cpp
In file included from /usr/include/c++/4.4/ios:39,
                 from /usr/include/c++/4.4/ostream:40,
                 from /usr/include/c++/4.4/iostream:40,
                 from list.cpp:4:
/usr/include/c++/4.4/bits/ios_base.h: In copy constructor ¡®std::basic_ios<char, std::char_traits<char> >::basic_ios(const std::basic_ios<char, std::char_traits<char> >&)¡¯:
/usr/include/c++/4.4/bits/ios_base.h:790: error: ¡®std::ios_base::ios_base(const std::ios_base&)¡¯ is private
/usr/include/c++/4.4/iosfwd:47: error: within this context
/usr/include/c++/4.4/iosfwd: In copy constructor ¡®std::basic_ofstream<char, std::char_traits<char> >::basic_ofstream(const std::basic_ofstream<char, std::char_traits<char> >&)¡¯:
/usr/include/c++/4.4/iosfwd:84: note: synthesized method ¡®std::basic_ios<char, std::char_traits<char> >::basic_ios(const std::basic_ios<char, std::char_traits<char> >&)¡¯ first required here 
/usr/include/c++/4.4/streambuf: In copy constructor ¡®std::basic_filebuf<char, std::char_traits<char> >::basic_filebuf(const std::basic_filebuf<char, std::char_traits<char> >&)¡¯:
/usr/include/c++/4.4/streambuf:770: error: ¡®std::basic_streambuf<_CharT, _Traits>::basic_streambuf(const std::basic_streambuf<_CharT, _Traits>&) [with _CharT = char, _Traits = std::char_traits<char>]¡¯ is private
/usr/include/c++/4.4/iosfwd:78: error: within this context
/usr/include/c++/4.4/iosfwd: In copy constructor ¡®std::basic_ofstream<char, std::char_traits<char> >::basic_ofstream(const std::basic_ofstream<char, std::char_traits<char> >&)¡¯:
/usr/include/c++/4.4/iosfwd:84: note: synthesized method ¡®std::basic_filebuf<char, std::char_traits<char> >::basic_filebuf(const std::basic_filebuf<char, std::char_traits<char> >&)¡¯ first required here 
In file included from list.cpp:6:
list.h: In copy constructor ¡®List::List(const List&)¡¯:
list.h:25: note: synthesized method ¡®std::basic_ofstream<char, std::char_traits<char> >::basic_ofstream(const std::basic_ofstream<char, std::char_traits<char> >&)¡¯ first required here 
In file included from list.cpp:6:
list.h: In function ¡®List MergeCreateNew(List, List)¡¯:
list.h:102: note: synthesized method ¡®List::List(const List&)¡¯ first required here 
make: *** [list.o] Error 1
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
g++ -c list.cpp
g++ -o run list.o
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
g++ -c list.cpp
g++ -o run list.o
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
g++ -c list.cpp
g++ -o run list.o
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# make
g++ -c list.cpp
In file included from /usr/include/c++/4.4/ios:39,
                 from /usr/include/c++/4.4/ostream:40,
                 from /usr/include/c++/4.4/iostream:40,
                 from list.cpp:4:
/usr/include/c++/4.4/bits/ios_base.h: In copy constructor ¡®std::basic_ios<char, std::char_traits<char> >::basic_ios(const std::basic_ios<char, std::char_traits<char> >&)¡¯:
/usr/include/c++/4.4/bits/ios_base.h:790: error: ¡®std::ios_base::ios_base(const std::ios_base&)¡¯ is private
/usr/include/c++/4.4/iosfwd:47: error: within this context
/usr/include/c++/4.4/iosfwd: In copy constructor ¡®std::basic_ofstream<char, std::char_traits<char> >::basic_ofstream(const std::basic_ofstream<char, std::char_traits<char> >&)¡¯:
/usr/include/c++/4.4/iosfwd:84: note: synthesized method ¡®std::basic_ios<char, std::char_traits<char> >::basic_ios(const std::basic_ios<char, std::char_traits<char> >&)¡¯ first required here 
/usr/include/c++/4.4/streambuf: In copy constructor ¡®std::basic_filebuf<char, std::char_traits<char> >::basic_filebuf(const std::basic_filebuf<char, std::char_traits<char> >&)¡¯:
/usr/include/c++/4.4/streambuf:770: error: ¡®std::basic_streambuf<_CharT, _Traits>::basic_streambuf(const std::basic_streambuf<_CharT, _Traits>&) [with _CharT = char, _Traits = std::char_traits<char>]¡¯ is private
/usr/include/c++/4.4/iosfwd:78: error: within this context
/usr/include/c++/4.4/iosfwd: In copy constructor ¡®std::basic_ofstream<char, std::char_traits<char> >::basic_ofstream(const std::basic_ofstream<char, std::char_traits<char> >&)¡¯:
/usr/include/c++/4.4/iosfwd:84: note: synthesized method ¡®std::basic_filebuf<char, std::char_traits<char> >::basic_filebuf(const std::basic_filebuf<char, std::char_traits<char> >&)¡¯ first required here 
In file included from list.cpp:6:
list.h: In copy constructor ¡®List::List(const List&)¡¯:
list.h:25: note: synthesized method ¡®std::basic_ofstream<char, std::char_traits<char> >::basic_ofstream(const std::basic_ofstream<char, std::char_traits<char> >&)¡¯ first required here 
In file included from list.cpp:6:
list.h: In function ¡®List MergeCreateNew(List, List)¡¯:
list.h:102: note: synthesized method ¡®List::List(const List&)¡¯ first required here 
make: *** [list.o] Error 1
root@linux_programming:/media/myproject/git/c_c++/linux/data_structure/List# 