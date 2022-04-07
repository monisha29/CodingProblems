	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int> pq ;
	    
	    for(int i = 0 ; i < n ; i++) {
	        pq.push(arr[i]);
	    }
	    
	    
	    vector<int> op;
	    
	    while(k > 0 && pq.size() > 0) {
	        op.push_back(pq.top());
	        pq.pop();
	        k--;
	    }
	    
	    return op;
	}
