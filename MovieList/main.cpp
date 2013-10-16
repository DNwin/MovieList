#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct MovieNode
{
	string title;
	string actor1;
	string actor2;
	string genre1;
	string genre2;
	int year;
	int rating;
	string plot;
	MovieNode *next;
};

void OutputHeader(string asName,   // IN - assignment Name
				  char asType,	   // IN - assignment type
								   // - (LAB or ASSIGNMENT)
				  int asNum);	   // IN - assignment number
void WordWrap(string inputString, ofstream &outFile);
MovieNode *CreateList(string filename);
void OutputList(MovieNode *head, string filename);



int main()

{
	string inFilename;
	string outFilename;

	MovieNode *movieList;

	// OutputHeader - Prints class header to output
	OutputHeader("Intro to Linked Lists", 'a', 6);

	// IN - Get names of the input and output files
	cout << "Please enter the name of the input file: ";
	getline(cin, inFilename);

	cout << "\nPlease enter the name of the output file: ";
	getline(cin, outFilename);

	// CreateList - Create a linked list, store the head pointer
	movieList = CreateList(inFilename);

	// OutputList - Formatted output of the linked list to text file 
	OutputList(movieList, outFilename);	
}

void OutputList(MovieNode *head,	// IN - Movie linked list
				string filename)	// IN - Name of output file
{
	ofstream outFile;		// OUT - Output file stream
	MovieNode *moviePtr;	// OUT - Points to current node in list
	int movieCnt;			// OUT - Current list count of movie
	
	outFile.open(filename.c_str());
	movieCnt = 1;

	// Set movie ponter to first item in the list
	moviePtr = head;

	while (moviePtr != NULL)
	{
		// Line 1 - Horizonal line of asterisks
		outFile << setfill('*') << setw(75) << '*' <<  setfill(' ') << endl;
		// Line 2 - Current count of the movie and title
		outFile << "MOVIE #: " << left << setw(9) << movieCnt << "Title: ";
		// IF ELSE - Output "..." if title is longer than 50 chars.
		if (moviePtr->title.length() > 50)
		{
			outFile << moviePtr->title.substr(0,44) << " ..." << endl;
		}
		else
		{
		outFile << moviePtr->title << endl;
		}
		// Line 3 - Horizontal line of hyphens
		outFile << setfill('-') << setw(75) << '-' << setfill(' ') << endl;
		// Line 4 - Year and Rating
		outFile << "Year: " << setw(12) << moviePtr->year << "Rating: " << moviePtr->rating << endl;
		// Line 5 - Horizontal line of hyphens
		outFile << setfill('-') << setw(75) << '-' << setfill(' ') << endl;
		// Line 6 & 7 - Actors and genres
		outFile << setw(18) << "Leading Actor:" << setw(25) << moviePtr->actor1 
			 << "Genre 1: " << moviePtr->genre1 << endl;
		outFile << setw(18) << "Supporting Actor:" << setw(25) << moviePtr->actor2 
			 << "Genre 2: " << moviePtr->genre2 << right << endl;
		// Line 8 - Horizontal line of hyphens
		outFile << setfill('-') << setw(75) << '-' << setfill(' ') << endl;
		// Line 9+ - Plot
		outFile << "PLOT:" << endl;

		// WordWrap - Output formatted plot string followed by horizonal line
		WordWrap(moviePtr->plot, outFile);

		outFile << setfill('*') << setw(75) << '*' <<  setfill(' ');
		outFile << endl << endl << endl;
	
		movieCnt++;
		moviePtr = moviePtr->next;
	}

	outFile.close();
}

MovieNode* CreateList(string filename)	// IN - Name of input file		
{
	ifstream inFile;		// IN - Input file stream
	MovieNode *head;		// IN - Head pointer of linked list
	MovieNode *moviePtr;	// IN - Current pointer of linked list

	// Initialize
	inFile.open(filename.c_str());
	head = NULL;
	moviePtr = NULL;
	moviePtr = new MovieNode;

	while (inFile && moviePtr != NULL)
	{
		// IN - Get data from input file and store into members of node
		getline(inFile, moviePtr->title);
		getline(inFile, moviePtr->actor1);
		getline(inFile, moviePtr->actor2);
		getline(inFile, moviePtr->genre1);
		getline(inFile, moviePtr->genre2);
		inFile >> moviePtr->year;
		inFile >> moviePtr->rating;
		inFile.ignore(10000,'\n');
		getline(inFile, moviePtr->plot);
		// Ignore the blank line
		inFile.ignore(10000,'\n');

		// Set next pointer of node to previous first node
		moviePtr->next = head;
		// Set head pointer to the initialized node.
		head = moviePtr;
		// Create a new node.
		moviePtr = new MovieNode;
	}
	// Dealloc unused memory and close input file stream
	delete moviePtr;
	inFile.close();

	return head;
}

void WordWrap(string inputString, // IN - String to be formatted
			  ofstream &outFile)  // OUT - Output to be written to	
{
	const int MAX_LENGTH = 74;
	string line;
	string word;
	int index;
	
	word = "";
	line = "";

	for (index = 0; index < inputString.length(); index++)
	{
		// Add each character to word if it is not a space.
		if (inputString[index] != ' ')
		{
			word += inputString[index];
		}

		// ELSE - Executes when a full word is stored.
		else
		{
			// OUT - Output if the line + word exceeds max length
			if (line.length() + word.length() > MAX_LENGTH)
			{
				outFile << line << endl;
				line.clear();
			}

			// Add the word to the line if less than max length
			line += word + " ";
			word.clear();
		}
	}

	// OUT - Add very last word to the line and output the last line.
	line += word;
	outFile << line << endl;

}