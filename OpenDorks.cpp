// This is the source code of OpenDorks
// The current version is Beta.1.2
// This tool is still in it's primitive state
// New features will be added over time
// If you find any bugs or have any suggestions please contact me. Here is my website with all my contacts: https://shady-cube.github.io/Official-Shady-Cube-Website/
// Please don't abuse the source code by putting anything malicious in here or by just changing the name and redistributing it as your own

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <shellapi.h>
#include <ctime>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

string KeywordFile;
string PagetypeFile;
string PageformatFile;
string OutputFile;
int GeneratedDorks = 0;

#define CLOCKS_PER_SEC ((clock_t)1000)

void ChangeConsoleTitle()
{
    SetConsoleTitle(TEXT("OpenDorks | Beta 1.2 | Made by Shady-Cube")); // Please don't edit this
}

void ClearConsole()
{
    cout << "\033[2J\033[1;1H"; // Clears console. Idk how it works. Copied it from StackOverflow lol
}

void WaitForUserInput()
{
    system("pause"); // Uses built in windows feature to wait for user input. It also prints out a waiting for input message in the systems language
}

void WelcomeUser()
{
    SetConsoleTextAttribute(hConsole, 7); // Change text color to yellow. Other colors: stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
    cout << R"( ____ ____ ____ ____ ____ ____ ____ ____ ____ 
||O |||p |||e |||n |||D |||o |||r |||k |||s ||
||__|||__|||__|||__|||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|/__\|/__\|/__\|/__\|)";
    cout << "\n\nBeta 1.2 | Made by Shady-Cube \n";
}

void PromptForKeywordFileName() // Get name of Keyword file
{
    cout << "Please type in the name of the Text file containing your Keywords. Ex:\"Keywords.txt\"> ";
    cin >> KeywordFile;

    fstream file; // Check if file can be read
    file.open(KeywordFile, ios::in);

    if (!file)
    {
        // Print out error message
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Failed to load file.\n";
        cout << "Please try again.\n";
        SetConsoleTextAttribute(hConsole, 7);
        PromptForKeywordFileName(); // Try again
    }

    file.close();
}

void PromptForPageTypeName() // Get name of PageType file
{
    cout << "Please type in the name of the Text file containing your PageTypes. Ex:\"Pagetypes.txt\"> ";
    cin >> PagetypeFile;

    fstream file; // Check if file can be read
    file.open(PagetypeFile, ios::in);

    if (!file)
    {
        // Print out error message
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Failed to load file.\n";
        cout << "Please try again.\n";
        SetConsoleTextAttribute(hConsole, 7);
        PromptForPageTypeName(); // Try again
    }

    file.close();
}

void PromptForPageformatFileName() // Get name of PageFormat file
{
    cout << "Please type in the name of the Text file containing your PageFormats. Ex:\"Pageformats.txt\"> ";
    cin >> PageformatFile;

    fstream file; // Check if file can be read
    file.open(PageformatFile, ios::in);

    if (!file)
    {
        // Print out error message
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Failed to load file.\n";
        cout << "Please try again.\n";
        SetConsoleTextAttribute(hConsole, 7);
        PromptForPageformatFileName(); // Try again
    }

    file.close();
}

void PromptForOutputFileName() // Get name of output file
{
    cout << "Please type in the name of the Output file. Ex:\"Output.txt\"> ";
    cin >> OutputFile;

    fstream file; // Check if file can be written
    file.open(OutputFile, ios::out);

    if (!file)
    {
        // Print out error message
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Failed to write file.\n";
        cout << "Please try again.\n";
        SetConsoleTextAttribute(hConsole, 7);
        PromptForOutputFileName(); // Try again
    }

    file.close();
}

void CreateSingleThreadDorks() // Might add multithread later, too stupid for that rn
{
    // Create fstreams for all of the files
    fstream KeywordFileName;
    fstream PageTypesFileName;
    fstream PageformatFileName;
    fstream OutputFileName;

    // Open all files
    KeywordFileName.open(KeywordFile, ios::in);
    PageTypesFileName.open(PagetypeFile, ios::in);
    PageformatFileName.open(PageformatFile, ios::in);
    OutputFileName.open(OutputFile, ios::out);

    // P = phase
    string DorkP1;
    string DorkP2;
    string DorkP3;

    // Create timer
    clock_t start;
    double duration;

    // Start timer
    start = clock();

    while (!KeywordFileName.eof()) // while there are still lines to read 
    {
        KeywordFileName >> DorkP1; // write to dork phase 1
        while (!PageformatFileName.eof()) // while there are still lines to read
        {
            PageformatFileName >> DorkP2; // write to dork phase 2
            while (!PageTypesFileName.eof()) // while there are still lines to read
            {
                PageTypesFileName >> DorkP3; // write to dork phase 3

                OutputFileName << DorkP1 + DorkP2 + DorkP3 << endl; // combine all dork phases and write them to the output file
                cout << DorkP1 + DorkP2 + DorkP3 << endl; // output generated dork to console
                GeneratedDorks++; // count how many dorks have been generated
            }
            PageTypesFileName.close();
            PageTypesFileName.open(PagetypeFile, ios::in); // refresh file
        }
        PageformatFileName.close();
        PageformatFileName.open(PageformatFile, ios::in); // refresh file
    }
    
    // Print execution time to console
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC; 
    cout << "\n\nFinished in " << duration << " seconds";
}

void DorksCreatedMessage()
{
    cout << "\nA total of: " << GeneratedDorks << " Dorks have been generated!\n";
}

void AskToVisitWebsite() // Please don't edit this function
{
    // All of this should stay unchanged

    string answer;

    cout << "\nWould you like to check out my other stuff?\n";
    cout << "y/n?\n";
    cin >> answer;

    if (answer == "y")
    {
        ShellExecute(0, 0, L"https://shady-cube.github.io/Official-Shady-Cube-Website/", 0, 0, SW_SHOW);
        return;
    }
    else
    {
        if (answer == "n")
        {
            return;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Did not understand answer. Please try again.\n";
            cout << "(only use \"y\" or \"n\" to answer.\n";
            SetConsoleTextAttribute(hConsole, 7);
            AskToVisitWebsite();
        }
    }
}

void SendExitMessage()
{
    cout << "\nOpenDorks will automatically close after input\n\n";
}

int main()
{
    ChangeConsoleTitle();
    WelcomeUser();
    WaitForUserInput();
    ClearConsole();
    PromptForKeywordFileName();
    PromptForPageTypeName();
    PromptForPageformatFileName();
    PromptForOutputFileName();
    ClearConsole();
    CreateSingleThreadDorks();
    DorksCreatedMessage();
    AskToVisitWebsite();
    ClearConsole();
    SendExitMessage();
    WaitForUserInput();
}