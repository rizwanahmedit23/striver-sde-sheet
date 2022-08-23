#include<climits>
int getMedian(vector<vector<int>> &matrix)
{
    // find smallest, largest and number of elements.
    // The mid1BasedIdx(N+1)/2 th element the median(N is given to be odd). 
    // Search in range smallest to largest and find mid.
    // count occurence of elements <= mid, and also check if mid is present.
    // if mid is present and count==mid1BasedIdx return mid
    // Handle other cases.
    int n = matrix.size();
    
    int N=0;
    
    int sm = INT_MAX;
    int lg = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<matrix[i].size();j++){
            N++;
            sm = min(sm, matrix[i][j]);
            lg = max(lg, matrix[i][j]);
        }
    }
    int mid1BasedIdx = (N+1)/2;
    while(sm!=lg){
        int mid = (sm+lg)/2;
        int count=0;
        bool isMidPresent = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==mid)    isMidPresent=true;
                if(matrix[i][j]<=mid)    count++;
            }
        }
        if(isMidPresent && count==mid1BasedIdx)    return mid;
        if(count>mid1BasedIdx){
            lg=mid;
        }
        else if(count==mid1BasedIdx){
            lg=mid-1;
        }
        else{
            sm=mid+1;
        }
    }   
    return sm;
}
