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
//void writeFileFromTemplate();
//string createREADME(string, string);


int main()
{

	// Get user input
	//string projectName = getProjectName();
	//string author = getAuthorName();
	int attempts = 0;
	string projectName = getProjectName();
	string author = getAuthorName();
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
	/*auto now = std::chrono::system_clock::now();
	auto timestamp = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
	projectName += to_string(timestamp);*/


	// Create directory using project name
	auto err = std::error_code{};
	auto basepath = fs::path{ "C:\\Users\\rsamo\\test" };
	auto path = basepath / projectName;
	//path.make_preferred();


	auto success = fs::create_directory(path, err);

	/* Check whether error_code object holds code of an error witmethod value() 
	 If value is not 0, use the message() method to retrieve and print error code.*/
	if (err.value() != 0)
	{
		cout << err.message();
	}
	else
	{
		cout << "\u001b[2J";
		cout << "\nCreating directory... " << endl;
	}

	
	// ### Render from template ###
	// Create string from path to use with Inja since it only accepts strings 
	string path_string{ path.string() };
	string templatePath = "C:/Users/rsamo/source/repos/auto_project_builder/";

	// Create template environment and json to store project data
	Environment env;
	json data;
	data["projectName"] = projectName;
	data["author"] = author;

	// Read from template in project directory
	Template temp = env.parse_template(templatePath + "README.md.template");

	//Write to README.md in project directory
	env.write(temp, data, path_string + "/README.md");

	// Check whether error_code object holds code of an error with method value() 
	// If value is not 0, use the message() method to retrieve and print error code.
	//if (err.value() != 0)
	//{
	//	cout << err.message();
	//}
	//else
	//{
	//	cout << "\u001b[2J";
	//	cout << "\nCreating directory... " << endl;
	//}

	//##### TODO.MD TEMPLATE #####
		// Read from template in project directory
	temp = env.parse_template("C:/Users/rsamo/source/repos/auto_project_builder/TODO.md.template");

	//Write to TODO.md in project directory
	env.write(temp, data, path_string + "/TODO.md");

	//##### main.cpp TEMPLATE #####
		// Read from template in project directory
	temp = env.parse_template("C:/Users/rsamo/source/repos/auto_project_builder/main.cpp.template");

	//Write to TODO.md in project directory
	env.write(temp, data, path_string + "/main.cpp");


	// Output project details
	cout << "\n## PROJECT DETAILS ##\n"
		<< "Project name: " << projectName << '\n'
		<< "Author:       " << author << '\n';

	cout << "Created directory at " << path_string << endl;
	cout << "Created file at " << path_string << "\\README.md" << endl;
	cout << "Created file at " << path_string << "\\TODO.md" << endl;
	cout << "Created file at " << path_string << "\\main.cpp" << endl;

	


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



