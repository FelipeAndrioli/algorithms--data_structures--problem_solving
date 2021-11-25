#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int clockAngle(double hour, double minute) {
	if (hour < 0 || minute < 0 || hour > 12 || minute > 60) {
		cout << "Wrong input" << endl;
		return -1;
	}

	if (hour == 12) {
		hour = 0;
	}

	if (minute == 60) {
		minute = 0;
		hour += 1;

		if (hour > 12) {
			hour = hour - 12;
		}
	}

	//Find hour angle and minute angle using 12:00 (hour = 12, minute = 00) as reference
	float hour_angle = 0.5 * (hour * 60 + minute);
	float minute_angle = 6 * minute;

	float angle = abs(hour_angle - minute_angle);

	angle = min(360 - angle, angle);

	return angle;
}

int main() {

	cout << clockAngle(9, 60) << endl;
	cout << clockAngle(3, 30) << endl;

	/*
	 * Problem:
	 *
	 * 	Angle between clock hands
	 *
	 * Solution:
	 *
	 * 	Find hour angle, the hour hand reaches 360 degrees each 720 minutes or 0.5ºby minute. With this information
	 * 	we can multiply the hour by 60 to get the angle, add with minutes (when minutes hand moves it also moves the
	 * 	hour hand), and then multiply by 0.5.
	 *
	 * 	Find minutes angle, the minute hand reaches 360 degrees each 60 minutes or 6ºby minute. With this information
	 * 	we can multiply the minute by 6 and we are going to have the minutes angle.
	 *
	 * 	To find the angle between hour and minute hands we just need to find the absolute value between its subtraction. With
	 * 	the subtraction value we are going to have two angle possibilities, one that runs inside and one that runs outside
	 * 	in this case we just need to return the smaller value.
	 *
	 * Complexity:
	 *
	 * 	The solution have a time complexity of O(1), once it doesn't need to loop through any value.
	 *
	 * */

	return 0;
}
