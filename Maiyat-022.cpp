#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    
    vector<pair<int, int>> jobs(n);
    int max_days = 0;

    
    for (int i = 0; i < n; i++) {
        int days_left, salary;
        cin >> days_left >> salary;
        jobs[i] = {salary, days_left};
        max_days = max(max_days, days_left);  
    }

    
    sort(jobs.begin(), jobs.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    });

    
    vector<int> assigned_salaries(max_days + 1, -1);

    
    for (auto job : jobs) {
        int salary = job.first;
        int days_left = job.second;
        for (int d = days_left; d > 0; d--) {
            if (assigned_salaries[d] == -1) {  
                assigned_salaries[d] = salary;
                break;
            }
        }
    }

    
    for (int i = 1; i <= max_days; i++) {
        cout << assigned_salaries[i] << " ";
    }
    cout << endl;

    return 0;
}