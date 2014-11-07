#include <iostream>
#include <cstdlib>
#include <exception>
#include <stdexcept>
using namespace std;
const int LIST_SIZE=100;
class AList
{
	public:
		AList(); // Default constructor
		 ~AList();//default destructor
		bool is_empty(); // determines whether alist is empty
		int length(); // determines the length of the list
		void insert(int new_index, int item);// n item intyo the new_index
		void delete_item_at_index(int index);// delet an item from indexi
		void getItem(int index, int& item); //retrieve the item from index
		void printList();// print the content of a list;
		void insertAtStart(int item);//inserts an item at the start of the list.
		void insertAtEnd(int item);//inserts an item at the end of the list.
		void deleteItem(int search, int index);
		void shiftLeft(int index);
	private:
		int items[LIST_SIZE];
		int size; 
};


int main()
{
	int item;
	int index;
	bool done = false;
	AList l1;
	int selection;
	while (!done)
	{
		cout <<"What would you like to do?"<<endl;
		cout <<"(1) insert an item at a specific index"<<endl;
		cout <<"(2) delete an item at a specific index"<<endl;
		cout <<"(3) insert at the start of the list"<<endl;
		cout <<"(4) insert at the end of the list"<<endl;
		cout <<"(5) display the contents of at a specific index"<<endl;
		cout <<"(6) delete all instances of an item"<<endl;
		cout <<"(7) print the list"<<endl;
		cout <<"(8) exit"<<endl;
		cin >> selection;

		if (selection == 1) //insert at index
		{
			
			cout <<"What would you like to add to the list?"<<endl;
			cin >> item;
			cout <<"Where would you like to store it?"<<endl;
			cin >> index;
			l1.insert(index, item);
		}
		else if (selection == 2) //delete at index
		{
			cout <<"What index would you like to erase?"<<endl;
			cin >> index;
			l1.delete_item_at_index(index);
		}
		else if (selection == 3) //insert at start
		{
			cout <<"What would you like to add to the list?"<<endl;
			cin >> item;
			l1.insertAtStart(item);
		}
		else if (selection == 4) //insert at end
		{
			cout <<"What would you like to add to the list?"<<endl;
			cin >> item;
			l1.insertAtEnd(item);

		}
		else if (selection == 5) //display contents at index
		{
			item = 0;
			cout <<"what index would you like to see?"<<endl;
			cin >> index;
			l1.getItem(index, item);
			cout <<item<<endl;
		}
		else if (selection == 6) //delete all instances of an item
		{
			index = l1.length();
			cout <<"What would you like to delete from the list?"<<endl;
			cin >> item;
			l1.deleteItem(item, index);
//			l1.shiftLeft(index);
		}
		else if (selection == 7) //print
		{
			l1.printList();
		}
		else if (selection == 8) //exit
		{
			done = true;
		}

	}



	return 0;
}

AList::AList()
{
	size=0;
}

bool AList::is_empty()
{
	return (size==0);
}


int AList::length()
{
	return size;
}

void AList::getItem(int index, int& item)
{
	item=items[index];
}


void AList::insert(int index, int item)
{
	for(int i=size;i>=index; i--) //shift all items
	{
		items[i+1]=items[i];
	}
	items[index]=item;
	size++;
}

void AList::delete_item_at_index(int index)
{
	for(int i=index; i<size; i++)
	{
		items[i]=items[i+1];
	}
	size--;

      
}
void AList::printList()
{
	for(int i=1; i<=size;i++)
	{
		cout<<"item at index: "<<i<< " is "<<items[i]<<endl;
	}
	cout<<endl;
}

AList::~AList()
{
    size=0;
}

void AList::insertAtStart(int item)
{
	int counter = size + 1;
	while (counter != 1)
	{
		items[counter] = items[counter-1];
		counter--;
	}
	items[1] = item;
	size++;
}

void AList::insertAtEnd(int item)
{
	items[size+1] = item;
	size++;
}

void AList::deleteItem(int search, int index)
{

	if (index == 0)
	{
		cout <<"items deleted"<<endl;
	}
	else if(items[index] == search)
	{
//		int tempSize = size;
		items[index] = items[index-1];
		size--;
//		cout <<"deleting stuff"<<endl;
		deleteItem(search, index-1);
	}
	else
	{
//		cout <<"next one"<<endl;
		deleteItem(search,index-1);
	}
}
