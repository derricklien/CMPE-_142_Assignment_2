#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int job_id[100] = {0};// array that can hold 100 numbers for 1st column
    int arrival_time[100] = {0};// array that can hold 100 numbers for 2nd column
    int duration[100] = {0};// array that can hold 100 numbers for 3rd column
    int num = 0; // num must start at 0
    int numberOFjobs = 0;
    string line;
    ifstream file ("jobs.dat");  
    
    //reading and stroing file data
    if(file.is_open()) // checks to see if file opened
    {
        while(getline(file, line)) // reads file to end of *file*, not line
        {
            stringstream ss(line);
            ss >> job_id[num] >> arrival_time [num] >> duration[num]; // read in each column's numbers
            //            cout << "JobID: " <<job_id[num]<< ", ArrTime: "<< arrival_time[num] << ", Duration: " <<duration[num]<<endl;
            num++;
        }
        file.close();
    }
    for (int i  = 0; i < 100; i++ )    //calculating the number of jobs

    {
        if (duration[i] != 0)
        {
            numberOFjobs++;
        }
    }
    
    cout << "numberOFjobs: " <<numberOFjobs<<endl;
    int temp = 0;
    int temp2 = 0;
    int temp3 = 0;
    int finish = 0;
    int responce = 0;
    int Et = 0;
    int hold =0;
    int TT = 0;
    
    //
    vector <int> StartTimeVec;
    vector <int> FinishTimeVec;
    vector <int> ElapsedTimeVec;
    vector <int> ResponceTimeVec;
    
    //////////FIFO////////////
    cout << "FIFO:" << endl << "Original Entry:" << endl;
      for (int i = 0; i <numberOFjobs; i++)
    {
        cout << "JobID: " <<job_id[i]<< ", ArrTime: "<< arrival_time[i] << ", Duration: " <<duration[i]<<endl;
    }
    
        for (int  i = 0; i<numberOFjobs; i++)
    {
        for (int j = 0; j <numberOFjobs; j++)
        {
            if (arrival_time[i] < arrival_time[j]) // arrange 1st arrival to last arrival using bubble sort
            {
                //                cout <<"Need to swap: "<< duration[i] << ">" << duration[j] <<endl;
                temp = duration[j];
                duration[j] = duration[i];
                duration[i] = temp;
                
                temp2 = arrival_time[j];
                arrival_time[j] = arrival_time[i];
                arrival_time[i] = temp2;
                
                temp3 = job_id[j];
                job_id[j] = job_id[i];
                job_id[i] = temp3;
            }
        }
    }
    
    /*
      cout << "Sorted Result:\n";
      for (int i = 0; i <numberOFjobs; i++)
      {
          cout << "JobID: " <<job_id[i]<< ", ArrTime: "<< arrival_time[i] << ", Duration: " <<duration[i]<<endl;
      }
      */
    
      cout << "FIFO: " << endl;
      for (int i = 0; i <numberOFjobs; i++)
    {
        if (i == 0)
        {
            StartTimeVec.push_back(arrival_time[0]);
            finish = arrival_time[0] + duration[0];
            FinishTimeVec.push_back(finish);
            ElapsedTimeVec.push_back(duration[0]);
            responce = StartTimeVec[0] - arrival_time[0];
            ResponceTimeVec.push_back(responce);
        }
        else
        {
            if (arrival_time[i] > FinishTimeVec[i-1])
            {
//                cout << "YEE\n";
                StartTimeVec.push_back(arrival_time[i]);
                finish = StartTimeVec[i]+ duration[i];
                FinishTimeVec.push_back(finish);
                Et = finish - arrival_time[i];
                ElapsedTimeVec.push_back(Et);
                responce = StartTimeVec[i] - arrival_time[i];
                ResponceTimeVec.push_back(responce);
            }
            else
            {
//                cout<<"NAH\n";
                StartTimeVec.push_back(FinishTimeVec[i-1]);
                finish = StartTimeVec[i] + duration[i];
                FinishTimeVec.push_back(finish);
                Et = finish - arrival_time[i];
                ElapsedTimeVec.push_back(Et);
                responce = StartTimeVec[i] - arrival_time[i];
                ResponceTimeVec.push_back(responce);
            }
            
        }
        cout << "JID: "<< job_id[i]<< " StartTime: " << StartTimeVec[i] << " FinishTime: " << FinishTimeVec[i]<< " ElapsedTime: " << ElapsedTimeVec[i] << " ResponseTime: " << ResponceTimeVec[i]<<endl;
    }
      
    StartTimeVec.clear();
    FinishTimeVec.clear();
    ElapsedTimeVec.clear();
    ResponceTimeVec.clear();
    
     cout << "Original entry\n";
    for (int i = 0; i <numberOFjobs; i++)
    {
        cout << "JobID: " <<job_id[i]<< ", ArrTime: "<< arrival_time[i] << ", Duration: " <<duration[i]<<endl;
    }
    
    cout << "BJF"<<endl;
    for (int  i = 0; i<numberOFjobs; i++)
    {
        for (int j = 0; j <numberOFjobs; j++)
        {
            if (arrival_time[i] < arrival_time[j])
            {
                //                cout <<"Need to swap: "<< duration[i] << ">" << duration[j] <<endl;
                temp = duration[j];
                duration[j] = duration[i];
                duration[i] = temp;
                
                temp2 = arrival_time[j];
                arrival_time[j] = arrival_time[i];
                arrival_time[i] = temp2;
                
                temp3 = job_id[j];
                job_id[j] = job_id[i];
                job_id[i] = temp3;
            }
            if (arrival_time[i] == arrival_time[j])
            {
                if (duration[i] > duration[j])
                {
                    //                    cout <<"Need to swap: "<< duration[i] << ">" << duration[j] <<endl;
                    temp = duration[j];
                    duration[j] = duration[i];
                    duration[i] = temp;
                    
                    temp2 = arrival_time[j];
                    arrival_time[j] = arrival_time[i];
                    arrival_time[i] = temp2;
                    
                    temp3 = job_id[j];
                    job_id[j] = job_id[i];
                    job_id[i] = temp3;
                }
            }
        }
    }
    TT = duration[0];
    for (int i = 1; i < numberOFjobs-1; i++)
    {
        for (int j = 2; j < numberOFjobs; j++)
        {
            //            cout <<"THE TT is: "<< TT<<", i is: "<<i<<", j is: "<<j<<endl; //debug
            if (TT > arrival_time[j]&& i != numberOFjobs -2)
            {
                //                cout << "HERE: "<< arrival_time[j]<<endl;
                if (duration[i] < duration[j])
                {
                    //                    cout << "Swap: "<< job_id[i] << "w/ " <<job_id[j]<<endl; //debug
                    temp = duration[j];
                    duration[j] = duration[i];
                    duration[i] = temp;
                    
                    temp = arrival_time[j];
                    arrival_time[j] = arrival_time[i];
                    arrival_time[i] = temp;
                    
                    temp = job_id[j];
                    job_id[j] = job_id[i];
                    job_id[i] = temp;
                }
            }
            else if (i == numberOFjobs -2)
            {
                if (duration[i] < duration[j] && j > i&& TT > arrival_time[i+1])
                {
                    //                    cout << "Swap: "<< job_id[i] << "w/ " <<job_id[j]<<endl; //debug
                    temp = duration[j];
                    duration[j] = duration[i];
                    duration[i] = temp;
                    
                    temp = arrival_time[j];
                    arrival_time[j] = arrival_time[i];
                    arrival_time[i] = temp;
                    
                    temp = job_id[j];
                    job_id[j] = job_id[i];
                    job_id[i] = temp;
                }
            }
        }
        TT = TT + duration[i];
    }
    cout << "After BJF entry\n";
    for (int i = 0; i <numberOFjobs; i++)
    {
        //            cout << "JobID: " <<job_id[i]<< ", ArrTime: "<< arrival_time[i] << ", Duration: " <<duration[i]<<endl;
    }
    for (int i = 0; i <numberOFjobs; i++)
    {
        //                cout << "JobID: " <<job_id[i]<< ", ArrTime: "<< arrival_time[i] << ", Duration: " <<duration[i]<<endl;
        if (i == 0)
        {
            StartTimeVec.push_back(arrival_time[0]);
            finish = arrival_time[0] + duration[0];
            FinishTimeVec.push_back(finish);
            ElapsedTimeVec.push_back(duration[0]);
            responce = StartTimeVec[0] - arrival_time[0];
            ResponceTimeVec.push_back(responce);
        }
        else
        {
            if (arrival_time[i] > FinishTimeVec[i-1])
            {
                StartTimeVec.push_back(arrival_time[i]);
                finish = StartTimeVec[i] + duration[i];
                FinishTimeVec.push_back(finish);
                Et = finish - arrival_time[i];
                ElapsedTimeVec.push_back(Et);
                responce = StartTimeVec[i] - arrival_time[i];
                ResponceTimeVec.push_back(responce);
            }
            else
            {
                StartTimeVec.push_back(FinishTimeVec[i-1]);
                finish = StartTimeVec[i] + duration[i];
                FinishTimeVec.push_back(finish);
                Et = finish - arrival_time[i];
                ElapsedTimeVec.push_back(Et);
                responce = StartTimeVec[i] - arrival_time[i];
                ResponceTimeVec.push_back(responce);
            }
        }
        cout << "JD: "<< job_id[i]<< " StartTime: " << StartTimeVec[i] << " FinishTime: " << FinishTimeVec[i]<< " ElapsedTime: " << ElapsedTimeVec[i] << " ResponceTime: " << ResponceTimeVec[i]<<endl;
    }
    StartTimeVec.clear();
    FinishTimeVec.clear();
    ElapsedTimeVec.clear();
    ResponceTimeVec.clear();
    
    /////////SJF////////////
    for (int  i = 0; i<numberOFjobs; i++)
    {
        for (int j = 0; j <numberOFjobs; j++)
        {
            if (arrival_time[i] < arrival_time[j]) // arrange 1st arrival to last arrival using bubble sort
            {
                //                cout <<"Need to swap: "<< duration[i] << ">" << duration[j] <<endl;
                temp = duration[j];
                duration[j] = duration[i];
                duration[i] = temp;
                
                temp2 = arrival_time[j];
                arrival_time[j] = arrival_time[i];
                arrival_time[i] = temp2;
                
                temp3 = job_id[j];
                job_id[j] = job_id[i];
                job_id[i] = temp3;
            }
            else if (arrival_time[i] == arrival_time[j]) // if arrival time eqaul, arrange based on job duration
            {
                if (duration[i] < duration[j])
                {
                    temp = duration[j];
                    duration[j] = duration[i];
                    duration[i] = temp;
                    
                    temp2 = arrival_time[j];
                    arrival_time[j] = arrival_time[i];
                    arrival_time[i] = temp2;
                    
                    temp3 = job_id[j];
                    job_id[j] = job_id[i];
                    job_id[i] = temp3;
                }
            }
        }
    }
    //    cout << "Result\n";
    //    for (int i = 0; i <numberOFjobs; i++)
    //    {
    //        cout << "JobID: " <<job_id[i]<< ", ArrTime: "<< arrival_time[i] << ", Duration: " <<duration[i]<<endl;
    //    }
    TT = duration[0];
    for (int i =1; i < numberOFjobs-1; i++) // might want to remove the minus 1
    {
        for (int j = 2; j < numberOFjobs; j++)
        {
            //            cout <<"THE TT is: "<< TT<<", i is: "<<i<<", j is: "<<j<<endl; //debug
            if(TT>arrival_time[j] && i != numberOFjobs -2)
            {
                //                cout<< TT << " > "<< arrival_time[j]<<endl;
                if(duration[i] > duration[j] && j > i)
                {
                    //                    cout << "Swap: "<< job_id[i] << "w/ " <<job_id[j]<<endl; //debug
                    temp = duration[j];
                    duration[j] = duration[i];
                    duration[i] = temp;
                    
                    temp = arrival_time[j];
                    arrival_time[j] = arrival_time[i];
                    arrival_time[i] = temp;
                    
                    temp = job_id[j];
                    job_id[j] = job_id[i];
                    job_id[i] = temp;
                }
            }
            if ( i == numberOFjobs - 2)
            {
                //                cout << "NEWWW TT is: "<< TT<<", i is: "<<i<<", j is: "<<j<<endl;
                if(duration[i] > duration[j] && j > i&& TT > arrival_time[i+1])
                {
                    //                    cout << "NEW SWAP: "<< job_id[i] << "w/ " <<job_id[j]<<endl; //debug
                    temp = duration[j];
                    duration[j] = duration[i];
                    duration[i] = temp;
                    
                    temp = arrival_time[j];
                    arrival_time[j] = arrival_time[i];
                    arrival_time[i] = temp;
                    
                    temp = job_id[j];
                    job_id[j] = job_id[i];
                    job_id[i] = temp;
                }
            }
        }
        TT = TT + duration[i];
    }
    
    cout << "AFTER SJF entry\n";
    for (int i = 0; i <numberOFjobs; i++)
    {
        //        cout << "JobID: " <<job_id[i]<< ", ArrTime: "<< arrival_time[i] << ", Duration: " <<duration[i]<<endl;
    }
    TT = duration[0];
    for (int i = 0; i <numberOFjobs; i++)
    {
        if (i == 0)
        {
            StartTimeVec.push_back(arrival_time[0]);
            finish = arrival_time[0] + duration[0];
            FinishTimeVec.push_back(finish);
            ElapsedTimeVec.push_back(duration[0]);
            responce = StartTimeVec[0] - arrival_time[0];
            ResponceTimeVec.push_back(responce);
        }
        else
        {
            if (arrival_time[i] > FinishTimeVec[i-1])
            {
                StartTimeVec.push_back(arrival_time[i]);
                finish = StartTimeVec[i]+ duration[i];
                FinishTimeVec.push_back(finish);
                Et = finish - arrival_time[i];
                ElapsedTimeVec.push_back(Et);
                responce = StartTimeVec[i] - arrival_time[i];
                ResponceTimeVec.push_back(responce);
            }
            else
            {
                StartTimeVec.push_back(FinishTimeVec[i-1]);
                finish = StartTimeVec[i] + duration[i];
                FinishTimeVec.push_back(finish);
                Et = finish - arrival_time[i];
                ElapsedTimeVec.push_back(Et);
                responce = StartTimeVec[i] - arrival_time[i];
                ResponceTimeVec.push_back(responce);
            }
            
        }
        cout << "JD: "<< job_id[i]<< " StartTime: " << StartTimeVec[i] << " FinishTime: " << FinishTimeVec[i]<< " ElapsedTime: " << ElapsedTimeVec[i] << " ResponceTime: " << ResponceTimeVec[i]<<endl;
    }
    int timeCount=FinishTimeVec[numberOFjobs-1];
    vector <int> RemainingTime;

    StartTimeVec.clear();
    FinishTimeVec.clear();
    ElapsedTimeVec.clear();
    ResponceTimeVec.clear();
    RemainingTime.clear();


    for (int i =0; i <numberOFjobs; i++)
    {
        StartTimeVec.push_back(0);
        FinishTimeVec.push_back(0);
        ElapsedTimeVec.push_back(0);
        ResponceTimeVec.push_back(0);
        RemainingTime.push_back(-10);
    }
    StartTimeVec.clear();
    FinishTimeVec.clear();
    ElapsedTimeVec.clear();
    ResponceTimeVec.clear();
    RemainingTime.clear();

