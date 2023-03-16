/** This program is a submition for CSCI331 FALL 2022 PROJECT3
 * Description: Using a buffer object parse a csv file of zipcodes, states, counties,
 * latitues, and longitudes, and generate a table with each row containing one states most;
 * eastern, western, northern, and southern zipcodes
/* @file name: Proj3_Group8.cpp 
	MemberName: Tyler Knudtson
				Adam Cox
				JIE XIE
	Due Date: October 10 2022
	Instructor: Jie Meichsner
	Comments: N/A
*/

#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include "deltext.h"
#include "zipcode.h"
#include "State.h"

/**compareStates;
 * compares 2 stateStructs states to see if they're in alphabetical order
 * @param stateStruct a
 * @param stateStruct b
 * @pre a stateStruct object must exist
 * @post returns true if the state field in the state structs are in alphabetical order*/
bool comparteStates(State a, State b){
	if(a.stateName[0] == b.stateName[0])
		return(a.stateName[1] < b.stateName[1]);

	return (a.stateName[0] < b.stateName[0]);
}

/**constructStateArray;
 * copies into an array of stateStruct structs given an array of Zipcode objects
 * @param stateStruct array sArray
 * @param Zipcode array zArray
 * @param int sArraySize size of sArray
 * @param int zArraySize size of zArray
 * @pre an array of stateStruct's and an array of Zipcode's must exist
 * @post sArray's fields will be filled with information from zArray's zipcodes*/
void constructStateArray(State sArray[], Zipcode zArray[], int sArraySize, int zArraySize){
	int count = 0;
	for(int i = 0; i < zArraySize; i++){
		bool found = false;
		for(int j= 0; j < sArraySize; j++){
			if(zArray[i].State[0] == sArray[j].stateName[0]&&zArray[i].State[1] == sArray[j].stateName[1]){
				found = true;
				break;
			}
		}
		if(!found){
			strcpy(sArray[count].stateName,zArray[i].State);
			strcpy(sArray[count].easternZipcode,zArray[i].Code);
			strcpy(sArray[count].westernZipcode,zArray[i].Code);
			strcpy(sArray[count].northernZipcode,zArray[i].Code);
			strcpy(sArray[count].southernZipcode,zArray[i].Code);
			strcpy(sArray[count].largestLong, zArray[i].Long);
			strcpy(sArray[count].smallestLong, zArray[i].Long);
			strcpy(sArray[count].largestLat, zArray[i].Lat);
			strcpy(sArray[count].smallestLat, zArray[i].Lat);
			count++;
			if(count >= 50)
				break;
		}
	}
}

/**findLargestSmallestLatLong
 * finds the largest and smallest latitudes and longitues and corresponding zipcodes
 * from an array of zipcodes and stores them in an array of stateStruct's
 * @param stateStruct array sArray
 * @param Zipcode array zArray
 * @param int sArraySize size of sArray
 * @param int zArraySize size of zArray
 * @pre an array of stateStruct's and an array of Zipcode's must exist
 * @post an array of stateStruct's with largest 
 * and smallest latitude and longitues and corresponding zipcodes*/
void findLargestSmallestLatLong(State sArray[], Zipcode zArray[], int sArraySize, int zArraySize){
	for(int i = 0; i < zArraySize; i++){
		for(int j = 0; j < sArraySize; j++){
			if(zArray[i].State[0] == sArray[j].stateName[0]&&zArray[i].State[1] == sArray[j].stateName[1]){
				if(std::stof(zArray[i].Long) > std::stof(sArray[j].largestLong)){
					strcpy(sArray[j].largestLong,zArray[i].Long);
					strcpy(sArray[j].westernZipcode,zArray[i].Code);
				}
				if(std::stof(zArray[i].Long) < std::stof(sArray[j].smallestLong)){
					strcpy(sArray[j].smallestLong,zArray[i].Long);
					strcpy(sArray[j].easternZipcode,zArray[i].Code);
				}
				if(std::stof(zArray[i].Lat) > std::stof(sArray[j].largestLat)){
					strcpy(sArray[j].largestLat,zArray[i].Lat);
					strcpy(sArray[j].northernZipcode,zArray[i].Code);
				}
				if(std::stof(zArray[i].Lat) < std::stof(sArray[j].smallestLat)){
					strcpy(sArray[j].smallestLat,zArray[i].Lat);
					strcpy(sArray[j].southernZipcode,zArray[i].Code);
				}
			}
		}
	}
}

/**outputTable
 * @param string outputFileName
 * @param DelimTextBuffer OutBuff
 * @param stateStruct array sArray
 * @param int sArraySize size of sArray
 * @pre an array of stateStructs and a DelimtTextBuffer object must exist
 * @post the given sArray is packed into OutBuff and OutBuff is written to a file with outputFileName*/
void outputTable(std::string outputFileName, DelimTextBuffer OutBuff, State sArray[], int sArraySize){
	std::ofstream OutFile (outputFileName,std::ios::out);
	char state [3] = "ST";
	char easternZipcode [6] = "E Zip";
	char westernZipcode [6] = "W Zip";
	char northernZipcode [6] = "N Zip";
	char southernZipcode [6] = "S Zip";
	OutBuff.Clear();
	OutBuff.Pack(state);
	OutBuff.Pack(easternZipcode);
	OutBuff.Pack(westernZipcode);
	OutBuff.Pack(northernZipcode);
	OutBuff.Pack(southernZipcode);
	OutBuff.Write(OutFile);

	std::cout << state << "," << easternZipcode << "," << westernZipcode << "," << northernZipcode << "," << southernZipcode << std::endl;

	for(int i = 0;i < sArraySize; i++){
		OutBuff.Clear();
		OutBuff.Pack(sArray[i].stateName);
		OutBuff.Pack(sArray[i].easternZipcode);
		OutBuff.Pack(sArray[i].westernZipcode);
		OutBuff.Pack(sArray[i].northernZipcode);
		OutBuff.Pack(sArray[i].southernZipcode);
		OutBuff.Write(OutFile);
		std::cout << sArray[i].stateName << "," << sArray[i].easternZipcode << "," << sArray[i].westernZipcode << "," << sArray[i].northernZipcode << "," << sArray[i].southernZipcode << std::endl;
	}
	OutFile.close();
}

void application()
{
	Zipcode ZipcodeArray[45000];
	State StateArray[50];
	int index = 0;
	int n = (sizeof(StateArray)/sizeof(StateArray[0]));

	//istream
	std::ifstream InFile("StateSort.csv", std::ios::in);
	DelimTextBuffer InBuff;
	Zipcode :: InitBuffer (InBuff);

	while(InFile.peek()!=EOF)
	{
	InBuff.Read(InFile);
	ZipcodeArray[index].Unpack(InBuff);
	index++;
	}

	InFile.close();
//sorting states
	
	constructStateArray(StateArray,ZipcodeArray,n,index);

	std::sort(StateArray,StateArray+n, comparteStates);

	findLargestSmallestLatLong(StateArray,ZipcodeArray,n,index);

//ostream
	std::string outputFileName = "OUTFILE.csv";
	DelimTextBuffer OutBuff;
	Zipcode :: InitBuffer (OutBuff);

	outputTable(outputFileName,OutBuff,StateArray,n);
}

int main(int argc, char ** argv)
{

	application();

	return 0;
}

