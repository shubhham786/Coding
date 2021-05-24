 #include<iostream>
 #include<vector>
 using namespace std;

 //To print the matrices
    vector<int> kadens_algo_generic_subarry01(vector<int>&arr)
   {
     int gsum=-(int)1e9,csum=0,gedx=0,csdx=0,gsdx=0;


     for(int i=0;i<arr.size();i++)
     {
         int ele=arr[i];
         csum=csum+ele;
         if(ele>csum)
         {
             csum=ele;
             csdx=i;
         }
         //csum=max(ele,csum+ele);
         if(csum>gsum){
             gsum=csum;
             gsdx=csdx;
             gedx=i;
         }
         //gsum=max(csum,gsum);
     }
      return {gsum,gsdx,gedx};
   }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        
        int gsum=-(int)1e9,csum=0;
        int gsri,geri,gsci,geci;
          
         //for(int i=0;i<C;i++)
           // ans.push_back(M[0][i]);
            
     // cout<<R<<endl;
    
        for(int i=0;i<R;i++)
        {
               //fill_n(ans.begin(), C, 0);
                vector<int>ans(C,0);
            for(int j=i;j<R;j++)
            {
                csum=0;
                for(int k=0;k<C;k++)
                {
                    ans[k]+=M[j][k];
                   // csum=max(ans[k],csum+ans[k]);
                    //gsum=max(gsum,csum);
                    
                }
   // vector<int> kadens_algo_generic_subarry01(vector<int>&arr)
                vector<int>a=kadens_algo_generic_subarry01(ans);
                    //cout<<csum<<" "<<i<<" "<<j<<endl;
                    if(a[0]>gsum)
                      {
                           gsum=a[0];
                           gsri=i;
                           geri=j;
                           gsci=a[1];
                           geci=a[2];
                      }
            }
        }
        
        for(int i=gsri;i<=geri;i++)
        {
            for(int j=gsci;j<=geci;j++)
            {
                cout<<M[i][j]<<" ";
            }
            cout<<endl;
        }
        return gsum;
    }
int main()
{
    
    vector<vector<int>>M(4,vector<int>(5));

     M={{1,2,-1,-4,-20},
{-8,-3,4,2,1},
{3,8,10,1,3},
{-4,-1,1,7,-6}};

 int gsum=maximumSumRectangle(4,5,M);
 
 

      //seggrate_0_1_2(arr);

//      cout<<arr.size();
     // for(int i:arr)
      //{
        //  cout<<i<<" ";
      //}
    

    return 0;
}