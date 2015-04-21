#include <iostream>
#include <string>
//tranform() to convert string to all upper
#include <algorithm>
//map
#include<map>

using namespace std;

struct distance{
	double lenght;
	double lenght_base;
	string unit;
	string unit_base;
};

map<string, double> si_2_imperial;
map<string, double> imperial_2_si;

void writeDistance(int input_lenght, string input_unit, struct distance* original);
bool legitUnit(string unit);
void convert(struct distance* original, struct distance* converted);
void init_si_2_imperial();
void init_imperial_2_si();

int main(){
	char option;
	int input_lenght;
	string input_unit;
	string newUnit;
	struct distance original;
	struct distance converted;
	init_si_2_imperial();
	init_imperial_2_si();
	cout << "Welcome" << endl << endl;
	/*
	kilometers, meters, centimeters, and millimeters
	miles, yards, feet, and inches
	*/
	do{
		cout << "Which option would you like?" << endl;
		cout << "a. Convert distance in SI units to imperial units" << endl;
		cout << "b. Convert distance in imperial units to SI units" << endl;
		cin >> option;
	} while (option != 'a' && option != 'A' && option != 'b' && option != 'B');

	switch (option){
	case 'a':
		cout << "Enter the distance with SI units (23 meters): ";
		break;
	case 'b':
		cout << "Enter the distance with imperial units (e.g. 3 miles): ";
	}
	cin >> input_lenght;
	cin >> input_unit;

	do{
		cout << endl;
		cout << "What unit do you want the distance to be converted into?" << endl;
		cout << "km, m, cm, mm, inches, feet, yard, miles" << endl;
		cin >> newUnit;
	} while (!legitUnit(newUnit));
	writeDistance(input_lenght, input_unit, &original);
	writeDistance(0, newUnit, &converted);
	convert(&original, &converted);

	cout << "Original: " << original.lenght << " " << original.unit << endl;
	cout << "Conversion: " << converted.lenght << " " << converted.unit << endl;
}

void convert(struct distance* original, struct distance* converted){
	double conversion_rate;
	if (original->unit_base == "METERS"){
		conversion_rate = si_2_imperial.find(converted->unit)->second;
	}
	else{
		conversion_rate = imperial_2_si.find(converted->unit)->second;
	}
	converted->lenght = original->lenght_base * conversion_rate;
}

bool legitUnit(string unit){
	transform(unit.begin(), unit.end(), unit.begin(), toupper);
	//cout << unit;
	return
		unit.compare("METER") == 0 || unit.compare("METERS") == 0 || unit.compare("M") == 0 || unit.compare("CENTIMETER") == 0 || unit.compare("CENTIMETERS") == 0 || unit.compare("CM") == 0 || unit.compare("MILLIMETER") == 0 ||
		unit.compare("MILLIMETERS") == 0 || unit.compare("MM") == 0 || unit.compare("KILOMETER") == 0 || unit.compare("KILOMETERS") == 0 || unit.compare("KM") == 0 || unit.compare("INCH") == 0 || unit.compare("INCHES") == 0 ||
		unit.compare("\"") == 0 || unit.compare("FOOT") == 0 || unit.compare("FT") == 0 || unit.compare("FEET") == 0 || unit.compare("'") == 0 || unit.compare("YARD") == 0 || unit.compare("YARDS") == 0 || unit.compare("MILE") == 0 || unit.compare("MILES") == 0;
}

void writeDistance(int input_lenght, string input_unit, struct distance* original){
	original->lenght = input_lenght;
	original->lenght_base = 0;
	transform(input_unit.begin(), input_unit.end(), input_unit.begin(), toupper);

	//SI Units
	if (input_unit.compare("METER") == 0 || input_unit.compare("METERS") == 0 || input_unit.compare("M") == 0){
		original->unit = "METERS";
		original->unit_base = "METERS";
		original->lenght_base = original->lenght;
	}
	else if (input_unit.compare("CENTIMETER") == 0 || input_unit.compare("CENTIMETERS") == 0 || input_unit.compare("CM") == 0){
		original->unit = "CENTIMETERS";
		original->unit_base = "METERS";
		original->lenght_base = 0.01 * original->lenght;
	}
	else if (input_unit.compare("MILLIMETER") == 0 || input_unit.compare("MILLIMETERS") == 0 || input_unit.compare("MM") == 0){
		original->unit = "MILLIMETERS";
		original->unit_base = "METERS";
		original->lenght_base = 0.001 * original->lenght;
	}
	else if (input_unit.compare("KILOMETER") == 0 || input_unit.compare("KILOMETERS") == 0 || input_unit.compare("KM") == 0){
		original->unit = "KILOMETERS";
		original->unit_base = "METERS";
		original->lenght_base = 1000 * original->lenght;
	}

	//Imperial Units
	else if (input_unit.compare("INCH") == 0 || input_unit.compare("INCHES") == 0 || input_unit.compare("\"") == 0){
		original->unit = "INCHES";
		original->unit_base = "INCHES";
		original->lenght_base = original->lenght;
	}
	else if (input_unit.compare("FOOT") == 0 || input_unit.compare("FEET") == 0 || input_unit.compare("'") == 0 || input_unit.compare("FT") == 0){
		original->unit = "FEET";
		original->unit_base = "INCHES";
		original->lenght_base = 12 * original->lenght;
	}
	else if (input_unit.compare("YARD") == 0 || input_unit.compare("YARDS") == 0){
		original->unit = "YARDS";
		original->unit_base = "INCHES";
		original->lenght_base = 36 * original->lenght;
	}
	else if (input_unit.compare("MILE") == 0 || input_unit.compare("MILES") == 0){
		original->unit = "MILES";
		original->unit_base = "INCHES";
		original->lenght_base = 63360 * original->lenght;
	}
}

void init_si_2_imperial(){
	//Meters to Imperial
	si_2_imperial.insert({ "MILES", 0.000621371 });
	si_2_imperial.insert({ "YARDS", 1.09361 });
	si_2_imperial.insert({ "FEET", 3.28084 });
	si_2_imperial.insert({ "INCHES", 39.3701 });
}

void init_imperial_2_si(){
	//Inches to SI
	imperial_2_si.insert({ "KILOMETERS", 0.0000254 });
	imperial_2_si.insert({ "METERS", 0.0254 });
	imperial_2_si.insert({ "CENTIMETERS", 2.54 });
	imperial_2_si.insert({ "MILLIMETERS", 25.4 });
}