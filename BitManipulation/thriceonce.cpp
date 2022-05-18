int Solution::singleNumber(const vector<int> &A) {
int singleElement =0;
 for (int i = 0; i <32 ; i++) { //this is for calculating for every position in 32 bit integer
 int y = (1 << i);
 int tempSum = 0;
 for (int j = 0; j <A.size() ; j++) {
 if((A[j] & y)>=1) //if that particular bit is set for the ith position, add 1 to sum (w.r.t that bit)
 tempSum = tempSum +1;
 }
 //if bits are not multiple of 3 then that bit belongs to the element appearing single time
 if((tempSum%3)==1) {
 singleElement = singleElement | y;
 }
 }
    return singleElement;
}
/*


*/
