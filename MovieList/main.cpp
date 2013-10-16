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


void WordWrap(string inputString);
MovieNode *CreateList(string filename);



int main()

{
	MovieNode *movieList;
	MovieNode *moviePtr;

	movieList = CreateList("InputFile.txt");

	// Set movie ponter to first item in the list
	moviePtr = movieList;

	int movieCnt = 10;

	// Line 1 - Horizonal line of asterisks
	cout << setfill('*') << setw(75) << '*' <<  setfill(' ') << endl;
	// Line 2 - Movie number and Title
	cout << "MOVIE #: " << left << setw(9) << movieCnt << "Title: ";
	// IF ELSE - Output "..." if title is longer than 50 chars.
	if (moviePtr->title.length() > 50)
	{
		cout << moviePtr->title.substr(0,44) << " ..." << endl;
	}
	else
	{
	cout << moviePtr->title << endl;
	}
	// Line 3 - Horizontal line of hyphens
	cout << setfill('-') << setw(75) << '-' << setfill(' ') << endl;
	// Line 4 - Year and Rating
	cout << "Year: " << setw(12) << moviePtr->year << "Rating: " << moviePtr->rating << endl;
	// Line 5 - Horizontal line of hyphens
	cout << setfill('-') << setw(75) << '-' << setfill(' ') << endl;
	// Line 6 & 7 - Actors and genres
	cout << setw(18) << "Leading Actor:" << setw(25) << moviePtr->actor1 
		 << "Genre 1: " << moviePtr->genre1 << endl;
	cout << setw(18) << "Supporting Actor:" << setw(25) << moviePtr->actor2 
		 << "Genre 2: " << moviePtr->genre2 << right << endl;
	// Line 8 - Horizontal line of hyphens
	cout << setfill('-') << setw(75) << '-' << setfill(' ') << endl;
	// Line 9+ - Plot
	cout << "PLOT:" << endl;
	// WordWrap - Output formatted plot string followed by horizonal line
	WordWrap(moviePtr->plot);
	cout << setfill('*') << setw(75) << '*' <<  setfill(' ') << endl;
	
}

MovieNode* CreateList(string filename)
{
	ifstream inFile;
	// Use pointers to create a linked list.
	MovieNode *head;
	MovieNode *moviePtr;

	inFile.open(filename.c_str());
	head = NULL;
	moviePtr = NULL;
	moviePtr = new MovieNode;

	while (inFile && moviePtr != NULL)
	{
		getline(inFile, moviePtr->title);
		getline(inFile, moviePtr->actor1);
		getline(inFile, moviePtr->actor2);
		getline(inFile, moviePtr->genre1);
		getline(inFile, moviePtr->genre2);
		inFile >> moviePtr->year;
		inFile >> moviePtr->rating;
		inFile.ignore(10000,'\n');
		getline(inFile, moviePtr->plot);
		inFile.ignore(10000,'\n');

		// Set next pointer of new node to first node
		moviePtr->next = head;
		// Set head pointer to the new node.
		head = moviePtr;
		moviePtr = new MovieNode;

		
	}

	delete moviePtr;
	inFile.close();

	return head;
}


void WordWrap(string inputString)
{
	const int MAX_LENGTH = 75;
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
				cout << line << endl;
				line.clear();
			}

			// Add the word to the line if less than max length
			line += word + " ";
			word.clear();
		}
	}

	// OUT - Add very last word to the line and output the last line.
	line += word;
	cout << line << endl;

}