#pragma once

#include<iostream>
using namespace std;

class StringCollection{
private:
	string* myString; //Pointer to the instance's string array
	int myStringSize; //Size of instance's array
	static const int DEFAULT_SIZE = 0; //Default size of the array created by the no argument constructor
public:
	//Zero argument constructor will use DEFAULT SIZE for creating array.
	StringCollection();

	//Single argument constructor will use specified size for creating array.
	StringCollection(int size);

	//Deconstructor
	~StringCollection();

	string* getMyString();

	string* add(int* size, string toAdd);

	string* del(int* size, string toDel);

	string* addArray(int* size, string* toAddArray, int addSize);

	string* delArray(int* size, string* toDelArray, int delSize);

	//Sends contents of myString to the output stream
	friend ostream& operator <<(ostream& outs, const StringCollection& stringObj);

};