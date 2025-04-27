
#include <iostream>
#include <sstream>

class wordReverser
{
	public:
		 static void wordReverserString(std:: string& sentence);
};

void wordReverser:: wordReverserString(std:: string& sentence)
{
	std:: stringstream ss(sentence);
	
	std:: string word;
	std:: string rword;

	while (ss >> word)
	{
		if (rword.empty())
			rword = word;
		else
		{
			std:: cout << "rword before: " << rword << std:: endl;
			std:: cout << "word before: " << word << std:: endl;
			rword = word + " " + rword;
			std:: cout << rword << std::endl;
		}	
	}
}


int main()
{
	std:: string line = "Gekko bro ka cola";
	wordReverser:: wordReverserString(line);
	
	std:: cout << (float)1/3 << std::endl;
}