class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>student;
        stack<int>sandwich;
        int count=0;
        
        for(int i=0;i<students.size();i++){
            student.push(students[i]);
        }
        for(int i=sandwiches.size()-1;i>=0;i--){
            sandwich.push(sandwiches[i]);
        }
        
        while(!sandwich.empty()){
            if(sandwich.top() == student.front()){
                sandwich.pop();
                student.pop();
                count=0;
            }
            else{
                student.push(student.front());
                student.pop();
                count++;
                if(count==student.size()){
                    return count;
                }
            }
        }
        
        return count;
    }

        
    
};
