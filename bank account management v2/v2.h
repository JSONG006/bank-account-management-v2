#ifndef   _ACCOUNT_H
#define  _ACCOUNT_H

class SavingAccount{					 //save the user account
private:
	int id;								 //user id
	double balance;				 //user balance
	double rate;					 //year rate
	int lastDate;					 //last time to change date
	double  accumulation;	 //the sum of balance
	static double total;			 //all users' money
	void record(int date, double amount, int flag);

	double accumulate(int date) const {			//get the sum of the balance
		return accumulation+balance*(date-lastDate);
	}

public:
	SavingAccount (int date, int id, double rate);
	int getId() const{
		return id;
	};
	double getBalance() const{
		return balance;
	}
	double getRate() const{
		return rate;
	}
	static double getTotal(){
		return total;
	}
	void deposit(int data, double amount, int flag);			//save money
	void withdraw(int date, double amount, int flag);		//withdraw money
	void settle(int date, int flag);	//calculate rate
	void show() const;				    //show the account info
};
#endif