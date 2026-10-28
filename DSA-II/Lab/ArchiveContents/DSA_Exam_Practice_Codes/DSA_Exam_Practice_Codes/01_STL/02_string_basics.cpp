#include<iostream>
#include<string>
using namespace std;

/// CLASS EXAMPLE: string length, character and substring
int main()
{
    string s;
    cin>>s;

    cout<<s.length()<<endl;
    cout<<s[3]<<endl;

    /// substr(starting_index, number_of_characters)
    cout<<s.substr(3,2)<<endl;
}
