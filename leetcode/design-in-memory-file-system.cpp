// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/design-in-memory-file-system/description/
// Date: 17th Feb, 2023
// Tags: system-design

class File {
    public:
    bool isFile;
    map<string,File*> children;
    string content;
    string filename;
    File(string filename, bool isFile) {
        this->filename = filename;
        this->isFile = isFile;
        this->content = "";
    }
};
class FileSystem {
public:
    File* root;
    FileSystem() {
        root = new File("/", false);
    }
    
    vector<string> ls(string path) {
        auto pathVec = splitPath(path);
        File* node = root;
        // cout << "pathvec size: " << pathVec.size() << endl;
        for (auto s : pathVec) {
            node = node->children[s];
        }

        vector<string> vec;
        if(node->isFile) {
            vec.push_back(node->filename);
        }
        else {
            for(auto i : node->children) {
            vec.push_back(i.first);
            }
        }
        return vec;
    }
    
    void mkdir(string path) {
        auto pathVec = splitPath(path);
        File* node = root;
        for (auto s : pathVec) {
            if(node->children.find(s)==node->children.end())
            {
                File* newNode = new File(s, false);
                node->children[s] = newNode;
            }
            node = node->children[s];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        auto pathVec = splitPath(filePath);
        File* node = root;
        int i;
        for (i=0; i<pathVec.size()-1;i++) {
            string s = pathVec[i];
            if(node->children.find(s)==node->children.end())
            {
                File* newNode = new File(s, false);
                node->children[s] = newNode;
            }
            node = node->children[s];
        }

        string s = pathVec.back();
        if(node->children.find(s)==node->children.end())
        {
            File* newNode = new File(s, true);
            node->children[s] = newNode;
        }
        node = node->children[s];
        node->content += content;


    }
    
    string readContentFromFile(string filePath) {
        auto pathVec = splitPath(filePath);
        File* node = root;
        for (auto s : pathVec) {
            node = node->children[s];
        }
        return node->content;
    }

    vector<string> splitPath(string path) {
        // path = "/goowmfn/c";
        vector<string> vec;
        stringstream ss(path);
        string token;
        while(getline(ss, token, '/')) {
            if(token != "")
            {
                vec.push_back(token);
            }
        }
        // for(auto i: vec) {
        //     cout << i << " ";
        // }
        // cout << endl;
        return vec;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
