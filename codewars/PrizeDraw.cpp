using namespace std;

class Rank {
public:
  static string nthRank(const string &st, const vector<int> &we, int n);
};

string Rank::nthRank(const string &st, const vector<int> &we, int n) {
  if (st.empty()) return "No participants";
  vector<string> names;
  int l = st.size();
  int p_s{-1};
  int p_e;
  do {
    p_e = st.find(',', ++p_s);
    if (p_e == string::npos) {
      names.push_back(st.substr(p_s));
      break;
    }
    names.push_back(st.substr(p_s, p_e - p_s));
    p_s = p_e;
  } while (1);
  l = names.size();
  if (n > l) return "Not enough participants";
  vector<pair<int, string>> ranks(l);
  for (int i = 0; i < l; ++i) {
    string &name = names[i];
    int rank = name.size() * 2;
    for (auto c : name) rank += toupper(c) - 'A';
    ranks[i] = {rank * we[i], name};
  }
  sort(ranks.begin(), ranks.end(),
       [ranks, names](const pair<int, string> &a, const pair<int, string> &b) {
         return a.first != b.first ? a.first < b.first : a.second > b.second;
       });
  return ranks[l - n].second;
}