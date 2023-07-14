#include <iostream>
#include <string>
using namespace std;

// PROTOTYPES
string getProjectName();
string getAuthorName();
bool validateProjectName(string);
bool validateAuthorName(string);

int main()
{
	// TODO: use c-string array with size 40 for project name
	// Validate by checking if each char isnum, isalpha, or is '-'
	// Change function type to const char *
	string projectName = getProjectName();
	string author = getAuthorName();

	cout << "\n## PROJECT DETAILS ##\n"
		<< "Project name: " << projectName << '\n'
		<< "Author:       " << author << '\n';

	if (validateProjectName(projectName) == false)
	{
		cout << "\nERROR: Invalid project name!\n";
	}
	else
	{
		cout << "\nPROJECT NAME VALID!\n";
	}
	return 0;
}

string getProjectName()
{
	string projectName;
	cout << "What is the name of your project?\n";
	getline(cin, projectName);
	return projectName;
}

string getAuthorName()
{
	string author;
	cout << "\nWho is the author of this project?\n";
	getline(cin, author);
	return author;
}

bool validateProjectName(string pname)
{
	// TODO: Validate that project name contains only letters, dashes, and numbers, and is bettwen 1-40 char in length
	if (pname.length() < 1 || pname.length() > 40)
	{
		return false;
	}
	else if (!isalnum)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}
