/**
 * Lost in Transliteration: http://codeforces.com/contest/883/problem/F
 *
 * There are some ambiguities when one writes Berland names with the letters of
 * the Latin alphabet.
 *
 * For example, the Berland sound u can be written in the Latin alphabet as "u",
 * and can be written as "oo". For this reason, two words "ulyana" and "oolyana"
 * denote the same name.
 *
 * The second ambiguity is about the Berland sound h: one can use both "h" and
 * "kh" to write it. For example, the words "mihail" and "mikhail" denote the
 * same name.
 *
 * There are n users registered on the Polycarp's website. Each of them
 * indicated a name represented by the Latin letters. How many distinct names
 * are there among them, if two ambiguities described above are taken into
 * account?
 *
 * Formally, we assume that two words denote the same name, if using the
 * replacements "u"  "oo" and "h"  "kh", you can make the words equal. One can
 * make replacements in both directions, in any of the two words an arbitrary
 * number of times. A letter that resulted from the previous replacement can
 * participate in the next replacements.
 *
 * For example, the following pairs of words denote the same name:
 *
 * "koouper" and "kuooper". Making the replacements described above, you can
 * make both words to be equal: "koouper" "kuuper" and "kuooper"  "kuuper".
 * "khun" and "kkkhoon". With the replacements described above you can make both
 * words to be equal: "khun"  "khoon" and "kkkhoon"  "kkhoon"  "khoon".
 * For a given list of words, find the minimal number of groups where the words
 * in each group denote the same name.
 *
 * Input
 * The first line contains integer number n (2 ≤ n ≤ 400) — number of the words in the list.
 *
 * The following n lines contain words, one word per line. Each word consists of only lowercase Latin letters. The length of each word is between 1 and 20 letters inclusive.
 *
 * Output
 * Print the minimal number of groups where the words in each group denote the same name.
 */

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
