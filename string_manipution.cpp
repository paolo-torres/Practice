string solution(string &S, int K) {
    string str = "";
    
    for (auto it = S.begin(); it != S.end(); ++it) {
        if (*it != '-') {
            str += toupper(*it);
        }
    }
    
    int count = 0;
    for (auto it = str.end(); it != str.begin(); --it, ++count) {
        if (count == K) {
            str.insert(it, '-');
            count = 0;
        }
    }
    
    return str;
}
