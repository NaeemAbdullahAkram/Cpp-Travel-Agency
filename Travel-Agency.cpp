#include<iostream>
#include<fstream>
#include<iomanip>  //for float precision points
#include<windows.h> //for sleep function 
#include<string>

using namespace std;
void menue(int a=0);


class admin 
{
   private:
        string usernameadmin;
        string password;
    public:
        admin()
        {
            usernameadmin = "amen";
            password = "123";

        }
        friend class manageMenue;
};

class manageMenue
{

   private:
        admin a;


        string username; // hide admin name

    public:
      
        manageMenue()  // constructor
        {
            system("title Happy Trails Tours");
            system("mode con: cols=142 lines=34"); // setting the size of the app window
            system("color 0A");                    // change color
            system("echo \a");                     // sound

            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t Press 1 if you are an Admin: \n\t Press 2 if you are a Customer: ";
           
            int c;
            cin>>c;
          system("cls");


            if(c==1)
       {
           cout << "\n\n\n\n\n\n\n\n\n\n\n\t ADMIN LOGIN\n\t \n";
           cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t Username: ";
           cin >> a.usernameadmin;

           cout << "\n\t Password: ";
           cin >> a.password;

           if (a.usernameadmin == "amen" && a.password == "123")
           {
               system("cls");
               menue(0);
     } 
     else
     {
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t Invalid username or password"<<endl;
       Sleep(999);
       system("cls");
       manageMenue();}

        
       
       }


        else if (c==2)
        {
               cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t Enter Your Name to Continue as as a Customer : ";
        cin >> username;
         system("cls");
       menue(1);
        }
        else
        {
            cout<<"Invalid choice"<<endl;
            system("cls");
            manageMenue();
    }
    }
    ~manageMenue()
    {
        
    }

};



class customers{
public:
 string name,gender, address;
 int age, mobileNo;
 static int cutomerId;
 
 //to print all values using file handlingin showDetails() function
 customers()   //constructor
 {
   name="";
   gender="";
    address="";
    age=0;
    mobileNo=0;
    getCustomerId();


 }
 static void getCustomerId()
 {
      cutomerId++;
 }
 void getDetails()
 { 
     
     ofstream out("old-customer.tx",ios::app);
     
         
        customers::cutomerId++;
         cout << "Enter Cutomer name: ";
         cin >> name;
         cout << "Enter address: ";
         cin >> address;
         cout << "Enter Age:  ";
         cin >> age;
         cout << "Enter Mobile No: ";
         cin >> mobileNo;
         cout << "Enter gender: ";
         cin >> gender;
     
     out << endl
         << "Cutomer ID:" << cutomerId << endl
         << "Name:" << name << endl
         << "Age: " << age << endl
         << "Mobile Number: " << mobileNo << endl
         << "Address: " << address << endl
         << "Gender: " << gender << endl;
     out.close();
     cout << "\nSAVED SUCCESSFULLY\n NOTE:we saved your details for future purpose\n"
          << endl;



}
void ShowDetails()
{
    ifstream in("old-customer.tx");
    if (!in)
    {
        cout << "File not found" << endl;
        return; // Exit the function since the file couldn't be opened
    }
    else
    {
        char allInfo[1000]; // Declaration of allInfo variable
        while (in.getline(allInfo, 999))
        {
            cout << allInfo << endl;
        }
        in.close();
    }
}

};
int customers::cutomerId = 0;











class cab{

 public:
 int cabChoice;
 int kilometers;
 static float price;
 float lastcabcost;
 string cabbok;



