/*@
    requires 1 <= month <= 12;
    assigns \nothing;
    ensures \result == 28 || \result == 30 || \result == 31;
    ensures month == 2 ==> \result == 28;
    ensures (month == 4 || month == 6 || month == 9 || month == 11) ==> \result == 30;
    ensures (month == 1 || month == 3 || month == 5 || month == 7 || 
             month == 8 || month == 10 || month == 12) ==> \result == 31;
*/
int number_of_days(int month){
  int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  return days[month-1];
}
