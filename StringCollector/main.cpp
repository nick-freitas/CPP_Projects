#include <iostream>
#include <string>
#include "StringCollection.h"

void printOptionsMenu();

void addSingleString(StringCollection* sobj);
void addStringArray(StringCollection* sobj);
void removerSingleString(StringCollection* sobj);
void removeStringArray(StringCollection* sobj);

void main(){
	int array_size = -1;
	int option = -1;
	string user_input;
	StringCollection mine;

	cout << "Welcome to the String Collector\n\n";

	while (option != 4){
		cout << "Which option would you like?" <<endl;
		printOptionsMenu();
		cin >> user_input;
		try{
			option = tolower(user_input[0]) - 'a';
			if (option != 0 && option != 1 && option != 2 && option != 3 && option != 4) throw - 1;
		}
		catch (...){
			cout << "Sorry, but " << user_input << " is an option. Please try again" << endl;
			continue;
		}
		if (option == 4){
			break;
		}
		switch (option){
		case 0:
			addSingleString(&mine);
			cout << "The new contents of the collection:\n" << mine << endl;
			break;
		case 1:
			removerSingleString(&mine);
			cout << "The new contents of the collection:\n" << mine << endl;
			break;
		case 2:
			addStringArray(&mine);
			cout << "The new contents of the collection:\n" << mine << endl;
			break;
		case 3:
			removeStringArray(&mine);
			cout << "The new contents of the collection:\n" << mine << endl;
			break;
		}
	}

	cout << "The final contents of the collection:\n\n" << mine << endl;
}

void addSingleString(StringCollection* sobj){
	string user_input;
	int size;
	cout << "Enter the string to add to the collection:";
	fflush(stdin); //prevents previous \n from being an input
	getline(cin, user_input); //get line so input is entire line, not next string
	string* res = (*sobj).add(&size, user_input);
}

void addStringArray(StringCollection* sobj){
	int maxSize = 1;
	string* tempStringarray = new string[maxSize];
	int tempArraySize = 0;
	string user_input;
	int returnedSize;
	do{
		cout << "Enter the string to add, or enter '-1' to stop" << endl;
		fflush(stdin); //prevents previous \n from being an input
		getline(cin, user_input); //get line so input is entire line, not next string
		if (user_input.compare("-1") == 0){
			break;
		}
		if (tempArraySize == maxSize){
			maxSize = maxSize * 2; //increase by 100%
			string* newStringArray = new string[maxSize];
			for (int i = 0; i < tempArraySize; i++){
				newStringArray[i] = tempStringarray[i]; //move elements to new array
			}
			delete[] tempStringarray;
			tempStringarray = newStringArray;
		}
		tempStringarray[tempArraySize] = user_input;
		tempArraySize++;
	} while (user_input.compare("-1") != 0);
	if (tempArraySize > 0){
		(*sobj).addArray(&returnedSize, tempStringarray, tempArraySize);
	}
}
void removerSingleString(StringCollection* sobj){
	string user_input;
	int size;
	cout << "Enter the string to delete: ";
	fflush(stdin); //prevents previous \n from being an input
	getline(cin, user_input); //get line so input is entire line, not next string
	(*sobj).del(&size, user_input);
	cout << "Removed! "<< user_input << " is no longer in the collection";
}

void removeStringArray(StringCollection* sobj){
	int maxSize = 1;
	string* tempStringarray = new string[maxSize];
	int tempArraySize = 0;
	string user_input;
	int returnedSize;
	do{
		cout << "Enter the string to delete, or enter '-1' to stop" << endl;
		fflush(stdin); //prevents previous \n from being an input
		getline(cin, user_input); //get line so input is entire line, not next string
		if (user_input.compare("-1") == 0){
			break;
		}
		if (tempArraySize == maxSize){
			maxSize = maxSize * 2; //increase by 100%
			string* newStringArray = new string[maxSize];
			for (int i = 0; i < tempArraySize; i++){
				newStringArray[i] = tempStringarray[i]; //move elements to new array
			}
			delete[] tempStringarray;
			tempStringarray = newStringArray;
		}
		tempStringarray[tempArraySize] = user_input;
		tempArraySize++;
	} while (user_input.compare("-1") != 0);
	if (tempArraySize > 0){
		(*sobj).delArray(&returnedSize, tempStringarray, tempArraySize);
	}
}

void printOptionsMenu(){
	cout << "a. Add a single string to the collection" << endl;
	cout << "b. Remove a single string from the collection" << endl;
	cout << "c. Add a number string to the collection" << endl;
	cout << "d. Remove a number string from the collection" << endl;
	cout << "e. Quit" << endl;
}