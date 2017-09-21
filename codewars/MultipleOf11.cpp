bool eleven(const std::string input) 
{
    // 11의 배수
    // 훌수자리의 합 - 짝수자리의 합이 11의 배수가 되면 된다.
    int even = 0;
    int odd = 0;
    
    for (int i=0; i<input.length(); i++) {
        if (i%2 == 0) 
            even += input[i] - '0';
        else 
            odd += input[i] - '0';
    }
  
    if ((odd-even)%11 == 0) 
        return true;
    return false;
}