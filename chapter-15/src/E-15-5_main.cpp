
#include <iostream>
#include "mystringmap.h"

using namespace std;

int main() {
    MyStringMap mmp;

    mmp.put("JS", "JIANGSU");
    mmp.put("SH", "SHANGHAI");
    cout << mmp.size() << endl;
    mmp.put("ZJ", "ZHEJIANG");
    cout << mmp.size() << endl;
    mmp.put("JX", "JIANGXI");
    cout << mmp.size() << endl;
    cout << mmp.get("ZJ") << endl;
    mmp.put("SD", "SHANDONG");
    cout << mmp.size() << endl;
    return 0;
}
