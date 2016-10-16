
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/**
datatype input corresponds to a single input parameter with a name and datatype.
*/
typedef struct input{
	std::string InputType;
	std::string InputName;	
} input;


//functions related to input
void initialiseInput (input* NewInput){
	NewInput->InputName = "New";
	NewInput->InputType = "Unknown";
}

void setInputName (input* MyInput, std::string name){
	MyInput->InputName = name;
}

void setInputType (input* MyInput, std::string type){
	MyInput->InputType = type;
}

std::string getInputName (input* MyInput){
	return MyInput->InputName;
}

std::string getInputType (input* MyInput){
	return MyInput->InputType;
}


	/*Test For input datatype*/
	/*
	input* NewInput= new input;
	initialiseInput (NewInput);
	
	std::cout<<"Input Name:"<<getInputName (NewInput)<<std::endl;
	setInputName (NewInput,"Soham");
	std::cout<<"Input Name:"<<getInputName (NewInput)<<std::endl;
	*/
	

	
