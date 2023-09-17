#include <iostream>
#include <fstream>
using namespace std;

class Employee{
    int employeeId;
    string name;
    double salary;
    float weeklyWage;
    string position;

public:
 void setEmployeeDetails(int id,string n,float h,string pos){
     employeeId=id;
      name=n;
    weeklyWage = h * 7;
     salary= weeklyWage*4;
     position = pos;


} 
void displayEmployeeDetails() {
    cout<<"Employee ID:"<<employeeId<<endl;
    cout<<"Employee Name:"<<name<<endl;
    cout<<"Employee position: "<<position<<endl;
    cout <<"Weekly wage: "<<weeklyWage << " Birr" <<endl;
    cout<<"Monthly wage:"<<salary<< " Birr" <<endl;
    cout<<endl;

}
float tax(){
    float tax;
    if (salary<3201) {
        tax = 0;
       
    }

   else if(salary>=3201 && salary<=5250) {
        tax = salary*.2;
        }
     else if (salary>=5251 && salary<=7800) {
         tax = salary*.25;
         
          }
      else if (salary>=7801 && salary<=10900) {
        tax = salary*.3;
        
      }   
      else if (salary>=10901) {
        tax = salary*.35;
    
      }
return tax;      
}

float pension() {
  float pension;
  pension = salary*.07;
  return pension;
}
float netsalary(){
    float netsalary;
    netsalary=salary-tax()-pension();
    return netsalary;
}
void addEmployeeToFile() {
    ofstream file("employees.txt", ios::app);
    file <<"Employee Id : " << employeeId<< "\n"
     << "Employee Name : " << name << "\n"
     << "Employee Position : " << position <<endl
     << " Employee Salary : " << salary <<"\n"
     << "Weekly wage : " << weeklyWage << endl
     << "Tax : " << tax() <<endl 
     << "Pension : " << pension() << endl
     << "Net salary : " << netsalary() << endl
     << "------------------------------------------"<<endl;
    file.close();

}

void displayAllEmployees() {
    ifstream file("employees.txt");
    string line;
    
    while (getline(file, line)){
            cout << line<<endl;
        }
    
    file.close();
}
};

int main() {
    Employee emp;
    int choice, id, hourPerDay;
    string name;
    float product;
    double salary;
    string possblepositons[6] {"acountant", "security","maintainance","janitor","boss"};
    string position;
    int input;
    ifstream fileIn;

    while (1) {
        cout << "Payroll System Menu\n";
        cout << "1. Add New Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Exit\n";

        cout << "Please Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter employee Name: ";
                cin >> name;
                label:
                cout << "choose Employment postion"<<endl;
                cout << "1.acountant    2.security   3.Maintainance   4.Janitor   5.Boss"<<endl;
                cin>>input;
                if (input > 5 || input < 1){
                cout <<"There is no position in that number try again!"<<endl;
              goto label;
                }
                position = possblepositons[input-1];
                cout << "Enter employee salary per hour: ";
                cin >> salary;
                cout << "How many hours per day: ";
                cin >> hourPerDay;
                cout<<endl;
                cout<<"<----------Employee's Info--------->"<<endl;
                product = salary*hourPerDay;
                emp.setEmployeeDetails(id, name, product,position);
                emp.displayEmployeeDetails();
                cout<<"Tax : "<<emp.tax() << " Birr"<<endl;
                cout<<"Pension : "<<emp.pension() << " Birr"<<endl;
                cout << "Net salary: " << emp.netsalary() << " Birr"<< "\n\n";
                emp.addEmployeeToFile();
                break;

            case 2:
                emp.displayAllEmployees();
                
                break;

            case 3:
                exit(0);

            default:
                cout << "Invalid choice\n";
                break;
        }
    }
    

    return 0;
}




