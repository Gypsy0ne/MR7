#ifndef Time_h
#define Time_h

// If timeMark = 0, sets current millis() to it and returns 1.
bool setTime(unsigned long& timeMark); 
bool countSeconds(unsigned long seconds, unsigned long& timeMark);
bool checkTimeMinutes(unsigned long count, unsigned long& timeMark);
bool checkTimeSeconds(unsigned long count, unsigned long& timeMark);

#endif
