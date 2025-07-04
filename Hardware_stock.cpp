#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct tool {
    string name;
    int quantity;
    float cost;
};
int count_record(){
	ifstream read;
	read.open("hardware_stock.txt");;
	string record;
	int count =0;
	while(getline(read,record)){
		count++;
	}
	return count;
}
void input_data(){
	int existcount=count_record();
	ofstream write;
	write.open("hardware_stock.txt",ios::app);
	int size;
	cout<<"Enter the number of items you want to insert in record"<<endl;
	cin>>size;
	cin.ignore();
	tool*t =new tool[size];
	for(int i=0; i<size; i++){
		cout<<"enter tool name"<<endl;
		getline(cin,t[i].name);
		cout<<"enter quantity"<<endl;
		cin>>t[i].quantity;
		cin.ignore();
		cout<<"enter cost"<<endl;
		cin>>t[i].cost;
		cin.ignore();
	    write<<"record no. "<<existcount+i+1<<"\t\t"<<"your name =>"<<t[i].name<<"\t\t"
		<<"your quantity => "<<t[i].quantity<<"\t\t"
		<<"your cost => "<<t[i].cost<<endl;
    }
    cout<<"data entered successfully"<<endl;
    write.close();
    count_record();
    delete[] t;
}
void view_record(){
	ifstream read;
	read.open("hardware_stock.txt");
	string record;
	cout<<"-------Your record--------"<<endl;
	while(getline(read,record)){
		cout<<record<<endl;
	}
}
void delete_record(){
	ifstream read;
	read.open("hardware_stock.txt");
	ofstream secondfile;
	secondfile.open("deleted_hardware.txt");
	int delete_record_number;
	cout<<"Enter the record number you want to delete"<<endl;
	cin>>delete_record_number;
	int current_line=1;
	string record;
	while(getline(read,record)){
		if(current_line!=delete_record_number){
		secondfile<<record<<endl;
	}
	current_line++;
}
read.close();
secondfile.close();
remove("hardware_stock.txt");
rename("deleted_hardware.txt","hardware_stock.txt");
}
void update_record(){
	tool t;
	ifstream read;
	read.open("hardware_stock.txt");
	ofstream thirdfile;
	thirdfile.open("update_hardware.txt");
	int update_record_number;
	cout<<"enter the record number you want to update"<<endl;
	cin>>update_record_number;
	int current_line=1;
	string record;
	cin.ignore();
	while(getline(read,record)){
		if(current_line==update_record_number){
		cout<<"enter update tool name"<<endl;
		getline(cin,t.name);
		cout<<"enter quantity"<<endl;
		cin>>t.quantity;
		cin.ignore();
		cout<<"enter cost"<<endl;
		cin>>t.cost;
		cin.ignore();
	    thirdfile<<"record no. "<<current_line<<"\t\t"<<"your name =>"<<t.name<<"\t\t"<<
	    "your quantity => "<<t.quantity<<"\t\t"
		<<"your cost => "<<t.cost<<endl;
	}else{
		thirdfile<<record<<endl;
	}
	current_line++;
}
read.close();
thirdfile.close();
remove("hardware_stock.txt");
rename("update_hardware.txt","hardware_stock.txt");
}
int main(){
	cout<<"--------- WELCOME TO HARDWARE STOCK MANAGEMENT SYSTEM ---------"<<endl;
	int choice;
	do{
	cout<<"choose your required option"<<endl;
	cout<<"1. For add hardware stock\t\t"<<"2. For view hardware stock"<<endl;
	cout<<"3. For delete hardware stock\t\t"<<"4. For update hardware stock\t\t"<<endl;
	cout<<"5. For exiting"<<endl;
	cout<<"enter the choosing no 1-5"<<endl;
	cin>>choice;
	cin.ignore();
	switch(choice){
		case 1:
    input_data();
    break;
        case 2:
    view_record();
    break;
        case 3:
    delete_record();
    break;
    case 4:
    update_record();
    break;
        case 5:
    cout<<"exiting program"<<endl;
    return 0;
    break;
    default:
    cout<<"invalid choice:"<<endl;
    return 0;
}
}while(choice!=5);
    return 0; 
}

