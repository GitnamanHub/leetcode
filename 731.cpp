/*731. My Calendar II
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

The event can be represented as a pair of integers startTime and endTime that represents a booking on the half-open interval [startTime, endTime), the range of real numbers x such that startTime <= x < endTime.

Implement the MyCalendarTwo class:

MyCalendarTwo() Initializes the calendar object.
boolean book(int startTime, int endTime) Returns true if the event 
can be added to the calendar successfully without causing a triple booking. 
Otherwise, return false and do not add the event to the calendar.
 

Example 1:

Input
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, true, true, true, false, true, true]

Explanation
MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
myCalendarTwo.book(10, 20); // return True, The event can be booked. 
myCalendarTwo.book(50, 60); // return True, The event can be booked. 
myCalendarTwo.book(10, 40); // return True, The event can be double booked. 
myCalendarTwo.book(5, 15);  // return False, The event cannot be booked, 
                            because it would result in a triple booking.
myCalendarTwo.book(5, 10); // return True, The event can be booked, 
                            as it does not use time 10 which is already double booked.
myCalendarTwo.book(25, 55); // return True, The event can be booked, 
                            as the time in [25, 40) will be double booked with the third event, 
                            the time [40, 50) will be single booked, and the time [50, 55) 
                            will be double booked with the second event.
 

Constraints:

0 <= start < end <= 109
At most 1000 calls will be made to book.
*/

/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Pp4LIen7d0M
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/my-calendar-ii/
*/


/******************************************************************************* C++ ************************************************************************************************/
//Approach (Using Line Sweep)
//T.C : O(nlogn)
//S.C : O(n) to store events in map
class MyCalendarTwo {
public:
    map<int, int> events;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        events[startTime]++;
        events[endTime]--;

        int count = 0;

        for(auto &it : events) {
            count += it.second;

            if(count > 2) {
                events[startTime]--;
                events[endTime]++;
                return false;
            }
        }

        return true;
    }
};




/******************************************************************************* JAVA ************************************************************************************************/
//Approach (Using Line Sweep)
//T.C : O(nlogn)
//S.C : O(n) to store events in map
class MyCalendarTwo {

    private TreeMap<Integer, Integer> events;

    public MyCalendarTwo() {
        events = new TreeMap<>();
    }
    
    public boolean book(int startTime, int endTime) {
        // Add this booking optimistically
        events.put(startTime, events.getOrDefault(startTime, 0) + 1);
        events.put(endTime, events.getOrDefault(endTime, 0) - 1);

        int count = 0;

        // Sweep through timeline
        for (int delta : events.values()) {
            count += delta;
            if (count > 2) {
                // Revert changes (since triple booking not allowed)
                events.put(startTime, events.get(startTime) - 1);
                if (events.get(startTime) == 0) {
                    events.remove(startTime);
                }

                events.put(endTime, events.get(endTime) + 1);
                if (events.get(endTime) == 0) {
                    events.remove(endTime);
                }

                return false;
            }
        }

        return true;
    }
}