// --------------------Part A----------------------

public class Time {

    int hours;
    int minutes;

    Time(int hours, int minutes) {
        this.hours = hours;
        this.minutes = minutes;
    }

    void add(Time t) {
        int h = this.hours + t.hours;
        int min = this.minutes + t.minutes;
        if (min >= 60) {
            h = h + min / 60;
            min = min % 60;
        }
        System.out.println("Time: " + h + " hours " + min + " minutes");
    }

    void sub(Time t) {
        int h = this.hours - t.hours;
        int min = this.minutes - t.minutes;
        if (min < 0) {
            h = h - 1;
            min = min + 60;
        }
        System.out.println("Time: " + h + " hours " + min + " minutes");
    }

    public static void main(String[] args) {
        Time t1 = new Time(5, 30);
        Time t2 = new Time(3, 40);

        System.out.println("=== Basic Time Operations ===");
        t1.add(t2);
        t1.sub(t2);

        System.out.println("\n=== Advanced Time Operations ===");
        AdvancedTime at1 = new AdvancedTime(50, 800, 2, 59);
        AdvancedTime at2 = new AdvancedTime(20, 500, 1, 30);

        at1.addAdv(at2);
        at1.subAdv(at2);
    }
}

// --------------------Part B----------------------
class AdvancedTime extends Time {

    int seconds;
    int milliseconds;

    public AdvancedTime(int seconds, int milliseconds, int hours, int minutes) {
        super(hours, minutes);
        this.seconds = seconds;
        this.milliseconds = milliseconds;
    }

    void addAdv(AdvancedTime t) {
        int h = this.hours + t.hours;
        int min = this.minutes + t.minutes;
        int sec = this.seconds + t.seconds;
        int mili = this.milliseconds + t.milliseconds;

        if (mili >= 1000) {
            sec += mili / 1000;
            mili = mili % 1000;
        }

        if (sec >= 60) {
            min += sec / 60;
            sec = sec % 60;
        }

        if (min >= 60) {
            h += min / 60;
            min = min % 60;
        }

        System.out.println("Time: " + h + " hours " + min + " minutes " + sec + " seconds " + mili + " milliseconds");
    }

    void subAdv(AdvancedTime t) {
        int h = this.hours - t.hours;
        int min = this.minutes - t.minutes;
        int sec = this.seconds - t.seconds;
        int mili = this.milliseconds - t.milliseconds;

        if (mili < 0) {
            sec -= 1;
            mili += 1000;
        }
        if (sec < 0) {
            min -= 1;
            sec += 60;
        }
        if (min < 0) {
            h -= 1;
            min += 60;
        }

        System.out.println("Time: " + h + " hours " + min + " minutes " + sec + " seconds " + mili + " milliseconds");
    }
}
