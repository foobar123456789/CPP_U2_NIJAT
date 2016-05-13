#include "count_13th.hpp"
#include <iostream>
using std::cout ;
using std::cerr ;
using std::endl;




 /*
  * a = (14 - month) / 12
y = year - a
m = month + 12*a - 2
For Julian calendar: d = (5 + day + y + y/4 + (31*m)/12) mod 7
For Gregorian calendar: d = (day + y + y/4 - y/100 + y/400 + (31*m)/12) mod 7

The value of d is 0 for a Sunday, 1 for a Monday, 2 for a Tuesday, etc.

  */
 int get_weekday(int year , int  month , int day) {
	int a = (14 - month) /12 ;
	int y = year - a;
	int m = month + 12*a - 2 ;
	int d = (day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7 ;
	return d ;
 }


Weekday_statistics count_13th(int start_year, int year_offset) {
   if(start_year < 1900) {
	   cerr << "start_year " << start_year << " muss >= 1900 sein" << endl ;
	  exit(-1) ;
   }
   Weekday_statistics stats;
   //berechne alle Wochentagen
   int all = start_year- 1900 + year_offset ;
   for(int i=1 ; i<= all ; ++i) {
	   //Wochentag
	   for(int j= 1 ; j<=12; ++j) {
		   int weekday = get_weekday(start_year+i, j , 13);
		   switch(weekday) {
		   case 1: stats.set_monday_value(stats.get_monday_value()+ 1); break;
		   case 2: stats.set_tuesday_value(stats.get_tuesday_value()+ 1); break;
		   case 3: stats.set_wednesday_value(stats.get_wednesday_value()+ 1); break;
		   case 4: stats.set_thursday_value(stats.get_thursday_value()+ 1); break;
		   case 5: stats.set_friday_value(stats.get_friday_value()+ 1); break;
		   case 6: stats.set_saturday_value(stats.get_saturday_value()+ 1); break;
		   case 0: stats.set_sunday_value(stats.get_sunday_value() +1); break;
		   }
	   }
   }


   all = start_year - 1900 ;
   for(int i=1 ; i<= all ; ++i) {
	   //Wochentag
	   for(int j= 1 ; j<=12; ++j) {
		   int weekday = get_weekday(start_year+i, j , 13);
		   switch(weekday) {
		   case 1: stats.set_monday_value(stats.get_monday_value()- 1); break;
		   case 2: stats.set_tuesday_value(stats.get_tuesday_value()- 1); break;
		   case 3: stats.set_wednesday_value(stats.get_wednesday_value()- 1); break;
		   case 4: stats.set_thursday_value(stats.get_thursday_value()- 1); break;
		   case 5: stats.set_friday_value(stats.get_friday_value()- 1); break;
		   case 6: stats.set_saturday_value(stats.get_saturday_value()- 1); break;
		   case 0: stats.set_sunday_value(stats.get_sunday_value() - 1); break;
		   }
	   }
   }

return stats ;
}