    cab() //constructor
    {
        cabChoice=0;
        kilometers=0;
        price=0;
        lastcabcost=0;
        cabbok="";
    }
 void cabDetails()
 {
    cout<<"1. Micro"<<endl;
    cout<<"2. Mini"<<endl;
    cout<<"3. Prime"<<endl;
    cout<<"Enter your choice: ";
    cin>>cabChoice;
    cout<<"Enter the distance in kilometers: ";
    cin>>kilometers;
    int hirecab;


    if(cabChoice==1)
    {
        price=kilometers*10;
        cout<<"Your total fare is: "<<price<<endl;
        cout<<"Your total fare is: "<<price<<endl;
        cout << "Press 1 to hire the cab\n";
         cout << "Press 2 to select another cab\n";
         cin >> hirecab;

         system("cls");
         if(hirecab == 1)
         {  lastcabcost=price;
             cout << "Your cab is booked\n";
             cout << "Your cab will arrive soon\n";
             cout << "Thank you for using our service\n";
             cout << "Goto Menue and take the recipt;"<<endl;
             cabbok="Micro";

         }
         else if(hirecab == 2)
         {
             cabDetails();
         }
         else
         {
             cout << "Invalid choice, Redurecting to previous Menue.\n Please wait!" << endl;
             Sleep(999);
             system("cls");
             cabDetails();  //Calling the cab funtion again to make user select a valid option
         }
    }


    else if(cabChoice==2)
    {
        price=kilometers*15;
        cout<<"Your total fare is: "<<price<<endl;
        cout << "Press 1 to hire the cab\n";
         cout << "Press 2 to select another cab\n";
         cin >> hirecab;

         system("cls");
         if(hirecab == 1)
         {  lastcabcost=price;
             cout << "Your cab is booked\n";
             cout << "Your cab will arrive soon\n";
             cout << "Thank you for using our service\n";
             cout << "Goto Menue and take the recipt;"<<endl;
                  cabbok="Mini";
         }
         else if(hirecab == 2)
         {
             cabDetails();
         }
         else
         {
             cout << "Invalid choice, Redurecting to previous Menue.\n Please wait!" << endl;
             Sleep(999);
             system("cls");
             cabDetails();  //Calling the cab funtion again to make user select a valid option
         }
    }


    else if(cabChoice==3)
    {
        price=kilometers*20;
        cout<<"Your total fare is: "<<price<<endl;
        cout<<"Your total fare is: "<<price<<endl;
        cout << "Press 1 to hire the cab\n";
         cout << "Press 2 to select another cab\n";
         cin >> hirecab;

         system("cls");
         if(hirecab == 1)
         {  lastcabcost=price;
             cout << "Your cab is booked\n";
             cout << "Your cab will arrive soon\n";
             cout << "Thank you for using our service\n";
             cout << "Goto Menue and take the recipt;"<<endl;
             cabbok="Prime";
         }
         else if(hirecab == 2)
         {
             cabDetails();
         }
         else
         {
             cout << "Invalid choice, Redurecting to previous Menue.\n Please wait!" << endl;
             Sleep(999);
             system("cls");
             cabDetails();  //Calling the cab funtion again to make user select a valid option
         }
    }
    else
    {
         cout << "Invalid choice, Redurecting to previous Menue.\n Please wait!" << endl;
             Sleep(999);
             system("cls");
             cabDetails();
           //  menu();
    }
   
   
    cout<<"\nPress 1 to Redirect to Main Menu\n";
    cin>>hirecab;
    system("cls");


    if(hirecab==1)
    {
         menue();
         }
    else
    {
        cout<<"Invalid Choice, Redirecting to Main Menu\n";
        Sleep(999);
        system("cls");
       menue();
    }
}

};
float cab::price;







class bookings 
{
    
   public:
       customers *c;
      
         bookings()
         {
              c = new customers();
         }
         ~bookings()
         {
             delete c;
         }
       virtual void displayOptions();
       virtual void bookActivity(){};
       void displayAllBookings(); // using association reation ship because bookings has a customer ponter to access all the bookings made byt that customer
};  







class hotels : public bookings               //classs inhereting from bookings class 

{
   

public:
    int choiceHotel;
    int hotelPackage;
    static float hotelPrice;
    string hotelName;

hotels():bookings()
{
    choiceHotel=0;
    hotelPackage=0;
    hotelPrice=0;
    hotelName="";

}

