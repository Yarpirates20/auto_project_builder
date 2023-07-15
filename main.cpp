#include <iostream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

// PROTOTYPES
string getProjectName();
string getAuthorName();
bool validateProjectName(string);
bool validateAuthorName(string);
void createDirectory(string);

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


	// Create directory using project name
	auto err = std::error_code{};
	auto basepath = fs::path{ "C:\\Users\\rsamo\\test" };
	auto path = basepath / projectName;
	path.make_preferred();


	auto success = fs::create_directory(path, err);

	// Check whether error_code object holds code of an error with method value() 
	// If value is not 0, use the message() method to retrieve and print error code.
	if (err.value() != 0)
	{
		cout << err.message();
	}
	else
	{
		cout << "\u001b[2J";
		cout << "\nCreating directory... " << endl;
	}


	// Clear screen

	// Output project details
	cout << "\n## PROJECT DETAILS ##\n"
		<< "Project name: " << projectName << '\n'
		<< "Author:       " << author << '\n';

	cout << "Created directory at " << path.make_preferred() << endl;

	// Make directory with project name
	/*auto path = fs::path{ "C:\\Users\\rsamo\\test" };*/
	/*string dir = projectName;*/
	

	
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

void createDirectory(string pName)
{
	
}
