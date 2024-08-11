#include <iostream>
using namespace std;

int main()
{
    /*
    1 2 3 4
    1 2 3 4
    1 2 3 4
    1 2 3 4
    */

    int i = 1;
    int n = 4;
    int count = 1;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= n)
    //     {
    //         cout << j << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
        4 3 2 1
        4 3 2 1
        4 3 2 1
        4 3 2 1
    */

    // i = 1;
    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= n)
    //     {
    //         cout << (n - j + 1) << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
          1 2 3
          4 5 6
          7 8 9
    */

    // i = 1;
    // n = 3;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= n)
    //     {
    //         cout << count << " ";
    //         count++;
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
     *
     * *
     * * *
     * * * *
     */

    // i = 1;
    // n = 4;
    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i)
    //     {
    //         cout << "* ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
     1
     2 2
     3 3 3
     4 4 4 4
    */

    // i = 1;
    // n = 4;
    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i)
    //     {
    //         cout << i << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
    1
    2 3
    4 5 6
    7 8 9 10
    */

    // i = 1;
    // count = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i)
    //     {
    //         cout << count << " ";
    //         count++;
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
       1
       2 3
       3 4 5
       4 5 6 7
    */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i)
    //     {
    //         cout << i + j - 1 << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
       1
       2 1
       3 2 1
       4 3 2 1
    */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i)
    //     {
    //         cout << i - j + 1 << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
          A A A
          B B B
          C C C
       */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= n)
    //     {
    //         cout << char('A' + i - 1) << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
             A B C
             A B C
             A B C
    */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= n)
    //     {
    //         cout << char('A' + j - 1) << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
        A B C D
        E F G H
        I J K L
        M N O P
    */

    // i = 1;
    // n = 4;
    // count = 1;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= n)
    //     {
    //         cout << char('A' + count - 1) << " ";
    //         count++;
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
           A B C
           B C D
           C D E
       */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= n)
    //     {
    //         cout << char('A' + i + j - 2) << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
              A
              B B
              C C C
          */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i)
    //     {
    //         cout << char('A' + i - 1) << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
                A
                B C
                D E F
                G H I J
    */

    // i = 1;
    // n = 4;
    // int value = 65;
    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i)
    //     {
    //         cout << char(value) << " ";
    //         value++;
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
               A
               B C
               C D E
               D E F G
   */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i)
    //     {
    //         cout << char('A' + i + j - 2) << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
              D
              C D
              B C D
              A B C D
  */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i)
    //     {
    //         cout << char('A' + n - i + j - 1) << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
     ---*
     --**
     -***
     ****
     */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= (n - i))
    //     {
    //         cout << " ";
    //         j++;
    //     }

    //     int k = 1;
    //     while (k <= i)
    //     {
    //         cout << "*";
    //         k++;
    //     }

    //     cout << endl;
    //     i++;
    // }

    /*
     ****
     ***
     **
     *
     */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= (n - i + 1))
    //     {
    //         cout << "*";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    /*
     ****
     -***
     --**
     ---*
     */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i - 1)
    //     {
    //         cout << " ";
    //         j++;
    //     }

    //     int k = 1;
    //     while (k <= (n - i + 1))
    //     {
    //         cout << "*";
    //         k++;
    //     }

    //     cout << endl;
    //     i++;
    // }

    /*
     1111
     -222
     --33
     ---4
     */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i - 1)
    //     {
    //         cout << " ";
    //         j++;
    //     }

    //     int k = 1;
    //     while (k <= (n - i + 1))
    //     {
    //         cout << i;
    //         k++;
    //     }

    //     cout << endl;
    //     i++;
    // }

    /*
    ---1
    --22
    -333
    4444
    */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= (n - i))
    //     {
    //         cout << " ";
    //         j++;
    //     }

    //     int k = 1;
    //     while (k <= i)
    //     {
    //         cout << i;
    //         k++;
    //     }

    //     cout << endl;
    //     i++;
    // }

    /*
    1234
    -234
    --34
    ---4
    */

    // i = 1;
    // n = 4;

    // while (i <= n)
    // {

    //     int k = 1;
    //     while (k <= (i - 1))
    //     {
    //         cout << " ";
    //         k++;
    //     }

    //     int j = 1;
    //     while (j <= (n - i + 1))
    //     {
    //         cout << i + j - 1;
    //         j++;
    //     }

    //     cout << endl;
    //     i++;
    // }

    /*
   ---1
   --23
   -456
   78910
   */

    // i = 1;
    // n = 4;
    // count = 1;
    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= (n - i))
    //     {
    //         cout << " ";
    //         j++;
    //     }

    //     int k = 1;
    //     while (k <= i)
    //     {
    //         cout << count;
    //         count++;
    //         k++;
    //     }

    //     cout << endl;
    //     i++;
    // }

    /*
   ---1
   --121
   -12321
   1234321
   */

    // i = 1;
    // n = 4;
    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= (n - i))
    //     {
    //         cout << " ";
    //         j++;
    //     }
    //     int k = 1;
    //     while (k <= i)
    //     {
    //         cout << k;
    //         k++;
    //     }

    //     int l = 1;
    //     while (l <= (i - 1))
    //     {
    //         cout << i - l;
    //         l++;
    //     }

    //     cout << endl;
    //     i++;
    // }

    /*
     1234554321
     1234**4321
     123****321
     12******21
     1********1
     **********
     */

    i = 1;
    n = 5;
    while (i <= n)
    {
        int j = 1;
        while (j <= (n - i + 1))
        {
            cout << j;
            j++;
        }

        int k = 1;
        while (k <= ((i - 1) * 2))
        {
            cout << "*";
            k++;
        }

        int l = 1;
        while (l <= (n - i + 1))
        {
            cout << n - i - l + 2;
            l++;
        }

        cout << endl;
        i++;
    }

    return 0;
}