    void bookActivity()
    {

        if (choiceHotel == 1)
        {
            cout<<"-----------Welcome to hotel Taj-----------"<<endl;
        cout << "Hotel Booking Options:\n";
        cout << "1. Standard Pack\n";
        cout<<"\t basic facilitiesyou need just for: Rs 5000.00\n";
        cout << "2. Premium Pack\n";
        cout << "\tEnjoy Premium: : Rs 10000.00\n"; 
        cout << "3. Luxury Pack\n";
        cout<<"\tLive a luxury at our hotel: Rs 15000.00\n";

        cout << "Press another key to back or\n Enter Package number you want to book.\n";
        cin >> hotelPackage;

        if(hotelPackage==1)
        {
            hotelPrice=5000.00;
            cout<<"You have successfully booked Standard Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;
               hotelName="Hotel Taj";
        }
        else if(hotelPackage==2)
        {
             hotelPrice=10000.00;
            cout<<"You have successfully booked Premium Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;
                hotelName="Hotel Taj";
        }
        else if(hotelPackage==3)
        {
            hotelPrice=15000.00;
           
            cout<<"You have successfully booked SLuxury Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;
               hotelName="Hotel Taj";
        }
        else
        {
            cout<<"Invalid choice, Redurecting to previous Menue.\n Please wait!"<<endl;
            Sleep(1100);
            system("cls");
            displayOptions(); // Calling the  funtion again to make user select a valid option
        }
        int gotomenue;
        cout<<"Press  1 to redirect main menu :\n";
        cin>>gotomenue;
        if(gotomenue==1)
        {
            system("cls");
            menue();
        }
        else
        {
            menue();
        }
 

        }
        

if(choiceHotel==2)  {
            

             cout<<"-----------Welcome to hotel Oberoi-----------"<<endl;
        cout << "Hotel Booking Options:\n";
        cout << "1. Standard Pack\n";
        cout<<"\t basic facilitiesyou need just for: Rs 5000.00\n";
        cout << "2. Premium Pack\n";
        cout << "\tEnjoy Premium: : Rs 10000.00\n"; 
        cout << "3. Luxury Pack\n";
        cout<<"\tLive a luxury at our hotel: Rs 15000.00\n";

        cout << "Press another key to back or\n Enter Package number you want to book.\n";
        cin >> hotelPackage;

        if(hotelPackage==1)
        {   hotelName="Hotel Oberio";
            hotelPrice=4000.00;
            cout<<"You have successfully booked Standard Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;

        }
        else if(hotelPackage==2)
        {     hotelName="Hotel Oberio";
             hotelPrice=9000.00;
            cout<<"You have successfully booked Premium Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;
            
        }
        else if(hotelPackage==3)
        {     hotelName="Hotel Oberio";
            hotelPrice=12000.00;
           
            cout<<"You have successfully booked SLuxury Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;
            
        }
        else
        {    
            cout<<"Invalid choice, Redurecting to previous Menue.\n Please wait!"<<endl;
            Sleep(1100);
            system("cls");
            displayOptions(); // Calling the  funtion again to make user select a valid option
        }
        int gotomenue;
        cout<<"Press  1 to redirect main menu :\n";
        cin>>gotomenue;
        if(gotomenue==1)
        {
            system("cls");
           menue();
        }
        else
        {
            menue();
        }
 
        }

        if(choiceHotel==3)  {
            
 cout<<"-----------Welcome to hotel Leela-----------"<<endl;
        cout << "Hotel Booking Options:\n";
        cout << "1. Standard Pack\n";
        cout<<"\t basic facilitiesyou need just for: Rs 5000.00\n";
        cout << "2. Premium Pack\n";
        cout << "\tEnjoy Premium: : Rs 10000.00\n"; 
        cout << "3. Luxury Pack\n";
        cout<<"\tLive a luxury at our hotel: Rs 15000.00\n";

        cout << "Press another key to back or\n Enter Package number you want to book.\n";
        cin >> hotelPackage;

        if(hotelPackage==1)
        {hotelName="Hotel Leela ";
            hotelPrice=6000.00;
            cout<<"You have successfully booked Standard Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;

        }
        else if(hotelPackage==2)
        {    hotelName="Hotel Leela ";
             hotelPrice=12000.00;
            cout<<"You have successfully booked Premium Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;
            
        }
        else if(hotelPackage==3)
        {   hotelName="Hotel Leela ";
            hotelPrice=17000.00;
           
            cout<<"You have successfully booked Luxury Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;
            
        }
        else
        {
            cout<<"Invalid choice, Redurecting to previous Menue.\n Please wait!"<<endl;
            Sleep(1100);
            system("cls");
            displayOptions(); // Calling the  funtion again to make user select a valid option
        }
        int gotomenue;
        cout<<"Press  1 to redirect main menu :\n";
        cin>>gotomenue;
        if(gotomenue==1)
        {
            system("cls");
            menue();
        }
        else
        {
           menue();
        }
 
             
    }

    if(choiceHotel==4)  {
         cout<<"-----------Welcome to hotel Trident-----------"<<endl;
        cout << "Hotel Booking Options:\n";
        cout << "1. Standard Pack\n";
        cout<<"\t basic facilitiesyou need just for: Rs 5000.00\n";
        cout << "2. Premium Pack\n";
        cout << "\tEnjoy Premium: : Rs 10000.00\n"; 
        cout << "3. Luxury Pack\n";
        cout<<"\tLive a luxury at our hotel: Rs 15000.00\n";

        cout << "Press another key to back or\n Enter Package number you want to book.\n";
        cin >> hotelPackage;

        if(hotelPackage==1)
        {  hotelName="Hotel Trident ";
            hotelPrice=6500.00;
            cout<<"You have successfully booked Standard Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;

        }
        else if(hotelPackage==2)
        {hotelName="Hotel Trident ";
             hotelPrice=11000.00;
            cout<<"You have successfully booked Premium Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;
            
        }
        else if(hotelPackage==3)
        {hotelName="Hotel Trident ";
            hotelPrice=14000.00;
           
            cout<<"You have successfully booked SLuxury Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;
            
        }
        else
        {
            cout<<"Invalid choice, Redurecting to previous Menue.\n Please wait!"<<endl;
            Sleep(1100);
            system("cls");
            displayOptions(); // Calling the  funtion again to make user select a valid option
        }
        int gotomenue;
        cout<<"Press  1 to redirect main menu :\n";
        cin>>gotomenue;
        if(gotomenue==1)
        {
            system("cls");
            menue();
        }
        else
        {
            menue();
        }
 

}

if(choiceHotel==5)
{
     cout<<"-----------Welcome to hotel ITC -----------"<<endl;
        cout << "Hotel Booking Options:\n";
        cout << "1. Standard Pack\n";
        cout<<"\t basic facilitiesyou need just for: Rs 5000.00\n";
        cout << "2. Premium Pack\n";
        cout << "\tEnjoy Premium: : Rs 10000.00\n"; 
        cout << "3. Luxury Pack\n";
        cout<<"\tLive a luxury at our hotel: Rs 15000.00\n";

        cout << "Press another key to back or\n Enter Package number you want to book.\n";
        cin >> hotelPackage;

        if(hotelPackage==1)
        {hotelName="Hotel   ITC ";
            hotelPrice=5000.00;
            cout<<"You have successfully booked Standard Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;

        }
        else if(hotelPackage==2)
        {
             hotelName="Hotel   ITC ";
             hotelPrice=10000.00;
            cout<<"You have successfully booked Premium Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;
            
        }
        else if(hotelPackage==3)
        {  hotelName="Hotel   ITC ";
            hotelPrice=15000.00;
           
            cout<<"You have successfully booked SLuxury Pack"<<endl;
            cout<<"Goto Menue and take the recipt;"<<endl;
            
        }
        else
        {
            cout<<"Invalid choice, Redurecting to previous Menue.\n Please wait!"<<endl;
            Sleep(1100);
            system("cls");
            displayOptions(); // Calling the  funtion again to make user select a valid option
        }
        int gotomenue;
        cout<<"Press  1 to redirect main menu :\n";
        cin>>gotomenue;
        if(gotomenue==1)
        {
            system("cls");
           menue();
        }
        else
        {
            menue();
        }
 
}


 
}
void displayOptions() // Just gives the main menue for the hoteql booking
        {   
           string hotelno[]={"\n1. Hotel Taj\n","2. Hotel Oberoi\n","3. Hotel Leela\n","4. Hotel Trident\n","5. Hotel ITC\n"};
           for (int a = 0; a < 5;   a++)
           {
               cout<<hotelno[a]<<endl;
           }
           cout<<"\nCurretly we have only 5 hotels in our list\n";

           cout<<"Press any key or \n Enter number of the hotel you want to book: "; 
        cin>>choiceHotel;
        system("cls");
        bookActivity(); //calling its own function to book the hotel
             }
};
float hotels::hotelPrice;







