#include"StringCollection.h"
#include<iostream>
#include<string>
using namespace std;

StringCollection::StringCollection() : myStringSize(DEFAULT_SIZE){
	//No size specified, therefore use DEFAULT SIZE for String Size
	//cannot be specified in (:) due to dependence on myStringSize ?
	myString = new string[myStringSize];
}

StringCollection::StringCollection(int size) : myStringSize(size){
	//Create array of specified size
	myString = new string[myStringSize];
}

StringCollection::~StringCollection(){
	delete[] myString;
}

string* StringCollection::getMyString(){
	return myString;
}

//Uses iostream:
ostream& operator <<(ostream& outs, const StringCollection& stringObj)
{
	for (int i = 0; i < stringObj.myStringSize; i++){
		outs << stringObj.myString[i] << endl;
	}
	outs << endl;
	return outs;
}

string* StringCollection::add(int* size, string toAdd){
	myStringSize++; //+1 for string being added.
	*size = myStringSize;
	string* newString = new string[myStringSize];

	int i = 0;
	for (i = 0; i < myStringSize - 1; i++){
		newString[i] = myString[i];
	}
	newString[i] = toAdd;
	delete[] myString;
	myString = newString;
	return myString;
}

string* StringCollection::addArray(int* size, string* toAddArray, int addSize){
	int oldStringSize = myStringSize;
	myStringSize += addSize; //+ for string being added.
	*size = myStringSize;
	string* newString = new string[myStringSize];

	int i = 0;
	int j = 0;
	for (i = 0; i < oldStringSize; i++){
		newString[i] = myString[i];
	}
	for (j = 0; j < addSize; j++){
		newString[i + j] = toAddArray[j];
	}
	delete[] myString;
	myString = newString;
	return myString;
}

string* StringCollection::del(int* size, string toDel){
	for (int i = 0; i < myStringSize; i++){
		//if it exists...
		if (myString[i].compare(toDel) == 0){
			//then remove it
			for (int j = i; j < myStringSize - 1; j++){
				myString[j] = myString[j + 1];
			}
			myStringSize--; //decriment string size
		}
	}
	*size = myStringSize;
	return myString;
}

string* StringCollection::delArray(int* size, string* toDelArray, int delSize){
	for (int i = 0; i < delSize; i++){
		del(size, toDelArray[i]);
	}
	return myString;
}