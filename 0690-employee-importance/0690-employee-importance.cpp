/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:

    int sum = 0;
    unordered_map<int , Employee*> mpp;

    void dfs(int id) {
        Employee *emp = mpp[id];

        sum += emp->importance;
        
        for(auto it : emp->subordinates) {
            dfs(it);
        }
    }

    int getImportance(vector<Employee*> employees, int id) {
        for(int i=0; i<employees.size(); i++) {
            Employee *emp = employees[i];

            mpp[emp->id] = emp;
        }

        dfs(id);

        return sum;
    }
};