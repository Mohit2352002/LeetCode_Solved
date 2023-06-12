class Solution {
public:
    vector<string> summaryRanges(vector<int>& arr) {

         //speeder
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        
        int n = arr.size(); // extracting size of the array
        vector<string> ans; // declaring answer array to store our answer
        
		// if size happens to be  zero return empty string
        if(n == 0 )
                return ans;
                
        if(n==1) return {to_string(arr[0])};
        
        
        string temp = ""; // temproray string that stores all possible answer
        
        for(int i = 0; i < n; i++) // start traversing from the array
        {
            int j = i; // declare anthor pointer that will move
            
            // run that pointer until our range is not break
            while(j + 1 < n && arr[j + 1] == arr[j] + 1)
            {
                j++;
            }
            
            // if j > i, that means we got our range more than one element
            if(j > i)
            {
                temp += to_string(arr[i]); // first store starting point
                temp += "->"; // then store arrow, as question wants it
                temp += to_string(arr[j]); // and lastly store the end point
            }
            else // we got only one element as range
            {
                temp += to_string(arr[i]); // then store that element in temp
            }
            
            ans.push_back(temp); // push one possible answer string to our answer
            temp = ""; // again reintiliaze temp for new possible answers
            i = j; // and move i to j for a fresh start
        }
        
        return ans; // and at last finally return the answer array
    }
};








/*
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        //speeder
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

		// resultant string
        vector<string> result;
        
        int n = nums.size();
		// if size happens to be  zero return empty string
        if(n == 0 )
                return result;
                
        if(n==1) return {to_string(nums[0])};

		// assigning first element to a
        int a = nums[0];
        
        for(int i = 0; i<n; i++)
        {
			// if one of both is true
            if( i == n-1 || nums[i]+1 != nums[i+1])
            {
			    // if current element is not equals a
				// this means we have found a range.
                if(nums[i] != a)
                    result.push_back(to_string(a)+ "->"+ to_string(nums[i]));
					
				// this means we have reached to the end of string and now
				// we have to add a that should be the last element
                else
                        result.push_back(to_string(a));
						
				// checking  for this condition so that a got updated for next range
				// also n-1 so that a doesn't contain out of bound value
                if(i != n-1)
                    a = nums[i+1];
            }
        }
		// return result
        return result;
    }
};*/