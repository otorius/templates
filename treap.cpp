struct node {
    node *l, *r;
    int key, prior, sz;
    node(int _key) {
        l = r = nullptr;
        key = _key; prior = rng(); sz = 1;
    }
};
class treap {
private:
    node *root;
public:
    int getsize(node *cur) {
        return (cur ? cur -> sz : 0);
    }
    int updsize(node *cur) {
        return cur -> sz = 1 + getsize(cur -> l) + getsize(cur -> r);
    }
    void insert(int pos, int val) {
        node *l, *r;
        split(root, l, r, pos);
        node *v = new node(val);
        merge(l, l, v);
        merge(root, l, r);
    }
    void erase(int pos) {
        node *l, *r;
        split(root, l, r, pos);
        split(r, root, r, 1);
        merge(root, l, r);
    }
    void split(node *cur, node *&l, node *&r, int val) {
        if (!cur) { l = r = nullptr; return; }
        if (getsize(cur -> l) < val) {
            split(cur -> r, cur -> r, r, val - getsize(cur -> l) - 1);
            l = cur;
        } else {
            split(cur -> l, l, cur -> l, val);
            r = cur;
        } updsize(cur);
    }
    void merge(node *&cur, node *l, node *r) {
        if (!l) { cur = r; return; }
        if (!r) { cur = l; return; }
        if (l -> prior < r -> prior) {
            merge(l -> r, l -> r, r);
            cur = l;
        } else {
            merge(r -> l, l, r -> l);
            cur = r;
        } updsize(cur);
    }
    int getpos(node *cur, int pos, int cnt = 0) {
        if (cnt + getsize(cur -> l) + 1 == pos) return cur -> key;
        if (cnt + getsize(cur -> l) + 1 > pos) return getpos(cur -> l, pos, cnt);
        return getpos(cur -> r, pos, cnt + getsize(cur -> l) + 1);
    }
    int getpos(int pos) {
        if (pos > getsize(root))
            return -1;
        return getpos(root, pos);
    }
} tr;
