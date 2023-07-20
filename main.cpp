#include"shms.h"
using namespace std;

int main()
{
    //Room Section

    ifstream room_infile("Roomfile.DAT",ios::binary);
    ll room_num;
    room_infile.seekg(0,ios::end);
    room_num=(room_infile.tellg()/sizeof(Room));
    if(room_infile.tellg()==EOF)
    {
   	 room_num=0;
    }

    Room *room_ara[100];
    room_infile.seekg(0);
    for(ll i=0;i<room_num;i++)
    {
   	 room_ara[i]=new Room;
   	 room_infile.read(reinterpret_cast<char*>(room_ara[i]),sizeof(*room_ara[i]));
    }
    room_infile.close();

    //Employee Section

	ifstream emp_infile("Employee.DAT",ios::binary);
	ll  emp_num;
	emp_infile.seekg(0,ios::end);
	emp_num=(emp_infile.tellg()/sizeof(Employee));

	if(emp_infile.tellg()==EOF)
	{
    	emp_num=0;
	}

	Employee *emp_ara[1200];
	emp_infile.seekg(0);
	for(ll  i=0;i<emp_num;i++)
	{
    	emp_ara[i]=new Employee;
    	emp_infile.read(reinterpret_cast<char*>(emp_ara[i]),sizeof(*emp_ara[i]));
	}
	emp_infile.close();

    //current Student section

	ifstream cur_infile("Student.DAT",ios::binary);
	ll cur_num;
	cur_infile.seekg(0,ios::end);
	cur_num=(cur_infile.tellg()/sizeof(Student));
	if(cur_infile.tellg()==EOF)
	{
    	cur_num=0;
	}
	Student *cur_ara[12000];
	cur_infile.seekg(0);
	for(ll i=0;i<cur_num;i++)
	{
    	cur_ara[i]=new Student;
    	cur_infile.read(reinterpret_cast<char*>(cur_ara[i]),sizeof(*cur_ara[i]));
	}
	cur_infile.close();

    // Food Service Provider Section

	ifstream food_infile("Food.DAT",ios::binary);
	Food_Service_Provider *food;
	food_infile.seekg(0);
    food=new Food_Service_Provider;

    food_infile.read(reinterpret_cast<char*>(food),sizeof(*food));
	food_infile.close();

    // Admin Section

	ifstream admin_infile("Admin.DAT",ios::binary);
	admin_infile.seekg(0);
	Admin *admin;
    admin=new Admin;
    admin_infile.read(reinterpret_cast<char*>(admin),sizeof(*admin));
	admin_infile.close();

    cout<<"\tAvailable ID: "<<endl;
    cout<<"\tNumber of Student: "<<cur_num<<endl;
    cout<<"\tNumber of Employee: "<<emp_num<<endl;
    cout<<"\tNumber of Room: "<<room_num<<endl;

    cout<<"\tPress Enter to Continue........"<<endl;
    getchar();
    system("clear");

	cout<<"---------------------- Welcome To A F M Kamaluddin Hall  -----------------------"<<endl<<endl;

	set<ll>student_id;
	set<ll>emp_id;
	ll choice;
	while(1)
	{
   	 cout<<endl;
    	cout<<"-----------------------------	Dashboard   -----------------------------------"<<endl;

    	cout<<endl;
    	cout<<"\n\tEnter 1 to LogIn";
    	cout<<"\n\tEnter 2 to See Room Information";
    	cout<<"\n\tEnter 3 to See The Food Menu";
    	cout<<"\n\tEnter 0 to Exit The Program.";
    	cin>>choice; getchar();
    	system("clear");


    	if(choice == 2)
    	{
   		 ll room_number;
   		 while(1)
   		 {
   			 cout<<"------------------------------ Room Information --------------------------------"<<endl<<endl;

   			 cout<<"\n\tEnter Room Number: ";
   			 cin>>room_number;
   			 getchar();
   			 system("clear");
   			 bool flg=false;
   			 for(ll i=0;i<room_num;i++)
   			 {
   				 if(room_ara[i]->return_room_no()==room_number)
   				 {
   					 flg=true;
   					 cout<<"------------------------------ Room Information --------------------------------"<<endl<<endl;
   					 room_ara[i]->get_data();

   					 cout<<"\tPress Enter to Continue......"<<endl;
   					 getchar();
   					 system("clear");
   				 }
   			 }
   			 if(flg==false)
   			 {
   				 cout<<"\n\tEnter Wrong Room Number!!!"<<endl;
   				 cout<<"\n\tDo You Want to Try Again? (1->YES/2->NO)"<<endl;
   				 ll xx;
   				 cin>>xx;
   				 getchar();
   				 system("clear");
   				 if(xx==2)
   				 {
   					 break;
   				 }
   			 }
   			 else
   			 {
   				 cout<<"\n\tDo You Want to Search More?(1->YES/2->NO)"<<endl;
   				 ll xx;
   				 cin>>xx; getchar();
   				 system("clear");
   				 if(xx==2)
   				 {
   					 break;
   				 }
   			 }
   		 }

   	 }
   	 else if(choice==3)
    	{
   		 cout<<"--------------------------------- Food Menu ------------------------------------"<<endl<<endl;

        	food->get_data();

   		 cout<<"\tPress Enter to Continue......"<<endl;
   		 getchar();
   		 system("clear");
    	}
    	else if( choice == 0)
    	{
        	break;
    	}
    	else if(choice==1)
    	{
        	ll ch;
        	while(1)
        	{
   			 cout<<"--------------------------- Log In Section (Admin) -----------------------------"<<endl<<endl;

            	cout<<"\tPress 1 if you want to LogIn as admin"<<endl;
            	cout<<"\tPress 2 to Log In as Current User"<<endl;
            	cout<<"\tPress 3 to Log In as Employee"<<endl;
            	cout<<"\tPress 0 to Return Previous Window!"<<endl;
            	cin>>ch;
            	getchar();
            	system("clear");
            	if(ch==1)
            	{
                	ll id;
                	ll pin;
                	while(1)
                	{
   					 cout<<"---------------------------- Log In Section (Admin) ----------------------------"<<endl<<endl;

   					 cout<<"\tEnter ID No: "; cin>>id; getchar();
   					 cout<<"\tEnter Pin NO: "; cin>>pin; getchar();system("clear");
   					 bool flg1=false;
   					 if(id==admin->return_id_number()&&pin==admin->return_pin_number())
   					 {
   						 cout<<"------------------------ You Have Entered as an Admin.--------------------------"<<endl<<endl;

   						 flg1=true;

   						 while(1)
   						 {

   							 cout<<endl;
   							 cout<<"------------------------------ Admin Dashboard ---------------------------------"<<endl<<endl;

   							 cout<<"\tEnter 1 to Create New Account"<<endl;
   							 cout<<"\tEnter 2 to Update Account Information"<<endl;
   							 cout<<"\tEnter 3 to Set Canteen/Dining Food Menu"<<endl;
   							 cout<<"\tEnter 4 to See Account Information"<<endl;
   							 cout<<"\tEnter 5 to See Canteen/Dining Food Menu"<<endl;
   							 cout<<"\tEnter 6 to See Complaint Box"<<endl;
   							 cout<<"\tEnter 0 to Return"<<endl;
   							 cout<<endl;

   							 ll ch1;
   							 cin>>ch1; getchar(); system("clear");

   							 if(ch1==1)
   							 {
   								 cout<<"----------------------------- Create New Account -------------------------------"<<endl<<endl;


   								 cout<<"\tEnter 1 to Create Account for Student"<<endl;
   								 cout<<"\tEnter 2 to Create Account for Employee"<<endl;
   								 cout<<"\tEnter 3 to Create New Room"<<endl;
   								 cout<<endl;
   								 ll ch2;
   								 cin>>ch2; getchar(); system("clear");
   								 if(ch2==1)
   								 {
   									 ll ch3;
   									 cout<<"--------------------------- Create Student Account -----------------------------"<<endl<<endl;

   									 cout<<"\tEnter 1 to Create One Account"<<endl;
   									 cout<<"\tEnter 2 to Create More Than One Account"<<endl;
   									 cin>>ch3;
   									 getchar();
   									 system("clear");
   									 if(ch3==1)
   									 {
   										 cur_ara[cur_num]=new Student;
   										 cout<<"----------------------Set Informations for Student Account----------------------"<<endl<<endl;

   										 cur_ara[cur_num]->set_data();
   										 cur_num++;

   										 cout<<"------------------------------ Account Created ---------------------------------"<<endl<<endl;
   										 cout<<"\tPress Enter to Continue......"<<endl;
   										 getchar();
   										 system("clear");
   									 }
   									 else if(ch3==2)
   									 {
   										 ll accnum;
   										 cout<<"------------------------- Create Student Account -------------------------------"<<endl<<endl;
   										 cout<<"\tEnter Number of Account You Want to Crate: "<<endl;
   										 cin>>accnum;
   										 getchar();

   										 while(accnum--)
   										 {
   											 cur_ara[cur_num]=new Student;
   											 cout<<"----------------------Set Informations for Student Account----------------------"<<endl<<endl;
   											 cur_ara[cur_num]->set_data();
   											 cur_num++;

   											 cout<<"------------------------------ Account Created ---------------------------------"<<endl<<endl;
   											 cout<<"\tPress Enter to Continue......"<<endl;
   											 getchar();
   											 system("clear");
   										 }
   									 }
   								 }
   								 else if(ch2==2)
   								 {
   									 ll ch3;
   									 cout<<"------------------------- Create Employee Account -------------------------------"<<endl<<endl;

   									 cout<<"\tEnter 1 to Create One Account"<<endl;
   									 cout<<"\tEnter 2 to Create More Than One Account"<<endl;
   									 cin>>ch3;
   									 getchar();
   									 system("clear");
   									 if(ch3==1)
   									 {
   										 emp_ara[emp_num]=new Employee;
   										 cout<<"----------------------Set Informations for Employee Account----------------------"<<endl<<endl;
   										 emp_ara[emp_num]->set_data();
   										 emp_num++;

   										 cout<<"------------------------------ Account Created ---------------------------------"<<endl<<endl;
   										 cout<<"\tPress Enter to Continue......"<<endl;
   										 getchar();
   										 system("clear");
   									 }
   									 else if(ch3==2)
   									 {
   										 ll accnum;
   										 cout<<"------------------------- Create Employee Account -------------------------------"<<endl<<endl;

   										 cout<<"\tEnter Number of Account You Want to Crate"<<endl;
   										 cin>>accnum;
   										 getchar();
   										 while(accnum--)
   										 {
   											 emp_ara[emp_num]=new Employee;
   											 cout<<"----------------------Set Informations for Employee Account----------------------"<<endl<<endl;
   											 emp_ara[emp_num]->set_data();
   											 emp_num++;

   											 cout<<"------------------------------ Account Created ---------------------------------"<<endl<<endl;
   											 cout<<"\tPress Enter to Continue......"<<endl;
   											 getchar();
   											 system("clear");
   										 }
   									 }
   								 }
   								 else if(ch2==3)
   								 {
   									 ll ch3;
   									 cout<<"--------------------------- Create New Room -------------------------------"<<endl<<endl;

   									 cout<<"\tEnter 1 to Create One Room Object"<<endl;
   									 cout<<"\tEnter 2 to Create More Than One Room Object"<<endl;
   									 cin>>ch3;
   									 getchar();
   									 system("clear");
   									 if(ch3==1)
   									 {
   										 room_ara[room_num]=new Room;
   										 cout<<"------------------------ Set New Room Information -------------------------"<<endl<<endl;
   										 room_ara[room_num]->set_data();
   										 room_num++;

   										 cout<<"------------------------------- Room Created -----------------------------------"<<endl<<endl;

   										 cout<<"\tPress Enter to Continue......"<<endl;
   										 getchar();
   										 system("clear");
   									 }
   									 else if(ch3==2)
   									 {
   										 ll accnum;
   										 cout<<"--------------------------- Create New Room -------------------------------"<<endl<<endl;

   										 cout<<"\tEnter Number of Account You Want to Crate: "<<endl;
   										 cin>>accnum;
   										 getchar();
   										 while(accnum--)
   										 {
   											 room_ara[room_num]=new Room;
   											 cout<<"------------------------ Set New Room Information -------------------------"<<endl<<endl;
   											 room_ara[room_num]->set_data();
   											 room_num++;

   											 cout<<"------------------------------- Room Created -----------------------------------"<<endl<<endl;

   											 cout<<"\tPress Enter to Continue......"<<endl;
   											 getchar();
   											 system("clear");
   										 }
   									 }
   								 }
   							 }

   							 else if(ch1==2)
   							 {
   								 cout<<"--------------------- Update Account Information --------------------------"<<endl<<endl;

   								 cout<<endl;
   								 cout<<"\tEnter 1 to Update Student Information"<<endl;
   								 cout<<"\tEnter 2 to Update Employee Information"<<endl;
   								 cout<<"\tEnter 3 to Update Room Information"<<endl;
   								 cout<<endl;

   								 ll ch2;
   								 cin>>ch2;
   								 getchar();
   								 system("clear");
   								 if(ch2==1)
   								 {
   									 while(1)
   									 {
   										 ll u_id;
   										 cout<<"------------------ Update Student Account Information ---------------------"<<endl<<endl;

   										 cout<<"\tEnter Student ID :";

   										 cin>>u_id; getchar(); system("clear");


   										 for(ll i=0;i<cur_num;i++)
   										 {
   											 if(cur_ara[i]->return_id_number()==u_id)
   											 {
   												 cout<<"------------------ Update Student Account Information ---------------------"<<endl<<endl;

   												 cur_ara[i]->update_info();

   												 cout<<"----------------------------- Account Updated ----------------------------------"<<endl<<endl;

   												 cout<<"\tPress Enter to Continue......"<<endl;
   												 getchar();
   												 system("clear");
   											 }
   										 }
   										 cout<<"\tDo You Want to Update more?( 1->YES/2->NO )"<<endl;
   										 ll ch3;
   										 cin>>ch3;
   										 getchar(); system("clear");
   										 if(ch3==2)
   										 {
   											 break;
   										 }
   									 }

   								 }
   								 else if(ch2==2)
   								 {
   									 while(1)
   									 {
   										 cout<<"------------------ Update Employee Account Information ---------------------"<<endl<<endl;

   										 cout<<"\tEnter Employee ID :";
   										 ll u_id;
   										 cin>>u_id; getchar(); system("clear");
   										 for(ll i=0;i<emp_num;i++)
   										 {
   											 if(emp_ara[i]->return_id_number()==u_id)
   											 {
   												 cout<<"------------------ Update Employee Account Information ---------------------"<<endl<<endl;

   												 emp_ara[i]->update_info();

   												 cout<<"----------------------------- Account Updated ----------------------------------"<<endl<<endl;

   												 cout<<"\tPress Enter to Continue......"<<endl;
   												 getchar();
   												 system("clear");
   											 }
   										 }
   										 cout<<"\tDo You Want to Update more?( 1->YES/2->NO )"<<endl;
   										 ll ch3;
   										 cin>>ch3;
   										 getchar();
   										 system("clear");
   										 if(ch3==2)
   										 {
   											 break;
   										 }
   									 }
   								 }
   								 else if(ch2==3)
   								 {
   									 while(1)
   									 {

   										 ll u_id;
   										 cout<<"------------------------ Update Room Information ---------------------------"<<endl<<endl;

   										 cout<<"\tEnter Room Number :";
   										 cin>>u_id; getchar(); system("clear");
   										 for(ll i=0;i<room_num;i++)
   										 {
   											 if(room_ara[i]->return_room_no()==u_id)
   											 {
   												 cout<<"------------------------ Update Room Information ---------------------------"<<endl<<endl;

   												 room_ara[i]->update_info();
   												 cout<<"---------------------------- Room Info Updated ---------------------------------"<<endl<<endl;

   												 cout<<"\tPress Enter to Continue......"<<endl;
   												 getchar();
   												 system("clear");
   											 }
   										 }
   										 cout<<"\tDo You Want to Update more?( 1->YES/2->NO )"<<endl;
   										 ll ch3;
   										 cin>>ch3;
   										 getchar();
   										 system("clear");
   										 if(ch3==2)
   										 {
   											 break;
   										 }
   									 }
   								 }
   							 }
   							 else if(ch1==3)
   							 {
   								 cout<<"----------------------------- Set Food Menu --------------------------------"<<endl<<endl;
   								 food->set_data();

   								 cout<<"--------------------------- Food Menu Updated -------------------------------"<<endl<<endl;

   								 cout<<"\tPress Enter to Continue......"<<endl;
   								 getchar();
   								 system("clear");
   							 }
   							 else if(ch1==4)
   							 {
   								 ll ch2;

   								 while(1)
   								 {
   									 cout<<"------------------------- See Account Information ------------------------------"<<endl<<endl;

   									 cout<<"\tEnter 1 to See Student Information"<<endl;
   									 cout<<"\tEnter 2 to See Employee Information"<<endl;
   									 cout<<"\tEnter 3 to See Room Information"<<endl;
   									 cout<<"\tEnter 0 to Return"<<endl;
   									 cin>>ch2;
   									 getchar();
   									 system("clear");
   									 if(ch2==1)
   									 {

   										 ll u_id;
   										 while(1)
   										 {
   											 cout<<"--------------------- See Student Account Information --------------------------"<<endl<<endl;

   											 cout<<"\tEnter Student ID NO:";
   											 cin>>u_id;
   											 getchar();
   											 system("clear");
   											 bool flag=false;
   											 for(ll i=0;i<cur_num;i++)
   											 {
   												 if(cur_ara[i]->return_id_number()==u_id)
   												 {
   													 flag=true;
   													 cout<<"----------------------- Student Account Information ----------------------------"<<endl<<endl;

   													 cur_ara[i]->get_data();

   													 cout<<"\tPress Enter to Continue......"<<endl;
   													 getchar();
   													 system("clear");
   												 }
   											 }
   											 if(flag==false)
   											 {
   												 cout<<"\tYou Have Entered Wrong ID!!!"<<endl;
   												 cout<<"\tPlease Try Again"<<endl;
   											 }
   											 else
   											 {
   												 cout<<"\tDo You Want to See More? (1->YES/2->NO)"<<endl;
   												 ll xx;
   												 cin>>xx;
   												 getchar();
   												 system("clear");
   												 if(xx==2)
   												 {
   													 break;
   												 }
   											 }
   										 }
   									 }
   									 else if(ch2==2)
   									 {
   										 ll u_id;
   										 while(1)
   										 {
   											 cout<<"--------------------- See Employee Account Information -------------------------"<<endl<<endl;

   											 cout<<"\tEnter Employee ID NO:";
   											 cin>>u_id;
   											 system("clear");
   											 getchar();
   											 bool flag=false;
   											 for(ll i=0;i<emp_num;i++)
   											 {
   												 if(emp_ara[i]->return_id_number()==u_id)
   												 {
   													 flag=true;
   													 cout<<"----------------------- Employee Account Information ---------------------------"<<endl<<endl;

   													 emp_ara[i]->get_data();

   													 cout<<"\tPress Enter to Continue......"<<endl;
   													 getchar();
   													 system("clear");
   												 }
   											 }
   											 if(flag==false)
   											 {
   												 cout<<"\tYou Have Entered Wrong ID!!!"<<endl;
   												 cout<<"\tPlease Try Again"<<endl;
   											 }
   											 else
   											 {
   												 cout<<"\tDo You Want to See More? (1->YES/2->NO)"<<endl;
   												 ll xx;
   												 cin>>xx;
   												 getchar();
   												 system("clear");
   												 if(xx==2)
   												 {
   													 break;
   												 }
   											 }
   										 }
   									 }
   									 else if(ch2==3)
   									 {
   										 ll room_number;
   										 while(1)
   										 {
   											 cout<<"--------------------------- See Room Information -------------------------------"<<endl<<endl;

   											 cout<<"\tEnter Room Number:";
   											 cin>>room_number;
   											 getchar();
   											 system("clear");
   											 bool flag=false;
   											 for(ll i=0;i<room_num;i++)
   											 {
   												 if(room_ara[i]->return_room_no()==room_number)
   												 {
   													 flag=true;
   													 cout<<"------------------------------ Room Information --------------------------------"<<endl<<endl;

   													 room_ara[i]->get_data();

   													 cout<<"\tPress Enter to Continue......"<<endl;
   													 getchar();
   													 system("clear");
   												 }
   											 }
   											 if(flag==false)
   											 {
   												 cout<<"\tYou Have Entered Wrong ID!!!"<<endl;
   												 cout<<"\tPlease Try Again"<<endl;
   											 }
   											 else
   											 {
   												 cout<<"\tDo You Want to See More? (1->YES/2->NO)"<<endl;
   												 ll xx;
   												 cin>>xx;
   												 system("clear");
   												 getchar();
   												 if(xx==2)
   												 {
   													 break;
   												 }
   											 }
   										 }
   									 }
   									 else
   									 {
   										 break;
   									 }
   								 }

   							 }
   							 else if(ch1==5)
   							 {

   								 cout<<"---------------------------------- Food Menu -----------------------------------"<<endl<<endl;

   								 food->get_data();

   								 cout<<"\tPress Enter to Continue......"<<endl;
   								 getchar();
   								 system("clear");
   							 }
   							 else if(ch1==6)
   							 {
   								 cout<<endl;
   								 cout<<"-------------------------------- Complaint Box ---------------------------------"<<endl<<endl;

   								 admin->get_complaint();

   								 cout<<"\tPress Enter to Continue......"<<endl;
   								 getchar();
   								 system("clear");
   							 }
   							 else
   							 {
   								 break;
   							 }
   						 }

   					 }
   					 else
   					 {
   						 cout<<"\tWrong ID or Pin Number!!!!!"<<endl;
   						 cout<<"\tDo you Want to Try again? (Press 1->YES/2->NO)"<<endl;
   						 ll xx;
   						 cin>>xx;
   						 system("clear");
   						 if(xx==2)
   						 {
   							 break;
   						 }
   					 }
   					 if(flg1==true)
   					 {
   						 break;
   					 }
   				 }

            	}
            	else if(ch==2)
            	{
   				 ll id;
   				 ll pin;
   				 while(1)
   				 {
   					 cout<<"------------------------- Log In Section (Student)  ----------------------------"<<endl<<endl;

   					 cout<<"\tEnter ID No: "; cin>>id; getchar();
   					 cout<<"\tEnter Pin No: "; cin>>pin; getchar();system("clear");
   					 bool flag=false;
   					 for(ll i=0;i<cur_num;i++)
   					 {
   						 if(cur_ara[i]->return_id_number()==id&&cur_ara[i]->return_pin_number()==pin)
   						 {
   							 flag=true;
   							 cout<<"\tLogged In!!!!"<<endl;

   							 while(1)
   							 {
   								 cout<<endl;
   								 cout<<"------------------------ Student Profile Dashboard -----------------------------"<<endl;

   								 cout<<endl;

   								 cout<<"\tPress 1 to see your Profile"<<endl;
   								 cout<<"\tPress 2 to Complaint to admin/officials"<<endl;
   								 cout<<"\tPress 3 to See Today's Food Menu "<<endl;
   								 cout<<"\tPress 0 to return"<<endl;

   								 ll xx;
   								 cin>>xx; getchar();
   								 system("clear");
   								 if(xx==1)
   								 {
   									 cout<<"------------------------------ Your Profile  -----------------------------------"<<endl<<endl;

   									 cur_ara[i]->get_data();

   									 cout<<"\tPress Enter to Continue......"<<endl;
   									 getchar();
   									 system("clear");

   								 }
   								 else if(xx==2)
   								 {

   									 cout<<"------------------------------- Complaint Box  ---------------------------------"<<endl<<endl;

   									 admin->set_complaint();

   									 cout<<"\tPress Enter to Continue......"<<endl;
   									 getchar();
   									 system("clear");
   								 }
   								 else if(xx==3)
   								 {
   									 cout<<"---------------------------------- Food Menu -----------------------------------"<<endl<<endl;
   									 food->get_data();

   									 cout<<"\tPress Enter to Continue......"<<endl;
   									 getchar();
   									 system("clear");
   								 }
   								 else if(xx==0)
   								 {
   									 break;
   								 }
   							 }
   							 break;
   						 }
   					 }
   					 if(flag==false)
   					 {
   						 cout<<"\tWrong ID or Pin!!"<<endl;
   						 cout<<"\tDo You Want to Try Again? (1->YES/2->NO)"<<endl;
   						 ll xx;
   						 cin>>xx; getchar();
   						 system("clear");
   						 if(xx==2)
   						 {
   							 break;
   						 }
   					 }
   					 else
   					 {

   						 break;
   					 }

   				 }

   			 }

   			 else if(ch==3)
   			 {
   				 ll id;
   				 ll pin;

   				 while(1)
   				 {
   					 cout<<"------------------------- Log In Section (Employee) ----------------------------"<<endl<<endl;

   					 cout<<"\tEnter Employee ID: "; cin>>id; getchar();
   					 cout<<"\tEnter Employee Pin: "; cin>>pin; getchar();
   					 system("clear");
   					 bool flag=false;
   					 for(ll i=0;i<emp_num;i++)
   					 {
   						 if(emp_ara[i]->return_id_number()==id&&emp_ara[i]->return_Pin_number()==pin)
   						 {
   							 flag=true;
   							 cout<<"\tLogged In as an Employee!!!!"<<endl;

   							 while(1)
   							 {
   								 cout<<endl;
   								 cout<<"------------------------ Employee Profile Dashboard ----------------------------"<<endl;

   								 cout<<endl;
   								 cout<<"\tPress 1 to see your Profile"<<endl;
   								 cout<<"\tPress 2 to Complaint to admin/officials"<<endl;
   								 cout<<"\tPress 0 to return"<<endl;
   								 ll xx;
   								 cin>>xx; getchar();

   								 system("clear");

   								 if(xx==1)
   								 {
   									 cout<<"------------------------------- Your Profile -----------------------------------"<<endl<<endl;

   									 emp_ara[i]->get_data();

   									 cout<<"\tPress Enter to Continue......"<<endl;
   									 getchar();
   									 system("clear");
   								 }
   								 else if(xx==2)
   								 {

   									 cout<<"------------------------------- Complaint Box ----------------------------------"<<endl<<endl;

   									 admin->set_complaint();


   									 cout<<"\tPress Enter to Continue......"<<endl;
   									 getchar();
   									 system("clear");
   								 }
   								 else if(xx==0)
   								 {
   									 break;
   								 }
   							 }
   							 break;
   						 }
   					 }
   					 if(flag==false)
   					 {
   						 cout<<"\tWrong ID or Pin!!"<<endl;
   						 cout<<"\tDo You Want to Try Again? (1->YES/2->NO)"<<endl;
   						 ll xx;
   						 cin>>xx; getchar();

   						 system("clear");

   						 if(xx==2)
   						 {
   							 break;
   						 }
   					 }
   					 else
   					 {
   						 break;
   					 }
   				 }
   			 }
            	else if(ch==0)
            	{
                	break;
            	}
            	else
            	{
                	cout<<"\tWrong Key!!!!!"<<endl;
                	cout<<"\tPlease Enter Correct Key!"<<endl;
            	}
        	}

    	}

    	else
    	{
        	cout<<endl;
        	cout<<"\tWrong Key!!!!"<<endl;
        	cout<<"\tPlease Enter Correct Key"<<endl;
        	cout<<endl<<endl;
    	}

	}
