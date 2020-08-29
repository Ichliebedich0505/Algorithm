class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (*pattern == '\0' && *str == '\0'){
            return true;
        }

        if (*pattern == '\0' && *str != '\0'){
            return false;
        }

        if(*(pattern+1) == '*'){
            if (*pattern == *str || (*pattern == '.' && *str != '\0')){
                return match(str+1, pattern) || match(str, pattern+2) || match(str+1, pattern+2);
            }else
            {
                return match(str, pattern+2);
            }
            
                
        }

        if (*pattern == *str || (*pattern == '.' && *str != '\0')){
                return match(str+1, pattern+1);
        }

        return false;
    }
};