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


// Bi-directional Association [multiplicity eka classes dekema 0..*]
class Student;
class Department;

class Student {
private:
  string name_p;
  Department *dep[2];

public:
  Student() {}
  Student(string pname, Department *pdep1) {
    name_p = pname;
    dep[0] = pdep1;
  }
  void sName() { cout << name_p << endl; }
};

class Department {
private:
  string depName;
  Student *std[2];

public:
  Department() {}
  Department(string pdepName, Student *pstd1, Student *pstd2) {
    depName = pdepName;
    std[0] = pstd1;
    std[1] = pstd2;
  }
  void dName() {}
  void Display() {
    cout << "Department Name : " << depName << endl;
    cout << "Student Names:-" << endl;
    for (int i = 0; i < 2; i++) {
      std[i]->sName();
    }
    cout << endl;
  }
};



// Uni-directional Association
class Employee {
    
};




int main() {

  // Inheritance
  Car *c1 = new Car(134, "TOYOTA", "Axio");
  c1->Display();

  cout << endl;




  // Assiosiation

  /*  Assiosiation eke class dekatama multiplicity eka 0..* nam issella ewage
   * objects hadaganna one naththan kelawenawa eg. Student *s1 = new Student();
   * Ehema hadaganna nam aniwarenma defualt constructor ekak hadagena thiyenna
   * one. Itapasse object walata values add karaddi depend wenna class eke object ekata data insert karagena inna       one naththan print wenne na (methananam Student) */

  Student *s1 = new Student();
  Student *s2 = new Student();
  Department *dep1 = new Department();

  s1 = new Student("Kamal", dep1);
  s2 = new Student("Nimal", dep1);

  dep1 = new Department("dep1", s1, s2);
  dep1->Display();

  return 0;
}
