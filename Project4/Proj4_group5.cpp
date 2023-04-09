
/*********THIS FILE IS NO LONGER CURRENT. stateStruct has been placed in its own separate file. */

/**
\file Proj3_group5.cpp
\author Steven Kraus
\author Emily Yang
\author Tyler Knudtson
\author Ashesh Nepal
\brief Driver file for Zipcode class
*/

#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include "deltext.h"
#include "zipcode.h"

/**
\struct stateStruct
\brief Struct with data values representing a State.
*/
struct stateStruct{

	char state [5];
	char easternZipcode [10];
	char westernZipcode [10];
	char northernZipcode [10];
	char southernZipcode [10];
	char largestLong [10];
	char smallestLong [10];
	char largestLat [10];
	char smallestLat [10];
};

/**
\fn compareStates
compares 2 stateStructs states to see if they're in alphabetical order
\param An instance of stateStruct
\param An instance of stateStruct
\return true if the state field in the state structs are in alphabetical order*/

bool comparteStates(stateStruct a, stateStruct b){
	if(a.state[0] == b.state[0])
		return(a.state[1] < b.state[1]);

	return (a.state[0] < b.state[0]);
}

/**
\fn constructStateArray;
copies into an array of stateStruct structs given an array of Zipcode objects
\param Array of stateStruct objects
\param Array of Zipcode Objects
\param int Size of stateStruct Array 
\param int Size of Zipcode Array
\post stateStruct Array will be filled with data from Zipcode Array*/
void constructStateArray(stateStruct sArray[], Zipcode zArray[], int sArraySize, int zArraySize){
	int count = 0;
	for(int i = 0; i < zArraySize; i++){
		bool found = false;
		for(int j= 0; j < sArraySize; j++){
			if(zArray[i].State[0] == sArray[j].state[0]&&zArray[i].State[1] == sArray[j].state[1]){
				found = true;
				break;
			}
		}
		if(!found){
			strcpy(sArray[count].state,zArray[i].State);
			strcpy(sArray[count].easternZipcode,zArray[i].Code);
			strcpy(sArray[count].westernZipcode,zArray[i].Code);
			strcpy(sArray[count].northernZipcode,zArray[i].Code);
			strcpy(sArray[count].southernZipcode,zArray[i].Code);
			strcpy(sArray[count].largestLong, zArray[i].Long);
			strcpy(sArray[count].smallestLong, zArray[i].Long);
			strcpy(sArray[count].largestLat, zArray[i].Lat);
			strcpy(sArray[count].smallestLat, zArray[i].Lat);
			count++;
			if(count >= 50)//Setting this to 51 did not fix the alaska issue.
				break;
		}
	}
}

