#include "stdafx.h"

ofstream outputFile;

Timer* timer;

std::vector<Function>activeFunctions;

bool allowOutput;

#define BEGIN 0
#define END 1

bool openDebugOutputFile()
{
	outputFile.open("DebugOutput\debugOutput.txt",ios::trunc);

	if (!outputFile.is_open())
		return false;

	outputFile << "starting debug output\n";

	timer = new Timer("debugOutputTimer");

	timer->Init();

	activeFunctions.clear();
	
	allowOutput = true;

	return true;
}

void closeDebugOutputFile()
{
	outputFile << "functions left in buffer ";
	outputFile << activeFunctions.size();
	outputFile << "\n";

	activeFunctions.clear();

	outputFile << "ending debug output\n";

	if (outputFile.is_open())
		outputFile.close();
}

void enableDebugOutput()
{
	outputFile << "enabling output\n";
	allowOutput = true;
}

void disableDebugOutput()
{
	outputFile << "disabling output\n";
	allowOutput = false;
}

void debugPrint(char* output)
{
	if(!allowOutput)
		return;	if(outputFile.is_open())
	{
		for (int j = activeFunctions.size(); j >= 0; --j)
			outputFile << "\t";
		outputFile << output;
		outputFile << "\n";
	}
}

void debugPrint(char* className, char* functionName)
{
	if(!allowOutput)
		return;
	if(outputFile.is_open())
	{
		for (int j = activeFunctions.size(); j >= 0; --j)
			outputFile << "\t";
		outputFile << className;
		outputFile << "::";
		outputFile << functionName;
		outputFile << "\n";
	}
}

void debugPrint(char* className, char* objectName, char* functionName)
{
	if(!allowOutput)
		return;
	if(outputFile.is_open())
	{
		for (int j = activeFunctions.size(); j >= 0; --j)
			outputFile << "\t";
		outputFile << className;
		outputFile << "::";
		outputFile << objectName;
		outputFile << "::";
		outputFile << functionName;
		outputFile << "\n";
	}
}

void debugPrint(char* className, char* functionName, int beginEnd)
{
	if(outputFile.is_open())
	{
		if (beginEnd == BEGIN)
		{
			if(allowOutput)
			{
				for (int j = activeFunctions.size(); j >= 0; --j)
					outputFile << "\t";
				outputFile << className;
				outputFile << "::";
				outputFile << functionName;
				outputFile << " started\n";
			}
			Function f;
			f.className = className;
			f.functionName = functionName;
			f.startTime = timer->GetTime();
			f.objectType = -1;
			activeFunctions.push_back(f);
		}
		else
		{
			for (int i = activeFunctions.size()-1; i >= 0; --i)
			{
				if (activeFunctions.at(i).className == className)
					if (activeFunctions.at(i).functionName == functionName)
					{
						if(allowOutput)
						{
							for (int j = activeFunctions.size()-1; j >= 0; --j)
								outputFile << "\t";
							outputFile << className;
							outputFile << "::";
							outputFile << functionName;
							outputFile << " ended. time elapsed: ";
							outputFile << (timer->GetTime() - activeFunctions.at(i).startTime)/1000;
							outputFile << "\n";
						}
						activeFunctions.erase(activeFunctions.begin() + i);
						return;
					}
			}
		}
	}
}

