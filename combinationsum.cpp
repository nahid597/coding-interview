#include<bits/stdc++.h>

using namespace std;

void findNumber(vector<int> &ar, int sum, vector<vector<int> >& res,vector<int> contibation, int i){

    if(sum < 0)
      return;
    if(sum == 0)
    {
       cout << "nahid" <<endl;
        res.push_back(contibation);

        return;
    }

    while(i < ar.size() && sum -ar[i] >= 0)
    {
        contibation.push_back(ar[i]);

        findNumber(ar, sum - ar[i], res, contibation, i);

        i++;

        contibation.pop_back();
    }
}

vector<vector<int> > combinationsum(vector<int>& ar, int sum)
{
    sort(ar.begin(), ar.end());

    ar.erase(unique(ar.begin(), ar.end()), ar.end());

    vector<int>contibation;
    vector<vector<int> > res;
    findNumber(ar, sum, res, contibation, 0);

     cout << res.size() << endl;
    return res;
}

int main()
{
    vector<int> ar;

    ar.push_back(2);
    ar.push_back(4);
    ar.push_back(6);
    ar.push_back(8);

    int sum = 8;

    vector< vector<int> >res = combinationsum(ar,sum);

    if(res.size() == 0)
    cout << "Empty" << endl;
    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
