#include<iostream>
#include <math.h>
using namespace std;
class A
{
	double m_a;
	double m_b;
	public:
		A()
		{
			
		} 
		 operator double ()const
		 { 
		    cout<<"¿´ÕâÀï"<<endl; 
		 	return m_b;
		 } 
		 
}; 


int main()
{   
    A a;
    cout<<a<<endl;

}
