// Decode a Message.cpp : This file contains the 'main' function. Program execution begins and ends there.
// test input 18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;

void Capital(int temp, int &state);
void LowerCase(int temp, int &state);
void Punctuation(int temp, int &state);


int main()
{
    string dataIn, s1;    
    int iter = 0, tempInt = 0, state = 1;
    vector<int> tempVec;
    char tempChar = 'null';
    
    cout << "Please enter a series of numbers, each followed by a comma: " << endl;
    getline(cin, dataIn);

    while (!dataIn.empty())
    {        
        s1 = dataIn.substr(0, dataIn.find(","));
        
        if (dataIn.find(",") == string::npos )   //want to test for condition where we do not find the next char after the comma, or fail to find the comma itself, i.e. - end of line
        {
            dataIn.erase(0, string::npos);
        }
        else
        {
            dataIn.erase(0, dataIn.find(",") + 1);
        }
       
        
        

        for (size_t i = 0; i < s1.size(); ++i)
        {
            tempVec.push_back(s1[i] - '0');
            iter = i;
        }

        for (size_t i = 0; i < tempVec.size(); i++)
        {
            tempInt += (tempVec[i] * pow(10, iter));
            iter--;
        }
                
        switch (state)
        {
             
        case 1: 
        {
            Capital(tempInt, state);
            break;
        }
        case 2: 
        {
            LowerCase(tempInt, state);
            break;
        }
        case 3: 
        {
            Punctuation(tempInt, state);
            break;
        }

        }
        
        tempInt = 0;
        s1 = "";
        tempVec.clear();       

    }
          
}

void Capital(int tempInt, int &state)
{
    char tempChar = 'null';

    if (tempInt % 27 != 0)
    {
        tempChar = tempInt % 27 + 64;
        cout << tempChar;
    }
    else if (tempInt % 27 == 0)
    {
        state = 2;       
    }
    
}

void LowerCase(int tempInt, int &state)
{
    char tempChar = 'null';

    if (tempInt % 27 != 0)
    {
        tempChar = tempInt % 27 + 96;
        cout << tempChar;
    }
    else if (tempInt % 27 == 0)
    {
        state = 3;
    }
  
}

void Punctuation(int tempInt, int &state)
{
    char tempChar = 'null';

    if (tempInt % 9 != 0)
    {
        int punctuationResult = tempInt % 9;

        switch (punctuationResult)
        {
        
        case 1:
        {
            cout << '!';
            break;
        }
        case 2:
        {
            cout << '?';
            break;
        }
        case 3:
        {
            cout << ',';
            break;
        }
        case 4:
        {
            cout << '.';
            break;
        }
        case 5:
        {
            cout << ' ';
            break;
        }
        case 6:
        {
            cout << ';';
            break;
        }
        case 7:
        {
            cout << '"';
            break;
        }
        case 8:
        {
            cout << '\'';
            break;
        }

        }
    }
    else if (tempInt % 9 == 0)
    {
        state = 1;
    }
}