#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using vint = vector<int>;
using matrix = vector<vint>;
using vll = vector<ll>;
using matrlx = vector<vll>;
using fourdimensionalMatrix = vector<matrix>; // ;;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using dbl = deque<bool>;
using dbltrix = deque<dbl>;
using sint = stack<int>;
using tii = tuple<int, int, int>;
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define _CRT_SECURE_NO_WARNINGS
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()

const int INF = 0x3f3f3f3f;
const ll VINF = 2e18;
const double PI = acos(-1);
const double EPS = 1e-9;

class item {
public:
    static int size = 0;
    int id, dmg, df, at, agg;
    string name;

    void init(int id) {
        static const matrix stat = {{1, 0, 0, "nasty dusty goofy ratty sword"}, {0, 7, 7, "lucky"}};
        size++;
        if (check()) {
            assert(stat[id][0] == stat[id][1] == stat[id][2] == stat[id][3] == 0);
            if (stat[id][1] == stat[id][2] == 0) agg = 0;
            else if (stat[id][0] == 0) agg = 1;
        }
    }

    item(int id) : id(id) {
        init(id);
    }

    bool check() {
        if (id < 0 || id > size) return false;
        return true;
    }

    bool checkx(int x) {
        if (x < 0 || x > size) return false;
        return true;
    }
};

using vit = vector<item>;

class player {
public:
    int hp, at, df, exp, level, fun;
    bool dead;
    string name;
    vit items;

    player() : hp(INF), at(INF), df(INF), exp(INF), level(INF), fun(-1), dead(false), name("koosaga") {
        items.clear();
        items.emplace_back();
    }

    void update() {
        if (hp < EPS) dead = true;
        for (int i = 0; i < items.size(); i++) {
            if (!items[i].check()) {
                cout << "Get rekt bozo" << endl;
                assert(!items[i].check());
            }
        }
    }

    void putItem(item it) {
        items.emplace_back(it);
    }
};
