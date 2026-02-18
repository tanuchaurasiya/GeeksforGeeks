class Solution {
  public:
    int res=0;
    void merge(int l, int m, int h, vector<int> &arr)
    {
        int n1=m-l+1;
        int n2=h-m;
        // cout<<"\nl="<<l<<" m="<<m<<" h="<<h<<endl;
        vector<int> a1(n1);
        vector<int> a2(n2);
        // cout<<"a1=";
        for(int i=0;i<n1;i++){
            // cout<<arr[l+i]<<" ";
            a1[i]=arr[l+i];
        }
        // cout<<"\na2=";
        for(int i=0;i<n2;i++){
            a2[i]=arr[m+i+1];
            // cout<<arr[m+i+1]<<" ";
        }
        
        int i=0,j=0;
        int k=l;
        
        while(i<n1 && j<n2){
            if(a1[i]>a2[j]) {
                // cout<<"i and j="<<i<<" "<<j<<endl;
                res+=(n1-i);
                // cout<<"Res="<<res<<endl;
                arr[k]=a2[j];
                j++;
            }
            else{
                arr[k]=a1[i];
                i++;
                
            }
            k++;
        }
        
        while(i<n1){
            arr[k]=a1[i];
            i++;
            k++;
        }
        
        while(j<n2){
            arr[k]=a2[j];
            j++;
            k++;
        }
    }
    void mergeSort(int l, int h, vector<int> &arr){
        if(l<h){
            int mid = (l+h)/2;
            mergeSort(l,mid,arr);
            mergeSort(mid+1,h,arr);
            merge(l,mid,h,arr);
        }
        
    }
    
    
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        mergeSort(0, n-1, arr);
        return res;
    }
};



