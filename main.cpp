#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define ll long long
#define yes cout<<"yes";
#define YES cout <<"YES\n";
#define no cout <<"no";
#define NO cout << "NO\n";
#define Fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;

int summation_from_X_to_Y (int SmallerNumber, int GreaterNumber)
{
    if ( GreaterNumber == SmallerNumber)
        return GreaterNumber ;
    else
    {
        return GreaterNumber + summation_from_X_to_Y(SmallerNumber,GreaterNumber-1);
    }
}

int FastPower (int base, int power)
{
    if (power == 0 )
        return 1 ;
    int value = FastPower(base, power/2);
    if (power % 2 == 0)
    {
        return value * value;
    }
    else
    {
        return base * value * value;
    }
}

void binary_generation (int x)
{
    if (x == 0)
        return;
    else
    {
        binary_generation(x/2);
        x%=2;
        cout << x;
    }

}

ll sum_of_an_array (ll array[],ll size)
{
    ll sum = 0;
    for (int i =0; i < size ; i++)
        sum+=array[i];
    return sum;
}

const int Max_specialization = 20 ;
const int Max_queue = 5;
static int counter ;

// +1 in order to start array from 1 to be more easier in other implementaion
string name [Max_specialization+1][Max_queue+1];
int status[Max_specialization+1][Max_queue+1];
// Frequency array to check if the specialization is full or not yet
int frequency_queue[20+1];
int specialization ;
//static int i = 1;


void Add_Patient(){

    beginning:


    cout << "Enter specialization ,name and status :\n";
    cin >> specialization ;
    if (specialization<1 || specialization > 20)
    {
        cout << "Please enter a valid specialization number ( 1 - 20 )\n";
        Add_Patient();

    }

    if (frequency_queue[specialization]==5){
        cout << "Sorry , but this specialization is full !\n";
//        Add_Patient();
          goto beginning;
    }
    frequency_queue[specialization]++;
    int i = frequency_queue[specialization];

    // The upcoming 2 lines are for an issue in getline but can be solved by them
    string s = "";
    getline(cin,s);
    getline(cin , name[specialization][i]);
    stat :
    cin >> status[specialization][i] ;
    if (status[specialization][i] < 0 || status[specialization][i] > 1)
    {
        cout << "Please enter only valid status ( 0 - 1 )\n";
        goto stat;
    }
    counter++;

    cout << "Patient added succefully \n";

}

void Print_All(){

//     cout << "Name " << "  Status  " << "  Specialization  \n";

if (counter==0){
    cout << "No patients are added yet !\n";

}

    else {
            for (int i = 1 ; i < 21 ; i++){
            if (frequency_queue[i]>0){
                    cout << "There are " << frequency_queue[i] << " person(s) in specialization " << i << "\n";
                 for (int j = 1 ; j <= frequency_queue[i] ; j++){
//                        if (name[i][j]==" ")
//                          continue;
                    cout << name[i][j] << "  "<<status[i][j] << "  "  << "\n";
            }
            }
      }
    }





}

void GetNext(){

//    int specialization;
    cout << "Enter the specialization :\n";
    cin >> specialization;
     if (specialization<1 || specialization > 20)
    {
        cout << "Please enter a valid specialization number ( 1 - 20 )\n";
        GetNext();
    }
    if (frequency_queue[specialization]<1){
        cout << "Sorry there are no waitings in that specialization at the moment !\n";
    }
    else {
        cout << name[specialization][1] << " go to the DR. please\n";

//        for (int i = specialization ;i<specialization+1  ;  )
            for (int j = 1 ; j <= frequency_queue[specialization] ; j++ ){
        name[specialization][j-1] = name[specialization][j];
        status[specialization][j-1] = status[specialization][j];
//        name[1][1] =" ";

        }
        frequency_queue[specialization]--;
        counter --;
    }




}



void Run_hospital ()
{
    home :
    int choice ;
    cout << "Enter your choice :\n1- Add new patient\n2- Print all patients\n3- Get next patient\n4- Exit\n";
    cin >> choice ;
    if (choice < 1 || choice > 4 )
    {
        cout << "Sorry but this is invalid input !\n";
        goto home ;
    }
    if (choice == 1)
        Add_Patient();
    else if (choice == 2)
        Print_All();
        else if (choice == 3)
            GetNext();
        else exit(0);

}


int main ()
{
    while (true)
    Run_hospital();

    return 0 ;

}
