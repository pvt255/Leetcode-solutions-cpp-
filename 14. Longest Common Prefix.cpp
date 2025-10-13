
s.find("low") != 0 // kiểm tra "low" có ở đầu chuỗi không
s.find("low")==string::npos // kiểm tra có trả về không

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  // tránh lỗi truy cập rỗng
        const char* commonChar = strs[0].c_str();
        if (commonChar[0] == '\0') return "";  // chuỗi đầu rỗng
        int i = 0;
        int size = strs.size();
        while (commonChar[i] != '\0') {
            bool allMatch = true;  // reset mỗi vòng
            for (int j = 1; j < size; j++) {
                const char* checkChar = strs[j].c_str();
                // nếu chuỗi hiện tại ngắn hơn hoặc ký tự khác nhau
                if (checkChar[i] == '\0' || checkChar[i] != commonChar[i]) {
                    allMatch = false;
                    break;
                }
            }
            if (!allMatch) break;
            i++;
        }
        return strs[0].substr(0, i);
    }
};



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix = strs[0];
        int size = strs.size();        
        for(int j =1; j < size; j++){
            while(strs[j].find(commonPrefix)!=0){
                int commonPrefixSize = commonPrefix.size();
                commonPrefix = commonPrefix.substr(0, commonPrefixSize-1);
            }
        if(commonPrefix ==""){
            return commonPrefix;
        }
            
        }
        return commonPrefix;

    }
};