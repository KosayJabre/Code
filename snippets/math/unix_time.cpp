// 0-indexed month/time, 1-indexed day
// minimum 1970, 0, 1, 0, 0, 0
ull toEpoch(int year, int month, int day, int hour, int minute, int second) {
	struct tm t; time_t epoch;
	t.tm_year = year - 1900; t.tm_mon = month;
	t.tm_mday = day; t.tm_hour = hour;
	t.tm_min = minute; t.tm_sec = second;
	t.tm_isdst = 0; // 1 = daylights savings
	epoch = mktime(&t);
	return (ull)epoch;
}