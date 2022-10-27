#include <iostream>
#include <functional>
#include <string>


using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int length = password.size();
    int numOfUC = 0;
    int numOfLC = 0;
    int numOfNum = 0;
    int numOfSC = 0;

    for (int i = 0; i < length; i++) {
        if ((int)password[i] >= 48 && (int)password[i] <= 57)
            numOfNum++;
        else if ((int)password[i] >= 65 && (int)password[i] <= 90)
            numOfUC++;
        else if ((int)password[i] >= 97 && (int)password[i] <= 122)
            numOfLC++;
        else
            numOfSC++;
    }
    int minNumber = 0;
    if (numOfNum < 1) minNumber++;
    if (numOfLC < 1) minNumber++;
    if (numOfUC < 1) minNumber++;
    if (numOfSC < 1) minNumber++;
    if (length + minNumber < 6) minNumber = 6 - length;
    return minNumber;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    std::cout << answer << "\n";

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}