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
    int getImportance(vector<Employee*> employees, int id) {
        int count = 0;
        for(auto emp: employees)
        {
            if(emp->id == id)
            {
                count = emp->importance;
                for(auto s: emp->subordinates)
                {
                    count += getImportance(employees, s);
                }
            }
        }
        return count;
    }
};