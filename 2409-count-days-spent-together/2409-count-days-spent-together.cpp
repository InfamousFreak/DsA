class Solution {
public:
    int convert(string date) {


        vector<int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int total = day;

        for (int i = 0; i < month - 1; i++){
            total += days[i];
        }

        return total;
    }


    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(convert(arriveAlice), convert(arriveBob));
        int end = min(convert(leaveAlice), convert(leaveBob));

        if (start > end) {
            return 0;
        }

        return end - start + 1;
    }
};


//mainly what we ahve to do here is convert the dates into days count so addition and subtraction is easier, so converting dsys into 365 day format, have to write a function about it
