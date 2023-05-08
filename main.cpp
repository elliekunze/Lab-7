#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

mt19937 random_mt;

class States {
    string state;
    int pop, income, households, perCapita;
    //basic_string<char, char_traits<char>, allocator<char>> perCapita;
public:
    States(string State = "Null", int perCapita = 0, int pop = 0, int income = 0, int households = 0) {
        this->state = State;
        this->perCapita = perCapita;
        this->pop = pop;
        this->income = income;
        this->households = households;
    }

    void Print() {
        cout << state << endl;
        cout << "Population: " << pop << endl;
        cout << "Per Capita Income: " << perCapita << endl;
        cout << "Median Household Income: " << income << endl;
        cout << "Number of Households: " << households << endl;
    }

//    States(string basicString, string basicString1, string basicString2, string basicString3, string basicString4) {
//
//    }
//    States(string stateName, string income, string population, string houseIncome, string numHouse) {
//
//    }
};

int Random(int min, int max) {
    uniform_int_distribution<int> dist(min, max);
    return dist(random_mt);
}

void RollDice(int numberOfRolls, int numberOfSides);

int main() {

    cout << "1. Random Numbers\n";
    cout << "2. State Info\n";

    int option;
    cin >> option;

    if (option == 1) {
        int randomSeed;
        cout << "Random seed value: ";
        cin >> randomSeed;
        random_mt.seed(randomSeed);
        int numTimes;
        cout << "Number of times to roll the die: ";
        cin >> numTimes;
        int numSides;
        cout << "Number of sides on this die: ";
        cin >> numSides;
        // user input

        RollDice(numTimes, numSides);
//        cout << "1. Random Numbers\n";
//        cout << "2. State Info\n";
    } else if (option == 2) {
        ifstream file;
        map<string, States> us_states;
        // Load the states
        file.open("states.csv");
        cout << "1. Print all states" << endl;
        cout << "2. Search for a state" << endl;
        cin >> option; //might be choice
        string fileLine, income, population, houseIncome, numHouse;
        string stateName;
        if (file.is_open()) {
            getline(file, fileLine);
            while (getline(file, fileLine)) {
                istringstream flow(fileLine);
                getline(flow, stateName, ',');
                getline(flow, income, ',');
                getline(flow, population, ',');
                getline(flow, houseIncome, ',');
                getline(flow, numHouse, ',');
                States States(stateName, stoi(income), stoi(population), stoi(houseIncome), stoi(numHouse));
                us_states.emplace(stateName, States);
            }
        }
        // Get input for option 1 (show all states) or 2 (do a search for a particular state)
//        cout << "1. Random Numbers\n";
//        cout << "2. State Info\n";

        if (option == 1) {
            map<string, States>::iterator iter;
            for (iter = us_states.begin(); iter != us_states.end(); iter++) {
                iter->second.Print();
            }
        } else if (option == 2) {
//            auto iter = us_states.begin();
//            string findState;
//            cin >> findState;
//            iter = us_states.find(findState);
//           // string stateName;
//            //cin >> stateName;
//            if (iter == us_states.end()) {
//                cout << "No match found for " << stateName << endl;
//            } else {
//                cout << "Per Capita Income: " << perCapita << endl;
//                cout << "Median Household Income" << income << endl;
//                cout << "Number of Households: " << households << endl;
//            }
            //string stateName;
            cin >> stateName;
            if (us_states.find(stateName) != us_states.end()) {
                us_states[stateName].Print();
            } else {
                cout << "No match found for " << stateName << endl;
            }
        }
    }
    return 0;

}

void RollDice(int numberOfRolls, int numberOfSides) {
    map<int, int> di;
    int j = 1;
    for (int i = 0; i < numberOfSides; i++) {
        di[j];
        j++;
    }
    for (int i = 0; i < numberOfRolls; i++) {
        int randomNumber = Random(1, numberOfSides);
        di[randomNumber] = di[randomNumber] + 1;
    }
    auto iter = di.begin();
    for (; iter != di.end(); iter++) {
        cout << iter->first << ":" << iter->second << endl; //go back
    }
}