#include<bits/stdc++.h>
#include<cstring>
#include<cmath>
#include<stdlib.h>
#include"shms.h"
using namespace std;
#define ll long long


Person::Person()
{
    name[0]='\0';
    gender[0]='\0';
    phone[0]='\0';
    email[0]='\0';
    address[0]='\0';
}
void Person::set_data()
{
    cout<<"\n\tEnter Name: "; fgets(name,len,stdin); ll siz=strlen(name); name[siz-1]='\0';
    cout<<"\n\tEnter Gender: "; fgets(gender,len,stdin); siz=strlen(gender); gender[siz-1]='\0';
    cout<<"\n\tEnter Phone: "; fgets(phone,len,stdin); siz=strlen(phone); phone[siz-1]='\0';
    cout<<"\n\tEnter Email: "; fgets(email,len,stdin); siz=strlen(email); email[siz-1]='\0';
    cout<<"\n\tEnter Address: "; fgets(address,len,stdin); siz=strlen(address); address[siz-1]='\0';


}
void Person::get_data()
{

    cout<<"\tName: "<<name<<endl;
    cout<<"\tGender: "<<gender<<endl;
    cout<<"\tPhone: "<<phone<<endl;
    cout<<"\tEmail: "<<email<<endl;
    cout<<"\tAddress: "<<address<<endl;

}
void Person::update_info()
{

    cout<<"\n\tUpdate Phone Number: "; fgets(phone,len,stdin); ll siz=strlen(phone); phone[siz-1]='\0';
    cout<<"\n\tUpdate Email: "; fgets(email,len,stdin); siz=strlen(email); email[siz-1]='\0';
    cout<<"\n\tUpdate Address: "; fgets(address,len,stdin); siz=strlen(address); address[siz-1]='\0';
}

Employee::Employee()
{
    job_type[0]='\0';
    designation[0]='\0';
    ID=0;
    Pin_number=0;
    salary[0]='\0';
    paid[0]='\0';
    Joining_date[0]='\0';
}
void Employee::set_data()
{
    Person::set_data();
    cout<<"\n\tEnter Job Type: "; fgets(job_type,len,stdin); ll siz=strlen(job_type); job_type[siz-1]='\0';
    cout<<"\n\tEnter Designation: "; fgets(designation,len,stdin); siz=strlen(designation); designation[siz-1]='\0';
    cout<<"\n\tEnter Employee ID: "; cin>>ID;
    getchar();
    cout<<"\n\tEnter Pin Number: "; cin>>Pin_number;
    getchar();
    cout<<"\n\tEnter Joining Date: "; fgets(Joining_date,len,stdin); siz=strlen(Joining_date); Joining_date[siz-1]='\0';
    cout<<"\n\tEnter Salary: "; fgets(salary,len,stdin); siz=strlen(salary); salary[siz-1]='\0';
    cout<<"\n\tEnter Whether Paid or Unpaid for last month?: "; fgets(paid,len,stdin); siz=strlen(paid); paid[siz-1]='\0';
    cout<<endl;

}
void Employee::get_data()
{
    Person::get_data();

    cout<<endl;
    cout<<"\n\tJob Type: "<<job_type;
    cout<<"\n\tDesignation: "<<designation;
    cout<<"\n\tEmployee ID: "<<ID;
    cout<<"\n\tJoining Date: "<<Joining_date;
    cout<<"\n\tSalary: "<<salary;
    cout<<"\n\tPaid or Unpaid for last month?: "<<paid;
    cout<<endl;

}
void Employee::update_info()
{
    Person::update_info();
    cout<<"\n\tUpdate Job Type: "; fgets(job_type,len,stdin); ll siz=strlen(job_type); job_type[siz-1]='\0';
    cout<<"\n\tUpdate Designation: "; fgets(designation,len,stdin); siz=strlen(designation); designation[siz-1]='\0';
    cout<<"\n\tUpdate Salary: "; fgets(salary,len,stdin); siz=strlen(salary); salary[siz-1]='\0';
    cout<<"\n\tUpdate Whether Paid or Unpaid for last month?: "; fgets(paid,len,stdin); siz=strlen(paid); paid[siz-1]='\0';
}
ll Employee::return_id_number()
{
    return ID;
}
ll Employee::return_Pin_number()
{
    return Pin_number;
}


