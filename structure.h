#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "input.h"
#include "cbox.h"

using namespace std;


typedef struct structure {
	std::string FunctionName;
	int NumOfLines;	

	input* InputList;
	int NumOfInputs;
    
    std::string OutputType;
    
    ConditionBox* ConditionBoxList;
    int NumOfConditions;
}structure; 



void initialiseStructure (structure* NewStructure){
	NewStructure->FunctionName = "Fbegin";
	NewStructure->NumOfLines = 0;
	
	NewStructure->InputList = new input[10];
	NewStructure->NumOfInputs = 0;
	
	NewStructure->OutputType = "Unknown";
	
	NewStructure->ConditionBoxList = new ConditionBox[10];
	NewStructure->NumOfConditions = 0;

}

void setOutputType (structure* MyStructure, std::string OutputType){
	MyStructure->OutputType = OutputType;
}

std::string getOutputType (structure* MyStructure){
	return MyStructure->OutputType;
}

void setFunctionName (structure* MyStructure, std::string name){
	MyStructure->FunctionName = name;
}

std::string getFunctionName (structure* MyStructure){
	return MyStructure->FunctionName;
}

void setNumOfLines (structure* MyStructure, int NumOfLines){
	MyStructure->NumOfLines = NumOfLines;
}

int getNumOfLines (structure* MyStructure){
	return MyStructure->NumOfLines;
}

void setInputList (structure* MyStructure, input* InputList, int NumOfInputs){
	if (NumOfInputs>10){
		std::cout<<"Too many inputs";
		return;
	}
	for (int i=0; i<NumOfInputs; i++){
		std::string TempInputName = getInputName(&InputList[i]);
		std::string TempInputType = getInputType(&InputList[i]);
		setInputName (&(MyStructure->InputList[i]),TempInputName);
		setInputType (&(MyStructure->InputList[i]),TempInputType);
		/*
		std::cout<<"InputName "<<i<<":"<<getInputName(&(MyStructure->InputList[i]))<<std::endl;
		std::cout<<"InputType "<<i<<":"<<getInputType(&(MyStructure->InputList[i]))<<std::endl;
		*/
	}
	MyStructure->NumOfInputs = NumOfInputs;
}


int getNumOfInputs (structure* MyStructure){
	return MyStructure->NumOfInputs;
}

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





void getStructureInfo (structure* MyStructure, std::string* RecFunction, int RecFunctionLength){
	std::string FirstLineOfCode = RecFunction[0];
	getFirstLineInfo (FirstLineOfCode, MyStructure);
	
	ConditionBox* ConditionBoxList = new ConditionBox[10];
	int* ConditionBoxLength = new int[10];
	int NumOfConditionBoxes; 
	
	bool IsConditionBlockPortion = 0;
	std::string tempstring;
	for (int i=0 ; i<RecFunctionLength; i++){
		tempstring = RecFunction[i];
		std::cout<<"Line Number "<<i<<std::endl;
		switch (IsConditionBlockPortion) {
			case 0:
				if ((tempstring.find("if")!=std::string::npos) || (tempstring.find("else")!=std::string::npos)){
					std::string condition = getConditionFromIfLine (tempstring);
					std::cout<<"if block starts with condition: "<<tempstring<<endl;
					std::string* block = new string[10];
					 	
				}
				else{
					std::cout<<"Not an if block"<<std::endl;
				}
			case 1:
				int f = 0;
				//do something	
		}
	}
}
	





/*Test For structure*/
	/*
	input* NewInput= new input[1];
	initialiseInput (NewInput);
	setInputName (&(NewInput[0]),"Soham");
	setInputType (&(NewInput[0]),"human");
	std::cout<<"Input Name:"<<getInputName (&(NewInput[0]))<<std::endl;
	std::cout<<"Input Type:"<<getInputType (&(NewInput[0]))<<std::endl;
	

	structure Structure;
	initialiseStructure(&Structure);
	std::cout<<"Structure Initialised"<<std::endl;
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
	
