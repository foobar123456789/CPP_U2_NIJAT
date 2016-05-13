#include <iostream>
#include "levenshtein.hpp"
using std::string;
int minimal(int *D, std::string *original, std::string *katze,int i, int j)  {
	string str1 = *original ,
			str2 = *katze ;

int index = i* katze->size() + j ;
if(index <= katze->size()) return j ;
int rest = index % katze->size();
if(rest == 0) return j ;

int prevIndex = index - katze->size();
int index2 = index -1 ;
int prevIndex2 = prevIndex - 1;

int x = (*original)[i] == (*katze)[j]? 0: 1 ;
int prev = D[prevIndex] +=1 ;
int i2 = D[index2] +1 ;
int prev2 = D[prevIndex2] += x ;
int min = prev;
if(i2 < min) min = i2 ;
if(prev2 < min) min = prev2 ;
D[index] = min;
return min ;
}

int levenshtein_distance(std::string original, std::string katze) {
  int *D = new int[(original.size() +1)* (katze.size() +1)];
  for(int j= 0 ; j<= katze.size(); ++j) D[j] = j;
  for(int i=0 ; i<= original.size(); ++i) {
	  int index = i* katze.size() + i ;
	  D[index] = i ;
  }

  for(int j= 1 ; j<= katze.size(); ++j) {
	  for(int i=1 ; i <= original.size(); ++i) {
         minimal(D , &original, &katze, i, j);
	  }
  }

  int size1 = original.size(),
		  size2 = katze.size();
  return minimal(D, &original, &katze, size1, size2);
}
