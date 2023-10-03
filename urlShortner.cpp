// C++ program to convert url id to short url and also mapping it back
// Pratham Nikam
#include <bits/stdc++.h>
using namespace std;

string idToShortURL(int n){
    string shorturl = "";
    string base = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    while(n){
        shorturl += base[n%62];
        n /= 62;
    }
    
    reverse(shorturl.begin(), shorturl.end());
    
    return shorturl;
}

int shortURLtoID(string shorturl){
    int n = shorturl.length(), id = 0;
    string base = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    map<char,int> mp;
    for(int i=0;i<62;i++){
        mp[base[i]] = i;
    }
    
    for(int i=0;i<n;i++){
        // cout << "char = " << shorturl[i] << " : index = " << mp[shorturl[i]] << endl;
        id += mp[shorturl[i]]*pow(62, n-i-1);
    }
    
    return id;
}

int main() {
    int n = 12345;
    string shorturl = idToShortURL(n);
    cout << "Generated short URL is " << shorturl << endl;
    cout << "Id from url is " << shortURLtoID(shorturl) << endl;
    
    return 0;
}
