vector<int> NextGreaterElement(vector<int> A)
{
    int n=A.size();
    vector<int> B(n);
    
    stack<int> S;
    
    for(int i=0;i<n;i++)
    {
        while(!S.empty() && A[i]>A[S.top()])
        {
            B[S.top()]=A[i];
            S.pop();
        }
        S.push(i);
    }
    while(!S.empty())
    {
        B[S.top()]=-1;
        S.pop();
    }
    return B;
}
