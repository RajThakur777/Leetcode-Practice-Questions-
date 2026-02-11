struct Node{
    int l,r;
    int mn,mx;
    int lazy;
};
class SegmentTree{
public:
    vector<Node * > arr;
    SegmentTree(int n){
        this->arr.resize((n+1)*4);
        for(int i=0;i<arr.size();i++) arr[i] = new Node();
        build(1,0,n-1);
    }
    void build(int idx,int l, int r){
        if(l>r) return;
        // cout<<idx<<" ";
        arr[idx]->mn = arr[idx]->mx = arr[idx]->lazy = 0;
        arr[idx]->l = l;
        arr[idx]->r = r;
        if(l==r) return;
        int mid = l + (r-l)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
    }

    void pDown(int idx){
        if(arr[idx]->lazy!=0){
            apply(idx*2,arr[idx]->lazy);
            apply(idx*2+1,arr[idx]->lazy);
            arr[idx]->lazy = 0;
        }
    }
    void pUp(int idx){
        arr[idx]->mn = min(arr[idx*2]->mn,arr[idx*2+1]->mn);
        arr[idx]->mx = max(arr[idx*2]->mx,arr[idx*2+1]->mx);
    }
    void apply(int idx,int val){
        arr[idx]->mn += val;
        arr[idx]->mx += val;
        arr[idx]->lazy += val;
    }

    void update(int idx,int l,int r,int val){
        if(r<arr[idx]->l || l>arr[idx]->r) return;
        if(arr[idx]->l>=l && arr[idx]->r<=r){
            apply(idx,val);
            return;
        }   
        pDown(idx);
        int mid = arr[idx]->l + (arr[idx]->r-arr[idx]->l)/2;
        if(l<=mid) update(idx*2,l,r,val);
        if(r>=mid+1) update(idx*2+1,l,r,val);
        pUp(idx);
    }
    int query(int idx,int target){
        if(arr[idx]->l == arr[idx]->r) return arr[idx]->l;
        pDown(idx);
        if(arr[idx*2]->mn<=target && arr[idx*2]->mx>=target){
            return query(idx*2,target);
        }
        else{
            return query(idx*2+1,target);
        }
    }
};
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SegmentTree * s = new SegmentTree(n);
        vector<int> last(1e5+1,-1);
        int res = 0;
        for(int i=1;i<=n;i++){
            int x = nums[i-1];
            int flag = (x%2==0) ? +1:-1;
            int fromIndex = last[x];
            last[x] = i-1;
            s->update(1,fromIndex+1,i-1,flag);
            int l = s->query(1,0);
            if(i-1 != l)res = max(res,i-l);
        }
        return res;
    }
};