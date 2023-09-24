//INDUSTRIAL TRAINING PROJECT
//AIRLINES MANAGEMENT AND RESERVATION SYSTEM
// 14-09-2023
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
const int MAX_FLIGHTS=10;
const int MAX_PASSENGERS=50;
struct Flight
{
  int flightnumber;
  string destination;
  string timess;
  int seatsAvailable;
  float fare;
};
struct Passenger
{
  string name;
  int passportno;
  string destinations;
  string times;
};
struct Flight flights[MAX_FLIGHTS];
struct Passenger passengers[MAX_PASSENGERS];
int flightCount=0;
int passengerCount=0;
class adflight
{
  public:
  void addflight(struct Flight flights[],int*flightCount )
  {
    if(*flightCount < MAX_FLIGHTS)
    {
      cout<<"\n--------------------------------------------------------------------";
	  cout<<"\nEnter the flight number\n";
      cin>>flights[*flightCount].flightnumber;
      cout<<"\nEnter destination:\n";
      cin>>flights[*flightCount].destination;
      cout<<"\nTimings:\n";
      cin>>flights[*flightCount].timess;
      cout<<"\nSeats Available:\n";
      cin>>flights[*flightCount].seatsAvailable;
      cout<<"\nFare\n";
      cin>>flights[*flightCount].fare;
      (*flightCount)++;
      cout<<"\nFlight added successfully\n";
    }else
    {
      cout<<"\n---------------------------------------------------------------------";
	  cout<<"\nMaximum flights reached\n";
    }
  }
};
class disflight 
{
  public:
  void displayFlight(struct Flight flights[],int flightCount)
  {
    cout<<"\n---------------------------------------------------------------";
	cout<<"\nFlight Details:\n";
    for(int i=0;i<flightCount;i++)
    {
      cout<<"\nFlight Number:"<<endl<<flights[i].flightnumber;
      cout<<"\nFlight Destination:"<<endl<<flights[i].destination;
      cout<<"\nFlight Time:"<<endl<<flights[i].timess;
      cout<<"\nSeats Available:"<<endl<<flights[i].seatsAvailable;
      cout<<"\nFlight Fare:"<<endl<<flights[i].fare;
      cout<<"\n------------------------------------------------------------------";
    }
  }
};
class searchflights
{
  public:
  void searchbydestination(struct Flight flights[],int flightCount,const string& searchDestination)
  {
    cout<<"\nFlights to:"<<searchDestination;
    for(int i=0;i<flightCount;i++)
    {
      if(flights[i].destination==searchDestination)
      {
         cout<<"\nFlight Number:"<<endl<<flights[i].flightnumber;
         cout<<"\nFlight Time:"<<endl<<flights[i].timess;
         cout<<"\nSeats Available:"<<endl<<flights[i].seatsAvailable;
         cout<<"\nFare:"<<endl<<flights[i].fare;
         cout<<"\n------------------------------------------------------------------";
      }
    }
  }
};
class makereservationflights
{
  public:
  void makeReservation(struct Flight flights[], struct Passenger passengers[], int* passengerCount)
{
    cout<<"\n--------------------------------------------------------------------";
    cout<<"\nDestination:\n";
    cin>>passengers[*passengerCount].destinations;
    cout<<"\nTimings:\n";
    cin>>passengers[*passengerCount].times;
    bool flightFound = false;
    for(int i=0;i<flightCount;i++)
    {
        if(flights[i].destination==passengers[*passengerCount].destinations &&
            flights[i].timess==passengers[*passengerCount].times)
        {
            if(flights[i].seatsAvailable>0)
            {
                cout<<"\nEnter the name of the Passenger\n";
                cin>>passengers[*passengerCount].name;
                cout<<"\nEnter Passport Number:\n";
                cin>>passengers[*passengerCount].passportno;
                (*passengerCount)++;
                flights[i].seatsAvailable--;  
                cout << "\nReservation is Successfully\n ";
            }
            else
            {
                cout << "\n--------------------------------------------------------------";
                cout << "\nNo seats available for this flight\n";
            }
            flightFound = true;
            break;
        }
    }
    if (!flightFound)
    {
        cout << "\n---------------------------------------------------------------------";
        cout << "\nNo flights are available for your required destination\n";
    }
}
};
class disPassenger
{
  public:
  void displayReservation(struct Passenger passengers[],int passengerCount)
  {
    cout<<"\n--------------------------------------------------------------";
	cout<<"\nPassenger Details:\n";
	cout<<left<<setw(15)<<"Serial No"<<setw(20)<<"Passenger Name"<<setw(20)<<"Passport No."<<setw(20)<<"Destination"<<setw(10)<<"Timing"<<endl;
    for(int i=0;i<passengerCount;i++)
    {
      cout<<left<<setw(10)<<i+1<<setw(30)<<passengers[i].name<<setw(20)<<passengers[i].passportno<<setw(20)<<passengers[i].destinations<<setw(10)<<passengers[i].times<<endl;
    }
  }
};
int  main()
{
  adflight ob1;
  disflight ob2;
  searchflights ob3,ob6;
  makereservationflights ob4;
  disPassenger ob5;
  int a,choice,choice1;
  string password;
  const char *password1="****";
  do
  {
    cout<<"\n\n\t\t****************************************************************************"<<endl;
    cout<<right<<setw(65)<<" Welcome to XYZ Airline";
    cout<<"\n\t\t****************************************************************************";
    cout<<"\nLogin as:\n";
    cout<<"\nCoustomer: press 1\n";
    cout<<"\nStaff member: press 2\n";
    cout<<"\nIf you want to exit it: press 3\n";
    cin>>a;
    cout<<"\nWelcome\n";
    switch(a)
    {
      case 1:
      {
        do
        {
          cout<<"\n\n\t\tWelcome to Airline Reservation System:\n\n";
          cout<<"\n1.Display Available Flights by Destination\n";
          cout<<"\n2.Make Reservation\n";
          cout<<"\n3.Exit\n";
          cout<<"\n------------------------------------------------------------------";
          cout<<"\nEnter your choice:";
          cin>>choice;
          switch(choice)
          {              
            case 1:
            {
              cout<<"\nDisplay Available Flights by Destination\n";
              string searchdest;
              cin>>searchdest;
              ob6.searchbydestination(flights,flightCount,searchdest);
              break;
            }
            case 2:
            {
              cout<<"\nMake Reservation\n";
             ob4.makeReservation(flights,passengers,&passengerCount);
             cout<<"\n--------------------------------------------------------------";
              break;
            }
            case 3:
            {
             cout<<"\nExit:\n";
             cout<<"\n-----------------------------------------------------------------";
             break;
            }
            default: cout<<"\nInvalid choice \n ";
          }
        } while(choice!=3);
      }
     break;
     case 2:
      {
        cout<<"\n---------------------------------------------------------------------";
		cout<<"\nEnter the password:";
        cin>>password;
        if(password==password1)
        {
         do
          { 
            cout<<"\n\n\t\t  Airline Management System\n\n";
            cout<<"PRESS:";
            cout<<"\n1.Add Flights\n";
            cout<<"\n2.Display Flights\n";
            cout<<"\n3.Search Flights by Destination\n";
            cout<<"\n4.Display the Reservation\n";
            cout<<"\n5.Logout\n";
            cout<<"\n------------------------------------------------------------------------";
            cout<<"\nEnter your choice:";
            cin>>choice1;
            switch(choice1)
            {
              case 1:
              {
                cout<<"\nAdd Flights\n";
                ob1.addflight(flights,&flightCount);
                cout<<"\n-------------------------------------------------------------------";
                break;
              }
              case 2:
              { 
                cout<<"\nDisplay\n";
                ob2.displayFlight(flights,flightCount);
                cout<<"\n------------------------------------------------------------------";
                break;
              }
              case 3:
              {
                cout<<"\nEnter the Destination to search:";
                string searchdest;
                cin>>searchdest;
                ob3.searchbydestination(flights,flightCount,searchdest);
                break;
              }
              case 4: 
              { 
                cout<<"Display the Reservations:";
                ob5.displayReservation(passengers,passengerCount);
                cout<<"\n-------------------------------------------------------------------";
                break;
              }
              case 5:
              {
                cout<<"\nLogout\n";
                cout<<"\n--------------------------------------------------------------";
                break;
              }
              default:cout<<"\nInvalid";
              cout<<"\n-----------------------------------------------------------";
              break;
            }
          } while(choice1!=5);
        }
        else
        {
          cout<<"\nIncorrect Password";
        }
      }
      break;
    }  
  } while (a!=3);
  cout<<"\n--------------------------------------------------------\n";
  cout<<"\nThank you for visiting\n ";
  return 0;
 }
 
