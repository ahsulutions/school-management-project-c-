#include<iostream>
#include<fstream>
using namespace std;

struct school{
	string studentdata[100][3];
};
school manage;


void enterStudentdata(int newadd){
	ofstream trFileO("school.txt");
	
	for(int i=0;i<newadd;i++){
		for(int j=0;j<3;j++){
			if(j==0)
				cout<<"\t\t\tEnter student Roll no: ";
			else if(j==1)
				cout<<"\t\t\tEnter student name: ";
			else
				cout<<"\t\t\tEnter student class: ";
			cin>>manage.studentdata[i][j];
		}
	}
	trFileO<<"\n\t\t\tStudent Roll no   Student name  Student class\n";
	for(int i=0;i<newadd;i++){
		for(int j=0;j<3;j++){
			if(j==0){
				trFileO<<"\t\t\t ";
			}
			trFileO<<manage.studentdata[i][j]<<"\t\t   ";
		}
		trFileO<<endl;
	}
	trFileO.close();
}

void viewStudentdetail(){
	char line[100];
	ifstream trFilef("school.txt");

		while(!trFilef.eof())
		{
			trFilef.getline(line,100); 
			cout<<line<<endl;
		}
		trFilef.close();
}

void searchStudentdetail(string rollnumber){
	char line[100];
	string rollno;
	ifstream trFilef("school.txt");

		 int curLine = 0;
		while(getline(trFilef, rollno)) 
		{ 	
		curLine++;
    		if (rollno.find(rollnumber, 0) != string::npos) 
			{// I changed this, see below
    		
    		cout<<"\n\t\t\tStudent Roll no   Student name  Student class\n";
				cout<<rollno;
				
        		cout << "found rollno: " << rollnumber << "line: " << curLine << endl;
    		}
		}
		
	trFilef.close();
	
}
int main(){
	int totalnewadmissions;
	char option;
	string search;
	cout<<"\n\n\n\t\t\t*******************************************************\n";
	cout<<"\t\t\t  ************AH School Management System************\n";
	cout<<"\t\t\t*******************************************************\n";
	cout<<"\n\n\t\t\t-----------------------------------\n";
	cout<<"\t\t\t| Press 1 to add new student data |\n";
	cout<<"\t\t\t| Press 2 to view student data	  |\n";
	cout<<"\t\t\t| Press 3 to search student data  |\n";
	cout<<"\t\t\t| Press 4 to Quit	  	  |\n";
	cout<<"\t\t\t-----------------------------------\n";
	cout<<"\n\t\t\tEnter one of above option: ";
	cin>>option;
	switch(option){
		case '1':
		{
			cout<<"\t\t\tEnter the total new admissons:";
			cin>>totalnewadmissions;
			cout<<endl;
			enterStudentdata(totalnewadmissions);
			cout<<"\t\t\tWould you like you view the data(y/n)";
			cin>>option;
			if(option=='1')	
				break;
		}
		case '2':
		{
			if(option=='y'||option=='2'){
				viewStudentdetail();
			}
			break;
		}
		case '3':
		{
			cout<<"Enter student by roll number: ";
			cin>>search;
			searchStudentdetail(search);
			break;
		}
			
	}
	
	
	
}
