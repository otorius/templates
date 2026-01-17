struct node {
    node *ch[2], *par;
    bool rev;

    node() {
        ch[0] = ch[1] = par = nullptr;
        rev = 0;
    }
} *v[maxN];

bool is_root(node *x) {
    return (!(x -> par) || (x -> par -> ch[0] != x && x -> par -> ch[1] != x));
}

void push(node *x) {
    if (!x || !(x -> rev)) return;

    swap(x -> ch[0], x -> ch[1]);
    if (x -> ch[0]) x -> ch[0] -> rev ^= 1;
    if (x -> ch[1]) x -> ch[1] -> rev ^= 1;

    x -> rev = 0;
}

void rotate(node *x) {
    node *p = x -> par;
    node *g = p -> par;

    push(p); push(x);

    bool f = (x == p -> ch[1]);
    if (!is_root(p))
        g -> ch[(p == g -> ch[1])] = x;
    x -> par = g;

    p -> ch[f] = x -> ch[!f];
    if (x -> ch[!f]) x -> ch[!f] -> par = p;

    x -> ch[!f] = p; p -> par = x;
}

void splay(node *x) {
    static vector<node*> stk; stk.clear();

    node *y = x;
    stk.pb(y);

    while (!is_root(y)) {
        y = y -> par;
        stk.pb(y);
    }
    
    for (int i = stk.size() - 1; i >= 0; i--) push(stk[i]);

    while (!is_root(x)) {
        node *p = x -> par;
        node *g = p -> par;

        if (!is_root(p)) {
            if ((x == p -> ch[1]) == (p == g -> ch[1])) rotate(p);
            else rotate(x); 
        }

        rotate(x);
    }
}

void access(node *x) {
    node *lst = nullptr;
    for (node *y = x; y; y = y -> par) {
        splay(y); y -> ch[1] = lst;
        if (lst) lst -> par = y; lst = y;
    }

    splay(x);
}

void make_root(node *x) {
    access(x);
    x -> rev ^= 1;
}

node* find_root(node *x) {
    access(x);
    while (1) {
        push(x);
        if (!x -> ch[0]) break;
        x = x -> ch[0];
    }

    splay(x);
    return x;
}

bool link(node *v, node *u) {
    make_root(v);
    if (find_root(u) == v) return 0;
    v -> par = u; return 1;
}

bool cut(node *v, node *u) {
    make_root(v); access(u);

    if (u -> ch[0] != v || v -> ch[1]) return 0;
    u -> ch[0] = nullptr; v -> par = nullptr; return 1;

}
