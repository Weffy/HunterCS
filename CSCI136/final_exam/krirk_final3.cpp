#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Books
{
	public:
		Books();
		Books(string number);
		void setISBN();
		void setAuthor();
		void setTitle();
		string getISBN();
		string getAuthor();
		string getTitle();
		void printOne();


	private:
		string isbn;
		string title;
		string author;
		
};

int main()
{
	int select;
	string done = "n";
	int choice;
	string isbnNumber;
//creating 5 books
	vector<Books>novela;
	cout << "We will create 5 books to populate the vector!"<<endl;
	cout << "please enter a ISBN number: ";
	for (int i = 0; i < 5;i++)
	{
		cout <<"Please enter another ISBN for book " << i+1 <<endl;
		cin >> isbnNumber;
		novela.push_back(isbnNumber);
	}

	while (done == "y")
	{
		cout <<"What would you like to do?"<<endl;
		cout <<"(1) set the title for a book"<<endl;
		cout <<"(2) set the author for a book"<<endl;
		cout <<"(3) print the information for a specific book"<<endl;
		cout <<"(4) print information for all books"<<endl;
		cout <<"(5) quit"<<endl;
		cin >> choice;
		if (choice == 1)
		{
			cout <<"which book?"<<endl;
			cin >> select;	
			novela[select].setTitle();			
		}
		else if (choice == 2)
		{
			cout <<"which book?"<<endl;
			cin >> select;	
			novela[select].setAuthor();		
		}
		else if (choice == 3)
		{

			cout <<"which book?"<<endl;
			cin >> select;
			select = select - 1;
			novela[select].printOne();
		}
		else if (choice == 4)
		{
			for (int i = 0; i < novela.size();i++)
			{
				cout <<"Book "<< i+1 <<endl;
				cout <<"title: "<< novela[i].getTitle()<<endl;
				cout <<"isbn: "<<novela[i].getISBN()<<endl;
				cout <<"author: "<<novela[i].getAuthor()<<endl;
			}
		}
		else if (choice == 5)
		{
			done = "y";
		}


	}


	return 0;
}

Books::Books()
{
	isbn = "0000000000000";
}

Books::Books(string number)
{
	isbn = number;
}

void Books::setISBN()
{
	string number;
	cout << "Please enter the ISBN of the book"<<endl;
	cin >> number;
	while (number.length() != 13)
	{
		cout <<"the ISBN must be 13 numbers"<<endl;
		cout <<"the number you entered has: " << number.length() <<endl;
		cout <<"please enter another number"<<endl;
		cin >> number;
	}
	isbn = number;
}
void Books::setAuthor()
{
	string name;
	cout <<"Please enter the Author's name"<<endl;
	cout <<"use a space to separate the first and last names"<<endl;
	cout <<"for example: Wilbur Smith"<<endl;
	cin >> name;
	author = name;
}
void Books::setTitle()
{
	string name;
	cout <<"Please enter the title of the book"<<endl;
	cin >> name;
	title = name;
}
string Books::getISBN()
{
	return isbn;
}
string Books::getAuthor()
{
	return author;
}
string Books::getTitle()
{
	return title;
}
void Books::printOne()
{
	cout <<"title: "<< title <<endl;
	cout <<"isbn: "<< isbn <<endl;
	cout <<"author: "<< author <<endl;

}




