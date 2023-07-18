#include <iostream>
#include <string>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <inja/inja.hpp>

using namespace std;
using namespace inja;
namespace fs = std::filesystem;

// PROTOTYPES
string getProjectName();
string getAuthorName();
bool validateProjectName(string);
bool validateAuthorName(string);
//string createREADME(string, string);


int main()
{

	// Get user input
	//string projectName = getProjectName();
	//string author = getAuthorName();
	int attempts = 0;
	string projectName = "testProject";
	string author = "Rob Test";

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

	// Get current time in unix timestamp format
	auto now = std::chrono::system_clock::now();
	auto timestamp = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
	projectName += to_string(timestamp);


	// Create directory using project name
	auto err = std::error_code{};
	auto basepath = fs::path{ "C:\\Users\\rsamo\\test" };
	auto path = basepath / projectName;
	path.make_preferred();


	auto success = fs::create_directory(path, err);

	// Add readme to directory
	auto readmePath = path / "README.md";
	ofstream outfile;

	//##################
	// Fix template problem
	// Render from template
	string path_string{ path.string() };
	Environment env;
	json data;
	data["projectName"] = projectName;
	data["author"] = author;
	Template temp = env.parse_template("C:/Users/rsamo/source/repos/auto_project_builder/README.md.template");

	env.write(temp, data, path_string + "/README.md");
	// Open and write to file
	//string templatePN = render("Welcome to {{ projectName }}!", data);
	//string templateAuth = render("Created by {{ author }}", data);

	/*cout << templatePN << templateAuth << endl;*/

	
	//outfile.open(readmePath);

	//outfile << "\n" << templatePN << endl;
	//outfile << "\n\n" << templateAuth << endl;
	
	//outfile << "\n\n";

	//outfile.close();

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


	// Output project details
	cout << "\n## PROJECT DETAILS ##\n"
		<< "Project name: " << projectName << '\n'
		<< "Author:       " << author << '\n';

	cout << "Created directory at " << path.make_preferred() << endl;
	cout << "Created file at " << readmePath.make_preferred() << endl;

	//string README = createREADME(projectName, author);
	/*cout << "Rendered README ";*/


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

//string createREADME(string projectName, string author)
//{
//	Environment env;
//	json data;
//	Template temp = env.parse_template("./README.md.template");
//	data["projectName"] = projectName;
//	data["author"] = author;
//
//	string result = env.render(temp, data);
//	return result;
//}



