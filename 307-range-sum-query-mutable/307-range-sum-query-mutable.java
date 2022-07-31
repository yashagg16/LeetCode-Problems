class NumArray {
    private int[] nums;
    private int[] tree;
    private int n;
    /*
        input :=
            1. idx := current index of the tree
            2. st  := stores the left limit for array sub part
            3. end := stores the right limit for array sub part
    */
    private void buildTree(int idx, int st, int end){
        if(st > end) return; //not possible
        
        else if(st == end) {
            tree[idx] = nums[st];   //store the element at the current index
            return;
        }
        
        //mid point to divide the array into 2 parts
        int mid = (st+end)/2;
        
        //building the left half of the tree
        buildTree(2*idx, st, mid);
        
        //building the right half of the tree
        buildTree(2*idx+1, mid+1, end);
        
        //updating the current idx with the left and right idx
        tree[idx] = tree[2*idx] + tree[2*idx+1]; 
    }
    
    private void updateUtil(int tr, int index, int val, int l, int r){
        if(l == r){
            tree[tr] = val;
            return;
        }
        
        int mid = (l+r)/2;
        
        if(index <= mid){
            updateUtil(2*tr, index, val, l, mid);
        }
        else{
            updateUtil(2*tr+1, index, val, mid+1, r);
        }
        tree[tr] = tree[2*tr] + tree[2*tr+1];
    }
    
    private int sumRangeUtil(int l, int r, int tl, int tr, int i){
        // System.out.println("l r " + l + " " + r);
        // System.out.println("tl tr i" + tl + " " + tr+ " " + i);
        if(l > r) return 0;
        
        if(l == tl && r == tr) return tree[i];
        
        int tm = (tl+tr)/2;
        return sumRangeUtil(l, Math.min(r, tm), tl, tm, 2*i) + sumRangeUtil(Math.max(tm+1, l), r, tm+1, tr, 2*i+1) ; 
    }
    public NumArray(int[] nums) {
        this.nums = nums;
        this.n = nums.length;
        this.tree = new int[4*n];
        
        buildTree(1, 0, n-1);
    }
    
    public void update(int index, int val) {
        updateUtil(1, index, val, 0, n-1);
    }
    
    public int sumRange(int left, int right) {
        return sumRangeUtil(left, right, 0, n-1, 1);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */