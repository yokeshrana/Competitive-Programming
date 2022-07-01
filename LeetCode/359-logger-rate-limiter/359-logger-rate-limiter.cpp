class Logger {
public:
    
    map<string,int> mp;
    Logger() {
       
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
       //if its new then simply add to map
        if(!mp.count(message)) {
            mp[message]=timestamp; 
            return true;
        }
        if(timestamp-mp[message]>=10)
        {
            mp[message]=timestamp;
            return true;
        }else
        {
            return false;
        }
    
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */