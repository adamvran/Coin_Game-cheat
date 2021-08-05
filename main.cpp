#include <iostream>
#include <vector>
#include <deque>
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

void solveHard(const vector<int> &wanted)
{
    vector<int> coins, table, start_position;
    for (int i = pow(2, wanted.size()-1); i < pow(2, wanted.size()); ++i)
    {
        table.clear();
        coins = decToBinary(i, wanted.size());
        int onecounter = 0;
        bool getout = false;
        for (auto coin : coins)
        {
            if (coin == 1)  onecounter++;
        }
        if (onecounter<coins.size()-onecounter) continue;

        while (!coins.empty())
        {

            for (int j = 2; j < wanted.size(); ++j) {
                if (table.size()==j && table.back() != wanted[j-1])
                {
                    getout = true;
                    break;
                }
            }
            if (getout){
                getout = false;
                break;
            }

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

            break;
        }

    }
}

void solveEasy(vector<int> &wanted)
{
    deque<int> deque;
    while (!wanted.empty())
    {
        deque.push_front(wanted.back());
        wanted.pop_back();
        deque.push_front(deque.back());
        deque.pop_back();
    }
    deque.push_back(deque.front());
    deque.pop_front();

    for (auto n : deque)
    {
        cout << n;
    }
    cout << endl;
}
int main() {
    vector<int> wanted = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,}; //Enter here what combinations you want to achieve

    //solveHard(wanted);
    solveEasy(wanted);


    return 0;
}
