class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> stu, sand;
        for(int i=0; i<n; i++) {
            stu.push(students[i]);
            sand.push(sandwiches[i]);
        }
        int count = 0;
        while(!stu.empty() and !sand.empty() and count < stu.size()) {
            if(stu.front() == sand.front()) {
                stu.pop();
                sand.pop();
                count = 0;
            }
            else {
                int top = stu.front();
                stu.pop();
                stu.push(top);
                count++;
            }
        }
        return stu.size();
    }
};










