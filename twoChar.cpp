#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {
    vector<char> v;
    vector<char> r;
    for(int i=0;i<s.size();i++)
    {
        r.push_back(s[i]);
        auto itr = find(v.begin(),v.end(),s[i]);
        if(itr == v.end())
        {
            v.push_back(s[i]);
        }
    }

    cout<<"distinct vector"<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;


    vector<char> alt;

    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            vector<char> temp = r;
            cout<<"selected to keep : "<<v[i]<<" "<<v[j]<<endl;
            cout<<"initial temp"<<endl;
            for(int z=0;z<temp.size();z++)
            {
                cout<<temp[z]<<" ";
            }
            cout<<endl;

            int k=0;
            while(k < temp.size())
            {
                if(temp[k] == v[i] || temp[k] == v[j])
                {
                    k++;
                }
                else
                {   
                    temp.erase(temp.begin() + k);
                    //cout<<"\tdeleting\t";
                    //for(int z=0;z<temp.size();z++)
                    //{
                    //    cout<<temp[z]<<" ";
                    //}
                    //cout<<endl;
                }
            }
            bool isAlt = true;
            for(int l=0;l<temp.size()-2;l++)
            {
                if(temp[l] != temp[l+2])
                {
                    isAlt = false;
                }
            }
            if(temp.size()<=2)
            {
                isAlt = false;
            }
            cout<<"temp"<<endl;
            for(int z=0;z<temp.size();z++)
            {
                cout<<temp[z]<<" ";
            }
            cout<<endl;
            if(isAlt)
            {
                if(temp.size() > alt.size())
                alt = temp;
            }
        }
    }

    if(alt.size() > 0)
    {
        return alt.size();
    }

    return 0;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
