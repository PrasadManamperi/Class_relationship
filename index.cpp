#include <iostream>
using namespace std;
#define SIZE 2

// Inheretence
class vehicel {
protected:
  string brand;
  string brclc;

public:
  vehicel() {
    brand = "";
    brclc = "";
  }
  vehicel(string pbrand, string pbrclc) {
    brand = pbrand;
    brclc = pbrclc;
  }
};

class Car : public vehicel {
private:
  int vhNo;

public:
  Car() { vhNo = 0; }
  Car(int pvhNo, string pbrand, string pbrclc) : vehicel(pbrand, pbrclc) {
    vhNo = pvhNo;
  }
  void Display() { cout << brand << endl << brclc << endl << vhNo << endl; }
};



// Uni-directional Association
class Employee {
    private:
      string empID;
      string name;
    public:
      Employee(string pempID, string pname) {
        empID = pempID;
        name = pname;
      }
      void displayEmployee(){
        cout << "Employee Name : " << name << endl;
        cout << "Employee ID : " << empID << endl;
      }
      ~Employee(){
        cout << "Deleting Employee " << empID << endl;
      }
};

class Department {
  private:
    string deptID;
    string depName;
    Employee *emp[SIZE];

  public:
    Department(string pdeptID, string pdepName, Employee *emp1, Employee *emp2) {
      deptID = pdeptID;
      depName = pdepName;
      emp[0] = emp1;
      emp[1] = emp2;
    }
    void displayDepartment() {
      cout << "Department Details : " << deptID << " - " << depName << endl;
      cout << "**************" << endl;
      cout << "Employee Details : " << endl;
      // godak employee la inna nisa loop ekak through ganna one.
      for (int i = 0; i < SIZE; i++) {
        emp[i]->displayEmployee();
        cout << endl;
      }
    }
    ~Department() {
      cout << "Department Deleted " << deptID << endl;
    }
};

//Bi-directional Association
class Order; // bi-directional ekedi class dekama kalin declare karannaone (Forward declaration)
class Customer;

class Order {
  private:
    string ordID;
    Customer *cust;
  public:
    Order(string pordID, Customer *pcust) {
      ordID = pordID;
      cust = pcust;
      cust->addOrders(this);
    }
    void displayOrder() {
      cout << "Order ID : " << ordID << endl;
    }
    ~Order(){
      cout << "Order Deleted " << ordID << endl;
    }
};

class Customer {
  private:
    string custID;
    string custName;
    Order *ord[SIZE];
    int noOfOrders = 0;
  public:
    Customer() {}
    Customer(string pcustID, string pcustName) {
      custID = pcustID;
      custName = pcustName;
    }
    void addOrders(Order *pord) {
      if ( noOfOrders < SIZE ) 
        ord[noOfOrders] = pord;
      noOfOrders++;
    }
    void displayCustomer() {
      cout << "Customer ID : " << custID << " - " << custName << endl;
      for ( int i = 0; i < SIZE; i++ ) {
       ord[i]->displayOrder();
      }
    }
    ~Customer() {
      cout << "Customer Deleted " << custID << endl;
    }
};




int main() {

  // Inheritance
  Car *c1 = new Car(134, "TOYOTA", "Axio");
  c1->Display();

  cout << endl << "-----------------------------" << endl;



  // Uni-direction Assiosiation
  Employee *emp1 = new Employee("E001", "Athula");
  Employee *emp2 = new Employee("E002", "Sannasgala");

  Department *dep1 = new Department("D001", "HR", emp1, emp2);
  dep1->displayDepartment();

  delete dep1; //delete the dinamic memory 

  
   cout << endl << "-----------------------------" << endl;
  //Bi-directional Assiosiation

  return 0;
}
