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
    vector<int> wanted = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0}; //Enter here what combinations you want to achieve

    for (int i = pow(2, wanted.size()-1); i < pow(2, wanted.size()); ++i)
    {
        table.clear();
        coins = decToBinary(i, wanted.size());

        while (!coins.empty())
        {

            if (table.size()==2 && table[table.size()-1] == 1)
                break;
            if (table.size()==3 && table[table.size()-1] == 0)
                break;
            if (table.size()==4 && table[table.size()-1] == 1)
                break;
            if (table.size()==5 && table[table.size()-1] == 0)
                break;
            if (table.size()==6 && table[table.size()-1] == 1)
                break;
            if (table.size()==7 && table[table.size()-1] == 0)
                break;
            if (table.size()==8 && table[table.size()-1] == 1)
                break;
            if (table.size()==9 && table[table.size()-1] == 0)
                break;
            if (table.size()==10 && table[table.size()-1] == 1)
                break;
            if (table.size()==11 && table[table.size()-1] == 0)
                break;
            if (table.size()==12 && table[table.size()-1] == 1)
                break;
            if (table.size()==13 && table[table.size()-1] == 0)
                break;
            if (table.size()==14 && table[table.size()-1] == 1)
                break;
            if (table.size()==15 && table[table.size()-1] == 0)
                break;
            if (table.size()==16 && table[table.size()-1] == 1)
                break;
            if (table.size()==17 && table[table.size()-1] == 0)
                break;
            if (table.size()==18 && table[table.size()-1] == 1)
                break;
            if (table.size()==19 && table[table.size()-1] == 0)
                break;
            if (table.size()==20 && table[table.size()-1] == 1)
                break;
            if (table.size()==21 && table[table.size()-1] == 0)
                break;
            if (table.size()==22 && table[table.size()-1] == 1)
                break;
            if (table.size()==23 && table[table.size()-1] == 0)
                break;
            if (table.size()==24 && table[table.size()-1] == 1)
                break;
            if (table.size()==25 && table[table.size()-1] == 0)
                break;
            if (table.size()==26 && table[table.size()-1] == 1)
                break;
            if (table.size()==27 && table[table.size()-1] == 0)
                break;
            if (table.size()==28 && table[table.size()-1] == 1)
                break;
            if (table.size()==29 && table[table.size()-1] == 0)
                break;
            if (table.size()==30 && table[table.size()-1] == 1)
                break;


            else if (coins.size() == 2)
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
            for (int j : table)
                cout << j << " ";
            cout << i << "\t\t";

            start_position = decToBinary(i, wanted.size());

            cout << "Start position: ";
            for (int j : start_position)
                cout << j << " ";


        }
    }
    return 0;
}
