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

//-----------------------------------------------
//               Class Declarations
//-----------------------------------------------

// Class below stores information about user entered grades
class Grades
{
  public:
  int length = 0;  // Length of array (needed to compute average & add values)
  double * array;  // Points to array of grades

  double average = 0.0;
  double returnAverage(double arr[], int size); // Returns average of array
  
  ~Grades() { delete[] array; array = NULL; }; // Deletes array at end of program
};

// Class below stores session information 
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
    //  Display formatted and includes user name and school ID #

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

    // Set user name and user ID
    newUser.setUserName(newUser.getUserName());
    newUser.setUserID(newUser.getUserID());

    cout << "How many grades would you like to enter?\n";
    cin >> userGrades.length;
    // Length used to initiate array below

  // Specification B1 - Dynamic Array
   userGrades.array = new double[userGrades.length];
 
  // Loop repeats to add all initial grades to array
    for (int i=0; i < userGrades.length; i++) {
        cout << "Please enter grade #" << i+1 << ":\n";
        cin >> userGrades.array[i];
    }

    cout << "Grades accepted.\n";

    // Loop below continues until user decides to end program
    // Selecting quit will change flag to 0
    while (newUser.sessionFlag == 1) {
      
      // Take user input below 
      newUser.userChoice = OptionMenu();

        // User selects option 1, "Add Grade"
        if (newUser.userChoice == 1) {

          // Specification B2 - Add Elements
          // Length is increased by one, and a new array is created with that length
          userGrades.length++;
          double * holderArr;
          holderArr = new double[userGrades.length];

          // Old array information is transferred to new array
          for (int i = 0; i < userGrades.length; ++i) {
            holderArr[i] = userGrades.array[i];
          }

          // Final element is assigned w/ the new grade
          cout << "Enter new grade: \n";
          cin >> holderArr[userGrades.length-1];

          // Original array is deleted, 
          delete[] userGrades.array;

          // and then recreated, using the new length
          userGrades.array = new double[userGrades.length];

          // Saved array elements are transferred back to original array
          for (int i = 0; i < userGrades.length; ++i) {
            userGrades.array[i] = holderArr[i];
          }

          // Placeholder array is deleted so it can be reused if
          //    new elements are added 
          delete[]holderArr;
          holderArr = NULL;

        }

        // User selects option 2, "Display All Grades"
        if (newUser.userChoice == 2) {
          DisplayGrades(newUser.userName, newUser.userID, userGrades.array, userGrades.length);
        }

        // User selects option 3, "Calculate Average"
        if (newUser.userChoice == 3) {
          DisplayAverage(userGrades.returnAverage(userGrades.array, userGrades.length), GradeGenerator(userGrades.returnAverage(userGrades.array, userGrades.length)));
        }

        // User selects option 4, "Quit Program"
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

  // Specification C3 - Letter Grades

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
  cout << "4. Quit Program\n" << endl;

  cin >> playerChoice;

  // Specification B3 - Menu Input Validation
  while (playerChoice > 4 || playerChoice < 1) {
    cout << "Please enter a valid selection from the menu.\n";
    cin >> playerChoice;
  }

  return playerChoice;
}

void DisplayGrades(string name, string number, double arr[], int length) {

  // Specification C2 - Print Scores
  cout << name << endl;
  cout << "(" << number << ")" << endl;
  cout << "SEMESTER GRADES\n";
  cout << "------------\n";

    for (int i=0; i < length; i++) {
      cout << (i+1) << ". ";
      // Spefification B4 - Print Leter Grade
      cout << arr[i] << "\t\t(" << GradeGenerator(arr[i]) << ") \n";
    } 
}

void DisplayAverage(double average, char letter) {

  // Specification C4 - Compute GPA
  cout << "Your grade average is " << average << " (" << letter << ").\n";

}