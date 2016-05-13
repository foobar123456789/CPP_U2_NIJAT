#include <iostream>
#include <string>

using std::string ;
using std::cout ;
using std::endl ;


int calcDistance(string str1 , string str2);
int minimum(int a , int b, int c) ;
int main(int argc, char** argv) {
	string str1 = "abcdef";
	string str2 = "azced";
  int d = calcDistance(str1, str2);
  cout << "d = " << d << endl ;

  str1 = "Katze";
  str2 = "katze";
  d = calcDistance(str1, str2);
  cout << "d = " << d << endl ;
  str2 = "Kaatzee";
  d = calcDistance(str1, str2);
    cout << "d = " << d << endl ;
    str1 = "Original";
    str2 = "Katze!";
    d = calcDistance(str1, str2);
        cout << "d = " << d << endl ;

  return 0 ;
}


int calcDistance(string str1 , string str2)  {
  int size1 = str1.size();
  int size2 = str2.size();
  int distance[size1+1][size2+1];
  for(int i=0 ; i<=size1; ++i) distance[i][0] = i;
  for(int j= 0; j <= size2; ++j) distance[0][j] = j ;

  for(int i=1 ; i<=size1; ++i) {
	  for(int j=1 ; j<=size2; ++j) {
		  int topLeftRest = str1[i-1] == str2[j-1] ? 0 : 1 ;
         int topLeft = distance[i-1][j-1] + topLeftRest;
         int topRight = distance[i][j-1]+1;
         int bottomLeft = distance[i-1][j] +1 ;
         int min = minimum(topLeft, topRight, bottomLeft);
         distance[i][j]= min ;
         cout << min<< " ";
	  }
	  cout << endl ;
  }

  return distance[size1][size2];
}


int minimum(int a , int b, int c)  {
	int min = a ;
	if(b < min) min = b ;
	if(c < min) min = c ;
	return min;
}
