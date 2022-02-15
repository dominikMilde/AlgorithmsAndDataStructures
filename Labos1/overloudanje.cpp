#include <iostream>
using namespace std;
class Point
{
   int x, y;

public:
   Point(int x, int y)
   {
      setPoint(x, y);
   }
   void setPoint(int x, int y)
   {
      this->x = x;
      this->y = y;
   }

   int getX()
   {
      return this->x;
   }
   int getY()
   {
      return this->y;
   }

   friend ostream &operator<<(ostream &os, const Point &p)
   {
      os << p.x;
      return os;
   }
};

main(void)
{

   Point p1(2, 4);
   cout << p1;
   system("pause");
   return 0;
}