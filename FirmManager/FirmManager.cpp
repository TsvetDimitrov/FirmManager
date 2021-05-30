/**
* Създайте приложение, което дава информация за отделите и служителите в
дадена фирма.Да има възможност за избор на вида на фирмата (ООД, АД,
ЕООД и т.н.), както и да ли е регистрирана по ДДС или не.
Броят на отделите във фирмата да бъде произволен. За всеки отдел да се
представя информация за  наименованието на отдела, броят служители, от
колко време е създаден отдела. За служителите необходимата информация е
имена, ЕГН, трудов стаж, договор на колко часа е, в кои проекти участва.
Класовете (най-малко 3 класа при реализацията) трябва да капсулира
всичките детайли. Използват се private инстанции на променливите за
съхраняване на различните детайли. Трябва да има най-малко два
конструктора, public getters/setters за private инстанции на
променливите(30 точки).
Необходимо е да извършвате проверка на входните данни (10 точки).
  Да се предефинира операцията <<, която да се използва за извеждане на
данните (10 точки). Данните да се четат и съхраняват във файл (20
точки).
Класовете да се опишат с UML клас диаграма (10 точки).
  Задължително данните да се въвеждат динамично, чрез меню.

Да се изготви документация, която да се предаде по време на зашитата на
проекта!
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Time {
private:
    int years;
    int months;
    int days;
public:
    Time();
    Time(int years, int months, int days);
    int getYears();
    int getMonths();
    int getDays();
    void setYears(int years);
    void setMonths(int months);
    void setDays(int days);
    friend std::ostream& operator<<(std::ostream& os, const Time& time);

};

Time::Time() {
    std::cout << "Enter years:" << std::endl;
    std::cin >> this->years;
    std::cout << "Enter months:" << std::endl;
    std::cin >> this->months;
    std::cout << "Enter days:" << std::endl;
    std::cin >> this->days;
}

int Time::getYears() {
    return this->years;
}

int Time::getMonths() {
    return this->months;
}

int Time::getDays() {
    return this->days;
}

void Time::setYears(int years) {
    this->years = years;
}

void Time::setMonths(int months) {
    this->months = months;
}

void Time::setDays(int days) {
    this->days = days;
}

std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << time.years << ' ' << time.months << ' ' << time.days;
    return os;
}

class Employee {
private:
    int employeeDepartmentId; //for file navigation
    std::string employeeName;
    int egn;
    Time experience;
    int workingHoursPerDay;
    int numberOfProjects;
    std::vector<std::string> projectsPartTaken;
public:
    Employee();
    int getEmployeeDepartmentId();
    std::string getEmployeeName();
    int getEgn();
    Time getExperience();
    int getWorkingHoursPerDay();
    int getNumberOfProjects();
    std::vector<std::string>& getProjectsPartTaken();
    void setEmployeeDepartmentId(int employeeDepartmentId);
    void setEmployeeName(std::string employeeName);
    void setEgn(int egn);
    void setExperience(Time experience);
    void setWorkingHoursPerDay(int workingHoursPerDay);
    void setNumberOfProjects(int numberOfProjects);
    void setProjectsPartTaken(const std::vector<std::string>& projectsPartTaken);
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
};

Employee::Employee() {
    std::cout << "Enter employee's department id:" << std::endl;
    std::cin >> this->employeeDepartmentId;
    std::cout << "Enter employee name:" << std::endl;
    std::cin >> this->employeeName;
    std::cout << "Enter Employee EGN:" << std::endl;
    std::cin >> this->egn;
    std::cout << "Enter working hours per day:" << std::endl;
    std::cin >> this->workingHoursPerDay;
    std::cout << "Enter number of projects part taken in by the employee:" << std::endl;
    std::cin >> this->numberOfProjects;
    for (int i = 1; i <= numberOfProjects; i++) {
        std::string projectInput;
        std::cout << "Enter project number" << '[' << i << ']' << std::endl;
        std::cin >> projectInput;
        projectsPartTaken.push_back(projectInput);
    }
}

int Employee::getEmployeeDepartmentId() {
    return this->employeeDepartmentId;
}

std::string Employee::getEmployeeName() {
    return this->employeeName;
}

int Employee::getEgn() {
    return this->egn;
}

Time Employee::getExperience() {
    return this->experience;
}

int Employee::getWorkingHoursPerDay() {
    return this->workingHoursPerDay;
}

int Employee::getNumberOfProjects() {
    return this->numberOfProjects;
}

std::vector<std::string>& Employee::getProjectsPartTaken() {
    return this->projectsPartTaken;
}

void Employee::setEmployeeDepartmentId(int employeeDepartmentId) {
    this->employeeDepartmentId = employeeDepartmentId;
}

void Employee::setEmployeeName(std::string employeeName) {
    this->employeeName = employeeName;
}

void Employee::setEgn(int egn) {
    this->egn = egn;
}

void Employee::setExperience(Time experience) {
    this->experience = experience;
}

void Employee::setWorkingHoursPerDay(int workingHoursPerDay) {
    this->workingHoursPerDay = workingHoursPerDay;
}

void Employee::setNumberOfProjects(int numberOfProjects) {
    this->numberOfProjects = numberOfProjects;
}

void Employee::setProjectsPartTaken(const std::vector<std::string>& projectsPartTaken) {
    this->projectsPartTaken = projectsPartTaken;
}

std::ostream& operator<<(std::ostream& os, const Employee& employee) {
    os << "EmployeeDepartmentID: " <<employee.employeeDepartmentId << " EmployeeName: "<< employee.employeeName << " EmployeeEGN: " << employee.egn <<
        " EmployeeExperience(y/m/d): " << employee.experience << " EmployeeWorkHoursDaily: " << employee.workingHoursPerDay << " EmployeeNumberProjects: " << employee.numberOfProjects << " Name: ";
    for (std::vector<std::string>::const_iterator i = employee.projectsPartTaken.begin(); i != employee.projectsPartTaken.end(); ++i)
        os << "|" << *i << "|";
    return os;
}

class Department {
private:
    int departmentId;
    int firmId; //for file navigation
    std::string departmentName;
    int numberOfEmployees;
    Time timeSinceCreated;
public:
    Department(int departmentId, int firmId, std::string departmentName, int numberOfEmployees);
    std::string getDepartmentName();
    int getNumberOfEmployees();
    Time getTimeSinceCreated();
    int getDepartmentId();
    int getFirmId(); //for file navigation
    void setDepartmentName(std::string departmentName);
    void setNumberOfEmployees(int numberOfEmployees);
    void setTimeSinceCreated(Time timeSinceCreated);
    void setDepartmentId(int departmentId);
    void setFirmId(int firmId); //for file navigation
    friend std::ostream& operator<<(std::ostream& os, const Department& department);
};

Department::Department(int departmentId, int firmId, std::string departmentName, int numberOfEmployees) {
    this->departmentId = departmentId;
    this->firmId = firmId;
    this->departmentName = departmentName;
    this->numberOfEmployees = numberOfEmployees;
}

std::string Department::getDepartmentName() {
    return this->departmentName;
}

int Department::getNumberOfEmployees() {
    return this->numberOfEmployees;
}

Time Department::getTimeSinceCreated() {
    return this->timeSinceCreated;
}

int Department::getDepartmentId() {
    return this->departmentId;
}

int Department::getFirmId() {
    return this->firmId;
}

void Department::setDepartmentName(std::string departmentName) {
    this->departmentName = departmentName;
}

void Department::setNumberOfEmployees(int numberOfEmployees) {
    this->numberOfEmployees = numberOfEmployees;
}

void Department::setTimeSinceCreated(Time timeSinceCreated) {
    this->timeSinceCreated = timeSinceCreated;
}

void Department::setDepartmentId(int departmentId) {
    this->departmentId = departmentId;
}

void Department::setFirmId(int firmId) {
    this->firmId = firmId;
}
// Changes here
std::ostream& operator<<(std::ostream& os, const Department& department) {
    os << "FirmID: " <<department.firmId << " DepartmentID: " << department.departmentId << " DepartmentName: " << department.departmentName
        << " NumberOfEmployees: " << department.numberOfEmployees << " TimeSinceCreated(y/m/d): " << department.timeSinceCreated;
    return os;
}

class Firm {
private:
    int firmId;
    std::string firmName;
    bool isRegisteredForDDS;
public:
    Firm();
    Firm(int firmId, std::string firmName, bool isRegisteredForDDs);
    std::string getFirmName();
    bool getIsRegisteredForDDS();
    int getFirmId();
    void setFirmName(std::string firmName);
    void setIsRegisteredForDDS(bool isRegisteredForDDS);
    void setFirmId();
    friend std::ostream& operator<<(std::ostream& os, const Firm& firm);
};

Firm::Firm() {
    this->firmName = "";
    this->isRegisteredForDDS = false;
}

Firm::Firm(int firmId, std::string firmName, bool isRegisteredForDDs) {
    this->firmId = firmId;
    this->firmName = firmName;
    this->isRegisteredForDDS = isRegisteredForDDs;
}

std::string Firm::getFirmName() {
    return this->firmName;
}

bool Firm::getIsRegisteredForDDS() {
    return this->isRegisteredForDDS;
}

int Firm::getFirmId() {
    return this->firmId;
}

void Firm::setFirmName(std::string firmName) {
    this->firmName = firmName;
}

void Firm::setIsRegisteredForDDS(bool isRegisteredForDDS) {
    this->isRegisteredForDDS = isRegisteredForDDS;
}

void Firm::setFirmId() {
    this->firmId = firmId;
}

std::ostream& operator<<(std::ostream& os, const Firm& firm) {
    os << "ID: " << firm.firmId << ' ' << "FirmName: " << firm.firmName << ' ' << "isRegisteredForDDS: " << firm.isRegisteredForDDS;
    return os;
}

void addNewFirm();
void addNewDepartment();
void addEmployees();
void getFirmNames(std::vector<Firm>& names);
void getDepartments();
void getEmployees();
bool isUniqueFirmId(Firm object, std::string filename);
bool isUniqueDepartmentId(Department object, std::string filename);
bool isUniqueEmployeeEGN(Employee emp, std::string filename);
template <class T>
void appendFileWithObject(T object, std::string filename);
//1. Add new firm
//2. Get firm's departments
//3. Get department's employees
//4. Get firm's employees
//5. Add new department in a firm
//6. Add new employee
int main()
{
    std::cout << std::endl << "Make a choice:" << std::endl;
    std::cout << "Enter 1 - Add new firm" << std::endl;
    std::cout << "Enter 2 - Add departments to a firm." << std::endl;
    std::cout << "Enter 3 - Add employees to a firm's department." << std::endl;
    std::cout << "Enter 4 - Get firms names." << std::endl;
    std::cout << "Enter 5 - Get firm's departments." << std::endl;
    std::cout << "Enter 6 - Get department's employees." << std::endl;
    std::cout << "Enter 7 to exit" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1: {
        addNewFirm();
        break;
    }
    case 2: {
        addNewDepartment();
        break;
    }
    case 3: {
        addEmployees();
        break;
    }
    case 4: {
        std::vector<Firm> firmNames;
        getFirmNames(firmNames);
        for (Firm name : firmNames) {
            std::cout << name << std::endl;
        }
        break;
    }
    case 5: {
        getDepartments();
        break;
    }
    case 6: {
        getEmployees();
        break;
    }
    case 7: {
        exit(0);
    }
    }
    main();
}

void addNewFirm() {
    std::string userInput;
    std::cout << "Enter firm name" << std::endl;
    std::cin >> userInput;
jump:
    std::cout << "Is the firm registered for DDS? (yes or no)" << std::endl;
    std::string isRegisteredInput;
    std::cin >> isRegisteredInput;
    bool isRegistered;
    if (isRegisteredInput.compare("yes")) {
        isRegistered = false;
    }
    else if (isRegisteredInput.compare("no")) {
        isRegistered = true;
    }
    else {
        std::cout << "Wrong input! Try again" << std::endl;
        goto jump;
    }
jump2:
    std::cout << "Enter unique firm Id:" << std::endl;
    int firmId;
    std::cin >> firmId;
    Firm firm(firmId, userInput, isRegistered);
    bool isUnique = (firm, "firms.txt");
    if (!isUnique) {
        std::cout << "Entered id was not unique." << std::endl;
        goto jump2;
    }
    appendFileWithObject(firm, "firms.txt");
}
//Department(int departmentId, int firmId, std::string departmentName, int numberOfEmployees, Time timeSinceCreated)
void addNewDepartment() {
start:
    std::string departmentNameInput;
    std::cout << "Enter department name:" << std::endl;
    std::cin >> departmentNameInput;
    int departmentId;
    std::cout << "Enter department id:" << std::endl;
    std::cin >> departmentId;
    int firmId;
    std::cout << "Enter id of firm which this department belongs to:" << std::endl;
    std::cin >> firmId;
    int numberOfEmployees;
    std::cout << "Enter number of employees that work here:" << std::endl;
    std::cin >> numberOfEmployees;
    std::cout << "Enter period of existence of this department:" << std::endl;
    Department dep(departmentId, firmId, departmentNameInput, numberOfEmployees);
    bool isUniqueDepId = isUniqueDepartmentId(dep, "departments.txt");
    if (!isUniqueDepId) {
        std::cout << "Duplicate department id, please try again..." << std::endl;
        goto start;
    }
    appendFileWithObject(dep, "departments.txt");
}

void addEmployees() {
    std::cout << "Enter number of employees to be added:" << std::endl;
    int numberOfEmployees;
    std::cin >> numberOfEmployees;
    for (int i = 1; i <= numberOfEmployees; i++) {
        std::cout << "Enter employee's experience:" << std::endl;
        Employee employee;
        if (!isUniqueEmployeeEGN(employee, "employees.txt")) {
            std::cout << "An employee with that egn already existed. Skipping.." << std::endl;
            continue;
        }
        appendFileWithObject(employee, "employees.txt");
    }
}
// 4Function Not Uploaded.
void getFirmNames(std::vector<Firm>& names) {
    std::ifstream infile;
    infile.open("firms.txt", std::ios::in);
    if (infile.fail()) {
        std::cout << "File was not found\n";
        system("PAUSE");
        exit(1);
    }

    int id;
    std::string firmName;
    int isRegisteredForDDS;
    std::string ignored;
    while (infile >> ignored >> id >> ignored >> firmName >> ignored >> isRegisteredForDDS) {
        Firm firm(id, firmName, isRegisteredForDDS);
        names.push_back(firm);
    }

    infile.close();
}

//5 Function not Uploaded.
void getDepartments() {
    std::ifstream infile;
    infile.open("departments.txt", std::ios::in);
    if (infile.fail()) {
        std::cout << "File was not found\n";
        system("PAUSE");
        exit(1);
    }
    int departmentID;
    int firmID;
    std::string departmentName;
    std::string ignored;
    std::vector<int> departments;
    std::cout << "Enter number of firmID to be checked." << std::endl;
    int firmIDtoCheck;
    std::cin >> firmIDtoCheck;
    while (infile >> ignored >> firmID >> ignored >> departmentID >> ignored >> departmentName >> ignored) {
        if (firmID == firmIDtoCheck) {
            departments.push_back(departmentID);
        }
    }
    

    if (departments.size() != 0) {
        std::cout << "DepartmentsID's related to checkedFirm are: ";
        for (auto i = departments.begin(); i != departments.end(); ++i) {
            std::cout << *i << " ";
        }
    }
    else {
        std::cout << "Given number of firmID or department does not exist." << std::endl;
    }    
    infile.close();
}

//6 Function not uploaded.
void getEmployees() {
    std::ifstream infile;
    infile.open("employees.txt", std::ios::in);
    if (infile.fail()) {
        std::cout << "File was not found\n";
        system("PAUSE");
        exit(1);
    }
    std::cout << "Enter departmentID to get the all Employees" << std::endl;
    int depId;
    std::cin >> depId;
    std::vector<std::string> workers;
    std::string ignored;
    int depIdToCheck;
    std::string workerName;
    int egn;
    while (infile >> ignored >> depIdToCheck >> ignored >> workerName >> ignored >> egn >> ignored) {
        if (depId == depIdToCheck) {
            workers.push_back(workerName);
        }
    }

    if (workers.size() != 0) {
        std::cout << "Workers related to this department are: ";
        for (auto i = workers.begin(); i != workers.end(); ++i) {
            std::cout << *i << " ";
        }
    }
    else {
        std::cout << "Given number of departmentID does not exist or does not have any workers yet." << std::endl;
    }
    infile.close();
}

template <class T>
void appendFileWithObject(T object, std::string filename) {
    std::ofstream outfile;
    outfile.open(filename, std::ios::app);
    if (outfile.fail()) {
        std::cout << "File was not found\n";
        system("PAUSE");
        exit(1);
    }
    outfile << object << std::endl;
    outfile.close();
}

bool isUniqueEmployeeEGN(Employee emp, std::string filename) {
    std::ifstream infile;
    infile.open(filename, std::ios::in);
    if (infile.fail()) {
        std::cout << "File was not found\n";
        system("PAUSE");
        exit(1);
    }
    std::string ignore;
    int departmentId;
    std::string employeeName;
    int egn;
    int years;
    int months;
    int days;
    int workingHoursPerDay;
    int numberOfProjects;
    std::string temp;
    std::vector<std::string> projects;
    while (infile >> ignore >> departmentId >> ignore >> employeeName >> ignore >> egn >> ignore >> years >> months >> days >> ignore >> workingHoursPerDay >> ignore >> numberOfProjects) {
        for (int i = 0; i < numberOfProjects; i++) {
            infile >> temp;
            projects.push_back(temp);
        }
        if (egn == emp.getEgn()) {
            return false;
        }
    }
    infile.close();
    return true;
}

bool isUniqueDepartmentId(Department dep, std::string filename) {
    std::ifstream infile;
    infile.open(filename, std::ios::in);
    if (infile.fail()) {
        std::cout << "File was not found\n";
        system("PAUSE");
        exit(1);
    }
    std::string ignore;
    int departmentId;
    int firmId;
    std::string departmentName;
    int numberOfEmployees;
    int years;
    int months;
    int days;
    while (infile >> ignore >> firmId >> ignore >> departmentId >> ignore >> departmentName >> ignore >>
        numberOfEmployees >> ignore >> years >> months >> days) {
        if (departmentId == dep.getDepartmentId()) {
            infile.close();
            return false;
        }
    }
    infile.close();
    return true;
}

bool isUniqueFirmId(Firm object, std::string filename) {
    std::ifstream infile;
    infile.open(filename, std::ios::in);
    if (infile.fail()) {
        std::cout << "File was not found\n";
        system("PAUSE");
        exit(1);
    }
    std::string ignore; //remove if it does not work. 
    int firmId;
    std::string firmName;
    bool isRegisteredForDDS;
    while (infile >> ignore >> firmId >> ignore >> firmName >> ignore >> isRegisteredForDDS) {  //while (infile >> firmId >> firmName >> isRegisteredForDDS)
        if (firmId == object.getFirmId()) {
            infile.close();
            return false;
        }
    }
    infile.close();
    return true;
}