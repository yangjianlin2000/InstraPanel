#include <future>
#include <stdio.h>




class A
{
public:
	A();

	void msgLoop()
	{

	}



};


A::A()
{
	std::future<void> fut = std::async(std::launch::async, &A::msgLoop, this);

}



int main()
{
	A a;

	return 0;
}

