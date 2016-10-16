#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


typedef struct ConditionBox{
	std::string condition;
	bool IsRecursiveCall;
	std::string* Content;
	int ContentLength;
	ConditionBox* subConditionBoxList;
	int NumOfSubConditions;
} ConditionBox; 

void initialiseConditionBox(ConditionBox* NewConditionBox){
	NewConditionBox->condition = "f(arg) == 0";
	NewConditionBox->Content = new std::string[20];
	NewConditionBox->ContentLength = 0;
	NewConditionBox->IsRecursiveCall = 0;
	NewConditionBox->subConditionBoxList = new ConditionBox[5];
	NewConditionBox->NumOfSubConditions = 0;
}

void setCondition (ConditionBox* MyConditionBox, std::string Condition){
	MyConditionBox->condition = Condition;
}

std::string getCondition (ConditionBox* MyConditionBox){
	return MyConditionBox->condition;
}

void setContent (ConditionBox* MyConditionBox, std::string* Content, int ContentLength){
	if (ContentLength>20){
		std::cout<<"Content length exceeded"<<std::endl;
		return;
	}
	for (int i=0; i<ContentLength; i++){
		MyConditionBox->Content[i] = Content[i];
	}
	MyConditionBox->ContentLength = ContentLength;
}

int getContentLength (ConditionBox* MyConditionBox){
	return MyConditionBox->ContentLength;
}

void setIsRecursiveCall (ConditionBox* MyConditionBox, bool IsRecursiveCall){
	MyConditionBox->IsRecursiveCall = IsRecursiveCall;
}

bool getIsRecursiveCall (ConditionBox* MyConditionBox){
	return MyConditionBox->IsRecursiveCall;
} 

std::string getConditionFromIfLine (std::string IfLine){
	std::cout<<IfLine<<std::endl;
	//std::string space = " ";
	std::string OpenParenthesis = "(";
	std::string ClosedParenthesis = ")";
	//size_t SpacePosition = 0;
	size_t OpenPosition = 0;
	size_t ClosePosition = 0;
	//SpacePosition = IfLine.find(space);
	//std::string Modal = IfLine.substr(0,SpacePosition);
	//std::cout<<Modal<<std::endl;
	OpenPosition = IfLine.find(OpenParenthesis);
	ClosePosition = IfLine.find(ClosedParenthesis);
	std::string condition;
	if ((OpenPosition!=std::string::npos) && (ClosePosition!=std::string::npos)){
		condition = IfLine.substr(OpenPosition+1,(ClosePosition-OpenPosition-1));	
	}
	else{
		if ((OpenPosition==std::string::npos) && (ClosePosition==std::string::npos)){
			condition = "Disjoint from others";
		}
		else{
			std::cout<<"Improper Format"<<std::endl;
			condition = "Invalid";
		}
	}
	return condition;
	//std::cout<<"condition:"<<condition<<std::endl;
}

bool isRecursiveCall (std::string* ConditionBlock, int NumOfLines, std::string FunctionName){
	for (int i=0; i<NumOfLines; i++){
		if (ConditionBlock[i].find(FunctionName)==std::string::npos){
			//do nothing
		}
		else{
			return 1;
		}
	}
	return 0;
}


void getConditionBoxInfo (ConditionBox* MyConditionBox, std::string* ConditionBlock, int NumOfLines){
	
	if (ConditionBlock[NumOfLines-2].find("return")==std::string::npos){
		std::cout<<ConditionBlock[NumOfLines-2]<<std::endl;
		std::cout<<"Condition Block must return"<<std::endl;
		return;
	}	

	std::string condition = getConditionFromIfLine(ConditionBlock[0]);
	setCondition (MyConditionBox, condition);
	std::cout<<"Condition:"<<getCondition(MyConditionBox)<<std::endl;
	bool IsRecursiveCall = isRecursiveCall (ConditionBlock,NumOfLines,"factorial");
	setIsRecursiveCall(MyConditionBox, IsRecursiveCall);
	std::cout<<"Recursive Call Present? "<<getIsRecursiveCall(MyConditionBox)<<std::endl;
	
}


//Testing getConditionBoxInfo
/*
ConditionBox TestConditionBox;
initialiseConditionBox(&TestConditionBox);
std::string* SampleBlock = new std::string[10];
int NumOfLines = 0;
SampleBlock[0] = RecFunction[4];
SampleBlock[1] = RecFunction[5];
SampleBlock[2] = RecFunction[6];
NumOfLines = 3;
std::cout<<SampleBlock[0]<<std::endl;
std::cout<<SampleBlock[1]<<std::endl;
std::cout<<SampleBlock[2]<<std::endl;
getConditionBoxInfo(&TestConditionBox, SampleBlock, NumOfLines);
*/















