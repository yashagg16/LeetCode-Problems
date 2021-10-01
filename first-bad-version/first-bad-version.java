/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        long st = 1;
        long end = n;
        
        long mid;
        
        while(st + 1 < end){
            mid = (st+end)/2;
            // System.out.println(st + " " + mid + " " + end);
            
            if(isBadVersion((int)mid)){
                end = mid;
            }
            else{
                st = mid;
            }
        }
        
        if(isBadVersion((int)st)){
            return (int)st;
        }
        return (int)end;
    }
}