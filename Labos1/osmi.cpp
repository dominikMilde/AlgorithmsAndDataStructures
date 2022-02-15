#include <iostream>
using namespace std;

class SanitizedString
{
   string str;

public:
   void setStr(string str)
   {
      this->str = str;
   }

   string getStr()
   {
      return this->str;
   }

   SanitizedString(string str)
   {
      setStr(str);
   }

   ~SanitizedString() {}

   string removeDuplicateWhitespace()
   {

      char *pomocni = (char *)malloc(sizeof(char) * str.length() + 1);
      int count = 0;
      for (int i = 0; i < str.length(); i++)
      {
         if (!isspace(str[i]) || isspace(str[i]) && !isspace(str[i + 1]))
         {
            pomocni[count] = str[i];
            count++;
         }
      }
      pomocni[count] = '\0';
      pomocni = (char *)realloc(pomocni, sizeof(char) * count + 1);

      setStr(pomocni);
      return getStr();
   }

   string removeNonAplhaChars()
   {
      char *pomocni = (char *)malloc(sizeof(char) * str.length() + 1);
      int count = 0;
      for (int i = 0; i < str.length(); i++)
      {
         if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
         {
            pomocni[count] = str[i];
            count++;
         }
      }
      pomocni[count] = '\0';
      pomocni = (char *)realloc(pomocni, sizeof(char) * count + 1);

      setStr(pomocni);
      return getStr();
   }
   friend ostream &operator<<(ostream &os, const SanitizedString &ss)
   {
      os << ss.str;
      return os;
   }
};

int main(void)
{
   string str1 = "Ljeto   je   dobro.  ";

   SanitizedString s1(str1);
   s1.removeDuplicateWhitespace();
   cout << s1;
   system("pause");
   return 0;
}