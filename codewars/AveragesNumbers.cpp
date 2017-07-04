std::vector<double> averages(std::vector<int> numbers)
{
    std::vector<double> result;
    
    for (int i=1; i<numbers.size(); i++)
    {
        result.push_back((numbers[i-1] + numbers[i]) / 2.0f);
    }

    return result;
}