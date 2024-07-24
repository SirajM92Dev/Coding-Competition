#include <iostream>
#include <string>
using namespace std;
const int Max = 220;

struct library
{
    string book_name;
    string author;
    int sr_no;
};

void add_book(library arr[Max], int &count)
{
    cout << "Enter Title of the Book: ";
    cin.ignore();
    getline(cin, arr[count].book_name);
    cout << "Enter Author Name: ";
    getline(cin, arr[count].author);
    
    count++;
    arr[count].sr_no = count;
    cout << "Book was Added Successfully at Serial Number: " << arr[count].sr_no << endl;
}

void remove_book(library arr[Max], int &count)
{
	int ch, flag = 0;
s:
	cout << "Enter..." << endl;
	cout << "1. To remove by Serial Number" << endl;
	cout << "2. To remove by Title" << endl;
	cin >> ch;
	
	if(ch == 1)
	{
		int s_num;
		cout << "Enter Serial Number of Book: ";
		cin >> s_num;
		
		for(int i=0; i<count; i++)
		{
			if(arr[i].sr_no +1 == s_num)
			{
				flag = 1;
				char choice;
				// Printing Details About Book
			inv:
				cout << "Book Found at Serial Number: " << arr[i].sr_no +1 << endl;
				cout << "Title: \"" << arr[i].book_name << "\" " << endl;
				cout << "Author: \"" << arr[i].author << "\" " << endl;
				
				cout << "Do You want to Remove it (Y / N)?: ";
				cin >> choice;
				
				if(choice == 'Y' || choice == 'y')
				{
					for(int j=i; j< count-1; j++)
						arr[j] = arr[j+1];
						
					count--;
					cout << "Book at Serial Number: " << arr[i].sr_no +1 << " was removed Successfully!" << endl;
					break;
				}
				else if(choice == 'N' || choice == 'n')
					cout << "Request Cancelled!" << endl;
				else
				{
					cout << "Invalid Input!" << endl;
					goto inv;
				}
			}
		
		}
	}
	else if(ch == 2)
	{
		string title;
		cout << "Enter Title: ";
		cin.ignore();
		getline(cin, title);
		
		for(int i=0; i<count; i++)
		{
			if(arr[i].book_name == title)
			{
				flag = 1;
				char choice;
				// Printing Details About Book
			invalid:
				cout << "Book Found at Serial Number: " << arr[i].sr_no +1 << endl;
				cout << "Title: \"" << arr[i].book_name << "\" " << endl;
				cout << "Author: \"" << arr[i].author << "\" " << endl;
				
				cout << "Do You want to Remove it (Y / N)?: ";
				cin >> choice;
				
				if(choice == 'Y' || choice == 'y')
				{
					for(int j=i; j< count-1; j++)
						arr[j] = arr[j+1];
						
					count--;
					cout << "Book at Serial Number: " << arr[i].sr_no +1 << " having Title: \""<< arr[i].book_name << "\" was removed Successfully!" << endl;
					break;
				}
				else if(choice == 'N' || choice == 'n')
					cout << "Request Cancelled!" << endl;
				else
				{
					cout << "Invalid Input!" << endl;
					goto invalid;
				}
			}
		}
	}
	else
	{
		cout << "Invalid Choice!" << endl;
		goto s;
	}
	
	if(flag == 0)
		cout << "There is no Book of Provided Title!" << endl;
}

void search_book(library arr[Max], int &count)
{
	int ch, flag = 0;
i:
	cout << "Enter..." << endl;
	cout << "1. To Search by Serial Number" << endl;
	cout << "2. To Search by Title" << endl;
	cin >> ch;
	if(ch == 1)
	{
		int s_num;
		cout << "Enter Serial Number to Search: ";
		cin >> s_num;
		for(int i=0; i<count; i++)
		{
			if(arr[i].sr_no +1 == s_num)
			{
				flag = 1;
				cout << "Book Found at Serial Number: " << arr[i].sr_no +1 << endl;
				cout << "Title: " << arr[i].book_name << endl;
				cout << "Author: " << arr[i].author << endl;
				break;
			}
		}
	}
	else if(ch == 2)
	{
		string title;
		cout << "Enter Title: ";
		cin.ignore();
		getline(cin, title);
		
		for(int i=0; i<count; i++)
		{
			if(arr[i].book_name == title)
			flag = 1;
				cout << "Book Found at Serial Number: " << arr[i].sr_no +1 << endl;
				cout << "Title: " << arr[i].book_name << endl;
				cout << "Author: " << arr[i].author << endl;
				break;
		}
	}
	else
	{
		cout << "Invalid Choice" << endl;
		goto i;
	}
	
	if(!flag)
		cout << "There is no Book of Provided Title!" << endl;
}

void book_quantity(library arr[Max], int &count)
{
	string title;
    int quantity = 0;
	cout << "Enter Title: ";
	cin.ignore();
	getline(cin, title);
	
	for(int i=0; i<count; i++)
	{
		if(arr[i].book_name == title)
			quantity++;
	}
	cout << "Total Quantity of the Book: \"" << title << "\" is: " << quantity; 
}

void print_all(library arr[Max], int &count)
{
	if(count == 0)
		cout << "There is Currently no Book in the Library!" << endl;
	else
	{
		for(int i=0; i<count; i++)
		{
			cout << "******************************" << endl;
			cout << "Serial Number: " << arr[i].sr_no +1 << endl;
			cout << "Title: " << arr[i].book_name << endl;
			cout << "Author: " << arr[i].author << endl;
		}
	}
}

int main()
{
    library arr[Max];
    int ch, count = 0;
    cout << "*******   Welcome to ABC Library!   *******" << endl;
    do
    {
    enter:
        cout << endl << "Enter ..." << endl;
        cout << "1. To Add a Book" << endl;
        cout << "2. To Remove a Book" << endl;
        cout << "3. To Search for a Book" << endl;
        cout << "4. To check Quantity a Book" << endl;
        cout << "5. To Print Info of all Exiting Books" << endl;
        cout << "6. To Exit" << endl;
        cin >> ch;

        if(ch == 1)
            add_book(arr, count);
        else if(ch == 2)
            remove_book(arr, count);
        else if(ch == 3)
            search_book(arr, count);
        else if(ch == 4)
            book_quantity(arr, count);
        else if(ch == 5)
            print_all(arr, count);
        else if(ch == 6)
        {
        	cout << "Exiting Program!" << endl;
            return 0;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
            goto enter;
        }
    } while(count < 220);
    
    return 0;
}