//    cout << "STCF entry\n";
    for (int  i = 0; i<numberOFjobs; i++)
    {
        for (int j = 0; j <numberOFjobs; j++)
        {
            if (arrival_time[i] < arrival_time[j]) // arrange 1st arrival to last arrival using bubble sort
            {
                //                cout <<"Need to swap: "<< duration[i] << ">" << duration[j] <<endl;
                temp = duration[j];
                duration[j] = duration[i];
                duration[i] = temp;
                
                temp2 = arrival_time[j];
                arrival_time[j] = arrival_time[i];
                arrival_time[i] = temp2;
                
                temp3 = job_id[j];
                job_id[j] = job_id[i];
                job_id[i] = temp3;
            }
            else if (arrival_time[i] == arrival_time[j]) // if arrival time eqaul, arrange based on job duration
            {
                if (duration[i] < duration[j])
                {
                    temp = duration[j];
                    duration[j] = duration[i];
                    duration[i] = temp;
                    
                    temp2 = arrival_time[j];
                    arrival_time[j] = arrival_time[i];
                    arrival_time[i] = temp2;
                    
                    temp3 = job_id[j];
                    job_id[j] = job_id[i];
                    job_id[i] = temp3;
                }
            }
        }
    }
//    cout << "order in shortest arrival time\n";
    int remain = 0;
    for (int i = 0; i <numberOFjobs; i++)
    {
//        cout << "JobID: " <<job_id[i]<< ", ArrTime: "<< arrival_time[i] << ", Duration: " <<duration[i]<<endl;
    }
    for (int i =1; i < numberOFjobs-1; i++)
    {
        for (int j =2; j < numberOFjobs; j++)
        {
            //            cout <<"THE TT is: "<< TT<<", i is: "<<i<<", j is: "<<j<<endl; //debug
            if (duration[i] < duration[j])
            {
                //                cout <<"HERE\n";
            }
        }
    }
    for (int i =0; i <numberOFjobs; i++)
    {
        for (int j = 0; j < numberOFjobs; j++)
        {
//            cout << "i is: "<<i<<", j is: "<<j<<", RT: "<<RemainingTime[i]<<endl; //debug
            if(i==0)
            {
                StartTimeVec[i]= arrival_time[i];
                responce = StartTimeVec[i] - arrival_time[i];
                ResponceTimeVec[i]= responce;
                if(duration[i] < arrival_time[i+1])
                {
//                    cout << "ran\n";
                    FinishTimeVec[i]=duration[i];
                }
                else
                {
                    remain = duration[i] - arrival_time[i+1];
                    RemainingTime[i]=remain;
                    FinishTimeVec[i]=RemainingTime[i];
                    ElapsedTimeVec[i] =RemainingTime[i];
                }
            }
            else if(RemainingTime[j] < duration[j] && RemainingTime[j]!=-10)
            {
//                cout << "R < D "<< RemainingTime[j]<< " < "<< duration[j]<<endl;
//                cout <<"i: "<< i<<", j: "<< j<<endl;
            }
            else if(RemainingTime[j] > duration[j] )
            {
//                cout << "R > D "<< RemainingTime[j]<< " > "<< duration[j]<<endl;
            }
            else if (RemainingTime[j] == 50)
            {
//                cout << "HERERE\n";
            }
        }
        
    }
    