class flights : public bookings
{
    public:
    static float flightPrice;
     int choiceFlight;
     int flightPackage;
     string flightName;

     flights():bookings()
     {
            choiceFlight=0;
            flightPackage=0;
            flightName=" ";
     }

     void bookActivity()
     {
        if(choiceFlight==1)
        {
            cout<<"-----------Welcome to Pak Air -----------"<<endl;	
            cout << "Flight Booking Options:\n";
            cout << "1. Economy Class\n";
            cout<<"\t basic facilities you need just for: Rs 20,000.00\n\n";
            cout << "2. Bussiness Class \n";
            cout << "\tEnjoy Premium comfort: : Rs 40,000.00\n\n";
            
            cout << "Enter the choice of your package:";
            cin>>flightPackage;

            if(flightPackage==1)
            {    flightName="Pak Air";
                flightPrice=20000.00;
                cout<<"You have successfully booked Economy Class"<<endl;
                cout<<"Goto Menue and take the recipt;"<<endl;

            }
            else if(flightPackage==2)
            {   
                flightName="Pak Air";
                flightPrice=40000.00;
                cout<<"You have successfully booked Bussiness Class"<<endl;
                cout<<"Goto Menue and take the recipt;"<<endl;
                
            }
            else
            {
                cout<<"Invalid choice, Redurecting to previous Menue.\n Please wait!"<<endl;
                Sleep(1100);
                system("cls");
                displayOptions(); // Calling the  funtion again to make user select a valid option
            }
           
               int gotomenue;           //redirecting to main menue after booling a flight 
        cout<<"Press  1 to redirect main menu :\n";
        cin>>gotomenue;
        if(gotomenue==1)
        {
            system("cls");
            menue();
        }
        else
        {
            menue();
        }


        }


        else if(choiceFlight==2)
        {
            cout<<"-----------Welcome to Indigo -----------"<<endl;	
            cout << "Flight Booking Options:\n";
            cout << "1. Economy Class\n";
            cout<<"\t basic facilities you need just for: Rs 10,000.00\n\n";
            cout << "2. Bussiness Class \n";
            cout << "\tEnjoy Premium comfort: : Rs 25,000.00\n\n";


            cout << "Enter the choice of your package:";
            cin>>flightPackage;

            if(flightPackage==1)
            {   flightName="Indigo";
                flightPrice=10000.00;
                cout<<"You have successfully booked Economy Class"<<endl;
                cout<<"Goto Menue and take the recipt;"<<endl;

            }
            else if(flightPackage==2)
            {flightName="Indigo";
                flightPrice=25000.00;
                cout<<"You have successfully booked Bussiness Class"<<endl;
                cout<<"Goto Menue and take the recipt;"<<endl;
                
            }
            else
            {
                cout<<"Invalid choice, Redurecting to previous Menue.\n Please wait!"<<endl;
                Sleep(1100);
                system("cls");
                displayOptions(); // Calling the  funtion again to make user select a valid option
            }
           
               int gotomenue;           //redirecting to main menue after booling a flight 
        cout<<"Press  1 to redirect main menu :\n";
        cin>>gotomenue;
        if(gotomenue==1)
        {
            system("cls");
            menue();
        }
        else
        {
            menue();
        }


        }

        else if (choiceFlight==3)
        {
            cout<<"-----------Welcome to Spice Jets  -----------"<<endl;	
            cout << "Flight Booking Options:\n";
            cout << "1. Economy Class\n";
            cout<<"\t Basic facilities you need just for: Rs 15,000.00\n\n";
            cout << "2. Bussiness Class \n";
            cout << "\tEnjoy Premium comfort: : Rs 35,000.00\n\n";

            cout << "Enter the choice of your package:";
            cin>>flightPackage;

            if(flightPackage==1)
            {    flightName="Spice Jets";
                flightPrice=15000.00;
                cout<<"You have successfully booked Economy Class"<<endl;
                cout<<"Goto Menue and take the recipt;"<<endl;

            }
            else if(flightPackage==2)
            {
                flightName="Spice Jets";
                flightPrice=15000.00;
                cout<<"You have successfully booked Bussiness Class"<<endl;
                cout<<"Goto Menue and take the recipt;"<<endl;
                
            }
            else
            {
                cout<<"Invalid choice, Redurecting to previous Menue.\n Please wait!"<<endl;
                Sleep(1100);
                system("cls");
                displayOptions(); // Calling the  funtion again to make user select a valid option
            }
           
               int gotomenue;           //redirecting to main menue after booling a flight 
        cout<<"Press  1 to redirect main menu :\n";
        cin>>gotomenue;
        if(gotomenue==1)
        {
            system("cls");
            menue();
        }
        else
        {
            menue();
        }


        }

else

{
    cout<<"Invalid choice, Redurecting to previous Menue.\n Please wait!"<<endl;
                Sleep(1100);
                system("cls");
                displayOptions();
}
     }


