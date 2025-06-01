class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        int i1=0,j1=0;
        int n=mat1.size();
	   int i2=n-1, j2=n-1; 
	   int res=0; 
	   
	   while(i1<=n-1 && j1<=n-1 && i2>=0 && j2>=0 ){ 
	       //cout<<mat1[i1][j1]<<" "<< mat2[i2][j2]<<endl;
	       if(mat1[i1][j1] + mat2[i2][j2] == x){
	           res++;
	           
	           if(j1==n-1){
	               i1++;
	               j1=0;
	           }
	           else{
	               j1++;
	           } 
	           
	           if(j2==0){
	               i2--;
	               j2=n-1;
	           }
	           else{
	               j2--;
	           }  
	       }
	       
	       else if(mat1[i1][j1] + mat2[i2][j2] > x){
	           if(j2==0){
	               i2--;
	               j2=n-1;
	           }
	           else{
	               j2--;
	           } 
	           
	       } 
	       
	       else{
	            if(j1==n-1){
	               i1++;
	               j1=0;
	           }
	           else{
	               j1++;
	           } 
	       }
	       
	   }
	   return res;
        
    }
};