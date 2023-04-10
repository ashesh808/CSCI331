/**
 * @file Proj4_group5.cpp
 * @brief Driver file for Zipcode class
 * @version 0.1
 * @date 2023-04-10
 * \author Steven Kraus
 * \author Emily Yang
 * \author Tyler Knudtson
 * \author Ashesh Nepal
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

bool compareStates(State a, State b){
	if(a.stateName[0] == b.stateName[0])
		return(a.stateName[1] < b.stateName[1]);

	return (a.stateName[0] < b.stateName[0]);
}

/**
\fn constructStateArray;
copies into an array of stateStruct structs given an array of Zipcode objects
\param Array of stateStruct objects
\param Array of Zipcode Objects
\param int Size of stateStruct Array 
\param int Size of Zipcode Array
\post stateStruct Array will be filled with data from Zipcode Array*/
void constructStateArray(State sArray[], Zipcode zArray[], int zArraySize){
	int count = 0;
	for(int i = 0; i < zArraySize; i++){
		bool found = false;
		for(int j= 0; j < 50; j++){
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

/**
\fn findLargestSmallestLatLong
finds the largest and smallest latitudes and longitues and corresponding Zipcodes from an array of Zipcodes and stores them in an array of stateStruct's
\param Array of stateStruct objects
\param Array of Zipcode Objects
\param int Size of stateStruct Array 
\param int Size of Zipcode Array
\post stateStruct Array will be filled with data corresponding to Zipcodes that are the furthest in each direction*/
void setZipCodes(State sArray[], Zipcode zArray[], int zArraySize){

	for(int i = 0; i < zArraySize; i++){
		for(int j = 0; j < 51; j++){
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

/**
\fn outputTable
\param string The file name to output to
\param the DelimTextBuffer that will be used for output
\param Array of stateStruct objects
\param int Size of stateStruct Array 
\post the stateStruct array is packed into the buffer and written to the specified file*/
void outputTable(std::string outputFileName, DelimTextBuffer OutBuff, State sArray[], int sArraySize){
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
		int length=((strlen(sArray[i].stateName)+strlen(sArray[i].easternZipcode)+strlen(sArray[i].westernZipcode)+strlen(sArray[i].northernZipcode)+strlen(sArray[i].southernZipcode))+8);
		charlen=(char*)std::to_string(length).c_str();
		if(std::stoi(charlen)<10){
			charlen[1]=charlen[0];
			charlen[0]='0';
		}	
		OutBuff.Pack(charlen);
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

struct PKIStruct{
	char zipcode[10];
	char byteOffset[10];
};

//global Variables
static const int HEADER_FIELDS=17;
//HeaderArray INDEX TABLE:
//field type
static const int RECORD_SIZE = 0;
static const int ZIP_CODE = 1;
static const int PLACE_NAME = 2;
static const int STATE = 3;
static const int COUNTY = 4;
static const int LAT = 5;
static const int LONG = 6;
//Header Record Architecture
//84,FileType=CSV,Version=1.0,SizeType=ASCII,out.pki,Primary Key Index,RecordCount=53FieldsPerRecord=5,End_Header_Record,
static const int HEADER_RECORD_SIZE = 7;
static const int FILE_STRUCTURE_TYPE = 8;
static const int VERSION = 9;
static const int SIZE_FORMAT_TYPE = 10;
static const int INDEX_FILE_NAME = 11;
static const int INDEX_FILE_SCHEMA_INFO = 12;
static const int RECORD_COUNT = 13;
static const int FIELDS_PER_RECORD = 14;
static const int INDEX_FILE_FORMAT = 15;
static const int HEADER_RECORD_END = 16;

std::string headerArray[HEADER_FIELDS] = {
	"RecordSize",			//0 record_size
	"ZipCode",				//1	zip_code
	"PlaceName",			//2	place_name
	"State",				//3	state
	"County",				//4 county
	"Lat",					//5 lat
	"Long",					//6 long
	"HeaderRecordSize",		//CALCULATE THIS 7 header_record_size 
	"FileType=CSV",			//8 file_structure_type
	"Version=1.0",			//9 version
	"SizeType=ASCII",		//10 size_format_type
	"IndexFileName", 		//UPDATE THIS 11 index_file_name 
	"PKISchema=CSV",		//12 index_file_schema_info
	"RecordCount=10",		//UPDATE THIS 13 record_count 
	"FieldsPerRecord=5",	//14 fields_per_record
	"PKIFormat=PKI,Index"	//15 index_file_format
	"EndOfHeaderRecord"		//16 header_record_end
};
/**
\fn application
Contains the code for controlling the Zipcode class and generating output file.
\pre specified InFile must be present
\post sorted OutFile with zip codes from each state will be created
*/

int packHeader(std::string outputFileName, DelimTextBuffer OutBuff, std::string hArray[]){
	std::ofstream OutFile(outputFileName,std::ios::out);

	if(!OutFile) {std::cout << "error opening file" << std::endl;}

	OutBuff.Clear();
	for(int i = 0; i < HEADER_FIELDS; i++){
		OutBuff.PackHeader(hArray[i].c_str());
	}
	OutBuff.Write(OutFile);
	return OutFile.tellp();
}

//calculate the size of the PKI Header NOT WORKING RIGHT NOW REMOVE BEFORE TURN IN IF NOT FINISHED
std::string generatePKIHeader(std::string PKIheader){
	return PKIheader;
}

void generatePKI(std::ofstream& PKIOutFile, int currentPos, char * zipcode, int index){
	//std::cout << "entered generatePKI. Index: " << index << std::endl; //DEBUG


	std::string header = "5,PKI,zipcode,index,version:1.0";

	if(index == 0) {PKIOutFile << header << std::endl;}

	int totalBytes = currentPos;

	PKIOutFile << zipcode << ',' << index << std::endl;
	
}

void outputCSV(std::string outputFileName,std::string PKIoutputFileName, DelimTextBuffer OutBuff, Zipcode zArray[], int zSize, std::string hArray[])
{
	//std::cout << "Entered outputCSV" << std::endl; //DEBUG


	std::ofstream OutFile(outputFileName,std::ios::out);
	std::ofstream PKIOutFile(PKIoutputFileName,std::ios::out);

	unsigned int totalBytes = 0;
	int recordLength;
	int pos;
	std::string s;

	if(OutFile.fail()){std::cout<<"error opening csv"<<std::endl;return;}
	if(PKIOutFile.fail()){std::cout<<"error opening pki"<<std::endl;return;}

	hArray[HEADER_RECORD_SIZE] = "calculate this";
	hArray[INDEX_FILE_NAME] = PKIoutputFileName;
	s = std::to_string(zSize);
	hArray[RECORD_COUNT]=s;

	pos = packHeader(outputFileName,OutBuff,hArray);
	OutFile.seekp(pos);
	for(int i = 0; i < zSize; i++){
		generatePKI(PKIOutFile,totalBytes,zArray[i].Code,i);
		recordLength = zArray[i].Size();
		s = std::to_string(recordLength);
		OutBuff.Clear();
		OutBuff.Pack(s.c_str());
		OutBuff.Pack(zArray[i].Code);
		OutBuff.Pack(zArray[i].Placename);
		OutBuff.Pack(zArray[i].State);
		OutBuff.Pack(zArray[i].County);
		OutBuff.Pack(zArray[i].Lat);
		OutBuff.Pack(zArray[i].Long);
		OutBuff.Write(OutFile);
		totalBytes +=(recordLength + 2);
	}

}

int readFileWithHeaderLength(Zipcode zArray[], DelimTextBuffer InBuff, std::string InFileName)
{
	std::ifstream InFile(InFileName, std::ios::in);
	if(InFile.fail()){std::cout<<"error opening csv"<<std::endl;return 0;}
	Zipcode::InitBuffer(InBuff);
	int index = 0;
	int pos = 0;
	char temp[100];

	pos = InBuff.ReadHeader(InFile);
	for(int i = 0; i < HEADER_FIELDS; i++){
		InBuff.UnpackHeader(temp);
		headerArray[i] = temp;
	}

	if(headerArray[FILE_STRUCTURE_TYPE]!="FileType=CSV"||headerArray[VERSION]!="Version=1.0"){
		std::cout <<"INCOMPATIBLE FILE!" << std::endl;
		return 0;
	}

	InFile.seekg(pos);
	while(InFile.peek()!=EOF)
	{
		InBuff.Read(InFile);
		zArray[index].Unpack(InBuff);
		index++;
	}
	InFile.close();

	return index;
}

int readFileNoHeaderLength(Zipcode zArray[], DelimTextBuffer InBuff, std::string InFileName){
	//std::cout <<"readFile entered" << std::endl;//DEBUG


	std::ifstream InFile(InFileName, std::ios::in);
	Zipcode::InitBuffer(InBuff);
	int index = 0;

	if(InFile.fail()){std::cout<<"error opening csv"<<std::endl;return 0;}

	while(InFile.peek()!=EOF){
		//std::cout << "read file index: " << index << std::endl; //DEBUG
		InBuff.Read(InFile);
		zArray[index].Unpack(InBuff);
		index++;
	}

	InFile.close();


	//std::cout << "readFile complete" << std::endl; //DEBUG


	return index;
}

int readPKI(PKIStruct pArray[],std::string PKIFileName){
	std::ifstream PKIFile(PKIFileName, std::ios::in);
	DelimTextBuffer InBuff;
	int index = 0;
	char z[10];
	char b[10];
	char trash[100];
	PKIFile.getline(trash,100);//get the header and trash it
	while(PKIFile.peek()!=EOF){
		PKIFile.getline(z,10,',');
		PKIFile.getline(b,10);
		strcpy(pArray[index].zipcode,z);
		strcpy(pArray[index].byteOffset,b);
		index++;
	}

	return index;
}

void searchPKI(int zIndex, int pIndex, int argc, char** argv, Zipcode zArray[], PKIStruct pArray[]){
	char arg[10];
	bool found;
	for(int i = 1; i < argc; i++){
		found = false;
		strcpy(arg,argv[i]);
		memmove(arg,arg+1,strlen(arg));//removing -Z from user provided zipcode
		memmove(arg,arg+1,strlen(arg));
		for(int j = 0; j < pIndex; j++){
			if(strcmp(arg,pArray[j].zipcode) == 0){
				std::cout << "Zipcode Found!" << std::endl;
				zArray[std::stoi(pArray[j].byteOffset)].Print(std::cout);
				found = true;
				break;
			}
		}
		if(!found){
			std::cout << "Zipcdoe " << arg << " was not found within this file!" << std::endl;
		}

	}
}

void application(int argc, char** argv)
{

	//if (argc!=3){
	//	std::cout<<"Must Specify an input and output file, e.g."<<std::endl<<"<executable name> 'input.csv' 'output.csv'"<<std::endl;
	//} else {//If we don't need custom input/output files, this can be omitted.
	
	Zipcode ZipcodeArray[45000];
	PKIStruct PKIArray[45000];
	stateStruct StateArray[50];

	int zIndex = 0;
	int pIndex = 0;
	int n = (sizeof(StateArray)/sizeof(StateArray[0]));
	std::string fileName;
	std::string InFileName = "OUTFILE.csv";
	std::string PKIFileName;

	bool another = true;

	while(another){
		std::cout << "Enter the file name you would like to use or type <cr> to use the default file: ";
		std::cin >> fileName;

		if(fileName == "<cr>"){
			std::cout << "Using default file: " << InFileName << std::endl;
		}
		else{
			std::cout << "Using file: " << fileName << std::endl;
			InFileName = fileName;
 		}

		PKIFileName = InFileName;

		int input;
		std::cout << "Do you want to generate a PKI(0) or serach a PKI(1)";
		std::cin >> input;
		if(input != 1 && input != 0){
			std::cout <<"You didn't enter a valid option. Goodbye" << std::endl;
			return;
		}

		DelimTextBuffer InBuff;
		PKIFileName.pop_back();
		PKIFileName.pop_back();
		PKIFileName.pop_back();
		PKIFileName += "pki";

		zIndex=readFileWithHeaderLength(ZipcodeArray,InBuff,InFileName);

		if(zIndex == 0){
			std::cout << "File doesn't exist, or cannot be opened. Try again." << std::endl;
			return;
		}

		if(input==1){
			if(!argv[1]){
				std::cout << "You didn't enter any arguments. Try using -Z501 next time." << std::endl;
				return;
			}

			pIndex = readPKI(PKIArray,PKIFileName);
			if(zIndex!=pIndex){
				std::cout << "Something is really wrong! The length of the PKI isn't the same as your file! Did you generate a PKI with this file first?" << std::endl;
				return;
			}
			searchPKI(zIndex,pIndex,argc,argv,ZipcodeArray,PKIArray);
		}
		else if(input == 0){
			std::string outputFileName = InFileName;
			DelimTextBuffer Outbuff;
			Zipcode::InitBuffer(Outbuff);

			outputCSV(outputFileName,PKIFileName,Outbuff,ZipcodeArray,zIndex,headerArray);
		}
		std::string choice;
		std::cout <<"Would you like to try another file? Type 'end' to exit the program: ";
		std::cin >> choice;

		if(choice == "end"){another = false;}
	}
	/*
	//std::ifstream InFile(argv[1], std::ios::in);
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
	
	ADD BACK MULTILINE COMMENT SYMBOL HERE IF UNCOMMENTED

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
	
	}//end if..else*/
		
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