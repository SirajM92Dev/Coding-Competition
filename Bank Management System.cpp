#include <iostream>
#include <string>
using namespace std;
const int size = 100;
struct Customer
{
    string name;
    int acc_no;
    float balance;
};

void Open_Account(Customer customer[size], int &count)
{
    int balance;
    cout << "Enter Name: ";
    getline(cin, customer[count].name);
    customer[count].acc_no = count;
s:
    cout << "Enter Money To Deposit (Minimum: 500 PKR): " << endl;
    cin >> balance;

    if(balance < 500)
    {
        cout << "Minimum Balance to Open Account is PKR 500/-" << endl;
        goto s;
    }
    else
    {
        customer[count].balance = balance;
        cout << "Your Account was opened Successfully!" << endl;
        count++;
        cout << "Your Account Number is " << count << endl;
        cout << "Your Balnce is " << balance << endl;
    }
}

void Print_Info(Customer customer[size], int &count)
{
    int acc_num, flag = 0;
    cout << "Enter Account Number: ";
    cin >> acc_num;

    for(int i=0; i<acc_num; i++)
    {
        if(customer[i].acc_no +1 == acc_num)
        {
            flag = 1;
            cout << "Name: " << customer[i].name << endl;
            cout << "Account Number: " << customer[i].acc_no +1 << endl;
            cout << "Current Balance: " << customer[i].balance << endl;
        }
    }
    if(flag == 0)
        cout << "No Data Exits on provided Account Number!" << endl;
}

void Balance_Check(Customer customer[size], int &count)
{
	int acc_num, flag = 0;
	cout << "Enter Account Number: ";
	cin >> acc_num;
	
	for(int i=0; i<count; i++)
	{
		if(customer[i].acc_no +1 == acc_num)
		{
			flag = 1;
			cout << "Balance is: " << customer[i].balance << endl;
		}
	}
	if(flag == 0)
		cout << "Provided Account Number Doesn't Exit!" << endl;
}

void Money_Deposit(Customer customer[size], int &count)
{
	int acc_num, flag = 0;
	cout << "Enter Account Number: ";
	cin >> acc_num;
	
	for(int i=0; i<count; i++)
	{
		if(customer[i].acc_no +1 == acc_num)
		{
			flag = 1;
			int bal;
			cout << "Enter Balance to Deposit: ";
			cin >> bal;
			
			customer[i].balance += bal;
			cout << bal << " PKR was added to your Account Successfully!" << endl;
			cout << "Your New Balance is: " << customer[i].balance << endl;
		}
		if(flag == 0)
			cout << "Provided Account Number Doesn't Exit!" << endl;
	}
}

void Money_Withdraw(Customer customer[], int &count)
{
	int acc_num, flag = 0;
	cout << "Enter Account Number: ";
	cin >> acc_num;
	
	for(int i=0; i<count; i++)
	{
		if(customer[i].acc_no +1 == acc_num)
		{
			flag = 1;
	transaction:
			int bal;
            cout << "Current Balance is: " << customer[i].balance << endl;
			cout << "Enter Balance to Withdraw: ";
			cin >> bal;
			
			if(customer[i].balance < bal)
			{
				cout << "Insufficient Money. Your Current Balance is " << customer[i].balance << " PKR!" << endl;
				goto transaction;
			}
			else
			{
				char ch;
			inv_in:
				cout << "Do you want to Withdraw " << bal << " PKR? (Y / N):" << endl;
				cin >> ch;
				if(ch == 'Y' || ch == 'y')
				{
					customer[i].balance -= bal;
					cout << "Transaction Successfull!" << endl;
					cout << "Remaining Balance is: " << customer[i].balance << " PKR!" << endl;
				}
				else if(ch == 'N' || ch == 'n')
				{
					cout << "Transaction Cancelled!" << endl;
					goto transaction;
				}
				else
				{
					cout << "Invalid Input" << endl;
					goto inv_in;
				}
			}
		}
	}
	if(flag == 0)
		cout << "Provided Account Number Doesn't Exit!" << endl;
}

int main()
{
    Customer customer[size];
    int ch, count = 0;
j:
    cout << endl << " ******* Welcome to ABC Bank! *******" << endl;
    cout << "Enter..." << endl;
    cout << "1. To Open Your Account" << endl;
    cout << "2. To Check Your Balance" << endl;
    cout << "3. To Deposit Money" << endl;
    cout << "4. To Withdraw Money" << endl;
    cout << "5. To Print Details of an Account" << endl;
    cout << "6. To Exit" << endl;
    cin >> ch;
    cin.ignore();
    switch(ch)
    {
        case 1:
            Open_Account(customer, count);
            goto j;
            break;
        case 2:
            Balance_Check(customer, count);
            goto j;
            break;
        case 3:
            Money_Deposit(customer, count);
            goto j;
            break;
         case 4:
             Money_Withdraw(customer, count);
             goto j;
             break;
        case 5:
            Print_Info(customer, count);
            goto j;
            break;
        case 6:
            cout << "Exiting Program!" << endl;
            return 0; 
            break;
        default:
            cout << "Invalid Input!" << endl;
            goto j;
    }
    return 0;
}