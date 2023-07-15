#include <iostream>
#include <string>
#include <direct.h>
using namespace std;

// PROTOTYPES
string getProjectName();
string getAuthorName();
bool validateProjectName(string);
bool validateAuthorName(string);

int main()
{
	// Get user input
	string projectName = getProjectName();
	string author = getAuthorName();
	int attempts = 0;

	// Validate input
	while ((!validateProjectName(projectName)) || (!validateAuthorName(author)))
	{
		if (!validateProjectName(projectName))
		{
			cout << "\nERROR: Invalid project name. Try again.\n";
			projectName = getProjectName();
			attempts++;
		}

		if (!validateAuthorName(author))
		{
			cout << "\nERROR: Invalid author name. Try again.\n";
			author = getAuthorName();
			attempts++;
		}


		if (attempts >= 3)
		{
			cout << "\nERROR: Too many attempts. Exiting program.\n";
			exit(1);
		}
	}

	// Clear screen
	cout << "\u001b[2J";

	// Output project details
	cout << "\n## PROJECT DETAILS ##\n"
		<< "Project name: " << projectName << '\n'
		<< "Author:       " << author << '\n';

	// Make directory with project name
	string parentDir = "C:\\Users\\rsamo\\test";
	string dir = projectName;

	_mkdir(string(parentDir + "\\" + dir).c_str());
	return 0;
}

string getProjectName()
{
	string projectName;
	cout << "\nWhat is the name of your project?\n";
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

// Returns true if project name is between 1-40 chars in length and only contains alphanumeric (A-za-z0-9) or dash ('-')
bool validateProjectName(string pname)
{
	// TODO: Validate that project name contains only letters, dashes, and numbers, and is bettwen 1-40 char in length
	if (pname.length() < 1 || pname.length() > 40)
	{
		return false;
	}

	for (auto c : pname)
	{
		if (!isalnum(c) && c != '-')
		{
			return false;
			//break;
		}
	}

	return true;

}

// Returns true if author name is between 1-40 chars in length
bool validateAuthorName(string authorString)
{
	if (authorString.length() < 1 || authorString.length() > 40)
	{
		return false;
	}

	return true;
}