/**
\fn findLargestSmallestLatLong
finds the largest and smallest latitudes and longitues and corresponding Zipcodes from an array of Zipcodes and stores them in an array of stateStruct's
\param Array of stateStruct objects
\param Array of Zipcode Objects
\param int Size of stateStruct Array 
\param int Size of Zipcode Array
\post stateStruct Array will be filled with data corresponding to Zipcodes that are the furthest in each direction*/
void findLargestSmallestLatLong(stateStruct sArray[], Zipcode zArray[], int sArraySize, int zArraySize){
	for(int i = 0; i < zArraySize; i++){
		for(int j = 0; j < sArraySize; j++){
			if(zArray[i].State[0] == sArray[j].state[0]&&zArray[i].State[1] == sArray[j].state[1]){
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

/**
\fn outputTable
\param string The file name to output to
\param the DelimTextBuffer that will be used for output
\param Array of stateStruct objects
\param int Size of stateStruct Array 
\post the stateStruct array is packed into the buffer and written to the specified file*/
void outputTable(std::string outputFileName, DelimTextBuffer OutBuff, stateStruct sArray[], int sArraySize){
	std::ofstream OutFile (outputFileName,std::ios::out);
	
	std::string outputPKIname=strtok((char*)outputFileName.c_str(), ".");//discard file extension
	outputPKIname.append(".pki");//add new file extension
	//std::cout<<outputPKIname<<std::endl;
	//outputPKIname now contains the outputFileName but with a .pki extension instead of the original extension.
	
	//Writing header has not been implemented yet!!!!!!!!
	
	int HeaderLengthRow1, HeaderLengthRow2, HeaderLengthAll;
	char* FileType=(char*)"FileType=CSV";//Many of these values are fixed in this case, but they can be modified to be calculated from something if needed.
	char* Version=(char*)"Version=1.0";
	char* SizeType=(char*)"SizeType=ASCII";
	char* IndexFile=(char*)outputPKIname.c_str();
	char* IndexSchema=(char*)"Primary Key Index";
	char* RecordCount=(char*)"RecordCount=53";//This is a fixed value in this case, though this may change in subsequent versions.
	//					                 The header is 2 records, the column labels are 1 record, and the states are 50 records
	char* FieldsPerRecord=(char*)"FieldsPerRecord=5";
	char* EndHeaderMessage=(char*)"End_Header_Record";
	
	HeaderLengthRow1=strlen(FileType)+strlen(Version)+strlen(SizeType)+strlen(IndexFile)+strlen(IndexSchema)+strlen(RecordCount)+9;
	HeaderLengthRow2=strlen(FieldsPerRecord)+strlen(EndHeaderMessage)+8;
	HeaderLengthAll=HeaderLengthRow1+HeaderLengthRow2;
	
	OutBuff.Clear();
	OutBuff.Pack((char*)std::to_string(HeaderLengthRow1).c_str());
	OutBuff.Pack(FileType);
	OutBuff.Pack(Version);
	OutBuff.Pack(SizeType);
	OutBuff.Pack(IndexFile);
	OutBuff.Pack(IndexSchema);
	OutBuff.Pack(RecordCount);
	OutBuff.Write(OutFile);
	
	OutBuff.Clear();
	OutBuff.Pack((char*)std::to_string(HeaderLengthRow2).c_str());
	OutBuff.Pack((char*)std::to_string(HeaderLengthAll).c_str());
	OutBuff.Pack(FieldsPerRecord);
	OutBuff.Pack(EndHeaderMessage);
	OutBuff.Write(OutFile);
	
	
	char state [3] = "ST";
	char easternZipcode [6] = "E Zip";
	char westernZipcode [6] = "W Zip";
	char northernZipcode [6] = "N Zip";
	char southernZipcode [6] = "S Zip";
	OutBuff.Clear();
	int length=((strlen(state)+strlen(easternZipcode)+strlen(westernZipcode)+strlen(northernZipcode)+strlen(southernZipcode))+8);
	char* charlen;
	charlen=(char*)std::to_string(length).c_str();//Hooray for three type conversions in one line of code!
	if(std::stoi(charlen)<10){
		charlen[1]=charlen[0];
		charlen[0]='0';
	}
	OutBuff.Pack(charlen);
	OutBuff.Pack(state);
	OutBuff.Pack(easternZipcode);
	OutBuff.Pack(westernZipcode);
	OutBuff.Pack(northernZipcode);
	OutBuff.Pack(southernZipcode);
	OutBuff.Write(OutFile);

	std::cout << state << "," << easternZipcode << "," << westernZipcode << "," << northernZipcode << "," << southernZipcode << std::endl;
	
	//char** headerList=['FileType=CSV', 'Version=1.0', 'SizeType=ASCII', outputFileName.append(".pki"), "Primary Key Index", "Record Count".append(stoi(sArraySize+3)), "FieldsPerRecord=6"];
	//Disused attempt to integrate header into existing buffer system. Decided it would be impractical.
	
	for(int i = 0;i < sArraySize; i++){
		OutBuff.Clear();
		int length=((strlen(sArray[i].state)+strlen(sArray[i].easternZipcode)+strlen(sArray[i].westernZipcode)+strlen(sArray[i].northernZipcode)+strlen(sArray[i].southernZipcode))+8);
		charlen=(char*)std::to_string(length).c_str();
		if(std::stoi(charlen)<10){
			charlen[1]=charlen[0];
			charlen[0]='0';
		}	
		OutBuff.Pack(charlen);
		OutBuff.Pack(sArray[i].state);
		OutBuff.Pack(sArray[i].easternZipcode);
		OutBuff.Pack(sArray[i].westernZipcode);
		OutBuff.Pack(sArray[i].northernZipcode);
		OutBuff.Pack(sArray[i].southernZipcode);
		OutBuff.Write(OutFile);
		std::cout << sArray[i].state << "," << sArray[i].easternZipcode << "," << sArray[i].westernZipcode << "," << sArray[i].northernZipcode << "," << sArray[i].southernZipcode << std::endl;
	}
	OutFile.close();
}

/**
\fn application
Contains the code for controlling the Zipcode class and generating output file.
\pre specified InFile must be present
\post sorted OutFile with zip codes from each state will be created
*/


void application(int argc, char** argv)
{
	if (argc!=3){
		std::cout<<"Must Specify an input and output file, e.g."<<std::endl<<"<executable name> 'input.csv' 'output.csv'"<<std::endl;
	} else {//If we don't need custom input/output files, this can be omitted.
	
	std::ifstream InFile(argv[1], std::ios::in);
	DelimTextBuffer InBuff;
	Zipcode :: InitBuffer (InBuff);
	
	//char** headerList=['FileType=CSV', 'Version=1.0', 'SizeType=ASCII', outputFileName.append(".pki"), "Primary Key Index", "Record Count".append(stoi(sArraySize+3)), "FieldsPerRecord=6"];
	
	//Unpack Header:
	InBuff.Read(InFile);
	
	/*
	char** HeaderInfo;
	

	InBuff.Unpack(HeaderInfo[0]);
	InBuff.Unpack(HeaderInfo[1]);
	InBuff.Unpack(HeaderInfo[2]);
	InBuff.Unpack(HeaderInfo[3]);
	InBuff.Unpack(HeaderInfo[4]);
	InBuff.Unpack(HeaderInfo[5]);
	InBuff.Unpack(HeaderInfo[6]);
	*/
	char HeaderLength[20];
	char FileType[20];
	char Version[20];
	char SizeType[20];
	char IndexFile[20];
	char IndexSchema[20];
	char RecordCount[20];
	char FieldsPerRecord[20];
	//std::cout<<"a"<<std::endl;
	InBuff.Unpack(HeaderLength);//This is only the header length for the line 1 and will be discarded
	//std::cout<<"b"<<std::endl;
	InBuff.Unpack(FileType);
	//std::cout<<"c"<<std::endl;
	InBuff.Unpack(Version);
	//std::cout<<"d"<<std::endl;
	InBuff.Unpack(SizeType);
	//std::cout<<"e"<<std::endl;
	InBuff.Unpack(IndexFile);
	//std::cout<<"f"<<std::endl;
	InBuff.Unpack(IndexSchema);
	//std::cout<<"g"<<std::endl;
	InBuff.Unpack(RecordCount);
	
	InBuff.Read(InFile);
	InBuff.Unpack(HeaderLength);//This is only the header length for the line 2 and will be discarded
	InBuff.Unpack(HeaderLength);//This is the total header length
	
	//std::cout<<"h"<<std::endl;
	InBuff.Unpack(FieldsPerRecord);
	//std::cout<<FileType[0]<<std::endl;
	//std::cout<<HeaderLength<<"/"<<FileType<<"/"<<Version<<"/"<<SizeType<<"/"<<IndexFile<<"/"<<IndexSchema<<"/"<<RecordCount<<"/"<<FieldsPerRecord<<std::endl;
	
	Zipcode ZipcodeArray[45000];
	stateStruct StateArray[50];
	int index = 0;
	int n = (sizeof(StateArray)/sizeof(StateArray[0]));

	
	

	while((InFile.peek()!=EOF)and (index==index)){
	InBuff.Read(InFile);//iterates through the entire file, creating Zipcode instances for each entry.
	if (ZipcodeArray[index].Unpack(InBuff)==1){//Can remove the if statement as the reason for it was never implemented due to a change in design strategy.
		index++;
	}
	}
	
	
	
	//Note that char[] IndexFile provides the filename for the Primary Key Index file.
	
	InFile.close();
	
	constructStateArray(StateArray,ZipcodeArray,n,index);

	std::sort(StateArray,StateArray+n, comparteStates);

	findLargestSmallestLatLong(StateArray,ZipcodeArray,n,index);

	std::string outputFileName = argv[2];
	DelimTextBuffer OutBuff;
	Zipcode :: InitBuffer (OutBuff);

	outputTable(outputFileName,OutBuff,StateArray,n);
	
	}//end if..else
		
}

/**
\fn main
Executes the code present in application()
*/

int main(int argc, char ** argv)
{

	application(argc, argv);

	return 0;
}