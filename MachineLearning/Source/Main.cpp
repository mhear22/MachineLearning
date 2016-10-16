//-h or -help or ? should return help page
//-s or -start {filename} should open the file
//-t or -test {Filename, Items to test with} the training data that should be opened
//-r or -rms {frequency integer} should show the RMS Error on iteration
//-e or -error {Percent} should be the percentage inaccuracy
//-q or -quit or q or quit should quit

//App should remember state so cycles can be operated again

#include "Tree.h"
#include "Header.h"

using namespace std;

char* getItem(int count, char* args[], char* errorMessage)
{
	try
	{
		char* item;
		item = args[count];
		return item;
	}
	catch (exception ex)
	{
		throw errorMessage;
	}
}

void RunArguments(Tree* tree,int argCount, char* arguments[])
{
	try
	{

		bool testTriggered = false;
		bool runTriggered = false;

		for (int i = 0; i < argCount; i++)
		{
			string item = arguments[i];

			if (item == "-h" || item == "-help")
			{
				printf("-h or -help shows the help");
				printf("-s or -start followed by a file will run the test data and guess");
				printf("-t or -test followed by a file will add to the training schedule");
				printf("-r or -rms followed by a float will target the training data to that percentage");
				printf("-q or -quit or quit will close the command line");
			}
			else if(item == "-s" || item == "-start")
			{
				string file = getItem(i+1,arguments, "File is required after flag");
				i = i + 1;
				tree->Data = file;
				runTriggered = true;
			}
			else if (item == "-t" || item == "-test")
			{
				string file = getItem(i + 1, arguments, "File is required after flag");
				i = i + 1;
				tree->testFiles.push_back(file);
				testTriggered = true;
			}
			else if (item == "-r" || item == "-rms")
			{
				char* file = getItem(i + 1, arguments, "An integer is required after -rms flag");
				int iterationCount = atoi(file);
				i = i + 1;
			}
			else if (item == "-q" || item == "-quit" || item == "q" || item == "quit")
			{
				exit(0);
			}
		}

		if (testTriggered)
		{
			tree->Test();
		}

		if (runTriggered)
		{
			tree->Run();
		}
	}
	catch (string e)
	{
		printf("Error, %e", e);
	}
}

int main(int argc, char* argv[])
{
	int argCount = argc;
	char** arguments = argv;

	Tree tree = Tree();

	while (true) {
		RunArguments(&tree, argCount, arguments);
		
		char* result[256];
		char* s = new char();
		int count = 0; 
		
		while (true)
		{
			cin >> s;
			if(s == "\n")
				break;
			result[count++] = s;
		}

		argCount = count;
		arguments = result;

		exit(0);
		//Gather user Input
	}

	return 0;
}