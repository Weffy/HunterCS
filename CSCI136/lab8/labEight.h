/*
Title: lab eight
Created By: Krirk Pongsema
Created Date: 11/5/13
Description: header file (class definition)
Modified: 
Modified Date: 
Modified By:
*/ 

class Table
{
public:
//mutators
	void setTable(int name, char location, int size, bool status);
	void checkTable(); //check if a table is available
	void freeTable(); //sets status to true so others can sit down
	void drawTable(); //print table on screen
	void assignTable(struct Groups g[]); //go through guest list and seat guests
//accessors
	bool getStatus(); //return table's status
	int getName(); //return table name
	char getLocation(); //return table location
	int getSize(); //return table size

private:
	int size;
	int name;
	char location;
	bool status;
};
