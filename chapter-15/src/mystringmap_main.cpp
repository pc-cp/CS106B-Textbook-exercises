
#include <iostream>
#include "mystringmap.h"
#include "myhashcode.h"
using namespace std;

int main() {
    MyStringMap smap;
    smap.put("JS", "JIANGSU");
    smap.put("ZJ", "ZHEJIANG");
    cout << smap.get("JS") << endl;
    cout << smap.get("SH") << endl;
    smap.put("SH", "SHANGHAI");
    cout << smap.get("SH") << endl;
    // cout << "" << endl;
    return 0;
}
