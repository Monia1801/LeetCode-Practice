class Solution {
public:
    int add(int n){
        int sum=0;
        while(n>0){
            int k=n%10;
            sum+=k;
            n/=10;
        }
        return sum;
    }
    int product(int n){
        int pro=1;
        while(n>0){
            int k=n%10;
            pro*=k;
            n/=10;
        }
        return pro;
    }
    bool checkDivisibility(int n) {
        int a=add(n);
        int b=product(n);
        if(n%(a+b)==0) return true;
        return false;
    }
};