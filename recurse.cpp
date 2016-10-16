/*****************************************************/
/*       Identifying structure of the function       */
/*****************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "structure.h"

using namespace std;




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
			std::cout<<LineCounter<<": "<<RecFunction[LineCounter]<<std::endl;
			LineCounter++;
		}
	    RecFunctionLength = LineCounter;
		recursion.close();
   	}
   	else{
   		std::cout<<"Unable to open file"<<std::endl;
		return -1;	
	}
	std::cout<<std::endl;
   	
	//std::cout<<RecFunctionLength;
	
	if (RecFunctionLength==0){
		std::cout<<"Empty file"<<std::endl;	
		return -1;	
    }
	/*File read
	**/

	
	//Creating new structure for the code
	structure* Structure = new structure;
	initialiseStructure(Structure);
	std::cout<<"Structure Initialised"<<std::endl;
	
	
	
	//getFirstLineInfo (RecFunction[0],Structure);
	
	getStructureInfo (Structure, RecFunction, RecFunctionLength);
	
	
	
	return 0;
}








