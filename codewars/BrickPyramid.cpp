class Pyramid {
  public:
    static double weight(int, int); 
};

double Pyramid::weight(int row, int pos) {
  if (pos < 0 || pos > row)
    return -1;
  else if (row == 0)
    return 0;

  return ((1 + weight(row - 1, pos - 1)) + (1 + weight(row - 1, pos))) / 2;
}