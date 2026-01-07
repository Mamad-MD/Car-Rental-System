//utils/hashhelper.h
#include <string>

using namespace std;

class HashHelper {
public:
    static string hashPassword(string password) {
        unsigned long hash = 5381;
        for (char c : password) {
            hash = ((hash << 5) + hash) + c;
        }
        return to_string(hash);
    }
};
