#include<bits/stdc++.h>
#include<cstring>
#include<cmath>
#include<stdlib.h>

using namespace std;
#define ll long long
const int len = 80;


class Person
{
    protected:
   	 char name[len];
   	 char gender[len];
   	 char phone[len];
   	 char email[len];
   	 char address[len];
    public:
   	 Person();
   	 void set_data();
   	 void get_data();
   	 void update_info();
};

class Employee: public Person
{
protected:
	char job_type[len];
	char designation[len];
	ll ID;
	ll Pin_number;
	char salary[len];
	char paid[len];
	char Joining_date[len];
public:
	Employee();
	void set_data();
	void get_data();
	void update_info();
	ll return_id_number();
	ll return_Pin_number();
};

class Student:public Person
{
protected:
	ll ID;
	ll PIN;
	char department[len];
	char batch[len];
	char session[len];
	char hall[len];

	ll room_no;
	ll bed_no;
	char complain[500];
public:
	Student();
	void set_data();
	void get_data();
	void update_info();
	ll return_id_number();
	ll return_pin_number();
};

class Room
{
    private:
   	 ll room_no;
   	 char floor[len];
   	 char room_type[len];
   	 ll number_of_seat;
   	 ll filled_seat;
   	 ll empty_seat;
    public:
   	 Room();
   	 Room(ll rm,char fr[],char rt[len],ll ns,ll fs,ll es);
   	 void set_data();
   	 void get_data();
   	 void update_info();
   	 ll return_room_no();
};


class Food_Service_Provider
{
private:

    //dining section

    ll token_price_breakfast;
	ll token_price_lunch;
	ll token_price_dinner;
	char breakfast_menu[len];
	char lunch_menu[len];
	char dinner_menu[len];

	//canteen section

	char boiled_rice[len];
	char fried_rice[len];
	char biriyani[len];
	char fish_fry[len];
	char fish_fry_hilsha[len];
	char fish_curry_hilsha[len];
	char fish_curry[len];
	char spicy_chicken_fry[len];
	char chicken_curry[len];
	char beef_curry[len];
	char mutton_curry[len];
	char mashed_potato[len];
	char mashed_fish[len];
	char dal_Vorta[len];


public:
    Food_Service_Provider();
    void set_data();
    void get_data();
    void update_info_Dining();
    void update_info_Canteen();
};


class Admin
{
protected:
	ll ID;
	ll Pin_number;
	char complaint[5000];
public:
	Admin();
	void Chnge_Pin();
	void set_complaint();
	void get_complaint();
	ll return_id_number();
    ll return_pin_number();
};