//    cout << "C: "<< timeCount<<endl;
    cout << "STCF Result\n";
    for (int i = 0; i <numberOFjobs; i++)
    {
        cout<< "JD: "<< job_id[i]<< " StartTime: " << StartTimeVec[i] << " FinishTime: " << FinishTimeVec[i]<< " ElapsedTime: " << ElapsedTimeVec[i] << " ResponceTime: " << ResponceTimeVec[i]<< " Remain: "<<RemainingTime[i]<<endl;
    }
    StartTimeVec.clear();
    FinishTimeVec.clear();
    ElapsedTimeVec.clear();
    ResponceTimeVec.clear();
    
    //////////Red Robin////////////
    cout << "RoundRobin " << endl << "Original Entry: " << endl;
      for (int i = 0; i <numberOFjobs; i++)
    {
        cout << "JobID: " <<job_id[i]<< ", ArrTime: "<< arrival_time[i] << ", Duration: " <<duration[i]<<endl;
    }
    
        for (int  i = 0; i<numberOFjobs; i++)
    {
        for (int j = 0; j <numberOFjobs; j++)
        {
            if (arrival_time[i] < arrival_time[j]) // arrange 1st arrival to last arrival using bubble sort
            {
                //                cout <<"Need to swap: "<< duration[i] << ">" << duration[j] <<endl;
                temp = duration[j];
                duration[j] = duration[i];
                duration[i] = temp;
                
                temp2 = arrival_time[j];
                arrival_time[j] = arrival_time[i];
                arrival_time[i] = temp2;
                
                temp3 = job_id[j];
                job_id[j] = job_id[i];
                job_id[i] = temp3;
            }
        }
    }
    
    /*  cout << "Sorted Result:\n";
      for (int i = 0; i <numberOFjobs; i++)
      {
          cout << "JobID: " <<job_id[i]<< ", ArrTime: "<< arrival_time[i] << ", Duration: " <<duration[i]<<endl;
      }
     */
   /* 
      cout << "Round Robin:" << endl;
      for (int i = 0; i <numberOFjobs; i++)
    {
        if (i == 0)
        {
            StartTimeVec.push_back(arrival_time[0]);
            finish = arrival_time[0] + duration[0];
            FinishTimeVec.push_back(finish);
            ElapsedTimeVec.push_back(duration[0]);
            responce = StartTimeVec[0] - arrival_time[0];
            ResponceTimeVec.push_back(responce);
        }
        else
        {
            if (arrival_time[i] > FinishTimeVec[i-1])
            {
//                cout << "YEE\n";
                StartTimeVec.push_back(arrival_time[i]);
                finish = StartTimeVec[i]+ duration[i];
                FinishTimeVec.push_back(finish);
                Et = finish - arrival_time[i];
                ElapsedTimeVec.push_back(Et);
                responce = StartTimeVec[i] - arrival_time[i];
                ResponceTimeVec.push_back(responce);
            }
            else
            {
//                cout<<"NAH\n";
                StartTimeVec.push_back(FinishTimeVec[i-1]);
                finish = StartTimeVec[i] + duration[i];
                FinishTimeVec.push_back(finish);
                Et = finish - arrival_time[i];
                ElapsedTimeVec.push_back(Et);
                responce = StartTimeVec[i] - arrival_time[i];
                ResponceTimeVec.push_back(responce);
            }
            
        }
        cout << "JID: "<< job_id[i]<< " StartTime: " << StartTimeVec[i] << " FinishTime: " << FinishTimeVec[i]<< " ElapsedTime: " << ElapsedTimeVec[i] << " ResponseTime: " << ResponceTimeVec[i]<<endl;
    }
 */   
    StartTimeVec.clear();
    FinishTimeVec.clear();
    ElapsedTimeVec.clear();
    ResponceTimeVec.clear();
    return 0;
}



