#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;

int main()
{
    int job_id[100] = {0};// array that can hold 100 numbers for 1st column
    int arrival_time[100] = {0};// array that can hold 100 numbers for 2nd column
    int duration[100] = {0};// array that can hold 100 numbers for 3rd column
    int num = 0; // num must start at 0
    string line;
    
    ifstream file ("cat.txt");  // file containing numbers in 3 columns //replace cat.txt later
    if(file.is_open()) // checks to see if file opened
    {
        while(getline(file, line)) // reads file to end of *file*, not line
        {
            stringstream ss(line);
            ss >> job_id[num] >> arrival_time [num] >> duration[num]; // read in each column's numbers
            cout << "JobID: " <<job_id[num]<< ", ArrTime: "<< arrival_time[num] << ", Duration: " <<duration[num]<<endl;
            num++;
        }
        file.close();
    }
    return 0;
}
