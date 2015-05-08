#include "v2.h"
#include <cmath>
#include <iostream>

using namespace std;
	double SavingAccount :: total=0;
	SavingAccount :: SavingAccount(int date, int id, double rate) : id(id), balance(0),rate(rate),lastDate(date),accumulation(0){
		cout<<"Date: "<<date<<"\tUser id"<<id<<" is created"<<endl;
	}

	void SavingAccount :: record(int date, double amount, int flag){	//amount = money
		accumulation = accumulate(date);
		lastDate = date;
		amount = floor(amount*100+0.5)/100;
		balance += amount;
		total += amount;
		if(flag==1){
			cout<<"Date: "<<date<<"\tUser id: "<<id<<"\tDeposit: "<<amount<<"\tBalance: "<<balance<<endl;
		}
		else if(flag==2){
			cout<<"Date: "<<date<<"\tUser id: "<<id<<"\tWithdraw: "<<amount<<"\tBalance: "<<balance<<endl;
		}
		else{
			cout<<"Date: "<<date<<"\tUser id: "<<id<<"\tInterest: "<<amount<<"\tBalance: "<<balance<<endl;
		}
	} 
	void SavingAccount :: deposit(int date, double amount, int flag){
		record(date, amount, flag);
	}
	void SavingAccount :: withdraw(int date, double amount, int flag){
		if(amount>getBalance()){
			cout<<"Error : not enough money"<<endl;
		}
		else{
			record(date, -amount, flag);
		}
	} 
	void SavingAccount :: settle(int date, int flag){
		double interest = accumulate(date)*rate/365;
		if(interest != 0){
			record(date, interest,flag);
		}
		accumulation = 0;
	}
	void SavingAccount :: show() const{
		cout<<"#"<<id<<"\tBalance: "<<balance<<endl;
	}