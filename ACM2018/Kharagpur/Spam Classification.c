/*
 * Spam Classification using Neural Network
 *
 * Neural nets are extremely popular in the Machine Learning domain. A neural
 * net is composed of multiple layers. It has an input layer in which you input
 * the parameter x (the input of the program). The input is then passed through
 * multiple hidden layers, finally getting one output at the final layer, called
 * the output layer.
 *
 * We have a very simple neural net, which consist of N hidden layers. Each
 * layer contains one neuron. Each neuron has two values associated with it:
 * wi, and bi, denoting the weight and the bias of the neuron. If you give the
 * neuron an input of x, it produces an output of (wi * x) + bi.
 *
 * Thus, an input x gets transformed by the neural net as follows. The first
 * hidden neuron takes the input x and produces y = w1 * x + b1, which acts as
 * the input for the second neuron. Then, the second neuron takes input y and
 * produces an output of z = w2 * y + b2. This keeps happening and you get a
 * single output at the end from the N-th neuron.
 *
 * There are some users and we want to find if they are spamming or not. They
 * have integer user-ids, which range from minX to maxX (both inclusive). So we
 * take each of these user-ids and feed it as input to the first layer of the
 * neural net. If the final output is even, then that user is not a spammer,
 * otherwise, the user is a spammer. You have to count the number of
 * non-spammers and spammers.
 */

#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, min, max;
        scanf("%d %d %d", &n, &min, &max);
        long long int se = 0, so = 0;
        int A[n * 2];
        for (int j = 0; j < n * 2; j++) {
            scanf("%d", A + j);
        }
        if (A[n * 2 - 1] % 2 == 0 && A[n * 2 - 2] % 2 == 0) {
            for (int j = min;j <= max; j++) {
                se++;
            }
            printf("%lld %lld\n", se, so);
            continue;
        }
        int flag_e = 0,flag_o = 1;

        for (int j = 0;j < n * 2; j += 2) {
            if (flag_e == 0) {
                se = 2 * A[j] + A[j + 1];
                if (se % 2 != 0) flag_e = 1;
                else flag_e = 0;
            } else {
                se = 1 * A[j] + A[j + 1];
                if (se % 2 == 0) flag_e = 0;
                else flag_e = 1;
            }
            if (flag_o == 1) {
                so = 1 * A[j] + A[j + 1];
                if (so % 2 == 0) flag_o = 0;
                else flag_o = 1;
            } else {
                so = 2 * A[j] + A[j + 1];
                if (so % 2 != 0 ) flag_o = 1;
                else flag_o = 0;
            }
        }
        se = 0, so = 0;
        for (int j = min;j <= max; j++) {
            if (j % 2 == 0) {
                if(flag_e == 1) {
                    so++;
                    continue;
                } else {
                    se++;
                    continue;
                }
            } else {
                if (flag_o == 1) {
                    so++;
                    continue;
                } else {
                    se++;
                }
            }
        }
        printf("%lld %lld\n", se, so);
    }
    return 0;
}
