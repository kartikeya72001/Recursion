// Given a long vector of strings, print the strings that contain the strings generated by numeric string str.
//
// string searchIn [] = {
//             "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
//             "utkarsh", "divyam", "vidhi", "sparsh", "akku"
//     };
// For example, if the input is 26 and the string is coding, then output should be coding since 26 can produce co which is contained in coding.
//
// Input Format
// A numeric string str
//
// Constraints
// len(str) < 10
// No of strings in the vector < 10
//
// Output Format
// Each matched string from the given vector.
//
// Sample Input
// 34
// Sample Output
// vidhi
// divyam
// sneha
// Explanation
// 34 will result into combinations :
//
// *dg         *eg         *fg
// *dh            *eh         *fh
// *di            *ei         *fi
// Corresponding strings are output.
//
// vidhi contains dh
// divyam contains di
// sneha contains eh
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string>words={"_","+-/","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","*()%","#"};
vector<string> search = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"};
int nokiakeypad(string s,string ans)
{
    if(s.length()==0)
    {
        for(int i=0;i<search.size();i++)
        {
            if(search[i].find(ans)!=string::npos)
                cout<<search[i]<<endl;
        }

        return 1;
    }

    int idx=s[0]-'0';
    char n=s[0];
    string word=words[idx];
    int count=0;

    for(int i=0;i<word.length();i++)
    {
        char ch=word[i];
        count+=nokiakeypad(s.substr(1),ans+ch);
    }

    return count;
}

int main()
{
	string s;
	cin>>s;
    nokiakeypad(s,"");
	return 0;
}
