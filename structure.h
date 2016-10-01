#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "input.h"
#include "cbox.h"



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
	
	std::cout<<"FunctionName and NumOfLines"<<std::endl;
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
		std::cout<<"InputName "<<i<<":"<<getInputName(&(MyStructure->InputList[i]))<<std::endl;
		std::cout<<"InputType "<<i<<":"<<getInputType(&(MyStructure->InputList[i]))<<std::endl;
	}
	MyStructure->NumOfInputs = NumOfInputs;
}


int getNumOfInputs (structure* MyStructure){
	return MyStructure->NumOfInputs;
}