Student::Student()
{
    ID=0;
    PIN=0;
    department[0]='\0';
    session[0]='\0';
    hall[0]='\0';

    room_no=0;
    bed_no=0;
    complain[0]='\0';
}
void Student::set_data()
{
    Person::set_data();
    cout<<"\n\tEnter Student ID: "; cin>>ID; getchar();
    cout<<"\n\tEnter Pin Number: "; cin>>PIN; getchar();
    cout<<"\n\tEnter Department: "; fgets(department,len,stdin); ll siz=strlen(department); department[siz-1]='\0';
    cout<<"\n\tEnter Batch: "; fgets(batch,len,stdin); siz=strlen(batch); batch[siz-1]='\0';
    cout<<"\n\tEnter Session: "; fgets(session,len,stdin); siz=strlen(session); session[siz-1]='\0';
    cout<<"\n\tEnter Hall: "; fgets(hall,len,stdin); siz=strlen(hall); hall[siz-1]='\0';

    cout<<"\n\tEnter Room No: "; cin>>room_no; getchar();
    cout<<"\n\tEnter Bed No: "; cin>>bed_no; getchar();
    cout<<endl;
}
void Student::get_data()
{

    Person::get_data();
    cout<<"\n\tStudent ID: "<<ID;
    cout<<"\n\tDepartment: "<<department;
    cout<<"\n\tBatch: "<<batch;
    cout<<"\n\tSession: "<<session;
    cout<<"\n\tHall: "<<hall;

    cout<<"\n\tRoom No: "<<room_no;
    cout<<"\n\tBed No: "<<bed_no;

    cout<<endl;

}
void Student::update_info()
{
    Person:: update_info();
    cout<<"\n\tUpdate Room No: "; cin>>room_no; getchar();
    cout<<"\n\tUpdate Bed No: "; cin>>bed_no; getchar();
}
ll Student::return_id_number()
{
    return ID;
}
ll Student::return_pin_number()
{
    return PIN;
}


Room::Room()
{
    room_no=0;
    floor[0]='\0';

    room_type[0]='\0';

    number_of_seat=0;
    filled_seat=0;
    empty_seat=0;


}
Room::Room(ll rm,char fr[],char rt[len],ll ns,ll fs,ll es)
{
    room_no=rm;
    strcpy(floor,fr);

    strcpy(room_type,rt);

    number_of_seat=ns;
    filled_seat=fs;
    empty_seat=es;
}

void Room::set_data()
{
    cout<<"\n\tEnter Room No: "; cin>>room_no; getchar();
    cout<<"\n\tEnter Floor No: "; fgets(floor,len,stdin); ll siz=strlen(floor); floor[siz-1]='\0';
    cout<<"\n\tEnter Room Type: "; fgets(room_type,len,stdin); siz=strlen(room_type); room_type[siz-1]='\0';

    cout<<"\n\tEnter Number of Seat: "; cin>>number_of_seat; getchar();
    cout<<"\n\tEnter Number of Filled Seat: "; cin>>filled_seat; getchar();
    cout<<"\n\tEnter Number of Empty Seat: "; cin>>empty_seat; getchar();
    cout<<endl;

}
void Room::get_data()
{
    cout<<"\n\tRoom Number: "<<room_no<<endl;
    cout<<"\n\tFloor Number: "<<floor<<endl;

    cout<<"\n\tRoom Type: "<<room_type<<endl;
    cout<<"\n\tNumber of Seat: "<<number_of_seat<<endl;
    cout<<"\n\tNumber of Filled Seat: "<<filled_seat<<endl;
    cout<<"\n\tNumber of Empty Seat: "<<empty_seat<<endl;
	cout<<endl;
}

void Room::update_info()
{
    cout<<"------------------------- Update Room Information ---------------------------"<<endl;
    cout<<"\n\tEdit Number of Seat: "; cin>>number_of_seat; getchar();
    cout<<"\n\tEdit Number of Filled Seat: "; cin>>filled_seat; getchar();
    cout<<"\n\tEdit Number of Empty Seat: "; cin>>empty_seat; getchar();
}

ll Room::return_room_no()
{
    return room_no;
}


