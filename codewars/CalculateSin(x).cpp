#define PI 3.14159265358979323846

double sin(double deg)
{
    deg = deg * PI / (double)180;
    
    double result = deg;
    double t = deg;
    
    for (int i = 1; i < 10; i++) {
      t = (t * (-1) * deg * deg) / (2 * i * (2 * i + 1));
      result = result + t;
    }
    
    return result;
}