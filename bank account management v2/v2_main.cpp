#include "v2.h"
#include <iostream>

using namespace std;
int main()
{
	//create 2 users
	SavingAccount user1(1, 1001, 0.012);
	SavingAccount user2(1, 1002, 0.012);

	//operate
	user1.deposit(5,10000,1);
	user2.deposit(20,20000,1);

	user1.deposit(35,28000,1);
	user2.withdraw(70,15000,2);

	//interest date=90
	user1.settle(90,3);
	user2.settle(90,3);

	//show info
	cout<<endl;
	user1.show();
	user2.show();
	cout<<endl;
	cout<<"Total: "<<SavingAccount :: getTotal()<<endl;
	system("pause");
	return 0;
}