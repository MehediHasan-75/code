void remove(int idx){
} // TODO: remove value at idx from data structure
void add(int idx){
} // TODO: add value at idx from data structure
int get_answer(){
} // TODO: extract the current answer of the data structure

int block_size;// block_size=sqrt(n);

struct Query {
    int l, r, idx;
    //In odd blocks sort the right index in ascending order and in even blocks sort it in descending order. This will minimize the movement of right pointer
    bool operator<(Query other) const
    {
        if(l/block_size != other.l/block_size)
            return l<other.l;
        return (l/ block_size & 1) ? (r < other.r) : (r > other.r);
    }
  
};
vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());
    // TODO: initialize data structure
    //VVI
    int cur_l = queries[0].l;
    int cur_r = queries[0].l;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}
//time complexity: O((N+Q)*F*sqrt(N)) where O(F) is the complexity of add and remove function.