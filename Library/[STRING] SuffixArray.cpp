struct SuffixArray{
    vector<int> p, lcp;
    void count_sort(vector<int> &p, const vector<int> &c){
        int n = p.size();
        vector<int> p_new(n), cnt(n + 1);
        for(int x : c) 
            cnt[x + 1]++;
        for(int i = 1; i < n; ++i) 
            cnt[i] += cnt[i - 1];
        for(int x : p) 
            p_new[cnt[c[x]]++] = x;
        p = p_new;
    }
    SuffixArray(string& s){
        s += "$";
        int n = s.size();
        vector<pair<int,int>> a(n);
        vector<int> c(n);
        p.resize(n);
        lcp.resize(n);
        for(int i = 0; i < n; i++){
            a[i] = {s[i], i};
        }
        sort(all(a));
        for(int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first == a[i - 1].first) c[p[i]] = c[p[i - 1]];
            else c[p[i]] = c[p[i - 1]] + 1;
        }
        int k = 0;
        while((1 << k) < n){
            for(int i = 0; i < n; i++){
                p[i] = (p[i]  - (1 << k) + n) % n;
            }
            count_sort(p, c);
            vector<int> c_new(n);
            c_new[p[0]] = 0;
            for(int i = 1; i < n; i++){
                pair<int,int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
                pair<int,int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
                if(cur == prev){
                    c_new[p[i]] = c_new[p[i - 1]];
                }else c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
            c = c_new;
            k++;
        }
        k = 0;
        for(int i = 0; i < n - 1; i++){
            int pi = c[i];
            int j = p[pi - 1];
            while(s[i + k] == s[j + k]) k++;
            lcp[pi] = k;
            k = max(k - 1, 0);
        }

    }
};