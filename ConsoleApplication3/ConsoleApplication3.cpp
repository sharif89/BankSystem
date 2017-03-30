// ConsoleApplication3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

#include <iostream>





using namespace std;

class account
{
	char cust_name[20];
	int acc_no;
	char acc_type[20];
public:
	void get_accinfo()
	{
		cout << "\n\nEnter Customer Name : ";
		cin >> cust_name;
		cout << "Enter Account Number : ";
		cin >> acc_no;
		cout << "Enter Account Type : ";
		cin >> acc_type;
	}
	void display_accinfo()
	{
		cout << "\n\nCustomer Name : " << cust_name;
		cout << "\nAccount Number : " << acc_no;
		cout << "\nAccount Type :" << acc_type; "\n";
	}
};

class checking : public account
{
	 static float balance;
public:
	void disp_currbal()
	{
		cout << "\nBalance : " << balance; "\n";
	}
	void deposit_currbal()
	{
		float deposit;
		cout << "\nEnter amount to Deposit : ";
		cin >> deposit;
		balance = balance + deposit;
	}
	void order_checks()
	{
		float checkOrder;
		char orderFee= 15;
		cout << "\n\nOrder checks for $15\n";
		balance = balance - orderFee;
		
		
	}

	void withdraw_currbal()
	{
		float penalty=5, withdraw;
		cout << "\n\nBalance : " << balance;
		cout << "\nEnter amount to be withdraw :";
		cin >> withdraw;
		balance = balance - withdraw;
		if (balance < 500)
		{
			balance = balance - penalty;
			cout << "\nBalance after deducting penalty : " << balance;
		}
		else if (withdraw > balance)
		{
			cout << "\n\nYou have overdrawn your account...\n";
			balance = balance + withdraw;
		}
		else
			cout << "\nAfter withdrawl your balance is now : " << balance;
	}
};

class savings : public account
{
	static float savbal;
public:
	void disp_savbal()
	{
		cout << "\nBalance : " << savbal; "\n";
	}
	void deposit_savbal()
	{
		float savdeposit, interest;
		cout << "\nEnter amount to Deposit : ";
		cin >> savdeposit;
		savbal = savbal + savdeposit;
		if (savbal >= 10000)

		{
			interest = (savbal * 2) / 100;
			savbal = savbal + interest;
		}

		else
		{
			interest = (savbal * 1) / 100;
			savbal = savbal + interest;
		}
	}
	void withdraw_savbal()
	{
		float savwithdraw;
		cout << "\nBalance :- " << savbal;
		cout << "\nEnter amount to be withdraw :-";
		cin >> savwithdraw;
		savbal = savbal - savwithdraw;
		if (savwithdraw > savbal)
		{
			cout << "\n\nYou have overdrawn your account...\n";
			savbal = savbal + savwithdraw;
		}
		else
			cout << "\nAfter Withdrawl your Balance is now: \n" << savbal;
	}
};


float checking::balance;
float savings::savbal;


void main()
{
	system("cls");
	checking c1;
	savings s1;

	cout << "\nEnter S-Savings, C-Checkings, D-CD...\n\n";
	char type;
	cin >> type;

	int choice;

	if (type == 's' || type == 'S')
	{
		s1.get_accinfo();
		while (1)
		{
			
			cout << "\n\nChoose Your Choice\n";
			cout << "1) Deposit\n";
			cout << "2) Withdraw\n";
			cout << "3) Display Balance\n";
			cout << "4) Display with full Details\n";
			cout << "5) Exit\n";
			cout << "6) Open another account\n";
			cin >> choice;
			switch (choice)
			{
			case 1: s1.deposit_savbal(); "\n";
				getchar();
				break;
			case 2: s1.withdraw_savbal(); "\n";
				getchar();
				break;
			case 3: s1.disp_savbal(); "\n";
				getchar();
				break;
			case 4: s1.display_accinfo(); "\n";
				s1.disp_savbal();
				getchar();
				break;
			case 5: exit(0);
			case 6: main();
			default: cout << "\n\nEntered choice is invalid, please enter correct value\n\n";
			}
		}
	}
	else
	{
		{
			c1.get_accinfo();
			while (1)
			{
				cout << "\n\nChoose Your Choice\n";
				cout << "1) Deposit\n";
				cout << "2) Withdraw\n";
				cout << "3) Order Checks\n";
				cout << "4) Display Balance\n";
				cout << "5) Display with full Details\n";
				cout << "6) Exit\n";
				cout << "7) Open another account\n";
				cin >> choice;
				switch (choice)
				{
				case 1: c1.deposit_currbal(); "\n";
					getchar();
					break;
				case 2: c1.withdraw_currbal(); "\n";
					getchar();
					break;
				case 3: c1.order_checks(); "\n";
					getchar();
					break;
				case 4: c1.disp_currbal(); "\n";
					getchar();
					break;
				case 5: c1.display_accinfo(); "\n";
					c1.disp_currbal();
					getchar();
					break;
				case 6: exit(0);
				case 7: main();
				default: cout << "\n\nEntered choice is invalid, please enter correct value\n\n";

				}
			}
		}

	}
}

