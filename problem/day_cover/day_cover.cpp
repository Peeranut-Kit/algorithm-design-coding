#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// not minimum
int day_cover_v1(vector< pair <int, int> > &staff_and_numfree, vector< vector <bool> > &availability, vector<bool> &covered_day_vector, int covered_day, int len, int staff_count, int n)
{
    while (covered_day < n) {
        if (len == n) return -1;
        int staff_id = staff_and_numfree[len].second;
        bool used = false;
        for (size_t i=0; i<n; i++) {
            if (!covered_day_vector[i] && availability[staff_id][i]) {
                used = true;
                covered_day_vector[i] = true;
                covered_day++;
            }
        }
        if (used) staff_count++;
        // cout << staff_count << " " << len << endl;
        len++;
    }
    return staff_count;
}

// use combination
int day_cover_v2(vector< vector <bool> > &availability, vector<bool> covered_day_vector, int len, int m)
{
    // All days are covered, end of this path.
    if (!count(covered_day_vector.begin(), covered_day_vector.end(), false)) {
        return 0;
    }

    // Iterate until last one but all days are not covered -> This path cannot be the candidate solution.
    if (len == m) {
        return m+1;
    }

    // exclude current staff (staff count is not incremented.)
    int exclude = day_cover_v2(availability, covered_day_vector, len+1, m);

    // include current staff (staff count++)
    for (size_t i=0; i<covered_day_vector.size(); i++) {
        covered_day_vector[i] = covered_day_vector[i] || availability[len][i];
    }
    int include = day_cover_v2(availability, covered_day_vector, len+1, m) + 1;
    return min(exclude, include);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector< pair <int, int> > staff_and_numfree;
    vector< vector<bool> > availabilty(m);
    for (int i = 0; i < m; i++)
    {
        int days_free;
        cin >> days_free;

        if (days_free >= n)
        {
            cout << "1";
            return 0;
        }

        staff_and_numfree.push_back(make_pair(days_free, i));
        vector<bool> tmp(n);
        availabilty[i] = tmp;

        for (int j = 0; j < days_free; j++)
        {
            int day;
            cin >> day;
            availabilty[i][day - 1] = true;
        }
    }

    sort(staff_and_numfree.begin(), staff_and_numfree.end());
    reverse(staff_and_numfree.begin(), staff_and_numfree.end());

    /*for (int i = 0; i < m; i++)
    {
        cout << staff_and_numfree[i].first << " " << staff_and_numfree[i].second << endl;
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << availabilty[i][j] << " ";
        }
        cout << endl;
    }*/

    vector<bool> covered_day_vector(n);
    cout << day_cover_v2(availabilty, covered_day_vector, 0, m);
    return 0;
}
