#include <iostream>

#include <string.h>

using namespace std;

// let's do the classic employee class
class Employee {
  private:
    char * name;
  int salary, yearsWorked, id;

  public:
    Employee(char * nameIn) { // constructor
      name = new char[sizeof(strlen(nameIn))];
      strcpy(name, nameIn);
      salary = yearsWorked = id = 0;
    };
  ~Employee() { // destructor
    delete[] name;
  };

  /* setters and getters */

  char * getName();
  int getSalary();
  int getYearsWorked();
  int getId();

  void setName(char * newName);
  void setSalary(int newSalary);
  void setYearsWorked(int newYears);
  void setId(int newId);
};

char * Employee::getName() {
  return name;
}

int Employee::getSalary() {
  return salary;
}

int Employee::getYearsWorked() {
  return yearsWorked;
}

int Employee::getId() {
  return id;
}

void Employee::setName(char * newName) {
  name = new char[strlen(newName)];
  strcpy(name, newName);
}

void Employee::setSalary(int newSalary) {
  salary = newSalary;
}

void Employee::setYearsWorked(int newYears) {
  yearsWorked = newYears;
}

void Employee::setId(int newId) {
  id = newId;
}

int main(void) {
  // lets make an employee
  Employee alex("alex");
  alex.setName("Alex");
  alex.setSalary(25);
  alex.setYearsWorked(1);
  alex.setId(0001);

  cout << "employee named " << alex.getName() << "| salary: " << alex.getSalary() <<
    "| years worked: " << alex.getYearsWorked() << "| id number: " << alex.getId();

  return 0;
}
