class Solution {
public:
    int countTriples(int n) {
        int count=0;
        int arr[n+1]; 
        for(int i=1;i<=n;i++){
            arr[i]=i*i;
        }
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                for(int c=1;c<=n;c++){
                    if((arr[a]+arr[b])==arr[c]){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};