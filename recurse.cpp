/*****************************************************/
/*       Identifying structure of the function       */
/*****************************************************/

#include <iostream>
#include <fstream>
#include <string>

//git added//
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

//For each condition of if or else
typedef struct ConditionBox{
	std::string condition;
	bool IsRecursiveCall;
	std::string* Content;
	int ContentLength;
} ConditionBox; 


//Contains the mai
typedef struct structure 
{
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
	}
	MyStructure->NumOfInputs = NumOfInputs;
}


int getNumOfInputs (structure* MyStructure){
	return MyStructure->NumOfInputs;
}

void getFirstLineInfo (std::string FirstLine, structure* MyStructure){
	
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
			std::cout<<templine<<std::endl;
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
	input* NewInput= new input[1];
	initialiseInput (NewInput);
	setInputName (&(NewInput[0]),"Soham");
	setInputType (&(NewInput[0]),"human");
	std::cout<<"Input Name:"<<getInputName (&(NewInput[0]))<<std::endl;
	std::cout<<"Input Type:"<<getInputType (&(NewInput[0]))<<std::endl;
	
	structure Structure;
	initialiseStructure(&Structure);
	std::cout<<"Structure Initialised"<<std::endl;
	/*
	std::cout<<getFunctionName(&Structure)<<std::endl;
	std::cout<<"Number of lines:"<<getNumOfLines(&Structure)<<std::endl;
	*/
	
	return 0;
}
