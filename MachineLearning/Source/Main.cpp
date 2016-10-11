//-h or -help or ? should return help page
//-s or -start {filename} should open the file
//-t or -test {Filename, Items to test with} the training data that should be opened
//-o or -outcome {Filename, Results that should be expected} the results from the training data
//-r or -rms {frequency integer} should show the RMS Error on iteration
//-e or -error {Percent} should be the percentage inaccuracy
//-q or -quit or q or quit should quit

//App should remember state so cycles can be operated again

#include "Tree.h"

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
		bool hasTest = false;
		bool hasTestResults = false;

		bool testTriggered = false;
		bool runTriggered = false;

		for (int i = 0; i < argCount; i++)
		{
			string item = arguments[i];

			if (item == "-h" || item == "-help")
			{
				printf("Help initiated");
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
				tree->testData = file;
				testTriggered = true;
				hasTest = true;
			}
			else if (item == "-o" || item == "-outcome")
			{
				string file = getItem(i + 1, arguments, "File is required after flag");
				i = i + 1;
				tree->testResults = file;
				hasTestResults = true;

			}
			else if (item == "-r" || item == "-rms")
			{
				char* file = getItem(i + 1, arguments, "An integer is required after -rms flag");
				int iterationCount = atoi(file);
				i = i + 1;
			}
			else if (item == "-e" || item == "-error")
			{
				char* file = getItem(i+1, arguments, "A floating point is required after -error flag");
				float error = strtof(file, NULL);
				i = i + 1;
			}
			else if (item == "-q" || item == "-quit" || item == "q" || item == "quit")
			{
				exit(0);
			}
		}

		if (hasTest != hasTestResults)
		{
			throw "Test data needs to be accompanied by result data";
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

		exit(0);
		//Gather user Input
	}

	return 0;
}