double findNthRootOfM(int n, int m) {
	// Write your code here.
    double low = 0;
    double high = m;
    double eps = 1e-7; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(pow(mid, n) < (double)m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    return low;
}
