#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> decToBinary(int n)
{
    int binaryNum[32];

    vector<int> result;

    int i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = 9; j >= 0; j--)
        result.push_back(binaryNum[j]);

    return result;
}

int main() {
    vector<int> coins;
    vector<int> table;
    vector<int> start_position;
    vector<int> wanted = {1,0,1,0,1,0,1,0,1,0};
    string str_bin;

    for (int i = 0; i < 1024; ++i) {
        table.clear();
        coins = decToBinary(i);
        while (!coins.empty())
        {
            if (coins.size() == 2)
            {
                table.push_back(coins.front());
                coins.erase(coins.begin());
                table.push_back(coins.front());
                coins.erase(coins.begin());
            }
            else
            {
                table.push_back(coins.front());
                coins.erase(coins.begin());
                coins.push_back(coins.front());
                coins.erase(coins.begin());
            }
        }

        if (wanted == table)
        {
            for (int j = 0; j < 10; ++j)
            {
                cout << table[j] << " ";
                str_bin += to_string(table[j]);
            }
            cout << i << "\t\t";

            start_position = decToBinary(i);

            cout << "Start position: ";
            for (int j = 0; j < 10; ++j)
            {
                cout << start_position[j] << " ";
            }
        }
    }
    return 0;
}
