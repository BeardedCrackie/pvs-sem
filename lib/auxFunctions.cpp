#include "auxFunctions.h"

void AuxFunctions::printInputError(string s, int i) {
    SerialHandler::sh_write("\nBad input\'");
    SerialHandler::sh_write(s);
    SerialHandler::sh_write("\':\'");
    SerialHandler::sh_write(to_string(i));
    SerialHandler::sh_write("\', terminating!\n");
}

void AuxFunctions::setTime() {

    lc_setState(info);
    struct tm custom_time;

    SerialHandler::sh_write("set day: ");
    custom_time.tm_mday = SerialHandler::sh_readInt();
    if(custom_time.tm_mday < 1 || custom_time.tm_mday > 31) {
        printInputError("day", custom_time.tm_mday);
        return;
    }

    SerialHandler::sh_write("\nset month: ");
    custom_time.tm_mon = SerialHandler::sh_readInt() - 1;
    if(custom_time.tm_mon < 1 || custom_time.tm_mon > 12) {
        printInputError("month", custom_time.tm_mon + 1);
        return;
    }

    SerialHandler::sh_write("\nset year: ");
    custom_time.tm_year = SerialHandler::sh_readInt() - 1900;
    if(custom_time.tm_year < 70 || custom_time.tm_year > 137) {
        printInputError("year", custom_time.tm_year + 1900);
        return;
    }

    SerialHandler::sh_write("\nset hour: ");
    custom_time.tm_hour = SerialHandler::sh_readInt();
    if(custom_time.tm_hour < 0 || custom_time.tm_hour > 23) {
        printInputError("hour", custom_time.tm_hour);
        return;
    }

    SerialHandler::sh_write("\nset minute: ");
    custom_time.tm_min = SerialHandler::sh_readInt();
    if(custom_time.tm_min < 0 || custom_time.tm_min > 59) {
        printInputError("minute", custom_time.tm_min);
        return;
    }

    SerialHandler::sh_write("\nset second: ");
    custom_time.tm_sec = SerialHandler::sh_readInt();
    if(custom_time.tm_sec < 0 || custom_time.tm_sec > 59) {
        printInputError("second", custom_time.tm_sec);
        return;
    }

    time_t t_of_day;
    t_of_day = mktime(&custom_time);
    set_time(t_of_day);
    SerialHandler::sh_write("\nTime set!");
}