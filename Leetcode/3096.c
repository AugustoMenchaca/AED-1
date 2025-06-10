char* triangleType(int* nums, int numsSize) {
    static char equilatero[] = "equilateral";
    static char isosceles[] = "isosceles";
    static char scalene[] = "scalene";
    static char none[] = "none";
    int i,z;

    z = numsSize - 1;

    if(nums[0] == nums[1] && nums[1] == nums[2]) return equilatero;

    if(nums[0] + nums[1] > nums[2] && nums[0] + nums[2] > nums[1] && nums[1] + nums[2] > nums[0]){
        for(i = 0 ; i < numsSize ; i++){
            for(z=numsSize - 1;z >= 0;z--){
                if(nums[i]==nums[z] && i!=z) return isosceles;
            }
        }

        return scalene;
    }else return none;
}

int main(){
    int lados[] = {3,3,4};

    triangleType(lados,3);
}