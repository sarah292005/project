#include<iostream>
using namespace std;
class employee{
	private:
		string empname;
		string pos;
		int age;
		int dept;
		double salary;
		int attendance;
		int id;
	public:
		static int empid;
	employee(double sal=0,string name=" ",string position=" ",int age=0,int department=0):salary(sal),empname(name),pos(position),age(age),dept(department){
	id=empid++;
	}
	
	void input(){
		cout<<"enter the employee name:"<<endl;
		cin>>empname;
		cout << "\n";
		cout<<"enter the position(a=assistant,b=assosciate)"<<endl;
		cin>>pos;
		cout << "\n";
		cout<<"enter the years of experiance:"<<endl;
		cin>>age;
		cout << "\n";
		cout<<"enter the department(1.dept of computerscience,2.dept of commerce,3.dept of business management,4.dept of lifescience)"<<endl;
		cin>>dept;
	}

void display(){
	cout<<"\n";
	cout<<"the id of the employee:"<<id<<endl;
	cout << "\n";
	cout<<"the name of the employee:"<<empname<<endl;
	cout << "\n";
	cout<<"the position of the employee:"<<pos<<endl;
		if(pos=="A" || pos=="a"){
			cout<<"position: assistant"<<endl;
		}
		else if(pos=="b"|| pos=="B"){
			cout<<"position: assosciate"<<endl;
		
		}
		else{
			cout<<"wrong alphabet"<<endl;
		}
	cout << "\n";
	cout<<"years of experiamce:"<<age<<endl;
	cout << "\n";
	cout<<"your department is:"<<dept<<endl;
	if(dept==1){
			cout<<"dept of computer science"<<endl;
		}
		else if(dept==2){
			cout<<"dept of commerce"<<endl;
		}
		else if(dept==3){
			cout<<"dept of buisness management"<<endl;
		}
		else if(dept==4){
			cout<<"dept of lifescience"<<endl;
		}
		else{
			cout<<"wrong no"<<endl;
		}
    cout<<"your salary is:"<<salary<<endl;
	
}
friend void calsalary(employee &emp);
friend void leave(employee &l);
		
};
int employee::empid = 0;
void calsalary(employee &emp){
	if(emp.pos=="a" || emp.pos=="A"){
		cout<<"the basic salary for assistant proffesor starts from rs.25000"<<endl;
		emp.salary=(emp.age*10000)+25000;
		cout<<"your total salary is:"<<emp.salary<<endl;
	}
	else{
		cout<<"the basic salary for assosciate professor starts from 50000"<<endl;
		emp.salary=(emp.age*15000)+50000;
		cout<<"your total salary is:"<<emp.salary<<endl;
	}
}
void leave(employee &l){
	cout<<"enter your no of leave days: ";
		cin>>l.attendance;
		double deduction=0.0;
		if (l.attendance>=0 && l.attendance<10){
			cout<<"youll have no salary deduction"<<endl;
		}
		else if (l.attendance>=10 && l.attendance<20){
	    double deduction = 1000; 
        l.salary-= deduction;   
        cout << "You will have a " << deduction << " Rs deduction in your salary." <<endl;
        cout << "Your new salary after deduction: " << l.salary<<endl;
    }
    else {
        cout << "Kindly meet the HOD of your department." <<endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of employees whose details you want to update: ";
    cin >> n;
    employee* employees = new employee[n];
    for(int i=0;i<n;i++){
        cout << "\nEnter details for Employee " << i + 1 << ":\n";
        employees[i].input();  
        calsalary(employees[i]);  
        leave(employees[i]);  
		employees[i].display();  
    }                            

    delete[] employees;    
	return 0;
}