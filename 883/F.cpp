#include <iostream>
#include <string.h>
#include <string>

using namespace std;

string expand(string str)
{
        int i;
        string expanded_str = "";
        for (i = 0; i < str.length(); i++) {
                if (str[i] == 'u') {
                        expanded_str += "oo";
                } else {
                        expanded_str += str[i];
                }
        }
        return expanded_str;
}

bool reduced_form(string str)
{
        for (int i = 0; i < str.length() - 1; i++) {
                if (str[i] == 'o' && str[i + 1] == 'o')
                        return false;
                if (str[i] == 'k' && str[i + 1] == 'h')
                        return false;
        }
        return true;
}

string reduce(string str)
{
        int i;
        string reduced_str = str;
        while (!reduced_form(str)) {
                //cout << str << endl;
                reduced_str = "";
                for (i = 0; i < str.length(); i++) {
                        if (str[i] == 'o' && (i + 1) < str.length() && str[i + 1] == 'o') {
                                reduced_str += 'u';
                                i++;
                        } else if (str[i] == 'k' && (i + 1) << str.length() && str[i + 1] == 'h') {
                                reduced_str += 'h';
                                i++;
                        } else {
                                reduced_str += str[i];
                        }
                }
                str = reduced_str;
        }
        return reduced_str;
}

bool isEqual(string s1, string s2)
{
        // u <=> oo
        // h <=> kh
        s1 = expand(s1);
        s2 = expand(s2);
        string red_s1, red_s2;
        red_s1 = reduce(s1);
        red_s2 = reduce(s2);

        if (!red_s1.compare(red_s2)) {
                return true;
        }
        return false;
}

int main()
{
        int n;
        cin >> n;
        string str[n];
        bool checked[n];

        memset(checked, false, sizeof(checked));
        for (int i = 0; i < n; i++)
                cin >> str[i];

        for (int i = 0; i < n; i++) {
                string curr_string = str[i];
                for (int j = i + 1; j < n; j++) {
                        if (checked[j])
                                continue;
                        if (isEqual(curr_string, str[j])) {
                                checked[j] = true;
                                //cout << curr_string << " == " << str[j] << endl;
                        }
                }
        }

        /*
        for (int i = 0; i < n; i++)
                if (!checked[i])
                        cout << ". " << str[i] << endl;

                        */
        int groups = 0;
        for (int i = 0; i < n; i++)
                if (!checked[i])
                        groups++;
        cout << groups << endl;
        return 0;
}
