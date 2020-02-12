// GPA.cpp 
// 2/17/2020	
// Brittany Wilson (W1811883)
// CISP 400 

#include <iostream>	
#include <array>
using namespace std;

// Global Variables
// ----------------

  // Costants below allow program to easily adjust for alternative
  //   grading scales, assuming they use A, B, C, D, February
  //   F not declared, as anything failing to reach a D is an F   
  const double A_MIN = 90;
  const double B_MIN = 80;
  const double C_MIN = 70;
  const double D_MIN = 60; 
// end global variables

class Grades
{
  public:
  int length = 0;
  double * array;

  double average = 0.0;
  double returnAverage(double arr[], int size);
  
  ~Grades() { delete[] array; };
};

class User 
{
    public:
    string userName;
    string userID;
    int sessionFlag = 1;
    int userChoice = 0;
    void setUserName(string name) { userName = name; };
    void setUserID(string idNumber) { userID = idNumber; };
    string getUserName();
    string getUserID();

};

//----------------------------------------------
//                Class Functions
//-----------------------------------------------

// Function below prompts user to enter a name
string User::getUserName() {
    string name = "Joe-Bob Johnson";
    cout << "Please enter your name: \n";
    getline(cin, name);
    return name;
}
// Funvtion below prompts user to enter a student ID
string User::getUserID() {
    string studentID = "0000000";
    cout << "Please enter your school ID #: \n";
    cin >> studentID;
    return studentID;
}
// Gets the average of our array of grades 
double Grades::returnAverage(double *arr, int size) {
  double sum = 0;
  double average = 0.0;

  for (int i = 0; i<size; ++i) {
    sum = sum + arr[i];
  }

  average = sum / size;

  return average;
}

// --------------------------
//    Function Prototypes 
// --------------------------

    void ProgramGreeting();
    // 	Introduces the program & programmer

    void Unittest();		

    void TitleScreen();
    //  Generates a decorative title screen 
    //    introducing the program 

    char GradeGenerator(double score);
    //  Converts a numeric score to a letter grade 
    //  Assumes constants 

    int OptionMenu();
    //  Prompts user to select from a menu of options 
    //  Returns answer as int (as labeled in menu) 

    void DisplayGrades(string name, string number, double arr[], int length);
    //  Displays all grades entered

    void DisplayAverage(double average, char letter);
    
// end function prototypes

// -----------------------------------------------
//                 Main Program
// -----------------------------------------------

int main() {
	ProgramGreeting();	
	Unittest();		
    TitleScreen();

    User newUser;	
    Grades userGrades;

    newUser.setUserName(newUser.getUserName());
    newUser.setUserID(newUser.getUserID());

    cout << "How many grades would you like to enter?\n";
    cin >> userGrades.length;

    userGrades.array = new double[userGrades.length];
 
    for (int i=0; i < userGrades.length; i++) {
        cout << "Please enter grade #" << i+1 << ":\n";
        cin >> userGrades.array[i];
    }

    cout << "Grades accepted.\n";

    while (newUser.sessionFlag == 1) {
      
      newUser.userChoice = OptionMenu();

      if (newUser.userChoice == 2) {
        DisplayGrades(newUser.userName, newUser.userID, userGrades.array, userGrades.length);
      }

      if (newUser.userChoice == 3) {
         DisplayAverage(userGrades.returnAverage(userGrades.array, userGrades.length), GradeGenerator(userGrades.returnAverage(userGrades.array, userGrades.length)));
      }

      if (newUser.userChoice == 4) {
        cout << "Goodbye.";
        newUser.sessionFlag = 0;
      }

    }

  return 0;
}

// Modular Functions
// -----------------

void ProgramGreeting() {

  // Specification C1 - Program Greeting Function
  cout << "Welcome to my GPA calculator.\n";
  cout << "Programmed by Brittany Wilson. (brittany.inbox@gmail.com)\n";
  cout << "Due February 17, 2020.\n";

}

void TitleScreen() {

    cout << endl;
    cout << "-----------------------------------------------------\n";
    cout << "-----------------------------------------------------\n";
    cout << "   ----------   G P A    CALCULATOR   ----------      \n";    
    cout << "-----------------------------------------------------\n";
    cout << "-----------------------------------------------------\n\n\n";

}

void Unittest() {
// All test code here
}

char GradeGenerator(double score) {

  // Function can take scores > 100
  //   and scores them "A". 

  double points = score;
  char grade = 'A';

  if (score < D_MIN) {
    grade = 'F';
  } else if (score < C_MIN) {
    grade = 'D';
  } else if (score < B_MIN) {
    grade = 'C';
  } else if (score < A_MIN) {
    grade = 'B';
  }

  return grade;
}

int OptionMenu() {

  int playerChoice = 0;

  cout << "\nMain Menu" << endl;
  cout << "----------------------" << endl;
  cout << "1. Add Grade" << endl;
  cout << "2. Display All Grades" << endl;
  cout << "3. Calculate Average" << endl;
  cout << "4. Quit\n" << endl;

  cin >> playerChoice;

  while (playerChoice > 4 || playerChoice < 1) {
    cout << "Please enter a valid selection from the menu.\n";
    cin >> playerChoice;
  }

  return playerChoice;
}

void DisplayGrades(string name, string number, double arr[], int length) {

  cout << name << endl;
  cout << "(" << number << ")" << endl;
  cout << "SEMESTER GRADES\n";
  cout << "------------\n";

    for (int i=0; i < length; i++) {
      cout << (i+1) << ". ";
      cout << arr[i] << "\t\t(" << GradeGenerator(arr[i]) << ") \n";
    } 
}

void DisplayAverage(double average, char letter) {

  cout << "Your grade average is " << average << " (" << letter << ").\n";

}