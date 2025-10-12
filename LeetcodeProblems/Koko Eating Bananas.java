class Solution {
    public int minEatingSpeed(int[] piles, int h) {

        int minspeed=1;
        int maxspeed=0;

        for(int pile:piles){
            maxspeed=Math.max(maxspeed,pile);
        }

        while(minspeed<maxspeed){
            int m=minspeed+(maxspeed-minspeed)/2;

            if(canEat(piles,h,m)){
                maxspeed=m;
            }else{
                minspeed=m+1;
            }
              

        }
        return minspeed;
        
    }
    private boolean canEat(int[]piles,int h,int speed){
        int hour=0;

        for(int pile:piles){
            hour+=Math.ceil((double)pile/speed);
        }
        return hour<=h;
    }
}
