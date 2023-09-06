#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> myMap; //creating a map of string and integer type

    myMap["apple"] = 10; //adding key-value pair to the map
    myMap["banana"] = 20;
    myMap["orange"] = 30;

    //printing the contents of the map
    for(auto it = myMap.begin(); it!= myMap.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}