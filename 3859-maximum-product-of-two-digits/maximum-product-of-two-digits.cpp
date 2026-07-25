class Solution {
public:
    int maxProduct(int n) {
        int first = 0,sec = 0;

        while(n>0){
            int temp = n%10;
            if(temp > first){
                sec = first;
                first = temp;
            }else if(temp <= first && temp >= sec){
                sec = temp;
            }
            n = n/10;
        }
        return first*sec;

    }
};