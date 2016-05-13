#include <iostream>


class Weekday_statistics {
private:
int monday = 0 ,
 tuesday = 0,
 wednesday = 0 ,
 thursday = 0 ,
 friday = 0,
 saturday = 0,
 sunday = 0 ;
public:
void set_monday_value(int);
  void set_tuesday_value(int);
  void set_wednesday_value(int);
  void set_thursday_value(int);
  void set_friday_value(int);
  void set_saturday_value(int);
  void set_sunday_value(int);

  int get_monday_value(void);
  int get_tuesday_value(void);
  int get_wednesday_value(void);
  int get_thursday_value(void);
  int get_friday_value(void);
  int get_saturday_value(void);
  int get_sunday_value(void);
};
