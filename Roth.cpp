#include <iostream>
#include <stdio.h>

using namespace std;

// Project: ROTH IRA Simulator
// This Project will allow the user to check balance of their ROTH IRA account, buy, and sell stocks. 

class MyClass {
  public:
    void getBalance(double balance, double shares[]) {
    cout << "Total balance is: $" + to_string(balance);
    cout << "\n You currently own " << shares[0] << " Tesla stock";
    cout << "\n You currenty own " << shares[1] << " Microsoft stock";
    cout << "\n You currently own " << shares[2] << " Bank of America stock";
    }
};

int main() {
	MyClass obj;
	double invest=0;
	double balance = 5000;
	string option = "0";
        double sell = 0;
	double shares[3] = {0, 0, 0};
	double stockPrices [3] = {710.32, 273.23, 37.00};
	string user="";
	string password="";

	cout << "Enter your user: ";
	cin >> user;
	cout << "Enter your password: ";
	cin >> password;

	cout << "Welcome, " + user + " ";
	cout << "\n IRA Options available below:";

	while (option != "exit") {
        
        
        cout << "\n 1) Check your balance";
	cout << "\n 2) Buy stock";
        cout << "\n 3) Sell stock";
	cout << "\n \n Type exit to logout \n";  
	cin >> option;

		if (option == "1") {
   		 cout << "Checking Balance...";
   		 obj.getBalance(balance, shares);
 		}
		if (option == "2") {
                 cout << "Choose available stock below: \n";
                 cout << "\n 1) TESLA " << stockPrices[0];
                 cout << "\n 2) Microsoft " << stockPrices[1];
	 cout << "\n 3) Bank of America " << stockPrices[2] <<  "\n";
                 cin >> option;
		 if (option == "1" || option == "2" || option == "3") {
		  cout << "How much do you want to invest? You currently hold " + to_string(balance) + "\n";

		  try {
 		  cin >> invest;
                  if(invest < balance) {

                  shares[stoi(option)-1] +=(invest / stockPrices[stoi(option)-1]);
                  
                  balance = balance - invest;
                  option = "0"; 
                  }
		  else {
		  cout <<"Error, Investment amount exceeded available balance!";
                  }
		  }
	          catch (std::invalid_argument & err) {
		  cout << "Error!";
		  } 
                  }
		}

		if (option == "3") {
                 cout << "Stock Options available to sell \n";
                 cout << "\n 1) TESLA " << shares[0] << "\n";
                 cout << "\n 2) Microsoft " << shares[1] << "\n";
	         cout << "\n 3) Bank of America " << shares[2] <<  "\n";	
                 cin >> option; 
                 
                 if (option == "1" || option == "2" || option == "3"){
                  cout << "You currently have " << shares[stoi(option)-1] <<  " shares to sell. How many would you like to sell? \n";
                  cin >> sell;
                  if (sell > shares[stoi(option)-1]) {
                   cout << "You cannot sell this many shares.";
                  }
                  else {
                   balance = balance + sell * stockPrices[stoi(option)-1];
                   shares[stoi(option)-1] = shares[stoi(option)-1] - sell;
                  }
                 }
		}
	}
  return 0;
}
