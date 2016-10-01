

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