Food_Service_Provider::Food_Service_Provider()
{
    token_price_breakfast=0;
    token_price_lunch=0;
    token_price_lunch=0;
    strcpy(breakfast_menu,"N/A");
    strcpy(lunch_menu,"N/A");
    strcpy(dinner_menu,"N/A");


    strcpy(boiled_rice,"N/A");
    strcpy(fried_rice,"N/A");
    strcpy(biriyani,"N/A");
    strcpy(fish_fry,"N/A");
    strcpy(fish_fry_hilsha,"N/A");
    strcpy(fish_curry,"N/A");
    strcpy(fish_curry_hilsha,"N/A");
    strcpy(spicy_chicken_fry,"N/A");
    strcpy(chicken_curry,"N/A");
    strcpy(beef_curry,"N/A");
    strcpy(mutton_curry,"N/A");
    strcpy(mashed_potato,"N/A");
    strcpy(mashed_fish,"N/A");
    strcpy(dal_Vorta,"N/A");

}

void Food_Service_Provider::set_data()
{
    // Dining section

    cout<<"-------------------------- Enter Dining Menu Chart -----------------------------"<<endl<<endl;

    cout<<"\n\tEnter Breakfast Menu: "; fgets(breakfast_menu,len,stdin); ll siz=strlen(breakfast_menu); breakfast_menu[siz-1]='\0';
    cout<<"\n\tEnter Breakfast Token Price: "; cin>>token_price_breakfast; getchar();
    cout<<"\n\tEnter Lunch Menu: "; fgets(lunch_menu,len,stdin); siz=strlen(lunch_menu); lunch_menu[siz-1]='\0';
    cout<<"\n\tEnter Lunch Token Price: ";cin>>token_price_lunch; getchar();
    cout<<"\n\tEnter Dinner Menu: "; fgets(dinner_menu,len,stdin); siz=strlen(dinner_menu); dinner_menu[siz-1]='\0';
    cout<<"\n\tEnter Dinner Token Price: "; cin>>token_price_dinner;getchar();


    //Canteen Section

    cout<<"-------------------------- Enter Canteen Menu Chart ----------------------------"<<endl<<endl;

    cout<<"\n\tEnter Price for Boiled Rice: "; cin>>boiled_rice;
    cout<<"\n\tEnter Price for Fried Rice:  "; cin>>fried_rice;
    cout<<"\n\tEnter Price for Biriyani:  "; cin>>biriyani;
    cout<<"\n\tEnter Price for Fish Fry:  "; cin>>fish_fry;
    cout<<"\n\tEnter Price for Hilsha Fry:  "; cin>>fish_fry_hilsha;
    cout<<"\n\tEnter Price for Fish Curry:  "; cin>>fish_curry;
    cout<<"\n\tEnter Price for Hilsha Curry:  "; cin>>fish_curry_hilsha;
    cout<<"\n\tEnter Price for Spicy Chicken Fry:  "; cin>>spicy_chicken_fry;
    cout<<"\n\tEnter Price for Chicken Curry:  "; cin>>chicken_curry;
    cout<<"\n\tEnter Price for Beef Curry:  "; cin>>beef_curry;
    cout<<"\n\tEnter Price for Mutton Curry:  "; cin>>mutton_curry;
    cout<<"\n\tEnter Price for Mashed Potato:  "; cin>>mashed_potato;
    cout<<"\n\tEnter Price for Mashed Fish:  "; cin>>mashed_fish;
    cout<<"\n\tEnter Price for Dal Vorta:  "; cin>>dal_Vorta;
    cout<<endl;
}