    void displayOptions()
    {        cout<<"-----------Welcome to Flight Booking-----------"<<endl;
        
         string flightno[]={"\n1. Pak Air \n","2. Indigo\n","3. Spice Jets\n"};
           for (int a = 0; a < 3;   a++)
           {
               cout<<flightno[a]<<endl;
           }
           cout<<"\nCurretly we have only 3 flights in our list\n";

           cout<<"Press any key or \n Enter number of the flight you want to book: ";
              cin>>choiceFlight;
        system("cls");
        bookActivity();
    
       
        

    }

   
   

};
float flights::flightPrice=0.0;




class dinner: public bookings
{
   public:
   int choiceDinner;
    float dinnerPrice;
    static float dinnerTotal;
    string dinnerName;
    
    dinner():bookings()
    {
        choiceDinner=0;
        dinnerPrice=0.0;
        // dinnerTotal=0.0;
        dinnerName="";

    }
    
    void bookActivity()
    {
          if(choiceDinner==1)
        {
            cout<<"-----------Welcome to Seafood Cove-----------"<<endl;	
            cout << "Dinner Booking Options:\n";
            cout << "1. Seafood Platter\n";
            cout<<"\t Enjoy the best seafood in town: Rs 5000.00\n\n";

            cout << "2. Seafood Platter with a sea view and chef's special.\n";
            cout << "\tEnjoy Premium comfort: : Rs 7000.00\n\n";
     cout << "Enter the choice: ";
    cin>>choiceDinner;

cout<<"You have successfully booked dinner at Seafood Crave "<<endl;
                cout<<"Goto Menue and take the recipt;"<<endl;
                dinnerName="Seafood Cove";
                if(choiceDinner==1)
                {
                    dinnerPrice=5000.00;
                }
                else if(choiceDinner==2)
                {
                    dinnerPrice=7000.00;
                }
                else
                {
                    cout<<"Invalid choice, Redurecting to previous Menue.\n Please wait!"<<endl;
                    Sleep(1100);
                    system("cls");
                    displayOptions(); // Calling the  funtion again to make user select a valid option
                }

             int gotomenue;           //redirecting to main menue after booling a flight 
        cout<<"Press  1 to redirect main menu :\n";
        cin>>gotomenue;
        if(gotomenue==1)
        {
            system("cls");
            menue();
        }
        else
        {
            menue();
        }


    
    }


else if(choiceDinner==2)
{
    
        
            dinnerName="Rustic farmhouse";
            cout<<"-----------Welcome to Rustic Farmhouse-----------"<<endl;	
            cout << "Dinner Booking Options:\n";
            cout << "1.  Embraces a farm-to-table concept, serving hearty dishes made with locally sourced ingredients and seasonal produce\n";
            cout<<"\t Enjoy the best Frmfood in town: Rs 4000.00\n\n";

            cout << "2. Chef's Special.\n";
            cout << "\tEnjoy Premium comfort food : : Rs 6000.00\n\n";
     cout << "Enter the choice: ";
    cin>>choiceDinner;
cout<<"You have successfully booked dinner at Rustic Farmhouse "<<endl;
                cout<<"Goto Menue and take the recipt;"<<endl;
                if(choiceDinner==1)
                {
                    dinnerPrice=4000.00;
                }
                else if(choiceDinner==2)
                {
                    dinnerPrice=6000.00;
                }
                else
                {
                    cout<<"Invalid choice, Redurecting to previous Menue.\n Please wait!"<<endl;
                    Sleep(1100);
                    system("cls");
                    displayOptions(); // Calling the  funtion again to make user select a valid option
                }

             int gotomenue;           //redirecting to main menue after booling a flight 
        cout<<"\nPress  1 to redirect main menu :\n";
        cin>>gotomenue;
        if(gotomenue==1)
        {
            system("cls");
            menue();
        }
        else
        {
            menue();
        }


}

else if(choiceDinner==3)
        {   dinnerName="Teakhouse Grill";
            cout<<"-----------Welcome to teakhouse Grill-----------"<<endl;	
            cout << "Dinner Booking Options:\n";
            cout << "1. Stake Platter\n";
            cout<<"\t Enjoy the best Stake in town: Rs 6000.00\n\n";
        cout << "2. Prime cuts of beef, grilled to perfection, along with gourmet sides and sauces.\n";
            cout << "\tEnjoy Premium comfort food: : Rs 8000.00\n\n";
     cout << "Enter the choice: ";
    cin>>choiceDinner;
cout<<"You have successfully booked dinner at Seafood Crave "<<endl;
                cout<<"Goto Menue and take the recipt;"<<endl;
                if(choiceDinner==1)
                {
                    dinnerPrice=6000.00;
                }
                else if(choiceDinner==2)
                {
                    dinnerPrice=8000.00;
                }
                else
                {
                    cout<<"Invalid choice, Redurecting to previous Menue.\n Please wait!"<<endl;
                    Sleep(1100);
                    system("cls");
                    displayOptions(); // Calling the  funtion again to make user select a valid option
                }

             int gotomenue;           //redirecting to main menue after booling a flight 
        cout<<"Press  1 to redirect main menu :\n";
        cin>>gotomenue;
        if(gotomenue==1)
        {
            system("cls");
            menue();
        }
        else
        {
            menue();
        }


    }
    else
    {
        cout<<"Invalid choice, Redurecting to previous Menue.\n Please wait!"<<endl;
        Sleep(1100);
        system("cls");
        displayOptions(); // Calling the  funtion again to make user select a valid option
    }
    }
    
