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
