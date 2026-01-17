class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();

        //flipp
        for(int i=0;i<n;i++){
            int j=0,k=m-1;
            while(j<k){
                swap(image[i][j++],image[i][k--]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(image[i][j] == 1){
                    image[i][j] = 0;
                }else{
                    image[i][j] = 1;
                }
            }
        }
        return image;
    }
};