    void displayOptions()
    {
        cout<<"-----------Welcome to Dinner Booking-----------"<<endl;
        
         string dinnerPlace[]={"1.Seafood Cove\n","2. Rustic Farmhouse\n","3.Steakhouse Grill\n"};
           for (int a = 0; a < 3;   a++)
           {
               cout<<dinnerPlace[a]<<endl;
           }
           cout<<"\nCurretly we have only 3 places in our list\n";

           cout<<"Press any key or \n Enter number of the place you want to book: ";
              cin>>choiceDinner;
        system("cls");
        bookActivity();
    
       
        

    }

};






void  bookings :: displayOptions()          //had to define the functio at the end of all the child classes because untill child classes are not defined the parent cannot make its object and use it 
{
     cout<<"What will you like to book? "<<endl;
        cout<<"1. Hotel"<<endl;
        cout<<"2. Flight"<<endl;
        cout<<"3. Dinner"<<endl;
        cout<<"4.Display booking summary:"<<endl;

       
        

        int choice;
        cin>>choice;
        system("cls");
        switch(choice)
        {
            case 1:
            {
                hotels h;
                h.displayOptions();
                break;
            }
            case 2:
            {
                flights f;
                f.displayOptions();
                break;
                    
            }
case 3:
             {
                 dinner d;
              d.displayOptions();
               break;
             }

        }
}







class charges: public hotels, flights, cab,dinner, customers{
                    public :
                        void printBill(){
                            ofstream outf("receipt.txt");
                {
               outf << "-------------Happy Trails Tours----------------" << endl;
               outf << "-------------------Receipt---------------------" << endl;
               outf << "_______________________________________________" << endl;

               outf << "Customer ID: " << customers::cutomerId << endl
                    << endl;
               outf << "Description\t\t     Total" << endl;
               outf << "Hotel cost:\t\t       " << fixed << setprecision(2) << hotels::hotelPrice << endl;
               outf << "Travel (Cab) cost:\t\t " << fixed << setprecision(2) << cab::price << endl;
               outf << "Travel (Flight) cost:\t\t " << fixed << setprecision(2) << flights::flightPrice << endl;
               outf << "Dinner Reservation:\t\t " << fixed << setprecision(2) << dinner::dinnerPrice << endl;
               outf << "_______________________________________________" << endl;
               outf << "Total cost:\t\t Rs." << fixed << setprecision(2) << hotels::hotelPrice + cab::price + flights::flightPrice+dinner::dinnerPrice  << endl;
               outf<<  "_______________________________________________"<<endl;
                outf<<  "Thank you for using our service"<<endl;
         }
         outf.close();
    }
    void showbill(){
        ifstream  inf("receipt.txt");
        {
            if(inf)
            {
                cout<<"File not found"<<endl;
            }
            while(!inf.eof())
            {    char allInfo[1000];
                inf.getline(allInfo,999);
                cout << allInfo << endl; // usinf if stream varible to print all values IN FILE TO PRINT ALL THE VALUES OR DATA IN THE FILE OF CUSTOERS 
            }
            inf.close();
        }
    }
};




class FeedbackDetails {
private:
    string customerName;

    string comment;
    int rating;

public:
    FeedbackDetails() {
    
    ofstream outf("feedback.txt", ios::app);
    {
        cout << "Enter customer name: ";
        cin>>customerName;

        cout << "Enter your comment: ";
         cin.ignore();
         getline(cin, comment);  

         cout<<"Enter your rating: ";
         cin>>rating;

         
    }
    {
        outf<<endl<<"Customer Name: "<<customerName<<endl;
        outf<<"Comment: "<<comment<<endl;
        outf<<"Rating: "<<rating<<endl;
    }
    }

    

    string getCustomerName() const {
        return customerName;
    }

    string getComment() const {
        return comment;
    }

    int getRating() const {
        return rating;
    }
};

class Feedback //Feedback class uses composition with a pointer (FeedbackDetails*) to indicate a stronger relationship of ownership and management. 
{
private:
    
    FeedbackDetails* details;

public:
    Feedback() {
      
        details = new FeedbackDetails();
    }

    ~Feedback() {
        delete details;
    }


    string getComment() const {
        return details->getComment();
    }
   string getCustomername() const {
        return details->getCustomerName();
    }

