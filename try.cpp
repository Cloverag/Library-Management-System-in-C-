#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
    time_t timestamp;
    cout << ctime(&timestamp);
    cout << "timestamp = " << timestamp << endl;
    time(&timestamp);
    cout << "timestamp = " << timestamp << endl;
    cout << ctime(&timestamp);
    
    // cout << "" << ctime(&timestamp) << endl;
    // Display the date and time represented by the timestamp
}
