class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int right = arr.size()-1;
        int elementMax = -1;
        
        for(int i=right; i>=0; i--)
        {
            int temp = elementMax;
            if(elementMax < arr[i])
            {
                elementMax = arr[i];
            }
            arr[i] = temp;
        }
        arr[right] = -1;
        return arr;
    }
};