    int getRating() const {
        return details->getRating();
    }

    void printFeedback() const {
        cout << "Comment: " << getComment() << endl;
        cout << "Rating: " << getRating() << endl;
    }
};

    

class FeedbackManagementSystem     //FeedbackManagementSystem class and the Feedback class. The FeedbackManagementSystem class has a member variable named feedbacks, which is an instance of the Feedback class.
{
private:
    Feedback feedbacks;
public:


void displayAllFeedbacks() {
        cout << "All feedbacks: " << endl; 
        ifstream in("feedback.txt");
{
    if(!in)
    {
        cout<<"File not found"<<endl;
    }
    while(!in.eof())
    {
        char allInfo[999];
        in.getline(allInfo,999);
        cout << allInfo << endl; // usinf if stream varible to print all values IN FILE TO PRINT ALL THE VALUES OR DATA IN THE FILE OF CUSTOERS 
    }
    in.close();

}
}
~FeedbackManagementSystem() {
       
    }
};






class Employee {
private:
    string name;
    string role;

public:
    Employee()
    {
        ofstream outf("employee.txt", ios::app);
        {
            cout << "Enter employee name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter employee role: ";
            getline(cin, role);
        }
        {
            outf<<endl<<"Employee Name: "<<name<<endl;
            outf<<"Employee Role: "<<role<<endl;
        }
    }

  string getName() const {
        return name;
    }

  string getRole() const {
        return role;
    }
};


class TravelAgency {
private:
    static const int MAX_EMPLOYEES = 100; // Maximum number of employees
    Employee* employees[MAX_EMPLOYEES];
    int numEmployees;

public:
    TravelAgency()
        : numEmployees(0) {}

    ~TravelAgency() {
        // Clean up memory
        for (int i = 0; i < numEmployees; ++i) {
            delete employees[i];
        }
    }

    void addEmployee() {
        if (numEmployees < MAX_EMPLOYEES) {
            employees[numEmployees] = new Employee();
            ++numEmployees;
        } else {
           cout << "Max employees reached. Cannot add more employees." << std::endl;
        }
    }

    void removeEmployee(string& name) {
        int index = findEmployeeIndex(name);
        if (index != -1) {
            delete employees[index];
            for (int i = index; i < numEmployees - 1; ++i) {
                employees[i] = employees[i + 1];
            }
            --numEmployees;
            cout << "Employee " << name << " removed." <<endl;
        } else {
            cout << "Employee " << name << " not found." << endl;
        }
    }

    void displayEmployees() const {
        cout << "Employees at the Travel Agency:" << endl;
        ifstream  inf("employee.txt");
        {
            if(!inf)
            {
                cout<<"File not found"<<endl;
            }
            while(!inf.eof())
            { char allInfo[999];
                inf.getline(allInfo,999);
                cout << allInfo << endl; // usinf if stream varible to print all values IN FILE TO PRINT ALL THE VALUES OR DATA IN THE FILE OF CUSTOERS 
            }
            inf.close();
        }
    }

private:
    int findEmployeeIndex(const std::string& name) const {
        for (int i = 0; i < numEmployees; ++i) {
            if (employees[i]->getName() == name) {
                return i;
            }
        }
        return -1;
    }
};




