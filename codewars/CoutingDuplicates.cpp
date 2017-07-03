size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{
    //....
    int arr[256] = { 0 };
    int result = 0;
    
    // Increment value to array
    while(*in) {
        arr[tolower(*in)]++;
        in++;
    }
    
    // Check value
    for (int i = 0; i < 256; i++) {
    	if(arr[i] > 1)	result++;
    }
    
    return result;
}