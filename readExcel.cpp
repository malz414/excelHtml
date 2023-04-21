
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "windows.h"
using namespace std;


string random_string()
{
	std::string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	std::random_device rd;
	std::mt19937 generator(rd());

	std::shuffle(str.begin(), str.end(), generator);

	return str.substr(0, 7);    // assumes 32 < number of characters in str         
};

int main()
{
	ifstream inFile;

	string name;
	string description;
	string itemNum;
	string price;

	inFile.open("C:\\Users\\maliq\\Documents\\newstuff.csv");
	if (inFile.is_open()) {
		cout << "File has been opened" << endl;
	}
	else {
		cout << "NO FILE HAS BEEN OPENED" << endl;
	}


	while (!inFile.eof()) {

		string rand = random_string();

		getline(inFile, itemNum, ',');
		getline(inFile, name, ',');
		getline(inFile, description, ',');
		getline(inFile, price);



		cout << "<li> \n <div class = \"col-md-3 text-center\">   <strong>" << name << "</strong> \n<br> "
			<< "<img src = \"assets/" << itemNum << ".jpg\" alt=\"" << name << "\" loading=\"lazy\"  width = \"150px\" height = \"150px\">" << endl
			<< "<br>" << endl
			<< "<strong>$" << price << "</strong>" << endl
			<< "<br>" << endl
			<< "<button class = \"btn btn-danger my-cart-btn\" data-id = \"" << itemNum << "\" data-name=\"" << name << "\" data-price=\"" << price << "\" data-quantity = \"1\"  data-summary=\"summary 1\" data-image = \"assets/" << itemNum << ".jpeg\">Add to Cart</button>" << endl
			<< "<a>" << endl
			<< "<button type=\"button\" class=\"btn btn-primary\" data-toggle = \"modal\" data-target=\"#" << rand << "\">" << endl
			<< "DETAILS" << endl
			<< "</button>" << endl
			<< "<div class = \"modal fade\" id = \"" << rand << "\" tabindex = \"-1\" role=\"dialog\" aria-labelledby = \"exampleModalCenterTitle\" aria-hidden = \"true\">" << endl
			<< " <div class=\"modal-dialog modal-dialog-centered\" role=\"document\">" << endl
			<< "<div class = \"modal-content\">" << endl
			<< "<div class=\"modal-body\">" << endl
			<< "<img src = \"assets/" << itemNum << ".jpg\" alt=\"" << name << "\" loading=\"lazy\" width = \"150px\" height = \"150px\">" << endl
			<< "<br>" << endl
			<< "   <!--Put Desription here-->" << endl
			<< description << endl
			<< "</div>" << endl
			<< "<div class=\"modal-footer\">" << endl
			<< "<button type=\"button\" class=\"btn btn-secondary\" data-dismiss=\"modal\">Close</button>" << endl
			<< "<button class = \"btn btn-danger my-cart-btn\" data-id = \"" << itemNum << "\" data-name=\"" << name << "\" data-price=\"" << price << "\" data-quantity=\"1\"  data-summary = \"summary 1\" data-image = \"assets/" << itemNum << ".jpeg\">Add to Cart</button>" << endl
			<< "</div>" << endl
			<< "</div>" << endl
			<< "</div>" << endl
			<< "</div>" << endl

			<< "<div style=\"display:none;\">" << name << "</div></a>" << endl
			<< "</div>" << endl
			<< "</li>" << endl;
	}
	inFile.close();
	system("pause");
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
