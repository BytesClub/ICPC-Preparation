/**
 * Quadcopter Competition: http://codeforces.com/contest/883/problem/M
 *
 * Polycarp takes part in a quadcopter competition. According to the rules a
 * flying robot should:
 *
 *   start the race from some point of a field,
 *   go around the flag,
 *   close cycle returning back to the starting point.
 *
 * Polycarp knows the coordinates of the starting point (x1, y1) and the
 * coordinates of the point where the flag is situated (x2, y2). Polycarp’s
 * quadcopter can fly only parallel to the sides of the field each tick changing
 * exactly one coordinate by 1. It means that in one tick the quadcopter can fly
 * from the point (x, y) to any of four points: (x - 1, y), (x + 1, y),
 * (x, y - 1) or (x, y + 1).
 *
 * Thus the quadcopter path is a closed cycle starting and finishing in (x1, y1)
 * and containing the point (x2, y2) strictly inside.
 *
 * The picture corresponds to the first example: the starting (and finishing)
 * point is in (1, 5) and the flag is in (5, 2).
 * What is the minimal length of the quadcopter path?
 *
 * Input
 * The first line contains two integer numbers x1 and y1 ( - 100 ≤ x1, y1 ≤ 100)
 * — coordinates of the quadcopter starting (and finishing) point.
 *
 * The second line contains two integer numbers x2 and y2 ( - 100 ≤ x2, y2 ≤ 100)
 * — coordinates of the flag.
 *
 * It is guaranteed that the quadcopter starting point and the flag do not
 * coincide.
 *
 * Output
 * Print the length of minimal path of the quadcopter to surround the flag and
 * return back.
 */

#include <iostream>

using namespace std;

typedef struct coord {
        int x;
        int y;
} coord;

typedef struct coord_pairs {
        coord entry;
        coord exit;
} coord_pairs;

int abs(int x)
{
        return x < 0 ? -1 * x : x;
}

coord find_relative_pos(coord start, coord end)
{
        coord relative_pos;
        relative_pos.x = end.x - start.x;
        relative_pos.y = end.y - start.y;
        return relative_pos;
}

coord find_enter_point(coord end, coord relative_pos)
{
        coord enter_point;
        if (relative_pos.x > 0) {
                enter_point.x = end.x - 1;
        } else {
                enter_point.x = end.x + 1;
        }

        if (relative_pos.y >= 0) {
                enter_point.y = end.y - 1;
        } else {
                enter_point.y = end.y + 1;
        }

        cout << "Enter Point: " << enter_point.x << " , " << enter_point.y << endl;
        return enter_point;
}


coord find_exit_point(coord end, coord relative_pos)
{
        coord exit_point;

        if (relative_pos.x > 0) {
                exit_point.x = end.x - 1;
        } else if (relative_pos.x == 0) {
                exit_point.x = end.x - 1;
        } else {
                exit_point.x = end.x + 1;
        }

        if (relative_pos.y > 0) {
                exit_point.y = end.y + 1;
        } else if (relative_pos.y == 0) {
                exit_point.y = end.y - 1;
        } else {
                exit_point.y = end.y - 1;
        }

        cout << "Exit point: " << exit_point.x << " , " << exit_point.y << endl;
        return exit_point;
}

int calc_distance(coord start, coord end)
{
        return (abs(start.x - end.x) + abs(start.y - end.y));
}

coord_pairs find_entry_exit_points(coord end, coord relative_pos)
{
        coord enter_point, exit_point;
        if (relative_pos.x > 0) {
                enter_point.x = end.x - 1;
                exit_point.x = end.x - 1;

                enter_point.y = end.y - 1;
                exit_point.y = end.y + 1;
        } else if (relative_pos.x == 0) {
                if (relative_pos.y > 0) {
                        enter_point.x = end.x + 1;
                        exit_point.x = end.x - 1;

                        enter_point.y = end.y - 1;
                        exit_point.y = end.y - 1;
                } else if (relative_pos.y < 0) {
                        enter_point.x = end.x + 1;
                        exit_point.x = end.x - 1;

                        enter_point.y = end.y + 1;
                        exit_point.y = end.y + 1;
                }
        } else if (relative_pos.x < 0) {
                enter_point.x = end.x + 1;
                exit_point.x = end.x + 1;

                enter_point.y = end.y + 1;
                exit_point.y = end.y - 1;
        }
        //cout << "Enter Point: " << enter_point.x << " , " << enter_point.y << endl;
        //cout << "Exit point: " << exit_point.x << " , " << exit_point.y << endl;

        coord_pairs pairs;
        pairs.entry = enter_point;
        pairs.exit = exit_point;
        return pairs;
}

int main()
{
        coord start, end;
        cin >> start.x >> start.y >> end.x >> end.y;

        coord relative_pos = find_relative_pos(start, end);
        coord_pairs pairs = find_entry_exit_points(end, relative_pos);
        coord enter_point = pairs.entry;
        coord exit_point = pairs.exit;

        //cout << calc_distance(start, enter_point) << endl;;
        //cout << calc_distance(exit_point, start) << endl;;
        cout << calc_distance(start, enter_point) + 6 + calc_distance(exit_point, start) << endl;
        return 0;
}
