#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
    string temp;
    int i;
    while (i != 1 && i != 2 && i != 3 && i != 4 && i != 5 && i != 6 && i != 7 && i != 8 && i != 9 && i != 10 || i != 11)
    {
        cout << "Enter a number between 1 and 11: " << endl;
        cin >> temp;
        if (temp == "1" || temp == "2" || temp == "3" || temp == "4" || temp == "5" || temp == "6" || temp == "7" || temp == "8" || temp == "9" || temp == "10" || temp == "11")
        {
            cout << "You have entered a valid number." << endl;
        i = stoi(temp);
        break;
        }
        else{
            cout << "You have not entered a valid number." << endl;
            continue;
        }
    }

    // time_t timestamp;
    // cout << ctime(&timestamp);
    // cout << "timestamp = " << timestamp << endl;
    // time(&timestamp);
    // cout << "timestamp = " << timestamp << endl;
    // cout << ctime(&timestamp);

    // cout << "" << ctime(&timestamp) << endl;
    // Display the date and time represented by the timestamp
}
