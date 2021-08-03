#include <iostream>
#include <vector>
using namespace std;

vector<int> decToBinary(int n, unsigned int arr_size)
{
    int binaryNum[32]; for (int & i : binaryNum) i = 0;
    vector<int> result;

    int i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = arr_size-1; j >= 0; j--)
        result.push_back(binaryNum[j]);

    return result;
}

int main() {
    vector<int> coins, table, start_position;
    vector<int> wanted = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1}; //Enter here what combinations you want to achieve

    for (int i = pow(2, wanted.size()-1); i < pow(2, wanted.size()); ++i) {
        table.clear();
        coins = decToBinary(i, wanted.size());
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
            for (int j = 0; j < wanted.size(); ++j)
            {
                cout << table[j] << " ";
            }
            cout << i << "\t\t";

            start_position = decToBinary(i, wanted.size());

            cout << "Start position: ";
            for (int j = 0; j < wanted.size(); ++j)
            {
                cout << start_position[j] << " ";
            }
            return 0;
        }
    }
    return 0;
}
