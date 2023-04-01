#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getCompartmentSize(int size){
    return size/2;
}

char findSharedItemType(string firstCompartment, string secondCompartment){
    char sharedItemType = 0;
    int compartmentSize = firstCompartment.length();

    for (int i = 0; i < compartmentSize; i++){
        char item = firstCompartment[i];
        if(secondCompartment.find(item) != string::npos){
            sharedItemType = item;
            break;
        }
    }
    
    return sharedItemType;
}

//This function will calculate the distance between two chars
//then use that to calculate the priority
int priorityCalculate(char sharedItemType){
    if (sharedItemType >= 'a' && sharedItemType <= 'z') {
        return sharedItemType - 'a' + 1;
    }
    if (sharedItemType >= 'A' && sharedItemType <= 'Z') {
        return sharedItemType - 'A' + 27;
    }
    return 0;
}

int main(){
    ifstream data("input.txt");
    string line;
    string firstCompartment, secondCompartment;
    int sumOfPriority = 0;
    
    while(getline(data, line)){
        int compartmentSize = getCompartmentSize(line.length());
        firstCompartment = line.substr(0,compartmentSize);
        secondCompartment = line.substr(compartmentSize, -1);
        sumOfPriority += priorityCalculate(findSharedItemType(firstCompartment, secondCompartment));
    }
    
    cout << sumOfPriority << endl;
    
    return 0;
}