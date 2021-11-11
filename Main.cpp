/*
Mason McManus
C++ Fa21
Due November 10 2021
CIS162
Lab 6: Binary to Decimal Conversion : The goal is to write a C++ program that reads characters representing binary
		numbers from a data file called BinaryIn.dat and translates them to decimal 
		numbers.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void InputFile(ifstream& inFile);  // Commanded to input a specific file
void InputFileZero(ifstream& inFile, char& input, int& position);  // The first input has found a zero within the input file
void PrintTable(int totalnumber, string binaryNum);  // The main function ran the binary numbers successfully
void AddedTotal(int& totalnumber, char input, int& position, string& binaryNum);  // Function will read an input that is given to the user (inputs will be 1 and 0)
int Decimal(int totalnumber);  // The main function calculated the correct number
void Reset(int& totalnumber, int& position, string& binaryNum);  // The while loop has either caught an error in the function or it noticed a new line

int main()
{
	ifstream inFile;

	cout << setw(22) << "Binary Number:" << setw(24) << "Decimal:" << endl;  // Heading for the output

	FileCheck(inFile);

	char input;  // Reads the character from the input file
	int totalnumbers = 0;  // Stores the decimal equivalent of input
	int position = 0;  // A counter that spots where the users curser is
	string binaryNum = "";  // Empty string to store input characters

	while (inFile.get(input) || (totalnumbers != 0))  // Shows if the input is vaild or has a running total
	{ 

		if (input == '0' && position == 0)  // If a 0 is read on the first space of a line
		{  
			RemoveLeadingZeros(inFile, input, position);
		}

		if ((input == '\n' && position > 0) || (!inFile))  // If file input cursor has read a new line where the position is at one
		{ 

			
			PrintTable(totalnumbers, binaryNum);  // Prints the table in the console

			
			Reset(totalnumbers, position, binaryNum);  // Resets counters for the next line of input
		}
		else if (input == '1' || input == '0')  // If the input character is a 1 or a 0
		{ 
			AddedTotal(totalnumbers, input, position, binaryNum);
		}
		else if (input == '\t' && position == 0)  // If the cursor reads a newline character on the first spot for a character
		{ 

			continue;  // Go over the function from the beginnning to make sure it works correctly
		}
		else if ((int(input) < '0' || int(input) > '1') && (input != ' ') || (input == ' ' && position > 0)) { //If the ASCII code for input is less than '0' or greater than '1' AND NOT a space (32 is ASCII code for ' ') OR there is a space in a binary number when position > 0

			cout << setw(24) << "There is bad data in the output";  // Print error message to the console

			Reset(totalnumbers, position, binaryNum);  // Resets counters for the line

			inFile.ignore(1000, '\n');  // Ignores all characters on the input line with bad data
		}
	}

	inFile.close();  // Close the input file
	return 0;
}

void FileCheck(ifstream& inFile) {
	inFile.open("BinaryIn.dat");

	if (!inFile) {
		cout << "The input file failed to open.\n";
	}
}

void RemoveLeadingZeros(ifstream& inFile, char& input, int& position) {

	bool isOne = false;
	bool isBadData = false;

	while (!isOne && !isBadData)  // The input is neither badd data or a one
	{

		position++;  // Go to the file cursor
		inFile.get(input);

		if (input == '1')
			isOne = true;  // First one of binary number found

		if ((int(input) < '0' || int(input) > '1') && (input != ' ') || (input == ' ' && position > 0)) // If anything other than a 1 or a 0 is read and the input is not a space in the middle of a binary number
		{  
			isBadData = true;  // Bad data found
		}
	}
}

void InputFile(ifstream& inFile)
{
	inFile.open("BinaryIn.dat");

	if (!inFile)
	{
		cout << "There was an error retrieving your file..." << endl;
	}
}

void InputFileZero(ifstream& inFile, char& input, int& position)
{
	bool one = true;  // The data value is equal to one
	bool bad = true;  // The data value is a bad data value

	while (!one && !bad);  // Shows that there is not a one or any bad data within the function
	{
		position++;
		inFile.get(input);
		if (input == '1');
		one = true;
		if ((int(input) < '0' || int(input) > '1') && (input != ' ') || (input == ' ' && position > 0));
		bad = true;
	}

}

void PrintTable(int totalnumber, string binaryNum)  // Prints out the data values by using a switch function
{
	switch (binaryNum.length()) 
	{

	case 1:
		cout << setw(long(binaryNum.length() + 14)) << binaryNum;
		break;

	case 2:
		cout << setw(long(binaryNum.length() + 13)) << binaryNum;
		break;

	case 3:
		cout << setw(long(binaryNum.length() + 13)) << binaryNum;
		break;

	case 4:
		cout << setw(long(binaryNum.length() + 12)) << binaryNum;
		break;

	case 5:
		cout << setw(long(binaryNum.length() + 12)) << binaryNum;
		break;

	case 6:
		cout << setw(long(binaryNum.length() + 11)) << binaryNum;
		break;

	case 7:
		cout << setw(long(binaryNum.length() + 11)) << binaryNum;
		break;

	case 8:
		cout << setw(long(binaryNum.length() + 10)) << binaryNum;
		break;

	case 9:
		cout << setw(long(binaryNum.length() + 10)) << binaryNum;
		break;

	case 10:
		cout << setw(long(binaryNum.length() + 9)) << binaryNum;
		break;

	case 11:
		cout << setw(long(binaryNum.length() + 9)) << binaryNum;
		break;

	case 12:
		cout << setw(long(binaryNum.length() + 8)) << binaryNum;
		break;

	case 13:
		cout << setw(long(binaryNum.length() + 8)) << binaryNum;
		break;

	case 14:
		cout << setw(long(binaryNum.length() + 7)) << binaryNum;
		break;

	case 15:
		cout << setw(long(binaryNum.length() + 7)) << binaryNum;
		break;

	case 16:
		cout << setw(long(binaryNum.length() + 6)) << binaryNum;
		break;

	default:
		cout << setw(22) << "There can only be a 16-bit limit";
		break;
	}
}
	
switch (Decimal(totalnumber)) // Switches off of the decimal place value to determine spacing in output
{ 

	case 1:

		if (totalnumber < 4)
		{
			cout << setw(20) << totalnumber << endl;
		}
		else
			cout << setw(19) << totalnumber << endl;
		break;

	case 2:
		if (totalnumber <= 15) 
		{
			cout << setw(19) << totalnumber << endl;
		}
		else if (totalnumber <= 32) 
		{
			cout << setw(18) << totalnumber << endl;
		}
		else if (totalnumber > 32 && totalnumber <= 63)
		{
			cout << setw(18) << totalnumber << endl;
		}
		else
			cout << setw(17) << totalnumber << endl;
		break;

	case 3:
		if (totalnumber < 256) 
		{
			cout << setw(18) << totalnumber << endl;
		}
		else
			cout << setw(17) << totalnumber << endl;
		break;

	case 4:
		if (totalnumber >= 1000 && totalnumber < 1024) 
		{
			cout << setw(17) << totalnumber << endl;
		}
		else if (totalnumber >= 1024 && totalnumber < 2048) 
		{
			cout << setw(16) << totalnumber << endl;
		}
		else if (totalnumber >= 2048 && totalnumber <= 4095) 
		{
			cout << setw(16) << totalnumber << endl;
		}
		else if (totalnumber >= 4096 && totalnumber < 10000) 
		{
			cout << setw(15) << totalnumber << endl;
		}
		break;

	case 5:
		if (totalnumber >= 10000 && totalnumber < 16384) 
		{
			cout << setw(16) << totalnumber << endl;
		}
		else if (totalnumber >= 16384 && totalnumber <= 32768) 
		{
			cout << setw(15) << totalnumber << endl;
		}
		else if (totalnumber > 32768 && totalnumber <= 65535) 
		{
			cout << setw(15) << totalnumber << endl;
		}
		break;
}

void AddedTotal(int& totalnumber, char input, int& position, string& binaryNum) // Either going to add a one or a zero
{
	int n;

	if (input == '1')
		n = 1;
	else
		n = 0;

	binaryNum += input; // Uses the string function to add the one or the zero to the string
	totalnumber = (totalnumber * 2) + n; // Multiplying the total amount by 2 and then adding 1 to that solution
	position++; // Add in the file cursor
}
}

int Decimal(int totalnumber)
{
int placeValue = 0;

	while (totalnumber != 0) 
	{
		totalnumber /= 10;
		placeValue++;
	}

	return placeValue;
	return 0;
}

void Reset(int& totalnumber, int& position, string& binaryNum)  // Resets counters for the next line of input
{
	
	position = 0;
	totalnumber = 0;
	binaryNum = "";
}