/*
    EXTRA EXAM VARIATIONS - ONLY MAIN CHANGES

    1. Sum of all odd numbers:
       Base case:
       if(v[start]%2!=0)
           return v[start];
       else
           return 0;

       Merge stays:
       return left_sum+right_sum;

    2. Count all even numbers:
       Base case:
       if(v[start]%2==0)
           return 1;
       else
           return 0;

    3. Count multiples of both 3 and 5:
       if(v[start]%3==0 && v[start]%5==0)
           return 1;

    4. Find maximum element:
       Base case:
       if(start==_end)
           return v[start];

       Merge:
       return max(left_max,right_max);

    5. Convert maximum-sum subarray to minimum-sum subarray:
       - Change max() to min()
       - Change -100000000 to 100000000
       - Keep the same divide and middle-crossing loops
*/

int main()
{
    return 0;
}
