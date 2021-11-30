/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Riya Singh
 */

//The purpose of this program is to find the value of x in quadratic equation.

#include <iostream> //allows program to perform input and output
#include <string> //allows program to work with strings
#include <vector> //allows program to create vectors and use associative functions
#include "std_lib_facilities.h" //header file


//A class to store the name and value
class Name_value
{
	public:
	std::string name;
	int value;
};

//Check whether the name already exists in the list
int check(vector<Name_value> list, std::string str)
{
	int i = 0;
	for(i = 0; i < list.size(); ++i)
	{
		if(list[i].name == str)
		{
			return 1;
		}
	}
	return 0;
}

//Create and return an object of NameValue class type
//Set the name and value
Name_value createObj(std::string str, int val)
{
	Name_value *obj = new Name_value;
	obj->name = str;
	obj->value = val;
	return *obj;
}

int main()
{
	vector<Name_value> list; //stores the object of type NameValue
	
	std::string str;
	int val;
	int check1;
	int i = 0;
	
	std::cin >> str >> val; //scan and store the input
	
	while(str != "NoName" && val != 0)
	{
	    check1 = check(list, str); //check if the name already exists

		if(check1 == 0) //if the name does not exist, add the name and value to the list
		{
			list.push_back(createObj(str, val));
			std::cin >> str >> val;
		}
		else //if the name exists, output already exists and ask the next input
		{
		    std::cout << str << " already exists " << std::endl;
			std::cin >> str >> val;
		}
	}
	
	std::cout << "\n" << std::endl;
	
	for(i = 0; i < list.size(); ++i) //print the name and values
	{
		std::cout << list[i].name << " " << list[i].value << std::endl;
	}
}
