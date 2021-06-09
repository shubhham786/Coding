//https://leetcode.com/discuss/interview-question/348510/Google-or-OA-2019-or-Maximum-Area-Serving-Cake


#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
//#include<numbers>

using namespace std;



bool ispossibeltocutcake(vector<int>&arr,double cakearea,int guest)
{
    int g=0;

    for(int i=0;i<arr.size();i++)
    {
        double pi=3.141592;
        double area=pi*arr[i]*arr[i];

        g+=floor(area/cakearea);

        if(g>=guest)
          return true;


    }

    return false;
}


double maximumAreaCake(vector<int>&radius, int guest) {
        // Arrays.sort(radius);
        int n = radius.size();
        // double si = (Math.PI * radius[0] * radius[0]) / guest, ei = Math.PI *
        // radius[n - 1] * radius[n - 1];
        double si = 0.0, ei = 1e7;
        while ((ei - si) > 1e-5) {
            double cakeArea = (si + ei) / 2.0;
            if (!ispossibeltocutcake(radius, cakeArea, guest))
                ei = cakeArea - 1e-5;
            else
                si = cakeArea;

        }

        return si;
    }


int main()
{
    //vector<int>arr={1,1,1,2,2,3};
    // int guest=6;
    vector<int>arr={4,3,3};
    int guest=3;

    double r =maximumAreaCake(arr,guest);

    cout<<r<<endl;
}