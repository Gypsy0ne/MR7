#ifndef Time_h
#define Time_h

bool setTime(unsigned long& Time_Mark); // If Time_Mark = 0, sets current millis() to it and returns 1.
bool countSeconds(unsigned long Seconds, unsigned long& Time_Mark);
bool checkTimeMinutes(unsigned long Count, unsigned long& Time_Mark); // If Count minutes have passed since Time_Mark, returns 1 and resets Time_Mark to 0.
bool checkTimeSeconds(unsigned long Count, unsigned long& Time_Mark); // If Count seconds have passed since Time_Mark, returns 1 and resets Time_Mark to 0.

#endif
