#include<iostream>
using std::cout;
using std::endl;

class MyDate
{
private:
    bool IsLeapYear(int year);
    int CalculateDaysBetweenTwoYear(MyDate date1, MyDate date2);
    int CalculateDaysBetweenTwoMonth(MyDate date);
public:
    int Year;
    int Month;
    int Day;
    int getdays(MyDate date1, MyDate date2);
};


bool MyDate::IsLeapYear(int year){
    if(year%400 == 0){
        return true;
    }else if(year%100 != 0 && year%4 == 0){
        return true;
    }else{
        return false;
    }

} 

int MyDate::CalculateDaysBetweenTwoYear(MyDate date1,MyDate date2){
    int days = 0;
    for (int i = date1.Year + 1; i <= date2.Year - 1; i++){
        if(IsLeapYear(i)){
            days += 366;
        }else{
            days += 365;
        }
    }
    return days;
}

int MyDate::CalculateDaysBetweenTwoMonth(MyDate date){
    int months[]{31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    if (IsLeapYear(date.Year))
    {
        months[1] = 29;
    }else{
        months[1] = 28;
    }
    for (int i = 0; i < date.Month - 1;i++){
        days += months[i];
    }
    return (days+date.Day);
}

int MyDate::getdays(MyDate date1,MyDate date2){
    int days = 0;
    int betweenyear = CalculateDaysBetweenTwoYear(date1,date2);
    int day1 = 0;
    if(date1.Year == date2.Year){
        return (CalculateDaysBetweenTwoMonth(date2)-CalculateDaysBetweenTwoMonth(date1));
    }else{
    if (IsLeapYear(date1.Year)){
        day1 = 366 - CalculateDaysBetweenTwoMonth(date1);
    }else{
        day1 = 365 - CalculateDaysBetweenTwoMonth(date1);
    }
    int day2 = CalculateDaysBetweenTwoMonth(date2);
    return (betweenyear + day1 + day2);
    }
}

int main(){
    MyDate date1;
    
    date1.Year = 1997;
    date1.Month = 11;
    date1.Day = 15;

    MyDate date2;
    date2.Year = 1997;
    date2.Month = 12;
    date2.Day = 31;

    MyDate obj;
    cout << obj.getdays(date1, date2) << endl;

    return (0);
}