void menue(int a )
{
    int choice, choice2,gotoMenue;
    if(a==0) // for admins the main menue is different 
    {

    

    cout << "\t\t           *Happy Trails Tours*\n " << endl;
    cout << "---------------------------------Main Menue--------------------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  " << endl;
    cout << "\t|\t\t\t\t\t |" << endl;
    cout << "\t|\tCustomer Management   -> 1\t\t|" << endl;
    cout << "\t|\tCabs Management       -> 2\t\t|" << endl;
    cout << "\t|\tBookings Management   -> 3\t\t|" << endl;
    cout << "\t|\tCharges & Bill        -> 4\t\t|" << endl;
    cout << "\t|\tFeedback              -> 5\t\t|" << endl;
    cout << "\t|\tExit                  -> 6\t\t|" << endl;
    cout << "\t|\tEmployee Managment     -> 7\t\t|" << endl;
    cout << "\t|\t\t\t\t\t\t|" << endl;
    cout<<"\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;}
    
    
    
    else 
    {
         cout << "\t\t           *Happy Trails Tours*\n " << endl;
    cout << "---------------------------------Main Menue--------------------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  " << endl;
    cout << "\t|\t\t\t\t\t |" << endl;
    cout << "\t|\tCustomer Management   -> 1\t\t|" << endl;
    cout << "\t|\tCabs Management       -> 2\t\t|" << endl;
    cout << "\t|\tBookings Management   -> 3\t\t|" << endl;
    cout << "\t|\tCharges & Bill        -> 4\t\t|" << endl;
    cout << "\t|\tFeedback              -> 5\t\t|" << endl;
    cout << "\t|\tExit                  -> 6\t\t|" << endl;
    cout << "\t|\t\t\t\t\t\t|" << endl;
    cout<<"\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;

  
    }

    cout << "\n Enter your choice: ";
    cin >> choice;



    system("cls");
    customers cust;
    cab cabs;
    bookings book;
    hotels h;
    charges ch;
    flights f;
    TravelAgency travelAgency;

   if(choice==1) //Customer Management
   {
    if(a==0)

     {  cout << "-------------Customer-------------\n" << endl;
       cout<<"1. Enter new Customer"<<endl;
       cout<<"2. See OLD Customer"<<endl;
       }
    else 
    {
        cout << "-------------Customer-------------\n" << endl;
       cout<<"1. Enter new Customer"<<endl;
       
    }
    



       cout<<"\n Enter your choice: ";
       cin>>choice2;

     system("cls");
     if(choice2==1)
     {
         cust.getDetails();

     }
     else if(choice2==2)
     {
        cust.ShowDetails();

     }
    
     else
     {
            // cout<<"Invalid choice"<<endl;
            // cout<<"Redirecting to main menue"<<endl;
            // Sleep(999);
            system("cls");
            menue();

     }

     cout<<"\nPress 1 to go to main menue"<<endl;
     cin>>gotoMenue;
     system("cls");

     if(gotoMenue==1)
     {
         menue();
     }
     else
     {
        //  cout<<"Invalid choice"<<endl;
        //  cout<<"Redirecting to main menue"<<endl;
        //  Sleep(999);
         system("cls");
         menue();
     }
   }
    

else if(choice==2) // Cab Mangment
{
  cout<<"-------------Cabs-------------\n"<<endl;

   cabs.cabDetails();

}
else if(choice==3)
{
  cout<<"-------------Bookings-------------\n"<<endl;
 book.displayOptions();



}


else if(choice==4)
{
    cout<<"-------------Charges & Bill-------------\n"<<endl;
    cout<<"----------Get your Reciept----------\n"<<endl;
    ch.printBill(); //this  will give you the reciept in txt 
    cout<<"Your receipt is already printed you can get it from the file path\n"<<endl;
    cout<<"To display your reciept on screen press 1"<<endl;
    cin>>gotoMenue;

    if(gotoMenue==1)
    {
         system("cls");
         ch.showbill();
         cout<<"\nPress 1 to go to main menue"<<endl;
         cin>>gotoMenue;
            system("cls");
            if(gotoMenue==1)
            {
                menue();
            }
            else
            {
                cout<<"Invalid choice"<<endl;
                cout<<"Redirecting to main menue"<<endl;
                Sleep(999);
                system("cls");
                menue();
            }
    }
    else
    {
        
        system("cls");
        menue();
    }


}


else if(choice==5)
{
       FeedbackManagementSystem *feedbackManagementSystem;
    cout<<"-------------Feedback-------------\n"<<endl;
    cout<<"1. Give Feedback"<<endl;
    
    cout<<"3. See All Feedbacks"<<endl;
    cout<<"\n Enter your choice: ";
    cin>>choice2;
    if(choice2==1)
    {
        system("cls");
        feedbackManagementSystem=new FeedbackManagementSystem();    //dynamic memory allocation
        cout << "\n Thankyou for your feedback!" << endl;
        Sleep(999);
        system("cls");
        menue();
    }
    else if(choice2==2)
    {  
           system("cls");
    feedbackManagementSystem->displayAllFeedbacks();
    cout << " \nPress 1 to go to main menue.";
    cin>>gotoMenue;
            system("cls");
            if(gotoMenue==1)
            {
                
                menue();
            }
            else
            {
                cout<<"Invalid choice"<<endl;
                cout<<"Redirecting to main menue"<<endl;
                Sleep(999);
                system("cls");
                menue();
            }

    }
    else
    {
        cout<<"Invalid choice"<<endl;
                cout<<"Redirecting to main menue"<<endl;
                Sleep(999);
                system("cls");
                menue();
    }
    delete feedbackManagementSystem;
}
else if(choice==6)
{
    cout<<"-----Good Bye-----"<<endl;
    Sleep(999);
    system("cls");
    exit(0);
}

else if(choice==7)
{
    cout<<"--------------Employee Of Happy Tours -----------------"<<endl;
    cout<<"1. Add Employee"<<endl;
    cout<<"2. Display Employee"<<endl;
    cout<<"3. Delete Employee"<<endl;
    ;
    cout<<"\n Enter your choice: ";
    cin>>choice2;
    if(choice2==1)
    {
        system("cls");

        travelAgency.addEmployee();
        cout << "\n Employee Added!" << endl;
        Sleep(999);
        system("cls");
        menue();
    }
    else if(choice2==2)
    {  
           system("cls");
           travelAgency.displayEmployees();
    cout << " \nPress 1 to go to main menue.";
    cin>>gotoMenue;
            system("cls");
            if(gotoMenue==1)
            {
                
                menue();
            }
            else
            {
                cout<<"Invalid choice"<<endl;
                cout<<"Redirecting to main menue"<<endl;
                Sleep(999);
                system("cls");
                menue();
            }
}

else if(choice2==3)
{
    system("cls");
    string n;
    cout<<"Enter Name of Employee you want to delete"<<endl;
    cin>>n;
    travelAgency.removeEmployee(n);
    Sleep(999);
    system("cls");
    menue();
}
}


else 
{
       cout<<"Invalid choice"<<endl;
                cout<<"Redirecting to main menue"<<endl;
                Sleep(999);
                system("cls");
                menue();
}


}

int main()
{


  
manageMenue startingObject;

return 0;

}