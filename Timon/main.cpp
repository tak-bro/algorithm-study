#include "CSVRow.h"
#include <iomanip>
#include <locale>
#include <algorithm>

using namespace std;

// Prototype for conversion functions
std::wstring StringToWString(const std::string& s)
{
    std::wstring temp(s.length(),L' ');
    std::copy(s.begin(), s.end(), temp.begin());
    return temp; 
}


std::string WStringToString(const std::wstring& s)
{
    std::string temp(s.length(), ' ');
    std::copy(s.begin(), s.end(), temp.begin());
    return temp; 
}
// Define Class
class SellingData {
    public:
    SellingData(string _name, int _origin, int _selling, unsigned int _nine, unsigned int _ten, int _sales)
    {  
        m_name = _name;
        m_origin = _origin;
        m_selling = _selling;
        m_nine = _nine;
        m_ten = _ten;
        m_sales = _sales;
    }     
    
    int setRank(int rank) {
        m_rank = rank;
    }
    
    int getRank() const {
        return m_rank;
    }
    
    string getName() const {
        return m_name;
    }
    
    int getOrigin() const {
        return m_origin;
    }
    
    int getSelling() const {
        return m_selling;
    }
    
    unsigned int getRevenueOfNine() const {
        return m_nine;
    }
    
    unsigned int getRevenueOfTen() const {
        return m_ten;
    }
    
    int getSales() const {
        return m_sales;
    }
    
    private:
    string m_name;
    int m_origin;
    int m_selling;
    unsigned int m_nine;
    unsigned int m_ten;
    int m_sales;
    int m_rank;
};

// helper function
string commify(unsigned long long n) {
    string s;
    int cnt = 0;
    do {
        s.insert(0, 1, char('0' + n % 10)); 
        n /= 10;
        if (++cnt == 3 && n) {
            s.insert(0, 1, ',');
            cnt = 0;
        }
    } while (n);
    return s + "원";
}

// string to int
int string2int(std::string n) {
    std::istringstream buffer(n);
    int result;
    buffer >> result;
    return result;
}

// int to string
string int2string(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

// sort
void quickSort(vector<SellingData>& data, int left, int right)
{
	int i = left, j = right;
	int tmp = 0;
	int pivotInx = (left + right) / 2;
	int pivot = data[pivotInx].getRank();

	while (i <= j){
		while (data[i].getRank() < pivot)
			i++;
		while (data[j].getRank() > pivot)
			j--;

		if (i <= j){
			tmp = data[i].getRank();
			data[i].setRank(data[j].getRank());
			data[j].setRank(tmp);
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(data, left, j);
	if (i < right)
		quickSort(data, i, right);
}

std::wstring utf8_to_utf16(const std::string& utf8)
{
    std::vector<unsigned long> unicode;
    size_t i = 0;
    while (i < utf8.size())
    {
        unsigned long uni;
        size_t todo;
        bool error = false;
        unsigned char ch = utf8[i++];
        if (ch <= 0x7F)
        {
            uni = ch;
            todo = 0;
        }
        else if (ch <= 0xBF)
        {
            throw std::logic_error("not a UTF-8 string");
        }
        else if (ch <= 0xDF)
        {
            uni = ch&0x1F;
            todo = 1;
        }
        else if (ch <= 0xEF)
        {
            uni = ch&0x0F;
            todo = 2;
        }
        else if (ch <= 0xF7)
        {
            uni = ch&0x07;
            todo = 3;
        }
        else
        {
            throw std::logic_error("not a UTF-8 string");
        }
        for (size_t j = 0; j < todo; ++j)
        {
            if (i == utf8.size())
                throw std::logic_error("not a UTF-8 string");
            unsigned char ch = utf8[i++];
            if (ch < 0x80 || ch > 0xBF)
                throw std::logic_error("not a UTF-8 string");
            uni <<= 6;
            uni += ch & 0x3F;
        }
        if (uni >= 0xD800 && uni <= 0xDFFF)
            throw std::logic_error("not a UTF-8 string");
        if (uni > 0x10FFFF)
            throw std::logic_error("not a UTF-8 string");
        unicode.push_back(uni);
    }
    std::wstring utf16;
    for (size_t i = 0; i < unicode.size(); ++i)
    {
        unsigned long uni = unicode[i];
        if (uni <= 0xFFFF)
        {
            utf16 += (wchar_t)uni;
        }
        else
        {
            uni -= 0x10000;
            utf16 += (wchar_t)((uni >> 10) + 0xD800);
            utf16 += (wchar_t)((uni & 0x3FF) + 0xDC00);
        }
    }
    return utf16;
}

// calculate rank
void calucateRank(std::vector<SellingData>& datas, std::vector<int>& rankArray, bool isNine) {
    int rank = 0;
    int size = datas.size();
    // Process 
    for(int i = 0; i < size; i++) {
        rank = 1;    
        for(int j = 0; j < size; j++) {
            if (isNine) {
                if (datas[i].getRevenueOfNine() < datas[j].getRevenueOfNine()) {
                    rank++; // 나보다 큰점수 나오면 순위 증가!
                }
            } else { // ten
                if (datas[i].getRevenueOfTen() < datas[j].getRevenueOfTen()) {
                    rank++; 
                }
            }
            datas[i].setRank(rank);
            rankArray[i] = rank; 
        }
    }
}

// main

int main()
{
    std::ifstream file("2017_be_sheet.csv");
    CSVRow row;
    
    std::vector<SellingData> datas;
    
    while(file >> row)
    {
        // calculate values
        int origin =  string2int(row[2]);
        int selling = string2int(row[1]);
        unsigned int revenueOfNine = selling * string2int(row[3]);
        unsigned int revenueOfTen = selling * string2int(row[4]);
        int sales = (origin - selling) * 100 / origin;
        // push data
        datas.push_back(SellingData(row[0], origin, selling, revenueOfNine, revenueOfTen, sales));
    }
    // get size
    int size = datas.size();
    std::vector<int> rankArray(size);
    std::vector<int> rankTenArray(size);
    bool isNine = true;
    
    calucateRank(datas, rankArray, isNine);
    calucateRank(datas, rankTenArray, !isNine);
    
    // Sorting 
    quickSort(datas, 0, size-1);
    
    cout << setw(20) << left << "현재 순위";
    cout << setw(20) << left << "순위 변동";
    cout << setw(20) << left << "상품명";
    cout << setw(20) << left << "정상가";
    cout << setw(20) << left << "판매가";
    cout << setw(20) << left << "할인율";
    cout << '\n';
    
    for (int i = 0; i < rankArray.size(); i++) {
        string tmp = "";
        int changed = rankArray[i] - datas[i].getRank();
        if (changed > 0) {
            tmp = "+" + int2string(changed);
        } else if (changed == 0) {
            tmp = "-";
        } else {
            tmp = int2string(changed);
        }
        // 방법2.  
        
        cout << setw(14) << left << datas[i].getRank();
        cout << setw(14) << left << tmp;
        wcout << setw(15) << left << StringToWString(datas[i].getName());
        cout << setw(15) << left << " ";
        cout << setw(15) << left << commify(datas[i].getOrigin());
        cout << setw(15) << left << commify(datas[i].getSelling());
        tmp = int2string(datas[i].getSales()) + "%";
        cout << setw(15) << left << tmp;
        cout << '\n';
    }

    file.close();
    return 0;
}