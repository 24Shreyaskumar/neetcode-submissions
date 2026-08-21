class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto i : tokens) {
            int num;
            try {
                num = stoi(i);
                st.push(num);
            }

            catch (...) {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                if (i == "+")
                    st.push(num1+num2);

                else if (i == "-")
                    st.push(num2-num1);

                else if (i == "*")
                    st.push(num1*num2);
                
                else
                    st.push(num2 / num1);
            }
        }

        int ans = st.top();
        st.pop();
        return ans;
    }
};
