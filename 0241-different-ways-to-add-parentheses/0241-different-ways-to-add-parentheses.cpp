class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
         // its not finding numbers and plaxing brackets choosing alternate places, its more like choosing an operator and using it as an independent split point. first identify the last operator, and then we need to solve everythign on the right side and the left side of the operator, not if any one is a single number 

         //basically resursive tree operator splitting is what this is, The recursive splitting automatically handles that. Each operator you choose becomes the operation joining two recursively solved subexpressions.

        return solve(expression);
    }

private:
    vector<int> solve(string expression) {
        vector<int> result;

        for (int i = 0; i < expression.length(); i++) {

            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {

                string left = expression.substr(0, i);
                string right = expression.substr(i+1);

                vector<int> leftResults = solve(left);
                vector<int> rightResults = solve(right);


                for (int l : leftResults) {
                    for (int r : rightResults) {

                        if (expression[i] == '+')
                            result.push_back(l + r);

                        else if (expression[i] == '-') {
                            result.push_back(l - r);
                        }
                            

                        else result.push_back(l * r);
                            

                    }
                }
             }
        }

        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return result;
    }
};