void Food_Service_Provider::get_data()
{
    //dining section

    cout<<"---------------------------- Dining Menu Chart ---------------------------------"<<endl<<endl;

    cout<<"\n\tBreakfast Menu: "<<endl;
    cout<<"\t"<<breakfast_menu<<endl;
    cout<<"\n\tToken Price for Breakfast: "<<token_price_breakfast<<endl;
    cout<<"\n\tLunch Menu: "<<endl;
    cout<<"\t"<<lunch_menu<<endl;
    cout<<"\n\tToken Price for Lunch: "<<token_price_lunch<<endl;
    cout<<"\n\tDinner Menu: "<<endl;
    cout<<"\t"<<dinner_menu<<endl;
    cout<<"\n\tToken Price for Dinner: "<<token_price_dinner<<endl;

    //Canteen section

    cout<<"---------------------------- Canteen Menu Chart --------------------------------"<<endl<<endl;


    cout<<"\n\tPrice for Boiled Rice: "<<boiled_rice;
    cout<<"\n\tPrice for Fried Rice: "<<fried_rice;
    cout<<"\n\tPrice for Biriyani: "<<biriyani;
    cout<<"\n\tPrice for Fish Fry: "<<fish_fry;
    cout<<"\n\tPrice for Hilsha Fry: "<<fish_fry_hilsha;
    cout<<"\n\tPrice for Fish Curry: "<<fish_curry;
    cout<<"\n\tPrice for Hilsha Curry: "<<fish_curry_hilsha;
    cout<<"\n\tPrice for Spicy Chicken Fry: "<<spicy_chicken_fry;
    cout<<"\n\tPrice for Chicken Curry: "<<chicken_curry;
    cout<<"\n\tPrice for Beef Curry: "<<beef_curry;
    cout<<"\n\tPrice for Mutton Curry: "<<mutton_curry;
    cout<<"\n\tPrice for Mashed Potato: "<<mashed_potato;
    cout<<"\n\tPrice for Mashed Fish: "<<mashed_fish;
    cout<<"\n\tPrice for Dal Vorta: "<<dal_Vorta;
    cout<<endl;
    cout<<endl;
}
void Food_Service_Provider::update_info_Dining()
{
    cout<<"------------------------- Update Dining Menu Chart -----------------------------"<<endl<<endl;

    cout<<"\n\tUpdate Breakfast Menu: "; fgets(breakfast_menu,len,stdin); ll siz=strlen(breakfast_menu); breakfast_menu[siz-1]='\0';
    cout<<"\n\tUpdate Breakfast Token Price: "; cin>>token_price_breakfast; getchar();
    cout<<"\n\tUpdate Lunch Menu: "; fgets(lunch_menu,len,stdin); siz=strlen(lunch_menu); lunch_menu[siz-1]='\0';
    cout<<"\n\tUpdate Lunch Token Price: ";cin>>token_price_lunch; getchar();
    cout<<"\n\tUpdate Dinner Menu: "; fgets(dinner_menu,len,stdin); siz=strlen(dinner_menu); dinner_menu[siz-1]='\0';
    cout<<"\n\tUpdate Dinner Token Price: "; cin>>token_price_dinner;getchar();
    cout<<endl;
}
void Food_Service_Provider::update_info_Canteen()
{
    cout<<"------------------------- Update Canteen Menu Chart ----------------------------"<<endl<<endl;

    cout<<"\n\tUpdate Price for Boiled Rice: "; cin>>boiled_rice;
    cout<<"\n\tUpdate Price for Fried Rice:  "; cin>>fried_rice;
    cout<<"\n\tUpdate Price for Biriyani:  "; cin>>biriyani;
    cout<<"\n\tUpdate Price for Fish Fry:  "; cin>>fish_fry;
    cout<<"\n\tUpdate Price for Hilsha Fry:  "; cin>>fish_fry_hilsha;
    cout<<"\n\tUpdate Price for Fish Curry:  "; cin>>fish_curry;
    cout<<"\n\tUpdate Price for Hilsha Curry:  "; cin>>fish_curry_hilsha;
    cout<<"\n\tUpdate Price for Spicy Chicken Fry:  "; cin>>spicy_chicken_fry;
    cout<<"\n\tUpdate Price for Chicken Curry:  "; cin>>chicken_curry;
    cout<<"\n\tUpdate Price for Beef Curry:  "; cin>>beef_curry;
    cout<<"\n\tUpdate Price for Mutton Curry:  "; cin>>mutton_curry;
    cout<<"\n\tUpdate Price for Mashed Potato:  "; cin>>mashed_potato;
    cout<<"\n\tUpdate Price for Mashed Fish:  "; cin>>mashed_fish;
    cout<<"\n\tUpdate Price for Dal Vorta:  "; cin>>dal_Vorta;
    cout<<endl;
}
Admin::Admin()
{
    ID=20200650740;
    Pin_number=56563232;
    complaint[0]='\0';
}
void Admin::Chnge_Pin()
{
    cout<<"\n\tEnter New Pin: "; cin>>Pin_number;
}
void Admin::set_complaint()
{
    cout<<"\n\tEnter Your Complaint: "; fgets(complaint,5000,stdin); ll siz=strlen(complaint); complaint[siz-1]='\0';
}
void Admin::get_complaint()
{
    cout<<complaint<<endl;
}
ll Admin::return_id_number()
{
    return ID;
}
ll Admin::return_pin_number()
{
    return Pin_number;
}
