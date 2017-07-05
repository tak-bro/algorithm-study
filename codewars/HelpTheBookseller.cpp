class StockList
{
public:
  static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories);
};

std::string StockList::stockSummary(std::vector<std::string> &books, std::vector<std::string> &categories)
{
    if (books.empty() || categories.empty())
      return "";

    int stocks['Z' + 1] = {0};
    for (const std::string &book : books) {
        std::size_t position = book.find_first_of(" ", 2, 1);
        stocks[book[0]] += std::atoi(book.data() + position);
    }

    std::string result = "";
    for (const std::string &category : categories) {
      result = result
        + (result.empty() ? "" : " - ")
        + "(" + category[0] + " : " + std::to_string(stocks[category[0]]) + ")";
    }

    return result;
}