void debugPrint(char* className, char* objectName, char* functionName, int beginEnd)
{
	if(outputFile.is_open())
	{
		if (beginEnd == BEGIN)
		{
			if(allowOutput)
			{
				for (int j = activeFunctions.size(); j >= 0; --j)
					outputFile << "\t";
				outputFile << className;
				outputFile << "::";
				outputFile << objectName;
				outputFile << "::";
				outputFile << functionName;
				outputFile << " started\n";
			}

			Function f;
			f.className = className;
			f.objectName = objectName;
			f.functionName = functionName;
			f.startTime = timer->GetTime();
			f.objectType = -1;
			activeFunctions.push_back(f);
		}
		else
		{
			for (int i = activeFunctions.size()-1; i >= 0; --i)
			{
				if (activeFunctions.at(i).className == className)
					if (activeFunctions.at(i).objectName == objectName)
						if (activeFunctions.at(i).functionName == functionName)
						{
							if(allowOutput)
							{
								for (int j = activeFunctions.size()-1; j >= 0; --j)
									outputFile << "\t";
								outputFile << className;
								outputFile << "::";
								outputFile << objectName;
								outputFile << "::";
								outputFile << functionName;
								outputFile << " ended. time elapsed: ";
								outputFile << (timer->GetTime() - activeFunctions.at(i).startTime)/1000;
								outputFile << "\n";
							}
							activeFunctions.erase(activeFunctions.begin() + i);
							return;
						}
			}
		}
	}
}

void debugPrint(char* className, char* functionName, int objectType, int beginEnd)
{
	if(outputFile.is_open())
	{
		if (beginEnd == BEGIN)
		{
			if(allowOutput)
			{
				for (int j = activeFunctions.size(); j >= 0; --j)
					outputFile << "\t";
				outputFile << className;
				outputFile << "::";
				outputFile << functionName;
				outputFile << ": ";
				outputFile << objectType;
				outputFile << " started\n";
			}

			Function f;
			f.className = className;
			f.functionName = functionName;
			f.startTime = timer->GetTime();
			f.objectType = objectType;
			activeFunctions.push_back(f);
		}
		else
		{
			for (int i = activeFunctions.size()-1; i >= 0; --i)
			{
				if (activeFunctions.at(i).className == className)
				{
					if (activeFunctions.at(i).functionName == functionName)
					{
						if (activeFunctions.at(i).objectType == objectType)
						{
							if(allowOutput)
							{
								for (int j = activeFunctions.size()-1; j >= 0; --j)
									outputFile << "\t";
								outputFile << className;
								outputFile << "::";
								outputFile << functionName;
								outputFile << ": ";
								outputFile << objectType;
								outputFile << " ended. time elapsed: ";
								outputFile << (timer->GetTime() - activeFunctions.at(i).startTime)/1000;
								outputFile << "\n";
							}
							activeFunctions.erase(activeFunctions.begin() + i);
							return;
						}
					}
				}
			}
		}
	}
}


void debugPrint(char* className, char* objectName, char* functionName, int objectType, int beginEnd)
{
	if(outputFile.is_open())
	{
		if (beginEnd == BEGIN)
		{
			if(allowOutput)
			{
				for (int j = activeFunctions.size(); j >= 0; --j)
					outputFile << "\t";
				outputFile << className;
				outputFile << "::";
				outputFile << objectName;
				outputFile << "::";
				outputFile << functionName;
				outputFile << ": ";
				outputFile << objectType;
				outputFile << " started\n";
			}

			Function f;
			f.className = className;
			f.objectName = objectName;
			f.functionName = functionName;
			f.startTime = timer->GetTime();
			f.objectType = objectType;
			activeFunctions.push_back(f);
		}
		else
		{
			for (int i = activeFunctions.size()-1; i >= 0; --i)
			{
				if (activeFunctions.at(i).className == className)
					if (activeFunctions.at(i).objectName == objectName)
						if (activeFunctions.at(i).functionName == functionName)
							if (activeFunctions.at(i).objectType == objectType)
							{
								if(allowOutput)
								{
									for (int j = activeFunctions.size()-1; j >= 0; --j)
										outputFile << "\t";
									outputFile << className;
									outputFile << "::";
									outputFile << objectName;
									outputFile << "::";
									outputFile << functionName;
									outputFile << ": ";
									outputFile << objectType;
									outputFile << " ended. time elapsed: ";
									outputFile << (timer->GetTime() - activeFunctions.at(i).startTime)/1000;
									outputFile << "\n";
								}
								activeFunctions.erase(activeFunctions.begin() + i);
								return;
							}
			}
		}
	}
}
