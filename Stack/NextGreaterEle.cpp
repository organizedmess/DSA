#include <bits/stdc++.h> 
vector<int> nextGreaterElement(vector<int>& arr, int n){
    vector<int> ans(n);
    stack<int> st;
    st.push(INT_MAX);

    for(int i=n-1; i>=0; i--){
        int ele = arr[i];
        while(st.top()<=ele){
            st.pop();
        }
        ans[i] = st.top();
        st.push(ele);
    }
    for(int i=0; i<n; i++){
        if(ans[i] == INT_MAX) ans[i] = -1;
    }
    return ans;
}