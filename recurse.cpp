/*****************************************************/
/*       Identifying structure of the function       */
/*****************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "structure.h"
 using namespace std;


void getFirstLineInfo (std::string FirstLine, structure* MyStructure){
		
	std::string OutputType = "";
	std::string FunctionName = "";
	std::string Arguments="";
	input* InputList = new input[10];
	int NumOfInputs = 0;
	
	size_t SpacePosition = 0;
	string space = " ";
	string curly="{";
	string buffer="";
	SpacePosition = FirstLine.find(space);
	OutputType = FirstLine.substr(0,SpacePosition);
	FirstLine=FirstLine.substr(SpacePosition+1,FirstLine.length());
	SpacePosition = FirstLine.find(space);
	FunctionName=FirstLine.substr(0,SpacePosition);
	FirstLine=FirstLine.substr(SpacePosition+1,FirstLine.length());
	SpacePosition = FirstLine.find(curly);
	Arguments=FirstLine.substr(0,SpacePosition);
	if(Arguments[0]=='('&& Arguments[Arguments.length()-1]==')')
	{
		for(int i=1;i<Arguments.length();i++)
		{
			
			if(Arguments[i]==' ')
			{
			setInputType(&(InputList[NumOfInputs]),buffer);
			buffer="";
			}
			else if(Arguments[i]==')' ||Arguments[i]==',')
			{
			setInputName(&(InputList[NumOfInputs]),buffer);
			buffer="";
			NumOfInputs++;
			}
			else
			{
				buffer=buffer+Arguments[i];
			}
		}
	}
	
	setOutputType (MyStructure, OutputType);
	setFunctionName (MyStructure,FunctionName);
	setInputList (MyStructure, InputList, NumOfInputs);
	
	
	
}



int main (){
	/**
	/*RecFunction stores the recursive function in an array of string. 
	/*Each entry (type char&) represents a line of the function (lines being separated by ENTER). 
	/*RecFunctionLength stores the number of entries filled in RecFunction after reading the file.
	*/
	
   	std::string* RecFunction = new std::string[100];
   	int RecFunctionLength = 0;
   
   	/**
	/*reading from file.*/
   	std::ifstream recursion ("recursion.txt");
   
   	if (recursion.is_open()){
   		int LineCounter = 0;
   		while (recursion.good()){
   			std::string templine;
   			getline (recursion,templine);
			RecFunction[LineCounter] =  templine;  	
			std::cout<<RecFunction[LineCounter]<<std::endl;
			LineCounter++;
		}
	    RecFunctionLength = LineCounter;
		recursion.close();
   	}
   	else{
   		std::cout<<"Unable to open file"<<std::endl;
		return -1;	
	}
   	
	//std::cout<<RecFunctionLength;
	
	if (RecFunctionLength==0){
		std::cout<<"Empty file"<<std::endl;	
		return -1;	
    }
	/*File read
	**/

	/*Test For input datatype*/
	/*
	input* NewInput= new input;
	initialiseInput (NewInput);
	
	std::cout<<"Input Name:"<<getInputName (NewInput)<<std::endl;
	setInputName (NewInput,"Soham");
	std::cout<<"Input Name:"<<getInputName (NewInput)<<std::endl;
	*/
	
	

	/*Test For structure*/
	/*
	input* NewInput= new input[1];
	initialiseInput (NewInput);
	setInputName (&(NewInput[0]),"Soham");
	setInputType (&(NewInput[0]),"human");
	std::cout<<"Input Name:"<<getInputName (&(NewInput[0]))<<std::endl;
	std::cout<<"Input Type:"<<getInputType (&(NewInput[0]))<<std::endl;
	*/
	
	structure Structure;
	initialiseStructure(&Structure);
	std::cout<<"Structure Initialised"<<std::endl;
	/*
	//std::cout<<getFunctionName(&Structure)<<std::endl;
	std::cout<<"Number of lines:"<<getNumOfLines(&Structure)<<std::endl;
	
	std::string TestFunctionName = "TestFunctionName";
	setFunctionName (&Structure,TestFunctionName);
	std::cout<<getFunctionName(&Structure)<<std::endl;
	input* TestInputList = new input[10];
	int NumOfInputs = 2;
	for (int i=0; i<NumOfInputs; i++){
		std::stringstream convert;
		convert<<i;
		std::string tempInputName = "Input"+convert.str();
		std::string tempInputType = "Type"+ convert.str();
		setInputName (&(TestInputList[i]),tempInputName);
		setInputType (&(TestInputList[i]),tempInputType);
	}
	setInputList(&Structure,TestInputList,NumOfInputs);
	std::cout<<"NumOfInputs:"<<getNumOfInputs(&Structure)<<std::endl;
	*/		
	//Testing getFirstLineInfo
	
	std::string TestFirstLine = RecFunction[0];
	getFirstLineInfo (TestFirstLine,&Structure);
	
	
	
	return 0;
}








