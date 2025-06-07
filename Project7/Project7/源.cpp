#include<iostream>
using namespace std;

class P
{
public:
	P(int a, int b) {
		cout << "P(int a,int b)\n ";
	}
	explicit P(int a, int b, int c) {
		cout << "explicit P\n";
	}
};
void  fp(const P&) {};
int main()
{
	P p1 = { 77,5,42 };
	fp({ 47,11,3 });
	return 0;
}