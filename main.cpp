#include <iostream>
#include <string>
using namespace std;

// PROTOTYPES
string getProjectName();
string getAuthorName();

int main()
{
	string projectName = getProjectName();
	string author = getAuthorName();

	cout << "\n## PROJECT DETAILS ##\n"
		<< "Project name: " << projectName << '\n'
		<< "Author:       " << author << '\n';


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
